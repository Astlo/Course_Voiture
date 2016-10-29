/**
 * Fichier EtatDebutCourse.hpp
 *
 * Etat du début de course.
 * (pattern Etat)
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef ETATDEBUTCOURSE_HPP
#define ETATDEBUTCOURSE_HPP
#pragma once

#include <string> // pour le type std::string

/******************************************************************************/


class EtatDebutCourse : public Etat
{
	public:
	//Méthodes d'Etat
		@Override
		void init();

		@Override
		void draw(SpriteBatch spriteBatch);

		@Override
		void update(float deltaTime);
		
		void dispose();
		
	//Autres méthodes
		/**
		 * Affichage d'une voiture.
		 * @param spriteBatch GDX sprite batch
		 * @param n Numéro de la voiture;
		 */
		public void drawVoiture(SpriteBatch spriteBatch, int n);

		@Override
		public void evenementClavier(EvenementClavier evenement);
	
	protected:
	//Constructeur et destructeur
		EtatDebutCourse(GestionnaireEtats gestionnaireEtats);
		~EtatDebutCourse();
	private:
	//Attributs
		/**
		 * Indicateur de décompte pour le départ.
		**/
		float decompte;
		
}; // class EtatDebutCourse
/******************************************************************************/

#endif // ETATDEBUTCOURSE_HPP

