/** @file  */

#include "PrintGraph.h"

/**
Konstruktor domy�lny klasy PrintGraph
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
@param DATA Wska�nik na obiekt typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
*/
PrintGraph::PrintGraph(Data* DATA)
{
	G = DATA->G;
	P = DATA->P;
	S = DATA->S;
	D = DATA->D;
}

/**
Publiczna metoda wyswietlaj�ca graf na ekranie
@param DATA Wska�nik na obiekt typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool PrintGraph::PrintDijkstra()
{
	Graph* t_G = G;
	if (G == nullptr)
	{
		std::cout << C("Brak grafu do wy�wietlenia!") << std::endl;
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

