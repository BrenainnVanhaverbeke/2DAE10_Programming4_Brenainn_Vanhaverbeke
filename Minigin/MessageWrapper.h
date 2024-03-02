#pragma once
#include <string>

namespace dae
{
	class MessageWrapper
	{
		enum class MessageTypes
		{

		};

	public:
		explicit MessageWrapper(MessageWrapper::MessageTypes type);
		virtual ~MessageWrapper();

		virtual MessageTypes GetType() const final;

	private:
		MessageTypes m_Type;
	};
}