/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include "Foncteur.h"

// TODO : Créer la classe GestionnaireGenerique
template < typename T, typename C, typename A, typename S, typename Predicate> // le predicat va peut etre pas la
class GestionnaireGenerique
{
	public:
		GestionnaireGenerique();
		


			// TODO : Méthodes :
			/*
			- ajouter()
			- supprime()
			- obtenirConteneur()
			- pourChaqueElement()
			*/

		A ajouter(*T);
		S supprimer(*T);
		C obtenirConteneur();
		void pourChaqueElement(Predicate);
	protected:
		C conteneur_;
};
#endif