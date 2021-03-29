/** @file  */

#include "User.h"

/**
Publiczna metoda przygotowujac¹ podstawowe dane na podstawie informacji uzyskanych z konsoli
@param DATA WskaŸnik na referencje do obiektu typu Data w który przechowywane s¹ wszystkie inne obiekty na których operuje program
@param p Tablica typu string przechowuj¹ca œcie¿ki do plików wejœcia/wyjœcia
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool User::Calibration(Data*& DATA, std::string p[])
{
	size_t size = sizeof(DATA->P->paths) / sizeof(std::string);

	for (size_t i = 0; i < size; i++)
	{
		DATA->P->paths[i] = p[i];
	}

	if (DATA->P->paths[0] != "\0")
	{
		DATA->P->Qgraph = 1;
	}
	else
	{
		DATA->P->Qgraph = 0;
	}

	if (DATA->P->paths[1] != "\0")
	{
		DATA->P->QIO = 1;
	}
	else
	{
		DATA->P->QIO = 0;
	}

	if (DATA->P->paths[2] != "\0")
	{
		DATA->P->Qsave = 1;
	}
	else
	{
		DATA->P->Qsave = 0;
	}

	return true;
}


/**
Publiczna metoda do komunikacji z u¿ytkownikiem w której przekazywane s¹ preferencje na temat tego jak ma dzia³aæ program
@param DATA WskaŸnik na referencje do obiektu typu Data w który przechowywane s¹ wszystkie inne obiekty na których operuje program
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool User::Ask(Data*& DATA)
{

	std::string answer = "\0";
	std::string addition1 = "./";
	std::string addition2 = ".txt";

	if (DATA->P->Qgraph == 0)
	{
		answer = "\0";

		std::cout << C("Czy chcesz opisaæ graf sam?") << std::endl;
		std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli chcesz podaæ nazwê pliku w folderze projektu: ");
		std::cin >> answer;

		system("cls");

		if (answer == "Nie")
		{
			std::cout << C("Podaj nazwê pliku z opisem grafu: ");
			std::cin >> DATA->P->paths[0];

			DATA->P->paths[0] = addition1 + DATA->P->paths[0];

			if (DATA->P->paths[0].find(addition2, 0) == std::string::npos)
			{
				DATA->P->paths[0] = DATA->P->paths[0] + addition2;
			}

		}
		else if (answer == "Tak")
		{
			DATA->P->Qgrapho = 1;
		}
		else
		{
			std::cout << C("B³êdna odpowiedŸ!") << std::endl;
			return false;
		}

		DATA->P->Qgraph = 1;
	}

	system("cls");

	if (DATA->P->QIO == 0)
	{
		answer = "\0";

		std::cout << C("Czy chcesz wprowadziæ dane sam?") << std::endl;
		std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli chcesz podaæ nazwê pliku w folderze projektu: ");
		std::cin >> answer;

		system("cls");

		if (answer == "Nie")
		{
			std::cout << C("Podaj nazwê pliku z danymi: ");
			std::cin >> DATA->P->paths[1];

			DATA->P->paths[1] = addition1 + DATA->P->paths[1];

			if (DATA->P->paths[1].find(addition2, 0) == std::string::npos)
			{
				DATA->P->paths[1] = DATA->P->paths[1] + addition2;
			}

			system("cls");

		}
		else if (answer == "Tak")
		{
			DATA->P->QIOo = 1;
		}
		else
		{
			std::cout << C("B³êdna odpowiedŸ!") << std::endl;
			return false;
		}

		DATA->P->QIO = 1;
	}

	if (DATA->P->Qsave == 0)
	{
		std::cout << C("Brak œcie¿ki pliku w którym zapisane ma byæ rozwi¹zanie!") << std::endl << std::endl;
		std::cout << C("Podaj nazwê pliku do zapisu: ");
		std::cin >> DATA->P->paths[2];

		DATA->P->paths[2] = addition1 + DATA->P->paths[2];

		if (DATA->P->paths[2].find(addition2, 0) == std::string::npos)
		{
			DATA->P->paths[2] = DATA->P->paths[2] + addition2;
		}

		DATA->P->Qsave = 1;
	}

	system("cls");

	answer = "\0";

	std::cout << C("Czy chcesz zapisaæ graf do pliku wyjœcowego?") << std::endl;
	std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli nie chcesz: ");
	std::cin >> answer;

	if (answer == "Tak")
	{
		DATA->P->Qsaveg = 1;
	}
	else if (answer == "Nie")
	{
		DATA->P->Qsaveg = 0;
	}
	else
	{
		std::cout << C("B³êdna odpowiedŸ!") << std::endl;
		return false;
	}


	system("cls");


	answer = "\0";

	std::cout << C("Czy chcesz zapisaæ dane do pliku wyjœciowego?") << std::endl;
	std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli nie chcesz: ");
	std::cin >> answer;

	if (answer == "Tak")
	{
		DATA->P->Qsaved = 1;
	}
	else if (answer == "Nie")
	{
		DATA->P->Qsaved = 0;
	}
	else
	{
		std::cout << C("B³êdna odpowiedŸ!") << std::endl;
		return false;
	}

	system("cls");

	answer = "\0";

	std::cout << C("Czy chcesz zapisaæ rozwi¹zanie do pilku wyjœciowego?") << std::endl;
	std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli nie chcesz: ");
	std::cin >> answer;

	if (answer == "Tak")
	{
		DATA->P->Qsaves = 1;
	}
	else if (answer == "Nie")
	{
		DATA->P->Qsaves = 0;
	}
	else
	{
		std::cout << C("B³êdna odpowiedŸ!") << std::endl;
		return false;
	}

	system("cls");

	answer = "\0";

	std::cout << C("Czy chcesz wyœwietliæ graf w konsoli?") << std::endl;
	std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli nie chcesz: ");
	std::cin >> answer;

	if (answer == "Tak")
	{
		DATA->P->Qshowg = 1;
	}
	else if (answer == "Nie")
	{
		DATA->P->Qshowg = 0;
	}
	else
	{
		std::cout << C("B³êdna odpowiedŸ!") << std::endl;
		return false;
	}

	system("cls");


	answer = "\0";

	std::cout << C("Czy chcesz wyœwietliæ dane w konsoli?") << std::endl;
	std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli nie chcesz: ");
	std::cin >> answer;

	if (answer == "Tak")
	{
		DATA->P->Qshowd = 1;
	}
	else if (answer == "Nie")
	{
		DATA->P->Qshowd = 0;
	}
	else
	{
		std::cout << C("B³êdna odpowiedŸ!") << std::endl;
		return false;
	}

	system("cls");

	answer = "\0";

	std::cout << C("Czy chcesz wyœwietliæ rozwi¹zanie w konsoli?") << std::endl;
	std::cout << C("Jeœli chcesz wpisz 'Tak', a 'Nie' jeœli nie chcesz: ");
	std::cin >> answer;

	if (answer == "Tak")
	{
		DATA->P->Qshows = 1;
	}
	else if (answer == "Nie")
	{
		DATA->P->Qshows = 0;
	}
	else
	{
		std::cout << C("B³êdna odpowiedŸ!") << std::endl;
		return false;
	}

	system("cls");

	return true;
}
