#include"Producer.h"
#include"Consumer.h"
#include <thread>
using std::thread;

int main() 
{
	
	list<Message> messages;
	Consumer c1(messages);
	Producer p1(messages, 20);
	Producer p2(messages, 22);

	thread tOut(c1);
	thread tIn1(p1);
	thread tIn2(p2);

	tIn1.join();
	tIn2.join();
	tOut.join();

	return 0;
}