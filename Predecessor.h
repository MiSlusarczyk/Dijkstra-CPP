/** @file  */

#pragma once

#include <iostream>

#include "Borderer.h"
#include "Graph.h"

/**
Klasa bed¹ca odpowiedzialn¹ za przechowywanie efektu dzia³ania algorytmu Dijkstry
*/
class Predecessor : public Borderer
{
public:
	long int predecessor; ///< Numer poprzedniego wierzcho³ka na trasie
	Predecessor* pNext; ///< WskaŸnik na nastepny element
	Predecessor* pPrev; ///< WskaŸnik na poprzedni element

	Predecessor();

	Predecessor& operator=(const Predecessor&);

	static bool AddPredecessorEnd(Predecessor*&, Predecessor*);
	static bool AddPredecessorByNumber(Predecessor*&, Predecessor*);
	static bool PreparePredecessor(Predecessor*&, Primal*, long int);
	static Predecessor* FindPredecessorByLowerCost(Predecessor*, Primal*);
	static Predecessor* FindPredecessorByNumber(Predecessor*, long int N);
	static bool CompletePredecessor(Predecessor*&, Primal*, long int, Graph*);
	bool DeletePredecessorList();
};
