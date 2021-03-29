/** @file  */

#include "PrintSolution.h"

/**
Konstruktor domyœlny klasy PrintSolution
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
@param DATA WskaŸnik na obiekt typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
*/
PrintSolution::PrintSolution(Data* DATA)
{
	G = DATA->G;
	P = DATA->P;
	S = DATA->S;
	D = DATA->D;
}

/**
Publiczna metoda wyœwietlaj¹ca rozwi¹zanie na ekranie
@param DATA WskaŸnik na obiekt typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool PrintSolution::PrintDijkstra()
{
	Solution* t_S = S;
	if (S == nullptr)
	{
		std::cout << C("Brak danych do wyœwietlenia!") << std::endl;
		return false;
	}
	else
	{
		std::cout << C("Rozwi¹zanie:") << std::endl << std::endl;

		while (t_S != nullptr)
		{
			std::cout << t_S;

			t_S = t_S->pNext;
		}

		std::cout << std::endl << std::endl;

		return true;
	}
}
