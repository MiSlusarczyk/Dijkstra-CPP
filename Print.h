/** @file  */

#pragma once

#include "Data.h"

/**
Klasa abstrakcyjna pozwalaj�ca po kt�rej dziedzicz� kalsy zawieraj�ce metody do wy�wietlania konkretnych danych na ekranie
*/
class Print : public Data
{
public:
	virtual bool PrintDijkstra() = 0;
};

