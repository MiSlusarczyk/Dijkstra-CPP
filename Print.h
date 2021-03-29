/** @file  */

#pragma once

#include "Data.h"

/**
Klasa abstrakcyjna pozwalaj¹ca po której dziedzicz¹ kalsy zawieraj¹ce metody do wyœwietlania konkretnych danych na ekranie
*/
class Print : public Data
{
public:
	virtual bool PrintDijkstra() = 0;
};

