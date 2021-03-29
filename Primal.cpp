/** @file  */

#include "Primal.h"

/**
Konstruktor domy�lny klasy Primal
*/
Primal::Primal()
{
	number = 0;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci��ony operator przypisania
@param P Referencja do sta�ego obiektu typu Primal
@return Referencja do elementu typu Primal pozwalaj�ca na kaskadowe wywo�anie
*/
Primal& Primal::operator=(const Primal& P)
{
	if (&P == this)
	{
		return *this;
	}
	else
	{
		number = P.number;
		pNext = P.pNext;
		pPrev = P.pPrev;

		return *this;
	}
}

/**
Publiczna metoda dodaj�ca element typu Primal na koniec listy
@param LP Wska�nik na referencje do listy typu Primal
@param P Wska�nik na obiekt typu Primal
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::AddPrimalEnd(Primal*& LP, Primal* P)
{
	if (P == nullptr)
	{
		return false;
	}
	else
	{
		if (LP == nullptr)
		{
			LP = new Primal;
			LP = P;
		}
		else
		{
			Primal* t_LP = LP;
			Primal* p_LP = t_LP;

			while (t_LP->pNext != nullptr)
			{
				t_LP = t_LP->pNext;
			}

			t_LP->pNext = P;
			t_LP->pNext->pPrev = t_LP;
			LP = p_LP;
		}

		return true;
	}
}

/**
Publiczna metoda dodaj�ca element typu Primal na pocz�tek listy
@param LP Wska�nik na referencje do listy typu Primal
@param P Wska�nik na obiekt typu Primal
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::AddPrimalFront(Primal*& LP, Primal* P)
{
	if (P == nullptr)
	{
		return false;
	}
	else
	{
		if (LP == nullptr)
		{
			LP = new Primal;
			LP = P;
		}
		else
		{
			LP->pPrev = P;
			LP->pPrev->pNext = LP;
			LP = LP->pPrev;
		}

		return true;
	}
}

/**
Publiczna metoda dodaj�ca element typu Primal w zale�no�ci od numeru
@param LP Wska�nik na referencje do listy typu Primal
@param P Wska�nik na obiekt typu Primal
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::AddPrimalByNumber(Primal*& LP, Primal* P)
{
	if (P == nullptr)
	{
		return false;
	}
	else
	{
		if (LP == nullptr)
		{
			LP = new Primal;
			LP = P;
		}
		else
		{

			Primal* t_LP = LP;
			Primal* p_LP = t_LP;
			Primal* h_LP1 = t_LP;

			while (t_LP->pNext!=nullptr)
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

						return true;
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

						return true;
					}
				}
			}

			if (t_LP->pNext == nullptr)
			{
				if (P->number > t_LP->number)
				{
					t_LP->pNext = P;
					t_LP->pNext->pPrev = t_LP;
					LP = p_LP;
				}
				else
				{
					h_LP1 = t_LP;
					t_LP->pPrev = P;
					t_LP = t_LP->pPrev;
					t_LP->pNext = h_LP1;
					LP = p_LP;
				}
			}
		}

		return true;
	}
}

/**
Publiczna metoda usuwaj�ca element typu Primal w zale�no�ci od numeru
@param P Wska�nik na referencje do listy typu Primal
@param N Numer wierzcho�ka do usuni�cia
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::DeletePrimalByNumber(Primal*& P, long int N)
{
	if (P == nullptr)
	{
		return true;
	}
	else
	{
		Primal* t_P = P;
		Primal* p_P = t_P;
		Primal* h_P1 = nullptr;
		Primal* h_P2 = nullptr;

		while (t_P != nullptr)
		{
			if (t_P->number == N)
			{
				if (t_P->pPrev == nullptr && t_P->pNext==nullptr)
				{
					delete t_P;
					P = nullptr;
				}
				else if (t_P->pPrev == nullptr)
				{
					h_P1 = t_P->pNext;
					delete t_P;
					t_P = h_P1;
					t_P->pPrev = nullptr;
					h_P1->pPrev = nullptr;
					P = t_P;
				}
				else if (t_P->pNext == nullptr)
				{
					h_P1 = t_P->pPrev;
					delete t_P;
					t_P = h_P1;
					t_P->pNext = nullptr;
					P = p_P;
				}
				else
				{
					h_P1 = t_P->pPrev;
					h_P2 = t_P->pNext;
					delete t_P;
					t_P = h_P1;
					t_P->pNext = h_P2;
					t_P->pNext->pPrev = t_P;
					P = p_P;
				}

				return true;
			}

			t_P = t_P->pNext;
		}

		return false;
	}
}

/**
Publiczna metoda do skopiowania elementu typu Primal
@param P Wska�nik na referencje do miejsca do kt�rego chcemy kopiowa�
@param CP Wska�nik na element typu Primal do skopiowania
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::CopyPrimal(Primal*& P, Primal*CP) 
{
	if (CP == nullptr)
	{
		return false;
	}
	else
	{
		if (P == nullptr)
		{
			P = new Primal();
		}

		*P = *CP;

		return true;
	}
}

/**
Publiczna metoda do skopiowania elementu typu Primal
@param P Wska�nik na referencje do miejsca do kt�rego chcemy kopiowa�
@param CP Wska�nik na list� typu Primal do skopiowania
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::CopyPrimalList(Primal*& P, Primal* CP)
{
	if (CP == nullptr || P!= nullptr)
	{
		return false;
	}
	else
	{
		Primal* t_P = nullptr;

		while (CP != nullptr)
		{
			t_P = new Primal();
			*t_P = *CP;
			AddPrimalEnd(P, t_P);
		}

		return true;
	}
}

/**
Publiczna metoda do usuwania listy typu Primal
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::DeletePrimalList()
{
	Primal* t_P = this;

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

/**
Publiczna metoda do usuwania ostatniego elementu listy typu Primal
@param P Wska�nik na referencje do listy typu Primal
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Primal::DeletePrimalEnd(Primal*& P)
{
	Primal* t_P = P;
	while (t_P->pNext != nullptr)
	{
		t_P = t_P -> pNext;
	}

	delete t_P;

	return true;
}

/**
Publiczna metoda do szuakania elementu o okre�lonym numerze w li�cie typu Primal
@param P Wska�nik na liste typu Primal
@param N Numer wierzcho�ka do znalezienia
@return Zwraca wska�nik na szukany element
*/
Primal* Primal::FindPrimalByNumber(Primal* P, long int N) 
{
	if (P == nullptr)
	{
		return nullptr;
	}
	else 
	{
		while (P != nullptr)
		{
			if (P->number == N)
			{
				return P;
			}
			P = P->pNext;
		}

		return nullptr;
	}
}

/**
Publiczna metoda do sprawdzenia czy element o takim numerze jest w li�cie typu Primal
@param P Wska�nik na list� typu Primal
@param N Numer wierzcho�ka do sprawdzenia
@return Zwraca informacj� czy element zosta� znaleziony
*/
bool Primal::CheckPrimalByNumber(Primal* P, long int N)
{
	while (P != nullptr)
	{
		if (P->number == N)
		{
			return true;
		}
		P = P->pNext;
	}

	return false;
}