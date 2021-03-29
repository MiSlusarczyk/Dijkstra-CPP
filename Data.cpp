/** @file  */

#include "Data.h"

/**
Konstruktor domy�lny klasy Data
*/
Data::Data()
{
	P = nullptr;
	G = nullptr;
	D = nullptr;
	S = nullptr;
}

/**
Wieloargumentowy konstruktor klasy Data do zapisu danych z klasy Management
@param p Wska�nik na referencje do obiektu typu Parameters w kt�rym przechowywane s� dane na temat dzia�ania programu
@param g Wska�nik na referencje do obiektu typu Graph w kt�rym przechowywany jest graf
@param d Wska�nik na referencje do obiektu typu DataTops w kt�rym przechowywane s� dane wej�ciowe
@param s Wska�nik na referencje do obiektu typu Solution w kt�rym przechowywane jest rozwi�zanie
*/
Data::Data(Parameters*& p, Graph*& g, DataTops*& d, Solution*& s) 
{
	P = p;
	G = g;
	D = d;
	S = s;
}

/**
Destruktor za kt�rego pomoc� jest zwalniana ca�a dynamicznie zarezerwowana pami�� w trakcie dzia�ania programu
*/
Data::~Data()
{
	delete P;
	P = nullptr;

	G->DeleteGraphList();
	G = nullptr;

	D->DeleteDataTopsList();
	D = nullptr;

	S->DeleteSolutionList();
	S = nullptr;
}