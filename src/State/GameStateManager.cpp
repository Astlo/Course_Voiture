/**
 * @file KeyEvent.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe KeyEvent.
**/

#include "GameStateManager.hpp"

#include <sstream> //pour les conversions en chaine

#include "../Input/KeyboardEvent.hpp"
#include "MenuState.hpp"
#include "RaceState.hpp"
#include "StartRaceState.hpp"
#include "EndRaceState.hpp"
 
using namespace std;

GameStateManager::GameStateManager(GraphicsEngine *ptr_graphicsEngine, GameData *ptr_gameData, /*GameState *ptr_menuState,*/ IKeySubject *ptr_subject) : ptr_graphicsEngine_(ptr_graphicsEngine), ptr_gameData_(ptr_gameData), ptr_subject_(ptr_subject)
{
ptr_startRaceState_ = new StartRaceState(this);
ptr_raceState_ = new RaceState(this);
ptr_endRaceState_ = new EndRaceState(this);
ptr_menuState_ = new MenuState(this);
ptr_gameState_ = ptr_menuState_;
}

GameStateManager::~GameStateManager()
{
	/*delete ptr_startRaceState_;
	delete ptr_raceState_;
	delete ptr_endRaceState_;
	delete ptr_menuState_;*/
}

//ACCESSEURS
GameState* GameStateManager::getGameState()
{
		return ptr_gameState_;
}

GameData* GameStateManager::getGameData()
{
		return ptr_gameData_;
}

GraphicsEngine* GameStateManager::getGraphicsEngine()
{
		return ptr_graphicsEngine_;
}

//MUTATEURS

void GameStateManager::setMenuState()
{
	ptr_gameState_ = ptr_menuState_;
}
		
void GameStateManager::setRaceState()
{
	ptr_gameState_ = ptr_raceState_;
}
		
void GameStateManager::setStartRaceState()
{
	ptr_gameState_ = ptr_startRaceState_;
}
		
void GameStateManager::setEndRaceState()
{
	ptr_gameState_ = ptr_endRaceState_;
}





	/**
	 * Nouvel état.
	 * @param state Indice du nouvel état.
	 */
/*	void setState(int state) {
		if (gameState != null) {
			gameState.dispose();
		}

		switch (state) {
		case STATE_MENU:
			gameState = new MenuState(this);
			break;

		case STATE_START_RACE:
			gameState = new StartRaceState(this);
			break;

		case STATE_RACE:
			gameState = new RaceState(this);
			break;

		case STATE_END_RACE:
			gameState = new EndRaceState(this);
			break;

		default:
			break;
		}
	}
*/
void GameStateManager::update(double deltaTime)
{
	if (ptr_gameState_ != NULL)
	{
		ptr_gameState_->update(deltaTime);
	}
}

void GameStateManager::draw()
{
	if (ptr_gameState_ != NULL)
	{
		ptr_gameState_->draw();
	}
}

void GameStateManager::keyEvent(KeyboardEvent *ptr_event)
{
	if (ptr_gameState_ != NULL)
	{
		ptr_gameState_->keyboardEvent(ptr_event);
	}
}