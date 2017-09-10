#ifndef SEND_STRATEGY_BASE_H
#define SEND_STRATEGY_BASE_H

#include <stdint.h>

namespace hos_comm
{
	class ISendStrategy
	{
	public:
		virtual ~ISendStrategy() { }
		virtual void send(void* buffer, uint64_t length, bool more) = 0;
	};
}

#endif // !SEND_STRATEGY_BASE_H
