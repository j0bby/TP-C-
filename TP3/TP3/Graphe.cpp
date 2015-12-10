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

//---------------------------------------------------- Variables de classe
int valeurNoeud;
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

void Graphe::GenereFichier(const string & nomFichier)
{
	char* nomFich = nomFichier.c_str;
	ofstream grapheFile(nomFich);
	if (grapheFile) // le fichier est correct
	{
		// génération des noeuds 
		cout << "digraph {" << endl;
		map<string, int > ::const_iterator noeudsDebut, noeudsFin;
		noeudsDebut = noeuds.begin;
		noeudsFin = noeuds.end;
		for (noeudsDebut; noeudsDebut != noeudsFin; noeudsDebut++)
		{
			cout << "node" << noeudsDebut->second << " [" << noeudsDebut->first << "];" << endl;
		}
		// génération des liens 
		map<paire, int > ::const_iterator liensDebut, liensFin;
		noeudsDebut = liens.begin;
		noeudsFin = liens.end;
		for (liensDebut; liensDebut != liensFin; liensDebut++)
		{
			cout << "node" << liensDebut->first.NumReferer << " -> node" << liensDebut->first.NumCible << " [label=\"" << liensDebut->second << "\"];" << endl;
		}

		cout << "}" << endl;
	}
	else
	{
		cerr << "[Generation Graphe] Pb sur le fichier" << endl;
	}

	
}

Graphe::Graphe ( const Collection &aCol, const bool e = false, const int h = -1  )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
	map<string , Cible > :: const_iterator debut,fin;
	debut=aCol.pages.begin;
	fin=aCol.pages.end;
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
				estImage = Extension.compare(EXCLUSIE[i]) == 0;// si l'extension est celle d'une image
			}
		}
		if(h!=-1 && !estImage) // filtre en fonction de l'heure
		{
			/*// déclaration des itérateurs de parcours 
			map<string, list<Log> > ::const_iterator typeReqDeb,typeReqFin;
			typeReqDeb = debut->second.lesLogs[h].begin();
			typeReqFin = debut->second.lesLogs[h].end();


			while (typeReqDeb != typeReqFin && typeReqDeb->first!="GET")// isolation des hits
			{
				typeReqDeb++;
			}

			if (typeReqDeb->first == "GET") // si la page a bien été hit au moins une fois.
			{
				if (typeReqDeb->second.empty()) //impossible
				{

				}
				Log* cur = typeReqDeb->second.begin;
				while (cur != typeReqDeb->second.end) // parcours des logs
				{
					// si le noeud n'existe pas ! 
					pair<string, int> aInserer = { cur->referer, valeurNoeud };
					if (!noeuds.insert(aInserer).second) // si le noeud est déjà présent
					{
						valeurNoeud++;
					}
					
					// si la paire n'existe pas
					paire paireInserer = { noeuds.find(cur->referer)->second , valeurNoeudCible};
					pair<paire, int> insertion = { paireInserer, 1 };
					if (!liens.insert(insertion).second) 
					{
						liens.find(paireInserer)->second++;
					}
					
					cur++; // on change de log !!!
				}
			}*/
			creeGrapheHeure(debut, h, valeurNoeudCible);

		} // on a fini de filtrer en fonction de l'heure !!!!!!!! 
		else if (h == -1 && !estImage) // si on veut pas de filtre sur les heures !!!!!!!!
		{
			for (size_t heure = 0; heure < 24; heure++) // on le fait pour chaques heures !!! 
			{
				creeGrapheHeure(debut, heure, valeurNoeudCible);
				/*map<string, list<Log> > ::const_iterator typeReqDeb, typeReqFin;
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
						if (!noeuds.insert(aInserer).second) // si on peut insérer
						{
							valeurNoeud++;
						}

						// si la paire n'existe pas
						paire paireInserer = { noeuds.find(cur->referer)->second , valeurNoeudCible };
						pair<paire, int> insertion = { paireInserer, 1 };
						if (!liens.insert(insertion).second )
						{
							liens.find(paireInserer)->second++;
						}

						cur++; // on change de log !!!
					}
				}*/

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

void Graphe::creeGrapheHeure(map<string, Cible>::const_iterator & Cible, const size_t & heure, int &valeurNoeudCible)
{
	// déclaration des itérateurs de parcours 
	map<string, list<Log> > ::const_iterator typeReqDeb, typeReqFin;
	typeReqDeb = Cible->second.lesLogs[heure].begin();
	typeReqFin = Cible->second.lesLogs[heure].end();


	while (typeReqDeb != typeReqFin && typeReqDeb->first != "GET")// isolation des hits
	{
		typeReqDeb++;
	}

	if (typeReqDeb->first == "GET") // si la page a bien été hit au moins une fois.
	{
		if (typeReqDeb->second.empty()) //impossible
		{

		}
		Log* cur = typeReqDeb->second.begin;
		while (cur != typeReqDeb->second.end) // parcours des logs
		{
			// si le noeud n'existe pas ! 
			pair<string, int> aInserer = { cur->referer, valeurNoeud };
			if (!noeuds.insert(aInserer).second) // si le noeud est déjà présent
			{
				valeurNoeud++;
			}

			// si la paire n'existe pas
			paire paireInserer = { noeuds.find(cur->referer)->second , valeurNoeudCible };
			pair<paire, int> insertion = { paireInserer, 1 };
			if (!liens.insert(insertion).second)
			{
				liens.find(paireInserer)->second++;
			}

			cur++; // on change de log !!!
		}
	}
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
