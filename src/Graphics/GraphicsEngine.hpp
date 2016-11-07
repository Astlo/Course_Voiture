/* 
	Fichier GraphicsEngine.hpp
	
	   
*/


#ifndef GRAPHICSENGINE_HPP
#define GRAPHICSENGINE_HPP
#pragma once

#include <SFML/Graphics.hpp>
	
#include "../Constants.hpp"

/**************************************************************************** */
class GraphicsEngine
{
	public:
		/** Indice voiture rouge. */
		static const int VOITURE_ROUGE;
		/** Indice voiture bleue. */
		static const int VOITURE_BLEUE;
		/** Indice voiture jaune. */
		static const int VOITURE_JAUNE;
		/** Indice voiture violette. */
		static const int VOITURE_VIOLETTE;

		GraphicsEngine();
		~GraphicsEngine();

		void drawSprite(sf::Texture *ptr_texture, sf::Sprite *ptr_sprite, double x, double y, double scaleX, double scaleY, double angle);
		sf::Color getPixelColorFromTexture(sf::Texture *ptr_texture, int x, int y);
		sf::Texture* getTextureMenu();
		sf::Texture* getTextureCircuit();
		sf::Texture* getTextureObstacles();
		sf::Texture* getTextureTrajectoireIA();
		sf::Texture* getTextureBord();
		sf::Texture* getOneTextureCar(unsigned indice);
		sf::Sprite* getOneSpriteCar(unsigned indice);

		sf::Font getFont();

		sf::RenderWindow* getRenderWindow();

	private:
		sf::RenderWindow *ptr_window_;
		/** Tableau des textures des voitures. */
		sf::Texture *ptr_texturesCars_[MAX_VOITURES];
		/** Tableau des sprites des voitures. */
		sf::Sprite *ptr_spritesCars_[MAX_VOITURES];
		/** Texture du menu. */
		sf::Texture *ptr_textureMenu_;
		/** Texture du circuit. */
		sf::Texture *ptr_textureCircuit_;
		/** Map de pixels du masque des obstacles. */
		sf::Texture *ptr_textureObstacles_;
		/** Map de pixels des trajectoires IA. */
		sf::Texture *ptr_textureTrajectoireIA_;

		sf::Texture *ptr_textureBord_;

		sf::Font font_;


}; // class GraphicsEngine
/**************************************************************************** */

#endif // GRAPHICSENGINE_HPP
