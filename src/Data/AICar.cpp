/**
 * @file AICar.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe AICar.
**/

#include "AICar.hpp"

#include <sstream> //pour les conversions en chaine

#include "Car.hpp"
#include "../Constants.hpp"
#include "../Point.hpp"


using namespace std;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
AICar::AICar() : Car()
{
	reset();
}

//DESTRUCTEUR
//------------------------------------------------------------------------------
AICar::~AICar()
{}

//METHODES
//------------------------------------------------------------------------------
void AICar::reset()
{
		Car::reset();
		for (int i = 0; i < MAX_ANGLE; ++i) {
			oldAngle_[i] = 0;
		}
		positionTrajectoire_ = 0;
		vitesseMaxi_ = VITESSE_AVANT_MAXI;
		variationVitesseMaxi_ = DELTA_VARIATION_VITESSE_MAXI;
}

//------------------------------------------------------------------------------
std::string AICar::toString()
{
	stringstream sst;
	stringstream sstOldAngle;
	sstOldAngle <<" (";
	for(int i; i< MAX_ANGLE; ++i)
	{
		sstOldAngle << oldAngle_[i] << ", ";
	}
	sstOldAngle << sstOldAngle << ")";
	sst << "VoitureIA [positionTrajectoire=" << positionTrajectoire_ << ", oldAngle=" << sstOldAngle
		<< ", vitesseMaxi=" << vitesseMaxi_ << ", variationVitesseMaxi=" << variationVitesseMaxi_ << "]";
	return sst.str();
}

//ACCESSEURS
//------------------------------------------------------------------------------
int AICar::getPositionTrajectoire()
{
		return positionTrajectoire_;
}

//------------------------------------------------------------------------------
double AICar::getVitesseMaxi()
{
		return vitesseMaxi_;
}

//------------------------------------------------------------------------------
double AICar::getVariationVitesseMaxi()
{
		return variationVitesseMaxi_;
}
/*
//------------------------------------------------------------------------------
double[] AICar::getOldAngle()
{
		return oldAngle_;
}
*/
//------------------------------------------------------------------------------
double AICar::getOneOldAngle(int indice)
{
		return oldAngle_[indice];
}

//MUTATEURS
//------------------------------------------------------------------------------
void AICar::setPositionTrajectoire (int positionTrajectoire)
{
		positionTrajectoire_ = positionTrajectoire;
}
	
//------------------------------------------------------------------------------
void AICar::setVitesseMaxi (double vitesseMaxi)
{
		vitesseMaxi_ = vitesseMaxi;
}

//------------------------------------------------------------------------------
void AICar::setVariationVitesseMaxi (double variationVitesseMaxi)
{
		variationVitesseMaxi_ = variationVitesseMaxi;
}

//------------------------------------------------------------------------------
void AICar::setOneOldAngle(double angle, int indice)
{
		oldAngle_[indice] = angle;
}