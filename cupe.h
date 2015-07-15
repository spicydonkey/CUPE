#ifndef CUPE_H
#define CUPE_H
#include <vector>
#include <string>

class PhysicsVector
{
private:
	// vector components
	std::vector<double> m_Components;

public:
	PhysicsVector() {}
	PhysicsVector(std::vector<double> vect) { m_Components.assign(vect.begin(),vect.end()); }
	~PhysicsVector() {}

	// Assignment
	PhysicsVector &operator=(const std::vector<double>& V);
	// Vector addition
	std::vector<double> operator+(const PhysicsVector& V);
	std::vector<double> operator+(const std::vector<double>& V);
	// Vector subtraction
	std::vector<double> operator-(const PhysicsVector& V);
	std::vector<double> operator-(const std::vector<double>& V);
	// Vector scaling
	std::vector<double> operator*(const double& M);
	
	double &operator[](int index);

	double magnitude();

	std::vector<double>& components() { return m_Components; }

};

class Particle
{
private:
	// Identifier
	std::string m_Name;

	// General physical properties
	double m_Mass;
	PhysicsVector m_Displacement, m_Velocity, m_Accerlation;

	// Collision properties
	double m_Radius, m_Elasticity;

	// Interaction properties
	double m_Charge;

public:
	Particle() {}
	~Particle() {}

	std::string& name() { return m_Name; }
	
	double& mass() { return m_Mass; }
	
	PhysicsVector& displacement() { return m_Displacement; }
	PhysicsVector& velocity() { return m_Velocity; }
	PhysicsVector& acceleration() { return m_Accerlation; }

	double& radius() { return m_Radius; }
	double& elasticity() { return m_Elasticity; }

	double& charge() { return m_Charge; }

	void print();
};

class Boundary
{
	enum BCtype { ground, wall, box };

private:
	// Boundary type
	BCtype m_Type;
	
	// Boundary condition parameters
	std::vector<double> m_Params;
};

typedef std::vector<Particle> Ensemble;
typedef std::vector<Boundary> Boundaries;

class World 
{

private:
	// Absolute clock
	double m_Time;

	// Particles
	Ensemble m_Ensemble;

	// Boundary conditions
	Boundaries m_BoundaryConditions;

public:
	World() : m_Time(0.0)
	{ 
	}
	~World() {}

	double& time() { return m_Time; }
	int size() { return m_Ensemble.size(); }
	Ensemble& ensemble() { return m_Ensemble; }
	Boundaries& boundaryconditions() { return m_BoundaryConditions; }

	// Print the current frame
	void printframe();
	
};

#endif