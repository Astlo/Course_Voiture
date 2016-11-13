/**
 * @file RaceState.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe RaceState.
 * @b (pattern State)
**/

#include "RaceState.hpp"
 
#include <sstream> //pour les conversions en chaine
#include <cmath>
 #include <iostream>
 
#include "../Constants.hpp"
#include "GameStateManager.hpp"
#include "../Decorator/IController.hpp"
#include "../Decorator/ControllerImpl.hpp"
#include "../Decorator/AIControllerType1.hpp"
#include "../Decorator/AIControllerType2.hpp"
#include "../Input/InputEngine.hpp"
#include "../Input/KeyboardEvent.hpp"
#include "../Data/GameData.hpp"
#include "../Data/Car.hpp"
#include "../Graphics/GraphicsEngine.hpp"

using namespace std;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
RaceState::RaceState(GameStateManager *ptr_gameStateManager) : GameState(ptr_gameStateManager)
{
	ptr_controller_ = new ControllerImpl();
	ptr_iaController1_ = new AIControllerType1(ptr_controller_);
	ptr_iaController2_ = new AIControllerType2(ptr_controller_);
	init();
}

//DESTRUCTEUR
//------------------------------------------------------------------------------
RaceState::~RaceState()
{
	/*delete ptr_controller_;
	delete ptr_iaController1_;
	delete ptr_iaController2_;*/
}

//METHODES
//------------------------------------------------------------------------------
void RaceState::init()
{}

//------------------------------------------------------------------------------
void RaceState::draw()
{
	sf::Sprite *ptr_spriteCircuit = new sf::Sprite();
	sf::Sprite *ptr_spriteObstacles = new sf::Sprite();
	sf::Sprite *ptr_spriteTrajectoire = new sf::Sprite();
	//sf::Sprite *ptr_sprite;
	Car *ptr_car;
	GraphicsEngine *ptr_graphicsEngine = getGameStateManager()->getGraphicsEngine();
	//ptr_graphicsEngine->drawSprite(ptr_graphicsEngine->getTextureObstacles(), ptr_spriteObstacles, GraphicsEngine::ECRAN_LARGEUR/2, GraphicsEngine::ECRAN_HAUTEUR/2, GraphicsEngine::ECRAN_LARGEUR/(double)ptr_graphicsEngine->getTextureObstacles()->getSize().x, GraphicsEngine::ECRAN_HAUTEUR/(double)ptr_graphicsEngine->getTextureObstacles()->getSize().y, 0);
	ptr_graphicsEngine->drawSprite(ptr_graphicsEngine->getTextureTrajectoireIA(), ptr_spriteTrajectoire, GraphicsEngine::ECRAN_LARGEUR/2, GraphicsEngine::ECRAN_HAUTEUR/2, GraphicsEngine::ECRAN_LARGEUR/(double)ptr_graphicsEngine->getTextureTrajectoireIA()->getSize().x, GraphicsEngine::ECRAN_HAUTEUR/(double)ptr_graphicsEngine->getTextureTrajectoireIA()->getSize().y, 0);
	

	//ptr_graphicsEngine->drawSprite(ptr_graphicsEngine->getTextureCircuit(), ptr_spriteCircuit, GraphicsEngine::ECRAN_LARGEUR/2.0, GraphicsEngine::ECRAN_HAUTEUR/2.0, (double)GraphicsEngine::ECRAN_LARGEUR/(double)ptr_graphicsEngine->getTextureCircuit()->getSize().x, (double)GraphicsEngine::ECRAN_HAUTEUR/(double)ptr_graphicsEngine->getTextureCircuit()->getSize().y, 0);


	//cout << ptr_graphicsEngine->getTextureCircuit()->getSize().x << " " << ptr_graphicsEngine->getTextureCircuit()->getSize().y << endl;
	//cout << GraphicsEngine::ECRAN_LARGEUR/(double)ptr_graphicsEngine->getTextureCircuit()->getSize().x << " " << GraphicsEngine::ECRAN_HAUTEUR/(double)ptr_graphicsEngine->getTextureCircuit()->getSize().y << endl;
	//cout << ptr_graphicsEngine->getTextureCircuit()->getSize().x*GraphicsEngine::ECRAN_LARGEUR/(double)ptr_graphicsEngine->getTextureCircuit()->getSize().x << " " << ptr_graphicsEngine->getTextureCircuit()->getSize().y*GraphicsEngine::ECRAN_HAUTEUR/(double)ptr_graphicsEngine->getTextureCircuit()->getSize().y << endl;
	//cout << GraphicsEngine::ECRAN_LARGEUR/2 << " " << GraphicsEngine::ECRAN_HAUTEUR/2 << endl;

	// Tableau de bord.
	/*for (int i = 0; i < MAX_VOITURES; ++i)
	{
		ptr_car = getGameStateManager()->getGameData()->getOneCar(i);
		ptr_sprite = getGameStateManager()->getGraphicsEngine()->getOneSpriteCar(i);

		getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(i), ptr_sprite, i * 250 + 10, 700, 1.0, 1.0, 0.0);
	}*/

	// En premier afficher les voitures ne sautant pas pour qu'elles apparaissent au dessous des autres.
	for (int i = 0; i < MAX_VOITURES; ++i) 
	{
		ptr_car = getGameStateManager()->getGameData()->getOneCar(i);
		if (ptr_car->getEtatSaut() == 0) 
		{
			drawVoiture(i);
		}
	}

	// Ensuite, les voitures qui sautent pour qu'elles apparaissent au dessus des autres.
	for (int i = 0; i < MAX_VOITURES; ++i) 
	{
		ptr_car = getGameStateManager()->getGameData()->getOneCar(i);
		if (ptr_car->getEtatSaut() != 0) 
		{
			drawVoiture(i);
		}
	}

	delete ptr_spriteCircuit;
	delete ptr_spriteTrajectoire;
	delete ptr_spriteObstacles;
}

//------------------------------------------------------------------------------
void RaceState::drawVoiture(int n)
{
		Car *ptr_car = getGameStateManager()->getGameData()->getOneCar(n);
		sf::Sprite *ptr_sprite = getGameStateManager()->getGraphicsEngine()->getOneSpriteCar(n);
		double x = ptr_car->getPoint().getX();
		double y = ptr_car->getPoint().getY();

		// Est-on en train de sauter ?
		double e = ptr_car->getEtatSaut();
		if (e > 0)
		{
			// Phase descendante, on a un scale correspondant à l'état du saut (5, 4, 3, 2 puis 1).
			if (ptr_car->getEtatSaut() >= FIRST_ETAT_SAUT / 2) {
				// Phase ascendante, on a un scale inverse à l'état du saut (1, 2, 3, 4 puis 5).
				e = abs(e - FIRST_ETAT_SAUT - 1);
			}
			getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(n), ptr_sprite, x, y, e, e, ptr_car->getAngle());
		}
		else if (ptr_car->getEtatGlissade() > 0)
		{
			// On est en train de glisser : on affiche avec l'angle de glissade
			getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(n), ptr_sprite, x, y, 1.0, 1.0, ptr_car->getAngleGlissade());
		}
		else
		{
			// Affichage "normal".
			getGameStateManager()->getGraphicsEngine()->drawSprite(getGameStateManager()->getGraphicsEngine()->getOneTextureCar(n), ptr_sprite, x, y, 1.0, 1.0, ptr_car->getAngle());
		}
}

//------------------------------------------------------------------------------
void RaceState::update(int deltaTime)
{
	// Passer le relai au différents contrôleurs de voitures.
	ptr_controller_->update(GameData::VOITURE_JOUEUR_0, getGameStateManager());
	ptr_controller_->update(GameData::VOITURE_JOUEUR_1, getGameStateManager());
	ptr_iaController1_->update(GameData::VOITURE_JOUEUR_IA_0, getGameStateManager());
	ptr_iaController2_->update(GameData::VOITURE_JOUEUR_IA_1, getGameStateManager());
	// Tester les collisions.
	testCollisions();
	// Tester les obstacles.
	testObstacles();
	// Tester la fin de course.
	testVainqueur();
}

//------------------------------------------------------------------------------
void RaceState::keyboardEvent(KeyboardEvent *ptr_event)
{
	// Voiture des joueurs.
	Car *ptr_car1 = getGameStateManager()->getGameData()->getOneCar(GameData::VOITURE_JOUEUR_0);
	Car *ptr_car2 = getGameStateManager()->getGameData()->getOneCar(GameData::VOITURE_JOUEUR_1);

	//event.key.code == sf::Keyboard::A

	switch (ptr_event->getKeyCode())
	{
		case KEY_UP1:
			//cout << "KEY_UP1 " << endl;
			//cout << "ptr_event->getEvent() = " << ptr_event->getEvent() << endl;
			//cout << "KeyboardEvent::KEY_PRESSE = " << KeyboardEvent::KEY_PRESSE << endl;
			ptr_car1->setAccelere(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_DOWN1:
			ptr_car1->setFreine(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_LEFT1:
			ptr_car1->setLeft(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_RIGHT1:
			ptr_car1->setRight(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_UP2:
			ptr_car2->setAccelere(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_DOWN2:
			ptr_car2->setFreine(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_LEFT2:
			ptr_car2->setLeft(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;

		case KEY_RIGHT2:
			ptr_car2->setRight(ptr_event->getEvent() == KeyboardEvent::KEY_PRESSE);
			break;
			
		case KEY_ESCAPE:
			getGameStateManager()->setMenuState();
			break;
			
		default:
			break;
	}
}

//------------------------------------------------------------------------------
void RaceState::testCollisions()
{
	for (int i = 0; i < MAX_VOITURES; ++i) {
		Car *ptr_car1 = getGameStateManager()->getGameData()->getOneCar(i);
		// Pas de test collision si la voiture est déjà en obstacle.
		if (ptr_car1->getCollision() == 0 && ptr_car1->getEtatGlissade() == 0 && ptr_car1->getEtatSaut() == 0)
		{
			for (int j = 0; j < MAX_VOITURES; ++j)
			{
				// Ne pas tester la collision avec soi-même.
				if (i != j)
				{
					Car *ptr_car2 = getGameStateManager()->getGameData()->getOneCar(j);
					if (ptr_car2->getCollision() == 0 && ptr_car2->getEtatGlissade() == 0 && ptr_car2->getEtatSaut() == 0)
					{
						// Calcul de la distance entre les 2 voitures.
						//double distance = Math.hypot(abs(ptr_car1->getPoint()->getX() - ptr_car2->getPoint()->getX()), abs(ptr_car1->getPoint()->getY() - ptr_car2->getPoint()->getY()));
						double distance = ptr_car1->getPoint().distancePoint(ptr_car2->getPoint());
						if (distance < GraphicsEngine::DISTANCE_COLLISION)
						{
							// Conséquences de la collision.
							ptr_car1->setPoint(Point(ptr_car1->getOldPoint().getX(),ptr_car1->getOldPoint().getY()));
							ptr_car2->setPoint(Point(ptr_car2->getOldPoint().getX(),ptr_car2->getOldPoint().getY()));
							ptr_car1->setVitesse(0);
							ptr_car2->setVitesse(0);
							ptr_car1->setCollision(DELAI_COLLISION);
							ptr_car2->setCollision(DELAI_COLLISION);
						}
					}
				}
			}
		}
		else if (ptr_car1->getCollision() > 0)
		{
			// La voiture est déjà en collision on décrémente son indicateur.
			ptr_car1->setCollision(ptr_car1->getCollision() - 1);
		}
	}
}

//------------------------------------------------------------------------------
void RaceState::testObstacles()
{
	for (int i = 0; i < MAX_VOITURES; ++i)
	{
		Car *ptr_car = getGameStateManager()->getGameData()->getOneCar(i);
		// Si la voiture est en mode glissade, on poursuit l'animation de la glissade.
		if (ptr_car->getEtatGlissade() > 0)
		{
			ptr_car->setEtatGlissade(ptr_car->getEtatGlissade() - 1);
			ptr_car->setAngleGlissade((int)(ptr_car->getAngleGlissade() - (360 / FIRST_ETAT_GLISSADE)) % 360);
		}
		else if (ptr_car->getEtatSaut() > 1)
		{
			// Si la voiture est en mode saut, on poursuit l'animation du saut.
			ptr_car->setEtatSaut(ptr_car->getEtatSaut() - 0.1);
		}
		else
		{
			// Réinitialiser pour problèmes d'arrondis...
			ptr_car->setEtatGlissade(0);
			ptr_car->setEtatSaut(0);
				// Quelle est la couleur du pixel à la position de la voiture sur le masque obstacle ?
			sf::Color color = getGameStateManager()->getGraphicsEngine()->getPixelColorFromTexture(getGameStateManager()->getGraphicsEngine()->getTextureObstacles(), ptr_car->getPoint().getX(), ptr_car->getPoint().getY());
			if (color.r == 255 && color.g == 0)
			{
				// On est sur une flaque d'huile.
				ptr_car->setEtatGlissade(FIRST_ETAT_GLISSADE);
				ptr_car->setAngleGlissade(ptr_car->getAngle());
			}
			else if (color.b == 255 && color.r == 0)
			{
				// On est sur l'obstacle (traitement idem collision).
				ptr_car->setPoint(Point(ptr_car->getOldPoint().getX(),ptr_car->getOldPoint().getY()));
				ptr_car->setVitesse(0);
				ptr_car->setCollision(DELAI_COLLISION);
			}
			else if (color.g == 255 && color.r == 0)
			{
				// On est sur le tremplin.
				ptr_car->setEtatSaut(FIRST_ETAT_SAUT);
			}
		}
	}
}

//------------------------------------------------------------------------------
void RaceState::testVainqueur()
{
	int vainqueur = -1;
	for (int i = 0; i < MAX_VOITURES; ++i)
	{
		Car *ptr_car = getGameStateManager()->getGameData()->getOneCar(i);
		// La voiture a-t-elle terminé la course : sur secteur 1 du dernier tour + 1 ?
		if (ptr_car->getTour() > NOMBRE_TOURS && ptr_car->getSecteurAtteint() == 1)
		{
			ptr_car->setCourseTerminee(true);
			if (vainqueur == -1) {
				vainqueur = i;
			}
			else
			{
				// Un autre vainqueur a déjà été trouvé : on les départage en regardant qui est le plus loin (arrivée en ligne droite)
				if (ptr_car->getPoint().getX() > getGameStateManager()->getGameData()->getOneCar(vainqueur)->getPoint().getX())
				{
					vainqueur = i;
				}
			}
		}
	}
	// Si un vainqueur est détecté, changer d'état.
	if (vainqueur != -1) {
		getGameStateManager()->getGameData()->setVainqueur(vainqueur);
		getGameStateManager()->setEndRaceState();
	}
}