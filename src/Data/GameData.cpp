/**
 * @file GameData.cpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Définition des méthodes de la classe GameData.
**/

#include "GameData.hpp"

#include <cmath> //pour les fonctions mathématiques
#include <sstream> //pour les conversions en chaine


#include "../Constants.hpp"
#include "../Point.hpp"
#include "AICar.hpp"
#include "Car.hpp"


using namespace std;

//CONSTANTES
//------------------------------------------------------------------------------
const int VOITURE_JOUEUR_0 = 0;

//------------------------------------------------------------------------------
const int VOITURE_JOUEUR_1 = 1;

//------------------------------------------------------------------------------
const int VOITURE_JOUEUR_IA_0 = 2;

//------------------------------------------------------------------------------
const int VOITURE_JOUEUR_IA_1 = 3;

//CONSTRUCTEUR
//------------------------------------------------------------------------------
GameData::GameData() 
{
	ptr_cars_[VOITURE_JOUEUR_0] = new Car();
	ptr_cars_[VOITURE_JOUEUR_1] = new Car();
	ptr_cars_[VOITURE_JOUEUR_IA_0] = new AICar();
	ptr_cars_[VOITURE_JOUEUR_IA_1] = new AICar();
}

//DESTRUCTEUR
//------------------------------------------------------------------------------
GameData::~GameData() 
{
	delete ptr_cars_[VOITURE_JOUEUR_0];
	delete ptr_cars_[VOITURE_JOUEUR_1];
	delete ptr_cars_[VOITURE_JOUEUR_IA_0];
	delete ptr_cars_[VOITURE_JOUEUR_IA_1];
}

//METHODES
//------------------------------------------------------------------------------
void GameData::reset() 
{
	vainqueur_ = -1;
	for (int i = 0; i < MAX_VOITURES; ++i) 
	{
			ptr_cars_[i]->reset();
	}
}

//------------------------------------------------------------------------------
int GameData::calculeTrajectoire(sf::Image & image, int xDebut, int yDebut, Point *ptr_t[]) 
{
		//sf::Color color = new Color();
		int r = 0;
		int g = 0;
		int b = 0;
		int x = xDebut;
		int y = yDebut;
		int i = 0;
		ptr_t[i++] = new Point(x, y);
		Point* ptr_trouve;
		do {
			ptr_trouve = NULL;
			// Boucler autour du carré encadrant le point courant (attention on
			// progresse vers la droite).
			for (int j = x + 1; j > x - 2; j--) {
				for (int k = y + 1; k > y - 2; k--) {
					// Ecarter les points déjà traités
					if (!pointDejaDansTrajectoire(ptr_t,Point(j, k))) {
						sf::Color color = image.getPixel(j, k);
						r = (int) color.r;
						g = (int) color.g;
						b = (int) color.b;
						// Ni noir, ni blanc
						if (!(r == 0 && g == 0 && b == 0) && !(r == 255 && g == 255 && b == 255)) {
							x = j;
							y = k;
							ptr_trouve = new Point(x, y);
							break;
						}
					}
				}
				if (ptr_trouve != NULL) {
					break;
				}
			}
			ptr_t[i++] = ptr_trouve;
		} while (ptr_trouve != NULL);
		return --i;
}

//------------------------------------------------------------------------------
bool GameData::pointDejaDansTrajectoire(Point *ptr_t[], Point point)
{
	bool trouve = false;
	int i = 0;
	while((trouve == false) && (i < MAX_TRAJECTOIRE))
	{
		if (ptr_t[i] == NULL) {
			i = MAX_TRAJECTOIRE;
		}
		if (ptr_t[i]->getX() == point.getX() && ptr_t[i]->getY() == point.getY()) {
			trouve = true;
		}
		++i;
	}
	return trouve;
}

//------------------------------------------------------------------------------
//int pointTrajectoireLePlusProche(Point[] t, int x, int y)
//{
//		// TODO à optimiser pour éviter de parcourir tous les points...
//		double d = Integer.MAX_VALUE;
//		int p = 0;
//		for (int i = 0; i < t.length; i++) {
//			if (t[i] == null) {
//				break;
//			}
//			if (t[i].x == x && t[i].y == y) {
//				p = i;
//				break;
//			} else {
//				double distance = Math.hypot(Math.abs(x - t[i].x), Math.abs(y - t[i].y));
//				if (distance < d) {
//					d = distance;
//					p = i;
//				}
//			}
//		}
//		return p;
//}

//------------------------------------------------------------------------------
int GameData::getSecteurFromColor(sf::Color color)
{
	if (color.r == 255 && color.g == 0) {
		return 1;
	} else if (color.r == 0 && color.g == 255) {
		return 2;
	} else if (color.r == 0 && color.b == 255) {
		return 3;
	} else if (color.r == 255 && color.g != 0 && color.b == 0) {
		return 4;
	} else if (color.r > 0 && color.r < 255 && color.r == color.g && color.g == color.b) {
		return 5;
	} else {
		return 0;
	}
}

//ACCESSEURS
//------------------------------------------------------------------------------
Car* GameData::getOneCar(int indice)
{
		return ptr_cars_[indice];
}

//------------------------------------------------------------------------------
Point* GameData::getUnPointTrajectoireIA (int i, int j)
{
		Point *ptr_point;
		ptr_point = new Point(trajectoiresIA_[i][j].getX(), trajectoiresIA_[i][j].getY());
		return ptr_point;
}

//------------------------------------------------------------------------------
int GameData::getNbPointsTrajectoiresIA(int player)
{
		return nbPointsTrajectoiresIA_[player];
}

//------------------------------------------------------------------------------
int GameData::getVainqueur()
{
		return vainqueur_;
}

//MUTATEURS
//------------------------------------------------------------------------------
void GameData::setNbPointsTrajectoiresIA(int player, int p)
{
		nbPointsTrajectoiresIA_[player] = p;
}

//------------------------------------------------------------------------------
void GameData::setVainqueur(int vainqueur)
{
		vainqueur_ = vainqueur;
}