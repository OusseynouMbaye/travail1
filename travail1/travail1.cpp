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

int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
	
	
	return 0;
}

void Jouer() 
{
	//melanger les paquet de cartes
	string nombreDeCartes;
	int nombreDeCartesChiffres;
	for (int i = 0; i < maxCartes; i++)
	{
		
		int nombreRandom = rand() % maxCartes;
		
		Carte temp=leJeu.lePaquetDeCarte[i];
		leJeu.lePaquetDeCarte[i]= leJeu.lePaquetDeCarte[nombreRandom];
		leJeu.lePaquetDeCarte[nombreRandom] = temp;

	}
//nombre de carte a distribuer
	
	cout << "combien de cartes il faut distribuer: ";
	cin >> nombreDeCartes ;
	
	try
	{
		nombreDeCartesChiffres = stoi(nombreDeCartes);

		for (int cpt = 0; cpt < nombreDeCartesChiffres *2; cpt+=2)
		{
			leJeu.Joueur1.AjouterUneCarteALaMain(&leJeu.lePaquetDeCarte[cpt]) ;
			leJeu.Joueur2.AjouterUneCarteALaMain(&leJeu.lePaquetDeCarte[cpt+1+nombreDeCartesChiffres]);
		}


	}
	catch (const std::exception&)
	{
		cout << "Le nombre n'a pas pu etre converti";
	}

	
	
	
	
}

void InitialiserJoueurs()
{
	string NomJoueur;
	
	cout << " Joueur1: Entrez votre nom ";
	cin >> NomJoueur;
	leJeu.Joueur1.setNom(NomJoueur);
	cout << " Joueur2: Entrez votre nom " ;
	cin >> NomJoueur ;
	leJeu.Joueur2.setNom(NomJoueur);

}
