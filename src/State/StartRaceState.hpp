/**
 * @file StartRaceState.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Etat début de course.
 * @b (Pattern State)
**/

#ifndef STARTRACESTATE_HPP
#define STARTRACESTATE_HPP
#pragma once

#include <string> // pour le type std::string

#include <SFML/Graphics.hpp>
 
#include "GameStateManager.hpp"
#include "RaceState.hpp"
#include "GameState.hpp"

class StartRaceState : public RaceState
{
	public:
	
	//Méthodes
		void init();

		void draw();

		void update(double deltaTime);
	
	protected:
	
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur
		 *
		 * @param ptr_gameStateManager GameStateManager (client du pattern State)
		 *
		 * @b Complexité O()
		**/
		StartRaceState(GameStateManager *ptr_gameStateManager);
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur.
		 *
		 * @b Complexité O()
		**/
		~StartRaceState();
	
	private:
	
	//Attribut
		/**
		 * Indicateur de décompte pour le départ.
		**/
		double decompte;
		
}; //class StartRaceState
/******************************************************************************/

#endif // STARTRACESTATE_HPP