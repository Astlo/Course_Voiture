/**
 * Interface ISujet
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef ISUJET_HPP
#define ISUJET_HPP
#pragma once

/******************************************************************************/
class ISujet
{
	public:
	//Destructeur
		virtual ~ISujet();
	//Autres méthodes
		/**
		 * Ajouter un observateur d'événements clavier
		 * @param obj observateur d'événements clavier à ajouter
		 */
		virtual void enregistrer(IObserver obs) = 0;

		/**
		 * Supprimer un observateur
		 * @param obj observateur d'événements clavier à supprimer
		 */
		virtual void supprimer(IObserver obs) = 0;

		/**
		 * Notifier les observateur d'événements clavier
		 */
		virtual void notifierObs(KeyEvent event) = 0;

}; // interface ISujet
/******************************************************************************/

#endif // ISUJET_HPP