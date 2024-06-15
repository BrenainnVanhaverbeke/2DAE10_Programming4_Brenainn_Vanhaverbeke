#pragma once
#include "RenderComponent.h"
#include <string>
#include "Transform.h"
#include <SDL_ttf.h>
#include <memory>

namespace dae
{
	class Texture2D;
	class Font;

	class TextComponent final :
		public RenderComponent
	{
	public:
		TextComponent(std::string text, std::string fontPath, int fontSize, Transform& parentTransform, int zIndex = 0);
		TextComponent(std::string text, std::string fontPath, int fontSize, Transform& parentTransform, const Transform& relativeTransform, int zIndex = 0);

		// Inherited via RenderComponent
		virtual void Render() const override;
		virtual void Update() override;
		virtual void FixedUpdate() override;
		virtual void ReceiveMessage(const MessageWrapper* pMessage) override;

		void SetText(const std::string& text);
		std::string  GetText() const;

	private:
		std::string m_Text;
		std::string m_FontPath;
		SDL_Colour m_TextColour;

		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_TextTexture;

		bool m_TextChanged;

		void UpdateText();
	};
}