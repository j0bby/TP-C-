/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ------
#if ! defined ( LOG_H )
#define LOG_H
#include <string>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//
// Il s'agit de la classe stockant l'équivalent d'un log.
// On y retrouve toutes les informations excepté le type de requête (GET, POST…)
// et l'adresse cible (pour éviter des redondances).
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog ); // déclaré mais non défini pour empécher son utilisation
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Log ( const Log & unLog ); // déclaré mais non défini pour empécher son utilisation
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log (const string &log );
    // Mode d'emploi :
    // découpe la string correspondant à un log et initialise les attributs.
    // Vérifie si la string est du bon format, si non, renvoie un message d'erreur (sortie erreur).
	//
    // Contrat :
    //

    virtual ~Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    string IP; 		// l'adresse IP à l'origine de la requête
    string logname;		// le nom d'utilisateur du visiteur
	string user;		// le nom d'utilisateur authentifié
    string date; 		// la date de la requête, ainsi que le décalage par rapport à Greenwich
    string statut; 		// le retour de la requête HTML
	string taille; 		// quantité de données transférées en octets
    string referer; 	// adresse depuis laquelle a été émise la requête
    string navigateur; 	// infos navigateur

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies
	friend class Graphe;
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Log>

#endif // LOG_H
