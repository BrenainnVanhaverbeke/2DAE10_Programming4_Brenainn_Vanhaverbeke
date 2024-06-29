#include "FpsScript.h"
#include "EngineGlobals.h"
#include "MessageWrapper.h"

dae::FpsScript::FpsScript(Transform& parentTransform)
	: BaseComponent(parentTransform)
	, m_Frames{ 0 }
	, m_AccumulatedTime{ 0 }
	//, m_MaxSamples{ 100 }
	, m_MaxTime{ 1.f }
{
}

void dae::FpsScript::Update()
{
	//float deltaTime{ EngineGlobals::GetDeltaTime() };
	//m_FrameTimes.push_back(deltaTime);
	//m_AccumulatedTime += deltaTime;
	//if (m_MaxSamples < m_FrameTimes.size())
	//{
	//	m_AccumulatedTime -= m_FrameTimes.front();
	//	m_FrameTimes.pop_front();
	//}
	//float fps{ m_FrameTimes.size() / m_AccumulatedTime };
	//std::string messageText{ "FPS: " + std::to_string(fps) };
	//m_Frames = 0;
	//{
	//	using mw = dae::MessageWrapper;
	//	using mt = mw::MessageTypes;

	//	mw::MessageContent messageBody{};
	//	messageBody.stringValue = _strdup(messageText.c_str());
	//	mw* message{ new mw(mt::ChangeText, messageBody) };
	//	m_Messages.push_back(message);
	//}


	m_AccumulatedTime += EngineGlobals::GetDeltaTime();
	++m_Frames;
	if (m_MaxTime < m_AccumulatedTime)
	{
		m_AccumulatedTime -= m_MaxTime;
		std::string messageText{ "FPS: " + std::to_string(m_Frames) };
		m_Frames = 0;
		{
			using mw = dae::MessageWrapper;
			using mt = mw::MessageTypes;

			mw::MessageContent messageBody{};
			messageBody.stringValue = _strdup(messageText.c_str());
			mw* message{ new mw(mt::ChangeText, messageBody) };
			m_Messages.push_back(message);
		}
	}
}

void dae::FpsScript::FixedUpdate()
{
}

void dae::FpsScript::ReceiveMessage(const MessageWrapper* pMessage)
{
	(void)pMessage;
}
