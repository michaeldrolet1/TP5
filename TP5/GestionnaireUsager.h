
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>


#include "ProduitAuxEncheres.h"


#include "GestionnaireGenerique.h"

// TODO : Cr�er la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup � la classe Gestionnaire
/*
Les m�thodes retrouv�es de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
*/
using namespace std;

class Gestionnaire
{
public:
	vector<Usager *> obtenirUsagers() const;
	void afficherLesProfils() const;
	double obtenirChiffreAffaires() const;

	void ajouterUsager(Usager *usager);
	void reinitialiser();
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;

private:
	vector<Usager *> usagers_;
};

#endif