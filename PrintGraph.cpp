/** @file  */

#include "PrintGraph.h"

/**
Konstruktor domyœlny klasy PrintGraph
*/
PrintGraph::PrintGraph()
{
	G = nullptr;
	P = nullptr;
	S = nullptr;
	D = nullptr;
}

/**
Jednoargumentowy konstruktor klasy PrintGraph
@param DATA WskaŸnik na obiekt typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
*/
PrintGraph::PrintGraph(Data* DATA)
{
	G = DATA->G;
	P = DATA->P;
	S = DATA->S;
	D = DATA->D;
}

/**
Publiczna metoda wyswietlaj¹ca graf na ekranie
@param DATA WskaŸnik na obiekt typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool PrintGraph::PrintDijkstra()
{
	Graph* t_G = G;
	if (G == nullptr)
	{
		std::cout << C("Brak grafu do wyœwietlenia!") << std::endl;
		return false;
	}
	else
	{
		std::cout << C("Opis grafu:") << std::endl << std::endl;

		while (t_G != nullptr)
		{
			std::cout << t_G;

			t_G = t_G->pNext;
		}

		std::cout << std::endl << std::endl;

		return true;
	}
}

