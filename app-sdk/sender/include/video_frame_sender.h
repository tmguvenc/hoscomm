#ifndef VIDEO_FRAME_SENDER_H
#define VIDEO_FRAME_SENDER_H

#include <sender_base.h>

namespace hos_comm
{
	class ISenderStrategy;

	class VideoFrameSender : public ISender
	{
	public:
		explicit VideoFrameSender(ISenderStrategy* sender_strategy);

		~VideoFrameSender() override;
		void sendFrame(upFrame) override;

	private:
		ISenderStrategy* m_sender_strategy;
	};
}

#endif // !VIDEO_FRAME_SENDER_H
