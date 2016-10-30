/**
 * @file InputEngine.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Moteur de gestion des entrées claviers.
 * @b (Pattern Observer)
**/

#ifndef INPUTENGINE_HPP
#define INPUTENGINE_HPP
#pragma once

#include <iostream>
#include <vector> //pour le type std::vector

/******************************************************************************/
class InputEngine /*: public InputAdapter*/ : public KeyObservable
{
	public:
	
	//Constantes
		/** --------------------------------------------------------------------
		 * Codes LIBGDX des touches clavier pour le joueur 1.
		**/
		static const int KEY_UP1;
		static const int KEY_DOWN1;
		static const int KEY_LEFT1;
		static const int KEY_RIGHT1;

		/** --------------------------------------------------------------------
		 * Codes LIBGDX des touches clavier pour le joueur 2.
		**/
		static const int KEY_UP2;
		static const int KEY_DOWN2;
		static const int KEY_LEFT2;
		static const int KEY_RIGHT2;

		/** --------------------------------------------------------------------
		 * Code LIBGDX pour escape.
		**/
		static const int KEY_ESCAPE;

		/** --------------------------------------------------------------------
		 * Nombre maximum de touches claviers gérées.
		**/
		static const int MAX_KEYS;
		
	//Constructeur et destructeur;
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
	
		void addObs(KeyObserver * o);
		
		void removeObs(KeyObserver * o);

		void notifyObs(const KeyEvent * event);
		
/*
		boolean keyDown(int keycode);

		boolean keyUp(int keycode);
*/	
	private:
	
	//Attributs
		/**
		 * Liste des observateurs 
		**/
		vector<IKeyObserver> obs_;
		
	//Autres méthodes
		/**
		 * @brief Renvoie la position à laquelle se trouve l'observateur donnée en paramètre
		 *
		 * @param o Observateur d'événements clavier
		 *
		 * @return la position de o dans obs_
		 * 
		 * @b Complexité O()
		**/
		int positionObs(const IKeyObserver * o) const;
		
		bool equals(const IKeyObserver * o) const;
		
}; //class InputEngine
/******************************************************************************/

#endif // INPUTENGINE_HPP
