#pragma once

#include <vector>
#include "Boid.h"

class BoidManager
{
public:
	BoidManager(size_t size);
	void UpdateBoids();
private:
	std::vector<Boid> m_Boids;
};

