/**
 * @file EndRaceState.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe EndRaceState.
 * @b (pattern State)
**/

#include "EndRaceState.hpp"
 
#include <sstream> //pour les conversions en chaine
#include <cmath>

#include "GameStateManager.hpp"
#include "RaceState.hpp"
#include "GameState.hpp"
#include "../Constants.hpp"
#include "../Decorator/IController.hpp"
#include "../Decorator/ControllerImpl.hpp"
#include "../Decorator/AIControllerType1.hpp"
#include "../Decorator/AIControllerType2.hpp"
#include "../Input/InputEngine.hpp"
#include "../Input/KeyboardEvent.hpp"
#include "../Data/GameData.hpp"
#include "../Data/Car.hpp"

using namespace std;

EndRaceState::EndRaceState(GameStateManager *ptr_gameStateManager) : RaceState(ptr_gameStateManager)
{
	init();
}
EndRaceState::~EndRaceState()
{}

void init()
{}

void EndRaceState::draw()
{
	RaceState::draw();
	// Affichage du vainqueur.
	if (getGameStateManager()->getGameData()->getVainqueur() != -1) {
		sf::Text winner("WINNER", getGameStateManager()->getGraphicsEngine()->getFont());
		winner.setCharacterSize(200);
		winner.setFillColor(sf::Color::Red);
		winner.setPosition(ECRAN_LARGEUR / 2 - 300,ECRAN_HAUTEUR / 2 - 200);


		sf::Sprite *ptr_sprite = getGameStateManager()->getGraphicsEngine()->getOneSpriteCar(getGameStateManager()->getGameData()->getVainqueur());
		getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(getGameStateManager()->getGameData()->getVainqueur()), ptr_sprite, ECRAN_LARGEUR / 2 - 30, ECRAN_HAUTEUR / 2 - 50, 3.0, 3.0, 0.0);
	}
	sf::Text text("hit spacebar", getGameStateManager()->getGraphicsEngine()->getFont());
	text.setCharacterSize(200);
	text.setFillColor(sf::Color::Red);
	text.setPosition(ECRAN_LARGEUR / 2 - 70,ECRAN_HAUTEUR / 2 - 100);
}

void EndRaceState::update(double deltaTime)
{}

void EndRaceState::keyboardEvent(KeyboardEvent *ptr_event)
{
	if (ptr_event->getEvent().type == KeyboardEvent::KEY_RELEASE && ptr_event->getKeyCode() == sf::Keyboard::Space)
	{
		getGameStateManager()->setMenuState();
	}
}