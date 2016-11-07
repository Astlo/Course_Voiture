/*

*/

#include "AIControllerType1.hpp"

#include <cmath>

#include "IController.hpp"
#include "../Data/Car.hpp"
#include "../Data/AICar.hpp"
#include "../State/GameStateManager.hpp"
#include "../Constants.hpp"

using namespace std;

const int AIControllerType1::VITESSE_MAXI = VITESSE_AVANT_MAXI - 1;

//------------------------------------------------------------------------------
AIControllerType1::AIControllerType1(IController *ptr_icontroller) : AIController(ptr_icontroller)
{
}



//------------------------------------------------------------------------------
void AIControllerType1::beforeUpdate(int player, GameStateManager *ptr_gameStateManager)
{
	AIController::beforeUpdate(player, ptr_gameStateManager);
	Car *ptr_car = (AICar*) ptr_gameStateManager->getGameData()->getOneCar(player);
	if (ptr_car->getVitesse() > VITESSE_MAXI) {
		ptr_car->setVitesse(VITESSE_MAXI);
	}
}