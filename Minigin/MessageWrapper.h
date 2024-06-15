#pragma once
#include <string>

namespace dae
{
	class MessageWrapper final
	{

	public:
		enum class MessageTypes
		{
			ChangeText
		};
		union MessageContent 
		{
			int intValue;
			float floatValue;
			// Run tests to check necessary max length. Possible to leave variable?
			const char* stringValue;
		};

		//explicit MessageWrapper(MessageWrapper::MessageTypes type);
		explicit MessageWrapper(MessageWrapper::MessageTypes type, MessageContent content);
		~MessageWrapper();

		MessageTypes GetType() const;
		MessageContent GetContent() const;


		void SetContent(MessageContent content);

	private:
		MessageTypes m_Type;
		
		// Generic pointer
		MessageContent m_Content;
	};
}