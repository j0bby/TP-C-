/*************************************************************************
Log  -  description
-------------------
début                : 23/11/2015
copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes
const char SEP = ' ', SEP_DATE = ']', SEP_REQ = '"';
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

/*
Log & Log::operator = ( const Log & unLog )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur

/*
Log::Log ( const Log & unLog )
// Algorithme :
//
{
#ifdef MAP
cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
} //----- Fin de Log (constructeur de copie)
*/

Log::Log(const string &log)
// Algorithme :
//
{
#ifdef MAP
	//cout << "Appel au constructeur de <Log>" << endl;
#endif
	if (log.empty()) // chaine vide
	{
		cerr << "[LOG] le log est vide " << endl;
		return;
	}
	else
	{
		size_t posDebut, posFin;

		posDebut = 0; // le début est toujours au début de la chaine.

					  // récupération de l'IP
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouvé
		{
			IP = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie traitée
		}
		else										// SEP non trouvé
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// récupération user
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouvé
		{
			user = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie traitée
		}
		else										// SEP non trouvé
		{
			cerr << "[LOG] erreur dans <user> : " << log << endl;
			return;
		}

		// récupération logname
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouvé
		{
			logname = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie traitée
		}
		else										// SEP non trouvé
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		//récupération date
		if ((posFin = log.find(SEP_DATE)) != string::npos)// SEP_DATE trouvé
		{
			date = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 2); 	//on supprime la partie traitée
												//on suprime bien SEP_DATE et SEP qui le suit
		}
		else										// SEP-DATE non trouvé
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// on enleve la partie requete
		if ((posFin = log.find(SEP_REQ)) != string::npos)	// SEP_REQ trouvé
		{
			log.erase(posDebut, posFin + 2); //on supprime la partie concernant la requete
		}
		else										// SEP_REQ non trouvé
		{
			cerr << "[LOG] erreur dans <requête> : " << log << endl;
			return;
		}

		// récupération statut
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouvé
		{
			statut = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie traitée
		}
		else										// SEP non trouvé
		{
			cerr << "[LOG] erreur dans <statut> : " << log << endl;
			return;
		}

		// récupération taille
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouvé
		{
			taille = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie traitée et le séparateur
		}
		else										// SEP non trouvé
		{
			cerr << "[LOG] erreur dans <taille> : " << log << endl;
			return;
		}

		// récupération referer
		if ((posFin = log.find(SEP_REQ)) != string::npos)	//SEP_REQ trouvé
		{
			referer = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 2); //on supprime la partie traitée
		}
		else										// SEP_REQ non trouvé
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// récupération navigateur
		if ((posFin = log.find(SEP_REQ)) != string::npos)	// SEP trouvé
		{
			navigateur = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie traitée
		}
		else										// SEP non trouvé
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// tous les attributs sont initialisés

		if (!log.empty())	// la chaine n'est pas vide
		{
			cerr << "[LOG] erreur de remplissage, il reste: ";
			cerr << log << endl;
		}
	} // fin du traitement sans erreur

} //----- Fin de Log


Log::~Log()
// Algorithme :
//
{
#ifdef MAP
	//cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
