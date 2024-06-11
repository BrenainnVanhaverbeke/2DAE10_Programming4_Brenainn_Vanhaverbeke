#include "RenderComponent.h"
#include "Renderer.h"
#include <iostream>

dae::RenderComponent::RenderComponent(Transform& parentTransform, int zIndex)
	: RenderComponent(parentTransform, Transform{}, zIndex)
{
}

dae::RenderComponent::RenderComponent(Transform& parentTransform, const Transform& transform, int zIndex)
	: BaseComponent(parentTransform, transform)
	, m_zIndex{ zIndex }
	, m_Id{ Renderer::GetInstance().GetNextId() }
{
	Renderer::GetInstance().RegisterComponent(this);
}

dae::RenderComponent::~RenderComponent()
{
	Renderer::GetInstance().DeregisterComponent(this);
}

unsigned int dae::RenderComponent::GetId() const
{
	return m_Id;
}

int dae::RenderComponent::GetZIndex() const
{
	return m_zIndex;
}

bool dae::RenderComponent::operator<(const RenderComponent& other)
{
	if (m_zIndex != other.m_zIndex) {
		return m_zIndex < other.m_zIndex;
	}
	return m_Id < other.m_Id; // Secondary criterion
}

bool dae::RenderComponent::operator==(const RenderComponent& other)
{
	return m_Id == other.m_Id && m_zIndex == other.m_zIndex;
}
