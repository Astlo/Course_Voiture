/* 
* Fichier Trajectoire.hpp 
*
* Détermnine une trajectoire par sa couleur, une liste de points dont le point de début et le point de fin.
* @author LE BARS Yannis & HUNAULT Marion
*	
*/

#ifndef TRAJECTOIRE_HPP
#define TRAJECTOIRE_HPP
#pragma once

/*****************************************************************************/
class Trajectoire
{
	private:
		/**
		 * Liste de points formant la trajectoire
		 */
		list<Point> trajet_;
		/**
		 * La couleur de la trajectoire
		 */
		Color couleur_ (utile ?);
	
	public:
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'une trajectoire
		 *
		 * @param trajet List<Point> : une liste de point qui constitue le trajet
		 * @param couleur Color : la couleur du trajet
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		 */
		Trajectoire(list<Point> trajet, Color couleur);
	
		/** --------------------------------------------------------------------
		 * @brief Destructeur d'une trajectoire
		 *
		 * @b Complexité O(1)
		 */
		~Trajectoire();
	
		/** --------------------------------------------------------------------
		 * @brief Accesseur du premier point de la liste
		 *
		 * @return le premier point de la liste
		 * 
		 * @b Complexité O(1)
		 */
		Point getDebut () const;
		/** --------------------------------------------------------------------
		 * @brief Accesseur du dernier point de la liste
		 *
		 * @return le dernier point de la liste
		 *
		 * @b Complexité O(1)
		 */
		Point getFin () const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de la trajectoire
		 *
		 * @return la trajectoire
		 *
		 * @b Complexité O(1)
		 */
		list<Point> getTrajet () const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur du point au rang i de la liste
		 *
		 * @param i Le ième rang
		 *
		 * @return point au rang i de la liste
		 *
		 * @b Complexité O(1)
		 */
		Point getPointTrajet (int i) const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de la couleur
		 *
		 * @return la couleur
		 *
		 * @b Complexité O(1)
		 */
		Color getCouleur () const;

		/** --------------------------------------------------------------------
		 * @brief Mutateur du premier point de la liste
		 *
		 * @param p point remplacant
		 *
		 * @b Complexité O(1)
		 */
		void setDebut (Point p);

		/** --------------------------------------------------------------------
		 * @brief Mutateur du dernier point de la liste
		 *
		 * @param p point remplacant
		 *
		 * @b Complexité O(1)
		 */
		void setFin (Point p);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de la liste
		 *
		 * @param trajet liste remplacante
		 *
		 * @b Complexité O(1)
		 */
		void setTrajet (List<Point> trajet);

		/** --------------------------------------------------------------------
		 * @brief Mutateur du premier point de la liste
		 *
		 * @param p point remplacant
		 *
		 * @b Complexité O(1)
		 */
		void setPointTrajet (Point p, int indice);


		/** --------------------------------------------------------------------
		 * @brief Mutateur de la couleur
		 *
		 * @param couleur couleur remplacante
		 *
		 * @b Complexité O(1)
		 */
		void setCouleur (Color couleur);
	
	//Autres méthodes
		/**
		 * @brief Ajoute un point dans la liste
		 *
		 * @param p Un point
		 *
		 * @b Complexité O(1)
		 */
		void ajouterPoint (Point p);

		/**
		 * @brief Supprimer un point dans la liste
		 *
		 * @param p Un point
		 *
		 * @b Complexité O(1)
		 */
		void supprimerPoint (Point p);

		/**
		 * @brief Compte le nombre de points dans la liste
		 *
		 * @return le nombre de points
		 *
		 * @b Complexité O(1)
		 */
		unsigned nbPoint ();
		/*
		* + toutes les fonctions correspondant à la liste comme :
		* ajouterPoint (Point p)
		* supprimerPoint (Point p)
		* nbPoint () ou tailleListe ()
		*/
		void calculeTrajectoire (image masqueTrajectoire);
		bool estDejaDansTrajectoire (Point p);
}; //class Trajectoire

/******************************************************************************/
#include "Trajectoire.cpp"

#endif // TRAJECTOIRE_HPP