/** @file  */

#include "Predecessor.h"

/**
Konstruktor domy�lny klasy Solution
*/
Predecessor::Predecessor()
{
	number = 0;
	metrics = -1;
	predecessor = -1;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci��ony operator przypisania
@param S Referencja do sta�ego obiektu typu Predecessor
@return Referencja do elementu typu Predecessor pozwalaj�ca na kaskadowe wywo�anie
*/
Predecessor& Predecessor::operator=(const Predecessor& P)
{
	if (&P == this)
	{
		return *this;
	}
	else
	{
		number = P.number;
		metrics = P.metrics;
		predecessor = P.predecessor;
		pNext = P.pNext;
		pPrev = P.pPrev;

		return *this;
	}
}

/**
Publiczna metoda przygotowuj�ca liste typu Predecesssor do uzupe�nienia
@param P Wska�nik na list� typu Predecessor
@param PR Wska�nik na list� typu Primal przechow�j�c� numery wszystkich wierzcho�k�w w grafie
@param N Numer wierzcho�ka startowego
@return Referencja do elementu typu Solution pozwalaj�ca na kaskadowe wywo�anie
*/
bool Predecessor::PreparePredecessor(Predecessor*& P, Primal* PR, long int N)
{
	if (PR == nullptr || P!=nullptr)
	{
		return false;
	}
	else
	{

		while (PR != nullptr)
		{
			Predecessor* t_P = new Predecessor();
			if(PR->number==N)
			{
				t_P->metrics = 0;
			}
			else
			{
				t_P->metrics = -1;
			}
			t_P->predecessor = -1;
			t_P->number = PR->number;

			AddPredecessorByNumber(P, t_P);

			t_P = nullptr;

			PR = PR->pNext;
		}

		return true;
	}
}

/**
Publiczna metoda dodaj�ca element typu Predecessor na koniec listy
@param LP Wska�nik na referencje do listy typu Predecessor
@param P Wska�nik na obiekt typu Predecessor
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Predecessor::AddPredecessorEnd(Predecessor*& LP, Predecessor* P)
{
	if (P == nullptr)
	{
		return false;
	}
	else
	{
		if (LP == nullptr)
		{
			LP = new Predecessor;
			LP = P;
			P = nullptr;
		}
		else
		{
			Predecessor* t_LP = LP;
			Predecessor* p_LP = t_LP;
			while (t_LP->pNext != nullptr)
			{
				t_LP = t_LP->pNext;
			}
			t_LP->pNext = P;
			t_LP->pPrev->pNext = t_LP;
			LP = p_LP;
		}

		return true;
	}
}

/**
Publiczna metoda dodaj�ca element typu Predecessor w zale�no�ci od warto�ci od numeru
@param LP Wska�nik na referencje do listy typu Predecessor
@param P Wska�nik na obiekt typu Predecessor
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Predecessor::AddPredecessorByNumber(Predecessor*& LP, Predecessor* P)
{
	if (P == nullptr)
	{
		return false;
	}
	else
	{
		if (LP == nullptr)
		{
			LP = new Predecessor;
			LP = P;
		}
		else
		{
			Predecessor* t_LP = LP;
			Predecessor* p_LP = t_LP;
			Predecessor* h_LP1 = t_LP;

			if (t_LP->pNext == nullptr)
			{
				if (P->number > t_LP->number)
				{
					t_LP->pNext = P;
					t_LP->pNext->pPrev = t_LP;
					LP = t_LP;
				}
				else
				{
					t_LP->pPrev = P;
					t_LP->pPrev->pNext = t_LP;
					LP = t_LP->pPrev;
				}
			}
			else
			{
				while (t_LP->pNext != nullptr)
				{
					if (P->number > t_LP->number)
					{
						t_LP = t_LP->pNext;
					}
					else
					{
						if (t_LP->pPrev == nullptr)
						{
							t_LP->pPrev = P;
							t_LP->pPrev->pNext = t_LP;
							LP = t_LP->pPrev;
						}
						else
						{
							h_LP1 = t_LP;
							t_LP = t_LP->pPrev;
							t_LP->pNext = P;
							t_LP->pNext->pPrev = t_LP;
							t_LP = t_LP->pNext;
							t_LP->pNext = h_LP1;
							t_LP->pNext->pPrev = t_LP;
							LP = p_LP;
						}

						return true;
					}
				}

				t_LP->pNext = P;
				t_LP->pNext->pPrev = t_LP;
				LP = p_LP;
			}
		}

		return true;
	}
}

/**
Publiczna metoda znajduj�ca najmniejszy element listy pod wzgl�dem odleg�o�ci
@param LP Wska�nik na referencje do listy typu Predecessor
@param P Wska�nik na obiekt typu Primal
@return Zwraca wska�nik na element o najmnieszym koszcie
*/
Predecessor* Predecessor::FindPredecessorByLowerCost(Predecessor* LP, Primal* P)
{
	Predecessor* t_LP = new Predecessor();

	double minimum = -1;
	int flag = 1;

	while (LP != nullptr)
	{
		if (Primal::CheckPrimalByNumber(P, LP->number) == true)
		{

			if (LP->metrics != -1 && flag == 1)
			{
				*t_LP = *LP;
				minimum = t_LP->metrics;
				flag = 0;
			}

			if (LP->metrics < minimum && LP->metrics!=-1)
			{
				*t_LP = *LP;
				minimum = t_LP->metrics;
			}
		}

		LP = LP->pNext;
	}

	return t_LP;
}

/**
Publiczna metoda znajdujaca element listy po numerze
@param LP Wska�nik na list� typu Predecessor
@param N Numer wierzcho�ka
@return Zwraca wska�nik na znaleziony element lub nullptr
*/
Predecessor* Predecessor::FindPredecessorByNumber(Predecessor* LP, long int N)
{
	if (LP == nullptr)
	{
		return nullptr;
	}
	{
		while (LP != nullptr)
		{
			if (LP->number == N)
			{
				return LP;
			}

			LP = LP->pNext;
		}

		return LP;
	}
}

/**
Publiczna metoda sprawdzaj�ca czy dana trasa jest lepsza i ewentualnie aktualizuj�ca dane
@param LP Wska�nik na referencje do listy typu Predecessor
@param P Wska�nik na  rozwa�any element
@param N Numer wierzcho�ka startowego
@param G Wska�nik na graf
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Predecessor::CompletePredecessor(Predecessor*& LP, Primal* P, long int N, Graph* G)
{
	if (LP == nullptr || G == nullptr)
	{
		return false;
	}
	{

		Borderer* B = nullptr;
		while (G != nullptr)
		{
			if (G->top->number == N)
			{
				B = G->BTops;
			}

			G = G->pNext;
		}


		Predecessor* t_LP = LP;
		Predecessor* p_LP = t_LP;
		Borderer* t_B = nullptr;

		Predecessor* t_LPP = Predecessor::FindPredecessorByNumber(LP, N);

		while (t_LP != nullptr)
		{
			if (CheckPrimalByNumber(P, t_LP->number) == true)
			{
				t_B = Borderer::FindBordererByNumber(B, t_LP->number);
				
				if(t_B!=nullptr)
				{
					if ((t_LP->metrics > t_LPP->metrics + t_B->metrics) || t_LP->metrics==-1)
					{
						t_LP->metrics = t_LPP->metrics + t_B->metrics;
						t_LP->predecessor = N;
					}
				}
			}

			t_LP = t_LP->pNext;
		}

		return true;
	}
}

/**
Publiczna metoda usuwaj�ca list� typu Predecessor
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Predecessor::DeletePredecessorList()
{
	Predecessor* t_P = this;

	if (t_P != nullptr)
	{
		while (t_P->pNext != nullptr)
		{
			t_P = t_P->pNext;
		}

		while (t_P->pPrev != nullptr)
		{
			t_P->pNext = nullptr;
			t_P = t_P->pPrev;
			delete t_P->pNext;

		}
		t_P->pNext = nullptr;
		delete t_P;

		t_P = nullptr;
	}

	return true;
}