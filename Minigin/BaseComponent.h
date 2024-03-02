#pragma once
#include <memory>
#include <vector>

namespace dae
{
	class GameObject;
	class MessageWrapper;

	class BaseComponent
	{
	public:
		explicit BaseComponent();
		virtual ~BaseComponent();

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent operator= (const BaseComponent& other) = delete;
		BaseComponent operator= (BaseComponent&& other) = delete;

		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() const = 0;
		virtual void ReceiveMessage(const MessageWrapper* pMessage) = 0;
		virtual std::vector<MessageWrapper*>& GetMessages() final;
		
	protected:
		std::vector<MessageWrapper*> m_Messages;
	};
}