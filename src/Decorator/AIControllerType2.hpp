/* 

*/

#ifndef AICONTROLLERTYPE2_HPP
#define AICONTROLLERTYPE2_HPP
#pragma once


#include "AIController.hpp"

/**
 * Décorateur : implémentation décorée type 2
 */
class AIControllerType2 : public AIController
{
	public:
		/** L'IA 2 a une vitesse maxi variable. */		
		static const int VITESSE_MAXI_INFERIEURE;	
		static const int VITESSE_MAXI_SUPERIEURE;
		
		AIControllerType2(IController *ptr_icontroller);
	protected:
		void beforeUpdate(int player, GameStateManager *ptr_gameStateManager);
}; // class AIController2
/**************************************************************************** */

#endif // AICONTROLLER2_HPP
