/** @file  */

#pragma once

#include <iostream>

#include "Borderer.h"
#include "Graph.h"

/**
Klasa bed�ca odpowiedzialn� za przechowywanie efektu dzia�ania algorytmu Dijkstry
*/
class Predecessor : public Borderer
{
public:
	long int predecessor; ///< Numer poprzedniego wierzcho�ka na trasie
	Predecessor* pNext; ///< Wska�nik na nastepny element
	Predecessor* pPrev; ///< Wska�nik na poprzedni element

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
