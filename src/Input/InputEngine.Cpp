/**
 * @file InputEngine.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe InputEngine.
**/

#include "InputEngine.hpp"
#include <iostream>
#include <vector> //pour le type std::vector

using namespace std;

//CONSTANTES
//------------------------------------------------------------------------------
const int KeyEvent::KEY_PRESSE = 0;
const int InputEngine::KEY_UP1 = 19;
const int InputEngine::KEY_DOWN1 = 20;
const int InputEngine::KEY_LEFT1 = 21;
const int InputEngine::KEY_RIGHT1 = 22;

//------------------------------------------------------------------------------
const int InputEngine::KEY_UP2 = 54;
const int InputEngine::KEY_DOWN2 = 47;
const int InputEngine::KEY_LEFT2 = 45;
const int InputEngine::KEY_RIGHT2 = 32;

//------------------------------------------------------------------------------
const int InputEngine::KEY_ESCAPE = 131;

//------------------------------------------------------------------------------
const int InputEngine::MAX_KEYS = 4;

//CONSTRUCTEURS
//------------------------------------------------------------------------------
InputEngine::InputEngine() obs_=NULL;
{}

//DESTRUCTEUR
//------------------------------------------------------------------------------
InputEngine::~InputEngine()
{}

//AUTRES METHODES
//------------------------------------------------------------------------------
void InputEngine::addObs(KeyObserver * o)
{
	obs_.push_back(o);
}
 
//------------------------------------------------------------------------------
void InputEngine::removeObs(KeyObserver * o)
{
	int pos = positionObs(o);
	obs_.erase(obs_.begin()+pos);
}

//------------------------------------------------------------------------------
void InputEngine::notifyObs(KeyEvent * event)
{
	for (KeyObserver o : obs_) {
		o.keyEvent(&event);
	}
}
/*
//------------------------------------------------------------------------------
bool InputEngine::keyDown(int keycode)
{
	notifyObservers(new KeyEvent(KeyEvent.KEY_DOWN, keycode));
	return true;
}

//------------------------------------------------------------------------------
bool InputEngine::keyUp(int keycode)
{
	notifyObservers(new KeyEvent(KeyEvent.KEY_RELEASE, keycode));
	return true;
}


//------------------------------------------------------------------------------
bool equals(const IKeyObserver * o) const
{
	if (this == o)
	{
		return true;
	}
	else if (o(insteanceof)IKeyObserver)
}

//------------------------------------------------------------------------------
int positionObs(IKeyObserver * o)
{
	int i = 0;
	int pos = NULL;
	IKeyObserver iko;
	while (i < obs_.size() ) // tant que i inférieur à al taille de obs_
	{
		iko = obs_.at(i);//obtenir le ième élément de la liste
		if (iko.equals(&o)) //méthode égalité ou surcharge de l'opérateur égale
		{
			pos = i;
			i = obs_.size();
		}
		else
		{
			++i;
		}
	}
	return pos;
}
*/