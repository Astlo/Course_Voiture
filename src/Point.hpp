/**
 * @file Point.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie un point par son abscisse et son ordonnée.
**/

#ifndef POINT_HPP
#define POINT_HPP
#pragma once

#include <string> // pour le type std::string

/*****************************************************************************/
class Point
{
	public:
	
	//Constructeurs et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur par défaut.
		 *
		 * @b Complexité O(1)
	     */
		Point();
		
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'un point.
		 * 
	     * @param x Entier
	     * @param y Entier
		 *
		 * @pre x > 0 et y > 0
		 *
		 * @b Complexité O(1)
	     */
		Point(unsigned x, unsigned y);

		/** --------------------------------------------------------------------
		 * @brief Destructeur d'un point
		 *
		 * @b Complexité O(1)
		 */
		~Point();
		
	//Méthodes
		/** --------------------------------------------------------------------
		 * @brief Renvoie la distance entre deux points this et autre
		 * 
		 * @param autre Point
		 * 
		 * @return la distance entre this et autre
		 * 
		 * @post distance > 0
		 * 
		 * @b Complexité O(1)
		**/
		double distancePoint(const Point & autre);
		
		/** --------------------------------------------------------------------
		 * @brief Déplace un point de dx en abscisse et dy en ordonnée
		 * 
		 * @param dx Entier
		 * @param dy Entier
		 * 
		 * @pre dx > 0 et dy > 0
		 * @post distance > 0
		 * 
		 * @b Complexité O(1)
		**/
		void deplacer(unsigned dx, unsigned dy);
		
		/** --------------------------------------------------------------------
		 * @brief Renvoie la distance entre deux points this et autre
		 * 
		 * @param autre Point
		 * 
		 * @return la distance entre this et autre
		 * 
		 * @post distance > 0
		 * 
		 * @b Complexité O(1)
		**/		
		bool equals(const Point & autre) const;
		
		/** --------------------------------------------------------------------
		 * @brief Affichage du point
		 * 
		 * @return une chaine de caractère comprenant l'affichage du point
		 * 
		 * @b Complexité O(1)
		**/		
		std::string toString() const;

	//Accesseurs et Mutateurs
		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'abscisse du point
		 *
		 * @return la valeur de x_
		 *
		 * @b Complexité O(1)
		 */
		unsigned getX() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'ordonnée du point
		 *
		 * @return la valeur de y_
		 *
		 * @b Complexité O(1)
		 */
		unsigned getY() const;
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'abscisse du point
		 *
		 * @param x Entier
		 *
		 * @pre x > 0
		 *
		 * @b Complexité O(1)
		 */
		void setX(unsigned x);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'ordonnée du point
		 *
		 * @param y Entier
		 *
		 * @pre y > 0
		 *
		 * @b Complexité O(1)
		 */
		void setY(unsigned y);
		
	private:
	
	// Attributs
		/**
		 * L'abscisse du point
		**/
		unsigned x_;
		/**
		 * L'ordonnée du point
		**/
		unsigned y_;

}; // class Point
/**************************************************************************** */

#endif // POINT_HPP