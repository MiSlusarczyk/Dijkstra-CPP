/** @file  */

#pragma once

#include "Print.h"
/**
Klasa odpowiedzialna za wy�wietlanie rozwi�zania na ekranie
*/
class PrintSolution : public Print
{
public:
	PrintSolution();
	PrintSolution(Data*);

	bool PrintDijkstra();
};

