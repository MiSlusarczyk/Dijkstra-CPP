/** @file  */

#include "Parameters.h"

/**
Konstruktor domy�lny klasy Parameters
*/
Parameters::Parameters()
{

	size_t size = sizeof(paths) / sizeof(std::string);

	for (size_t i = 0; i < size; i++)
	{
		paths[i] = "\0";
	}

	Qgraph = 0;
	QIO = 0;
	Qsave = 0;

	Qgrapho = 0;
	QIOo = 0;

	Qsaveg = 0;
	Qsaved = 0;
	Qsaves = 0;

	Qshowg = 0;
	Qshowd = 0;
	Qshows = 0;
}

/**
Jednoargumentowy konstruktor klasy Parameters kt�ry przypisuje sobie przekazane �cie�ki do plik�w
*/
Parameters::Parameters(std::string p[])
{
	size_t size = sizeof(paths) / sizeof(std::string);

	for (size_t i = 0; i < size; i++)
	{
		paths[i] = p[i];
	}

	Qgraph = 0;
	QIO = 0;
	Qsave = 0;

	Qgrapho = 0;
	QIOo = 0;

	Qsaveg = 0;
	Qsaved = 0;
	Qsaves = 0;

	Qshowg = 0;
	Qshowd = 0;
	Qshows = 0;
}