#pragma once

#include"Locker.h"

/**
 * \class Producer
 * \brief A class representing a producer that sends messages to a shared list.
 *
 * The `Producer` class is responsible for producing messages and adding them to a shared list of messages.
 *
 */
class Producer 
{
    list<Message>& _messages;   /**< Reference to the shared list of messages */
    Locker _locker;             /**< Instance of the Locker struct for synchronization */
    const int _millisecondsToWait;    /**< Time to wait between sending messages in milliseconds */

public:
    /**
     * \brief Constructs a `Producer` object with the specified parameters.
     * \param messages A reference to the shared list of messages.
     * \param millisecondsToWait The time to wait between sending messages in milliseconds.
     */
    Producer(list<Message>& messages, int millisecondsToWait);

    /**
     * \brief Overloaded function call operator.
     *
     * This operator is invoked when the `Producer` object is used as a callable.
     */
    void operator()();
};
