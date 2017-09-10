#ifndef SENDER_STRATEGY_ZMQ_H
#define SENDER_STRATEGY_ZMQ_H
#include "sender_strategy_base.h"

namespace hos_comm
{
	class SenderStrategyZmq : public ISenderStrategy
	{
	public:
		explicit SenderStrategyZmq(void* socket);

		~SenderStrategyZmq() override;
		void send(void* buffer, uint64_t length, bool more) override;

	private:
		void* m_socket;
	};
}

#endif // !SENDER_STRATEGY_ZMQ_H
