/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include<numeric>

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

void GestionnaireProduits::obtenirTotalAPayer()
{
	double somme = accumulate(conteneur_.begin()->second, conteneur_.end()->second, 0);

};

void GestionnaireProduits::obtenirTotalApayerPremium()
{
	double rabais = 5;
	double somme = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		somme += it->second->obtenirPrix - 5;
	}

}
Produit GestionnaireProduits::trouverProduitPlusCher()
{

	return Produit();
}
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double debut, double fin)
{
	vector<pair<int, Produit*>> vecteur;
	copy_if(debut, fin, back_inserter(vecteur),FoncteurIntervalle(debut,fin));
	return vecteur;
}
Produit* GestionnaireProduits::obtenirProduitSuivant(Produit * produit)
{
	Produit* produitReferenceSuperieur = find_if(conteneur_.begin(),conteneur_.end(),bind(  )
}
;
