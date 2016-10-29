/**
 * Interface Observateur.
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef IOBSERVATEUR_HPP
#define IOBSERVATEUR_HPP
#pragma once

/******************************************************************************/
class IObservateur
{
	public:
	
	// Destructeur
		virtual ~IObservateur();

		/**
		 * Un événement clavier s'est produit.
		**/
	//Autres méthodes virtuelles
		/**
		* @brief Un événement clavier s'est produit.
		* 
		* @param evenement EvenementClavier.
		**/
		virtual void evenementClavier(EvenementClavier evenement) = 0;

}; // interface IObservateur
/******************************************************************************/

#endif // IOBSERVATEUR_HPP