/** @file  */

#include "Save.h"

/**
Publiczna metoda s�u��ca do czyszczenia pliku przed zapisem danych
@param DATA Wska�nik na referencje do obiektu  typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Save::ClearFile(Data* DATA)
{
	std::ofstream FILE;

	FILE.open(DATA->P->paths[2].c_str(), std::ios::out);

	FILE.close();

	return true;
}

/**
Publiczna metoda zapisuj�ca graf do pliku wynikowego
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Save::SaveGraph(Data* DATA)
{
	std::ofstream FILE;

	if (DATA->P->Qsaved == true || DATA->P->Qsaves == true)
	{
		FILE.open(DATA->P->paths[2].c_str(), std::ios::app);
	}
	else
	{
		FILE.open(DATA->P->paths[2].c_str(), std::ios::out);
	}

	if (FILE.fail())
	{
		return false;
	}
	else
	{
		Graph* t_G = DATA->G;

		FILE << C("Opis grafu:") << std::endl << std::endl;

		while (t_G != nullptr)
		{
			FILE << t_G;

			t_G = t_G->pNext;
		}

		FILE << std::endl;
	}

	FILE.close();

	return true;
}

/**
Publiczna metoda zapisuj�ca dane do pliku wynikowego
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Save::SaveData(Data* DATA)
{
	std::ofstream FILE;

	if (DATA->P->Qsaveg == true || DATA->P->Qsaves == true)
	{
		FILE.open(DATA->P->paths[2].c_str(), std::ios::app);
	}
	else
	{
		FILE.open(DATA->P->paths[2].c_str(), std::ios::out);
	}

	if (FILE.fail())
	{
		return false;
	}
	else
	{
		DataTops* t_D = DATA->D;

		FILE << C("Dane wejsciowe:") << std::endl << std::endl;

		while (t_D != nullptr)
		{
			FILE << t_D;

			t_D = t_D->pNext;
		}

		FILE << std::endl;
	}

	FILE.close();

	return true;
}

/**
Publiczna metoda zapisuj�ca rozwi�zanie do pliku wynikowego
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Save::SaveSolution (Data* DATA)
{
	std::ofstream FILE;

	if (DATA->P->Qsaved == true || DATA->P->Qsaveg == true)
	{
		FILE.open(DATA->P->paths[2].c_str(), std::ios::app);
	}
	else
	{
		FILE.open(DATA->P->paths[2].c_str(), std::ios::out);
	}

	if (FILE.fail())
	{
		return false;
	}
	else
	{
		Solution* t_S = DATA->S;

		FILE << C("Rozwiazanie:") << std::endl << std::endl;

		while (t_S != nullptr)
		{
			FILE << t_S;

			t_S = t_S->pNext;
		}

		FILE << std::endl;
	}

	FILE.close();

	return true;
}