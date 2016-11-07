/* 

*/

#ifndef AICONTROLLERTYPE1_HPP
#define AICONTROLLERTYPE1_HPP
#pragma once

#include "AIController.hpp"

/**
 * Décorateur : implémentation décorée type 1
 */
class AIControllerType1 : public AIController
{
	public:
		/** L'IA 1 a une vitesse maxi constante mais légèrement inférieure aux joueurs. */
		static const int VITESSE_MAXI;
		
		AIControllerType1(IController *ptr_icontroller);
	protected:
		void beforeUpdate(int player, GameStateManager *ptr_gameStateManager);
}; // class AIController1
/**************************************************************************** */

#endif // AICONTROLLER1_HPP
