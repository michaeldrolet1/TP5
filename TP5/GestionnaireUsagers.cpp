/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double somme = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		Usager* usager = dynamic_cast<Usager*>(*it);
		somme += usager->obtenirTotalAPayer();
	}
	return somme;
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsagers::reinitialiser()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		Usager* usager = dynamic_cast<Usager*>(*it);
		if (usager) {
			usager->reinitialiser();
		}
	}
	conteneur_.clear();
}

void GestionnaireUsagers::afficherProfils() const
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		Usager* usager = dynamic_cast<Usager*>(*it);
		if (usager) {
			usager->afficher();
		}
	}
}
