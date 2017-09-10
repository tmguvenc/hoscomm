#ifndef VIDEO_FRAME_SENDER_H
#define VIDEO_FRAME_SENDER_H

#include <sender_base.h>

namespace hos_comm
{
	class ISendStrategy;

	class VideoFrameSender : public ISender
	{
	public:
		explicit VideoFrameSender(ISendStrategy* sender_strategy);

		~VideoFrameSender() override;
		void sendFrame(upFrame) override;

	private:
		ISendStrategy* m_send_strategy;
	};
}

#endif // !VIDEO_FRAME_SENDER_H
