/** @file  */

#pragma once

#include <cstdbool>
#include <string>

class Parameters
{
	friend class Management; ///< Zaprzyja�nienie z klas� s�u�ac� do zarz�dzania programem

public:
	Parameters();
	Parameters(std::string[]);

public:
	std::string paths[3]; ///< Atrybut b�d�cy tablic� typu string zawieraj�cy �cie�ki do pliku

	bool Qgraph; ///< Atrybut typu bool zawieraj�cy informacje czy �cie�ka do pliku z grafem zosta�a wczytana z konsoli
	bool Qgrapho; ///< Atrybut typu bool zawieraj�cy informacje czy u�ytkownik chce opisac graf sam

	bool QIO; ///< Atrybut typu bool zawieraj�cy informacje czy �cie�ka do pliku z danymi zosta�a wczytana z konsoli
	bool QIOo; ///< Atrybut typu bool zawieraj�cy informacje czy u�ytkownik chce poda� dane r�cznie

	bool Qsave; ///< Atrybut typu bool zawieraj�cy informacje czy �cie�ka do pliku gdzie ma by� zapisane rozwi�zanie zosta�a wczytana z konsoli
	bool Qsaveg; ///< Atrybut typu bool zawieraj�cy informacje czy zapisa� graf
	bool Qsaved; ///< Atrybut typu bool zawieraj�cy informacje czy zapisa� dane
	bool Qsaves; ///< Atrybut typu bool zawieraj�cy informacje czy zapisa� rozwi�zanie

	bool Qshowg; ///< Atrybut typu bool zawieraj�cy informacje czy wy�wietla� graf
	bool Qshowd; ///< Atrybut typu bool zawieraj�cy informacje czy wy�wietla� dane
	bool Qshows; ///< Atrybut typu bool zawieraj�cy informacje czy wy�wietla� rozwi�zanie
};

