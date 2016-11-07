/**
 * @file InputEngine.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Moteur de gestion des entrées claviers.
 * @b (Pattern Observer)
**/

#ifndef INPUTENGINE_HPP
#define INPUTENGINE_HPP
#pragma once

#include <vector> //pour le type std::vector
#include <iostream>

#include "IKeySubject.hpp"
#include "IKeyObserver.hpp"
#include "KeyboardEvent.hpp"

/******************************************************************************/
class InputEngine : public IKeySubject
{
	public:
		
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un moteur de clavier
		 *
		 * @b Complexité O(1)
		**/
		InputEngine();
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur d'un moteur de clavier
		 *
		 * @b Complexité O(1)
		**/
		~InputEngine();
		

	//Méthodes interface
	
		virtual void addObs(IKeyObserver *ptr_obs);
		
		virtual void removeObs(IKeyObserver *ptr_obs);

		virtual void notifyObs(KeyboardEvent *ptr_event);

		bool keyDown(sf::Keyboard::Key keycode);

		bool keyUp(sf::Keyboard::Key keycode);
	
	private:
	
	//Attributs
		/**
		 * Liste des observateurs 
		**/
		std::vector<IKeyObserver*> obs_;
		
	//Autres méthodes
		/**
		 * @brief Renvoie la position à laquelle se trouve l'observateur donnée en paramètre
		 *
		 * @param o Observateur d'événements clavier
		 *
		 * @return la position de o dans obs_
		 * 
		 * @b Complexité O(n), n étant la taille de obs_
		**/
//		int positionObs(IKeyObserver *ptr_obs);
		
}; //class InputEngine
/******************************************************************************/

#endif // INPUTENGINE_HPP
