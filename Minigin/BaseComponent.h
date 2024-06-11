#pragma once
#include <memory>
#include <vector>
#include "Transform.h"
#include <ostream>

namespace dae
{
	class MessageWrapper;

	class BaseComponent
	{
	public:
		BaseComponent(Transform& parentTransform);
		BaseComponent(Transform& parentTransform, const Transform& relativeTransform);
		virtual ~BaseComponent();

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent operator= (const BaseComponent& other) = delete;
		BaseComponent operator= (BaseComponent&& other) = delete;

		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		virtual void ReceiveMessage(const MessageWrapper* pMessage) = 0;
		virtual std::vector<MessageWrapper*>& GetMessages() final;
		virtual void SetTransform(const Transform& transform) final;

	protected:
		Transform& m_ParentTransform;
		Transform m_RelativeTransform;

		std::vector<MessageWrapper*> m_Messages;
	};
}