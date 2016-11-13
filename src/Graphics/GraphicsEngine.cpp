/*
	Fichier GraphicsEngine.cpp


*/

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "GraphicsEngine.hpp"

#include <cstdlib>
#include <iostream>
#include <cmath>

//#include "../Constants.hpp"

using namespace std;

const int GraphicsEngine::VOITURE_ROUGE = 0;
const int GraphicsEngine::VOITURE_BLEUE = 1;
const int GraphicsEngine::VOITURE_JAUNE = 2;
const int GraphicsEngine::VOITURE_VIOLETTE = 3;

int GraphicsEngine::ECRAN_LARGEUR;
int GraphicsEngine::ECRAN_HAUTEUR;

// Conserver les dimensions des voitures.

int GraphicsEngine::VOITURE_LARGEUR;
int GraphicsEngine::VOITURE_HAUTEUR;

int GraphicsEngine::DISTANCE_COLLISION;


//------------------------------------------------------------------------------
//Constructeur
GraphicsEngine::GraphicsEngine()
{
	vector<sf::VideoMode> VideoModesCount = sf::VideoMode::getFullscreenModes();

	// Conserver les dimensions de la zone d'affichage.


	// Calculer la distance de collision entre 2 voitures : moitié de l'hypothénuse du demi-rectangle d'une voiture.
	
	ptr_window_ = new sf::RenderWindow(sf::VideoMode(VideoModesCount[0].width,VideoModesCount[0].height), "Jeu!", sf::Style::Fullscreen);
	ECRAN_LARGEUR = VideoModesCount[0].width;
	ECRAN_HAUTEUR = VideoModesCount[0].height;
	//ptr_window_->setVerticalSyncEnabled(true);
	ptr_window_->setFramerateLimit(60);

	ptr_textureCircuit_ = new sf::Texture();
	if(!ptr_textureCircuit_->loadFromFile("img/course_Circuit.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}
	

	ptr_texturesCars_[VOITURE_ROUGE] = new sf::Texture();
	ptr_texturesCars_[VOITURE_BLEUE] = new sf::Texture();
	ptr_texturesCars_[VOITURE_JAUNE] = new sf::Texture();
	ptr_texturesCars_[VOITURE_VIOLETTE] = new sf::Texture();
	if(!ptr_texturesCars_[VOITURE_ROUGE]->loadFromFile("img/Car_1.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}
	if(!ptr_texturesCars_[VOITURE_BLEUE]->loadFromFile("img/Car_2.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}
	if(!ptr_texturesCars_[VOITURE_JAUNE]->loadFromFile("img/Car_3.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}
	if(!ptr_texturesCars_[VOITURE_VIOLETTE]->loadFromFile("img/Car_4.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}

	VOITURE_LARGEUR = ptr_texturesCars_[VOITURE_ROUGE]->getSize().x;
	VOITURE_HAUTEUR = ptr_texturesCars_[VOITURE_ROUGE]->getSize().y;
	DISTANCE_COLLISION = (unsigned) sqrt(VOITURE_HAUTEUR*VOITURE_HAUTEUR+ VOITURE_LARGEUR*VOITURE_LARGEUR) / 2;

	ptr_textureMenu_ = new sf::Texture();
	if(!ptr_textureMenu_->loadFromFile("img/Menu.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}


	for (int i = 0; i < MAX_VOITURES; ++i) {
		ptr_spritesCars_[i] = new sf::Sprite();
		ptr_spritesCars_[i]->setTexture(*ptr_texturesCars_[i]);
	}

	ptr_textureObstacles_ = new sf::Texture();
	if(!ptr_textureObstacles_->loadFromFile("img/course_Obstacles.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}

	ptr_textureTrajectoireIA_ = new sf::Texture();
	if(!ptr_textureTrajectoireIA_->loadFromFile("img/course_Trajectoire.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}

	ptr_textureSecteurs_ = new sf::Texture();
	if(!ptr_textureSecteurs_->loadFromFile("img/course_Secteurs.png"))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}

	if (!font_.loadFromFile("arial.ttf"))
	{
		cout<<"Erreur durant le chargement de la police"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}
}

//------------------------------------------------------------------------------
//Destructeur
GraphicsEngine::~GraphicsEngine()
{
	for (int i = 0; i < MAX_VOITURES; ++i) {
		delete ptr_spritesCars_[i];
		delete ptr_texturesCars_[i];
	}	
	delete ptr_textureMenu_;
	delete ptr_textureCircuit_;
	delete ptr_textureObstacles_;
	delete ptr_window_;
}


/**
 * Afficher un sprite
 * @param texture Texture à afficher.
 * @param sprite Sprite à afficher.
 * @param x Position x (origine à gauche de l'écran).
 * @param y Position y (origine en bas de l'écran).
 * @param scaleX Echélle de zoom sur X (1 = pas de zoom).
 * @param scaleY Echélle de zoom sur Y (1 = pas de zoom).
 * @param angle Angle de rotation de 0 (horizontal vers droite) à 360.
 */
void GraphicsEngine::drawSprite(sf::Texture *ptr_texture, sf::Sprite *ptr_sprites, double x, double y, double scaleX, double scaleY, double angle)
{
	ptr_sprites->setTexture(*ptr_texture);
	ptr_sprites->setOrigin(ptr_sprites->getLocalBounds().width/2,ptr_sprites->getLocalBounds().height/2);
	ptr_sprites->setPosition((float) x, (float) y);
	ptr_sprites->setScale((float) scaleX, (float) scaleY);
	ptr_sprites->setRotation((float)angle);
	ptr_window_->draw(*ptr_sprites);
}

/**
 * Récupère la couleur d'un pixel dans une map de pixels.
 * @param pixmap Map de pixels.
 * @param x Position x (origine à gauche de l'écran).
 * @param y Position y (origine en haut de l'écran).
 * @return Couleur RGB
 */
sf::Color GraphicsEngine::getPixelColorFromTexture(sf::Texture *ptr_texture, int x, int y)
{
	return ptr_texture->copyToImage().getPixel(x,y);
}

sf::Texture* GraphicsEngine::getTextureMenu() 
{
	return ptr_textureMenu_;
}

sf::Texture* GraphicsEngine::getTextureCircuit() 
{
	return ptr_textureCircuit_;
}

sf::Texture* GraphicsEngine::getTextureObstacles()
{
	return ptr_textureObstacles_;
}

sf::Texture* GraphicsEngine::getTextureTrajectoireIA()
{
	return ptr_textureTrajectoireIA_;
}

sf::Texture* GraphicsEngine::getTextureSecteurs()
{
	return ptr_textureSecteurs_;
}

sf::Texture* GraphicsEngine::getOneTextureCar(unsigned indice) 
{
	return ptr_texturesCars_[indice];
}

sf::Sprite* GraphicsEngine::getOneSpriteCar(unsigned indice) 
{
	return ptr_spritesCars_[indice];
}

sf::Font& GraphicsEngine::getFont()
{
	return font_;
}

sf::RenderWindow* GraphicsEngine::getRenderWindow()
{
	return ptr_window_;
}