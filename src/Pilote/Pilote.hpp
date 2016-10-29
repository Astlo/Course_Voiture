/**
 * Fichier Pilote.hpp 
 *
 * Implémentation du pilote de voiture.
 * (Correspond à l'implémentation pour le pattern Decorateur).
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef PILOTE_HPP
#define PILOTE_HPP
#pragma once

class Pilote : public IPilote
{
	public:
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un pilote
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		**/
		Pilote()
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur d'un pilote
		 *
		 * @b Complexité O(1)
		**/
		~Pilote();
		
	//Autres méthodes
		/** --------------------------------------------------------------------
		 * @overried
		 * 
		 * @b Complexité 
		**/
		void actualiser (unsigned joueur, Gestionnaire gestionnaire);
}; // class Pilote
/******************************************************************************/

#endif // Pilote_HPP
