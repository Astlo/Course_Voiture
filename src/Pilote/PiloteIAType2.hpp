/**
 * Fichier PiloteIAType2.hpp
 *
 * Décorateur : implémentation décorée type 2
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef PILOTEIA_HPP
#define PILOTEIA_HPP
#pragma once

/******************************************************************************/
class PiloteIAType2 : public PiloteIA
{
	public:
	//Constante
		/** --------------------------------------------------------------------
		 * L'IA 2 a une vitesse maxi variable.
		**/
		static const int VITESSE_MAXI_INFERIEURE = 2;
		static const int VITESSE_MAXI_SUPERIEURE = 6;
		
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur du décorateur
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		**/
		PiloteIAType2(IPilote iPilote);
		
		/** --------------------------------------------------------------------
		 * @brief Constructeur du décorateur
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		**/
		~PiloteIAType2();
		
	private:
	//Autres méthodes
		/** --------------------------------------------------------------------
		 * @Override
		**/
		void avantActualiser(unsigned joueur, Gestionnaire gestionnaire);
	
}; //class PiloteIAType2
/******************************************************************************/

#endif // PiloteIAType2_HPP
