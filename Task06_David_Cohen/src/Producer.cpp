#include"Producer.h"

Producer::Producer(list<Message>& messages, int millisecondsToWait)
	: _messages(messages),
	_millisecondsToWait(millisecondsToWait) {};

void Producer::operator()()
{
	Message msg;
	msg.value = static_cast<double>(msg.t_id = std::hash<std::thread::id>{}(std::this_thread::get_id()));
	msg.is_finish = false;
	try
	{
		while (true)
		{
			{
				std::lock_guard lck(_locker.mtx_msg);
				_messages.push_back(msg);
			}
			_locker.cond_msg.notify_all();
			if (msg.is_finish)
				break;
			msg.value /= 10.0;
			if (msg.value == 0.0)
				msg.is_finish = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(_millisecondsToWait));
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception in enterMessages: " << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown exception occurred in enterMessages" << std::endl;
	}
}