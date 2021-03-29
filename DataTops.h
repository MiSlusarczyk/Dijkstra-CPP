/** @file  */

#pragma once
#include "Primal.h"

/**
Klasa bed�ca odpowiedzialna za list� z danymi wej�ciowymi
*/
class DataTops
{
	friend class Primal;
public:
	Primal* top; /// <Wska�nik na wierzcho�ek startowy
	Primal* Dtops; /// <Wska�nik na list� wierzcho�k�w do kt�rych chcemy wyznaczy� tras�
	DataTops* pNext; ///< Wska�nik na nast�pny element
	DataTops* pPrev; ///< Wska�nik na poprzedni element
	
	DataTops& operator=(const DataTops&);

	DataTops();

	static bool AddDataTopsEnd(DataTops*&, DataTops*);
	static bool AddDataTopsByTop(DataTops*&, DataTops*);
	static bool CreatePrimalList(Primal*&, DataTops*);
	bool DeleteDataTopsList();
};

