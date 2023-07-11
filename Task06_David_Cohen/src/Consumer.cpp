#include"Consumer.h"

Consumer::Consumer(list<Message>& messages)
	: _messages(messages) {};

void Consumer::operator()()
{
	int not_finish = NUM_PRODUCERS;
	Message msg;
	try
	{
		while (not_finish != 0)
		{
			{
				std::unique_lock lck(_locker.mtx_msg);
				// Waiting until notify and '_messages' is not empty which returns true
				// or until it reaches the maximum time to wait
				if (_locker.cond_msg.wait_for(lck, std::chrono::milliseconds(MAX_MILLISECOND_TO_WAIT), [&]() {
					return !_messages.empty();}))
				{
					msg = _messages.front();
					_messages.pop_front();
				}
				else
				{
					std::cerr << "Termination due to excessive waiting time" << std::endl;
					break;
				}
			}
			if (msg.is_finish)
			{
				cout << "<" << msg.t_id << "> finished" << endl;
				--not_finish;
			}
			else
			{
				cout << "<" << msg.t_id << "> sent: <" << msg.value << ">" << endl;
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception in the Consumer: " << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown exception occurred in the Consumer" << std::endl;
	}
}
