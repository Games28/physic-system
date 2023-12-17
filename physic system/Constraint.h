#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include "Body.h"
#include "MatMN.h"

class Constraint
{
public:
	Body* a;
	Body* b;
	
	Vec2f aPoint;
	Vec2f bPoint;

	MatMN GetInvM() const;
	VecN GetVelocities() const;
	virtual void Solve() {}
};

class JointConstraint : public Constraint
{
private:
	MatMN jacobian;


public:
	JointConstraint();
	JointConstraint(Body* a, Body* b, const Vec2f& anchorPoint);
	void Solve() override;

};

class PenetrationConstraint : public Constraint
{
	MatMN jacobian;

};

#endif // !CONSTRAINT_H



