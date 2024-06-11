#pragma once
#include "BaseComponent.h"

namespace dae
{
	class RenderComponent  : public BaseComponent
	{
	public:
		RenderComponent(Transform& parentTransform, int zIndex = 0);
		RenderComponent(Transform& parentTransform, const Transform& transform, int zIndex = 0);

		virtual ~RenderComponent();

		virtual void Render() const = 0;
		void Update() override = 0;
		void FixedUpdate() override = 0;
		void ReceiveMessage(const MessageWrapper* pMessage) override = 0;

		unsigned int GetId() const;
		int GetZIndex() const;

		bool operator<(const RenderComponent& other);

		bool operator==(const RenderComponent& other);

	protected:
		int m_zIndex;
		unsigned int m_Id;
	};
}