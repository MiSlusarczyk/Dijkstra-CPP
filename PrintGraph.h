/** @file  */

#pragma once

#include "Print.h"

/**
Klasa odpowiedzialna za wyświetlanie grafu na ekranie
*/
class PrintGraph : public Print
{
public:
	PrintGraph();
	PrintGraph(Data*);

	bool PrintDijkstra();
};

