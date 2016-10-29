/**
 * Evénement clavier.
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef EVENEMENTCLAVIER_HPP
#define EVENEMENTCLAVIER_HPP
#pragma once

/******************************************************************************/
class EvenementClavier
{
	public:
	//Constantes
		/** Evénément : une touche a été enfoncée. */
		public static final int KEY_DOWN = 0;

		/** Evénément : une touche a été relâchée. */
		public static final int KEY_RELEASE = 1;
		
	//Constructeur et destructeur
		EvenementClavier(int event, int keyCode);
		~EvenementClavier();

	//Accesseur et Mutateur
		/** --------------------------------------------------------------------
		 * @brief Accesseur
		 *
		 * @b Complexité O(1)
		**/
		public int getEvent();
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur
		 *
		 * @b Complexité O(1)
		**/
		public int getKeyCode();
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur
		 *
		 * @b Complexité O(1)
		**/
		public void setEvent(int event);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur
		 *
		 * @b Complexité O(1)
		**/	
		public void setKeyCode(int keyCode);

	//Autres méthodes
		/**
		 *@Override
		**/
		public String toString();
	
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

}; //class EvenementClavier
/******************************************************************************/

#endif // EVENEMENTCLAVIER_HPP
