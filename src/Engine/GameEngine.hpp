/* 
	Fichier GameEngine.hpp
	
	   
*/


#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP
#pragma once

/*
#include "../Graphics/GraphicsEngine.hpp"
#include "../State/GameStateManager.hpp"
#include "../Data/GameData.hpp" 
#include "../Input/InputEngine.hpp"*/

class GraphicsEngine;
class GameStateManager;
class GameData;
class InputEngine;

/**************************************************************************** */
class GameEngine
{
	public:
		GameEngine();
		~GameEngine();

		void create();
		void execute();
		void render();

	private:
		/** Gestionnaire d'état du jeu. */
		GraphicsEngine *ptr_graphicsEngine_;
		GameStateManager *ptr_gameStateManager_;
		GameData *ptr_gameData_;
		InputEngine *ptr_inputEngine_;
}; // class GameEngine
/**************************************************************************** */

#endif // GAMEENGINE_HPP
