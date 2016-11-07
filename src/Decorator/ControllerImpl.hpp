/* 

*/

#ifndef CONTROLLERIMPL_HPP
#define CRONTOLLERIMPL_HPP
#pragma once

#include "../State/GameStateManager.hpp"
#include "IController.hpp"

//class IController;

class ControllerImpl : public IController
{
	public:
		virtual void update(int player, GameStateManager *ptr_gameStateManager);
}; // class ControllerImpl
/**************************************************************************** */

#endif // CRONTOLLERIMPL_HPP