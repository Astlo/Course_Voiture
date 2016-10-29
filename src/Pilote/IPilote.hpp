/**
 * Interface des pilotes de voitures.
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef IPILOTE_HPP
#define IPILOTE_HPP
#pragma once

/******************************************************************************/
class IPilote
{
	public:
	
	// Destructeur
		virtual ~I_Pilote() {}
		
	//Autres méthodes virtuelles
		/**
		* @brief Mise à jour de l'état d'une voiture.
		* 
		* @param joueur Joueur.
		* @param gestionnaire Gestionnaire.
		**/
		virtual void actualiser (unsigned joueur, Gestionnaire gestionnaire) = 0;
}; // interface IPilote
/******************************************************************************/

#endif // IPilote_HPP