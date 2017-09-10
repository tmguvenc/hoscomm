#ifndef FRAME_BASE_H
#define FRAME_BASE_H

#include <memory>

namespace hos_comm
{
	class IFrame
	{
	public:

		explicit IFrame() : IFrame(0){ }
		explicit IFrame(uint64_t index) :
			m_index(index),
			m_data(nullptr),
			m_lenght(0)
		{
			
		}
		
		virtual ~IFrame()
		{
			
		}

		virtual uint64_t index() const { return m_index; }
		virtual char* data() const { return m_data; }
		virtual uint64_t lenght() const { return m_lenght; };

	protected:
		uint64_t m_index;
		char* m_data;
		uint64_t m_lenght;

	private:
		IFrame(const IFrame&);
		IFrame& operator=(const IFrame&);
	};

	using upFrame = std::unique_ptr<IFrame>;
}

#endif // !FRAME_BASE_H