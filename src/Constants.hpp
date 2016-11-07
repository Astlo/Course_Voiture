/**
 * @file Constants.hpp
 * @author HUNAULT Marion & LE BARS Yannis
 * @brief Identifie les constantes utilisées par le programme.
**/

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#pragma once

#include <SFML/Window.hpp>

/*****************************************************************************/

/**
 * Coordonnées de base de la trajectoire idéale.
**/
const int X_BASE_TRAJECTOIRE = 500;
const int Y_BASE_TRAJECTOIRE = 128;

/**
 * Hauteur et largeur de l'espace graphique (initialisées par le moteur graphique)
**/
int ECRAN_LARGEUR;
int ECRAN_HAUTEUR;

/**
 * Hauteur et largeur des voitures (initialisées par le moteur graphique)
**/
int VOITURE_LARGEUR;
int VOITURE_HAUTEUR;

/**
 * Distance entre les voitures à partir de laquelle il y a collision.
**/
int DISTANCE_COLLISION;

/**
 * Délai pendant lequel la collision n'est plus testée pour permettre de se dégager.
**/
const int DELAI_COLLISION = 5;

/**
 * Vitesses
**/
const int VITESSE_AVANT_MAXI = 6;
const int VITESSE_ARRIERE_MAXI = 2;
const int VITESSE_HORS_PISTE = 1;

/**
 * Accélération.
**/
const double DELTA_VITESSE = 0.1;

/**
 * Augmentation d'angle en fonction de la vitesse
**/
const double DELTA_ANGLE_VITESSE_MINI = 5;
const double DELTA_ANGLE_VITESSE_MAXI = 2;
const double DELTA_COEF = (DELTA_ANGLE_VITESSE_MINI - DELTA_ANGLE_VITESSE_MAXI) / VITESSE_AVANT_MAXI;

/**
 * Nombre de secteurs.
**/
const int NOMBRE_SECTEURS = 5;

/**
 * Nombre de tours à parcourir dans une course.
**/
const int NOMBRE_TOURS = 10;

/**
 * Pour gérer les glissades
**/
const int FIRST_ETAT_GLISSADE = 20;

/**
 * Pour gérer les glissades
**/
const int FIRST_ETAT_SAUT = 8;

/**
 * Nombre maxi d'angles conservés pour le lissage.
**/
const int MAX_ANGLE = 10;
const double DELTA_VARIATION_VITESSE_MAXI = 0.05;

/**
 * Nombre maximum de voitures participant à chaque course.
**/
const int MAX_VOITURES = 4;

/**
 * Nombre maximum de points dans la trajectoire idéale.
**/
const int MAX_TRAJECTOIRE = 5000;

/**
 * Nombre de joueurs IA.
**/
const int MAX_JOUEUR_IA = 2;


/** --------------------------------------------------------------------
 * Codes SFML des touches clavier pour le joueur 1.
**/
const sf::Keyboard::Key KEY_UP1 = sf::Keyboard::Up;
const sf::Keyboard::Key KEY_DOWN1 = sf::Keyboard::Down;
const sf::Keyboard::Key KEY_LEFT1 = sf::Keyboard::Left;
const sf::Keyboard::Key KEY_RIGHT1 = sf::Keyboard::Right;

/** --------------------------------------------------------------------
 * Codes SFML des touches clavier pour le joueur 2.
**/
const sf::Keyboard::Key KEY_UP2 = sf::Keyboard::Z;
const sf::Keyboard::Key KEY_DOWN2 = sf::Keyboard::S;
const sf::Keyboard::Key KEY_LEFT2 = sf::Keyboard::Q;
const sf::Keyboard::Key KEY_RIGHT2 = sf::Keyboard::D;

/** --------------------------------------------------------------------
 * Code SFML pour escape.
**/
const int KEY_ESCAPE = sf::Keyboard::Escape;

/** --------------------------------------------------------------------
 * Nombre maximum de touches claviers gérées.
**/
const int MAX_KEYS = 4;






/**************************************************************************** */

#endif // CONSTANTS_HPP