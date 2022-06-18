#include "ProperTime.h"
#include "utilities.h"
#include "Constants.h"
#include <iostream>
#include <cmath>
#include <ParticleReco.h>

using namespace std;

 
// constructor
ProperTime::ProperTime() {
}


// destructor
ProperTime::~ProperTime() {
}


// recompute tag informations for new event
void ProperTime::update( const Event& e ) {
  //get the ParticleReco singleton
  static ParticleReco* pr = ParticleReco::instance();
  particleEnergy = pr->get_particleEnergy();
  particleMass = pr->get_particleMass();
  
  //t = d*m/(p*c) d distance, c light velocity, p momentum = sqrt(e^2-m^2), e tot energy, m inv mass 
  time =( sqrt(pow(e.get_x(),2) + pow(e.get_y(),2) + pow(e.get_z(),2)) * particleMass) / (sqrt(pow(particleEnergy,2) - pow(particleMass,2)) * Constants::lightVelocity);
 
  return;

}


// return particle type
ProperTime::ParticleType ProperTime::get_particleType() {
  // check for new event and return result
  check();
  return type;
}


// return particle energy
double ProperTime::get_particleEnergy() {
  // check for new event and return result
  check();
  return particleEnergy;
}


// return particle mass
double ProperTime::get_particleMass() {
  // check for new event and return result
  check();
  return particleMass;
}

//return time
double ProperTime::get_decayTime(){
  //check for new event and return result
  check();
  return time;
}

