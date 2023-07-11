/**
 * @struct Message
 * @brief Represents a message used for communication between threads.
 *
 * The Message struct represents a message used for communication between threads.
 * It contains information such as the thread ID, a numerical value, and a flag
 * indicating whether it is the final message.
 */
struct Message
{
	/**
	 * @brief Thread ID associated with the message.
	 *
	 * The `t_id` field represents the thread ID associated with the message.
	 */
	size_t t_id;

	/**
	 * @brief Numerical value associated with the message.
	 *
	 * The `value` field represents the numerical value associated with the message.
	 */
	double value;

	/**
	 * @brief Flag indicating if it is the final message.
	 *
	 * The `is_finish` field is a boolean flag that indicates whether the message is
	 * the final message in a series of messages.
	 */
	bool is_finish;
};
