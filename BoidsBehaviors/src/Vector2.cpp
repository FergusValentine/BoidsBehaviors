#include "Vector2.h"
#include <cmath>
#include <iostream>

Vector2::Vector2() : m_x(0), m_y(0) {}
Vector2::Vector2(float x, float y) : m_x(x), m_y(y) {}

// operators
Vector2 Vector2::operator+(const Vector2& vec) const{ return Add(vec);}
Vector2 Vector2::operator-(const Vector2& vec) const{ return Subtract(vec);}
Vector2 Vector2::operator*(const Vector2& vec) const{ return Multiply(vec);}
Vector2 Vector2::operator*(const float scalar) const{ return Multiply(scalar);}
Vector2 Vector2::operator/(const Vector2& vec) const{ return Divide(vec);}
Vector2 Vector2::operator/(const float scalar) const{ return Divide(scalar);}

// assignment operators
Vector2& Vector2::operator+=(const Vector2& vec){*this = *this + vec;return *this;}
Vector2& Vector2::operator-=(const Vector2& vec){*this = *this - vec;return *this;  }
Vector2& Vector2::operator*=(const Vector2& vec){*this = *this * vec;return *this;}
Vector2& Vector2::operator*=(const float scalar){*this = *this * scalar;return *this;}
Vector2& Vector2::operator/=(const Vector2& vec){*this = *this / vec;return *this;}
Vector2& Vector2::operator/=(const float scalar){*this = *this / scalar;return *this;}

// math operations
Vector2 Vector2::Add(const Vector2& vec) const{	return Vector2(m_x + vec.m_x, m_y + vec.m_y);}
Vector2 Vector2::Subtract(const Vector2& vec) const{ return Vector2(m_x - vec.m_x, m_y - vec.m_y);}
Vector2 Vector2::Multiply(const Vector2& vec) const{ return Vector2(m_x * vec.m_x, m_y * vec.m_y);}
Vector2 Vector2::Multiply(const float scalar) const{ return Vector2(m_x * scalar, m_y * scalar);}
Vector2 Vector2::Divide(const Vector2& vec) const{return Vector2(m_x / vec.m_x, m_y / vec.m_y);}
Vector2 Vector2::Divide(const float scalar) const{	return Vector2(m_x / scalar, m_y / scalar);}

// math functions
float Vector2::Magnitude() const{ return Magnitude(*this); }
float Vector2::Magnitude(const Vector2& vector) const
{
	return std::sqrt(std::pow(vector.m_x, 2.0f) + std::pow(vector.m_y, 2.0f));
}

Vector2 Vector2::Normalized() const{ return Normalized(*this); }
Vector2 Vector2::Normalized(const Vector2& vector) const
{
	const float magnitude = Magnitude(vector);
	if (magnitude == 0.0f)
		return Vector2(0.0f, 0.0f);
	return Vector2(vector.m_x / magnitude, vector.m_y / magnitude);
}

Vector2 Vector2::LimitMagnitude(const float limit) const{ return LimitMagnitude(*this, limit); }
Vector2 Vector2::LimitMagnitude(const Vector2& vector, const float maxMagnitude) const
{
	const float magnitude = Magnitude(vector);
	
	if (magnitude < maxMagnitude)
		return vector;
	else
	{
		Vector2 normal = Normalized(vector);
		return (normal * maxMagnitude);
	}
}