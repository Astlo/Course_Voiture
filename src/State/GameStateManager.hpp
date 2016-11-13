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

#include "../Input/IKeyObserver.hpp"

class GraphicsEngine;
class GameState;
class GameData;
class IKeySubject;
/*
#include "GameState.hpp"
#include "../Graphics/GraphicsEngine.hpp"
#include "../Data/GameData.hpp"
#include "../Input/IKeySubject.hpp"*/

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
		void update(int deltaTime);

		void draw();

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

	private:
		/**
		 * Moteur graphique.
		**/
		GraphicsEngine *ptr_graphicsEngine_;
		/**
		 * Les données du jeu.
		**/
		GameData *ptr_gameData_;
		
		IKeySubject *ptr_subject_;
		/**
		 * Etat menu.
		**/
		GameState* ptr_menuState_;
		/**
		 * Etat course.
		**/
		GameState* ptr_raceState_;	
		/**
		 * Etat debut de course.
		**/
		GameState* ptr_startRaceState_;
		/**
		 * Etat fin de course.
		**/
		GameState* ptr_endRaceState_;
		/**
		 * Etat courant.
		**/
		GameState *ptr_gameState_;	

}; //class GameStateManager
/******************************************************************************/

#endif // GAMESTATEMANAGER_HPP