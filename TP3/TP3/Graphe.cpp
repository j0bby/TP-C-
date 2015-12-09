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
//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes
const int NB_FORMAT_IMAGE=7;
const string FORMAT_IMAGE = ".jpg";// , ".png", ".jpeg", ".tga", ".gif", ".tiff", ".bmp" };


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

Graphe::Graphe ( const Collection &aCol, const bool e = false, const int h = -1  )
// Algorithme :
//
{
#ifdef MAP
    //cout << "Appel au constructeur de <Graphe>" << endl;
#endif
	map<string , Cible > :: const_iterator debut,fin;
	debut=aCol.pages.begin();
	fin=aCol.pages.end();
	int valeurNoeud = 0;
	int valeurNoeudCible = 0;
	for(debut ; debut!=fin; debut++) // itération de parcours de la map pages
	{
		// création du noeud ; 
		pair<string, int> aInserer = { debut->first, valeurNoeud };
		noeuds.insert(aInserer);
		valeurNoeudCible = valeurNoeud;
		valeurNoeud++;

		bool estImage = false;
		if(e) // filtre en fonction des extensions
		{
			size_t posExtension = debut->first.find_last_of('.'); // position à partir de laquelle commence l'extension
			string Extension = debut->first.substr(posExtension, debut->first.npos); // l'extension
			unsigned int i = 0;
			while(!estImage && i<NB_FORMAT_IMAGE) // parcours les extensions images.
			{
				estImage = Extension.compare(FORMAT_IMAGE) == 0;// si l'extension est celle d'une image
			}
		}
		if(h!=-1 && !estImage) // filtre en fonction de l'heure
		{
			map<string, list<Log> > ::const_iterator typeReqDeb,typeReqFin;
			typeReqDeb = debut->second.lesLogs[h].begin();
			typeReqFin = debut->second.lesLogs[h].end();
			while (typeReqDeb != typeReqFin && typeReqDeb->first!="GET")
			{
				typeReqDeb++;
			}
			if (typeReqDeb->first == "GET")
			{
				if (typeReqDeb->second.empty()) //impossible
				{

				}
				Log* cur = typeReqDeb->second.begin;
				while (cur != typeReqDeb->second.end)
				{
					// si le noeud n'existe pas ! 
					pair<string, int> aInserer = { cur->referer, valeurNoeud };
					if (noeuds.insert(aInserer) == ? ? ? ? ) // si on peut insérer
					{
						valeurNoeud++;
					}
					
					// si la paire n'existe pas
					paire paireInserer = { noeuds.find(cur->referer)->second , valeurNoeudCible};
					pair<paire, int> insertion = { paireInserer, 1 };
					if (liens.insert(insertion) == ? ? ? ? ? ? ) 
					{
						liens.find(paireInserer)->second++;
					}
					
					cur++; // on change de log !!!
				}
			}
		} // on a fini de filtrer en fonction de l'heure !!!!!!!! 
		else if (h == -1 && !estImage) // si on veut pas de filtre sur les heures !!!!!!!!
		{
			for (size_t heure = 0; heure < 24; heure++) // on le fait pour chaques heures !!! 
			{
				map<string, list<Log> > ::const_iterator typeReqDeb, typeReqFin;
				typeReqDeb = debut->second.lesLogs[h].begin();
				typeReqFin = debut->second.lesLogs[h].end();
				while (typeReqDeb != typeReqFin && typeReqDeb->first != "GET")
				{
					typeReqDeb++;
				}
				if (typeReqDeb->first == "GET")
				{
					if (typeReqDeb->second.empty()) //impossible
					{

					}
					Log* cur = typeReqDeb->second.begin;
					while (cur != typeReqDeb->second.end)
					{
						// si le noeud n'existe pas ! 
						pair<string, int> aInserer = { cur->referer, valeurNoeud };
						if (noeuds.insert(aInserer) == ? ? ? ? ) // si on peut insérer
						{
							valeurNoeud++;
						}

						// si la paire n'existe pas
						paire paireInserer = { noeuds.find(cur->referer)->second , valeurNoeudCible };
						pair<paire, int> insertion = { paireInserer, 1 };
						if (liens.insert(insertion) == ? ? ? ? ? ? )
						{
							liens.find(paireInserer)->second++;
						}

						cur++; // on change de log !!!
					}
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
    //cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
