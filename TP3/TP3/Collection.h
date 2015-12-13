/*************************************************************************
Collection  -  description
-------------------
début                : 2015
copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Cible.h"
using namespace std;
//------------------------------------------------------------- Constantes 
const string EXCLUSIE[] = { (string)"jpg", (string)"png", (string)"tga", (string)"gif", (string)"jpeg", (string)"bmp", (string)"js",(string)"css", (string)"ico" };	//extensions à exclure si option e spécifiée
const int NB_EXTENSIONS = 9;	//nombre d'extensions bannies
																																						//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Collection>
// Cette classe contient un arbre de Cible, identifiées par leur adresse.
// Elle regroupe les données correspondant à un fichier de logs.
//
//------------------------------------------------------------------------ 
class Collection
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	
	void Top10(const bool e = false, const int t = -1) const;
	// Mode d'emploi :
	// Affiche dans la console les 10 documents les plus consultés.
	// Si jamais il y des égalités qui ne sortiraient pas si l’on n’affichait
	// que 10 résultats, on affiche exceptionnellement davantage de résultats.
	// Si la collection comporte moins de 10 cibles, n’affiche que les 
	// cibles présentes dans la collection.
	// Prend en compte les options e et t pour filtrer l’affichage.
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'opérateurs
	Collection & operator = (const Collection & unCollection);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Collection(const Collection & unCollection);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Collection(const string &nomFichier);
	// Mode d'emploi :
	// crée une Collection à partir d’un nom de fichier.
	// Si le fichier n’est pas trouvé, affiche un message d’erreur. 
	// Contrat :
	//

	virtual ~Collection();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	map<string , Cible > pages;	// le dictionnaire de Cible
private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies
	friend class Graphe;
	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Collection>

#endif // COLLECTION_H
