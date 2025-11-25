#include "Boid.h"

Boid::Boid() : m_maxSpeed(1.0f), m_maxForce(0.01f) {}

Boid::Boid(float x, float y, float maxSpeed, float maxForce) 
	: m_position(x, y), m_maxSpeed(maxSpeed), m_maxForce(maxForce) {}