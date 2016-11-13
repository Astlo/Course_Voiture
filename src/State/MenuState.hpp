/**
 * @file MenuState.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Etat menu.
 * @b (Pattern State)
**/

#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#pragma once

#include <string> // pour le type std::string

#include "GameState.hpp"

//class GameStateManager;
//class KeyboardEvent;

/******************************************************************************/
class MenuState : public GameState
{
	public:
	
	//Méthodes
		void init();

		void draw();

		void update(int deltaTime);

		void keyboardEvent(KeyboardEvent *ptr_event);
	
	//protected:
	
	//Constructeur et destructeur
		MenuState(GameStateManager *ptr_gameStateManager);
		~MenuState();

	private:
	
	//Attributs
		/**
		 * Pour l'animation du menu (position d'affichage des voitures à la queue leu leu).
		**/
		int p_;


}; //class MenuState
/******************************************************************************/

#endif // MENUSTATE_HPP