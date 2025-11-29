#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	Vector2 operator+(const Vector2& vector) const;
	Vector2 operator-(const Vector2& vector) const;
	Vector2 operator*(const Vector2& vector) const;
	Vector2 operator*(const float scalar) const;
	Vector2 operator/(const Vector2& vector) const;
	Vector2 operator/(const float scalar) const;

	Vector2& operator+=(const Vector2& vector);
	Vector2& operator-=(const Vector2& vector);
	Vector2& operator*=(const Vector2& vector);
	Vector2& operator*=(const float scalar);
	Vector2& operator/=(const Vector2& vector);
	Vector2& operator/=(const float scalar);

	float Magnitude() const;
	Vector2 Normalized() const;
	Vector2 LimitMagnitude(const float limit) const;

	float m_x;
	float m_y;
private:
	Vector2 Add(const Vector2& vec) const;
	Vector2 Subtract(const Vector2& vec) const;
	Vector2 Multiply(const Vector2& vec) const;
	Vector2 Multiply(const float scalar) const;
	Vector2 Divide(const Vector2& vec) const;
	Vector2 Divide(const float scalar) const;

	float Magnitude(const Vector2& vector) const;
	Vector2 Normalized(const Vector2& vector) const;
	Vector2 LimitMagnitude(const Vector2& vector, const float maxMagnitude) const;
};