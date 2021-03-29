/** @file  */

#pragma once

#include "Print.h"
/**
Klasa odpowiedzialna za wyœwietlanie rozwi¹zania na ekranie
*/
class PrintSolution : public Print
{
public:
	PrintSolution();
	PrintSolution(Data*);

	bool PrintDijkstra();
};

