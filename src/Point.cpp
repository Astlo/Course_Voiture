/**
 * @file Point.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe Point.
**/

#include "Point.hpp"
#include <cmath> //pour les fonctions mathématiques
#include <sstream> //pour les conversions en chaine

using namespace std;

//CONSTRUCTEURS
//------------------------------------------------------------------------------
Point::Point() : x_ (0), y_ (0)
{}

//------------------------------------------------------------------------------
Point::Point(unsigned x, unsigned y) : x_ (x), y_ (y)
{}

//DESTRUCTEUR
//------------------------------------------------------------------------------
Point::~Point()
{}

//METHODES
//------------------------------------------------------------------------------
double Point::distancePoint(const Point & autre)
{
	return sqrt( (autre.getX() - x_)*(autre.getX() - x_) + (autre.getY() - y_)*(autre.getY() - y_) );
}

//------------------------------------------------------------------------------
void Point::deplacer(unsigned dx, unsigned dy)
{
	x_ = x_ + dx;
	y_ = y_ + dy;
}

//------------------------------------------------------------------------------
bool Point::equals(const Point & autre) const
{
	return true;
}

//------------------------------------------------------------------------------
string Point::toString() const
{
	stringstream sst;
	sst <<"(" << x_ << "," << y_ << ")";
	return sst.str();
}

//ACCESSEURS
//------------------------------------------------------------------------------
unsigned Point::getX() const
{
	return x_;
}

//------------------------------------------------------------------------------
unsigned Point::getY() const
{
	return y_;
}

//MUTATEURS
//------------------------------------------------------------------------------
void Point::setX(unsigned x)
{
	x_ = x;
}

//------------------------------------------------------------------------------
void Point::setY(unsigned y)
{
	y_ = y;
}