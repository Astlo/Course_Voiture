/*
	Fichier Trajectoire.cpp

	Définition des méthodes de Point
*/
#include "Trajectoire.hpp"
#include <cmath> // utile pour les fonctions mathématiques
using namespace std;

//------------------------------------------------------------------------------
//Constructeur
Trajectoire::Trajectoire(list<Point> trajet, Color couleur)
	: trajet_ (trajet),
	  couleur_ (couleur)
{}

//------------------------------------------------------------------------------
//Destructeur
Trajectoire::~Trajectoire()
{}

//------------------------------------------------------------------------------
Point Trajectoire::getDebut() const
{
	trajet_.front();
}

//------------------------------------------------------------------------------
Point Trajectoire::getFin() const{
	trajet_.back();
}

//------------------------------------------------------------------------------
list<Point> Trajectoire::getTrajet() const
{
	return trajet_;
}

//------------------------------------------------------------------------------
Point Trajectoire::getPointTrajet(int i) const
{

}
	
//------------------------------------------------------------------------------
Color Trajectoire::getCouleur() const
{
	return couleur_;
}

//------------------------------------------------------------------------------
void Trajectoire::setDebut(Point p)
{
	trajet_.pop_front();
	trajet_.push_front(p);
}

//------------------------------------------------------------------------------
void Trajectoire::setFin(Point p)
{
	trajet_.pop_back();
	trajet_.push_back(p);
}

//------------------------------------------------------------------------------
void Trajectoire::setTrajet(List<Point> trajet)
{
	trajet_ = trajet;
}

//------------------------------------------------------------------------------
void Trajectoire::setPointTrajet(Point p, int indice)
{

}

//------------------------------------------------------------------------------
void Trajectoire::setCouleur(Color couleur)
{
	couleur_ = couleur:
}

//------------------------------------------------------------------------------
void Trajectoire::ajouterPoint(Point p)
{

}

//------------------------------------------------------------------------------
void Trajectoire::supprimerPoint(Point p)
{

}

//------------------------------------------------------------------------------
unsigned Trajectoire::nbPoint()
{
	return trajet_.size();
}
