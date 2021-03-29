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
	Parameters* P; ///< Atrybut klasy Parameters przechowuj�cy dane na temat funkcjonalno�ci kt�re maj� byc u�yte
	Graph* G; ///< Atrybut klasy Graph w kt�rym przechowywany jest opis grafu
	DataTops* D; ///< Atrybut klasy DataTops w kt�rym przechowywane s� dane wej�ciowe
	Solution* S; ///< Atrybut klasy Solution w kt�rym przechowywane jest rozwi�zanie

	Data();
	Data(Parameters*&, Graph*&, DataTops*&, Solution*&);
	~Data();
};

