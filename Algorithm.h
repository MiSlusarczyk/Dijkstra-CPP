/** @file  */

#pragma once
#include "Data.h"

/**
Klasa odpowiedzialna za realizacje algorytmu Dijkstry
*/
class Algorithm
{
public:
	bool PrepareSolution(Data*&);
	bool Dijkstra(Data*&);
	bool CreateSolution(Solution*&, Predecessor*);
};

