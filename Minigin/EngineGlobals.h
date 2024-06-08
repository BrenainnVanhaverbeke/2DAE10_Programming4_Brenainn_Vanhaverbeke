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
			// TODO: Get time step from setting file.
		}

		static float m_DeltaTime;
		static float m_FixedTimeStep;
	};
}