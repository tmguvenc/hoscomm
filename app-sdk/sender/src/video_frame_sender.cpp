#include <video_frame_sender.h>
#include <video_frame.h>
#include <sender_strategy_base.h>
#include <stdexcept>

using namespace hos_comm;

VideoFrameSender::VideoFrameSender(ISendStrategy* sender_strategy) :
	m_send_strategy(sender_strategy)
{
	if (!m_send_strategy)
	{
		throw std::invalid_argument("send strategy cannot be null");
	}
}

VideoFrameSender::~VideoFrameSender()
{

}

void VideoFrameSender::sendFrame(upFrame frame)
{
	auto videoFrame = dynamic_cast<VideoFrame*>(frame.get());

	if (videoFrame)
	{
		auto w = videoFrame->width();
		auto h = videoFrame->height();
		auto c = videoFrame->channels();
		auto co = videoFrame->codec();
		auto ise = videoFrame->isEncoded();
		auto idx = videoFrame->index();

		m_send_strategy->send(&w, sizeof(int), true);
		m_send_strategy->send(&h, sizeof(int), true);
		m_send_strategy->send(&c, sizeof(int), true);
		m_send_strategy->send(&co, sizeof(int), true);
		m_send_strategy->send(&ise, sizeof(bool), true);
		m_send_strategy->send(&idx, sizeof(uint64_t), true);
		m_send_strategy->send(videoFrame->data(), frame->lenght(), false);
	}
	else
	{
		throw std::invalid_argument("frame is not VideoFrame");
	}

}