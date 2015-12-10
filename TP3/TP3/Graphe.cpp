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
	string Extension = adresse.substr(posExtension,adresse.npos); // l'extension
	unsigned int i = 0;
	for (int i = 0; i < NB_FORMAT; i++) // parcours les extensions images.
	{
		return Extension.compare(EXCLUSIE[i]) == 0;// si l'extension est celle d'une image
	}
	return false;
}

void Graphe::GenereFichier(const string & nomFichier)
{
	//char *nomFich = nomFichier.c_str;
	ofstream grapheFile(nomFichier.c_str());
	if (grapheFile) // le fichier est correct
	{
		// génération des noeuds 
		cout << "digraph {" << endl;
		map<string, int > ::const_iterator noeudsDebut, noeudsFin;
		noeudsDebut = noeuds.begin();
		noeudsFin = noeuds.end();
		for (noeudsDebut; noeudsDebut != noeudsFin; noeudsDebut++)
		{
			cout << "node" << noeudsDebut->second << " [" << noeudsDebut->first << "];" << endl;
		}
		// génération des liens 
		map<paire, int > ::const_iterator liensDebut, liensFin;
		liensDebut = liens.begin();
		liensFin = liens.end();
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
		

		bool estImage = false; // permet de gérer l'option -e
		if(e) // filtre en fonction des extensions
		{
			estImage = EstImage(debut->first);
		} 

		if (!estImage) // création du noeud ,si la cible est pas une image -e 
		{   
			creeNoeud( debut->first, valeurNoeud ); 
			valeurNoeudCible = valeurNoeud;
			valeurNoeud++;
		} // fin de la création

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
			creeGrapheHeure(debut, h, valeurNoeudCible, e);

		} // on a fini de filtrer en fonction de l'heure !!!!!!!! 
		else if (h == -1 && !estImage) // si on veut pas de filtre sur les heures !!!!!!!!
		{
			for (size_t heure = 0; heure < 24; heure++) // on le fait pour chaques heures !!! 
			{
				creeGrapheHeure(debut, heure, valeurNoeudCible, e);
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

void Graphe::creeGrapheHeure(map<string, Cible>::const_iterator & Cible, const size_t & heure, int &valeurNoeudCible, bool e)
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
		
		list<Log> :: const_iterator cur = typeReqDeb->second.begin(); // itérateur de parcours des logs
		while (cur != typeReqDeb->second.end()) // parcours des logs
		{
			// on vérifie si c'est une image ou non
			if (!e ||(e && !EstImage(cur->referer)))
			{
				// si le noeud n'existe pas ! 
				pair<string, int> aInserer = { cur->referer, valeurNoeud };
				if (!noeuds.insert(aInserer).second) // si le noeud n'est pas déjà présent
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
			}
			cur++; // on change de log !!!
		}
	}
}

void Graphe::creeNoeud(const string & page, const int & valeurNoeud)
{
	pair<string, int> aInserer = { page, valeurNoeud }; // le noeud
	noeuds.insert(aInserer);
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
