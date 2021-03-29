/** @file  */

#include "Data.h"

/**
Konstruktor domyœlny klasy Data
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
@param p WskaŸnik na referencje do obiektu typu Parameters w którym przechowywane s¹ dane na temat dzia³ania programu
@param g WskaŸnik na referencje do obiektu typu Graph w którym przechowywany jest graf
@param d WskaŸnik na referencje do obiektu typu DataTops w którym przechowywane s¹ dane wejœciowe
@param s WskaŸnik na referencje do obiektu typu Solution w którym przechowywane jest rozwi¹zanie
*/
Data::Data(Parameters*& p, Graph*& g, DataTops*& d, Solution*& s) 
{
	P = p;
	G = g;
	D = d;
	S = s;
}

/**
Destruktor za którego pomoc¹ jest zwalniana ca³a dynamicznie zarezerwowana pamiêæ w trakcie dzia³ania programu
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