/**
 * Fichier GestionnaireEtats
 *
 * Gestionnaire des états du jeu.
 * (pattern Etat)
 * @author LE BARS Yannis & HUNAULT Marion
**/

#ifndef GESTIONNAIREETATS_HPP
#define GESTIONNAIREETATS_HPP
#pragma once

#include <string> // pour le type std::string


/******************************************************************************/
class GameStateManager : public IObservateur
{
	public:
	//Constantes
		/**
		 * Indice de l'état menu.
		**/
		static const int STATE_MENU = 0;
		/**
		 * Indice de l'état début de course.
		**/
		static const int STATE_START_RACE = 1;
		/**
		 * Indice de l'état course.
		**/
		static const int STATE_RACE = 2;
		/**
		 * Indice de l'état fin de course.
		**/
		static const int STATE_END_RACE = 3;
	//Construteur et destructeur
		GestionnaireEtats(GraphicsEngine graphicsEngine, GameModel gameModel);
		~GestionnaireEtats();
	//Accesseurs et mutateurs
		public GameState getGameState();
		public GameModel getGameModel();
		public GraphicsEngine getGraphicsEngine();

		/**
		 * Nouvel état.
		 * @param state Indice du nouvel état.
		 */
		void setState(int state);
	//Autres méthodes
		void update(float deltaTime);

		void draw(SpriteBatch spriteBatch);

		void dispose();

		@Override
		public void evenementClavier(EvenementClavier evenement);
	
	private:
	//Attributs
		/** Modèle. */
		private final GameModel gameModel;
		/** Moteur graphique. */
		private final GraphicsEngine graphicsEngine;
		/** Etat courant. */
		private GameState gameState;

}; // class GestionnaireEtats
/******************************************************************************/

#endif // GESTIONNAIREETATS_HPP
