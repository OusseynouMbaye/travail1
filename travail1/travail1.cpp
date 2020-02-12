#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include "joueur.h"
#include "carte.h"
using namespace std;

Donnees leJeu;

void InitialiserJoueurs();
void Jouer();
void Afficher(int nombreDeCartesChiffres, Joueur unJoueur);
void VerfierVictoire();
void FinPartie();
int main() 
{
	TextColor(Yellow);

	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
	FinPartie();

	return 0;
}

void Jouer() 
{
	/******************************************************
	melanger les paquet de cartes
	*******************************************************/
	string nombreDeCartes;
	int nombreDeCartesChiffres;
	for (int i = 0; i < maxCartes; i++)
	{
		
		int nombreRandom = rand() % maxCartes;
		
		Carte temp=leJeu.lePaquetDeCarte[i];
		leJeu.lePaquetDeCarte[i]= leJeu.lePaquetDeCarte[nombreRandom];
		leJeu.lePaquetDeCarte[nombreRandom] = temp;

	}
/*************************************************************
nombre de carte a distribuer
*************************************************************/
	
	cout << "combien de cartes il faut distribuer: ";
	cin >> nombreDeCartes ;
	
	try
	{
		nombreDeCartesChiffres = stoi(nombreDeCartes);

		for (int cpt = 0; cpt < nombreDeCartesChiffres; cpt++)
		{
			leJeu.Joueur1.AjouterUneCarteALaMain(&leJeu.lePaquetDeCarte[cpt]) ;
			leJeu.Joueur2.AjouterUneCarteALaMain(&leJeu.lePaquetDeCarte[cpt+1+nombreDeCartesChiffres]);
		}

	}
	catch (const std::exception&)
	{
		cout << "Le nombre n'a pas pu etre converti";
	}

/*********************************************************************
faire afficher pur chaque joueur le nom,les cartes et total des cartes
**********************************************************************/
	
	Afficher(nombreDeCartesChiffres, leJeu.Joueur1);
	Afficher(nombreDeCartesChiffres, leJeu.Joueur2);
	 VerfierVictoire();
	
}
/***************************************************************************
fonction qui fait afficher joeur son nom ,ses cartes et le total des cartes
****************************************************************************/
void Afficher(int nombreDeCartesChiffres, Joueur unJoueur)
{

	cout << "nom joueur : ";
	cout << unJoueur.GetNom()<<"\n";

	for (int  i = 0; i < nombreDeCartesChiffres ; i++)
	{

		cout << unJoueur.getUneCarteDuPaquet(i)->GetValeur();
		cout << unJoueur.getUneCarteDuPaquet(i)->GetAtout()<<"\n";
		
	}
	cout << unJoueur.additionerLesCarteDuJoueur()<<"\n";
}
/***************************************************************************
FONCTION VERIFIER VICTOIRE
****************************************************************************/
void VerfierVictoire()
{
	if (leJeu.Joueur1.additionerLesCarteDuJoueur() > leJeu.Joueur2.additionerLesCarteDuJoueur())
	{
		leJeu.Joueur1.AjouterDesVictoires();
		leJeu.Joueur2.AjouterDesDefaites();
		cout << leJeu.Joueur1.GetNom() << " gagne";

	
	}
	else if (leJeu.Joueur1.additionerLesCarteDuJoueur() < leJeu.Joueur2.additionerLesCarteDuJoueur())
	{
		leJeu.Joueur2.AjouterDesVictoires();
		leJeu.Joueur1.AjouterDesDefaites();
		cout << leJeu.Joueur2.GetNom() << "gagne ";

	}
	else
	{
		cout << "Les 2 joeurs sont a egalité ";
	}
	leJeu.Joueur1.EnleverToutesLesCartesDUneMain();
	leJeu.Joueur2.EnleverToutesLesCartesDUneMain();

}
void FinPartie()
{
	cout << " Joueur 1 : " << leJeu.Joueur1.GetNom() << " : ";
	cout <<  leJeu.Joueur1.GetNombreVictoires() << " victoires  et ";
	cout << leJeu.Joueur1.GetNombreDefaites() << " defaites \n" ;
	
	cout << " Joueur 2 : " << leJeu.Joueur2.GetNom() << " : ";
	cout << leJeu.Joueur2.GetNombreVictoires() << " victoires  et ";
	cout << leJeu.Joueur2.GetNombreDefaites() << " defaites \n";

	if (leJeu.Joueur1.GetNombreVictoires() > leJeu.Joueur2.GetNombreVictoires())
	{

		cout << leJeu.Joueur1.GetNom() << " Tu a gagne la partie. \n";
	}
	else if (leJeu.Joueur1.GetNombreVictoires() < leJeu.Joueur2.GetNombreVictoires())
	{
		cout << leJeu.Joueur2.GetNom() << " Tu a gagne la partie. \n ";
	}
	else
	{
		cout << "La PARTIE EST NULLE.  \n";
	}
	
}

void InitialiserJoueurs()
{
	string NomJoueur;
	
	cout << " Joueur1: Entrez votre nom \n";
	cin >> NomJoueur;
	leJeu.Joueur1.setNom(NomJoueur);
	cout << " Joueur2: Entrez votre nom \n" ;
	cin >> NomJoueur ;
	leJeu.Joueur2.setNom(NomJoueur);

}

