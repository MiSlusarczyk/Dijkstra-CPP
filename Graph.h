/** @file  */

#pragma once
#include <iostream>

#include "Borderer.h"
#include "Primal.h"

/**
Klasa bed¹ca odpowiedzialna za graf
*/
class Graph
{
	friend class Borderer;
public:
	Primal* top;
	Borderer* BTops;
	Graph* pNext;
	Graph* pPrev;

	Graph();

	Graph& operator=(const Graph&);

	static bool AddGraphEnd(Graph*& , Graph*);
	static bool AddGraphByTop(Graph*&, Graph*);
	bool DeleteGraphList();
};