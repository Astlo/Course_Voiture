/**
 * Fichier EtaTCourse.hpp
 *
 * Etat course.
 * (pattern Etat)
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef ETATCOURSE_HPP
#define ETATCOURSE_HPP
#pragma once

#include <string> // pour le type std::string

/******************************************************************************/
class EtatCourse : public Etat
{
	public:
	//Méthodes d'Etat
		@Override
		public void init();

		@Override
		public void draw(SpriteBatch spriteBatch);

		@Override
		public void update(float deltaTime);

		@Override
		public void dispose();
		
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
		EtatCourse(GestionnaireEtats gestionnaireEtats);
		~EtatCourse();	
	
	private:
	
	//Attributs
		/**
		 * Contrôleur de voiture principal.
		**/
		IPilote pilote;
		/**
		 * Contrôleur de voiture IA type 1.
		**/
		IPilote iaPilote1;
		/**
		 * Contrôleur de voiture IA type 2.
		**/
		IPilote iaPilote2;
		
	//Autres méthodes
		/**
		 * Gestion des collisions
		 */
		void testCollisions();

		/**
		 * Gestion des obstacles.
		 */
		void testObstacles();

		/**
		 * Gestion fin de course.
		 */
		void testVainqueur();
		
}; // class EtatCourse
/******************************************************************************/

#endif // ETATCOURSE_HPP
