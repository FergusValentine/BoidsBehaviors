#include "BoidManager.h"

BoidManager::BoidManager(size_t size) : m_Boids(size)
{
	for (int i = 0; i < size; i++)
	{
		Boid newBoid((float)i * 10.0f, (float)i * 10.0f, 2.0f, 0.01f);
		m_Boids.push_back(newBoid);
	}
}

BoidManager::~BoidManager()
{

}

void BoidManager::UpdateBoids()
{
	for (Boid boid : m_Boids)
	{
		boid.Update();
	}
}