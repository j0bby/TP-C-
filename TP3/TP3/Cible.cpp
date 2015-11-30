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
#include <Cible.h>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


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
} //----- Fin de ~Cible


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
