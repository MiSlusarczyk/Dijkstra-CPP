/** @file  */

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Signs.h"
#include "Operators.h"
#include "Parameters.h"
#include "Data.h"
#include "Signs.h"

#include "Primal.h"
#include "Borderer.h"
#include "Predecessor.h"
#include "DataTops.h"
#include "Graph.h"
#include "Solution.h"

#include "User.h"
#include "Create.h"
#include "Algorithm.h"
#include "Save.h"

#include "PrintGraph.h"
#include "PrintData.h"
#include "PrintSolution.h"

/**
Klasa odpowiedzialna za obs�ug� procesu wykonywania zadania programistycznego
*/
class Management
{
	friend class Parameters; ///< Zaprzyja�nienie z klas� zawieraj�c� prametry uk�adu
	friend class Print; ///< Zaprzyja�nienie z klas� abstrakcyjn� Print wykorzystywan� podczas wyswietlania

public:
	Management();

	Management(std::string p[]);

	bool Coordinate(Data*&);

protected:

	Parameters* P; ///< Atrybut klasy Parameters przechowuj�cy dane na temat funkcjonalno�ci kt�re maj� byc u�yte
	Graph* G; ///< Atrybut klasy Graph w kt�rym przechowywany jest opis grafu
	DataTops* D; ///< Atrybut klasy DataTops w kt�rym przechowywane s� dane wej�ciowe
	Solution* S; ///< Atrybut klasy Solution w kt�rym przechowywane jest rozwi�zanie
};
