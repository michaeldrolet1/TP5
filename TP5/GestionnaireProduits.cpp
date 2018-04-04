/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"

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