/**
 * @file GameState.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Classe abstraite d'état de jeu.
 * @b (Pattern State)
 * @b (Pattern Observer)
**/

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#pragma once

#include <string> // pour le type std::string

#include <SFML/Graphics.hpp>

#include "../Input/IKeyObserver.hpp"

class GameStateManager;

/******************************************************************************/
class GameState : public IKeyObserver
{
	public:
		
	//Méthodes
		/** --------------------------------------------------------------------
		 * @brief Initialisation de l'état.
		 *
		 * @b Complexité O()
		**/
		virtual void init() =0;

		/** --------------------------------------------------------------------
		 * @brief Affichage de l'état.
		 *
		 * @param spriteBatch GDX sprite batch 
		 *
		 * @b Complexité O()
		**/
		virtual void draw() =0; //Doit être autre chose pour notre bibliothèque

		/** --------------------------------------------------------------------
		 * @brief Mise à jour de l'état du jeu.
		 *
		 * @param deltaTime Réel
		 *
		 * @b Complexité O()
		**/
		virtual void update(double deltaTime) =0; //float deltaTime

	//Accesseur
		/** --------------------------------------------------------------------
		 * @brief Accesseur du gameStateManager (client du pattern State)
		 *
		 * @b Complexité O()
		**/
		GameStateManager* getGameStateManager();
		
	protected:
	
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur
		 *
		 * @param gameStateManager GameStateManager (client du pattern State)
		 *
		 * @b Complexité O()
		**/
		GameState(GameStateManager *ptr_gameStateManager);
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur.
		 *
		 * @b Complexité O()
		**/
		~GameState();
		
	private:
	
	//Attributs
		/**
		 * Gestionnaire d'état du jeu.
		**/
		GameStateManager *ptr_gameStateManager_;
		
}; //class GameState
/******************************************************************************/

#endif // GAMESTATE_HPP