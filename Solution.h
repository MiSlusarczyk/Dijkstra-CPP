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
Klasa bed¹ca odpowiedzialna za listê z rozwi¹zaniem
*/
class Solution
{
public:
	Primal* start; ///< WskaŸnik na element typu primal bêd¹cy wierzcho³kiem dla którego liczmy trasy do reszty wierzcho³ków
	Branch* branch; ///< WskaŸnik na element typu Branch zawieraj¹cy wierzcho³ek koñcowy i trasê do niego
	Solution* pNext; ///< WskaŸnik na nastêpny element
	Solution* pPrev; ///< WskaŸnik na poprzedni element

	Solution();

	Solution& operator=(const Solution&);

	static bool AddSolutionEnd(Solution*&, Solution*);
	static bool AddSolutionByStart(Solution*&, Solution*);
	bool DeleteSolutionList();
};

