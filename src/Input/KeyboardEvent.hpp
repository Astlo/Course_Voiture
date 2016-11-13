/**
 * @file KeyboardEvent.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie un événement clavier.
**/

#ifndef KEYBOARDEVENT_HPP
#define KEYBOARDEVENT_HPP
#pragma once

#include <string> // pour le type std::string

#include <SFML/Window.hpp>

/******************************************************************************/
class KeyboardEvent
{
	public:
	
	//Constantes
		/** --------------------------------------------------------------------
		 * Evénement : une touche a été enfoncée.
		**/
		static const sf::Event::EventType KEY_PRESSE; //KEY_DOWN

		/** --------------------------------------------------------------------
		 * Evénement : une touche a été relâchée.
		**/
		static const sf::Event::EventType KEY_RELEASE;
		
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un événement clavier
		 *
		 * @param event Entier
		 * @param keyCode Entier
		 *
		 * @b Complexité O(1)
		**/
		KeyboardEvent(sf::Event::EventType event, sf::Keyboard::Key keyCode);
		
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un événement clavier
		 *
		 * @param event Entier
		 * @param keyCode Entier
		 *
		 * @b Complexité O(1)
		**/
		~KeyboardEvent();
	
	//Méthode
		/** --------------------------------------------------------------------
		 * @brief Affichage de l'événement clavier
		 * 
		 * @return une chaine de caractère comprenant l'affichage de l'événement clavier
		 * 
		 * @b Complexité O(1)
		**/	
		//std::string toString() const;

	//Accesseur et Mutateur
		/** --------------------------------------------------------------------
		 * @brief Accesseur du type de l'événement.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		sf::Event::EventType getEvent() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur du code de la touche.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		sf::Keyboard::Key getKeyCode() const;
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur du type de l'événement.
		 *
		 * @param event Entier
		 *
		 * @b Complexité O(1)
		**/
		void setEvent(sf::Event::EventType event);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur du code de la touche.
		 *
		 * @param keyCode Entier
		 *
		 * @b Complexité O(1)
		**/
		void setKeyCode(sf::Keyboard::Key keyCode);
	
	private:
	
	//Attributs
		/**
		 * Type de l'événement.
		**/
		sf::Event::EventType event_;

		/**
		 * Code de la touche.
		**/
		sf::Keyboard::Key keyCode_;

}; //class KeyboardEvent
/******************************************************************************/

#endif // KEYBOARDEVENT_HPP
