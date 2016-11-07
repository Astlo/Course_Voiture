/**
 * @file GameState.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe MenuState.
 * @b (pattern State)
**/

#include "MenuState.hpp"
 
#include <sstream> //pour les conversions en chaine

#include "GameStateManager.hpp"
#include "GameState.hpp"
#include "../Input/KeyboardEvent.hpp"
#include "../Constants.hpp"

using namespace std;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
MenuState::MenuState(GameStateManager *ptr_gameStateManager) : GameState(ptr_gameStateManager), p_(0)
{
	init();
}

//DESTRUCTEUR
//------------------------------------------------------------------------------
MenuState::~MenuState()
{}

//METHODES
//------------------------------------------------------------------------------
void MenuState::init()
{
	p_ = -MAX_VOITURES * (VOITURE_LARGEUR + 10);
}

void MenuState::draw()
{
	sf::Sprite *ptr_spriteMenu = new sf::Sprite();
	getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getTextureMenu(), ptr_spriteMenu, 0, 0, 1, 1, 0);

	for (int i=0; i < MAX_VOITURES; ++i)
	{
		getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(i), getGameStateManager()->getGraphicsEngine()->getOneSpriteCar(i), p_ + i * (VOITURE_LARGEUR + 10), 130, 1.0, 1.0, 0.0);
	}
}

//------------------------------------------------------------------------------
void MenuState::update(double deltaTime)
{
		p_ += deltaTime * 200;
		// Si on déborde on reset pour recommencer à gauche.
		if (p_ >= ECRAN_LARGEUR)
		{
			init();
		}
}

//------------------------------------------------------------------------------
void MenuState::keyEvent(KeyboardEvent *ptr_event)
{
	// Appui sur une touche autre que escape qui sert à abandonner le jeu.
	if (ptr_event->getEvent().type == KeyboardEvent::KEY_RELEASE && ptr_event->getKeyCode() != KEY_ESCAPE)
	{
		getGameStateManager()->setStartRaceState();
	}
}