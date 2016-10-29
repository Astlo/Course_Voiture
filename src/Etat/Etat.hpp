/**
 * Fichier Etat.hpp
 * Classe abstraite d'état de jeu
 * (pattern Etat)
 * (pattern observer)
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef GESTIONNAIREETATS_HPP
#define GESTIONNAIREETATS_HPP
#pragma once

#include <string> // pour le type std::string

class Etat : public IObserver
{
	public:
	//Constructeur et destructeur
		Etat(GestionnaireEtats gestionnaireEtats);
		~Etat();
	
	//Accesseur
		GestionnaireEtats getGestionnaireEtats();
	
	//Autres méthodes
		/**
		 * Initialisation de l'état.
		 */
		virtual void init() = 0;

		/**
		 * Affichage de l'état.
		 * @param spriteBatch GDX sprite batch
		 */
		virtual void draw(SpriteBatch spriteBatch);

		/**
		 * Mise à jour de l'état du jeu.
		 * @param deltaTime
		 */
		virtual void update(float deltaTime);

		/**
		 * Libération des ressources créés par l'état.
		 */
		virtual void dispose();
	
	private:
	//Attributs
		/**
		 * Gestionnaire d'état du jeu.
		**/
		private GestionnaireEtats gestionnaireEtats;

}; // class Etat
/******************************************************************************/

#endif // ETAT_HPP