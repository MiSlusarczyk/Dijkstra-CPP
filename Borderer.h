/** @file  */

#pragma once

#include <iostream>

#include "Primal.h"
#include "DataTops.h"

/**
Klasa bed¹ca odpowiedzialna za listê z s¹siadami wierzcho³ka startowego
*/
class Borderer : public Primal
{
public:
	double metrics; ///< Odleg³oœæ do danego s¹siedniego wierzcho³ka
	Borderer* pNext; ///< WskaŸnik na nastêpny element
	Borderer* pPrev; ///< WskaŸnik na poprzedni element

	Borderer();
	Borderer& operator=(const Borderer&);

	static bool AddBordererEnd(Borderer*&, Borderer*);
	static bool AddBordererByNumber(Borderer*&, Borderer*);
	static Borderer* FindBordererByNumber(Borderer*, long int);
	bool DeleteBordererList();
};
