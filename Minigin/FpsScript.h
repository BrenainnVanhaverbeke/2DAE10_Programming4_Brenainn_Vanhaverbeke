#pragma once
#include "BaseComponent.h"
namespace dae
{
	class FpsScript :
		public BaseComponent
	{
	public:
		FpsScript(Transform& parentTransform);

		// Inherited via BaseComponent
		virtual void Update() override;
		virtual void FixedUpdate() override;
		virtual void ReceiveMessage(const MessageWrapper* pMessage) override;
	
	private:
		short m_Frames;
		float m_AccumulatedTime;
		float m_MaxTime;
	};
}

