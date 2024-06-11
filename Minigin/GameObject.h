#pragma once
#include <memory>
#include <vector>
#include <queue>
#include "Transform.h"

namespace dae
{
	class Texture2D;
	class BaseComponent;
	class MessageWrapper;

	// todo: this should become final.
	class GameObject
	{
	public:
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
		Transform& GetTransform();

		void AddComponent(std::shared_ptr<BaseComponent>& component);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	protected:
		void AddMessages(const std::shared_ptr<BaseComponent>& component);
		void HandleMessages();

	private:
		template<typename UpdateFunction>
		void UpdateComponents(UpdateFunction updateFunction);

		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};
		std::vector<std::shared_ptr<BaseComponent>> m_Components;
		std::queue<MessageWrapper*> m_MessageQueue;
	};

	template<typename UpdateFunction>
	inline void GameObject::UpdateComponents(UpdateFunction updateFunction)
	{
		for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
		{
			std::shared_ptr<BaseComponent>& component{ *it };
			updateFunction(component);
			AddMessages(component);
		}
	}
}