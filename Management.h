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
Klasa odpowiedzialna za obs³ugê procesu wykonywania zadania programistycznego
*/
class Management
{
	friend class Parameters; ///< ZaprzyjaŸnienie z klas¹ zawieraj¹c¹ prametry uk³adu
	friend class Print; ///< ZaprzyjaŸnienie z klas¹ abstrakcyjn¹ Print wykorzystywan¹ podczas wyswietlania

public:
	Management();

	Management(std::string p[]);

	bool Coordinate(Data*&);

protected:

	Parameters* P; ///< Atrybut klasy Parameters przechowuj¹cy dane na temat funkcjonalnoœci które maj¹ byc u¿yte
	Graph* G; ///< Atrybut klasy Graph w którym przechowywany jest opis grafu
	DataTops* D; ///< Atrybut klasy DataTops w którym przechowywane s¹ dane wejœciowe
	Solution* S; ///< Atrybut klasy Solution w którym przechowywane jest rozwi¹zanie
};
