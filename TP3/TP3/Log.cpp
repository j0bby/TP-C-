/*************************************************************************
Log  -  description
-------------------
d�but                : 23/11/2015
copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- R�alisation de la classe <Log> (fichier Log.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes
const char SEP = ' ', SEP_DATE = ']', SEP_REQ = '"';
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

//------------------------------------------------- Surcharge d'op�rateurs

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

		posDebut = 0; // le d�but est toujours au d�but de la chaine.

					  // r�cup�ration de l'IP
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouv�
		{
			IP = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie trait�e
		}
		else										// SEP non trouv�
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// r�cup�ration user
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouv�
		{
			user = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie trait�e
		}
		else										// SEP non trouv�
		{
			cerr << "[LOG] erreur dans <user> : " << log << endl;
			return;
		}

		// r�cup�ration logname
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouv�
		{
			logname = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie trait�e
		}
		else										// SEP non trouv�
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		//r�cup�ration date
		if ((posFin = log.find(SEP_DATE)) != string::npos)// SEP_DATE trouv�
		{
			date = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 2); 	//on supprime la partie trait�e
												//on suprime bien SEP_DATE et SEP qui le suit
		}
		else										// SEP-DATE non trouv�
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// on enleve la partie requete
		if ((posFin = log.find(SEP_REQ)) != string::npos)	// SEP_REQ trouv�
		{
			log.erase(posDebut, posFin + 2); //on supprime la partie concernant la requete
		}
		else										// SEP_REQ non trouv�
		{
			cerr << "[LOG] erreur dans <requ�te> : " << log << endl;
			return;
		}

		// r�cup�ration statut
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouv�
		{
			statut = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie trait�e
		}
		else										// SEP non trouv�
		{
			cerr << "[LOG] erreur dans <statut> : " << log << endl;
			return;
		}

		// r�cup�ration taille
		if ((posFin = log.find(SEP)) != string::npos)		// SEP trouv�
		{
			taille = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie trait�e et le s�parateur
		}
		else										// SEP non trouv�
		{
			cerr << "[LOG] erreur dans <taille> : " << log << endl;
			return;
		}

		// r�cup�ration referer
		if ((posFin = log.find(SEP_REQ)) != string::npos)	//SEP_REQ trouv�
		{
			referer = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 2); //on supprime la partie trait�e
		}
		else										// SEP_REQ non trouv�
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// r�cup�ration navigateur
		if ((posFin = log.find(SEP_REQ)) != string::npos)	// SEP trouv�
		{
			navigateur = log.substr(posDebut, posFin);
			log.erase(posDebut, posFin + 1); //on supprime la partie trait�e
		}
		else										// SEP non trouv�
		{
			cerr << "[LOG] erreur dans <ip> : " << log << endl;
			return;
		}

		// tous les attributs sont initialis�s

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

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es
