#ifndef VIDEO_FRAME_H
#define VIDEO_FRAME_H

#include <frame_base.h>
#include <stdlib.h>
#include <malloc.h>
#include <utility>

namespace hos_comm
{
	class VideoFrame : public IFrame
	{
	public:
		explicit VideoFrame() : VideoFrame(-1, -1, -1, -1, false, 0) { }
		explicit VideoFrame(int width, int height, int channels, int codec, bool isEncoded, uint64_t index) :
			IFrame(index),
			m_isEncoded(isEncoded),
			m_codec(codec),
			m_width(width),
			m_height(height),
			m_channels(channels)
		{
			m_lenght = width * height * channels;
			m_data = static_cast<char*>(malloc(m_lenght));
		}

		virtual ~VideoFrame() override {
			if (m_data)
			{
				free(m_data);
				m_data = nullptr;
			}
		}

		virtual bool isEncoded() const { return m_isEncoded; }
		virtual int codec() const { return m_codec; }
		virtual int width() const { return m_width; }
		virtual int height() const { return m_height; }
		virtual int channels() const { return m_channels; }

		VideoFrame(VideoFrame&& other) : 
			m_isEncoded(other.m_isEncoded),
			m_codec(other.m_codec),
			m_width(other.m_width),
			m_height(other.m_height),
			m_channels(other.m_channels)
		{
			m_index = other.m_index;
			m_data = other.m_data;
			m_lenght = other.m_lenght;

			other.m_data = nullptr;
			other.m_channels = -1;
			other.m_isEncoded = false;
			other.m_width = -1;
			other.m_height = -1;
			other.m_index = 0;
			other.m_lenght = -1;
			other.m_codec = -1;
		}

		VideoFrame& operator=(VideoFrame other)
		{
			using std::swap;
			swap(*this, other);
			return *this;
		}

	protected:
		bool m_isEncoded;
		int m_codec;
		int m_width;
		int m_height;
		int m_channels;
	};
}

#endif // !VIDEO_FRAME_H
