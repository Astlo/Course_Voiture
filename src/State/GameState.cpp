/**
 * @file GameState.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe GameState.
 * @b (pattern State)
 * @b (pattern Observer)
**/

#include "GameState.hpp"

#include <sstream> //pour les conversions en chaine

#include "GameStateManager.hpp"

using namespace std;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
GameState::GameState(GameStateManager *ptr_gameStateManager) : ptr_gameStateManager_(ptr_gameStateManager)
{}

//DESTRUCTEUR
//------------------------------------------------------------------------------
GameState::~GameState()
{}

//ACCESSEUR
//------------------------------------------------------------------------------
GameStateManager* GameState::getGameStateManager()
{
	return ptr_gameStateManager_;
}

void GameState::keyboardEvent(KeyboardEvent *ptr_event)
{
	ptr_gameStateManager_->keyboardEvent(ptr_event);
}