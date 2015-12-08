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

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes
const int NB_FORMAT_IMAGE=7;
const string[NB_FORMAT_IMAGE] FORMAT_IMAGE= {".jpg",".png",".jpeg",".tga",".gif",".tiff", ".bmp"};


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
	for(debut ; debut!=fin; debut++)
	{
		if(e) // filtre en fonction des extensions
		{
			for(int i=0; i<NB_FORMAT_IMAGE; i++)
			{

			}
		}
		if(h!=-1) // filtre en fonction de l'heure
		{

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
