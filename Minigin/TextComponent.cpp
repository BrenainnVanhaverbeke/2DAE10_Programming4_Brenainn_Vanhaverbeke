#include "TextComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <stdexcept>
#include "Font.h"
#include "Texture2D.h"
#include "MessageWrapper.h"
#include <iostream>

dae::TextComponent::TextComponent(std::string text, std::string fontPath, int fontSize, Transform& parentTransform, int zIndex)
	: TextComponent(text, fontPath, fontSize, parentTransform, Transform{}, zIndex)
{
}

dae::TextComponent::TextComponent(std::string text, std::string fontPath, int fontSize, Transform& parentTransform, const Transform& relativeTransform, int zIndex)
	: RenderComponent(parentTransform, relativeTransform, zIndex)
	, m_Text{ text }
	, m_FontPath{ fontPath }
	, m_TextChanged{ true }
	, m_TextColour{ 255, 255, 255, 255 }
	, m_Font{ ResourceManager::GetInstance().LoadFont(fontPath, fontSize) }
{
}

void dae::TextComponent::Render() const
{
	if (m_TextTexture)
	{
		Transform transform{ m_ParentTransform + m_RelativeTransform };
		const glm::vec3& position{ transform.GetPosition() };
		Renderer::GetInstance().RenderTexture(*m_TextTexture, position.x, position.y);
	}
}

void dae::TextComponent::Update()
{
	try
	{
		if (m_TextChanged)
			UpdateText();
	}
	catch (const std::exception&)
	{
		std::cout << "Error updating text.\n";
	}
}

void dae::TextComponent::FixedUpdate()
{
}

void dae::TextComponent::ReceiveMessage(const MessageWrapper* pMessage)
{
	if (pMessage->GetType() == MessageWrapper::MessageTypes::ChangeText)
	{
		SetText(pMessage->GetContent().stringValue);
	}
}

void dae::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_TextChanged = true;
}

std::string dae::TextComponent::GetText() const
{
	return m_Text;
}

void dae::TextComponent::UpdateText()
{
	std::cout << "Received text: " << m_Text << std::endl;
	const auto surface{ TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), m_TextColour) };
	if (surface == nullptr)
		throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
	auto texture{ SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surface) };
	if (texture == nullptr)
		throw std::runtime_error(std::string("Create text texture from surface failed.") + SDL_GetError());
	SDL_FreeSurface(surface);
	m_TextTexture = std::make_shared<Texture2D>(texture);
	m_TextChanged = false;
}