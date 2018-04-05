/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std::placeholders;

void GestionnaireProduits::reinitialiserClient()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		ProduitAuxEncheres* produit = dynamic_cast<ProduitAuxEncheres*>(it->second);
			if (produit) {
				produit->modifierEncherisseur(nullptr);
				produit->modifierPrix(produit->obtenirPrixInitial());

			}
	}
	conteneur_.clear();


};

void GestionnaireProduits::reinitialiserFournisseur()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		ProduitAuxEncheres* produit = dynamic_cast<ProduitAuxEncheres*>(it->second);
		if (produit) {
			produit->modifierFournisseur(nullptr);
			produit->modifierPrix(produit->obtenirPrixInitial());

		}
	}
	conteneur_.clear();


};

void GestionnaireProduits::afficher()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		it->second->afficher();
	}
};

double GestionnaireProduits::obtenirTotalAPayer() const
{
	double somme = accumulate(conteneur_.begin()->second->obtenirPrix(), conteneur_.end()->second->obtenirPrix(), 0);
	return somme;
};

double GestionnaireProduits::obtenirTotalApayerPremium() const
{
	double rabais = 5;
	double somme = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		somme += it->second->obtenirPrix() - 5;
	}
	return somme;

}
Produit GestionnaireProduits::trouverProduitPlusCher() const
{
	
	
	auto produitPlusCher = max_element(conteneur_.begin(), conteneur_.end(), [](const pair<int, Produit*> P1, const pair<int, Produit*> P2)
	{
		return P1.second->obtenirPrix() < P2.second->obtenirPrix();
	});
	if (produitPlusCher == conteneur_.end()) {
		return nullptr;
	}
}
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double debut, double fin) const
{
	vector<pair<int, Produit*>> vecteur;
	copy_if(debut, fin, back_inserter(vecteur),FoncteurIntervalle(debut,fin));
	return vecteur;
}
Produit* GestionnaireProduits::obtenirProduitSuivant(Produit * produit) const
{
	auto it = find_if(conteneur_.begin(), conteneur_.end(), bind(greater< pair<int, Produit*>>() , _1, pair<int, Produit*> (produit->obtenirReference(), produit)));
	return it->second;
}
;
