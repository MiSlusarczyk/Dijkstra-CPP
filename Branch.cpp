/** @file  */

#include "Branch.h"

/**
Konstruktor domyœlny klasy Branch
*/
Branch::Branch()
{
	end = nullptr;
	way = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci¹¿ony operator przypisania
@param B Referencja do sta³ego obiektu typu Solution
@return Referencja do elementu typu Solution pozwalaj¹ca na kaskadowe wywo³anie
*/
Branch& Branch::operator=(const Branch& B) 
{
	if (&B == this)
	{
		return *this;
	}
	else
	{
		end = B.end;
		way = B.way;
		pNext = B.pNext;
		pPrev = B.pPrev;

		return *this;
	}
}

/**
Publiczna metoda dodaj¹ca element typu Branch na koniec listy
@param LB WskaŸnik na referencje typu Branch
@param B WskaŸnik na obiekt typu Branch
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Branch::AddBranchEnd(Branch*& LB, Branch* B)
{
	if (B != nullptr)
	{
		if (LB == nullptr)
		{
			LB = new Branch;
			LB = B;
		}
		else
		{
			Branch* t_LB = LB;
			Branch* p_LB = t_LB;
			while (t_LB->pNext != nullptr)
			{
				t_LB = t_LB->pNext;
			}
			t_LB->pNext = B;
			t_LB->pNext->pPrev = t_LB;
			LB = p_LB;

		}

		return true;
	}
	else
	{
		return false;
	}
}

/**
Publiczna metoda dodaj¹ca element typu Branch z uwzglêdnieniem numeru wiecho³ka koñcowego
@param LB WskaŸnik na referencje typu Branch
@param B WskaŸnik na obiekt typu Branch
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Branch::AddBranchByEnd(Branch*& LB, Branch* B)
{
	if (B == nullptr)
	{
		return false;
	}
	else
	{
		if (LB == nullptr)
		{
			LB = new Branch;
			LB = B;
		}
		else
		{
			Branch* t_LB = LB;
			Branch* p_LB = t_LB;
			Branch* h_LB1 = t_LB;

			if (t_LB->pNext == nullptr)
			{
				if (B->end->number > t_LB->end->number)
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
					if (B->end->number > t_LB->end->number)
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
Publiczna metoda do usuwania listy typu Branch
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Branch::DeleteBranchList()
{
	Branch* t_B = this;

	if (t_B != nullptr)
	{
		while (t_B->pNext != nullptr)
		{
			t_B = t_B->pNext;
		}

		while (t_B->pPrev != nullptr)
		{
			t_B->end->DeleteBordererList();
			t_B->end = nullptr;

			t_B->way->DeletePrimalList();
			t_B->end = nullptr;

			t_B->pNext = nullptr;
			t_B = t_B->pPrev;
			delete t_B->pNext;
		}

		t_B->pNext = nullptr;
		t_B->end->DeleteBordererList();
		t_B->end = nullptr;
		t_B->way->DeletePrimalList();
		t_B->end = nullptr;
		delete t_B;

		t_B = nullptr;
	}

	return true;
}