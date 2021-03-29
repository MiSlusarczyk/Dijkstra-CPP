/** @file  */

#pragma once

#include "Parameters.h"
#include "Primal.h"
#include "Borderer.h"
#include "Branch.h"
#include "Predecessor.h"
#include "DataTops.h"
#include "Graph.h"

/**
Klasa bed�ca odpowiedzialna za list� z rozwi�zaniem
*/
class Solution
{
public:
	Primal* start; ///< Wska�nik na element typu primal b�d�cy wierzcho�kiem dla kt�rego liczmy trasy do reszty wierzcho�k�w
	Branch* branch; ///< Wska�nik na element typu Branch zawieraj�cy wierzcho�ek ko�cowy i tras� do niego
	Solution* pNext; ///< Wska�nik na nast�pny element
	Solution* pPrev; ///< Wska�nik na poprzedni element

	Solution();

	Solution& operator=(const Solution&);

	static bool AddSolutionEnd(Solution*&, Solution*);
	static bool AddSolutionByStart(Solution*&, Solution*);
	bool DeleteSolutionList();
};

