/*

*/
#include "AIController.hpp"

#include <cmath>
#include <iostream>

#include "IController.hpp"
#include "../Point.hpp"
#include "../Data/GameData.hpp"
#include "../Data/AICar.hpp"
#include "../State/GameStateManager.hpp"
//#include "../Constants.hpp"

#define PI 3.14159265

using namespace std;

//------------------------------------------------------------------------------
AIController::AIController(IController *ptr_icontroller) : Decorator(ptr_icontroller)
{
}

//------------------------------------------------------------------------------
void AIController::update(int player, GameStateManager *ptr_gameStateManager)
{
	// Décoration avant.

	beforeUpdate(player, ptr_gameStateManager);
	ptr_icontroller->update(player, ptr_gameStateManager);
	// Décoration après.
	afterUpdate(player, ptr_gameStateManager);
}

//------------------------------------------------------------------------------
void AIController::beforeUpdate(int player, GameStateManager *ptr_gameStateManager)
{

	// Les voitures IA accélèrent toujours (la vitesse maxi est controlée dans phase après).
	AICar *ptr_aiCar = (AICar*) ptr_gameStateManager->getGameData()->getOneCar(player);
	ptr_aiCar->setAccelere(true);
}

//------------------------------------------------------------------------------
void AIController::afterUpdate(int player, GameStateManager *ptr_gameStateManager)
{
	AICar *ptr_aiCar = (AICar*) ptr_gameStateManager->getGameData()->getOneCar(player);

	// Combien de points parcourus en ligne droite  ?
	int n = (int) (abs(ptr_aiCar->getOldPoint().getX() - ptr_aiCar->getPoint().getX())*abs(ptr_aiCar->getOldPoint().getX() - ptr_aiCar->getPoint().getX())+abs(ptr_aiCar->getOldPoint().getY() - ptr_aiCar->getPoint().getY())*abs(ptr_aiCar->getOldPoint().getY() - ptr_aiCar->getPoint().getY()));

	// On suit la trajectoire pré-établie en ajustant le point suivant sur la trajectoire.
	ptr_aiCar->setPositionTrajectoire(ptr_aiCar->getPositionTrajectoire() + n);

	// Contrôle en bout de trajectoire.
	if (ptr_aiCar->getPositionTrajectoire() >= ptr_gameStateManager->getGameData()->getNbPointsTrajectoiresIA(player - GameData::VOITURE_JOUEUR_IA_0)) 
	{
		ptr_aiCar->setPositionTrajectoire(ptr_aiCar->getPositionTrajectoire() - ptr_gameStateManager->getGameData()->getNbPointsTrajectoiresIA(player - GameData::VOITURE_JOUEUR_IA_0));
	}

	// Re-positionner la voiture.
/*	Point *ptr_t[ptr_gameStateManager->getGameData()->getNbPointsTrajectoiresIA(player)];
	for(int i = 0; i < ptr_gameStateManager->getGameData()->getNbPointsTrajectoiresIA(player) ; ++i)
	{
		ptr_t[i] = ptr_gameStateManager->getGameData()->getUnPointTrajectoireIA(pos, i);
	}*/
	
	Point* ptr_t[MAX_TRAJECTOIRE];
	int pos = player - GameData::VOITURE_JOUEUR_IA_0;
	for(int j = 0; j<MAX_TRAJECTOIRE; ++j)
	{
		ptr_t[j] = ptr_gameStateManager->getGameData()->getUnPointTrajectoireIA(pos, j);
	}
	ptr_aiCar->setPoint(Point(ptr_t[ptr_aiCar->getPositionTrajectoire()]->getX(),ptr_t[ptr_aiCar->getPositionTrajectoire()]->getY()));

	// Ajuster l'angle si on a bougé.
	if (ptr_aiCar->getPoint().getX() != ptr_aiCar->getOldPoint().getX() || ptr_aiCar->getPoint().getY() != ptr_aiCar->getOldPoint().getY()) 
	{
		// Calcul de l'angle par rapport à la position précédente.
		double angle = (asin((ptr_aiCar->getPoint().getY() - ptr_aiCar->getOldPoint().getY()) / (abs(ptr_aiCar->getPoint().getX() - ptr_aiCar->getOldPoint().getX())*abs(ptr_aiCar->getPoint().getX() - ptr_aiCar->getOldPoint().getX())+abs(ptr_aiCar->getPoint().getY() - ptr_aiCar->getOldPoint().getY())*abs(ptr_aiCar->getPoint().getY() - ptr_aiCar->getOldPoint().getY()))))*180/PI;

		// Lissage sur la moyenne des 10 derniers angles pour éviter des effets de tremblement disgracieux.
		double a = 0;
		for (int i = 0; i < 9; i++) {
			ptr_aiCar->setOneOldAngle(ptr_aiCar->getOneOldAngle(i+1), i);
			a += ptr_aiCar->getOneOldAngle(i);
		}
		ptr_aiCar->setOneOldAngle(angle, 9);
		a += angle;
		angle = ((int)(a / 10)) % 360;

		// Ajustement du résultat sur 360° en fonction de la direction.
		if (ptr_aiCar->getPoint().getX() < ptr_aiCar->getOldPoint().getX()) {
			angle = 180 - angle;
		} else if (ptr_aiCar->getPoint().getY() < ptr_aiCar->getOldPoint().getY()) {
			angle = 360 + angle;
		}
		angle = ((int) angle) % 360;
		ptr_aiCar->setAngle(angle);
	}
}