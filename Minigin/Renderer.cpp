#include "pch.h"
#include <stdexcept>
#include "Renderer.h"
#include "SceneManager.h"
#include "Texture2D.h"
#include "RenderComponent.h"

int GetOpenGLDriverIndex()
{
	auto openglIndex = -1;
	const auto driverCount = SDL_GetNumRenderDrivers();
	for (auto i = 0; i < driverCount; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
			if (!strcmp(info.name, "opengl"))
				openglIndex = i;
	}
	return openglIndex;
}

void dae::Renderer::Init(SDL_Window* window)
{
	m_window = window;
	m_renderer = SDL_CreateRenderer(window, GetOpenGLDriverIndex(), SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
}

void dae::Renderer::Render() const
{
	const auto& color = GetBackgroundColor();
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer);

	//SceneManager::GetInstance().Render();

	
	SDL_RenderPresent(m_renderer);
	RenderComponents();
}

void dae::Renderer::Destroy()
{
	if (m_renderer != nullptr)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y, const float width, const float height) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(width);
	dst.h = static_cast<int>(height);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

SDL_Renderer* dae::Renderer::GetSDLRenderer() const { return m_renderer; }

unsigned int dae::Renderer::RegisterComponent(std::shared_ptr<RenderComponent> component)
{
	m_RenderComponents.insert(component);
	return m_NextId++;
}

void dae::Renderer::DeregisterComponent(std::shared_ptr<RenderComponent> component)
{
	auto it{ m_RenderComponents.find(component) };
	if (it != m_RenderComponents.end())
		m_RenderComponents.erase(it);
}

//unsigned int dae::Renderer::RegisterComponent(RenderComponent* component)
//{
//	unsigned int givenId{ m_NextId };
//	++m_NextId;
//	return givenId;
//}
//
//void dae::Renderer::DeregisterComponent(RenderComponent* component)
//{
//
//}
//
//void dae::Renderer::DeregisterComponent(unsigned int id)
//{
//	RenderComponent* test{};
//	//auto zIndices{ m_RenderComponents.equal_range(test) };
//	//auto iterator{ m_RenderComponents.find(id) };
//	//if (iterator != m_RenderComponents.end())
//	//{
//	//	m_RenderComponents.erase(iterator);
//	//}
//}


void dae::Renderer::RenderComponents() const
{
	for (auto iterator{ m_RenderComponents.begin() }; iterator != m_RenderComponents.end(); ++iterator)
	{
		(*iterator)->Render();
	}
}
