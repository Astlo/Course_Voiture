 /**
 * Fichier EtaTMenu.hpp
 *
 * Etat menu.
 * (pattern Etat)
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef ETATMENU_HPP
#define ETATMENU_HPP
#pragma once

#include <string> // pour le type std::string


/******************************************************************************/
class EtatMenu : public Etat
{
	public:
	//Constructeur et destructeur
		MenuState(GameStateManager gameStateManager);
		~MenuState();
		
	//Autres méthodes
		@Override
		public void init();

		@Override
		public void draw(SpriteBatch spriteBatch);

		@Override
		public void update(float deltaTime);

		@Override
		public void dispose();

		@Override
		public void evenementClavier(EvenementClavier evenement);
		
	private:
	//Attributs
		/**
		 * Pour l'animation du menu (position d'affichage des voitures à la queue leu leu).
		**/
		int p;


}; // class EtatMenu
/******************************************************************************/

#endif // ETATMENU_HPP
