/**
 * Gestion des entrées claviers.
 * (pattern observer)
 * @author LE BARS Yannis & HUNAULT Marion
**/
 
#ifndef GESTIONCLAVIER_HPP
#define GESTIONCLAVIER_HPP
#pragma once

/******************************************************************************/
class GestionClavier : public ISujet
{
	public:
	//Constantes
		/** Codes LIBGDX des touches clavier pour le joueur 1. */
		static const int KEY_UP1 = 19;
		static const int KEY_DOWN1 = 20;
		static const int KEY_LEFT1 = 21;
		static const int KEY_RIGHT1 = 22;

		/** Codes LIBGDX des touches clavier pour le joueur 2. */
		static const int KEY_UP2 = 54;
		static const int KEY_DOWN2 = 47;
		static const int KEY_LEFT2 = 45;
		static const int KEY_RIGHT2 = 32;

		/** Code LIBGDX pour escape. */
		static const int KEY_ESCAPE = 131;

		/** Nombre maximum de touches claviers gérées. */
		static const int MAX_KEYS = 4;
	
	//Constructeur et destructeur
		GestionClavier(List<IObservateur> obs);
		~GestionClavier();
		
	//Autres méthodes
		/**
		 * @overried
		 */
		void enregistrer(IObserver obs);

		/**
		 * @overried
		 */
		void supprimer(IObserver obs);

		/**
		 * @overried
		 */
		void notifierObs(KeyEvent event);
		
	private:
	//Attributs
		/**
		 * Liste d'observateur
		**/
		List<IObservateur> obs_

}; //class GestionClavier
/******************************************************************************/

#endif // GESTIONCLAVIER_HPP