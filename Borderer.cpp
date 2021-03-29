/** @file  */

#include "Borderer.h"

/**
Konstruktor domyœlny klasy Borderer
*/
Borderer::Borderer()
{
	number = 0;
	metrics = 0;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci¹¿ony operator przypisania
@param S Referencja do sta³ego obiektu typu Borderer
@return Referencja do elementu typu Borderer pozwalaj¹ca na kaskadowe wywo³anie
*/
Borderer& Borderer::operator=(const Borderer& B) 
{
	if (&B == this)
	{
		return *this;
	}
	else
	{
		number = B.number;
		metrics = B.metrics;
		pNext = B.pNext;
		pPrev = B.pPrev;

		return *this;
	}
}

/**
Publiczna metoda dodaj¹ca element typu Borderer na koniec listy
@param LB WskaŸnik na referencje typu Solution
@param B WskaŸnik na obiekt typu Solution
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Borderer::AddBordererEnd(Borderer*& LB, Borderer* B)
{
	if (B == nullptr)
	{
		return false;
	}
	else
	{
		if (LB == nullptr)
		{
			LB = new Borderer;
			LB = B;
			B = nullptr;
		}
		else
		{
			Borderer* t_LB = LB;
			Borderer* p_LB = t_LB;
			while (t_LB->pNext != nullptr)
			{
				t_LB = t_LB->pNext;
			}
			t_LB->pNext = B;
			t_LB->pPrev->pNext = t_LB;
			LB = p_LB;
		}

		return true;
	}
}

/**
Publiczna metoda dodaj¹ca element typu Borderer z uwzglêdnieniem numeru sasiedniego wierzcho³ka
@param LS WskaŸnik na referencje typu Borderer
@param S WskaŸnik na obiekt typu Borderer
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Borderer::AddBordererByNumber(Borderer*& LB, Borderer* B)
{
	if (B == nullptr)
	{
		return false;
	}
	else
	{
		if (LB == nullptr)
		{
			LB = new Borderer;
			LB = B;
		}
		else
		{
			Borderer* t_LB = LB;
			Borderer* p_LB = t_LB;
			Borderer* h_LB1 = t_LB;

			if (t_LB->pNext == nullptr)
			{
				if (B->number > t_LB->number)
				{
					t_LB->pNext = B;
					t_LB->pNext->pPrev = t_LB;
					LB = t_LB;
				}
				else
				{
					t_LB->pPrev = B;
					t_LB->pPrev->pNext = t_LB;
					LB = t_LB->pPrev;
				}
			}
			else
			{
				while (t_LB->pNext != nullptr)
				{
					if (B->number > t_LB->number)
					{
						t_LB = t_LB->pNext;
					}
					else
					{
						if (t_LB->pPrev == nullptr)
						{
							t_LB->pPrev = B;
							t_LB->pPrev->pNext = t_LB;
							LB = t_LB->pPrev;
						}
						else
						{
							h_LB1 = t_LB;
							t_LB->pPrev->pNext = B;
							t_LB->pPrev = h_LB1->pNext;
							LB = p_LB;
						}

						return true;
					}
				}

				t_LB->pNext = B;
				t_LB->pNext->pPrev = t_LB;
				LB = p_LB;
			}
		}

		return true;
	}
}

/**
Publiczna metoda dodaj¹ca szuakj¹ca element w liœcie typu Borderer o zadanym numerze
@param B WskaŸnik na listê typu Borderer
@param N Numer szukanego wierzcho³ka
@return Zwraca wskaŸnik na szukany element lub nullptr
*/
Borderer* Borderer::FindBordererByNumber(Borderer* B, long int N)
{
	if (B == nullptr)
	{
		return nullptr;
	}
	else
	{
		while (B != nullptr)
		{
			if (B->number == N)
			{
				return B;
			}

			B = B->pNext;
		}

		return nullptr;
	}
}

/**
Publiczna metoda do usuwania listy typu Borderer
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Borderer::DeleteBordererList()
{
	Primal* t_B = this;

	if (t_B != nullptr)
	{
		while (t_B->pNext != nullptr)
		{
			t_B = t_B->pNext;
		}

		while (t_B->pPrev != nullptr)
		{
			t_B->pNext = nullptr;
			t_B = t_B->pPrev;
			delete t_B->pNext;
		}

		t_B->pNext = nullptr;
		delete t_B;

		t_B = nullptr;
	}

	return true;
}