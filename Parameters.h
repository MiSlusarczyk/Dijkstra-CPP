/** @file  */

#pragma once

#include <cstdbool>
#include <string>

class Parameters
{
	friend class Management; ///< ZaprzyjaŸnienie z klas¹ s³u¿ac¹ do zarz¹dzania programem

public:
	Parameters();
	Parameters(std::string[]);

public:
	std::string paths[3]; ///< Atrybut bêd¹cy tablic¹ typu string zawieraj¹cy œcie¿ki do pliku

	bool Qgraph; ///< Atrybut typu bool zawieraj¹cy informacje czy œcie¿ka do pliku z grafem zosta³a wczytana z konsoli
	bool Qgrapho; ///< Atrybut typu bool zawieraj¹cy informacje czy u¿ytkownik chce opisac graf sam

	bool QIO; ///< Atrybut typu bool zawieraj¹cy informacje czy œcie¿ka do pliku z danymi zosta³a wczytana z konsoli
	bool QIOo; ///< Atrybut typu bool zawieraj¹cy informacje czy u¿ytkownik chce podaæ dane rêcznie

	bool Qsave; ///< Atrybut typu bool zawieraj¹cy informacje czy œcie¿ka do pliku gdzie ma byæ zapisane rozwi¹zanie zosta³a wczytana z konsoli
	bool Qsaveg; ///< Atrybut typu bool zawieraj¹cy informacje czy zapisaæ graf
	bool Qsaved; ///< Atrybut typu bool zawieraj¹cy informacje czy zapisaæ dane
	bool Qsaves; ///< Atrybut typu bool zawieraj¹cy informacje czy zapisaæ rozwi¹zanie

	bool Qshowg; ///< Atrybut typu bool zawieraj¹cy informacje czy wyœwietlaæ graf
	bool Qshowd; ///< Atrybut typu bool zawieraj¹cy informacje czy wyœwietlaæ dane
	bool Qshows; ///< Atrybut typu bool zawieraj¹cy informacje czy wyœwietlaæ rozwi¹zanie
};

