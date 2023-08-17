#ifndef PARTICLE_H
#define PARTICLE_H
#include "Vec2.h"


struct Particle
{
	int radius;
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	float mass;

	Particle(float x, float y, float mass);
	~Particle();
	void integrate(float deltatime);
};
#endif // !PARTICLE_H


