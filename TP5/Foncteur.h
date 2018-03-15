/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include"Produit.h"
#include"ProduitSolde.h"

// TODO : Créer le FoncteurEgal
template<typename T>
class FoncteurEgal
{
	public: 
		FoncteurEgal(T* t) : t_(t) {};
		bool operator()(pair<int, T* > pair)
		{
			return(d == pair.second);
			
		};

	private:
		T * t_;

}; 

// TODO : Créer le FoncteurGenerateurId
/*
Attributs :
- id_;
Méthodes :
- operator(); Incrémenter id_ à chaque appel
*/
class FoncteurGenerateurId
{
	public:
		FoncteurGenerateurId(int id) : id_(0) {};
		void operator()()
		{
			id_++;
		};
	
	private:
		int id_;
};
// TODO : Créer le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
Méthodes :
- operator(); Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
*/
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage) {};
	void operator()( pair<int , Produit* > pair)
	{
		if(typeid(pair.second) != typeid(ProduitSolde))
		pair.second->modifierPrix(pair.second->obtenirPrix -= pair.second->obtenirPrix*(pourcentage_/100));

	};

private:
	int pourcentage_;

// TODO : Créer le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
Méthodes :
- operator(); Vérifie que le Produit associé à la pair passé en paramètre est compris entre les bornes borneInf_ et borneSup_ (retourne un booléen)
*/
class FoncteurIntervalle
	{
	public:
		FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf),borneSup_(borneSup) {};
		bool operator()(pair<int, Produit* > pair)
		{
			return(pair.second->obtenirPrix <= borneSup_ && pair.second->obtenirPrix >= borneInf_);
		};

	private:
		double borneInf_, borneSup_;
// TODO : Créer le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/
class AjouterProduit
{
	public:
		FoncteurIntervalle( map<int,Produit*> &multimap) : &multimap_(&multimap) {};
		bool operator()(pair<int, Produit* > pair)
		{
			return(pair.second->obtenirPrix <= borneSup_ && pair.second->obtenirPrix >= borneInf_);
		};

	private:
		map<int, Produit*> &multimap_;

// TODO : Créer le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/

//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
