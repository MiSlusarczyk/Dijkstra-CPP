/** @file  */

#include "Management.h"


/**
Konstruktor domyœlny klasy Management
*/
Management::Management()
{
	P = nullptr;
	G = nullptr;
	D = nullptr;
	S = nullptr;
}

/**
Konstruktor z argumentem bêd¹cym œcie¿k¹ do plików wejœcia/wyjœcia
@param p Tablica typu string przechowuj¹ca œcie¿ki do plików wejœcia/wyjœcia
*/
Management::Management(std::string p[])
{
	P = new Parameters(p);

	G = nullptr;
	D = nullptr;
	S = nullptr;

	Data* DATA = new Data(P, G, D, S);

	bool error = true;

	error = Coordinate(DATA);
	if (error == false)
	{
		std::cout << C("RAPORT B£ÊDÓW:") << std::endl << std::endl;
		std::cout << C("Wyst¹pi³ b³¹d podczas wykonywania programu!") << std::endl;
	}


	delete DATA;
	DATA = nullptr;
}

/**
Konstruktor z argumentem bêd¹cym œcie¿k¹ do plików wejœcia/wyjœcia
@param DATA WskaŸnik na referencje do obiektu typu Data w którym przechowywane s¹ wszystkie inne obiekty na których operuje program
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Management::Coordinate(Data*& DATA)
{
	bool error = true;

	std::cout << C("::ALGORYTM DIJKSTRY::");

	Sleep(5000);

	system("cls");

	User* U = new User();

	U->Calibration(DATA, DATA->P->paths);
	error = U->Ask(DATA);
	if (error == false)
	{
		std::cout << C("Wyst¹pi³ b³¹d podczas komunikacji z u¿ytkownikiem!") << std::endl;
		return false;
	}

	delete U;

	Create* CR = new Create();

	if (DATA->P->Qgrapho == false)
	{
		error = CR->LoadGraph(DATA);
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas wczytywania grafu!") << std::endl;
			return false;
		}
	}
	else if (DATA->P->Qgrapho == true)
	{
		error = CR->CreateGraph(DATA);
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas tworzenia grafu!") << std::endl;
			return false;
		}
	}

	if (DATA->P->QIOo == false)
	{
		error = CR->LoadData(DATA);
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas wczytywania danych!") << std::endl;
			return false;
		}
	}
	else if (DATA->P->QIOo == true)
	{
		error = CR->CreateData(DATA);
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas tworzenia danych!") << std::endl;
			return false;
		}
	}

	delete CR;


	Print* pPrint;
	PrintGraph* PG = new PrintGraph(DATA);
	PrintData* PD = new PrintData(DATA);

	if (DATA->P->Qshowg == true)
	{
		pPrint = PG;
		error = pPrint->PrintDijkstra();
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas wyœwietlania grafu!") << std::endl;
			return false;
		}
	}

	if (DATA->P->Qshowd == true)
	{
		pPrint = PD;
		error = pPrint->PrintDijkstra();
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas wyœwietlania danych!") << std::endl;
			return false;
		}
	}

	Algorithm* A = new Algorithm();

	error = A->Dijkstra(DATA);
	if (error == false)
	{
		std::cout << C("Wyst¹pi³ b³¹d podczas realizacji algorytmu Dijkstry!") << std::endl;
		return false;
	}

	delete A;

	Save* SA = new Save();

	if (DATA->P->Qsaved || DATA->P->Qsaveg || DATA->P->Qsaves)
	{
		error = SA->ClearFile(DATA);
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas czyszczenia pliku z rozwi¹zaniem!") << std::endl;
			return false;
		}
	}

	if (DATA->P->Qsaveg)
	{
		error = SA->SaveGraph(DATA);
		if (error == false)
		{
			std::cout << C("Wyst¹pi³ b³¹d podczas zapisu grafu w pliku wynikowym!") << std::endl;
			return false;
		}
	}

	if (DATA->P->Qsaved)
	{
		error = SA->SaveData(DATA);
		if (error == false)
		{
			std::cout << "Wyst¹pi³ b³¹d podczas zapisu danych w pliku wynikowym!" << std::endl;
			return false;
		}
	}

	if (DATA->P->Qsaves)
	{
		error = SA->SaveSolution(DATA);
		if (error == false)
		{
			std::cout << "Wyst¹pi³ b³¹d podczas zapisu rozwi¹zania w pliku wynikowym!" << std::endl;
			return false;
		}
	}

	delete SA;

	PrintSolution* PS = new PrintSolution(DATA);

	if (DATA->P->Qshows == true)
	{
		pPrint = PS;
		error = pPrint->PrintDijkstra();
		if (error == false)
		{
			std::cout << "Wyst¹pi³ b³¹d podczas wyœwietlania rozwiaz¹nia!" << std::endl;
			return false;
		}
	}

	return true;
}