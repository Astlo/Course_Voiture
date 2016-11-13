/**
 * @file AICar.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie une voiture IA.
**/

#ifndef AICAR_HPP
#define AICAR_HPP
#pragma once

#include <string> // pour le type std::string

#include "Car.hpp"
#include "../Constants.hpp"

/******************************************************************************/
class AICar : public Car
{
	public:
	
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'une voiture IA
		 *
		 * @b Complexité O(1)
		**/
		AICar();
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur d'une voiture IA
		 *
		 * @b Complexité O(1)
		**/
		~AICar();
		
	//Méthodes
		/** --------------------------------------------------------------------
		 * @brief Réinitialisation à chaque course.
		 *
		 * @b Complexité O(1)
		**/
		void reset();
		
		/** --------------------------------------------------------------------
		 * @brief Affichage de la voiture.
		 * 
		 * @return une chaine de caractère comprenant l'affichage de la voiture
		 * 
		 * @b Complexité O(1)
		**/
		std::string toString();
	
	//Accesseurs et mutateurs
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la position de la voiture dans la trajectoire.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getPositionTrajectoire();
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la vitesse maximale de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getVitesseMaxi();
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la valeur de variation de la vitesse maxi de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getVariationVitesseMaxi();
		
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur d'un angle dans le tableau des angles précédents.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getOneOldAngle(int indice);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la position de la voiture dans la trajectoire.
		 *
		 * @param positionTrajectoire Entier
		 *
		 * @b Complexité O(1)
		**/
		void setPositionTrajectoire(int positionTrajectoire);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la vitesse maximale de la voiture.
		 *
		 * @param vitesseMaxi Réel
		 *
		 * @b Complexité O(1)
		**/
		void setVitesseMaxi(double vitesseMaxi);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la valeur de variation de la vitesse maxi de la voiture.
		 *
		 * @param variationVitesseMaxi Réel
		 *
		 * @b Complexité O(1)
		**/
		void setVariationVitesseMaxi(double variationVitesseMaxi);

		void setOneOldAngle(double angle, int indice);
	
	private:
	
	//Attributs
		/**
		 * Position de la voiture dans la trajectoire.
		**/
		int positionTrajectoire_;
		/**
		 * Tableaux des angles précédents pour le lissage à l'écran.
		**/
		double oldAngle_[MAX_ANGLE];
		/**
		 * Vitesse maximale de la voiture.
		**/
		double vitesseMaxi_;
		/**
		 * Valeur de variation de la vitesse maxi.
		**/
		double variationVitesseMaxi_;		
}; //class AICar
/******************************************************************************/

#endif // AICAR_HPP
