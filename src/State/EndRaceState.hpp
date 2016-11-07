/**
 * @file EndRaceState.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Etat de fin de course.
 * @b Hérite de l'affichage de l'état course et le stabilise.
 * @b (Pattern State)
**/

#ifndef ENDRACESTATE_HPP
#define ENDRACESTATE_HPP
#pragma once

#include <string> // pour le type std::string

#include "RaceState.hpp"

class EndRaceState : public RaceState
{
	public:
	
	//Méthodes
		void init();

		void draw();

		void update(double deltaTime);

		void keyboardEvent(KeyboardEvent *ptr_event);
	
	protected:
	
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur
		 *
		 * @param ptr_gameStateManager GameStateManager (client du pattern State)
		 *
		 * @b Complexité O()
		**/
		EndRaceState(GameStateManager *ptr_gameStateManager);
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur.
		 *
		 * @b Complexité O()
		**/
		~EndRaceState();
	
	
}; //class EndRaceState
/******************************************************************************/

#endif // ENDRACESTATE_HPP