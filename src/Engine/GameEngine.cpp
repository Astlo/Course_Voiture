/*
	Fichier GameEngine.cpp


*/
#include "GameEngine.hpp"

using namespace std;

//------------------------------------------------------------------------------
//Constructeur
GameEngine::GameEngine()
{
	graphicsEngine_ = new GraphicsEngine();
	gameStateManager_ = new GameStateManager();
}

//------------------------------------------------------------------------------
//Destructeur
GameEngine::~GameEngine()
{
	delete graphicsEngine_;
	delete gameStateManager_;
}

void GameEngine::execute()
{
	while(window.isOpen())
	{

		// Remplissage de l'écran (couleur noire par défaut)
        window.clear();
        gameStateManager_.affichage();
        // Affichage de la fenêtre à l'écran
        window.display();
	}
}
