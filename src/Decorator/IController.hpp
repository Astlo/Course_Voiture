/* 

*/

#ifndef ICONTROLLER_HPP
#define ICRONTOLLER_HPP
#pragma once

//#include "../State/GameStateManager.hpp"

class GameStateManager;

class IController
{
	public:
		virtual void update(int player, GameStateManager *ptr_gameStateManager)=0;
}; // class IController
/**************************************************************************** */

#endif // ICRONTOLLER_HPP