﻿// ConsoleApplication1.cpp : Цей файл містить функцію "main".
// Тут починається і закінчується виконання програми.

#include "pch.h"
#include <iostream>
#include <Windows.h>

int main()
{
	// перша "обов'язкова" програма
	std::cout << "Hello World!\n";
	// додаткові налаштування для правильного введення-виведення кирилиці
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введіть Ваше ім\'я: ";
	// оголошення структури для зберігання імені
	char name[20] = { '\0' };
	std::cin >> name;
	std::cout << "Hello, " << name << "!\n";
	// затримка завершення програми
	system("pause");
	return 0;
}

// Запуск програми: CTRL+F5 або меню "Отладка" > "Запуск без отладки"
// Налагодження програми: F5 або меню "Отладка" > "Запустить отладку"
