#include <string>
#include <iostream>
#include "Cible.h"
#include "Collection.h"
#include "Graphe.h"
#include "Log.h"
using namespace std;

static void testCible();
static void testConstructCible();
static void testAjouterCible();
static void testCompteCible();
static const string logGet = "192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] \"GET / temps / 4IF16.html HTTP / 1.1\" 200 12106 \"http://intranet-if.insa-lyon.fr/temps/4IF15.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";
static const string logPost = "192.168.0.0 - -[08/Sep / 2012:11 : 16 : 07 + 0200] \"POST /temps/4IF20.html HTTP/1.1\" 200 5185 \"http://intranet-if.insa-lyon.fr/temps/4IF19.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";


int main()
{
	cout << "Programme de tests" << endl;
	testCible();
	cout << "Appuyer sur entr�e pour quitter" << endl;
	string zzz;
	cin >> zzz;
	return 0;
}

void testCible()	//batterie de tests de la classe Cible
{
	testConstructCible();
	testAjouterCible();
	testCompteCible();
}

void testConstructCible()
{
	cout << "Test du constructeur et destructeur de Cible" << endl;
	Cible *tcible = new Cible();
	delete tcible;
}

void testAjouterCible()
{
	cout << "Test de Cible::Ajouter" << endl;
	Cible *tcible = new Cible();
	tcible->Ajouter(logGet);
	tcible->Ajouter(logPost);
	delete tcible;
}

void testCompteCible()
{
	cout << "Test de Cible::Compte" << endl;
	Cible *tcible = new Cible();
	tcible->Ajouter(logGet);
	tcible->Ajouter(logGet);
	tcible->Ajouter(logGet);
	tcible->Ajouter(logPost);

	cout << "Comptage des GET -- Reponse attendue : 3" << endl;
	cout << tcible->Compte("GET") << endl;

	cout << "Comptage des GET entre 1 et 2h -- Reponse attendue : 0" << endl;
	cout << tcible->Compte("GET", 1) << endl;

	cout << "Comptage des GET entre 9 et 10h -- Reponse attendue : 3" << endl;
	cout << tcible->Compte("GET", 9) << endl;

	cout << "Comptage des POST -- Reponse attendue : 1" << endl;
	cout << tcible->Compte("POST") << endl;

	cout << "Comptage des Virsolvy -- Reponse attendue : 0" << endl;
	cout << tcible->Compte("Virsolvy") << endl;

	delete tcible;
}