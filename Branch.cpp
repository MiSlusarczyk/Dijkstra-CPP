/** @file  */

#include "Branch.h"

/**
Konstruktor domy�lny klasy Branch
*/
Branch::Branch()
{
	end = nullptr;
	way = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci��ony operator przypisania
@param B Referencja do sta�ego obiektu typu Solution
@return Referencja do elementu typu Solution pozwalaj�ca na kaskadowe wywo�anie
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
Publiczna metoda dodaj�ca element typu Branch na koniec listy
@param LB Wska�nik na referencje typu Branch
@param B Wska�nik na obiekt typu Branch
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
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
Publiczna metoda dodaj�ca element typu Branch z uwzgl�dnieniem numeru wiecho�ka ko�cowego
@param LB Wska�nik na referencje typu Branch
@param B Wska�nik na obiekt typu Branch
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
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
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
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