/*************************************************************************
Collection  -  description
-------------------
début                : 2015
copyright            : (C) 2015 par mfallouh mvirsolvy
*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier Collection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <iostream>
#include <list>
//------------------------------------------------------ Include personnel
#include "Collection.h"
#include "Cible.h"
//------------------------------------------------------------- Constantes
const char SEP_REQ = '"', SEP = ' ', SEP_DATE_DEBUT = '[', SEP_DATE_FIN = ']', SEP_HEURE = ':';
const string excluSiE[] = {(string)"jpg", (string)"png", (string)"tga", (string)"gif", (string)"jpeg", (string)"bmp", (string)"js",(string)"css"}
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Collection::Top10(const bool e, const int h)
// Algorithme
//
{
	list<string> leTop;

	if (e)	//option e spécifiée
	{
		if (h == -1)	//option h spécifiée
		{

		}
		else	//option h non spécifiée
		{

		}
	}
	else	//option e non-spécifiée
	{
		if (h == -1)	//option h spécifiée
		{

		}
		else	//option h non spécifiée
		{

		}
	}
}//----- Fin de Top10


/*//------------------------------------------------- Surcharge d'opérateurs
Collection & Collection::operator = ( const Collection & unCollection )
// Algorithme :
//
{
} //----- Fin de operator =

*/
//-------------------------------------------- Constructeurs - destructeur
Collection::Collection(const Collection & unCollection)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Collection>" << endl;
#endif
} //----- Fin de Collection (constructeur de copie)



Collection::Collection(const string & nomFichier)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Collection>" << endl;
#endif
	ifstream fichier (nomFichier.c_str());
	if (fichier)	//fichier trouvé
	{
		string ligneLog;
		while (fichier)		//tant que l'on a pas fini de lire le fichier
		{
			/* extraction de la cible de la requête */
			getline(fichier, ligneLog);
			size_t debut = ligneLog.find(SEP_REQ);
			debut = ligneLog.find(SEP, debut);
			size_t fin = ligneLog.find(SEP_REQ, debut);
			string adrCible = ligneLog.substr(debut, fin);

			/* mise à jour du dictionnaire de Cible */
			pair<map<string, Cible>::iterator, bool> insertion;		//pour recevoir le résultat de la tentative d'insertion
			Cible cibleInser;
			cibleInser.Ajouter(ligneLog);
			pair<string, Cible> aInserer = { adrCible, cibleInser };	// créér une paire pour l'insertion
			insertion = pages.insert(aInserer);	//tentative d'insertion, on récupère le résultat
			if (!insertion.second)	//si la Cible existait déjà dans la map
			{
				pages.find(adrCible)->second.Ajouter(ligneLog);	//on ajoute le nouveau log à la Cible
			}
		}	//fin du fichier atteinte
	}
	else	//fichier non trouvé
	{
		cerr << "Fichier " << nomFichier << " non trouve !" << endl;
	}


} //----- Fin de Collection

Collection::~Collection()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Collection>" << endl;
#endif
} //----- Fin de ~Collection


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
