/**
 * @file RaceState.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Etat course.
 * @b (Pattern State)
**/

#ifndef RACESTATE_HPP
#define RACESTATE_HPP
#pragma once

#include <string> // pour le type std::string

#include "GameState.hpp"
#include "../Decorator/IController.hpp"

class RaceState : public GameState
{
	public:
	
	//Méthodes
		void init();

		void draw();

		/** --------------------------------------------------------------------
		 * @biref Affichage d'une voiture.
		 *
		 * @param n Numéro de la voiture;
		 *
		 * @b Complexité O()
		 */
		void drawVoiture(int n);

		void update(int deltaTime);

		void keyboardEvent(KeyboardEvent *ptr_event);
	
	//protected:
	
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur
		 *
		 * @param ptr_gameStateManager GameStateManager (client du pattern State)
		 *
		 * @b Complexité O()
		**/
		RaceState(GameStateManager *ptr_gameStateManager);
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur.
		 *
		 * @b Complexité O()
		**/
		~RaceState();
	
	private:
	
	//Attributs
		/**
		 * Contrôleur de voiture principal.
		**/
		IController *ptr_controller_;
		/**
		 * Contrôleur de voiture IA type 1.
		**/
		IController *ptr_iaController1_;
		/**
		 * Contrôleur de voiture IA type 2.
		**/
		IController *ptr_iaController2_;
		
	//Méthodes
		/** --------------------------------------------------------------------
		 * @brief Gestion des collisions.
		 *
		 * @b Complexité O()
		 */
		void testCollisions();

		/** --------------------------------------------------------------------
		 * @brief Gestion des obstacles.
		 * 
		 * @b Complexité O()
		 */
		void testObstacles();
		
		/** --------------------------------------------------------------------
		 * @brief Gestion fin de course.
		 *
		 *@b Complexité O()
		 */
		void testVainqueur();

}; //class RaceState
/******************************************************************************/

#endif // RACESTATE_HPP