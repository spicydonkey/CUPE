#include "cupe.h"
#include <iostream>
#include <math.h>

double& PhysicsVector::operator[](int index)
{
	return m_Components[index];
}

PhysicsVector& PhysicsVector::operator=(const std::vector<double>& V)
{
	this->m_Components = V;
	return *this;
}

std::vector<double> PhysicsVector::operator+(const PhysicsVector& V)
{	
	std::vector<double> tmpVect;
	for (int i = 0; i < m_Components.size(); i++)
	{
		tmpVect.push_back(m_Components[i] + V.m_Components[i]);
	}
	return tmpVect;
}

std::vector<double> PhysicsVector::operator+(const std::vector<double>& V)
{
	std::vector<double> tmpVect;
	for (int i = 0; i < m_Components.size(); i++)
	{
		tmpVect.push_back(m_Components[i] + V[i]);
	}
	return tmpVect;
}

std::vector<double> PhysicsVector::operator-(const PhysicsVector& V)
{
	std::vector<double> tmpVect;
	for (int i = 0; i < m_Components.size(); i++)
	{
		tmpVect.push_back(m_Components[i] - V.m_Components[i]);
	}
	return tmpVect;
}

std::vector<double> PhysicsVector::operator-(const std::vector<double>& V)
{
	std::vector<double> tmpVect;
	for (int i = 0; i < m_Components.size(); i++)
	{
		tmpVect.push_back(m_Components[i] - V[i]);
	}
	return tmpVect;
}

std::vector<double> PhysicsVector::operator*(const double& M)
{
	std::vector<double> tmpVect;
	for (int i = 0; i < m_Components.size(); i++)
	{
		tmpVect.push_back(m_Components[i] * M);
	}
	return tmpVect;
}

// Magnitude of a vector in Cartesian coordinates
double PhysicsVector::magnitude()
{
	double mag;
	for (int i = 0; i < m_Components.size(); i++)
	{
		mag += m_Components[i] * m_Components[i];
	}
	mag = sqrt(mag);
	return mag;
}

void Particle::print()
{

}

// Print the current frame
void World::printframe()
{
	printf("Time [%lf]\n",m_Time);
	printf("----------------------\n");

	
}