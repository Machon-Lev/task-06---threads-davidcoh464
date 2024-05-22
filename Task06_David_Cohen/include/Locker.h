#pragma once

#include "Message.h"
#include<iostream>
#include <list>
#include <mutex>
#include <chrono>

using std::mutex;
using std::condition_variable;
using std::list;

/**
 * @struct Locker
 * @brief Provides a thread-safe locking mechanism for message communication.
 *
 * The Locker struct is used to manage locking and synchronization for message communication
 * between threads. It includes a mutex and condition variable that can be used to control
 * access to shared resources and ensure safe communication.
 */
struct Locker
{
	/**
	 * @brief Mutex for thread synchronization.
	 *
	 * The `mtx_msg` mutex is used to control access to shared resources and ensure that
	 * only one thread can modify or access the resources at a time. It is used in conjunction
	 * with the `cond_msg` condition variable to provide thread-safe communication.
	 */
	static mutex mtx_msg;

	/**
	 * @brief Condition variable for thread synchronization.
	 *
	 * The `cond_msg` condition variable is used to block or wake up threads based on specific
	 * conditions. It is typically used in conjunction with the `mtx_msg` mutex to provide
	 * thread-safe communication and synchronization.
	 */
	static condition_variable cond_msg;
};