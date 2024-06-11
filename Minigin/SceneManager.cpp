#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update()
{
	for(auto i = m_scenes.begin(); i != m_scenes.end(); ++i)
	{
		(*i)->Update();
	}
}

void dae::SceneManager::FixedUpdate()
{
	for (auto i = m_scenes.begin(); i != m_scenes.end(); ++i)
	{
		(*i)->FixedUpdate();
	}
}

void dae::SceneManager::Render()
{
	for (auto i = m_scenes.begin(); i != m_scenes.end(); ++i)
	{
		(*i)->Render();
	}
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}