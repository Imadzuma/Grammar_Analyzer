#include <stdbool.h>

//Структура множества неповторяющихся символов
struct Str {
	char* s; //Cтрока
	int size;
};

//Инициализация строки
void InitStr(struct Str *str, int sz, char* s);

//Замена
void CopyStr(struct Str *str, int sz, char* s);

//Наличие символа в строке
int FindChar(struct Str *str, char symb);

//Добавление символа
void AddChar(struct Str *str, char symb);

//Добавить символы строки
void AddStr(struct Str *str, struct Str *add_str);

//Проверка на равенство
bool CompareStr(struct Str *str1, struct Str *str2);

//Удаление символа
void DelChar(struct Str *str, char symb);

//Очистка памяти
void ClearStr(struct Str *str);

//Печать строки
void PrintStr(struct Str *str);