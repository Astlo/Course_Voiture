/**
 * @file IKeySubject.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Interface Sujet.
 * @b (Pattern Observer)
**/

#ifndef IKEYSUBJECT_HPP
#define IKEYSUBJECT_HPP
#pragma once

#include "IKeyObserver.hpp"
#include "KeyboardEvent.hpp"

/******************************************************************************/
class IKeySubject
{
	public:
	
	//Methodes
		/** --------------------------------------------------------------------
		 * @brief Ajouter un observateur d'événements clavier
		 *
		 * @param o Observateur d'événements clavier à ajouter
		 *
		 * @b Complexité O(1)
		**/
		virtual void addObs(IKeyObserver *ptr_obs) = 0; // enregistrerObs(Observer o)

		/** --------------------------------------------------------------------
		 * @brief Supprimer un observateur d'événements clavier
		 *
		 * @param o Observateur d'événements clavier à supprimer
		 *
		 * @b Complexité O()
		**/
		virtual void removeObs(IKeyObserver *ptr_obs) = 0; //supprimerObs (Observer o)

		/** --------------------------------------------------------------------
		 * @brief Notifier les observateur d'événements clavier
		 *
		 * @param event Evénement clavier à transmettre
		 *
		 * @b Complexité O()
		**/
		virtual void notifyObs(KeyboardEvent *ptr_event) = 0; //notifierObs()

}; //class IKeySubject
/******************************************************************************/

#endif // IKEYSUBJECT_HPP