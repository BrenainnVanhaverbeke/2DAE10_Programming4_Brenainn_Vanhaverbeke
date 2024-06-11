#include "pch.h"
#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
#include "MessageWrapper.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	UpdateComponents([](std::shared_ptr<BaseComponent>& component)
	{
		component->Update();
	});
	HandleMessages();
}

void dae::GameObject::FixedUpdate()
{
	UpdateComponents([](std::shared_ptr<BaseComponent>& component)
	{
		component->FixedUpdate();
	});
	HandleMessages();
}

void dae::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

dae::Transform& dae::GameObject::GetTransform()
{
	return m_transform;
}

void dae::GameObject::AddComponent(std::shared_ptr<BaseComponent>& component)
{
	m_Components.push_back(component);
}

void dae::GameObject::AddMessages(const std::shared_ptr<BaseComponent>& component)
{
	std::vector<dae::MessageWrapper*>& messages{ component->GetMessages() };
	for (MessageWrapper* pMessage : messages)
		m_MessageQueue.push(pMessage);

}

void dae::GameObject::HandleMessages()
{
	while (!m_MessageQueue.empty())
	{
		MessageWrapper* pMessage{ m_MessageQueue.front() };
		for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
		{
			std::shared_ptr<BaseComponent>& component{ *it };
			component->ReceiveMessage(pMessage);
		}
		delete pMessage;
		pMessage = nullptr;
		m_MessageQueue.pop();
	}
}