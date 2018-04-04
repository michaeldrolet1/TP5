/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include"Produit.h"
#include"ProduitSolde.h"
#include <map>
#include <algorithm>
#include <set>


// TODO : Cr�er le FoncteurEgal
template<typename T>
class FoncteurEgal
{
	public: 
		FoncteurEgal(T* t) : t_(t) {};
		bool operator()(pair<int, T* > &pair) const
		{
			return t_ == pair.second;
			
		};

	private:
		T * t_;

}; 

// TODO : Cr�er le FoncteurGenerateurId
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
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
// TODO : Cr�er le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
*/
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage) {};
	void operator()(pair<int, Produit* > pair)
	{
		if (typeid(pair.second) != typeid(ProduitSolde))
			pair.second->modifierPrix(pair.second->obtenirPrix -= pair.second->obtenirPrix*(pourcentage_ / 100));

	};

private:
	int pourcentage_;
};
// TODO : Cr�er le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
*/
	class FoncteurIntervalle
	{
	public:
		FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
		bool operator()(pair<int, Produit* > pair)
		{
			return(pair.second->obtenirPrix <= borneSup_ && pair.second->obtenirPrix >= borneInf_);
		};

	private:
		double borneInf_, borneSup_;
	};
// TODO : Cr�er le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/
	class AjouterProduit
		{
		public:
			AjouterProduit( multimap<int, Produit*> &m) : multimap_(m) {};
			
			
			 multimap <int, Produit*> operator()(Produit* produit)
			{
				 multimap<int, Produit*> ::iterator begin = multimap_.begin();
				 multimap_.insert(pair<int, Produit*>(begin->first, produit));
				 return multimap_;
			}; 
			 

		private:
			multimap<int, Produit*> &multimap_;

	};

// TODO : Cr�er le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/
class SupprimerProduit
	{
	public:
		SupprimerProduit( multimap <int, Produit*> &m) : multimap_(m) {};


		multimap <int, Produit*> & operator()(Produit* produit)
		{
			FoncteurEgal<Produit>  comparateur(produit);
			auto it = find_if(multimap_.begin(), multimap_.end(), comparateur);
			if (it != multimap_.end())
			{
				multimap_.erase(it);
				return multimap_;
			}
			 
		};

	private:
		multimap<int, Produit*> &multimap_;

	};

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class AjouterUsager
{
	public:
		AjouterUsager(set<Usager*> &s) : set_(s) {};


		set <Usager*> operator()(Usager* produit)
		{
		set_.insert(produit);
		return set_;
		};


	private:
		set<Usager*> &set_;
};

class SupprimerUsager
{
public:
	SupprimerUsager(set <Usager*> &s) : set_(s) {};


	set < Usager*> & operator()(Usager* usager)
	{
		FoncteurEgal<Usager>  comparateur(usager);
		auto it = find_if(set_.begin(), set_.end(), comparateur);
		if (it != set_.end())
		{
			set_.erase(it);
			return set_;
		}

	};

private:
	set<Usager*> &set_;

};
