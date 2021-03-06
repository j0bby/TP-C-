/*************************************************************************
Graphe  -  description
-------------------
d�but                : 2015
copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <map>
#include "Collection.h"
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef struct paire {
	// structure associant une cilbe et un referer par le num�ro de noeud leur correspondant

	int NumReferer;
	int NumCible;

	bool const& operator<(const paire & unePaire) const
	// surchage de l'operteur de comparaison pour permettre l'utilisation en tant que cl�e dans la map
	// 
	// Mode d'emploi :
	// compare d'abord les numReferer entre eux, en cas d'�galit�, compare les numCible
	// Contrat :
	//
	{
		if (this->NumReferer != unePaire.NumReferer)
		{
			return (this->NumReferer < unePaire.NumReferer);
		}
		else
		{
			return (this->NumCible < unePaire.NumCible);
		}
	}
};
//------------------------------------------------------------------------ 
// R�le de la classe <Graphe>
// Cette classe repr�sente un graphe. Elle contient les informations 
// n�cessaires � sa g�n�ration (n�uds et liens). On construit un Graphe 
// � partir d�une Collection et des options souhait�es.
//
//------------------------------------------------------------------------ 
class Graphe
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	static bool EstImage(const string &adresse);
	// Mode d'emploi : 
	// v�rifie si l'extension est celle d'une image
	// Contrat :
	// le param�tre est une string correspondant � une adresse bien form�e

	void GenereFichier(const string & nomFichier);
	// Mode d'emploi :
	// �crit dans(ou cr�e) le fichier de nom � nomFichier � les instructions
	// de cr�ation de graphe, au format sp�cifi� dans l��nonc�.
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'op�rateurs
	Graphe & operator = (const Graphe & unGraphe); // d�clar� mais non d�fini pour emp�cher son utilisation
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Graphe(const Graphe & unGraphe); // d�clar� mais non d�fini pour emp�cher son utilisation
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Graphe(const Collection &aCol, const bool e = false, const int t = -1);
	// Mode d'emploi :
	// parcourt la Collection entr�e en param�tre afin de remplir les dictionnaires.
	// Prend en compte des options e et t.
	// Contrat :
	//

	virtual ~Graphe();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

	map<string, int > noeuds;	// dictionnaire de n�uds associant � chaque 
							    // adresse de page son numero pour le trac� du graphe

	map<paire, int> liens;		//dictionnaire de liens, associant � chaque paire(structure :
								//referer et cible, identifi�s par leurs num�ros de noeud) son nombre de hits.

	int valeurNoeud;			// la valeur du prochain noeud ajout� dans la la map noeud
private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es
	void creeGrapheHeure(map<string, Cible > ::const_iterator &Cible, const size_t &heure, bool e);
	// Mode d'emploi :
	// Pour la cible entr� en param�tre , et l'heure, parcours les logs en mettant � jour les attributs liens et noeuds.
	// Contrat :
	// heure < 24

	bool creeNoeud(const string &page, const int &valeurNoeud);
	// Mode d'emploi :
	// Cr�e le noeud, si jamais il existe d�j�, alors rien ne se passe
	// Contrat :
	// 
	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Graphe>

#endif // GRAPHE_H
