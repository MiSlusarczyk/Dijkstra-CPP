/** @file  */

#include "PrintData.h"

/**
Konstruktor domy�lny klasy PrintData
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
@param DATA Wska�nik na obiekt typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
*/
PrintData::PrintData(Data* DATA)
{
	G = DATA->G;
	P = DATA->P;
	S = DATA->S;
	D = DATA->D;
}

/**
Publiczna metoda wyswietlajaca dane wej�ciowe na ekranie
@param DATA Wska�nik na obiekt typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool PrintData::PrintDijkstra()
{
	if (D == nullptr)
	{
		std::cout << C("Brak danych do wy�wietlenia!") << std::endl;
		return false;
	}
	else
	{
		DataTops* t_D = D;

		std::cout << C("Dane wej�ciowe:") << std::endl << std::endl;

		while (t_D != nullptr)
		{
			std::cout << t_D;

			t_D = t_D->pNext;
		}

		std::cout << std::endl << std::endl;

		return true;
	}
}