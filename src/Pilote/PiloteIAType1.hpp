/**
 * Fichier PiloteIAType1.hpp
 *
 * Décorateur : implémentation décorée type 1
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef PILOTEIA_HPP
#define PILOTEIA_HPP
#pragma once

/******************************************************************************/
class PiloteIAType1 : public PiloteIA
{
	public:
	//Constante
		/** --------------------------------------------------------------------
		 * L'IA 1 a une vitesse maxi constante mais légèrement inférieure aux joueurs.
		**/
		static const int VITESSE_MAXI = Constants.VITESSE_AVANT_MAXI - 1;
		
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur du décorateur
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		**/
		PiloteIAType1(IPilote iPilote);
		
		/** --------------------------------------------------------------------
		 * @brief Constructeur du décorateur
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		**/
		~PiloteIAType1();
		
	private:
	//Autres méthodes
		/** --------------------------------------------------------------------
		 * @Override
		**/
		void apresActualiser(unsigned joueur, Gestionnaire gestionnaire);
	
}; //class PiloteIAType1
/******************************************************************************/

#endif // PiloteIAType1_HPP