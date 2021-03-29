/** @file  */

#pragma once

#include <string>

/**
Statyczna metoda pozwalaj�ca na wy�wietlanie �a�cuch�w znakowych z polskimi znakami
@param str �a�cuch znakowy kt�ry chcemy wy�wietli� z polskimi znakami
@return Zwraca �a�cuch znakowy kt�ry mo�na wyswietla� w konsoli z polskimi znakami
*/
static const char* C(const char* str)
{
	static char buff[256];
	char signs[] = "\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215����󜿟��ʣ�ӌ��";
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