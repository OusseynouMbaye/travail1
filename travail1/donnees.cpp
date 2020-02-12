#include "donnees.h"


Donnees::Donnees()
{
	creerLePaquetDeCarte();

}

void Donnees::creerLePaquetDeCarte()
{
	int inNumeroDesCartes=0;
	
	creerLesCartes("pique", inNumeroDesCartes);
	creerLesCartes("Coeur", inNumeroDesCartes);
	creerLesCartes("Trefle", inNumeroDesCartes);
	creerLesCartes("Carreau", inNumeroDesCartes);
	

}
void Donnees::creerLesCartes(string inAtoutCarte, int &inNumeroDesCartes)
{
	
	int ValeurCarte;
	for (ValeurCarte = 1; ValeurCarte <=13 ; ValeurCarte++)
	{
		
		lePaquetDeCarte[inNumeroDesCartes].InitialiserCarte(ValeurCarte,inAtoutCarte);
		inNumeroDesCartes++;
	}

}
