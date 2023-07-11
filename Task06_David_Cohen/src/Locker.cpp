#include"Locker.h"

mutex Locker::mtx_msg;
condition_variable Locker::cond_msg;