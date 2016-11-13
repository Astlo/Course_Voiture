/*
model;
Point;
Color;
Pixmap;
*/
/**
 * @file GameData.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie les données du jeu.
**/

#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP
#pragma once

#include <string> // pour le type std::string

#include <SFML/Graphics.hpp>

/*#include "Car.hpp"*/
#include "../Point.hpp"
#include "../Constants.hpp"


class Car;
class AICar;

//Constantes



/*****************************************************************************/
class GameData
{
	public:
		/**
		 * Indice de la voiture du premier joueur.
		**/
		static const int VOITURE_JOUEUR_0;

		/**
		 * Indice de la voiture du second joueur.
		**/
		static const int VOITURE_JOUEUR_1;

		/**
		 * Indice de la voiture du premier joueur IA.
		**/
		static const int VOITURE_JOUEUR_IA_0;

		/**
		 * Indice de la voiture du second joueur IA.
		**/
		static const int VOITURE_JOUEUR_IA_1;

		//Constructeur 
		GameData();
		~GameData();

	//Méthodes
		/** --------------------------------------------------------------------
		 * @brief Réinitialisation à chaque course.
		 *
		 * @b Complexité O(1)
		**/
		void reset();

		/** --------------------------------------------------------------------
		 * @brief Calcule des points d'une trajectoire.
		 *
		 * @param Image Image de pixels
		 * @param xDebut Entier : origine x
		 * @param yDebut Entier : origine y
		 * @param t Tableaux de points à calculer.
		 *
		 * @return Le nombre de points.
		 *
		 * @pre
		 * @pos
		 *
		 * @b Complexité O()
		 */
		int calculeTrajectoire(sf::Image & image, int xDebut, int yDebut, Point *ptr_t[]);

		/** --------------------------------------------------------------------
		 * @brief Indique si le point est déjà dans la trajectoire.
		 *
		 * @param t Points de la trajectoire.
		 * @param point Point  à tester
		 * 
		 * @return Vrai sur le point est déjà dans la trajectoire, sinon faux.
		 *
		 * @pre
		 * @pos
		 *
		 * @b Complexité O(MAX_TRAJECTOIRE)
		 */
		bool pointDejaDansTrajectoire(Point *ptr_t[], Point point) ;

		/** --------------------------------------------------------------------
		 * @brief Donne le point de trajectoire le plus proche du point à tester.
		 *
		 * @param t Points de la trajectoire.
		 * @param point Point à tester
		 *
		 * @return un point
		 *
		 * @b Complexité O()
		 */
//		int pointTrajectoireLePlusProche(Point t[], Point point);

	//Accesseurs et mutateurs
		/**--------------------------------------------------------------------
		 * @brief Accesseur du secteur correspondant à la couleur en paramètre.
		 *
		 * @param color Couleur à tester.
		 *
		 * @return Numéro du secteur.
		 *
		 * @b Complexité O()
		 */
		int getSecteurFromColor(sf::Color color);
		
		/**--------------------------------------------------------------------
		 * @brief Accesseur d'une voiture dans le tableau cars_.
		 *
		 * @param indice Entier.
		 *
		 * @return une voiture.
		 *
		 * @b Complexité O()
		 */
		Car* getOneCar(int indice);
		
		/**--------------------------------------------------------------------
		 * @brief Accesseur d'un point de la trajectoire IA.
		 *
		 * @param i Entier : indice de la première colonne.
		 * @param j Entier : indice de la deuxième colonne.
		 *
		 * @return un Point
		 *
		 * @b Complexité O()
		 */
		Point* getUnPointTrajectoireIA (int i, int j);
		
		/**--------------------------------------------------------------------
		 * @brief Accesseur du nombre de points dans la trajectoire d'une des IA.
		 *
		 * @param player Voiture IA.
		 *
		 * @return nombre de points.
		 *
		 * @b Complexité O()
		 */
		int getNbPointsTrajectoiresIA (int player);
		void setUnPointTrajectoireIA(int i, int j, Point point);
		
		/**--------------------------------------------------------------------
		 * @brief Accesseur du vainqueur de la course.
		 *
		 * @return le numéro du gagnant.
		 *
		 * @b Complexité O()
		 */
		int getVainqueur();
		
		/**--------------------------------------------------------------------
		 * @brief Mutateur du nombre de points dans la trajectoire d'une des IA.
		 *
		 * @param player Voiture IA.
		 * @param p Entier remplaçant
		 *
		 * @b Complexité O()
		 */
		void setNbPointsTrajectoiresIA (int player, int p);
		
		/**--------------------------------------------------------------------
		 * @brief Mutateur du vainqueur de la course.
		 *
		 * @param vainqueur Numéro du vainqeur.
		 *
		 * @b Complexité O()
		 */		
		void setVainqueur (int vainqueur);
	
	private:
	//Attributs
		/**
		 * Voitures
		**/
		Car* ptr_cars_[MAX_VOITURES];

		/**
		 * Points des trajectoires IA.
		**/
		Point trajectoiresIA_[MAX_JOUEUR_IA][MAX_TRAJECTOIRE];

		/**
		 * Nombre de points dans la trajectoire.
		**/
		int nbPointsTrajectoiresIA_[MAX_JOUEUR_IA];

		/**
		 * Voiture ayant gagné la course.
		**/
		int vainqueur_;

}; // class GameData
/**************************************************************************** */

#endif // GAMEDATA_HPP