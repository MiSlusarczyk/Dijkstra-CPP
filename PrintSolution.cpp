/** @file  */

#include "PrintSolution.h"

/**
Konstruktor domy�lny klasy PrintSolution
*/
PrintSolution::PrintSolution()
{
	G = nullptr;
	P = nullptr;
	S = nullptr;
	D = nullptr;
}

/**
Jednoargumentowy konstruktor klasy PrintSolution
@param DATA Wska�nik na obiekt typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
*/
PrintSolution::PrintSolution(Data* DATA)
{
	G = DATA->G;
	P = DATA->P;
	S = DATA->S;
	D = DATA->D;
}

/**
Publiczna metoda wy�wietlaj�ca rozwi�zanie na ekranie
@param DATA Wska�nik na obiekt typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool PrintSolution::PrintDijkstra()
{
	Solution* t_S = S;
	if (S == nullptr)
	{
		std::cout << C("Brak danych do wy�wietlenia!") << std::endl;
		return false;
	}
	else
	{
		std::cout << C("Rozwi�zanie:") << std::endl << std::endl;

		while (t_S != nullptr)
		{
			std::cout << t_S;

			t_S = t_S->pNext;
		}

		std::cout << std::endl << std::endl;

		return true;
	}
}
