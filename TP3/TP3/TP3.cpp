#include <string>
#include <iostream>
using namespace std;

static bool e = false, g = false; 
static int t = -1;
static string ficGraphe;
const char *EOPT = "-e";
const char *TOPT = "-t";
const char *GOPT = "-g";
const string EXTLOG = ".log";

int main(int argc, char* argv[])
{
	/*traitement des options*/
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], EOPT) == 0)	//test si c'est l'option e
		{
			e = true;
		}
		else if (i + 1 < argc && strcmp(argv[i], TOPT) == 0)	//test si option t et argument suivant
		{
			if (atoi(argv[i+1]) >= 0 && atoi(argv[i+1]) < 24)
			{
				t = atoi(argv[i+1]);
			}
		}
		else if (i + 1 < argc && strcmp(argv[i], GOPT) == 0)	//test si option g et argument suivant
		{
			ficGraphe = string(argv[i + 1]);
			if (ficGraphe.find(EXTLOG) != string::npos)
			{
				g = true;
			}
		}
	}

#ifdef MAP
	cout << "e = " << e << endl;
	cout << "t = " << t << endl;
	cout << "g = " << g << endl;
	cout << "nom graphe = " << ficGraphe << endl;
	string virsolvy;
	cin >> virsolvy;
#endif

	return 0;

}