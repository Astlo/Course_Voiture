/*
	Fichier GameEngine.cpp


*/
	
#include "GameEngine.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Graphics/GraphicsEngine.hpp"
#include "../State/GameStateManager.hpp"
#include "../Input/InputEngine.hpp"
#include "../Constants.hpp"

using namespace std;

//------------------------------------------------------------------------------
//Constructeur
GameEngine::GameEngine()
{
	ptr_graphicsEngine_ = new GraphicsEngine();
	ptr_gameStateManager_ = new GameStateManager(ptr_graphicsEngine_, ptr_gameData_, ptr_inputEngine_);
}

//------------------------------------------------------------------------------
//Destructeur
GameEngine::~GameEngine()
{
	delete ptr_graphicsEngine_;
	delete ptr_gameStateManager_;
}

void GameEngine::execute()
{
	while(ptr_graphicsEngine_->getRenderWindow()->isOpen())
	{

		// Remplissage de l'écran (couleur noire par défaut)
        ptr_graphicsEngine_->getRenderWindow()->clear();
        //ptr_gameStateManager_->draw();
        // Affichage de la fenêtre à l'écran
        ptr_graphicsEngine_->getRenderWindow()->display();
	}
}

void GameEngine::create()
{
	ptr_inputEngine_->addObs(ptr_gameStateManager_);

	//Max_ia=2

	for (int i = GameData::VOITURE_JOUEUR_IA_0; i <= GameData::VOITURE_JOUEUR_IA_1; ++i) {

		Point *ptr_t[ptr_gameData_->getNbPointsTrajectoiresIA(i - MAX_JOUEUR_IA)];	
		for(int j = 0 ; j<ptr_gameData_->getNbPointsTrajectoiresIA(i - MAX_JOUEUR_IA) ; ++j)
		{
			ptr_t[j] = ptr_gameData_->getUnPointTrajectoireIA(i, j);
		}

		sf::Image image = ptr_graphicsEngine_->getTextureTrajectoireIA()->copyToImage();
		ptr_gameData_->setNbPointsTrajectoiresIA(i - GameData::VOITURE_JOUEUR_IA_0, 
			ptr_gameData_->calculeTrajectoire(image,
				X_BASE_TRAJECTOIRE, 
				Y_BASE_TRAJECTOIRE + (i % 2) * 50 - 25, 
				ptr_t));
	}
}

void GameEngine::render()
{
	ptr_gameStateManager_->update(1);
	ptr_gameStateManager_->draw();
}