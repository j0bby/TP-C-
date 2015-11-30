/*************************************************************************
                           Cible  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Interface de la classe <Cible> (fichier Cible.h) ------
#if ! defined ( CIBLE_H )
#define CIBLE_H
#include <string>
#include <list>
#include <map>
using namespace std;

#include "Log.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const int NB_HEURES = 24;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cible>
//
// Il s'agit de la classe stockant l'ensemble des logs relatifs à une adresse cible.
// Les données sont organisées par heure de Greenwich et type de requête,
// pour accélérer les traitements.
//
//------------------------------------------------------------------------

class Cible
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int Ajouter(const string &requete, string log);
	// Mode d'emploi :
	// Crée un Log à partir de la string entrée en paramètre.
	// Ajoute ce Log au bon emplacement (bonne heure, bonne requête).
	// Crée au besoin une nouvelle clé (requête) dans la map.
	//
	// Contrat :
	//

	int Compte(const string &requete, const bool e =false , const int h =-1);
	// Mode d'emploi :
	// Compte le nombre de logs consignés correspondant à la requête entrée en paramètre.
	// Tient compte des options e et h pour filtrer les résultats.
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
    Cible & operator = ( const Cible & unCible ); // déclaré mais non défini pour empécher son utilisation
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Cible ( const Cible & unCible ); // déclaré mais non défini pour empécher son utilisation
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cible ( );
    // Mode d'emploi :
    //
	//
    // Contrat :
    //

    virtual ~Cible ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

	map <string, list<Log>> *lesLogs;	// stock des logs. Tableau de 24 cases (1 par heure) 
										// contenant des listes de logs triées par type de requête,
										// par le biais d'une map.

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Cible>

#endif // CIBLE_H
