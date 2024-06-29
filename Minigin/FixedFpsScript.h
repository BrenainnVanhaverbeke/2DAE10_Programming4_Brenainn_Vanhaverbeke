#pragma once
#include "BaseComponent.h"

namespace dae
{
	class FixedFpsScript : public BaseComponent
	{
	public:
		FixedFpsScript(Transform& parentTransform);

		// Inherited via BaseComponent
		void Update() override;
		void FixedUpdate() override;
		void ReceiveMessage(const MessageWrapper* pMessage) override;

	private:
		short m_Frames;
		float m_AccumulatedTime;
		float m_MaxTime;
	};
}

