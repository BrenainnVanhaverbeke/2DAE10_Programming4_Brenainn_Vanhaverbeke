#include "ImageComponent.h"
#include "MessageWrapper.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::ImageComponent::~ImageComponent()
{
}

dae::ImageComponent::ImageComponent(std::string sourcePath)
	: RenderComponent()
	, m_Texture{ ResourceManager::GetInstance().LoadTexture(sourcePath) }
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
	Renderer::GetInstance().RenderTexture(*m_Texture, 0, 0);
}
