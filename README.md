# clockwork-universe

## Description
A physics engine aimed at observing complexity in macroscopic structure built from simple building blocks

## Program structure
The Clockwork-Universe physics engine simulates a **world** according to the **Theory of Everything** (ToE) that govern all internal interactions of the world. Compuatation relies on numerical solvers defined in **processor**.

### World
* Physical constant
  * gravitational acceleration/const
  * Coulomb's constant
* Clock
  * time (absolute) 
* Thing
  * General
    * mass
    * position
    * velocity
    * acceleration
  * Collision 
    * collision hull
    * elasticity/inelasticity
  * Charge
    * gravitational (mass)
    * electrical
    * etc. (interaction specific)
  * Advanced
    * orientation (point approximation of a rigid body)
    * rotational axis
    * rotational velocity
* Boundary
  * General types
    * ground
    * wall
    * box
    * platform
    * etc.
  
### Theory of Everything (ToE)
* Interactions/Forces
  * Gravitation
  * Electrostatics
  * Collision kinetics
  * etc.

### Processor
* ODEsolver: Solving *physics* as the dynamics of a system of ODEs
* NumIntegrator: Simple numerical integration of acceleration to evolve *world*
