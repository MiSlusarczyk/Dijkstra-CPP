/** @file  */

#include "DataTops.h"

/**
Konstruktor domy�lny klasy DataTops
*/
DataTops::DataTops()
{
	top = nullptr;
	Dtops = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci��ony operator przypisania
@param D Referencja do sta�ego obiektu typu DataTops
@return Referencja do elementu typu DataTops pozwalaj�ca na kaskadowe wywo�anie
*/
DataTops& DataTops::operator=(const DataTops& D)
{
	if (&D == this)
	{
		return *this;
	}
	else
	{
		top = D.top;
		Dtops = D.Dtops;
		pNext = D.pNext;
		pPrev = D.pPrev;

		return *this;
	}
}

/**
Publiczna metoda dodaj�ca element typu DataTops na koniec listy
@param LD Wska�nik na referencje typu DataTops
@param D Wska�nik na obiekt typu DataTops
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool DataTops::AddDataTopsEnd(DataTops*& LD, DataTops* D)
{
	if (D == nullptr)
	{
		return false;
	}
	else
	{
		if (LD == nullptr)
		{
			LD = new DataTops;
			LD = D;
		}
		else
		{
			DataTops* t_LD= LD;
			DataTops* p_LD = t_LD;
			while (t_LD->pNext != nullptr)
			{
				t_LD = t_LD->pNext;
			}
			t_LD->pNext = D;
			t_LD->pPrev->pNext = t_LD;
			LD = p_LD;

		}

		return true;
	}
}

/**
Publiczna metoda dodaj�ca element typu DataTops z uwzgl�dnieniem numeru wierzcho�ka startowego
@param LD Wska�nik na referencje typu DataTops
@param D Wska�nik na obiekt typu DataTops
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool DataTops::AddDataTopsByTop(DataTops*& LD, DataTops* D) 
{
	if (D == nullptr)
	{
		return false;
	}
	else
	{
		if (LD == nullptr)
		{
			LD = new DataTops;
			LD = D;
		}
		else
		{
			DataTops* t_LD = LD;
			DataTops* p_LD = t_LD;
			DataTops* h_LD1 = t_LD;

			if (t_LD->pNext == nullptr)
			{
				if (D->top->number > t_LD->top->number)
				{
					t_LD->pNext = D;
					t_LD->pNext->pPrev = t_LD;
					LD = t_LD;
				}
				else
				{
					t_LD->pPrev = D;
					t_LD->pPrev->pNext = t_LD;
					LD = t_LD->pPrev;
				}
			}
			else
			{
				while (t_LD->pNext != nullptr)
				{
					if (D->top->number > t_LD->top->number)
					{
						t_LD = t_LD->pNext;
					}
					else
					{
						if (t_LD->pPrev == nullptr)
						{
							t_LD->pPrev = D;
							t_LD->pPrev->pNext = t_LD;
							LD = t_LD->pPrev;
						}
						else
						{
							h_LD1 = t_LD;
							t_LD->pPrev->pNext = D;
							t_LD->pPrev = h_LD1->pNext;
							LD = p_LD;
						}

						return true;
					}
				}

				t_LD->pNext = D;
				t_LD->pNext->pPrev = t_LD;
				LD = p_LD;
			}
		}

		return true;
	}
}

/**
Publiczna metoda tworz�ca liste poprzednik�w
@param P Wska�nik na referencje typu Primal
@param D Wska�nik na liste typu DataTops
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool DataTops::CreatePrimalList(Primal*& P, DataTops* D)
{
	if (D == nullptr)
	{
		return false;
	}
	else
	{

		while (D != nullptr)
		{
			if (Primal::CheckPrimalByNumber(P, D->top->number) == false)
			{
				Primal* t_P = new Primal();
				t_P->number = D->top->number;

				Primal::AddPrimalByNumber(P, t_P);
			}

			Primal* t_DT = D->Dtops;

			while (t_DT != nullptr)
			{
				if (Primal::CheckPrimalByNumber(P, t_DT->number) == false)
				{
					Primal* t_P = new Primal();
					t_P->number = t_DT->number;

					Primal::AddPrimalByNumber(P, t_P);
				}

				t_DT = t_DT->pNext;
			}

			D = D->pNext;
		}
		return true;
	}
}

/**
Publiczna metoda do usuwania listy typu DataTops
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool DataTops::DeleteDataTopsList()
{
	DataTops* t_D = this;

	if (t_D != nullptr)
	{
		while (t_D->pNext != nullptr)
		{
			t_D = t_D->pNext;
		}

		while (t_D->pPrev != nullptr)
		{
			t_D->top->DeletePrimalList();
			t_D->top = nullptr;

			t_D->Dtops->DeletePrimalList();
			t_D->Dtops = nullptr;

			t_D->pNext = nullptr;
			t_D = t_D->pPrev;
			delete t_D->pNext;
		}

		t_D->pNext = nullptr;
		t_D->top->DeletePrimalList();
		t_D->top = nullptr;
		t_D->Dtops->DeletePrimalList();
		t_D->Dtops = nullptr;
		delete t_D;

		t_D = nullptr;
	}

	return true;
}