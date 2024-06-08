#pragma once
#include "BaseComponent.h"

namespace dae
{
	class RenderComponent  : public BaseComponent
	{
	public:
		RenderComponent(int zIndex = 0);
		virtual ~RenderComponent();

		virtual void Render() const = 0;
		void Update() override = 0;
		void FixedUpdate() override = 0;
		void ReceiveMessage(const MessageWrapper* pMessage) override = 0;

		unsigned int GetId() const;
		int GetZIndex() const;

		bool operator<(const RenderComponent& other);

		bool operator==(const RenderComponent& other);

	private:
		unsigned int m_Id;
		int m_zIndex;
	};
}