#ifndef CUPE_H
#define CUPE_H
#include <vector>
#include <string>

class Particle
{
private:
	// Identifier
	std::string mName;

	// General physical properties
	double mMass;
	double mPosition[3];
	double mVelocity[3];
	double mAcceleration[3];
	double mOrientation[3];

	// Collision properties
	double mRadius;
	double mElasticity;

	// Interaction properties
	double mCharge;		// electrical charge
};

class Boundary
{
	enum BCtype { ground, wall, box };

private:
	// Boundary type
	BCtype mType;
	
	// Boundary condition parameters
	std::vector<double> mParams;
};

typedef std::vector<Particle> Ensemble;
typedef std::vector<Boundary> Boundaries;

class World 
{

private:
	// Absolute clock
	double mTime;

	// Particles
	Ensemble mEnsemble;

	// Boundary conditions
	Boundaries mBoundaryConditions;

public:

};

#endif