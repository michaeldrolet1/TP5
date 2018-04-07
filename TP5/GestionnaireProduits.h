/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once



#include <vector>
#include "Usager.h"
#include "GestionnaireGenerique.h"
#include<map>
#include"Foncteur.h"
#include"Produit.h"

// TODO : Créer la classe GestionnaireProduits

// TODO : Méthodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/
using namespace std;

class GestionnaireProduits : public GestionnaireGenerique<Produit, multimap< int, Produit*>, AjouterProduit, SupprimerProduit>
{
public:
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	double obtenirTotalAPayer() const;
	double obtenirTotalApayerPremium() const;
	Produit trouverProduitPlusCher() const ;
	vector<pair<int,Produit*>> obtenirProduitsEntre(double debut, double fin) const;
	Produit* obtenirProduitSuivant(Produit* produit )const;


	
};

