/** @file  */

#pragma once

#include "Print.h"
/**
Klasa odpowiedzialna za wyświetlanie rozwiązania na ekranie
*/
class PrintSolution : public Print
{
public:
	PrintSolution();
	PrintSolution(Data*);

	bool PrintDijkstra();
};

