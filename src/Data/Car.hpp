/**
 * @file Car.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie une voiture.
**/

#ifndef CAR_HPP
#define CAR_HPP
#pragma once

#include <string> // pour le type std::string
 
#include "../Point.hpp"

/*****************************************************************************/
class Car
{
	public:
	
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur d'une voiture
		 *
		 * @b Complexité O(1)
		**/
		Car();
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur d'une voiture
		 *
		 * @b Complexité O(1)
		**/
		~Car();
		
	//Méthodes

		/** --------------------------------------------------------------------
		 * @brief Réinitialisation à chaque course.
		 *
		 * @b Complexité O(1)
		**/
		virtual void reset();
		
		/** --------------------------------------------------------------------
		 * @brief Affichage de la voiture.
		 * 
		 * @return une chaine de caractère comprenant l'affichage de la voiture
		 * 
		 * @b Complexité O(1)
		**/	
		std::string toString() const;
		
	//Accesseurs
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la position de la voiture.
		 *
		 * @return un point
		 *
		 * @b Complexité O(1)
		**/
		Point& getPoint();
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la position précédente de la voiture.
		 *
		 * @return un Point
		 *
		 * @b Complexité O(1)
		**/
		Point& getOldPoint();
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la vitesse de progression de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getVitesse() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'angle de direction de progression de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getAngle() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur du numéro du tour dans lequel est la voiture.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getTour() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de la lace de la voiture dans la course.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getPlace() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur du numéro du secteur où se trouve la voiture.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getSecteur() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur du numéro du secteur précédent où se trouve la voiture.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getOldSecteur() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur du numéro du secteur le plus élevé atteint par la voiture dans le tour en cours.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getSecteurAtteint() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'accélération de la voiture.
		 *
		 * @return vrai si la voiture accélère, faux sinon
		 *
		 * @b Complexité O(1)
		**/
		bool isAccelere() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur du ralentissement de la voiture.
		 *
		 * @return vrai si la voiture ralenti, faux sinon
		 *
		 * @b Complexité O(1)
		**/
		bool isFreine() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la translation à gauche de la voiture.
		 *
		 * @return vrai si la voiture tourne à gauche, faux sinon
		 *
		 * @b Complexité O(1)
		**/
		bool isLeft() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de la translation à droite de la voiture.
		 *
		 * @return vrai si la voiture tourne à droite, faux sinon
		 *
		 * @b Complexité O(1)
		**/
		bool isRight() const;
		
		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'indicateur de collision.
		 *
		 * @return un entier
		 *
		 * @b Complexité O(1)
		**/
		int getCollision() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'indicateur de fin de course pour la voiture.
		 *
		 * @return vrai si la course est terminée pour la voiture, faux sinon
		 *
		 * @b Complexité O(1)
		**/
		bool isCourseTerminee() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'indicateur de glissade de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getEtatGlissade() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'angle de glissade pour l'animation de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getAngleGlissade() const;

		/** --------------------------------------------------------------------
		 * @brief Accesseur de l'indicateur de saut de la voiture.
		 *
		 * @return un réel
		 *
		 * @b Complexité O(1)
		**/
		double getEtatSaut() const;

	//Mutateurs
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la position de la voiture.
		 *
		 * @param point Point
		 *
		 * @b Complexité O(1)
		**/
		void setPoint(Point point);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la position précédente de la voiture.
		 *
		 * @param oldPoint Point
		 *
		 * @b Complexité O(1)
		**/
		void setOldPoint(Point oldPoint);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la vitesse de progression de la voiture.
		 *
		 * @param vitesse Réel
		 *
		 * @b Complexité O(1)
		**/
		void setVitesse(double vitesse);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'angle de direction de progression de la voiture.
		 *
		 * @param angle Réel
		 *
		 * @b Complexité O(1)
		**/
		void setAngle(double angle);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur du numéro du tour dans lequel est la voiture.
		 *
		 * @param tour Entier
		 *
		 * @b Complexité O(1)
		**/
		void setTour(int tour);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de la place de la voiture dans la course.
		 *
		 * @param place Entier
		 *
		 * @b Complexité O(1)
		**/
		void setPlace(int place);

		/** --------------------------------------------------------------------
		 * @brief Mutateur du numéro du secteur où se trouve la voiture.
		 *
		 * @param secteur Entier
		 *
		 * @b Complexité O(1)
		**/
		void setSecteur(int secteur);

		/** --------------------------------------------------------------------
		 * @brief Mutateur du numéro du secteur précédent où se trouve la voiture.
		 *
		 * @param oldSecteur Entier
		 *
		 * @b Complexité O(1)
		**/
		void setOldSecteur(int oldSecteur);

		/** --------------------------------------------------------------------
		 * @brief Mutateur du numéro du secteur le plus élevé atteint par la voiture dans le tour en cours.
		 *
		 * @param secteurAttein Entier
		 *
		 * @b Complexité O(1)
		**/
		void setSecteurAtteint(int secteurAtteint);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'accélération de la voiture.
		 *
		 * @param accelere Booléen
		 *
		 * @b Complexité O(1)
		**/
		void setAccelere(bool accelere);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur du ralentissement de la voiture.
		 *
		 * @param freine Booléen
		 *
		 * @b Complexité O(1)
		**/
		void setFreine(bool freine);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la translation à gauche de la voiture.
		 *
		 * @param left Booléen
		 *
		 * @b Complexité O(1)
		**/
		void setLeft(bool left);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de la translation à droite de la voiture.
		 *
		 * @param right Booléen
		 *
		 * @b Complexité O(1)
		**/
		void setRight(bool right);
		
		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'indicateur de collision.
		 *
		 * @param collision Entier
		 *
		 * @b Complexité O(1)
		**/
		void setCollision(int collision);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'indicateur de fin de course pour la voiture.
		 *
		 * @param courseTerminee Booléen
		 *
		 * @b Complexité O(1)
		**/
		void setCourseTerminee(bool courseTerminee);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'indicateur de glissade de la voiture.
		 *
		 * @param etatGlissade Réel
		 *
		 * @b Complexité O(1)
		**/
		void setEtatGlissade(double etatGlissade);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'angle de glissade pour l'animation de la voiture.
		 *
		 * @param angleGlissade Réel
		 *
		 * @b Complexité O(1)
		**/
		void setAngleGlissade(double angleGlissade);

		/** --------------------------------------------------------------------
		 * @brief Mutateur de l'indicateur de saut de la voiture.
		 *
		 * @param etatSaut Réel
		 *
		 * @b Complexité O(1)
		**/
		void setEtatSaut(double etatSaut);
		
	private:
	//Attributs
		/**
		 * Position point.
		**/
		Point point_;
		/**
		 * Ancienne position.
		**/
		Point oldPoint_;

		/**
		 * Vitesse de progression.
		**/
		double vitesse_; //speed
		/**
		 * Angle en degrés (direction de progression).
		**/
		double angle_;
		
		/**
		 * Numéro du tour dans lequel est la voiture.
		**/
		int tour_;
		/**
		 * Place de la voiture dans la course.
		**/
		int place_;
		
		/**
		 * Numéro du secteur où se trouve la voiture.
		**/
		int secteur_; //sector
		/**
		 * Numéro du secteur précédent.
		**/
		int oldSecteur_; //oldSector
		/**
		 * Numéro du secteur le plus élevé atteint par la voiture dans le tour en cours.
		**/
		int secteurAtteint_;
		
		/**
		 * La voiture accélère-t-elle ?
		**/
		bool accelere_; //accelerate
		/**
		 * La voiture freine-t-elle ?
		**/
		bool freine_; //brake
		/**
		 * La voiture tourne-t-elle à gauche ?
		**/
		bool left_;
		/**
		 * La voiture tourne-t-elle à droite ?
		**/
		bool right_;
		
		/**
		 * Indicateur de collision.
		**/
		int collision_;
		/**
		 * Indicateur de course terminée pour la voiture.
		**/
		bool courseTerminee_;
		/**
		 * Indicateur de glissade.
		**/
		double etatGlissade_;
		/**
		 * Angle de glissade pour l'animation.
		**/
		double angleGlissade_;
		/**
		 * Indicateur de saut.
		**/
		double etatSaut_;

}; // class Car
/**************************************************************************** */

#endif // CAR_HPP