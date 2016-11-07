/**
 * @file GameStateManager.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Gestionnaire des états du jeu.
 * @b (pattern State)
 * @b (pattern Observer)
**/

#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP
#pragma once

#include <string> // pour le type std::string

#include <SFML/Graphics.hpp>


#include "GameState.hpp"
#include "../Graphics/GraphicsEngine.hpp"
#include "../Data/GameData.hpp"
#include "../Input/IKeyObserver.hpp"
#include "../Input/IKeySubject.hpp"

/******************************************************************************/
class GameStateManager : public IKeyObserver
{
	public:
		
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Accesseur du gameStateManager (client du pattern State)
		 *
		 * @param graphicsEngine Le moteur graphique
		 * @param gameData Les données du jeu
		 *
		 * @b Complexité O()
		**/
		GameStateManager(GraphicsEngine *ptr_graphicsEngine, GameData *ptr_gameData, /*GameState *ptr_menuState,*/ IKeySubject *ptr_subject);
		
		~GameStateManager();
	//Méthodes
		void update(double deltaTime);

		void draw();

		void dispose();

		void keyboardEvent(KeyboardEvent *ptr_event); // actualiser(donee)
	
	//Accesseurs et mutateur
		
		GameState* getGameState();

		GameData* getGameData();
		
		GraphicsEngine* getGraphicsEngine();
	
		/**
		 * Nouvel état.
		 * @param state Indice du nouvel état.
		 */
		void setState(int state);


		void setMenuState();
		
		void setRaceState();
		
		void setStartRaceState();
		
		void setEndRaceState();

		void keyEvent(KeyboardEvent *ptr_event);
	
	private:
		/**
		 * Les données du jeu.
		**/
		GameData *ptr_gameData_;
		/**
		 * Moteur graphique.
		**/
		GraphicsEngine *ptr_graphicsEngine_;
		
		IKeySubject *ptr_subject_;
		/**
		 * Etat courant.
		**/
		GameState *ptr_gameState_;
		/**
		 * Etat menu.
		**/
		GameState *ptr_menuState_;
		/**
		 * Etat course.
		**/
		GameState *ptr_raceState_;
		/**
		 * Etat debut de course.
		**/
		GameState *ptr_startRaceState_;
		/**
		 * Etat fin de course.
		**/
		GameState *ptr_endRaceState_;

}; //class GameStateManager
/******************************************************************************/

#endif // GAMESTATEMANAGER_HPP