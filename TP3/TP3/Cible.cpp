/*************************************************************************
Cible  -  description
-------------------
début                : 2015
copyright            : (C) 2015 par mfallouh mvirsolvy
*************************************************************************/

//---------- Réalisation de la classe <Cible> (fichier Cible.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <map>
#include <string>
//------------------------------------------------------ Include personnel
#include "Cible.h"
//------------------------------------------------------------- Constantes
const char SEP_REQ = '"', SEP = ' ', SEP_DATE_DEBUT = '[', SEP_DATE_FIN = ']', SEP_HEURE = ':';	// a mettre en extern
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


int Cible::Ajouter(const string & log)
// Algorithme :
//
{
	
	Log nouveauLog = Log(log);				//			!!!VERIFIER SI CA MARCHE AVEC ALLOCATION STATIQUE !!!
	string requete;		// nom de la requête (GET, POST..)
	string date;		// informations de date
	int heureLocale;	//heure locale
	int decalage;		//decalage par rapport à Greenwich
	int heureGreenwich;	//heure de Greenwich
	size_t debut = log.find(SEP_REQ);
	size_t fin = log.find(SEP, debut);
	if (debut != fin)
	{
		requete = log.substr(debut, fin);
	}
	else
	{
		//ERREUR
	}
	debut = log.find(SEP_DATE_DEBUT);
	fin = log.find(SEP_DATE_FIN);
	if (debut != fin)
	{
		date = log.substr(debut, fin);
	}
	else
	{
		//ERREUR
	}
	debut = date.find(SEP_HEURE);
	fin = date.find(SEP_HEURE, debut);
	heureLocale = stoi(date.substr(debut, fin));

	debut = date.find(SEP, fin);
	string::iterator itFin = date.end();
	fin = distance(date.begin(), itFin);

	decalage = stoi(date.substr(debut, fin));
	heureGreenwich = heureLocale - decalage;

	pair<map<string, list<Log>>::iterator, bool> insertion;
	list<Log> listeLogs;
	listeLogs.push_back(nouveauLog);
	pair<string, list<Log>> aInserer = { requete, listeLogs };	// créér une paire pour l'insertion
	insertion = lesLogs[heureGreenwich].insert(aInserer);	//tentative d'insertion, on récupère le résultat
	if (!insertion.second)	//si la liste existait déjà dans la map
	{
		lesLogs[heureGreenwich].find(requete)->second.push_back(nouveauLog);	//on ajoute le nouveau log à la liste
		return 0;
	}


	return 1;
}	//fin de Ajouter

int Cible::Compte(const string & requete,  const int h)
// Algorithme :
//
{
	int compte = 0;	//variable de retour
	map<string, list<Log>>::iterator it;	//itérateur pour le parcours de la map
	list<Log>::iterator itListe;	//itérateur pour le parcours des listes

	if (h == -1)	//pas d'option h
	{
		for (int heure = 0; heure < 24; heure++)
		{
			it = lesLogs[heure].find(requete);
			if (it != lesLogs[heure].end())	//si la requete est présente dans le dictionnaire
			{
					compte += it->second.size();
			}
		}
	}
	else	//option h spécifiée
	{
		it = lesLogs[h].find(requete);
		if (it != lesLogs[h].end())	//si la requete est présente dans le dictionnaire
		{
			compte += it->second.size();
		}
	}
	return compte;
}	//fin de Compte

/*//------------------------------------------------- Surcharge d'opérateurs
Cible & Cible::operator = ( const Cible & unCible )
// Algorithme :
//
{
} //----- Fin de operator =

*/
//-------------------------------------------- Constructeurs - destructeur
Cible::Cible(const Cible & unCible)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Cible>" << endl;
#endif
	lesLogs = new map<string, list<Log>>[NB_HEURES];
} //----- Fin de Cible (constructeur de copie)


Cible::Cible()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Cible>" << endl;
#endif
} //----- Fin de Cible


Cible::~Cible()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Cible>" << endl;
#endif
	delete[] lesLogs;
} //----- Fin de ~Cible


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
