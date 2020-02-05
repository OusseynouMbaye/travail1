#include "donnees.h"


Donnees::Donnees()
{
	
}

void Donnees::creerLePaquetDeCarte()
{
	int cpt=0;
	//il faudrait aller creer les cartes de piques
	lePaquetDeCarte[0].InitialiserCarte(1, "pique");
	
	//il faudrait aller creer les cartes de coeur
	//il faudrait aller creer les cartes de trefle
	//il faudrait aller creer les cartes de carreau

}
void Donnees::creerLesCartes(string inAtoutCarte, int &inCompteur)
{
	
	int ValeurCarte;
	for (ValeurCarte = 1; ValeurCarte <=13 ; ValeurCarte++)
	{

		lePaquetDeCarte[inCompteur] = new Carte;
		
		lePaquetDeCarte[inCompteur].InitialiserCarte(ValeurCarte)
	}

}
