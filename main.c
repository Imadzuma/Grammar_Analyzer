#include <stdio.h>
#include <string.h>
#include "include\grammar.h"

int main(int argc, char** argv) {
	struct Grammar g; //Грамматика
	int i, j; //Переменные для циклов
	int len; //Длина строки
	char str[256];  //строка
	//1. Заполнение полей грамматики (инициализация)

	//Грамматика из задачи
	InitGrammar(&g, 4, "012$", 2, "BS", 'S');
	AddRule(&g, 'S', 2, "B2");
	AddRule(&g, 'B', 1, "0");
	AddRule(&g, 'B', 1, "1");

	////Первая подобранная грамматика
	//InitGrammar(&g, 7, "+-()ab$", 3, "STR", 'S');
	//AddRule(&g, 'S', 2, "TR");
	//AddRule(&g, 'R', 1, "$");
	//AddRule(&g, 'R', 3, "+TR");
	//AddRule(&g, 'R', 3, "-TR");
	//AddRule(&g, 'T', 3, "(S)");
	//AddRule(&g, 'T', 1, "a");
	//AddRule(&g, 'T', 1, "b");

	////Вторая подобранная грамматика
	//InitGrammar(&g, 6, "i+*()$", 5, "EATDF", 'E');
	//AddRule(&g, 'E', 2, "TA");
	//AddRule(&g, 'A', 3, "+TA");
	//AddRule(&g, 'A', 1, "$");
	//AddRule(&g, 'T', 2, "FD");
	//AddRule(&g, 'D', 3, "*FD");
	//AddRule(&g, 'D', 1, "$");
	//AddRule(&g, 'F', 3, "(E)");
	//AddRule(&g, 'F', 1, "i");

	//2. Нахождение FIRST 
	FindFIRST(&g);
	//3. Нахождение FOLLOW 
	FindFOLLOW(&g);
	//4. Создание таблицы
	CreateTable(&g);
	//5. Вывод FIRST, FOLLOW и таблицы на экран
	printf("\tFIRST\tFOLLOW\n");
	for (i = 0; i < g.Vn.size; ++i) {
		printf("%c\t", g.Vn.s[i]);
		PrintStr(&g.FIRST[i]);
		printf("\t");
		PrintStr(&g.FOLLOW[i]);
		printf("\n");
	}
	printf("\n");
	printf("Table:\n");
	for (j = 0; j < g.Vt.size; ++j)
		printf("\t%c", g.Vt.s[j]);
	printf("\n");
	for (i = 0; i<g.Vn.size; ++i) {
		printf("%c\t", g.Vn.s[i]);
		for (j = 0; j < g.Vt.size; ++j) {
			if (g.table[i][j] != -1) {
				printf("%c->", g.P[g.table[i][j]].a);
				PrintStr(&g.P[g.table[i][j]].b);
			}
			else
				printf("Err");
			printf("\t");
		}
		printf("\n");
	}
	printf("\n");
	//6. Запись в логический файл
	WriteInFILE(&g);
	//7. Взаимодействие с пользователем
	printf("Enter string: ");
	fgets(str, 256, stdin);
	len = strlen(str);
	//8. Парсинг
	printf("Parsing: ");
	Parse(&g, len, str);
	return 0;
}