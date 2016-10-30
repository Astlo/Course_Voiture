/* 
	Fichier GameEngine.hpp
	
	   
*/


#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP
#pragma once

/**************************************************************************** */
class GameEngine
{
	public:
		GameEngine();
		~GameEngine();

		void execute();

	private:
		GraphicsEngine* graphicsEngine_;
		GameStateManager* gameStateManager_;

}; // class GameEngine
/**************************************************************************** */

#endif // GAMEENGINE_HPP
