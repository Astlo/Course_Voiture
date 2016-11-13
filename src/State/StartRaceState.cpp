/**
 * @file StartRaceState.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe StartRaceState.
 * @b (pattern State)
**/

#include "StartRaceState.hpp"
#include <sstream> //pour les conversions en chaine
#include <cmath>
#include <iostream>

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
#include "../Graphics/GraphicsEngine.hpp"

using namespace std;

StartRaceState::StartRaceState(GameStateManager *ptr_gameStateManager) : RaceState(ptr_gameStateManager)
{
	init();
}

StartRaceState::~StartRaceState()
{}

void StartRaceState::init()
{
	decompte = 240;
	getGameStateManager()->getGameData()->reset();
	// Placer les voitures sur la ligne de départ.
	for (int i = 0; i < MAX_VOITURES; ++i)
	{
		Car *ptr_car = getGameStateManager()->getGameData()->getOneCar(i);
		if (i < GameData::VOITURE_JOUEUR_IA_0)
		{
			ptr_car->setPoint(Point(X_BASE_TRAJECTOIRE - GraphicsEngine::VOITURE_LARGEUR*2,Y_BASE_TRAJECTOIRE + (i % 2) * GraphicsEngine::VOITURE_HAUTEUR*2));
		}
		else
		{
			ptr_car->setPoint(Point(X_BASE_TRAJECTOIRE, Y_BASE_TRAJECTOIRE + (i % 2) * 53));
		}
	}
}

void StartRaceState::draw()
{
		RaceState::draw();
		// Afficher le décompte.

		//getGameStateManager()->getGraphicsEngine()->getFont()->draw(spriteBatch, String.valueOf((int)decompte), ECRAN_LARGEUR / 2 - 100, ECRAN_HAUTEUR / 2 + 100);
			stringstream ss;
			ss << (int)(decompte / 60);
			string str = ss.str();
			sf::Text text(str, getGameStateManager()->getGraphicsEngine()->getFont());
			text.setCharacterSize(200);
			text.setFillColor(sf::Color::Red);
			text.setPosition(500,500);
			getGameStateManager()->getGraphicsEngine()->getRenderWindow()->draw(text);


}

void StartRaceState::update(int deltaTime)
{
		// Décompter (deltaTime est une fraction de seconde) puis démarrer la course en changeant l'état.
		decompte -= deltaTime;
		if (decompte <= 0)
		{
			getGameStateManager()->setRaceState();
		}
}