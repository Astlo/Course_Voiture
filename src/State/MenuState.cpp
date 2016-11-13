/**
 * @file GameState.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe MenuState.
 * @b (pattern State)
**/

#include "MenuState.hpp"
 
#include <sstream> //pour les conversions en chaine
#include <iostream>

#include <SFML/Window.hpp>

#include "GameStateManager.hpp"
#include "GameState.hpp"
#include "../Input/KeyboardEvent.hpp"
#include "../Graphics/GraphicsEngine.hpp"
//#include "../Constants.hpp"

using namespace std;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
MenuState::MenuState(GameStateManager *ptr_gameStateManager) : GameState(ptr_gameStateManager), p_(1)
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
	p_ = -(MAX_VOITURES * (GraphicsEngine::VOITURE_LARGEUR + 10));
}

void MenuState::draw()
{
	sf::Sprite *ptr_spriteMenu = new sf::Sprite();
	sf::Texture *ptr_textureMenu = getGameStateManager()->getGraphicsEngine()->getTextureMenu();
	getGameStateManager()->getGraphicsEngine()->drawSprite(ptr_textureMenu, ptr_spriteMenu, GraphicsEngine::ECRAN_LARGEUR/2, GraphicsEngine::ECRAN_HAUTEUR/2, GraphicsEngine::ECRAN_LARGEUR/(double)ptr_textureMenu->getSize().x, GraphicsEngine::ECRAN_HAUTEUR/(double)ptr_textureMenu->getSize().y, 0);

	for (int i=0; i < MAX_VOITURES; ++i)
	{
		getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(i), getGameStateManager()->getGraphicsEngine()->getOneSpriteCar(i), (double)(p_ + i * (GraphicsEngine::VOITURE_LARGEUR*2)), GraphicsEngine::ECRAN_HAUTEUR*0.81, 1.0, 1.0, 0.0);
	}
	delete ptr_spriteMenu;
}

//------------------------------------------------------------------------------
void MenuState::update(int deltaTime)
{
		p_ = p_ + (deltaTime *6);
		// Si on déborde on reset pour recommencer à gauche.
		if (p_ >= GraphicsEngine::ECRAN_LARGEUR)
		{
			init();
		}
}

//------------------------------------------------------------------------------
void MenuState::keyboardEvent(KeyboardEvent *ptr_event)
{
	// Appui sur une touche autre que escape qui sert à abandonner le jeu.
	if (ptr_event->getEvent() == KeyboardEvent::KEY_RELEASE && ptr_event->getKeyCode() != KEY_ESCAPE)
	{
		getGameStateManager()->setStartRaceState();
	}
	/*else if(sf::Keyboard::isKeyPressed(KEY_ESCAPE))
	{
		getGameStateManager()->getGraphicsEngine()->getRenderWindow()->close();
	}*/
}