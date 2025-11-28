#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	static Vector2 Add(const Vector2& a, const Vector2& b);

	static Vector2 Subtract(const Vector2& a, const Vector2& b);
	
	static Vector2 Multiply(const Vector2& a, const Vector2& b);
	static Vector2 Multiply(const Vector2& a, const float scalar);

	static Vector2 Divide(const Vector2& a, const Vector2& b);
	static Vector2 Divide(const Vector2& a, const float scalar);
	
	static float Magnitude(const Vector2& vector);
	static Vector2 Normalize(const Vector2& vector);

	static Vector2 LimitMagnitude(const Vector2& vector, const float maxMagnitude);

	//float Magnitude() const;
	////Vector2 Magnitude(Vector2& vector);

	//void Normalize();
	//static Vector2 Normalize(const Vector2& vector);
	//
	float m_x;
	float m_y;
};