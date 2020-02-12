#include "joueur.h"
#include <conio.h>

Joueur::Joueur()
{

	nom = "";
	nombreVictoires = 0;
	nombreDefaites = 0;
		//boucle pour initialiser chaque carte à NULL
		//lesCartesDuPaquet[26];
	for (int cpt = 0; cpt < maxCartesAJouer; cpt++)
	{
		
		lesCartesDuPaquet[cpt]= NULL;
		cpt++;
	}
}
string Joueur::GetNom() const
{

	return nom;
}
int Joueur::GetNombreVictoires() const
{

	return nombreVictoires;
}

int Joueur::GetNombreDefaites() const
{

	return nombreDefaites;
}

Carte* Joueur::getUneCarteDuPaquet(int inPosition) const
{
	return lesCartesDuPaquet[inPosition];
}

void Joueur::setNom(string inNom)
{
	nom = inNom;
}
void Joueur::AjouterDesVictoires()
{
	nombreVictoires++;

}
void Joueur::AjouterDesDefaites()
{
	nombreDefaites++;

}

void Joueur::AjouterUneCarteALaMain(Carte* inCarteDuJoueur)
{
	int cpt = 0;

	while (lesCartesDuPaquet[cpt]!= NULL)
	{
		
		cpt++;
	}
	lesCartesDuPaquet[cpt] = inCarteDuJoueur;
}
void Joueur::EnleverToutesLesCartesDUneMain() 
{

	for (int cpt = 0; cpt < maxCartesAJouer ; cpt++)
	{
		
		lesCartesDuPaquet[cpt] = NULL;
	}
}

int Joueur::additionerLesCarteDuJoueur()
{
	int sommme = 0;
	for (int cpt = 0; cpt < maxCartesAJouer; cpt++)
	{
		if (lesCartesDuPaquet[cpt]!=NULL)
		{
		sommme = sommme + lesCartesDuPaquet[cpt]->GetValeur();
		}
		
	}

	return  sommme;
}









/*if (lesCartesDuPaquet[cpt] == NULL)
		{
			lesCartesDuPaquet[cpt] = inCarteDuJoueur;
		}*/