#include <zmq.h>
#include <video_frame_sender.h>
#include <sender_strategy_zmq.h>
#include <video_frame.h>

static inline void sendFrame()
{
	auto context = zmq_ctx_new();
	auto sender = zmq_socket(context, ZMQ_DEALER);
	auto linger = 1;
	zmq_setsockopt(sender, ZMQ_LINGER, &linger, sizeof(linger));
	zmq_setsockopt(sender, ZMQ_IDENTITY, "sender", 6);
	zmq_connect(sender, "tcp://127.0.0.1:5555");

	hos_comm::SenderStrategyZmq strategy(sender);
	
	hos_comm::VideoFrameSender video_frame_sender(&strategy);
	zmq_send(sender, "", 0, ZMQ_SNDMORE);
	video_frame_sender.sendFrame(std::make_unique<hos_comm::VideoFrame>(640, 480, 3, 28, true, 4));

	zmq_close(sender);
	zmq_ctx_destroy(context);
}

int main()
{
	auto context = zmq_ctx_new();
	auto listener = zmq_socket(context, ZMQ_ROUTER);
	zmq_bind(listener, "tcp://*:5555");

	char buffer[640 * 480 * 3];

	sendFrame();

	size_t more = 1;
	auto more_size = sizeof(more);
	zmq_recv(listener, buffer, sizeof(buffer), 0);
	zmq_recv(listener, buffer, sizeof(buffer), 0);
	do
	{
		long temp;

		zmq_recv(listener, &temp, sizeof(temp), 0);
		zmq_getsockopt(listener, ZMQ_MORE, &more, &more_size);
	} while (more);

	zmq_close(listener);
	zmq_ctx_destroy(context);
}