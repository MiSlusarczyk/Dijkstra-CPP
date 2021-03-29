/** @file  */

#pragma once
#include "Data.h"

/**
Klasa odpowiedzialna za obs�ug� komunikacji z u�ytkownikiem i pozyskaniem od niego niezb�dnych informacji
*/
class User
{
public:
	bool Calibration(Data*& , std::string p[]);
	bool Ask(Data*&);
};

