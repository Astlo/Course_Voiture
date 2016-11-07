/* 

*/

#ifndef AICONTROLLER_HPP
#define AICONTROLLER_HPP
#pragma once

#include "Decorator.hpp"

class GameStateManager;

class AIController : public Decorator
{
	public:
		AIController(IController *ptr_icontroller);
		void update(int player, GameStateManager *ptr_gameStateManager);

	protected:
		/**
		 * Avant mise à jour.
		 */
		void beforeUpdate(int player, GameStateManager *ptr_gameStateManager);
		void afterUpdate(int player, GameStateManager *ptr_gameStateManager);
	private:
}; // class AIController
/**************************************************************************** */

#endif // AICONTROLLER_HPP