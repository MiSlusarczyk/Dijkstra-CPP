/** @file  */

#pragma once
#include <Windows.h>

#include "Operators.h"
#include "Signs.h"

/**
Klasa do przechowywania wszystkich struktur potrzebnych do realizacji algorytmu Dijkstry
*/
class Data
{
public:
	Parameters* P; ///< Atrybut klasy Parameters przechowuj¹cy dane na temat funkcjonalnoœci które maj¹ byc u¿yte
	Graph* G; ///< Atrybut klasy Graph w którym przechowywany jest opis grafu
	DataTops* D; ///< Atrybut klasy DataTops w którym przechowywane s¹ dane wejœciowe
	Solution* S; ///< Atrybut klasy Solution w którym przechowywane jest rozwi¹zanie

	Data();
	Data(Parameters*&, Graph*&, DataTops*&, Solution*&);
	~Data();
};

