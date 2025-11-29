#include <iostream>
#include "Boid.h"

Boid::Boid() : m_maxSpeed(1.0f), m_maxForce(0.01f) {}

Boid::Boid(float x, float y, const float maxSpeed, const float maxForce)
	: m_position(x, y), m_maxSpeed(maxSpeed), m_maxForce(maxForce) {}

void Boid::Update(Vector2 target)
{
	//SEEK BEHAVIOR//
	//calculate unit vector to target, scale to max_speed
	//calculate difference between current velocity and target vector, scale by max_force
	Vector2 vec(target.m_x, target.m_y);
	vec = (vec - m_position).Normalized() * m_maxSpeed;
	vec = (vec - m_velocity).LimitMagnitude(m_maxForce);

	//add all steering behaviors
	m_steeringForce += vec;

	//add new steering force to m_velocity, add to position for new position
	m_velocity = (m_velocity + m_steeringForce).LimitMagnitude(m_maxSpeed);
	m_position += m_velocity;
	
	m_steeringForce = Vector2(0.0f, 0.0f);

	//std::cout << "Boid Position: (" << m_position.m_x << ", " << m_position.m_y << ")\n";
}