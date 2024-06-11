#pragma once
#include <SDL.h>
#include <unordered_map>
#include <set>
#include <memory>
#include "Singleton.h"

namespace dae
{
	class Texture2D;
	class RenderComponent;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
		SDL_Renderer* m_renderer{};
		SDL_Window* m_window{};
		SDL_Color m_clearColor{};	
	public:
		void Init(SDL_Window* window);
		void Render() const;
		void Destroy();

		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, float x, float y, float width, float height) const;

		SDL_Renderer* GetSDLRenderer() const;

		const SDL_Color& GetBackgroundColor() const { return m_clearColor; }
		void SetBackgroundColor(const SDL_Color& color) { m_clearColor = color; }

		unsigned int GetNextId();
		void RegisterComponent(RenderComponent* component);
		void DeregisterComponent(RenderComponent* component);

	private: 
		struct RenderComponentComparer {
			bool operator() (const RenderComponent* lhs, const RenderComponent* rhs) const;
		};
		//std::unordered_map<unsigned int, RenderComponent*> m_RenderComponents;
		std::multiset<RenderComponent*, RenderComponentComparer> m_RenderComponents;
		unsigned int m_NextId{ 0 };


		void RenderComponents() const;
	};
}