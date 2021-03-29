/** @file  */

#include "Graph.h"

/**
Konstruktor domyœlny klasy Graf
*/
Graph::Graph()
{
	top = nullptr;
	BTops = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeci¹¿ony operator przypisania
@param G Referencja do sta³ego obiektu typu Graph
@return Referencja do elementu typu Graph pozwalaj¹ca na kaskadowe wywo³anie
*/
Graph& Graph::operator=(const Graph& G)
{
	if (&G == this)
	{
		return *this;
	}
	else
	{
		if (top != nullptr)
		{
			delete top;
		}

		if (BTops != nullptr)
		{
			delete BTops;
		}

		if (pNext != nullptr)
		{
			delete pNext;
		}

		if (pPrev != nullptr)
		{
			delete pPrev;
		}

		top = new Primal;
		BTops = new Borderer;
		pNext = nullptr;
		pPrev = nullptr;

		top = G.top;
		BTops = G.BTops;
		pNext = G.pNext;
		pPrev = G.pPrev;

		return *this;
	}
}

/**
Publiczna metoda dodaj¹ca element typu Graph na koniec listy
@param LG WskaŸnik na referencje do listy typu Graph
@param G WskaŸnik na obiekt typu Graph
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Graph::AddGraphEnd(Graph*& LG, Graph* G)
{
	if (G == nullptr)
	{
		return false;
	}
	else
	{
		if (LG == nullptr)
		{
			LG = new Graph;
			LG = G;
		}
		else
		{
			Graph* t_LG = LG;
			Graph* p_LG = t_LG;
			while (t_LG->pNext != nullptr)
			{
				t_LG = t_LG->pNext;
			}
			t_LG->pNext = G;
			t_LG->pPrev->pNext = G;
			LG = p_LG;
		}

		return true;
	}
}

/**
Publiczna metoda dodaj¹ca element typu Graph z uwzglêdnieniem numeru wierzcho³ka startowego
@param LG WskaŸnik na referencje do listy typu Graph
@param G WskaŸnik na obiekt typu Graph
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Graph::AddGraphByTop(Graph*& LG, Graph* G)
{
	if (G == nullptr)
	{
		return false;
	}
	else
	{
		if (LG == nullptr)
		{
			LG = new Graph;
			LG = G;
		}
		else
		{
			Graph* t_LG = LG;
			Graph* p_LG = t_LG;
			Graph* h_LG1 = t_LG;

			if (t_LG->pNext == nullptr)
			{
				if (G->top->number > t_LG->top->number)
				{
					t_LG->pNext = G;
					t_LG->pNext->pPrev = t_LG;
					LG = t_LG;
				}
				else
				{
					t_LG->pPrev = G;
					t_LG->pPrev->pNext = t_LG;
					LG = t_LG->pPrev;
				}
			}
			else
			{
				while (t_LG->pNext != nullptr)
				{
					if (G->top->number > t_LG->top->number)
					{
						t_LG = t_LG->pNext;
					}
					else
					{
						if (t_LG->pPrev == nullptr)
						{
							t_LG->pPrev = G;
							t_LG->pPrev->pNext = t_LG;
							LG = t_LG->pPrev;
						}
						else
						{
							h_LG1 = t_LG;
							t_LG->pPrev->pNext = G;
							t_LG->pPrev = h_LG1->pNext;
							LG = p_LG;
						}

						return true;
					}
				}

				t_LG->pNext = G;
				t_LG->pNext->pPrev = t_LG;
				LG = p_LG;
			}
		}

		return true;
	}
}

/**
Publiczna metoda do usuwania listy typu Graph
@return Zwraca informacjê o poprawnoœci wykonania metody i wyst¹pieniu ewentualnego b³êdu
*/
bool Graph::DeleteGraphList()
{
	Graph* t_G = this;

	if (t_G != nullptr)
	{
		while (t_G->pNext != nullptr)
		{
			t_G = t_G->pNext;
		}

		while (t_G->pPrev != nullptr)
		{
			t_G->top->DeletePrimalList();
			t_G->top = nullptr;

			t_G->BTops->DeleteBordererList();
			t_G->BTops = nullptr;

			t_G->pNext = nullptr;
			t_G = t_G->pPrev;
			delete t_G->pNext;

		}
		t_G->pNext = nullptr;
		t_G->top->DeletePrimalList();
		t_G->top = nullptr;
		t_G->BTops->DeleteBordererList();
		t_G->BTops = nullptr;
		delete t_G;

		t_G = nullptr;
	}

	return true;
}

