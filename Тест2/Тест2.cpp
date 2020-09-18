#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Test* A=Test::getInstance();//использование паттерна одиночка для создание программы тестирования в единственном экземпляре
	A->OPEN();	
}