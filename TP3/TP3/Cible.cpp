/*************************************************************************
Cible  -  description
-------------------
d�but                : 2015
copyright            : (C) 2015 par mfallouh mvirsolvy
*************************************************************************/

//---------- R�alisation de la classe <Cible> (fichier Cible.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <map>
#include <string>
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Cible.h"
//------------------------------------------------------------- Constantes
extern const int NB_HEURES;
extern const char SEP_REQ, SEP, SEP_DATE_DEBUT, SEP_DATE_FIN, SEP_HEURE;
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques


int Cible::Ajouter(const string & log)
// Algorithme :
//
{
	
	Log nouveauLog = Log(log);				//			!!!VERIFIER SI CA MARCHE AVEC ALLOCATION STATIQUE !!!
	string requete;		// nom de la requ�te (GET, POST..)
	string date;		// informations de date
	int heureLocale;	//heure locale
	int decalage;		//decalage par rapport � Greenwich
	int heureGreenwich;	//heure de Greenwich
	size_t debut = log.find(SEP_REQ) +1;
	size_t fin = log.find(SEP, debut);
	if (debut != fin)
	{
		requete = log.substr(debut, fin - debut);
	}
	else
	{
		//ERREUR
	}
	debut = log.find(SEP_DATE_DEBUT) +1;
	fin = log.find(SEP_DATE_FIN);
	if (debut != fin)
	{
		date = log.substr(debut +1, fin - debut);
	}
	else
	{
		//ERREUR
	}
	debut = date.find(SEP_HEURE) +1;
	fin = date.find(SEP_HEURE, debut);
	heureLocale = stoi(date.substr(debut, fin - debut));

	debut = date.find(SEP, fin) +1;
	string::iterator itFin = date.end();
	fin = distance(date.begin(), itFin);

	decalage = stoi(date.substr(debut, fin - debut)) / 100;
	heureGreenwich = heureLocale - decalage;


#ifdef MAP
	cout << "Insertion du log -- heure = " << heureGreenwich << endl;
#endif


	pair<map<string, list<Log>>::iterator, bool> insertion;
	list<Log> listeLogs;
	listeLogs.push_back(nouveauLog);
	pair<string, list<Log>> aInserer = { requete, listeLogs };	// cr��r une paire pour l'insertion
	insertion = lesLogs[heureGreenwich].insert(aInserer);	//tentative d'insertion, on r�cup�re le r�sultat
	if (!insertion.second)	//si la liste existait d�j� dans la map
	{
		lesLogs[heureGreenwich].find(requete)->second.push_back(nouveauLog);	//on ajoute le nouveau log � la liste
#ifdef MAP
		cout << "Requete " << requete << " deja presente pour la Cible, ajout a la liste" << endl;
#endif
		return 0;
	}

#ifdef MAP
	cout << "Nouvelle requete trouvee: " << requete << ", ajout a la Cible" << endl;
#endif

	return 1;
}	//fin de Ajouter

int Cible::Compte(const string & requete,  const int h) const
// Algorithme :
//
{
	int compte = 0;	//variable de retour
	list<Log>::iterator itListe;	//it�rateur pour le parcours des listes

	if (h == -1)	//pas d'option h
	{
		for (int heure = 0; heure < 24; heure++)
		{
			if (lesLogs[heure].find(requete) != lesLogs[heure].end())	//si la requete est pr�sente dans le dictionnaire
			{
					compte += lesLogs[heure].find(requete)->second.size();
			}
		}
	}
	else	//option h sp�cifi�e
	{
		if (lesLogs[h].find(requete) != lesLogs[h].end())	//si la requete est pr�sente dans le dictionnaire
		{
			compte += lesLogs[h].find(requete)->second.size();
		}
	}
	return compte;
}	//fin de Compte

/*//------------------------------------------------- Surcharge d'op�rateurs
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
} //----- Fin de ~Cible


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es
