#include <iostream>
#include "Boid.h"

Boid::Boid() : m_maxSpeed(1.0f), m_maxForce(0.01f) {}

Boid::Boid(float x, float y, const float maxSpeed, const float maxForce)
	: m_position(x, y), m_maxSpeed(maxSpeed), m_maxForce(maxForce) {}

void Boid::Update(Vector2 target)
{
	// set velocity to target dir, convert to unit vector, scale to max speed
	m_velocity = Vector2::Subtract(target, m_position);
	m_velocity = Vector2::Normalize(m_velocity);
	m_velocity = Vector2::Multiple(m_velocity, m_maxSpeed);
	
	m_position = Vector2::Add(m_position, m_velocity);
	std::cout << "Boid Position: (" << m_position.m_x << ", " << m_position.m_y << ")\n";
}