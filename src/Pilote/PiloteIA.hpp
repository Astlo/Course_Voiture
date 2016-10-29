/**
 * Fichier PiloteIA.hpp 
 *
 * Implémentation du décorateur pour les voitures IA.
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef PILOTEIA_HPP
#define PILOTEIA_HPP
#pragma once

/******************************************************************************/
class PiloteIA : public Decorateur
{
	private:
		/**
		 * Avant mise à jour.
		**/
		void avantActualiser(unsigned joueur, Gestionnaire gestionnaire);
		/**
		 * Après mise à jour, on corrige la trajectoire.
		**/
		void apresActualiser(unsigned joueur, Gestionnaire gestionnaire);
		
	public:
	// Constructeur et destructeur
		PiloteIA(IPilote iPilote);
		~PiloteIA();
		
	//Autres méthodes
		/**
		 * @overried
		 * 
		 * @b Complexité 
		**/
		void actualiser (unsigned joueur, Gestionnaire gestionnaire);
		
}; // class PiloteIA
/******************************************************************************/

#endif // PiloteIA_HPP