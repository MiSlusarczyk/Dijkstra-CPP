/** @file  */

#pragma once
#include "Borderer.h"
#include "Primal.h"

/**
Klasa bed¹ca odpowiedzialna za listê typu Branch
*/
class Branch
{
public:
	Borderer* end; ///< WskaŸnik na element typu Borderer bêd¹cy wierzcho³kiem koñcowym
	Primal* way; ///< WskaŸnik na liste typu Primal przechowujac¹ trasê do wêz³a wynikowego 
	Branch* pNext; ///< WskaŸnik na nastepny element
	Branch* pPrev; ///< WskaŸnik na poprzedni element

	Branch();

	Branch& operator=(const Branch&);

	static bool AddBranchEnd(Branch*&, Branch*);
	static bool AddBranchByEnd(Branch*&, Branch*);

	bool DeleteBranchList();


};

