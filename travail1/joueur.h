#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{
private:
	string nom;
	int nombreVictoires;
	int nombreDefaites;
	Carte* lesCartesDuPaquet[maxCartesAJouer];

	public:
		Joueur();

		string GetNom() const;
		void setNom(string inNom);
		int GetNombreVictoires() const;
		int GetNombreDefaites() const;
	

		Carte* getUneCarteDuPaquet(int inPosition) const;

		void AjouterDesVictoires();
		void AjouterDesDefaites(); 
		void AjouterUneCarteALaMain(Carte* inCarteDuJoueur) ;// quand faire in et const
		void EnleverToutesLesCartesDUneMain() ;
};
#endif
