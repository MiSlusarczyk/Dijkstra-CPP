/** @file  */

#pragma once
#include "Borderer.h"
#include "Primal.h"

/**
Klasa bed�ca odpowiedzialna za list� typu Branch
*/
class Branch
{
public:
	Borderer* end; ///< Wska�nik na element typu Borderer b�d�cy wierzcho�kiem ko�cowym
	Primal* way; ///< Wska�nik na liste typu Primal przechowujac� tras� do w�z�a wynikowego 
	Branch* pNext; ///< Wska�nik na nastepny element
	Branch* pPrev; ///< Wska�nik na poprzedni element

	Branch();

	Branch& operator=(const Branch&);

	static bool AddBranchEnd(Branch*&, Branch*);
	static bool AddBranchByEnd(Branch*&, Branch*);

	bool DeleteBranchList();


};

