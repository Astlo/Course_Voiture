/*

*/

#include "AIControllerType2.hpp"

#include <cmath>

#include "IController.hpp"
#include "../Data/Car.hpp"
#include "../Data/AICar.hpp"
#include "../Data/GameData.hpp"
#include "../State/GameStateManager.hpp"
#include "../Constants.hpp"

using namespace std;

const int AIControllerType2::VITESSE_MAXI_INFERIEURE = 2;
const int AIControllerType2::VITESSE_MAXI_SUPERIEURE = 6;

//------------------------------------------------------------------------------
AIControllerType2::AIControllerType2(IController *ptr_icontroller) : AIController(ptr_icontroller)
{
}



//------------------------------------------------------------------------------
void AIControllerType2::beforeUpdate(int player, GameStateManager *ptr_gameStateManager)
{
	AIController::beforeUpdate(player, ptr_gameStateManager);
	AICar *ptr_aiCar = (AICar*) ptr_gameStateManager->getGameData()->getOneCar(player);

	// Ajuster la vitesse maxi.
	ptr_aiCar->setVitesseMaxi(ptr_aiCar->getVitesseMaxi() + ptr_aiCar->getVariationVitesseMaxi());
	if (ptr_aiCar->getVitesseMaxi() > VITESSE_MAXI_SUPERIEURE) {
		ptr_aiCar->setVitesseMaxi(VITESSE_MAXI_SUPERIEURE);
		ptr_aiCar->setVariationVitesseMaxi(-ptr_aiCar->getVariationVitesseMaxi());
	} else if (ptr_aiCar->getVitesseMaxi() < VITESSE_MAXI_INFERIEURE) {
		ptr_aiCar->setVitesseMaxi(VITESSE_MAXI_INFERIEURE);
		ptr_aiCar->setVariationVitesseMaxi(-ptr_aiCar->getVariationVitesseMaxi());
	}

	// Ajuster la vitesse.
	if (ptr_aiCar->getVitesse() > ptr_aiCar->getVitesseMaxi()) {
		ptr_aiCar->setVitesse(ptr_aiCar->getVitesseMaxi());
	}
}