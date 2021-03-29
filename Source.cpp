/** @file  */

#include <iostream>
#include <string>
#include <Windows.h>

#include "Management.h"

/*
int main(int argc, char* argv[])
{
	system("cls");

	if (argc == 0)
	{
		std::cout << C("B³¹d podczas uruchamiania programu! Brak lub niepoprawne argument!") << std::endl;
	}
	else if (argc == 1)
	{
		std::cout << C("Œcie¿ka programu: ") << argv[0] << std::endl << std::endl;
		std::cout << C("Brak dodatkowych argumentów!") << std::endl << std::endl;
		std::cout << C("Graf oraz parametry okreœlane przez u¿ytkownika!") << std::endl;

	}
	else
	{
		std::string paths[3];
		for (int i = 0; i < 3; i++)
		{
			paths[i] = "";
		}

		std::cout << C("Dodatkowe argumenty:") << std::endl;

		for (int i = 1; i < argc; i++)
		{
			std::cout << i << C(". ") << argv[i] << std::endl;
		}


		for (int i = 1; i < argc-1; i++)
		{
			if (strcmp(argv[i],C("-G")) == 0)
			{
				std::cout << C("Graf wczytany z pliku!") << std::endl;
				paths[0] = argv[i+1];
			}
			else if (strcmp(argv[i],C("-D")) == 0)
			{
				std::cout << C("Dane algorytmu wczytane z pliku!") << std::endl;
				paths[1] = argv[i + 1];
			}
			else if (strcmp(argv[i],C("-S")) == 0)
			{
				std::cout << C("Œcie¿ka do pliku wynikowego pozyskana z konsoli!") << std::endl;
				paths[2] = argv[i + 1];
			}
		}

		std::string addition1 = "./";
		std::string addition2 = ".txt";

		for (int i = 0; i < 3; i++)
		{
			paths[i] = addition1 + paths[i];

			if (paths[i].find(addition2, 0) == std::string::npos)
			{
				paths[i] = paths[i] + addition2;
			}
		}

		std::cout << std::endl;

		Sleep(5000);

		system("cls");

		Management M(paths);
	}

	return 0;
}
*/

//TESTOWY BEZ WYKORZYSTANIA KONSOLI

int main()
{
	std::string paths[3];

	paths[0] = "./GRAPH.txt";
	paths[1] = "./DATA.txt";
	paths[2] = "./SOLUTION.txt";

	Management M(paths);

	return 0;
}


