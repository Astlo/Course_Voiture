/* 
	Fichier GameEngine.hpp
	
	   
*/


#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP
#pragma once


#include "../Graphics/GraphicsEngine.hpp"
#include "../State/GameStateManager.hpp"
#include "../Input/InputEngine.hpp"
#include "../Data/GameData.hpp" 

/**************************************************************************** */
class GameEngine
{
	public:
		GameEngine();
		~GameEngine();

		void execute();
		void create();
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
