#include "Vector2.h"
#include <cmath>

Vector2::Vector2() : m_x(0), m_y(0) {}
Vector2::Vector2(float x, float y) : m_x(x), m_y(y) {}

Vector2 Vector2::Add(const Vector2& a, const Vector2& b)
{
	return Vector2(a.m_x + b.m_x, a.m_y + b.m_y);
}

Vector2 Vector2::Subtract(const Vector2& a, const Vector2& b)
{
	return Vector2(a.m_x - b.m_x, a.m_y - b.m_y);
}

Vector2 Vector2::Multiply(const Vector2& a, const Vector2& b)
{
	return Vector2(a.m_x * b.m_x, a.m_y * b.m_y);
}

Vector2 Vector2::Multiple(const Vector2& a, const float scalar)
{
	return Vector2(a.m_x * scalar, a.m_y * scalar);
}

Vector2 Vector2::Divide(const Vector2& a, const Vector2& b)
{
	return Vector2(a.m_x / a.m_x, a.m_y / a.m_y);
}

Vector2 Vector2::Divide(const Vector2& a, const float scalar)
{
	return Vector2(a.m_x / scalar, a.m_y / scalar);
}

float Vector2::Magnitude(const Vector2& vector)
{
	return std::sqrt(std::pow(vector.m_x, 2.0f) + std::pow(vector.m_y, 2.0f));
}

Vector2 Vector2::Normalize(const Vector2& vector)
{
	const float magnitude = Magnitude(vector);
	if (magnitude == 0.0f)
		return Vector2(0.0f, 0.0f);
	return Vector2(vector.m_x / magnitude, vector.m_y / magnitude);
}

//Vector2 Vector2::Add(const Vector2& vector)
//{
//	return Vector2(this->m_x + vector.m_x, this->m_y + vector.m_y);
//}
//
//Vector2 Vector2::Subtract(const Vector2& vector)
//{
//	return Vector2(this->m_x - vector.m_x, this->m_y - vector.m_y);
//}
//
//Vector2 Vector2::Multiply(const Vector2& vector)
//{
//	return Vector2(this->m_x * vector.m_x, this->m_y * vector.m_y);
//}
//
//Vector2 Vector2::Multiply(const float scalar)
//{
//	return Vector2(this->m_x * scalar, this->m_y * scalar);
//}
//
//void Vector2::Set(const Vector2& vector)
//{
//	this->m_x = vector.m_x;
//	this->m_y = vector.m_y;
//}
//
//float Vector2::Magnitude() const
//{
//	return std::sqrt(std::pow(m_x, 2.0f) + std::pow(m_y, 2.0f));
//}
//
//Vector2 Vector2::Normalize(const Vector2& vector)
//{
//	const float mag = vector.Magnitude();
//	if (mag == 0.0f)
//		return Vector2(0.0f, 0.0f);
//
//	return Vector2(vector.m_x / mag, vector.m_y / mag);
//}
//
//void Vector2::Normalize()
//{
//	const float mag = Magnitude();
//	if (mag <= 0.0f)
//		return; // void division by zero + if mag 0 then vec 0
//
//	m_x = m_x/mag;
//	m_y = m_y/mag;
//}