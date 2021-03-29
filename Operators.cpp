/** @file  */

#include "Operators.h"

/**
Przeci��ony operator strumienia wykorzystywany do wy�wietlania Grafu na ekranie
@param print Referencja na wska�nik wskazuj�cy na pierwszy element listy z grafem
@return Zwraca referencje na strumie� co pozwala na kaskadowe wywywo�ywanie
*/
std::ostream& operator<<(std::ostream& print, Graph*& G)
{
	print << C("Wierzcholek: ") << G->top << std::endl;

	Borderer* t_B = G->BTops;

	print << C("Lista sasiadow: ");

	while (t_B != nullptr)
	{
		print << t_B;

		t_B = t_B->pNext;
	}

	print << std::endl << std::endl;

	return print;
}

/**
Przeci��ony operator strumienia wykorzystywany do wy�wietlania obiektu typu Borderer
@param print Referencja na wska�nik wskazuj�cy na pierwszy element listy typu Borderer
@return Zwraca referencje na strumie� co pozwala na kaskadowe wywywo�ywanie
*/
std::ostream& operator<<(std::ostream& print, Borderer*& B)
{
	print << B->number << " " << B->metrics << "; ";

	return print;
}

/**
Przeci��ony operator strumienia wykorzystywany do wy�wietlania obiektu typu DataTops zawierajacego dane wej�ciowe
@param print Referencja na wska�nik wskazuj�cy na pierwszy element listy typu DataTops
@return Zwraca referencje na strumie� co pozwala na kaskadowe wywywo�ywanie
*/
std::ostream& operator<<(std::ostream& print, DataTops*& D)
{

	print << C("Wierzcholek: ") << D->top << std::endl;

	print << C("Wierzcholki dla ktorych chcemy wyznaczyc polaczenie: ");

	Primal* t_P = D->Dtops;

	while (t_P != nullptr)
	{
		print << t_P;

		if (t_P->pNext != nullptr)
		{
			print << " ";
		}

		t_P = t_P->pNext;
	}

	print << ";" << std::endl << std::endl;

	return print;
}

/**
Przeci��ony operator strumienia wykorzystywany do wy�wietlania obiektu typu Primal
@param print Referencja na wska�nik wskazuj�cy na pierwszy element listy typu Primal
@return Zwraca referencje na strumie� co pozwala na kaskadowe wywywo�ywanie
*/
std::ostream& operator<<(std::ostream& print, Primal*& P)
{
	print << P->number;
	return print;
}

/**
Przeci��ony operator strumienia wykorzystywany do wy�wietlania obiektu typu Branch
@param print Referencja na wska�nik wskazuj�cy na pierwszy element listy typu Branch
@return Zwraca referencje na strumie� co pozwala na kaskadowe wywywo�ywanie
*/
std::ostream& operator<<(std::ostream& print, Branch*& B)
{
	print << B->end->number << ": ";

	Primal* t_P = B->way;

	if (t_P != nullptr)
	{
		while (t_P != nullptr)
		{
			if (t_P->pNext != nullptr)
			{
				print << t_P << "->";
			}
			else
			{
				print << t_P << " ";
			}

			t_P = t_P->pNext;
		}
	}
	else
	{
		print << B->end->number << " ";
	}

	print << "| " << B->end->number << ":" << B->end->metrics << std::endl;


	return print;
}

/**
Przeci��ony operator strumienia wykorzystywany do wy�wietlania rozwi�zania
@param print Referencja na wska�nik wskazuj�cy na pierwszy element listy zawieraj�cej rozwi�zanie
@return Zwraca referencje na strumie� co pozwala na kaskadowe wywywo�ywanie
*/
std::ostream& operator<<(std::ostream& print, Solution*& S)
{

	print << C("Wierzcholek: ") << S->start << std::endl;

	Branch* t_B = S->branch;

	while (t_B != nullptr)
	{
		print << S->start << ">>" << t_B;

		t_B = t_B->pNext;
	}

	if (S->pNext != nullptr)
	{
		print << std::endl << std::endl;
	}

	return print;
}