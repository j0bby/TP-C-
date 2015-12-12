#include <string>
#include <iostream>
using namespace std;

static bool e = false; 
static int h = -1;
const char *EOPT = "-e";
const char *TOPT = "-t";
const char *GOPT = "-g";

int main(int argc, char* argv[])
{
	/*traitement des options d'appel du programme*/
	if (argc == 2)	//option e ou option invalide
	{
		cout << argv[1] << endl; 
		if (strcmp(argv[1], EOPT)==0)	//on vérifie que c'est bien l'option e
		{
			e = true;
		}
	}	//sinon, on ignore l'option
	else if (argc == 3)		//option h ou option invalide
	{
		if (strcmp(argv[1], TOPT) == 0)
		{
			if (atoi(argv[2]) >= 0 && atoi(argv[2]) < 24)
			{
				h = atoi(argv[2]);
			}
		}
	}
	else if (argc == 4)		// e puis h, ou h puis e, ou options (partiellement) invalides
	{
		if (strcmp(argv[1], EOPT) == 0)
		{
			e = true;
			if (strcmp(argv[2], TOPT) == 0)
			{
				if (atoi(argv[3]) >= 0 && atoi(argv[3]) < 24)
				{
					h = atoi(argv[3]);
				}
			}
		}
		else if (strcmp(argv[1], TOPT) == 0)
		{
			if (atoi(argv[2]) >= 0 && atoi(argv[2]) < 24)
			{
				h = atoi(argv[2]);
				if (strcmp(argv[3], EOPT) == 0)
				{
					e = true;
				}
			}
		}
	}
	//fin traitement options



	return 0;

}