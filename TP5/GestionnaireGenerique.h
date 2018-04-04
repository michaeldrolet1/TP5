/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Créer la classe GestionnaireGenerique
template <typename T, typename C, typename A, typename S > 
class GestionnaireGenerique
{
public:
	C obtenirConteneur() const
	{
		return conteneur_;
	};

	void Ajouter(T* t)
	{
		A ajouter(conteneur_);
		conteneur_ = ajouter(t);
	}

	void Supprimer(T* t)
	{
		S supprimer(conteneur_);
		conteneur_ = supprimer(t);
	}

	template<typename Foncteur>
	void pourChaqueElement(Foncteur foncteur) const
	{
		for_each(conteneur_.begin(), conteneur_.end(), foncteur);
	}


protected:
	C conteneur_;
};
