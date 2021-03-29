/** @file  */

#include "Predecessor.h"

/**
Konstruktor domyœlny klasy Solution
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
Przeci¹¿ony operator przypisania
@param S Referencja do sta³ego obiektu typu Predecessor
@return Referencja do elementu typu Predecessor pozwalaj¹ca na kaskadowe wywo³anie
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
Publiczna metoda przygotowuj¹ca liste typu Predecesssor do uzupe³nienia
@param P WskaŸnik na listê typu Predecessor
@param PR WskaŸnik na listê typu Primal przechow¹j¹c¹ numery wszystkich wierzcho³ków w grafie
@param N Numer wierzcho³ka startowego
@return Referencja do elementu typu Solution pozwalaj¹ca na kaskadowe wywo³anie
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
Publiczna metoda dodaj¹ca element typu Predecessor na koniec listy
@param LP WskaŸnik na referencje do listy typu Predecessor
@param P WskaŸnik na obiekt typu Predecessor
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
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
Publiczna metoda dodaj¹ca element typu Predecessor w zale¿noœci od wartoœci od numeru
@param LP WskaŸnik na referencje do listy typu Predecessor
@param P WskaŸnik na obiekt typu Predecessor
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
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
Publiczna metoda znajduj¹ca najmniejszy element listy pod wzglêdem odleg³oœci
@param LP WskaŸnik na referencje do listy typu Predecessor
@param P WskaŸnik na obiekt typu Primal
@return Zwraca wskaŸnik na element o najmnieszym koszcie
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
@param LP WskaŸnik na listê typu Predecessor
@param N Numer wierzcho³ka
@return Zwraca wskaŸnik na znaleziony element lub nullptr
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
Publiczna metoda sprawdzaj¹ca czy dana trasa jest lepsza i ewentualnie aktualizuj¹ca dane
@param LP WskaŸnik na referencje do listy typu Predecessor
@param P WskaŸnik na  rozwa¿any element
@param N Numer wierzcho³ka startowego
@param G WskaŸnik na graf
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
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
Publiczna metoda usuwaj¹ca listê typu Predecessor
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
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