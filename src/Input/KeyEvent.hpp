/**
 * @file KeyEvent.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie un événement clavier.
**/

#ifndef KEYEVENT_HPP
#define KEYEVENT_HPP
#pragma once

#include <string> // pour le type std::string

/******************************************************************************/
class KeyEvent
{
	public:
	
	//Constantes
		/** --------------------------------------------------------------------
		 * Evénement : une touche a été enfoncée.
		**/
		static const int KEY_PRESSE; //KEY_DOWN

		/** --------------------------------------------------------------------
		 * Evénement : une touche a été relâchée.
		**/
		static const int KEY_RELEASE;
		
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un événement clavier
		 *
		 * @param event Entier
		 * @param keyCode Entier
		 *
		 * @b Complexité O(1)
		**/
		KeyEvent(int event, int keyCode);
		
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un événement clavier
		 *
		 * @param event Entier
		 * @param keyCode Entier
		 *
		 * @b Complexité O(1)
		**/
		~KeyEvent();

	//Accesseur et Mutateur
		/** --------------------------------------------------------------------
		 * @brief Accesseur du type de l'événement.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getEvent() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur du code de la touche.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getKeyCode() const;
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur du type de l'événement.
		 *
		 * @param event Entier
		 *
		 * @b Complexité O(1)
		**/
		void setEvent(int event);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur du code de la touche.
		 *
		 * @param keyCode Entier
		 *
		 * @b Complexité O(1)
		**/
		void setKeyCode(int keyCode);

	//Autres méthodes
		/** --------------------------------------------------------------------
		 * @brief Affichage de l'événement clavier
		 * 
		 * @return une chaine de caractère comprenant l'affichage de l'événement clavier
		 * 
		 * @b Complexité O(1)
		**/	
		std::string toString() const;
	
	private:
	
	//Attributs
		/**
		 * Type de l'événement.
		**/
		int event_;

		/**
		 * Code de la touche.
		**/
		int keyCode_;

}; //class KeyEvent
/******************************************************************************/

#endif // KEYEVENT_HPP
