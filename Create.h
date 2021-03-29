/** @file  */

#pragma once
#include "Data.h"

/**
Klasa odpowiedzialna za wczytanie lub stworzenie w oparciu o komunikacje z u¿ytkownikiem danych na których ma operowaæ program
*/
class Create
{
public:
	bool LoadGraph(Data*&);
	bool CreateGraph(Data*&);
	bool LoadData(Data*&);
	bool CreateData(Data*&);
};

