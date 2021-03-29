/** @file  */

#include "Algorithm.h"

/**
Publiczna metoda przygotowuj�ca struktur� listy kt�ra p�niej ma przechowywac rozwi�zanie
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst apieniu ewentualnego b��du
*/
bool Algorithm::PrepareSolution(Data*& DATA)
{
	if (DATA == nullptr)
	{
		return false;

	}
	else
	{
		DataTops* t_D = DATA->D;

		while (t_D != nullptr)
		{
			Solution* t_S = new Solution;

			Primal* t_P = new Primal;
			t_P->number = t_D->top->number;
			Primal::AddPrimalByNumber(t_S->start, t_P);

			Primal* t_Dtops = t_D->Dtops;

			while (t_Dtops != nullptr)
			{
				Branch* t_Branch = new Branch;
				t_Branch->end = new Borderer;

				t_Branch->end->number = t_Dtops->number;

				Branch::AddBranchByEnd(t_S->branch, t_Branch);
				t_Branch = nullptr;

				t_Dtops = t_Dtops->pNext;
			}

			t_Dtops = nullptr;
			Solution::AddSolutionByStart(DATA->S, t_S);

			t_D = t_D->pNext;
		}

		return true;
	}
}

/**
Publiczna metoda realizuj�ca algorytm Dijkstry
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst apieniu ewentualnego b��du
*/
bool Algorithm::Dijkstra(Data*& DATA)
{
	if (DATA == nullptr)
	{
		std::cout << "Brak danych do realizacji algorytmu Dijkstry!" << std::endl;
		return false;
	}
	else
	{
		bool error = true;

		error = PrepareSolution(DATA);
		if(error == false)
		{
			return false;
		}

		Solution* t_S = DATA->S;

		while (t_S != nullptr)
		{
			Primal* S = nullptr;
			Primal* Q = nullptr;
			DataTops::CreatePrimalList(Q, DATA->D);

			Predecessor* d = nullptr;
			Predecessor::PreparePredecessor(d, Q, t_S->start->number);

			while (Q != nullptr)
			{
				Predecessor* t_P = Predecessor::FindPredecessorByLowerCost(d, Q);
				t_P->pNext = nullptr;
				t_P->pPrev = nullptr;

				Primal::DeletePrimalByNumber(Q, t_P->number);
				Primal::AddPrimalByNumber(S, t_P);

				Predecessor::CompletePredecessor(d, Q, t_P->number, DATA->G);
			}

			error = CreateSolution(t_S, d);
			if (error == false)
			{
				return false;
			}

			d->DeletePredecessorList();
			d = nullptr;

			t_S = t_S->pNext;
		}

		return true;
	}
}

/**
Publiczna metoda uzupe�niaj�ca rozwi�zanie na podstawie dzia�ania algorytmu Dijkstry
@param DATAWska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@param P Wska�nik na list� obiekt�w typu Predecessor w kt�rej przechowywany jest wynik dzia�ania algorytmu Dijkstry
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Algorithm::CreateSolution(Solution*& S, Predecessor* P)
{
	if (S == nullptr || P == nullptr)
	{
		return false;
	}
	else
	{
		Branch* t_B = S->branch;

		while (t_B != nullptr)
		{
			Predecessor* t_P = P;
			while (t_P->number != t_B->end->number)
			{
				t_P = t_P->pNext;
			}

			t_B->end->metrics = t_P->metrics;

			while (t_P->predecessor != -1)
			{
				Primal* p_P = new Primal;
				p_P->number = t_P->predecessor;

				Primal::AddPrimalFront(t_B->way, p_P);
				t_P = Predecessor::FindPredecessorByNumber(P, t_P->predecessor);
			}

			t_B = t_B->pNext;
		}

		return true;
	}
}