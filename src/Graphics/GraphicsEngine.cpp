/* 
	Fichier GraphicsEngine.hpp
	
	   
*/


#ifndef GRAPHICSENGINE_HPP
#define GRAPHICSENGINE_HPP
#pragma once

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

		void drawSprite(Texture texture, Sprite sprite, double x, double y, double scaleX, double scaleY, double angle);
		Texture getTextureMenu();
		Texture[] getTexturesVoitures();
		Sprite[] getSpritesVoitures();



	private:
		RenderWindow window;
		/** Tableau des textures des voitures. */
		Texture texturesVoitures_[GameModel::MAX_VOITURES];
		/** Tableau des sprites des voitures. */
		Sprite spritesVoitures_[GameModel::MAX_VOITURES];
		/** Texture du menu. */
		const Texture textureMenu;
		/** Texture du circuit. */
		const Texture textureCircuit;


}; // class GraphicsEngine
/**************************************************************************** */

#endif // GRAPHICSENGINE_HPP
