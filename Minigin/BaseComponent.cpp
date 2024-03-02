#include "pch.h"
#include "BaseComponent.h"
#include "MessageWrapper.h"


dae::BaseComponent::BaseComponent()
{
}

dae::BaseComponent::~BaseComponent()
{
}

std::vector<dae::MessageWrapper*>& dae::BaseComponent::GetMessages()
{
	return m_Messages;
}