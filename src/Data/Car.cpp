/**
 * @file Car.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe Car.
**/

#include "Car.hpp"

#include <sstream> //pour les conversions en chaine

#include "../Constants.hpp"
#include "../Point.hpp"

using namespace std;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
Car::Car()
{
	reset();
}

//DESTRUCTEUR
//------------------------------------------------------------------------------
Car::~Car()
{}

//METHODES
//------------------------------------------------------------------------------
void Car::reset()
{
	point_.setX(X_BASE_TRAJECTOIRE);
	point_.setY(Y_BASE_TRAJECTOIRE);
	oldPoint_.setX(point_.getX());
	oldPoint_.setY(point_.getY());
	vitesse_ = 0.0;
	angle_ = 0.0;
	place_ = 0;
	secteur_ = 1;
	tour_ = 1;
	oldSecteur_ = 0;
	secteurAtteint_ = 1;
	accelere_ = false;
	freine_ = false;
	left_ = false;
	right_ = false;
	collision_ = 0;
	courseTerminee_ = false;
	etatGlissade_ = 0.0;
	etatSaut_ = 0.0;
}

//------------------------------------------------------------------------------
//string Car::toString() const
//{
	//stringstream sst;
	//sst <<"Voiture [Point=" << point_ /*<< ", oldPoint_=" << oldPoint_ */<< ", vitesse=" << vitesse_
	//		<< ", angle=" << angle_ /*<< ", tour=" << tour_ << ", place=" << place_ << ", secteur=" << secteur_ << ", oldSecteur="
	//		<< oldSecteur_ << ", secteurAtteint=" << secteurAtteint_ */<< ", accelere=" << accelere_ << ", freine=" << freine_
	//		<< ", left=" << left_ << ", right=" << right_ /*<< ", collision=" << collision_ << ", courseTerminee="
	//		<< courseTerminee_ << ", etatGlissade=" << etatGlissade_ << ", angleGlissade=" << angleGlissade_ << ", etatSaut="
	//		<< etatSaut_ */<< "]"
	//return sst.str();
//}

//ACCESSEURS
//------------------------------------------------------------------------------
Point Car::getPoint() const
{
	return point_;
}

//------------------------------------------------------------------------------
Point Car::getOldPoint() const
{
	return oldPoint_;
}

//------------------------------------------------------------------------------
double Car::getVitesse() const
{
	return vitesse_;
}

//------------------------------------------------------------------------------
double Car::getAngle() const
{
	return angle_;
}

//------------------------------------------------------------------------------
int Car::getTour() const
{
	return tour_;
}

//------------------------------------------------------------------------------
int Car::getPlace() const
{
	return place_;
}

//------------------------------------------------------------------------------
int Car::getSecteur() const
{
	return secteur_;
}

//------------------------------------------------------------------------------
int Car::getOldSecteur() const
{
	return oldSecteur_;
}

//------------------------------------------------------------------------------
int Car::getSecteurAtteint() const
{
	return secteurAtteint_;
}

//------------------------------------------------------------------------------
bool Car::isAccelere() const
{
	return accelere_;
}

//------------------------------------------------------------------------------
bool Car::isFreine() const
{
	return freine_;
}

//------------------------------------------------------------------------------
bool Car::isLeft() const
{
	return left_;
}

//------------------------------------------------------------------------------
bool Car::isRight() const
{
	return right_;
}

//------------------------------------------------------------------------------
int Car::getCollision() const
{
	return collision_;
}

//------------------------------------------------------------------------------
bool Car::isCourseTerminee() const
{
	return courseTerminee_;
}

//------------------------------------------------------------------------------
double Car::getEtatGlissade() const
{
	return etatGlissade_;
}

//------------------------------------------------------------------------------
double Car::getEtatSaut() const
{
	return etatSaut_;
}

//------------------------------------------------------------------------------
double Car::getAngleGlissade() const
{
	return angleGlissade_;
}

//MUTATEURS
//------------------------------------------------------------------------------
void Car::setPoint(Point point)
{
	point_ = point;
}

//------------------------------------------------------------------------------
void Car::setOldPoint(Point oldPoint)
{
	oldPoint_ = oldPoint;
}

//------------------------------------------------------------------------------
void Car::setVitesse(double vitesse)
{
	vitesse_ = vitesse;
}

//------------------------------------------------------------------------------
void Car::setAngle(double angle)
{
	angle_ = angle;

}

//------------------------------------------------------------------------------
void Car::setTour(int tour)
{
	tour_ = tour;
}

//------------------------------------------------------------------------------
void Car::setPlace(int place)
{
	place_ = place;
}

//------------------------------------------------------------------------------
void Car::setSecteur(int secteur)
{
	secteur_ = secteur;
}

//------------------------------------------------------------------------------
void Car::setOldSecteur(int oldSecteur)
{
	oldSecteur_ = oldSecteur;
}

//------------------------------------------------------------------------------
void Car::setSecteurAtteint(int secteurAtteint)
{
	secteurAtteint_ = secteurAtteint;
}

//------------------------------------------------------------------------------
void Car::setAccelere(bool accelere)
{
	accelere_ = accelere;
}

//------------------------------------------------------------------------------
void Car::setFreine(bool freine)
{
	freine_ = freine;
}

//------------------------------------------------------------------------------
void Car::setLeft(bool left)
{
	left_ = left;
}

//------------------------------------------------------------------------------
void Car::setRight(bool right)
{
	right_ = right;
}

//------------------------------------------------------------------------------
void Car::setCollision(int collision)
{
	collision_ = collision;
}

//------------------------------------------------------------------------------
void Car::setCourseTerminee(bool courseTerminee)
{
	courseTerminee_ = courseTerminee;
}

//------------------------------------------------------------------------------
void Car::setEtatGlissade(double etatGlissade)
{
	etatGlissade_ = etatGlissade;
}

//------------------------------------------------------------------------------
void Car::setAngleGlissade(double angleGlissade)
{
	angleGlissade_ = angleGlissade;
}

//------------------------------------------------------------------------------
void Car::setEtatSaut(double etatSaut)
{
	etatSaut_ = etatSaut;
}
