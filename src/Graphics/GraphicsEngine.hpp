/*
	Fichier GraphicsEngine.cpp


*/
#include "GraphicsEngine.hpp"

using namespace std;

const int GraphicsEngine::VOITURE_ROUGE = 0;
const int GraphicsEngine::VOITURE_BLEUE = 1;
const int GraphicsEngine::VOITURE_JAUNE = 2;
const int GraphicsEngine::VOITURE_VIOLETTE = 3;


//------------------------------------------------------------------------------
//Constructeur
GraphicsEngine::GraphicsEngine()
{
	RenderWindow window(VideoMode(1366,768), "SFML works!", Style::Fullscreen);
	/*vector<VideoMode> VideoModesCount = VideoMode::getFullscreenModes();
   for (unsigned int i = 0; i < VideoModesCount.size(); ++i)
   {
	   VideoMode Mode = VideoModesCount[i];
	   // Mode is a valid video mode
	   cout << "Mode " << Mode.width << "-" << Mode.height << "-" << Mode.bitsPerPixel << " is valid" << endl;
   }*/

	Sprite sprite;
	Image image;
	image.loadFromFile("img/chat.jpg" );
	if(!texture.loadFromImage(image))
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		return EXIT_FAILURE; // On ferme le programme
	}


	textureCircuit_.loadFromImage("images/Circuit.png"));

	texturesVoitures_[VOITURE_ROUGE].loadFromImage("images/VoitureRouge.png"));
	texturesVoitures_[VOITURE_BLEUE].loadFromImage("images/VoitureBleue.png"));
	texturesVoitures_[VOITURE_JAUNE].loadFromImage("images/VoitureJaune.png"));
	texturesVoitures_[VOITURE_VIOLETTE].loadFromImage("images/VoitureViolette.png"));

	textureMenu_.loadFromImage("images/Menu.png"));

	this.spritesVoitures = new Sprite[GameModel::MAX_VOITURES];
	for (int i = 0; i < GameModel::MAX_VOITURES; i++) {
		spritesVoitures_[i].setTexture(texturesVoitures_[i]);
		//this.spritesVoitures[i].setOrigin(Constants.VOITURE_WIDTH / 2, Constants.VOITURE_HEIGHT / 2);
	}
}

//------------------------------------------------------------------------------
//Destructeur
GraphicsEngine::~GraphicsEngine()
{
	delete graphicsEngine_;
	delete gameStateManager_;
}

void GraphicsEngine::execute()
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
void GraphicsEngine::drawSprite(Texture texture, Sprite sprite, double x, double y, double scaleX, double scaleY, double angle)
{
	sprite.setTexture(texture);
	sprite.setPosition((float) x, (float) y);
	sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
	sprite.setScale((float) scaleX, (float) scaleY)
	sprite.setRotation((float)angle);
	window.draw(sprite);
}

/**
 * Récupère la couleur d'un pixel dans une map de pixels.
 * @param pixmap Map de pixels.
 * @param x Position x (origine à gauche de l'écran).
 * @param y Position y (origine en bas de l'écran).
 * @return Couleur RGB
 */
Color GraphicsEngine::getPixelColorFromPixmap(Texture texture, int x, int y) {
	Color color = new Color();
	return texture.copyToImage().getPixel(x,y)	return color;
}



/**
 * Libération des ressources graphiques.
 */
void GraphicsEngine::dispose() {
	textureMenu_.~Texture();
	textureCircuit_.~Texture();
	for (int i = 0; i < GameModel.MAX_VOITURES; i++) {
		texturesVoitures[i]_.~Texture();
	}
}

Texture GraphicsEngine::getTextureMenu() {
	return textureMenu;
}

Texture GraphicsEngine::getTextureCircuit() {
	return textureCircuit;
}

Texture[] GraphicsEngine::getTexturesVoitures() {
	return texturesVoitures;
}

Sprite[] GraphicsEngine::getSpritesVoitures() {
	return spritesVoitures;
}