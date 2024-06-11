#include "ImageComponent.h"
#include "MessageWrapper.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <iostream>

dae::ImageComponent::~ImageComponent()
{
}

dae::ImageComponent::ImageComponent(std::string sourcePath, Transform& parentTransform, int zIndex)
	: ImageComponent(sourcePath, parentTransform, Transform{}, zIndex)
{
}

dae::ImageComponent::ImageComponent(std::string sourcePath, Transform& parentTransform, const Transform& relativeTransform, int zIndex)
	: RenderComponent(parentTransform, relativeTransform, zIndex)
	, m_Texture{ ResourceManager::GetInstance().LoadTexture(sourcePath) }
	, m_SourcePath{ sourcePath }
{
}

void dae::ImageComponent::Update()
{
}

void dae::ImageComponent::FixedUpdate()
{
}

void dae::ImageComponent::ReceiveMessage(const MessageWrapper* pMessage)
{
	pMessage->GetType();
}

void dae::ImageComponent::Render() const
{
	Transform transform{ m_ParentTransform + m_RelativeTransform };
	const glm::vec3& position{ transform.GetPosition() };
	Renderer::GetInstance().RenderTexture(*m_Texture, position.x, position.y);
}