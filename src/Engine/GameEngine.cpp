/*
	Fichier GameEngine.cpp


*/
	
#include "GameEngine.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Graphics/GraphicsEngine.hpp"
#include "../State/GameStateManager.hpp"
#include "../Data/GameData.hpp"
#include "../Input/InputEngine.hpp"

using namespace std;

//------------------------------------------------------------------------------
//Constructeur
GameEngine::GameEngine()
{

	ptr_graphicsEngine_ = new GraphicsEngine();
	ptr_gameData_ = new GameData();
	ptr_inputEngine_ = new InputEngine();
	ptr_gameStateManager_ = new GameStateManager(ptr_graphicsEngine_, ptr_gameData_, ptr_inputEngine_);
}

//------------------------------------------------------------------------------
//Destructeur
GameEngine::~GameEngine()
{
	delete ptr_graphicsEngine_;
	delete ptr_gameStateManager_;
	delete ptr_inputEngine_;
	delete ptr_gameData_;
}

void GameEngine::create()
{
	ptr_inputEngine_->addObs(ptr_gameStateManager_);
	for (int i = GameData::VOITURE_JOUEUR_IA_0; i <= GameData::VOITURE_JOUEUR_IA_1; ++i) 
	{
		Point* ptr_t[MAX_TRAJECTOIRE];
		for(int j = 0; j<MAX_TRAJECTOIRE; ++j)
		{
			ptr_t[j] = ptr_gameData_->getUnPointTrajectoireIA(i- MAX_JOUEUR_IA, j);
		}
		sf::Image image = ptr_graphicsEngine_->getTextureTrajectoireIA()->copyToImage();
		ptr_gameData_->setNbPointsTrajectoiresIA(i - GameData::VOITURE_JOUEUR_IA_0, ptr_gameData_->calculeTrajectoire(image, X_BASE_TRAJECTOIRE, Y_BASE_TRAJECTOIRE + (i % 2) * 53, ptr_t));
		for(int j = 0; j<ptr_gameData_->getNbPointsTrajectoiresIA(i - GameData::VOITURE_JOUEUR_IA_0); ++j)
		{
			ptr_gameData_->setUnPointTrajectoireIA(i - GameData::VOITURE_JOUEUR_IA_0, j, *ptr_t[j]);
		}
	}
}

void GameEngine::execute()
{	
	while(ptr_graphicsEngine_->getRenderWindow()->isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		KeyboardEvent* kbEvent = new KeyboardEvent(event.type, event.key.code);
		
		while (ptr_graphicsEngine_->getRenderWindow()->pollEvent(event))
		{
			ptr_inputEngine_->notifyObs(kbEvent);
			//ptr_gameStateManager_->keyboardEvent(kbEvent);
		}
		// Remplissage de l'écran (couleur noire par défaut)
		ptr_graphicsEngine_->getRenderWindow()->clear();
		render();
		// Affichage de la fenêtre à l'écran
		ptr_graphicsEngine_->getRenderWindow()->display();

		delete kbEvent;
	}
}

void GameEngine::render()
{
	ptr_gameStateManager_->draw();
	ptr_gameStateManager_->update(1);
}