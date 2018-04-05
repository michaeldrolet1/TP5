/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include <vector>
#include "Usager.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireGenerique.h"
#include "Produit.h"
#include <map>
#include "Foncteur.h"

// TODO : Créer la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup à la classe Gestionnaire
/*
Les méthodes retrouvées de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
*/
class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, AjouterUsager, SupprimerUsager>
{
public:
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
};
