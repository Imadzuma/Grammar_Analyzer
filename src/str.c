#include <stdlib.h>
#include <stdio.h>
#include "..\include\str.h"

//Инициализация строки
void InitStr(struct Str *str, int sz, char* s) {
	int i;
	str->size = sz;
	if (sz != 0) {
		str->s = (char*)malloc(sz * sizeof(char));
		for (i = 0; i < sz; ++i)
			str->s[i] = s[i];
	}
}

//Замена
void CopyStr(struct Str *str, int sz, char* s) {
	int i;
	ClearStr(str);
	str->size = sz;
	if (sz != 0) {
		str->s = (char*)malloc(sz * sizeof(char));
		for (i = 0; i < sz; ++i)
			str->s[i] = s[i];
	}
}

//Наличие символа в строке
int FindChar(struct Str * str, char symb)
{
	int i;
	for (i = 0; i < str->size; ++i) {
		if (str->s[i] == symb)
			return i;
	}
	return -1;
}

//Функция для добавления символа в строку
void AddChar(struct Str *str, char symb)
{
	int i;
	if (FindChar(str, symb)!=-1)
		return;
	char* tmp = (char*)malloc((str->size + 1) * sizeof(char));
	for (i = 0; i < str->size; ++i)
		tmp[i] = str->s[i];
	tmp[str->size] = symb;
	if (str->size)
		free(str->s);
	str->s = tmp;
	str->size++;
}

//Добавить символы строки
void AddStr(struct Str *str, struct Str *add_str)
{
	int i;
	for (i = 0; i < add_str->size; ++i) {
		if (FindChar(str, add_str->s[i])==-1)
			AddChar(str, add_str->s[i]);
	}
}

//Проверка на равенство
bool CompareStr(struct Str *str1, struct Str *str2) {
	int i;
	if (str1->size != str2->size)
		return false;
	for (i = 0; i < str1->size; ++i) {
		if (FindChar(str2, str1->s[i])==-1)
			return false;
	}
	return true;
}

//Удаление символа
void DelChar(struct Str * str, char symb)
{
	int i, new_size;
	char* tmp=NULL;
	for (i = 0, new_size=str->size; i < str->size; ++i) {
		if (str->s[i] == symb) 
			new_size--;
	}
	if (new_size == str->size)
		return;
	if (new_size) {
		tmp = (char*)malloc(new_size * sizeof(char));
		for (i = 0, new_size = 0; i < str->size; ++i) {
			if (str->s[i] != symb)
				tmp[new_size++] = str->s[i];
		}
	}
	if (str->size)
		free(str->s);
	str->s = tmp;
	str->size=new_size;
}

//Очистка памяти
void ClearStr(struct Str * str)
{
	if (str->size)
		free(str->s);
}

void PrintStr(struct Str * str)
{
	int i;
	for (i = 0; i < str->size; ++i)
		printf("%c", str->s[i]);
}

