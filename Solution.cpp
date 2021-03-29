/** @file  */

#include "Solution.h"

/**
Konstruktor domy�lny klasy Solution
*/
Solution::Solution()
{
	start = nullptr;
	branch = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci��ony operator przypisania
@param S Referencja do sta�ego obiektu typu Solution
@return Referencja do elementu typu Solution pozwalaj�ca na kaskadowe wywo�anie
*/
Solution& Solution::operator=(const Solution& S)
{
	if (&S == this)
	{
		return *this;
	}
	else
	{
		start = new Primal;
		branch = new Branch;
		pNext = nullptr;
		pPrev = nullptr;

		start = S.start;
		branch = S.branch;
		pNext = S.pNext;

		return *this;
	}
}

/**
Publiczna metoda dodaj�ca element typu Solution na koniec listy
@param LS Wska�nik na referencje do listy typu Solution
@param S Wska�nik na obiekt typu Solution
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Solution::AddSolutionEnd(Solution*& LS, Solution* S)
{
	if (S != nullptr)
	{
		if (LS == nullptr)
		{
			LS = new Solution;
			LS = S;
		}
		else
		{
			Solution* t_LS = LS;
			Solution* temp_LS = LS;
			while (t_LS->pNext != nullptr)
			{
				t_LS = t_LS->pNext;
			}
			temp_LS = t_LS;
			t_LS->pNext = S;
			t_LS = t_LS->pNext;
			t_LS->pPrev = temp_LS;

			S = nullptr;
		}

		return true;
	}
	else
	{
		return false;
	}
}

/**
Publiczna metoda dodaj�ca element typu Solution z uwzgl�dnieniem numeru wierzcho�ka startowego
@param LS Wska�nik na referencje do listy typu Solution
@param S Wska�nik na obiekt typu Solution
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Solution::AddSolutionByStart(Solution*& LS, Solution* S)
{
	if (S == nullptr)
	{
		return false;
	}
	else
	{
		if (LS == nullptr)
		{
			LS = new Solution;
			LS = S;
		}
		else
		{
			Solution* t_LS = LS;
			Solution* p_LS = t_LS;
			Solution* h_LS1 = t_LS;

			if (t_LS->pNext == nullptr)
			{
				if (S->start->number > t_LS->start->number)
				{
					t_LS->pNext = S;
					t_LS->pNext->pPrev = t_LS;
					LS = t_LS;
				}
				else
				{
					t_LS->pPrev = S;
					t_LS->pPrev->pNext = t_LS;
					LS = t_LS->pPrev;
				}
			}
			else
			{
				while (t_LS->pNext != nullptr)
				{
					if (S->start->number > t_LS->start->number)
					{
						t_LS = t_LS->pNext;
					}
					else
					{
						if (t_LS->pPrev == nullptr)
						{
							t_LS->pPrev = S;
							t_LS->pPrev->pNext = t_LS;
							LS = t_LS->pPrev;
						}
						else
						{
							h_LS1 = t_LS;
							t_LS->pPrev->pNext = S;
							t_LS->pPrev = h_LS1->pNext;
							LS = p_LS;
						}

						return true;
					}
				}

				t_LS->pNext = S;
				t_LS->pNext->pPrev = t_LS;
				LS = p_LS;
			}
		}

		return true;
	}
}

/**
Publiczna metoda do usuwania listy typu Solution
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Solution::DeleteSolutionList()
{
	Solution* t_S = this;

	if (t_S != nullptr)
	{
		while (t_S->pNext != nullptr)
		{
			t_S = t_S->pNext;
		}

		while (t_S->pPrev != nullptr)
		{

			t_S->start->DeletePrimalList();
			t_S->start = nullptr;

			t_S->branch->DeleteBranchList();
			t_S->branch = nullptr;

			t_S->pNext = nullptr;
			t_S = t_S->pPrev;
			delete t_S->pNext;
		}

		t_S->pNext = nullptr;

		t_S->start->DeletePrimalList();
		t_S->start = nullptr;

		t_S->branch->DeleteBranchList();
		t_S->pNext = nullptr;

		delete t_S;

		t_S = nullptr;
	}

	return true;
}
