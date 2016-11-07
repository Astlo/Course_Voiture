/**
 * @file InputEngine.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe InputEngine.
**/

#include "InputEngine.hpp"
#include <iostream>
#include <vector> //pour le type std::vector
 
#include "IKeySubject.hpp"
#include "IKeyObserver.hpp"
#include "KeyboardEvent.hpp"

using namespace std;

//CONSTRUCTEURS
//------------------------------------------------------------------------------
 InputEngine::InputEngine()
{}

//DESTRUCTEUR
//------------------------------------------------------------------------------
InputEngine::~InputEngine()
{}

//METHODES
//------------------------------------------------------------------------------
void InputEngine::addObs(IKeyObserver *ptr_obs)
{
	obs_.push_back(*ptr_obs);
}

//------------------------------------------------------------------------------
void InputEngine::removeObs(IKeyObserver *ptr_obs)
{
	/*int pos = positionObs(*ptr_obs);
	obs_.erase(obs_.begin()+pos);*/
}

//------------------------------------------------------------------------------
void InputEngine::notifyObs(KeyboardEvent *ptr_event)
{
	for (IKeyObserver o : obs_) {
		o.keyEvent(*ptr_event);
	}
}

//------------------------------------------------------------------------------
bool InputEngine::keyDown(Keyboard::Key keycode)
{
	notifyObs(new KeyboardEvent(KeyboardEvent::KEY_PRESSE, keycode));
	return true;
}

//------------------------------------------------------------------------------
bool InputEngine::keyUp(Keyboard::Key keycode)
{
	notifyObs(new KeyboardEvent(KeyboardEvent::KEY_RELEASE, keycode));
	return true;
}
/*
//------------------------------------------------------------------------------
int InputEngine::positionObs(IKeyObserver *ptr_obs)
{
	int i = 0;
	int pos = NULL;
	IKeyObserver * ptr_iko;
	while (i < obs_.size() ) // tant que i inférieur à al taille de obs_
	{
		ptr_iko = obs_.at(i);//obtenir le ième élément de la liste
		if (ptr_iko==ptr_o) //méthode égalité ou surcharge de l'opérateur égale
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
}*/