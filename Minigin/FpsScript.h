#pragma once
#include "BaseComponent.h"
#include <deque>

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
		//const int m_MaxSamples;

		//std::deque<float> m_FrameTimes;
		short m_Frames;
		float m_AccumulatedTime;
		float m_MaxTime;

	};
}

