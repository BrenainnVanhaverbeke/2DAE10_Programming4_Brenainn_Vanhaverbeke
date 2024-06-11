#include "pch.h"
#include "Transform.h"

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

dae::Transform dae::Transform::operator+(const Transform& other)
{
	Transform newTransform{ *this };
	newTransform += other;
	return newTransform;
}

dae::Transform& dae::Transform::operator+=(const Transform& other)
{
	m_position.x += other.GetPosition().x;
	m_position.y += other.GetPosition().y;
	m_position.z += other.GetPosition().z;
	return *this;
}
