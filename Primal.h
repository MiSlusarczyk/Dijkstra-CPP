/** @file  */

#pragma once

#include <iostream>

/**
Klasa bed�ca odpowiedzialna za liste typu Primal
*/
class Primal
{
public:
	long int number; ///< Numer zadania 
	Primal* pNext; ///< Wska�nik na nast�pny element
	Primal* pPrev; ///< Wska�nik na poprzedni element

	Primal();

	Primal& operator=(const Primal&);

	static bool AddPrimalEnd(Primal*&, Primal*);
	static bool AddPrimalFront(Primal*&, Primal*);
	static bool AddPrimalByNumber(Primal*&, Primal*);
	static bool CopyPrimalList(Primal*&, Primal*);
	static bool CopyPrimal(Primal*&, Primal*);
	static bool DeletePrimalByNumber(Primal*&, long int);
	bool DeletePrimalList();
	bool DeletePrimalEnd(Primal*&);
	static Primal* FindPrimalByNumber(Primal*, long int);
	static bool CheckPrimalByNumber(Primal*, long int);
};

