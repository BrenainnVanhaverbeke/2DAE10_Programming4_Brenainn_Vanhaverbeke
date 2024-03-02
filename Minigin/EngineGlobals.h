#pragma once

namespace dae
{
	class EngineGlobals final
	{
		friend class Minigin;

	public:
		static const float GetDeltaTime()
		{
			return m_DeltaTime;
		}

		static const float GetFixedTimeStep()
		{
			return m_FixedTimeStep;
		}

	private:
		static void SetDeltaTime(const float deltaTime)
		{
			m_DeltaTime = deltaTime;
		}

		static void SetFixedTimeStep(const float fixedTimeStep)
		{
			m_FixedTimeStep = fixedTimeStep;
			// TODO: Update setting file.
		}

		static float m_DeltaTime;
		static float m_FixedTimeStep;
	};

	float EngineGlobals::m_DeltaTime{ 0 };
	// TODO: Read from setting file.
	float EngineGlobals::m_FixedTimeStep{ 0.02f };
}