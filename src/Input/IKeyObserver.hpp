/**
 * @file IKeyObserver.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Interface Observatrice.
 * @b (Pattern Observer)
**/

#ifndef IKEYOBSERVER_HPP
#define IKEYOBSERVER_HPP
#pragma once

/******************************************************************************/
class IKeyObserver
{
	public:
	
	//Methode
		/** --------------------------------------------------------------------
		 * @brief Un événement clavier s'est produit.
		 *
		 * @param event Evénement clavier
		 *
		 * @b Complexité O();
		 */
		virtual void keyEvent(KeyEvent * event) = 0;

}; //class IKeyObserver
/******************************************************************************/

#endif // IKEYOBSERVER_HPP