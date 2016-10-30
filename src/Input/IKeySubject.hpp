/**
 * @file IKeySubject.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Interface Sujet.
 * @b (Pattern Observer)
**/

#ifndef IKEYSUBJECT_HPP
#define IKEYSUBJECT_HPP
#pragma once

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
		 * @b Complexité O()
		**/
		virtual void addObs(KeyObserver * o) = 0;

		/** --------------------------------------------------------------------
		 * @brief Supprimer un observateur d'événements clavier
		 *
		 * @param o Observateur d'événements clavier à supprimer
		 *
		 * @b Complexité O()
		**/
		virtual void removeObs(KeyObserver * o) = 0;

		/** --------------------------------------------------------------------
		 * @brief Notifier les observateur d'événements clavier
		 *
		 * @param event Evénement clavier à transmettre
		 *
		 * @b Complexité O()
		**/
		virtual void notifyObs(KeyEvent * event) = 0;

}; //class IKeySubject
/******************************************************************************/

#endif // IKEYSUBJECT_HPP