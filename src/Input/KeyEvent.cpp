/**
 * @file KeyEvent.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe KeyEvent.
**/


#include "KeyEvent.hpp"
#include <sstream> //pour les conversions en chaine

using namespace std;

//CONSTANTES
//------------------------------------------------------------------------------
const int KeyEvent::KEY_PRESSE = 0;

//------------------------------------------------------------------------------
const int KeyEvent::KEY_RELEASE = 1;

//CONSTRUCTEURS
//------------------------------------------------------------------------------
KeyEvent::KeyEvent(int event, int keyCode) : event_ (event), keyCode_ (keyCode)
{}

//DESTRUCTEUR
//------------------------------------------------------------------------------
KeyEvent::~KeyEvent()
{}

//ACCESSEURS
//------------------------------------------------------------------------------
int KeyEvent::getEvent() const
{
	return event_;
}

//------------------------------------------------------------------------------
int KeyEvent::getKeyCode() const
{
	return keyCode_;
}

//MUTATEURS
//------------------------------------------------------------------------------
void KeyEvent::setEvent(int event)
{
	event_ = event;
}

//------------------------------------------------------------------------------
void KeyEvent::setKeyCode(int keyCode)
{
	keyCode_ = keyCode;
}

//AUTRES METHODES
//------------------------------------------------------------------------------
string KeyEvent::toString() const
{
	stringstream sst;
	sst <<"KeyEvent [event=" << event_ << ", keyCode=" << keyCode_ << "]";
	return sst.str();
}
