#pragma once

#include "Vector2.h"

class Boid
{
public:
	Boid();
	Boid(float x, float y, float maxSpeed, float maxForce);
	void Update(const Vector2 target);

	float m_maxSpeed;
	float m_maxForce;

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_steeringForce;
};