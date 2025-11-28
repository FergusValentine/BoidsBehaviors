#include <iostream>
#include "Boid.h"

Boid::Boid() : m_maxSpeed(1.0f), m_maxForce(0.01f) {}

Boid::Boid(float x, float y, const float maxSpeed, const float maxForce)
	: m_position(x, y), m_maxSpeed(maxSpeed), m_maxForce(maxForce) {}

void Boid::Update(Vector2 target)
{
	Vector2 vec(target.m_x, target.m_y);
	vec = Vector2::Subtract(vec, m_position);
	vec = Vector2::Normalize(vec);
	vec = Vector2::Multiply(vec, m_maxSpeed);
	vec = Vector2::Subtract(vec, m_velocity);
	vec = Vector2::LimitMagnitude(vec, m_maxForce);

	m_steeringForce = Vector2::Add(m_steeringForce, vec);

	// set velocity to target dir, convert to unit vector, scale to max speed
	m_velocity = Vector2::Add(m_velocity, m_steeringForce);
	m_velocity = Vector2::LimitMagnitude(m_velocity, m_maxSpeed);
	m_position = Vector2::Add(m_position, m_velocity);

	m_steeringForce = Vector2(0.0f, 0.0f);

	std::cout << "Boid Position: (" << m_position.m_x << ", " << m_position.m_y << ")\n";
}