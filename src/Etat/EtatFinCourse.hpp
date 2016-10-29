/**
 * Fichier EtatFinCourse.hpp
 *
 * Etat de fin de course.
 * Hérite de l'affichage de l'état course et le stabilise. // plus vraiment le cas
 * (pattern Etat)
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef ETATFINCOURSE_HPP
#define ETATFINCOURSE_HPP
#pragma once

#include <string> // pour le type std::string

/******************************************************************************/
class EtatFinCourse : public Etat
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
		@Override
		public void evenementClavier(EvenementClavier evenement);
	
	protected:
	//Constructeur et destructeur
		EtatFinCourse(GestionnaireEtats gestionnaireEtats);
		~EtatFinCourse();
		
}; // class EtatFinCourse
/******************************************************************************/

#endif // ETATFINCOURSE_HPP