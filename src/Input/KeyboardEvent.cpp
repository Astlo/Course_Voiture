/**
 * @file KeyBoardEvent.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe KeyboardEvent.
**/


#include "KeyboardEvent.hpp"

#include <sstream> //pour les conversions en chaine

#include <SFML/Window.hpp>

using namespace std;

//CONSTANTES
//------------------------------------------------------------------------------
const sf::Event::EventType KeyboardEvent::KEY_PRESSE = sf::Event::KeyPressed;

//------------------------------------------------------------------------------
const sf::Event::EventType KeyboardEvent::KEY_RELEASE = sf::Event::KeyReleased;

//CONSTRUCTEURS
//------------------------------------------------------------------------------
KeyboardEvent::KeyboardEvent(sf::Event event, sf::Keyboard::Key keyCode) : event_ (event), keyCode_ (keyCode)
{}

//DESTRUCTEUR
//------------------------------------------------------------------------------
KeyboardEvent::~KeyboardEvent()
{}
/*
//METHODES
//------------------------------------------------------------------------------
string KeyboardEvent::toString() const
{
	stringstream sst;
	sst <<"KeyboardEvent [event=" << event_ << ", keyCode=" << keyCode_ << "]";
	return sst.str();
}*/

//ACCESSEURS
//------------------------------------------------------------------------------
sf::Event KeyboardEvent::getEvent() const
{
	return event_;
}

//------------------------------------------------------------------------------
sf::Keyboard::Key KeyboardEvent::getKeyCode() const
{
	return keyCode_;
}

//MUTATEURS
//------------------------------------------------------------------------------
void KeyboardEvent::setEvent(sf::Event event)
{
	event_ = event;
}

//------------------------------------------------------------------------------
void KeyboardEvent::setKeyCode(sf::Keyboard::Key keyCode)
{
	keyCode_ = keyCode;
}