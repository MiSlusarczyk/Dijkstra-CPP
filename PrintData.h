/** @file  */

#pragma once

#include"Print.h"

/**
Klasa odpowiedzialna za wy�wietlanie danych na ekranie
*/
class PrintData : public Print
{
public:
	PrintData();
	PrintData(Data*);

	bool PrintDijkstra();
};

