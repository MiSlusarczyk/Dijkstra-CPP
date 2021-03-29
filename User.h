/** @file  */

#pragma once
#include "Data.h"

/**
Klasa odpowiedzialna za obs³ugê komunikacji z u¿ytkownikiem i pozyskaniem od niego niezbêdnych informacji
*/
class User
{
public:
	bool Calibration(Data*& , std::string p[]);
	bool Ask(Data*&);
};

