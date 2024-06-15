#include "pch.h"
#include "MessageWrapper.h"

dae::MessageWrapper::MessageWrapper(MessageWrapper::MessageTypes type, MessageContent content)
	: m_Type{ type }
	, m_Content{ content }
{
}

dae::MessageWrapper::~MessageWrapper()
{
	if (m_Content.stringValue != nullptr)
	{
		delete m_Content.stringValue;
		m_Content.stringValue = nullptr;
	}
}

dae::MessageWrapper::MessageTypes dae::MessageWrapper::GetType() const
{
	return m_Type;
}

dae::MessageWrapper::MessageContent dae::MessageWrapper::GetContent() const
{
	return m_Content;
}

void dae::MessageWrapper::SetContent(MessageContent content)
{
	m_Content = content;
}
