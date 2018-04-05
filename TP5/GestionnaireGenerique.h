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
	C obtenirConteneur() const;
	void ajouter(T* T);
	void Supprimer(T* T);
	template<typename Foncteur>
	void pourChaqueElement(Foncteur foncteur)const;


protected:
	C conteneur_;
};



template <typename T, typename C, typename A, typename S >
void GestionnaireGenerique<T, C, A, S>::ajouter(T* t)
{
	A ajouter(conteneur_);
	conteneur_ = ajouter(t);


};

template <typename T, typename C, typename A, typename S >
void GestionnaireGenerique<T, C, A, S>::Supprimer(T* t)
{
	S supprimer(conteneur_);
	conteneur_ = supprimer(t);

};

template <typename T, typename C, typename A, typename S >
C GestionnaireGenerique<T, C, A, S>::obtenirConteneur() const
{
	return conteneur_;
};

template <typename T, typename C, typename A, typename S>
template<typename Foncteur>
void GestionnaireGenerique<T, C, A, S>::pourChaqueElement(Foncteur foncteur) const
{
	for_each(conteneur_.begin(), conteneur_.end(), foncteur);

};



// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/
