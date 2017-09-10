#include <sender_strategy_zmq.h>
#include <stdexcept>
#include <zmq.h>

using namespace hos_comm;

SenderStrategyZmq::SenderStrategyZmq(void* socket) :
m_socket(socket)
{
	if (!m_socket)
	{
		throw std::invalid_argument("socket cannot be null");
	}
}

SenderStrategyZmq::~SenderStrategyZmq()
{

}

void SenderStrategyZmq::send(void* buffer, uint64_t length, bool more)
{
	zmq_send(m_socket, buffer, length, more ? ZMQ_SNDMORE : 0);
}