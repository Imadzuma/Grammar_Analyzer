#include <stdbool.h>
#include "str.h"

#define END '$' //символ пустой строки

//Структура грамматики
struct Grammar {
	struct Str Vt; //Множество нетерминальных символов
	struct Str Vn; //Множество терминальных символов
	struct Rule {
		char a;
		struct Str b;
	}* P; //правила вывода грамматики
	int S; //номер начального символа грамматики
	int size_P;
	struct Str* FIRST;
	struct Str* FOLLOW;
	int** table;
};

//Инициализация грамматики
void InitGrammar(struct Grammar *g, int term_size, char* term, int state_size, char* state, char start);

//Добавление правила
void AddRule(struct Grammar *g, char from, int size_to, char* to);

//Определение symb как терминального символа
bool IsTerm(struct Grammar *g, char symb);

//Определение symb как нетерминального символа
bool IsState(struct Grammar *g, char symb);

//Функция заполнения множества FIRST
void FindFIRST(struct Grammar *g);

//Функция заполнения множества FOLLOW
void FindFOLLOW(struct Grammar *g);

//Функция нахождения таблицы
void CreateTable(struct Grammar *g);

//Функция печати в лог файл
void WriteInFILE(struct Grammar *g);

//Парсер
bool Parse(struct Grammar *g, int str_size, char* str);