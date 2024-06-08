#include "RenderComponent.h"
#include "Renderer.h"
#include <memory>

dae::RenderComponent::RenderComponent(int zIndex)
	: BaseComponent()
	, m_Id{ Renderer::GetInstance().RegisterComponent(std::shared_ptr<RenderComponent>(this)) }
	, m_zIndex{ zIndex }
{
}

dae::RenderComponent::~RenderComponent()
{
	Renderer::GetInstance().DeregisterComponent(std::shared_ptr<RenderComponent>(this));
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
	return m_zIndex <= other.m_zIndex;
}

bool dae::RenderComponent::operator==(const RenderComponent& other)
{
	return m_Id == other.m_Id && m_zIndex == other.m_zIndex;
}
