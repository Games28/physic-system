#include "World.h"

World::World(float gravity)
{
	G = -gravity;
	std::cout << "world constructed!" << std::endl;

}

World::~World()
{
	for (auto body : bodies)
	{
		delete body;
	}

	std::cout << "world deconstructed!" << std::endl;
}

void World::AddBody(Body* body)
{
	bodies.push_back(body);
}

std::vector<Body*>& World::GetBodies()
{
	return bodies;
}

void World::AddForce(const Vec2f& force)
{
	forces.push_back(force);
}

void World::AddTorque(float torque)
{
	torques.push_back(torque);
}

void World::AddConstraint(Constraint* constraint)
{
	constraints.push_back(constraint);
}

std::vector<Constraint*>& World::GetConstraints()
{
	return constraints;
}

void World::Update(olc::PixelGameEngine* pge,float dt)
{
	for (auto body : bodies)
	{
		Vec2f weight = Vec2f(0.0f, body->mass * G * PIXELS_PER_METER);
		body->AddForce(weight);

		for (auto force : forces)
		{
			body->AddForce(force);
		}

		for (auto torque : torques)
		{
			body->AddTorque(torque);
		}
	}

	for (auto body : bodies)
	{
		body->IntegrateForces(dt);

	}

	for (auto& constraint : constraints)
	{
		constraint->Solve();
	}

	for (auto body : bodies)
	{
		body->IntegrateVelocities(dt);
	}
	
		CheckCollisions(pge);
	
}

void World::CheckCollisions(olc::PixelGameEngine* ptr)
{
	for (int i = 0; i <= bodies.size() - 1; i++)
	{
		for (int j = i + 1; j < bodies.size(); j++)
		{
			Body* a = bodies[i];
			Body* b = bodies[j];
			Contact contact;
			a->isColliding = false;
			b->isColliding = false;
			if (CollisionDetection::IsColliding(a, b, contact))
			{
				contact.ResolveCollision();
				


			}

		}
	}
}
