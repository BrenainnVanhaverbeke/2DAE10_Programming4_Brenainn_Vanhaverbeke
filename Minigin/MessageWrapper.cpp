#include "pch.h"
#include "MessageWrapper.h"

dae::MessageWrapper::MessageWrapper(dae::MessageWrapper::MessageTypes type)
	: m_Type{ type }
{
}

dae::MessageWrapper::~MessageWrapper()
{
}

dae::MessageWrapper::MessageTypes dae::MessageWrapper::GetType() const
{
	return m_Type;
}