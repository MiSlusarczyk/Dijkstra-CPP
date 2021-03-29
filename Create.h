/** @file  */

#pragma once
#include "Data.h"

/**
Klasa odpowiedzialna za wczytanie lub stworzenie w oparciu o komunikacje z u�ytkownikiem danych na kt�rych ma operowa� program
*/
class Create
{
public:
	bool LoadGraph(Data*&);
	bool CreateGraph(Data*&);
	bool LoadData(Data*&);
	bool CreateData(Data*&);
};

