/*

*/

#include "ControllerImpl.hpp"

#include <cmath>

#include "../Data/Car.hpp"
#include "../State/GameStateManager.hpp"
#include "../Constants.hpp"
#include "../Graphics/GraphicsEngine.hpp"
#include "../Data/GameData.hpp"

#define PI 3.14159265

using namespace std;

//------------------------------------------------------------------------------
//virtual void ControllerImpl::update(int player, GameStateManager *ptr_gameStateManager)
void ControllerImpl::update(int player, GameStateManager *ptr_gameStateManager)
{
	//Voiture voiture = gameStateManager->getGameModel()->getVoitures()[player];
	Car *ptr_car = ptr_gameStateManager->getGameData()->getOneCar(player);
	ptr_car->getOldPoint().setX((int) ptr_car->getPoint().getX());
	ptr_car->getOldPoint().setY((int) ptr_car->getPoint().getY());

	bool enObstacle = ptr_car->getEtatGlissade() != 0 || ptr_car->getEtatSaut() != 0;

	// Si on a appuyé sur flêche haut et que la vitesse n'est pas au maximum et qu'on est ni en glissade, ni en saut, alors on accélère.
	if (ptr_car->isAccelere() && !enObstacle && ptr_car->getVitesse() < (ptr_car->getSecteur() == 0 ? VITESSE_HORS_PISTE : VITESSE_AVANT_MAXI)) 
	{
		ptr_car->setVitesse(ptr_car->getVitesse() + DELTA_VITESSE);
	}

	// Si on a relâché la flêche haut et que la vitesse n'est pas nulle et qu'on est ni en glissade ni en saut, alors on décélère.
	if (!ptr_car->isAccelere() && !enObstacle && ptr_car->getVitesse() > 0) 
	{
		ptr_car->setVitesse(ptr_car->getVitesse() - DELTA_VITESSE);
	}

	// Si on a appuyé sur flêche bas et que la vitesse n'est pas au maximum de la vitesse arrière, alors on accélère en arrière.
	if (ptr_car->isFreine() && !enObstacle && ptr_car->getVitesse() > (ptr_car->getSecteur() == 0 ? -VITESSE_HORS_PISTE : -VITESSE_ARRIERE_MAXI)) 
	{
		ptr_car->setVitesse(ptr_car->getVitesse() - DELTA_VITESSE);
	}

	// Si on a relâché la flêche bas et que l'on reculait, alors on stoppe immédiatement.
	if (!ptr_car->isFreine() && !enObstacle && ptr_car->getVitesse() < 0) 
	{
		ptr_car->setVitesse(0);
	}

	// Calculer l'angle de rotation : on veut une rotation maxi quand la vitesse est mini et vice versa.
	double absv = abs(ptr_car->getVitesse());
	double c = DELTA_ANGLE_VITESSE_MINI - (absv * DELTA_COEF);

	// Si on a appuyé sur gauche et que la vitesse n'est pas nulle, alors on tourne à gauche (augmentation de l'angle)
	if (ptr_car->isLeft() && !enObstacle && ptr_car->getVitesse() != 0) {
		ptr_car->setAngle((int)(ptr_car->getAngle() + c) % 360);
	}
	// Si on a appuyé sur droite et que la vitesse n'est pas nulle, alors on tourne à droite (diminution de l'angle)
	if (ptr_car->isRight() && !enObstacle && ptr_car->getVitesse() != 0) {
		ptr_car->setAngle((int)(ptr_car->getAngle() - c) % 360);
	}

	// Calculer le nouveau point d'arrivée en fonction du vecteur donné par l'angle et la vitesse.
	double x = ptr_car->getPoint().getX();
	double y = ptr_car->getPoint().getY();
	double angleRadian = (ptr_car->getAngle()*PI)/180;
	ptr_car->setPoint(Point(x + (ptr_car->getVitesse() * cos(angleRadian)),y + (ptr_car->getVitesse() * sin(angleRadian))));
	// Si on sort des limites du jeu, on revient à la position précédente.
	if ((ptr_car->getPoint().getX() < GraphicsEngine::VOITURE_LARGEUR / 2)
			|| (ptr_car->getPoint().getX() > GraphicsEngine::ECRAN_LARGEUR - (GraphicsEngine::VOITURE_LARGEUR / 2))
			|| (ptr_car->getPoint().getY() < GraphicsEngine::VOITURE_HAUTEUR / 2)
			|| (ptr_car->getPoint().getY() > GraphicsEngine::ECRAN_HAUTEUR - (GraphicsEngine::VOITURE_HAUTEUR / 2))) {
		ptr_car->setPoint(Point(x,y));
	}

	// Calculer sur quel secteur on est.
	sf::Color color = ptr_gameStateManager->getGraphicsEngine()->getPixelColorFromTexture(ptr_gameStateManager->getGraphicsEngine()->getTextureCircuit(), (int) ptr_car->getPoint().getX(), (int) ptr_car->getPoint().getY());
	int secteur = ptr_gameStateManager->getGameData()->getSecteurFromColor(color);

	// On mémorise l'ancien secteur.
	if (ptr_car->getSecteur() != 0) {
		ptr_car->setOldSecteur(ptr_car->getSecteur());
	}

	// Est-on hors piste ?
	if (secteur == 0) {
		ptr_car->setSecteur(0);
			// On ralentit.
		if (ptr_car->getVitesse() > VITESSE_HORS_PISTE) {
			ptr_car->setVitesse(fmax(0, ptr_car->getVitesse() - DELTA_VITESSE * 2));
		}
	} else if (ptr_car->getSecteur() == 0) {
		// On était hors piste et on revient sur la piste. Rentre-t-on par le bon secteur ?
		if (secteur < ptr_car->getOldSecteur() || (secteur - ptr_car->getOldSecteur() < 2) || (secteur == 1 && ptr_car->getOldSecteur() == NOMBRE_SECTEURS)) {
			ptr_car->setSecteur(secteur);
		} else {
			// Non : on bloque.
			ptr_car->getPoint().setX(x);
			ptr_car->getPoint().setY(y);
		}
	} else {
		ptr_car->setSecteur(secteur);
	}

	// Ajuster le secteur atteint par la voiture dans le tour.
	if (ptr_car->getSecteur() == ptr_car->getSecteurAtteint() + 1 || (ptr_car->getSecteur() == 1 && ptr_car->getSecteurAtteint() == NOMBRE_SECTEURS)) {
		// La voiture a atteint un nouveau secteur.
		ptr_car->setSecteurAtteint(ptr_car->getSecteur());
		// Si dernier secteur, alors incrémenter le tour.
		if (ptr_car->getSecteurAtteint() == 1) {
			ptr_car->setTour(ptr_car->getTour() + 1);
		}
	}
}