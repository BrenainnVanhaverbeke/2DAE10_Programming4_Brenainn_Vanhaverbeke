#include "pch.h"
#include "BaseComponent.h"
#include "MessageWrapper.h"



dae::BaseComponent::BaseComponent(Transform& parentTransform)
	: BaseComponent(parentTransform, Transform{})
{
}

dae::BaseComponent::BaseComponent(Transform& parentTransform, const Transform& transform)
	: m_ParentTransform{ parentTransform }
	, m_RelativeTransform{ transform }
{
}

dae::BaseComponent::~BaseComponent()
{
}

std::vector<dae::MessageWrapper*>& dae::BaseComponent::GetMessages()
{
	return m_Messages;
}

void dae::BaseComponent::SetTransform(const Transform& transform)
{
	m_RelativeTransform = transform;
}
