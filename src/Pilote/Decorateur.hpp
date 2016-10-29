/**
 * Fichier Decorateur.hpp 
 *
 * Décorateur.
 * @author LE BARS Yannis & HUNAULT Marion
**/
class Decorateur : public IPilote
{
	private:
	//Attribut
		/**
		 * Pilote par défaut.
		**/
		private Controller controller_;
		
	public:
	//Constructeur et destructeur
		/** --------------------------------------------------------------------
		 * @brief Constructeur du décorateur
		 * 
		 * @pre 
		 * @post 
		 *
		 * @b Complexité O(1)
		**/
		Decorateur(IPilote iPilote);
		
		/** --------------------------------------------------------------------
		 * @brief Destructeur du décorateur
		 *
		 * @b Complexité O(1)
		**/
		~Decorateur();
		
	//Autres méthodes
		/** --------------------------------------------------------------------
		 * @overried
		 * 
		 * @b Complexité 
		**/
		virtual void actualiser (unsigned joueur, Gestionnaire gestionnaire) = 0;
}; // class Decorateur
/******************************************************************************/

#endif // DECORATEUR_HPP