#include <stdbool.h>

#define STACK_SIZE 20
#define ERR -1

//Структура стек
struct Stack {
	char* buf;
	int size;
	int hi;
};

//Инициализация стека
void InitStack(struct Stack *st);

//Добавление
void PushStack(struct Stack *st, char symb);

//Показать вершину
char TopStack(struct Stack *st);

//Удалить вершину
void PopStack(struct Stack *st);

//Проверка на полноту
bool FullStack(struct Stack *st);

//Проверка на пустоту
bool EmptyStack(struct Stack *st);

//Очистка стека
void ClearStack(struct Stack *st);

//Перепаковка
void ResizeStack(struct Stack *st);

//Вывод
void PrintStack(struct Stack *st);
