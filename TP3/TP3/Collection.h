/*************************************************************************
Collection  -  description
-------------------
d�but                : 2015
copyright            : (C) 2015 par mfallouh_mvirsolvy
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <map>
#include "Cible.h"
using namespace std;
//------------------------------------------------------------- Constantes 
const string EXCLUSIE[] = { (string)"jpg", (string)"png", (string)"tga", (string)"gif", (string)"jpeg", (string)"bmp", (string)"js",(string)"css", (string)"ico" };	//extensions � exclure si option e sp�cifi�e
const int NB_EXTENSIONS = 9;	//nombre d'extensions bannies
																																						//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Collection>
// Cette classe contient un arbre de Cible, identifi�es par leur adresse.
// Elle regroupe les donn�es correspondant � un fichier de logs.
//
//------------------------------------------------------------------------ 
class Collection
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	
	void Top10(const bool e = false, const int t = -1) const;
	// Mode d'emploi :
	// Affiche dans la console les 10 documents les plus consult�s.
	// Si jamais il y des �galit�s qui ne sortiraient pas si l�on n�affichait
	// que 10 r�sultats, on affiche exceptionnellement davantage de r�sultats.
	// Si la collection comporte moins de 10 cibles, n�affiche que les 
	// cibles pr�sentes dans la collection.
	// Prend en compte les options e et t pour filtrer l�affichage.
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'op�rateurs
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
	// cr�e une Collection � partir d�un nom de fichier.
	// Si le fichier n�est pas trouv�, affiche un message d�erreur. 
	// Contrat :
	//

	virtual ~Collection();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	map<string , Cible > pages;	// le dictionnaire de Cible
private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies
	friend class Graphe;
	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Collection>

#endif // COLLECTION_H
