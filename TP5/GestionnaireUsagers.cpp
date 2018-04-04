/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{

}

void GestionnaireUsagers::reinitialiser()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		Usager* usager = dynamic_cast<Usager*>(&it);
		if (usager) {
			usager->reinitialiser();
		}
	}
	conteneur_.clear();
}

void GestionnaireUsagers::afficherProfils() const
{

}
