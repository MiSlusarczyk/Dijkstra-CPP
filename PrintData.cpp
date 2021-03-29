/** @file  */

#include "PrintData.h"

/**
Konstruktor domyœlny klasy PrintData
*/
PrintData::PrintData()
{
	G = nullptr;
	P = nullptr;
	S = nullptr;
	D = nullptr;
}

/**
Jednoargumentowy konstruktor klasy PrintData
@param DATA WskaŸnik na obiekt typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
*/
PrintData::PrintData(Data* DATA)
{
	G = DATA->G;
	P = DATA->P;
	S = DATA->S;
	D = DATA->D;
}

/**
Publiczna metoda wyswietlajaca dane wejœciowe na ekranie
@param DATA WskaŸnik na obiekt typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool PrintData::PrintDijkstra()
{
	if (D == nullptr)
	{
		std::cout << C("Brak danych do wyœwietlenia!") << std::endl;
		return false;
	}
	else
	{
		DataTops* t_D = D;

		std::cout << C("Dane wejœciowe:") << std::endl << std::endl;

		while (t_D != nullptr)
		{
			std::cout << t_D;

			t_D = t_D->pNext;
		}

		std::cout << std::endl << std::endl;

		return true;
	}
}