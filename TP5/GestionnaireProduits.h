/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include "Usager.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireGenerique.h"
#include "Produit.h"
#include<map>
#include"Foncteur.h"

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

class GestionnaireProduits : public GestionnaireGenerique<Produit, multimap< int, Produit*>, AjouterProduit(), SupprimerProduit()>
{
public:
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	void obtenirTotalAPayer();
	void obtenirTotalApayerPremium();
	Produit trouverPrdouitPlusCher();
	vector<pair<int,Produit*>> obtenirProduitsEntre(double debut, double fin);
	Produit obtenirProduitSuivant(Produit* produit);


	
};

#endif