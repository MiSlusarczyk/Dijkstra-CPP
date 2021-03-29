/** @file  */

#pragma once

#include <string>

/**
Statyczna metoda pozwalaj¹ca na wyœwietlanie ³añcuchów znakowych z polskimi znakami
@param str £añcuch znakowy który chcemy wyœwietliæ z polskimi znakami
@return Zwraca ³añcuch znakowy który mo¿na wyswietlaæ w konsoli z polskimi znakami
*/
static const char* C(const char* str)
{
	static char buff[256];
	char signs[] = "\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯";
	if (strlen(str) >= sizeof(buff))
	{
		return str;
	}

	char* bf = buff;
	while (*str)
	{
		char* pos = strchr(signs + 18, *str);
		*(bf++) = pos ? *(pos - 18) : *str;
		++str;
	}
	*bf = 0;
	const char* cstr = buff;
	return cstr;
}