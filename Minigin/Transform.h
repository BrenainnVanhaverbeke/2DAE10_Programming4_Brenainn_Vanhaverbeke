#pragma once
#include <glm/glm.hpp>

namespace dae
{
	class Transform final
	{
	public:
		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);

		Transform operator+(const Transform& other);
		Transform& operator+=(const Transform& other);
	private:
		glm::vec3 m_position;
	};
}
