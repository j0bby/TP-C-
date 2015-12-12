/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include<fstream>
//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

extern const string EXCLUSIE[];
extern const int NB_FORMAT;
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

/*
Graphe & Graphe::operator = ( const Graphe & unGraphe )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur

/*
Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)
*/

bool Graphe::EstImage(const string & adresse)
{
	size_t posExtension = adresse.find_last_of('.'); // position à partir de laquelle commence l'extension
	string Extension = adresse.substr(posExtension + 1,adresse.npos); // l'extension
	bool image = false;
	int i = 0;
	while( i < NB_FORMAT && !image ) // parcours les extensions images.
	{
		image = Extension.compare(EXCLUSIE[i]) == 0;// si l'extension est celle d'une image
		i++;
	}
	return image;
}

void Graphe::GenereFichier(const string & nomFichier)
{
	ofstream grapheFile(nomFichier.c_str());
	if (grapheFile) // le fichier est correct
	{
		// génération des noeuds 
		grapheFile << "digraph {" << endl;
		map<string, int > ::const_iterator noeudsDebut, noeudsFin;
		noeudsDebut = noeuds.begin();
		noeudsFin = noeuds.end();
		for (noeudsDebut; noeudsDebut != noeudsFin; noeudsDebut++)
		{
			grapheFile << "node" << noeudsDebut->second << " [" << noeudsDebut->first << "];" << endl;
		}
		// génération des liens 
		map<paire, int > ::const_iterator liensDebut, liensFin;
		liensDebut = liens.begin();
		liensFin = liens.end();
		for (liensDebut; liensDebut != liensFin; liensDebut++)
		{
			grapheFile << "node" << liensDebut->first.NumReferer << " -> node" << liensDebut->first.NumCible << " [label=\"" << liensDebut->second << "\"];" << endl;
		}

		grapheFile << "}" << endl;
	}
	else
	{
		cerr << "[Generation Graphe] Pb sur le fichier" << endl;
	}

	
}

Graphe::Graphe ( const Collection &aCol, const bool e , const int h   ) : 
	valeurNoeud(0)
// Algorithme :
// parcours la collection dans son ensemble, 
// si option, compare l'extension avec celles connues pour une image et passe à vraie la variable estImage
// puis établis des liens entre referer et cible (mits dans noeuds) que cré des liens, ou implémente leur valeur pour chaque logs.
// si option h, alors celà est fait que pour l'heure précisée
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
	map<string , Cible > :: const_iterator debut,fin; // les itérateurs de parcours de la collection
	debut=aCol.pages.begin();
	fin=aCol.pages.end();
	int valeurNoeudCible = 0; // la valeur de la cible, donc associé à l'itérateur début
	for(debut ; debut!=fin; debut++) // itération de parcours de la map pages
	{
		bool estImage = e && EstImage(debut->first); // permet de gérer l'option -e

		if (!(e && EstImage(debut->first)))
		{
			if (h != -1) // filtre en fonction de l'heure
			{
				creeGrapheHeure(debut, h, e);

			} // on a fini de filtrer en fonction de l'heure !!!!!!!! 
			else if (h == -1) // si on veut pas de filtre sur les heures !!!!!!!!
			{
				for (size_t heure = 0; heure < 24; heure++) // on le fait pour chaques heures !!! 
				{
					creeGrapheHeure(debut, heure, e);
				}
			}
		}

	}

} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe

void Graphe::creeGrapheHeure(map<string, Cible>::const_iterator & cible, const size_t & heure, bool e)
{
	bool noeudCree = false; // savoir si on a crée un noeud pour la cible ou pas encore
							// permettra de créer le noeud uniquement si il interagit avec une autre page
	int valeurNoeudCible; // garder en mémoire la valeur du noeud si il est crée
	// déclaration des itérateurs de parcours 
	map<string, list<Log> > ::const_iterator typeReqDeb, typeReqFin;
	if (!cible->second.lesLogs[heure].empty())// si la liste est non vide
	{
		typeReqDeb = cible->second.lesLogs[heure].begin();
		typeReqFin = cible->second.lesLogs[heure].end();


		while (typeReqDeb != typeReqFin && typeReqDeb->first != "GET")// isolation des hits
		{
			typeReqDeb++;
		}

		if (typeReqDeb != typeReqFin && typeReqDeb->first == "GET") // si la page a bien été hit au moins une fois.
		{

			list<Log> ::const_iterator cur = typeReqDeb->second.begin(); // itérateur de parcours des logs
			while (cur != typeReqDeb->second.end()) // parcours des logs
			{
				// on vérifie si c'est pas une image 
				if (!e || (e && !EstImage(cur->referer)))
				{
					if (!noeudCree) // si on a pas encore eu besoin de créer le noeud de la cible
					{
						if (creeNoeud(cible->first, valeurNoeud)) // si le noeud est doit etre crée
						{
							valeurNoeudCible = valeurNoeud;
							valeurNoeud++;
						}
						else // si il était déjà présent
						{
							valeurNoeudCible = noeuds.find(cible->first)->second;

						}
					}
					if (creeNoeud(cur->referer, valeurNoeud)) // si le noeud du referer n'est pas déjà présent
					{
						valeurNoeud++;
					}

					// si la paire n'existe pas
					paire paireInserer = { noeuds.find(cur->referer)->second , valeurNoeudCible };
					pair<paire, int> insertion = { paireInserer, 1 };
					pair<map<paire,int >::iterator, bool> bInsertion;
					bInsertion = liens.insert(insertion);
					if (!bInsertion.second)
					{
						liens.find(paireInserer)->second++;
					}
				}
				cur++; // on change de log !!!
			}
		}
	}
}

bool Graphe::creeNoeud(const string & page, const int & valeurNoeud)
{
	pair<string, int> aInserer = { page, valeurNoeud }; // le noeud
	pair<map<string, int >::iterator, bool> retInsertion;
	retInsertion = noeuds.insert(aInserer);
	return retInsertion.second;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
