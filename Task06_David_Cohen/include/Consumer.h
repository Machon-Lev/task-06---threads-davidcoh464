#pragma once
#include "Locker.h"

using std::cout;
using std::endl;

#define NUM_PRODUCERS 2
#define MAX_MILLISECOND_TO_WAIT 3000

/**
 * @class Consumer
 * @brief Represents a consumer thread that retrieves messages from a shared list and processes them.
 *
 * The Consumer class is responsible for consuming messages from a shared list and performing
 * the necessary operations based on the content of each message. It waits for messages to become
 * available in the list and processes them accordingly.
 */
class Consumer
{
	list<Message>& _messages; /**< Reference to the shared list of messages */
	Locker _locker; /**< Object for thread synchronization using mutex and condition variable */
public:
	/**
	 * @brief Constructs a Consumer object.
	 * @param messages A reference to the shared list of messages.
	 */
	Consumer(list<Message>& messages);

	/**
	 * @brief Executes the consumer thread.
	 *
	 * This function is called when the consumer thread is started. It continuously retrieves messages
	 * from the shared list, processes them, and performs the necessary actions based on the content
	 * of each message.
	 */
	void operator()();
};
