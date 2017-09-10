#ifndef SENDER_BASE_H
#define SENDER_BASE_H

#include <frame_base.h>

namespace hos_comm
{
	class ISender
	{
	public:
		virtual ~ISender() { }
		virtual void sendFrame(upFrame) = 0;
	};
}

#endif // !SENDER_BASE_H
