/** @file  */

#pragma once

#include <iostream>

#include "Primal.h"
#include "DataTops.h"

/**
Klasa bed�ca odpowiedzialna za list� z s�siadami wierzcho�ka startowego
*/
class Borderer : public Primal
{
public:
	double metrics; ///< Odleg�o�� do danego s�siedniego wierzcho�ka
	Borderer* pNext; ///< Wska�nik na nast�pny element
	Borderer* pPrev; ///< Wska�nik na poprzedni element

	Borderer();
	Borderer& operator=(const Borderer&);

	static bool AddBordererEnd(Borderer*&, Borderer*);
	static bool AddBordererByNumber(Borderer*&, Borderer*);
	static Borderer* FindBordererByNumber(Borderer*, long int);
	bool DeleteBordererList();
};
