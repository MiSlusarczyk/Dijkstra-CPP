/** @file  */

#pragma once
#include "Primal.h"

/**
Klasa bed¹ca odpowiedzialna za listê z danymi wejœciowymi
*/
class DataTops
{
	friend class Primal;
public:
	Primal* top; /// <WskaŸnik na wierzcho³ek startowy
	Primal* Dtops; /// <WskaŸnik na listê wierzcho³ków do których chcemy wyznaczyæ trasê
	DataTops* pNext; ///< WskaŸnik na nastêpny element
	DataTops* pPrev; ///< WskaŸnik na poprzedni element
	
	DataTops& operator=(const DataTops&);

	DataTops();

	static bool AddDataTopsEnd(DataTops*&, DataTops*);
	static bool AddDataTopsByTop(DataTops*&, DataTops*);
	static bool CreatePrimalList(Primal*&, DataTops*);
	bool DeleteDataTopsList();
};

