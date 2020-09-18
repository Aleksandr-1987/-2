#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<conio.h>
#include <cstdio> 
using namespace std;

class User
{
public:
	string name, adress, fone, log, passw;
	User() { name = "-", adress = "-", fone = "-", log = "-", passw = "-"; }
	~User() {}
	User(string n, string a, string f, string l, string p) { name = n; adress = a; fone = f; log = l; passw = p; }
	User(const User& ch) { name = ch.name; adress = ch.adress; fone = ch.fone; log = ch.log; passw = ch.passw; }
	User& operator=(const User& obj) { name = obj.name; adress = obj.adress; fone = obj.fone; log = obj.log; passw = obj.passw; return *this; }
	void print(){
		cout << "Фамилия И.О. пользователя    : " << name << endl;
		cout << "Адрес эл. почты пользователя : " << adress << endl;
		cout << "Номер телефона пользователя  : " << fone << endl;
		cout << "Логин пользователя           : " << log << endl;
		cout << "Пароль пользователя : " << passw << endl;
	}
};

class Vopros
{
public:
	string vopr, var1, var2, var3, var4,prav;
	Vopros() { vopr = "-", var1 = "-", var2 = "-", var3 = "-", var4 = "-", prav = "-"; }
	~Vopros() {}
	Vopros(string v, string v1, string v2, string v3, string v4, string p) { vopr = v; var1 = v1; var2 = v2; var3 = v3; var4 = v4, prav = p; }
	Vopros(const Vopros& ch) { vopr = ch.vopr; var1 = ch.var1; var2 = ch.var2; var3 = ch.var3; var4 = ch.var4; prav = ch.prav; }
	Vopros& operator=(const Vopros& obj) { vopr = obj.vopr; var1 = obj.var1; var2 = obj.var2; var3 = obj.var3; var4 = obj.var4; prav = obj.prav; return *this; }
	void print(){
		cout << vopr << endl;
		cout << var1 << endl;
		cout << var2 << endl;
		cout << var3 << endl;
		cout << var4 << endl;
		cout << prav << endl;
	}
};

class tests
{
public:
	string nazv; Vopros* voprosy; 
	tests() { nazv = "-", voprosy = nullptr; }
	~tests() { delete[]voprosy; }
	tests(const tests& ch) { nazv = ch.nazv; voprosy = ch.voprosy;}
	tests& operator=(const tests& obj) { nazv = obj.nazv; voprosy = obj.voprosy; return *this; }
};

class Kategor
{
public:
	string nazvkateg; tests* testy; 
	Kategor() { nazvkateg = "-", testy = nullptr; }
	~Kategor() { delete[]testy; }
	Kategor(const Kategor& ch) { nazvkateg = ch.nazvkateg; testy = ch.testy; }
	Kategor& operator=(const Kategor& obj) { nazvkateg = obj.nazvkateg; testy = obj.testy; return *this; }
};

class Test
{
	int kolpr, prozpr, ozenka;
	string login, parol;
	static Test* obj;
	User* polzovateli; int kolpolzov;// указатель на массив пользователей, длина массива
	Kategor* kategorii; int nkateg;// указатель на массив категорий, длина массива	
	Test() {kolpr = 0, prozpr = 0, ozenka = 0; login = "", parol = ""; polzovateli = nullptr; kolpolzov = 0; kategorii = nullptr; nkateg = 0;}
	~Test() { delete[]polzovateli; delete[]kategorii;}
	Test(const Test& ch) { kolpr = ch.kolpr; prozpr = ch.prozpr; ozenka = ch.ozenka; login = ch.login; parol = ch.parol; polzovateli = ch.polzovateli; kolpolzov = ch.kolpolzov; kategorii = ch.kategorii; nkateg = ch.nkateg;	}
	Test& operator=(const Test& obj) { kolpr = obj.kolpr; prozpr = obj.prozpr; ozenka = obj.ozenka; login = obj.login; parol = obj.parol; polzovateli = obj.polzovateli; kolpolzov = obj.kolpolzov; kategorii = obj.kategorii; nkateg = obj.nkateg; return *this; }
public:
	static Test* getInstance(){	if (!obj) { obj = new Test(); }	return obj;	} //паттерн одиночка
	void OPEN()
	{
		cout << "             Вас приветствует программа тестирования." << endl;
		char ch;
		do	{
			cout << "1 - Войти в систему в режите пользователя;\n";
			cout << "2 - Войти в систему в режите администратора;\n";
			cout << "0 - Выход из программы тестирования\n";
			cin >> ch; cin.ignore();
			switch (ch)	{
			case '1':
				Users();
				break;
			case '2':
				Admin();
				break;
			}
		} while (ch != '0');
	}
private:
	void Admin()
	{
		string par;	char ch; int c = 0;
		cout << "Введите пароль администратора:" << endl;
		while (true){//шифрование ввода
			c = _getch();
			if (c == 0)	c = _getch();
			if (c == '\r' || c == '\n')	break;
			cout << '*'; par += c;
		}	cout << endl;
		if (par == "777") {
			do {
				cout << "1 - Создать пользователя;\n";
				cout << "2 - Изменить пользователя;\n";
				cout << "3 - Удалить пользователя\n";
				cout << "4 - Просмотр результатов тестирования по конкретным пользователям\n";
				cout << "5 - Просмотр результатов тестирования по конкретным тестам\n";
				cout << "6 - Просмотр результатов тестирования по категориям\n";
				cout << "7 - Управление тестированием\n";
				cout << "0 - Назад к главному меню\n";
				cin >> ch; cin.ignore();
				switch (ch) {
				case '1':
					addUser();
					break;
				case '2':
					izmenUser();
					break;
				case '3':
					dellUser();
					break;
				case '4':
					seenUser();
					break;
				case '5':
					seenTest();
					break;
				case '6':
					seenKategor();
					break;
				case '7':
					testizmen();
					break;
				}
			} while (ch != '0');
		}
		else cout << "Вы ввели неверный пароль!" << endl; par = "";//очистка пароля 
	}
	void testizmen()
	{
		char ch;
		do	{
			cout << "1 - Добавить новую категорию;\n";
			cout << "2 - Изменить категорию\n";
			cout << "3 - Добавить новый раздел в категорию\n";
			cout << "4 - Изменить раздел в категории\n";
			cout << "5 - Добавить вопрос в раздел категории\n";			
			cout << "6 - Изменить вопрос в разделе категории\n";
			cout << "0 - Назад к главному меню\n";
			cin >> ch; cin.ignore();
			switch (ch)	{
			case '1':
				void addKateg();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close(); string im;//считывание из файла количества категорий
					cout << "Введите название новой категории:" << endl; getline(cin, im);					
					ofstream out; out.open("Kategg.txt", ios::app); out.close(); string t; int z = 0;//если категорий нет, то создание пустого файла 
					do {//проверка на совпадение категорий
						ifstream in("Kategg.txt");	char buff[200]; z = 0;
						for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); t = buff;if (im == t)z++;}	in.close();
						if (z != 0)	{cout << "Такая категория уже существует, пожалуйста введите другую категорию: " << endl;getline(cin, im); }
					} while (z != 0);
					ofstream Out; Out.open("Kategg.txt", ios::app);	Out << im << endl;	Out.close();//запись новой категории в файл
					int temp = nkateg + 1; ofstream Oout; Oout.open("Kolkat.txt"); Oout << temp; Oout.close();//перезапись количества категорий
					cout << "Категория добавлена!" << endl;					
				}
				break;			
			case '2':
				void izmendKateg();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
					kategorii = new Kategor[nkateg];//создание массива категорий
					ifstream in("Kategg.txt");	char buff[200];
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;}in.close(); //заполнение массива категорий из файла
					int np; string newn;
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//вывод категорий на экран
					cout << "Введите номер категории, данные которого вы желаете изменить:" << endl;
					cin >> np; cin.ignore();
					cout << "Укажите новое название категории:" << endl;
					getline(cin, newn);	 kategorii[np - 1].nazvkateg = newn; //изменение категории						
					ofstream out; out.open("Kategg.txt");  for (size_t i = 0; i < nkateg; i++) {out << kategorii[i].nazvkateg << endl;}out.close(); //перезапись категорий в файл
					cout << "Данные о категории изменены!" << endl;
				}
				break;
			case '3':
				void addRazdel();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
					kategorii = new Kategor[nkateg];//создание массива категорий
					ifstream in("Kategg.txt");	char buff[200]; 
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;}	in.close(); //заполнение массива категорий из файла
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	} //вывод категорий на экран					 
					cout << "Введите номер категории, в которую Вы хотите добавить раздел:" << endl;
					string np; cin >> np; cin.ignore();
					cout << "Введите название нового раздела:" << endl;
					string nov; getline(cin, nov);
					int z = 0; string temp; string file = np + "razd.txt";
					ofstream out; out.open(file, ios::app); out.close();//если разделов нет, то создание пустого файла
					do {//проверка на совпадение категорий
						ifstream in(file);char buff[200]; z = 0;
						while (!in.eof()){	in.getline(buff, 200); temp = buff;	if (temp == nov)z++;}in.close();
						if (z != 0)	{cout << "Такой раздел уже существует, пожалуйста введите другой раздел: " << endl;	getline(cin, nov);	}
					} while (z != 0);
					ofstream out1; out1.open(file, ios::app);out1 << nov << endl;out1.close();//запись нового раздела в файл
					cout << "Раздел успешно добавлен!" << endl;
				}
				break;			
			case '4':
				void izmenRazdel();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
					kategorii = new Kategor[nkateg];//создание массива категорий
					ifstream in("Kategg.txt");	char buff[200]; 
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //заполнение массива категорий из файла
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//вывод категорий на экран
					cout << "Введите номер категории, в которой Вы хотите изменить раздел:" << endl;
					string np; cin >> np; cin.ignore();
					string file = np + "razd.txt";	ofstream out; out.open(file, ios::app); out.close();//если разделов нет, то создание пустого файла
					ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//подсчет количества разделов в файле
					tests* razd = new tests[i - 1];//создание массива разделов
					ifstream in2(file); for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close(); //заполнение массива разделов из файла
					cout << "Укажите номер раздела, который Вы желаете изменить:" << endl;
					for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//вывод разделов на экран
					int nk; cin >> nk; cin.ignore();
					cout << "Укажите новое название раздела:" << endl;
					string newn; getline(cin, newn); razd[nk - 1].nazv = newn;//изменение раздела
					ofstream out2; out2.open(file);	for (size_t z = 0; z < i - 1; z++){	out2 << razd[z].nazv << endl;}out2.close();//перезапись категорий в файл					
					cout << "Данные о разделе изменены!" << endl;
				}
				break;
			case '5':
				void addvopros();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
					kategorii = new Kategor[nkateg];//создание массива категорий
					ifstream in("Kategg.txt");	char buff[200]; 
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;}	in.close();//заполнение массива категорий из файла 
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//вывод категорий на экран
					cout << "Введите номер категории, в раздел которой, Вы хотите добавить вопрос:" << endl;
					string np; cin >> np; cin.ignore();
					string file = np + "razd.txt"; ofstream out; out.open(file, ios::app); out.close();//если разделов нет, то создание пустого файла
					ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//подсчет количества разделов в файле
					tests* razd = new tests[i - 1];//создание массива разделов
					ifstream in2(file); for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close(); //заполнение массива разделов из файла
					cout << "Укажите номер раздела, в который вы хотите добавить вопрос:" << endl;
					for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//вывод разделов на экран
					string nk; cin >> nk; cin.ignore();					
					string vopr, v1, v2, v3, v4, pr;
					cout << "Введите вопрос для добавления:" << endl;
					getline(cin, vopr);
					cout << "Укажите первый вариант ответа:" << endl;
					getline(cin, v1);
					cout << "Укажите второй вариант ответа:" << endl;
					getline(cin, v2);
					cout << "Укажите третий вариант ответа:" << endl;
					getline(cin, v3);
					cout << "Укажите четвертый вариант ответа:" << endl;
					getline(cin, v4);
					cout << "Укажите номер правильного ответа:" << endl;
					getline(cin, pr);					
					string file2 = np + nk + "vopr.txt"; ofstream out2; out2.open(file2, ios::app);//запись вопроса в файл
					out2 << vopr << endl;out2 << v1 << endl;out2 << v2 << endl;	out2 << v3 << endl;	out2 << v4 << endl;	out2 << pr << endl;	out2.close();
					cout << "Вопрос успешно добавлен!" << endl;		delete[]razd;
				}
				break;			
			case '6':
				void izmenvopros();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
					kategorii = new Kategor[nkateg];//создание массива категорий
					ifstream in("Kategg.txt");	char buff[200];
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;} in.close(); //заполнение массива категорий из файла
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//вывод категорий на экран
					cout << "Введите номер категории, в разделе которой, Вы хотите изменить вопрос:" << endl;
					string np; cin >> np; cin.ignore();
					string file = np + "razd.txt";	ofstream out; out.open(file, ios::app); out.close();//если разделов нет, то создание пустого файла
					ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//подсчет количества разделов в файле
					tests* razd = new tests[i - 1];//создание массива разделов
					ifstream in2(file);	for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close();//заполнение массива разделов из файла 
					cout << "Укажите номер раздела, в который вы хотите изменить вопрос:" << endl;
					for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//вывод разделов на экран
					string nk; cin >> nk; cin.ignore();
					string file2 = np + nk + "vopr.txt"; ifstream inn2(file2);
					int i2 = -1;while (!inn2.eof()) { inn2.getline(buff, 200); i2++; }	inn2.close();//подсчет количества вопросов в разделе
					Vopros* voprosy = new Vopros[i2 / 6];//создание массива вопросов
					ifstream inn3(file2);  
					for (size_t z = 0; z < i2 / 6; z++)	{//заполнение масива вопросов из файла
						inn3.getline(buff, 200); voprosy[z].vopr = buff;
						inn3.getline(buff, 200); voprosy[z].var1 = buff;
						inn3.getline(buff, 200); voprosy[z].var2 = buff;
						inn3.getline(buff, 200); voprosy[z].var3 = buff;
						inn3.getline(buff, 200); voprosy[z].var4 = buff;
						inn3.getline(buff, 200); voprosy[z].prav = buff;
					}inn3.close();
					for (size_t z = 0; z < i2 / 6; z++)	{voprosy[z].print();}//вывод вопросов на экран
					cout << "Введите номер вопроса который Вы желаете изменить:" << endl;
					int nv; cin >> nv;
					do	{
						cout << "1 - Изменить вопрос;\n";
						cout << "2 - Изменить первый вариант ответа;\n";
						cout << "3 - Изменить второй вариант ответа;\n";
						cout << "4 - Изменить третий вариант ответа; \n";
						cout << "5 - Изменить четвертый вариант ответа;\n";
						cout << "6 - Изменить номер правильного варианта ответа;\n";
						cout << "0 - Назад к главному меню\n";
						cin >> ch; cin.ignore(); string newn;
						switch (ch)	{
						case '1':
							cout << "Введите новый вопрос:\n";
							getline(cin, newn);	 voprosy[nv - 1].vopr = newn;
							break;
						case '2':
							cout << "Введите первый вариант ответа:\n";
							getline(cin, newn);	 voprosy[nv - 1].var1 = newn;
							break;
						case '3':
							cout << "Введите второй вариант ответа:\n";
							getline(cin, newn);	 voprosy[nv - 1].var2 = newn;
							break;
						case '4':
							cout << "Введите третий вариант ответа:\n";
							getline(cin, newn);	 voprosy[nv - 1].var3 = newn;
							break;
						case '5':
							cout << "Введите четвертый вариант ответа:\n";
							getline(cin, newn);	 voprosy[nv - 1].var4 = newn;
							break;
						case '6':
							cout << "Введите номер правильного варианта ответа:\n";
							getline(cin, newn);	 voprosy[nv - 1].prav = newn;
							break;
						}
					} while (ch != '0');
					ofstream out4; out4.open(file2);//перезапись вопросов в файл
					for (size_t i = 0; i < i2/6; i++){
						out4 << voprosy[i].vopr << endl;
						out4 << voprosy[i].var1 << endl;
						out4 << voprosy[i].var2 << endl;
						out4 << voprosy[i].var3 << endl;
						out4 << voprosy[i].var4 << endl;
						out4 << voprosy[i].prav << endl;
					}out4.close(); 
					cout << "Данные о вопросе изменены!" << endl;
					delete[]razd; delete[]voprosy;
				}
				break;
			}
		} while (ch != '0');
	}
	void addUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//считывание из файла количества пользователей
		string im, a, f, l, p; hash<string> t; 
		cout << "Введите Ф.И.О. пользователя:" << endl;
		getline(cin, im);
		cout << "Укажите адрес эл. почты пользователя:" << endl;
		getline(cin, a);
		cout << "Введите номер телефона пользователя:" << endl;
		getline(cin, f);
		cout << "Укажите логин пользователя:" << endl;
		getline(cin, l); 
		cout << "Введите пароль пользователя:" << endl;
		getline(cin, p); 
		User N(im, a, f, l, p);  User n; int z = 0;		
		ofstream out; out.open("User.txt", ios::app); out.close();
		do {//проверка на совпадение пользователей
			ifstream in("User.txt");char buff[200]; z = 0;
			for (size_t i = 0; i < kolpolzov; i++)	{
				in.getline(buff, 200); n.name = buff;
				in.getline(buff, 200); n.adress = buff;
				in.getline(buff, 200); n.fone = buff;
				in.getline(buff, 200); n.log = buff;
				in.getline(buff, 200); n.passw = buff; 
				if (n.log == l)z++;
			}	in.close();
			if (z != 0)	{cout << "Такой логин уже существует, пожалуйста введите другой логин: " << endl;getline(cin, l); N.log = l;}
		} while (z != 0);
		ofstream Out; Out.open("User.txt", ios::app);//добавление нового пользователя		
		Out << N.name << endl; Out << N.adress << endl; Out << N.fone << endl; Out << N.log << endl;Out << t(N.passw) << endl;Out.close();
		int temp = kolpolzov + 1; ofstream Oout; Oout.open("Kolp.txt"); Oout << temp; Oout.close();//перезапись количества пользователей
		cout << "Пользователь добавлен!" << endl;		
	}
	void izmenUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//считывание из файла количества пользователей
		polzovateli = new User[kolpolzov];//создание масива пользователей
		ifstream in("User.txt");char buff[200];
		for (size_t i = 0; i < kolpolzov; i++)	{//заполнение масива пользователей из файла
			in.getline(buff, 200); polzovateli[i].name = buff;
			in.getline(buff, 200); polzovateli[i].adress = buff;
			in.getline(buff, 200); polzovateli[i].fone = buff;
			in.getline(buff, 200); polzovateli[i].log = buff;
			in.getline(buff, 200); polzovateli[i].passw = buff;
		}	in.close(); 		 
		for (size_t i = 0; i < kolpolzov; i++)	{cout<<i+1<<"."<<" ", polzovateli[i].print();}//вывод пользователей на экран
		cout << "Введите номер пользователя, данные которого вы желаете изменить:" << endl;
		char ch; hash<string> t; int np;  cin >> np;
		do	{//изменение данных о пользователе
			cout << "1 - Изменение имени пользователя;\n";
			cout << "2 - Изменение адреса эл. почты пользователя;\n";
			cout << "3 - Изменение номера телефона пользователя\n";
			cout << "4 - Изменение логина пользовпароля \n";
			cout << "5 - Изменение пароля пользователя\n";
			cout << "0 - Назад к главному меню\n";
			cin >> ch; cin.ignore(); string newn;
			switch (ch)	{
			case '1':
				cout << "Введите новое имя пользователя;\n"; 
				getline(cin, newn);	 polzovateli[np - 1].name = newn;
				break;
			case '2':
				cout << "Введите новый адрес эл. почты пользователя;\n";
				getline(cin, newn); polzovateli[np - 1].adress = newn;
				break;
			case '3':
				cout << "Введите новый номер телефона пользователя;\n";
				getline(cin, newn); polzovateli[np - 1].fone = newn;
				break;
			case '4':
				cout << "Введите новый логин пользователя;\n";
				getline(cin, newn); polzovateli[np - 1].log = newn;
				break;
			case '5':
				cout << "Введите новый пароль пользователя;\n";
				getline(cin, newn); polzovateli[np - 1].passw = t(newn);
				break;
			}
		} while (ch != '0');
		ofstream out; out.open("User.txt");
		for (size_t i = 0; i < kolpolzov; i++){//перезапись пользователей в файл
			out << polzovateli[i].name << endl;
			out << polzovateli[i].adress << endl;
			out << polzovateli[i].fone << endl;
			out << polzovateli[i].log << endl;
			out << polzovateli[i].passw << endl;
		}	out.close(); 
		cout << "Данные о пользователе изменены!" << endl;
	}
	void dellUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//считывание из файла количества пользователей
		polzovateli = new User[kolpolzov];//создание масива пользователей
		ifstream in("User.txt"); char buff[200];
		for (size_t i = 0; i < kolpolzov; i++)	{//заполнение масива пользователей из файла
			in.getline(buff, 200); polzovateli[i].name = buff;
			in.getline(buff, 200); polzovateli[i].adress = buff;
			in.getline(buff, 200); polzovateli[i].fone = buff;
			in.getline(buff, 200); polzovateli[i].log = buff;
			in.getline(buff, 200); polzovateli[i].passw = buff;
		} in.close(); 		
		for (size_t i = 0; i < kolpolzov; i++)	{cout << i + 1 << "." << " ", polzovateli[i].print(); } //вывод пользователей на экран
		cout << "Введите номер пользователя, которого вы желаете удалить:" << endl;
		int np;  cin >> np;
		for (size_t i = np-1; i < kolpolzov - 1; i++){	polzovateli[i] = polzovateli[i + 1];}//удаление пользователя
		string nn = polzovateli[np - 1].log + ".txt"; remove(nn.c_str());//удаление файла пользователя
		ofstream out; out.open("User.txt");
		for (size_t i = 0; i < kolpolzov-1; i++){//перезапись в файл нового масива пользователей
			out << polzovateli[i].name << endl;
			out << polzovateli[i].adress << endl;
			out << polzovateli[i].fone << endl;
			out << polzovateli[i].log << endl;
			out << polzovateli[i].passw << endl;
		}	out.close(); 
		int temp = kolpolzov - 1; ofstream Oout; Oout.open("Kolp.txt"); Oout << temp; Oout.close();//перезапись количества пользователей
		cout << "Пользователь удален!" << endl;
	}	
	void seenUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//считывание из файла количества пользователей
		polzovateli = new User[kolpolzov];//создание масива пользователей
		ifstream in("User.txt");char buff[200];
		for (size_t i = 0; i < kolpolzov; i++)	{//заполнение масива пользователей из файла
			in.getline(buff, 200); polzovateli[i].name = buff;
			in.getline(buff, 200); polzovateli[i].adress = buff;
			in.getline(buff, 200); polzovateli[i].fone = buff;
			in.getline(buff, 200); polzovateli[i].log = buff;
			in.getline(buff, 200); polzovateli[i].passw = buff;
		}	in.close(); 		
		for (size_t i = 0; i < kolpolzov; i++)	{cout << i + 1 << "." << " " << polzovateli[i].name << endl;}//вывод пользователей на экран
		cout << "Введите номер пользователя, чтобы просмотреть его результаты тестирования:" << endl;
		int np; cin >> np;
		string file = polzovateli[np-1].log + ".txt"; ofstream out; out.open(file, ios::app); out.close();//если файл с пользователями не создан, создаем его
		ifstream inn(file);	while (!inn.eof()) {inn.getline(buff, 200); cout << buff << endl;}	inn.close();//вывод на экран результатов тестирования	
	}
	void seenTest()
	{
		ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
		kategorii = new Kategor[nkateg];//создание масива категорий
		ifstream in("Kategg.txt");	char buff[200];
		for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //заполнение масива категорий из файла	
		cout << "Введите категорию:" << endl;		
		for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//вывод категорий на экран		
		string np; cin >> np;
		string file = np+ "razd.txt"; ofstream out; out.open(file, ios::app); out.close(); //если файл с разделами не создан, создаем его
		cout << "Выберите раздел для просмотра результатов тестирования:" << endl;
		ifstream inn(file);
		 int i = 1;
		while (!inn.eof()) {inn.getline(buff, 200); cout << i++ << "." << " "<< buff << endl; }	inn.close(); //вывод разделов на экран
		string tp;	cin>> tp;
		string file2 = np +tp+ ".txt";	ofstream out1; out1.open(file2, ios::app); out1.close();//если файл с результатами тестирования не создан, создаем его
		ifstream inn1(file2); while (!inn1.eof()) {	inn1.getline(buff, 200); cout << buff << endl;}	inn1.close();//вывод на экран результатов тестирования
	}
	void seenKategor()
	{
		ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
		kategorii = new Kategor[nkateg];//создание масива категорий
		ifstream in("Kategg.txt");	char buff[200];
		for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //заполнение масива категорий из файла
		for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	} //вывод категорий на экран	
		cout << "Введите номер категории, чтобы увидеть ее результаты тестирования:" << endl;
		string np; cin >> np;
		string file = np + ".txt"; ofstream out; out.open(file, ios::app); out.close();//если файл с результатами тестирования не создан, создаем его
		ifstream inn(file);	while (!inn.eof()) {inn.getline(buff, 200); cout << buff << endl;}	inn.close();//вывод на экран результатов тестирования
	}
	void Users()
	{
		char ch;		
		do	{
			cout << "1 - Войти в систему по логину и паролю;\n";
			cout << "2 - Зарегистрироваться;\n";
			cout << "0 - Назад к главному меню\n";
			cin >> ch; cin.ignore();
			switch (ch)	{
			case '1':
				vhod();
				break;
			case '2':
				registr();
				break;
			}
		} while (ch != '0');
	}
	void registr()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//считывание из файла количества пользователей
		string im, a, f, l, p; hash<string> t; int c = 0;
		cout << "Введите Ваши Ф.И.О.:" << endl;
		getline(cin, im);		
		cout << "Укажите адрес Вашей эл. почты:" << endl;
		getline(cin, a);
		cout << "Введите Ваш номер телефона:" << endl;
		getline(cin, f);
		cout << "Укажите Ваш логин:" << endl;
		getline(cin, l); 
		cout << "Введите Ваш пароль:" << endl;		
		while (true) {//шифрование ввода
			c = _getch();
			if (c == 0)	c = _getch();
			if (c == '\r' || c == '\n')	break;
			cout << '*'; p += c;
		} cout << endl;		
		User N(im, a, f, l, p); User n; int z = 0; 		
		ofstream out; out.open("User.txt", ios::app); out.close();//если файл с пользователями не создан, создаем его
		do {
			ifstream in("User.txt"); char buff[200]; z = 0; 
			while (!in.eof()) {//проверка на совпадение пользователей
				in.getline(buff, 200); n.name = buff;
				in.getline(buff, 200); n.adress = buff;
				in.getline(buff, 200); n.fone = buff;
				in.getline(buff, 200); n.log = buff; 
				in.getline(buff, 200); n.passw = buff; 
				if (n.log == l)z++;       
			}	in.close();
			if (z != 0) {cout << "Такой логин уже существует, пожалуйста введите другой логин: " << endl;getline(cin, l); N.log = l; }			
		} while (z != 0);		
		out.open ("User.txt", ios::app); //дописываем нового пользователя
		out << N.name << endl;out << N.adress << endl;	out << N.fone << endl;	out << N.log << endl;	out << t(N.passw) << endl;	out.close();		
		cout << "Регистрация успешно завершена!" << endl; p = "";//очистка пароля 		
		int temp = kolpolzov + 1; ofstream Oout; Oout.open("Kolp.txt"); Oout << temp; Oout.close();//изменение количества пользователей
	}
	void vhod()
	{
		double ps; hash<string> t;	int c3 = 0;
		cout << "Введите свой логин:" << endl;
		getline(cin, login); 
		cout << "Введите свой пароль:" << endl;
		while (true) {//шифрование ввода
			c3 = _getch();
			if (c3 == 0)	c3 = _getch();
			if (c3 == '\r' || c3 == '\n')	break;
			cout << '*'; parol += c3;
		} cout << endl;	
		ps = t(parol);	
		ofstream out; out.open("User.txt", ios::app); out.close();//если файл с пользователями не создан, создаем его
		ifstream in("User.txt");char buff[200]; User n; int z = 0; char ch;
		while (!in.eof()) {//проверка логина и пароля
			in.getline(buff, 200); n.name = buff;
			in.getline(buff, 200); n.adress = buff;
			in.getline(buff, 200); n.fone = buff;
			in.getline(buff, 200); n.log = buff; 
			in.getline(buff, 200); n.passw = buff; double val2 = atof(buff); 
			if (login == n.log && val2 == ps)z++;
		}	in.close();
		if (z == 1) {
			do	{
				cout << "1 - Просмотреть свои предыдущие результаты тестирования;\n";
				cout << "2 - Сдать новое тестирование;\n";
				cout << "0 - Назад к меню авторизации.\n";
				cin >> ch;
				switch (ch)	{
				case '1':
					showres();
					break;
				case '2':
					testirovanie();
					clear();
					break;
				}
			} while (ch != '0');
		}
		else cout << "Вы указали неверный логин или пароль!" << endl; parol = "";//очистка пароля 
	}
	void showres()
	{
		string file = login + ".txt";ofstream out; out.open(file, ios::app); out.close(); //если файл пользователя не создан, создаем его
		ifstream in(file);	char buff[200];	while (!in.eof()) {	in.getline(buff, 200); cout << buff << endl;}in.close();//считывание данных с файла пользователя		
	}
	void testirovanie()
	{
		ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//считывание из файла количества категорий
		kategorii = new Kategor[nkateg];//создание масива категорий
		ifstream in("Kategg.txt");	char buff[200]; 		
		for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //заполнение масива категорий из файла
		for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//вывод категорий на экран
		cout << "Введите номер категории, в которой Вы хотите пройти тестирование:" << endl;
		string np; cin >> np; cin.ignore(); 
		string file = np + "razd.txt"; 
		ofstream out; out.open(file, ios::app); out.close();//если файл с разделами не создан, создаем его
		ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//подсчет количества разделов в файле
		tests* razd = new tests[i - 1];//создание масива разделов
		ifstream in2(file); for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close();//заполнение масива разделов из файла 
		cout << "Укажите номер раздела, для прохождения тестирования:" << endl;
		for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//вывод разделов на экран
		string nk; cin >> nk; cin.ignore(); 
		string file2 = np + nk + "vopr.txt"; ifstream in3(file2);
		int y = -1;	while (!in3.eof()) { in3.getline(buff, 200); y++; } in3.close();//подсчет количества вопросов в разделе
		Vopros* voprosy = new Vopros[y / 6]; //создание масива вопросов
		ifstream in4(file2); string ot;
		for (size_t i = 0; i < y/6; i++){//заполнение масива вопросов из файла
			in4.getline(buff, 200); voprosy[i].vopr = buff;
			in4.getline(buff, 200); voprosy[i].var1 = buff;
			in4.getline(buff, 200); voprosy[i].var2 = buff;
			in4.getline(buff, 200); voprosy[i].var3 = buff;
			in4.getline(buff, 200); voprosy[i].var4 = buff;
			in4.getline(buff, 200); voprosy[i].prav = buff;
		}	in4.close(); 		
		for (size_t i = 0; i < y/6; i++){//тестирование
			cout << voprosy[i].vopr << endl;
			cout << voprosy[i].var1 << endl;
			cout << voprosy[i].var2 << endl;
			cout << voprosy[i].var3 << endl;
			cout << voprosy[i].var4 << endl;
			cin >> ot;if(ot== voprosy[i].prav) { kolpr++; }//подсчет количества правильных ответов
		}
		cout << "Тест завершен!" << endl;
		cout << "Количество правильно отвеченных вопросов: " << kolpr << endl;
		double p = ((float)kolpr / (y / 6)) * 100;	prozpr = p;
		cout << "Процент правильных ответов: " << prozpr << "%" << endl;
		double b = (float)kolpr * (12/((float)y/6)); ozenka = b;
		cout << "Полученная оценка: " << ozenka << endl;

		const time_t timer = time(0); int k1 = atoi(np.c_str()); int k = atoi(nk.c_str());
		ofstream out3; string file3 = login + ".txt"; out3.open(file3, ios::app);//сохранение результатов тестирования в файл конкретного пользователя
		out3 <<kategorii[k1-1].nazvkateg<<" "<< razd[k - 1].nazv<<" "<< ctime(&timer);
		out3 << "Количество правильно отвеченных вопросов: " << kolpr << endl;
		out3 << "Процент правильных ответов: " << prozpr << "%" << endl;
		out3 << "Полученная оценка: " << ozenka << endl; out3.close();
		string file5 = np + ".txt"; ofstream Oout; Oout.open(file5, ios::app);//сохранение результатов тестирования в файл конкретной категории
		Oout << login << " " << razd[k-1].nazv<<" "<<ctime(&timer);
		Oout << "Количество правильно отвеченных вопросов: " << kolpr << endl;
		Oout << "Процент правильных ответов: " << prozpr << "%" << endl;
		Oout << "Полученная оценка: " << ozenka << endl; Oout.close();
		string file4 = np + nk + ".txt"; ofstream Kout;	Kout.open(file4, ios::app);//сохранение результатов тестирования в файл конкретного раздела
		Kout << login<<" "<<ctime(&timer);
		Kout << "Количество правильно отвеченных вопросов: " << kolpr << endl;
		Kout << "Процент правильных ответов: " << prozpr << "%" << endl;
		Kout << "Полученная оценка: " << ozenka << endl; Kout.close();
		delete[]razd; delete[]voprosy;
	}
	void clear() { kolpr = 0, prozpr = 0, ozenka = 0; }//очистка переменных
};

Test* Test::obj = nullptr;