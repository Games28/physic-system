#ifndef FORCE_H
#define FORCE_H
#include "Vec2.h"
#include "Particle.h"

class Force
{
public:
	Force() = default;

public:
	static Vec2 GenerateDragForce(const Particle& particle, float k);
};

#endif // !FORCE_H



