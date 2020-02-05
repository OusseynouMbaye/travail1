#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{


public:
	Joueur Joueur1;
	Joueur Joueur2;
	Carte lePaquetDeCarte[maxCartes];
	Donnees();
	void creerLePaquetDeCarte();
	void creerLesCartes(string inAtoutCarte, int& compteur);

	
};

