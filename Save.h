/** @file  */

#pragma once

#include <iostream>
#include <fstream>

#include "Data.h"

/**
Klasa zapisuj�ca okre�lone dane do pliku wynikowego
*/
class Save
{
public:
	bool ClearFile(Data*);
	bool SaveGraph(Data*);
	bool SaveData(Data*);
	bool SaveSolution(Data*);
};

