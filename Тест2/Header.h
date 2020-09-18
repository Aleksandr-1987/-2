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
		cout << "������� �.�. ������������    : " << name << endl;
		cout << "����� ��. ����� ������������ : " << adress << endl;
		cout << "����� �������� ������������  : " << fone << endl;
		cout << "����� ������������           : " << log << endl;
		cout << "������ ������������ : " << passw << endl;
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
	User* polzovateli; int kolpolzov;// ��������� �� ������ �������������, ����� �������
	Kategor* kategorii; int nkateg;// ��������� �� ������ ���������, ����� �������	
	Test() {kolpr = 0, prozpr = 0, ozenka = 0; login = "", parol = ""; polzovateli = nullptr; kolpolzov = 0; kategorii = nullptr; nkateg = 0;}
	~Test() { delete[]polzovateli; delete[]kategorii;}
	Test(const Test& ch) { kolpr = ch.kolpr; prozpr = ch.prozpr; ozenka = ch.ozenka; login = ch.login; parol = ch.parol; polzovateli = ch.polzovateli; kolpolzov = ch.kolpolzov; kategorii = ch.kategorii; nkateg = ch.nkateg;	}
	Test& operator=(const Test& obj) { kolpr = obj.kolpr; prozpr = obj.prozpr; ozenka = obj.ozenka; login = obj.login; parol = obj.parol; polzovateli = obj.polzovateli; kolpolzov = obj.kolpolzov; kategorii = obj.kategorii; nkateg = obj.nkateg; return *this; }
public:
	static Test* getInstance(){	if (!obj) { obj = new Test(); }	return obj;	} //������� ��������
	void OPEN()
	{
		cout << "             ��� ������������ ��������� ������������." << endl;
		char ch;
		do	{
			cout << "1 - ����� � ������� � ������ ������������;\n";
			cout << "2 - ����� � ������� � ������ ��������������;\n";
			cout << "0 - ����� �� ��������� ������������\n";
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
		cout << "������� ������ ��������������:" << endl;
		while (true){//���������� �����
			c = _getch();
			if (c == 0)	c = _getch();
			if (c == '\r' || c == '\n')	break;
			cout << '*'; par += c;
		}	cout << endl;
		if (par == "777") {
			do {
				cout << "1 - ������� ������������;\n";
				cout << "2 - �������� ������������;\n";
				cout << "3 - ������� ������������\n";
				cout << "4 - �������� ����������� ������������ �� ���������� �������������\n";
				cout << "5 - �������� ����������� ������������ �� ���������� ������\n";
				cout << "6 - �������� ����������� ������������ �� ����������\n";
				cout << "7 - ���������� �������������\n";
				cout << "0 - ����� � �������� ����\n";
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
		else cout << "�� ����� �������� ������!" << endl; par = "";//������� ������ 
	}
	void testizmen()
	{
		char ch;
		do	{
			cout << "1 - �������� ����� ���������;\n";
			cout << "2 - �������� ���������\n";
			cout << "3 - �������� ����� ������ � ���������\n";
			cout << "4 - �������� ������ � ���������\n";
			cout << "5 - �������� ������ � ������ ���������\n";			
			cout << "6 - �������� ������ � ������� ���������\n";
			cout << "0 - ����� � �������� ����\n";
			cin >> ch; cin.ignore();
			switch (ch)	{
			case '1':
				void addKateg();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close(); string im;//���������� �� ����� ���������� ���������
					cout << "������� �������� ����� ���������:" << endl; getline(cin, im);					
					ofstream out; out.open("Kategg.txt", ios::app); out.close(); string t; int z = 0;//���� ��������� ���, �� �������� ������� ����� 
					do {//�������� �� ���������� ���������
						ifstream in("Kategg.txt");	char buff[200]; z = 0;
						for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); t = buff;if (im == t)z++;}	in.close();
						if (z != 0)	{cout << "����� ��������� ��� ����������, ���������� ������� ������ ���������: " << endl;getline(cin, im); }
					} while (z != 0);
					ofstream Out; Out.open("Kategg.txt", ios::app);	Out << im << endl;	Out.close();//������ ����� ��������� � ����
					int temp = nkateg + 1; ofstream Oout; Oout.open("Kolkat.txt"); Oout << temp; Oout.close();//���������� ���������� ���������
					cout << "��������� ���������!" << endl;					
				}
				break;			
			case '2':
				void izmendKateg();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
					kategorii = new Kategor[nkateg];//�������� ������� ���������
					ifstream in("Kategg.txt");	char buff[200];
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;}in.close(); //���������� ������� ��������� �� �����
					int np; string newn;
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//����� ��������� �� �����
					cout << "������� ����� ���������, ������ �������� �� ������� ��������:" << endl;
					cin >> np; cin.ignore();
					cout << "������� ����� �������� ���������:" << endl;
					getline(cin, newn);	 kategorii[np - 1].nazvkateg = newn; //��������� ���������						
					ofstream out; out.open("Kategg.txt");  for (size_t i = 0; i < nkateg; i++) {out << kategorii[i].nazvkateg << endl;}out.close(); //���������� ��������� � ����
					cout << "������ � ��������� ��������!" << endl;
				}
				break;
			case '3':
				void addRazdel();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
					kategorii = new Kategor[nkateg];//�������� ������� ���������
					ifstream in("Kategg.txt");	char buff[200]; 
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;}	in.close(); //���������� ������� ��������� �� �����
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	} //����� ��������� �� �����					 
					cout << "������� ����� ���������, � ������� �� ������ �������� ������:" << endl;
					string np; cin >> np; cin.ignore();
					cout << "������� �������� ������ �������:" << endl;
					string nov; getline(cin, nov);
					int z = 0; string temp; string file = np + "razd.txt";
					ofstream out; out.open(file, ios::app); out.close();//���� �������� ���, �� �������� ������� �����
					do {//�������� �� ���������� ���������
						ifstream in(file);char buff[200]; z = 0;
						while (!in.eof()){	in.getline(buff, 200); temp = buff;	if (temp == nov)z++;}in.close();
						if (z != 0)	{cout << "����� ������ ��� ����������, ���������� ������� ������ ������: " << endl;	getline(cin, nov);	}
					} while (z != 0);
					ofstream out1; out1.open(file, ios::app);out1 << nov << endl;out1.close();//������ ������ ������� � ����
					cout << "������ ������� ��������!" << endl;
				}
				break;			
			case '4':
				void izmenRazdel();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
					kategorii = new Kategor[nkateg];//�������� ������� ���������
					ifstream in("Kategg.txt");	char buff[200]; 
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //���������� ������� ��������� �� �����
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//����� ��������� �� �����
					cout << "������� ����� ���������, � ������� �� ������ �������� ������:" << endl;
					string np; cin >> np; cin.ignore();
					string file = np + "razd.txt";	ofstream out; out.open(file, ios::app); out.close();//���� �������� ���, �� �������� ������� �����
					ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//������� ���������� �������� � �����
					tests* razd = new tests[i - 1];//�������� ������� ��������
					ifstream in2(file); for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close(); //���������� ������� �������� �� �����
					cout << "������� ����� �������, ������� �� ������� ��������:" << endl;
					for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//����� �������� �� �����
					int nk; cin >> nk; cin.ignore();
					cout << "������� ����� �������� �������:" << endl;
					string newn; getline(cin, newn); razd[nk - 1].nazv = newn;//��������� �������
					ofstream out2; out2.open(file);	for (size_t z = 0; z < i - 1; z++){	out2 << razd[z].nazv << endl;}out2.close();//���������� ��������� � ����					
					cout << "������ � ������� ��������!" << endl;
				}
				break;
			case '5':
				void addvopros();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
					kategorii = new Kategor[nkateg];//�������� ������� ���������
					ifstream in("Kategg.txt");	char buff[200]; 
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;}	in.close();//���������� ������� ��������� �� ����� 
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//����� ��������� �� �����
					cout << "������� ����� ���������, � ������ �������, �� ������ �������� ������:" << endl;
					string np; cin >> np; cin.ignore();
					string file = np + "razd.txt"; ofstream out; out.open(file, ios::app); out.close();//���� �������� ���, �� �������� ������� �����
					ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//������� ���������� �������� � �����
					tests* razd = new tests[i - 1];//�������� ������� ��������
					ifstream in2(file); for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close(); //���������� ������� �������� �� �����
					cout << "������� ����� �������, � ������� �� ������ �������� ������:" << endl;
					for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//����� �������� �� �����
					string nk; cin >> nk; cin.ignore();					
					string vopr, v1, v2, v3, v4, pr;
					cout << "������� ������ ��� ����������:" << endl;
					getline(cin, vopr);
					cout << "������� ������ ������� ������:" << endl;
					getline(cin, v1);
					cout << "������� ������ ������� ������:" << endl;
					getline(cin, v2);
					cout << "������� ������ ������� ������:" << endl;
					getline(cin, v3);
					cout << "������� ��������� ������� ������:" << endl;
					getline(cin, v4);
					cout << "������� ����� ����������� ������:" << endl;
					getline(cin, pr);					
					string file2 = np + nk + "vopr.txt"; ofstream out2; out2.open(file2, ios::app);//������ ������� � ����
					out2 << vopr << endl;out2 << v1 << endl;out2 << v2 << endl;	out2 << v3 << endl;	out2 << v4 << endl;	out2 << pr << endl;	out2.close();
					cout << "������ ������� ��������!" << endl;		delete[]razd;
				}
				break;			
			case '6':
				void izmenvopros();
				{
					ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
					kategorii = new Kategor[nkateg];//�������� ������� ���������
					ifstream in("Kategg.txt");	char buff[200];
					for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;} in.close(); //���������� ������� ��������� �� �����
					for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//����� ��������� �� �����
					cout << "������� ����� ���������, � ������� �������, �� ������ �������� ������:" << endl;
					string np; cin >> np; cin.ignore();
					string file = np + "razd.txt";	ofstream out; out.open(file, ios::app); out.close();//���� �������� ���, �� �������� ������� �����
					ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//������� ���������� �������� � �����
					tests* razd = new tests[i - 1];//�������� ������� ��������
					ifstream in2(file);	for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close();//���������� ������� �������� �� ����� 
					cout << "������� ����� �������, � ������� �� ������ �������� ������:" << endl;
					for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//����� �������� �� �����
					string nk; cin >> nk; cin.ignore();
					string file2 = np + nk + "vopr.txt"; ifstream inn2(file2);
					int i2 = -1;while (!inn2.eof()) { inn2.getline(buff, 200); i2++; }	inn2.close();//������� ���������� �������� � �������
					Vopros* voprosy = new Vopros[i2 / 6];//�������� ������� ��������
					ifstream inn3(file2);  
					for (size_t z = 0; z < i2 / 6; z++)	{//���������� ������ �������� �� �����
						inn3.getline(buff, 200); voprosy[z].vopr = buff;
						inn3.getline(buff, 200); voprosy[z].var1 = buff;
						inn3.getline(buff, 200); voprosy[z].var2 = buff;
						inn3.getline(buff, 200); voprosy[z].var3 = buff;
						inn3.getline(buff, 200); voprosy[z].var4 = buff;
						inn3.getline(buff, 200); voprosy[z].prav = buff;
					}inn3.close();
					for (size_t z = 0; z < i2 / 6; z++)	{voprosy[z].print();}//����� �������� �� �����
					cout << "������� ����� ������� ������� �� ������� ��������:" << endl;
					int nv; cin >> nv;
					do	{
						cout << "1 - �������� ������;\n";
						cout << "2 - �������� ������ ������� ������;\n";
						cout << "3 - �������� ������ ������� ������;\n";
						cout << "4 - �������� ������ ������� ������; \n";
						cout << "5 - �������� ��������� ������� ������;\n";
						cout << "6 - �������� ����� ����������� �������� ������;\n";
						cout << "0 - ����� � �������� ����\n";
						cin >> ch; cin.ignore(); string newn;
						switch (ch)	{
						case '1':
							cout << "������� ����� ������:\n";
							getline(cin, newn);	 voprosy[nv - 1].vopr = newn;
							break;
						case '2':
							cout << "������� ������ ������� ������:\n";
							getline(cin, newn);	 voprosy[nv - 1].var1 = newn;
							break;
						case '3':
							cout << "������� ������ ������� ������:\n";
							getline(cin, newn);	 voprosy[nv - 1].var2 = newn;
							break;
						case '4':
							cout << "������� ������ ������� ������:\n";
							getline(cin, newn);	 voprosy[nv - 1].var3 = newn;
							break;
						case '5':
							cout << "������� ��������� ������� ������:\n";
							getline(cin, newn);	 voprosy[nv - 1].var4 = newn;
							break;
						case '6':
							cout << "������� ����� ����������� �������� ������:\n";
							getline(cin, newn);	 voprosy[nv - 1].prav = newn;
							break;
						}
					} while (ch != '0');
					ofstream out4; out4.open(file2);//���������� �������� � ����
					for (size_t i = 0; i < i2/6; i++){
						out4 << voprosy[i].vopr << endl;
						out4 << voprosy[i].var1 << endl;
						out4 << voprosy[i].var2 << endl;
						out4 << voprosy[i].var3 << endl;
						out4 << voprosy[i].var4 << endl;
						out4 << voprosy[i].prav << endl;
					}out4.close(); 
					cout << "������ � ������� ��������!" << endl;
					delete[]razd; delete[]voprosy;
				}
				break;
			}
		} while (ch != '0');
	}
	void addUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//���������� �� ����� ���������� �������������
		string im, a, f, l, p; hash<string> t; 
		cout << "������� �.�.�. ������������:" << endl;
		getline(cin, im);
		cout << "������� ����� ��. ����� ������������:" << endl;
		getline(cin, a);
		cout << "������� ����� �������� ������������:" << endl;
		getline(cin, f);
		cout << "������� ����� ������������:" << endl;
		getline(cin, l); 
		cout << "������� ������ ������������:" << endl;
		getline(cin, p); 
		User N(im, a, f, l, p);  User n; int z = 0;		
		ofstream out; out.open("User.txt", ios::app); out.close();
		do {//�������� �� ���������� �������������
			ifstream in("User.txt");char buff[200]; z = 0;
			for (size_t i = 0; i < kolpolzov; i++)	{
				in.getline(buff, 200); n.name = buff;
				in.getline(buff, 200); n.adress = buff;
				in.getline(buff, 200); n.fone = buff;
				in.getline(buff, 200); n.log = buff;
				in.getline(buff, 200); n.passw = buff; 
				if (n.log == l)z++;
			}	in.close();
			if (z != 0)	{cout << "����� ����� ��� ����������, ���������� ������� ������ �����: " << endl;getline(cin, l); N.log = l;}
		} while (z != 0);
		ofstream Out; Out.open("User.txt", ios::app);//���������� ������ ������������		
		Out << N.name << endl; Out << N.adress << endl; Out << N.fone << endl; Out << N.log << endl;Out << t(N.passw) << endl;Out.close();
		int temp = kolpolzov + 1; ofstream Oout; Oout.open("Kolp.txt"); Oout << temp; Oout.close();//���������� ���������� �������������
		cout << "������������ ��������!" << endl;		
	}
	void izmenUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//���������� �� ����� ���������� �������������
		polzovateli = new User[kolpolzov];//�������� ������ �������������
		ifstream in("User.txt");char buff[200];
		for (size_t i = 0; i < kolpolzov; i++)	{//���������� ������ ������������� �� �����
			in.getline(buff, 200); polzovateli[i].name = buff;
			in.getline(buff, 200); polzovateli[i].adress = buff;
			in.getline(buff, 200); polzovateli[i].fone = buff;
			in.getline(buff, 200); polzovateli[i].log = buff;
			in.getline(buff, 200); polzovateli[i].passw = buff;
		}	in.close(); 		 
		for (size_t i = 0; i < kolpolzov; i++)	{cout<<i+1<<"."<<" ", polzovateli[i].print();}//����� ������������� �� �����
		cout << "������� ����� ������������, ������ �������� �� ������� ��������:" << endl;
		char ch; hash<string> t; int np;  cin >> np;
		do	{//��������� ������ � ������������
			cout << "1 - ��������� ����� ������������;\n";
			cout << "2 - ��������� ������ ��. ����� ������������;\n";
			cout << "3 - ��������� ������ �������� ������������\n";
			cout << "4 - ��������� ������ ������������� \n";
			cout << "5 - ��������� ������ ������������\n";
			cout << "0 - ����� � �������� ����\n";
			cin >> ch; cin.ignore(); string newn;
			switch (ch)	{
			case '1':
				cout << "������� ����� ��� ������������;\n"; 
				getline(cin, newn);	 polzovateli[np - 1].name = newn;
				break;
			case '2':
				cout << "������� ����� ����� ��. ����� ������������;\n";
				getline(cin, newn); polzovateli[np - 1].adress = newn;
				break;
			case '3':
				cout << "������� ����� ����� �������� ������������;\n";
				getline(cin, newn); polzovateli[np - 1].fone = newn;
				break;
			case '4':
				cout << "������� ����� ����� ������������;\n";
				getline(cin, newn); polzovateli[np - 1].log = newn;
				break;
			case '5':
				cout << "������� ����� ������ ������������;\n";
				getline(cin, newn); polzovateli[np - 1].passw = t(newn);
				break;
			}
		} while (ch != '0');
		ofstream out; out.open("User.txt");
		for (size_t i = 0; i < kolpolzov; i++){//���������� ������������� � ����
			out << polzovateli[i].name << endl;
			out << polzovateli[i].adress << endl;
			out << polzovateli[i].fone << endl;
			out << polzovateli[i].log << endl;
			out << polzovateli[i].passw << endl;
		}	out.close(); 
		cout << "������ � ������������ ��������!" << endl;
	}
	void dellUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//���������� �� ����� ���������� �������������
		polzovateli = new User[kolpolzov];//�������� ������ �������������
		ifstream in("User.txt"); char buff[200];
		for (size_t i = 0; i < kolpolzov; i++)	{//���������� ������ ������������� �� �����
			in.getline(buff, 200); polzovateli[i].name = buff;
			in.getline(buff, 200); polzovateli[i].adress = buff;
			in.getline(buff, 200); polzovateli[i].fone = buff;
			in.getline(buff, 200); polzovateli[i].log = buff;
			in.getline(buff, 200); polzovateli[i].passw = buff;
		} in.close(); 		
		for (size_t i = 0; i < kolpolzov; i++)	{cout << i + 1 << "." << " ", polzovateli[i].print(); } //����� ������������� �� �����
		cout << "������� ����� ������������, �������� �� ������� �������:" << endl;
		int np;  cin >> np;
		for (size_t i = np-1; i < kolpolzov - 1; i++){	polzovateli[i] = polzovateli[i + 1];}//�������� ������������
		string nn = polzovateli[np - 1].log + ".txt"; remove(nn.c_str());//�������� ����� ������������
		ofstream out; out.open("User.txt");
		for (size_t i = 0; i < kolpolzov-1; i++){//���������� � ���� ������ ������ �������������
			out << polzovateli[i].name << endl;
			out << polzovateli[i].adress << endl;
			out << polzovateli[i].fone << endl;
			out << polzovateli[i].log << endl;
			out << polzovateli[i].passw << endl;
		}	out.close(); 
		int temp = kolpolzov - 1; ofstream Oout; Oout.open("Kolp.txt"); Oout << temp; Oout.close();//���������� ���������� �������������
		cout << "������������ ������!" << endl;
	}	
	void seenUser()
	{
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//���������� �� ����� ���������� �������������
		polzovateli = new User[kolpolzov];//�������� ������ �������������
		ifstream in("User.txt");char buff[200];
		for (size_t i = 0; i < kolpolzov; i++)	{//���������� ������ ������������� �� �����
			in.getline(buff, 200); polzovateli[i].name = buff;
			in.getline(buff, 200); polzovateli[i].adress = buff;
			in.getline(buff, 200); polzovateli[i].fone = buff;
			in.getline(buff, 200); polzovateli[i].log = buff;
			in.getline(buff, 200); polzovateli[i].passw = buff;
		}	in.close(); 		
		for (size_t i = 0; i < kolpolzov; i++)	{cout << i + 1 << "." << " " << polzovateli[i].name << endl;}//����� ������������� �� �����
		cout << "������� ����� ������������, ����� ����������� ��� ���������� ������������:" << endl;
		int np; cin >> np;
		string file = polzovateli[np-1].log + ".txt"; ofstream out; out.open(file, ios::app); out.close();//���� ���� � �������������� �� ������, ������� ���
		ifstream inn(file);	while (!inn.eof()) {inn.getline(buff, 200); cout << buff << endl;}	inn.close();//����� �� ����� ����������� ������������	
	}
	void seenTest()
	{
		ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
		kategorii = new Kategor[nkateg];//�������� ������ ���������
		ifstream in("Kategg.txt");	char buff[200];
		for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //���������� ������ ��������� �� �����	
		cout << "������� ���������:" << endl;		
		for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//����� ��������� �� �����		
		string np; cin >> np;
		string file = np+ "razd.txt"; ofstream out; out.open(file, ios::app); out.close(); //���� ���� � ��������� �� ������, ������� ���
		cout << "�������� ������ ��� ��������� ����������� ������������:" << endl;
		ifstream inn(file);
		 int i = 1;
		while (!inn.eof()) {inn.getline(buff, 200); cout << i++ << "." << " "<< buff << endl; }	inn.close(); //����� �������� �� �����
		string tp;	cin>> tp;
		string file2 = np +tp+ ".txt";	ofstream out1; out1.open(file2, ios::app); out1.close();//���� ���� � ������������ ������������ �� ������, ������� ���
		ifstream inn1(file2); while (!inn1.eof()) {	inn1.getline(buff, 200); cout << buff << endl;}	inn1.close();//����� �� ����� ����������� ������������
	}
	void seenKategor()
	{
		ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
		kategorii = new Kategor[nkateg];//�������� ������ ���������
		ifstream in("Kategg.txt");	char buff[200];
		for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //���������� ������ ��������� �� �����
		for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	} //����� ��������� �� �����	
		cout << "������� ����� ���������, ����� ������� �� ���������� ������������:" << endl;
		string np; cin >> np;
		string file = np + ".txt"; ofstream out; out.open(file, ios::app); out.close();//���� ���� � ������������ ������������ �� ������, ������� ���
		ifstream inn(file);	while (!inn.eof()) {inn.getline(buff, 200); cout << buff << endl;}	inn.close();//����� �� ����� ����������� ������������
	}
	void Users()
	{
		char ch;		
		do	{
			cout << "1 - ����� � ������� �� ������ � ������;\n";
			cout << "2 - ������������������;\n";
			cout << "0 - ����� � �������� ����\n";
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
		ifstream Iin; Iin.open("Kolp.txt"); Iin >> kolpolzov; Iin.close();//���������� �� ����� ���������� �������������
		string im, a, f, l, p; hash<string> t; int c = 0;
		cout << "������� ���� �.�.�.:" << endl;
		getline(cin, im);		
		cout << "������� ����� ����� ��. �����:" << endl;
		getline(cin, a);
		cout << "������� ��� ����� ��������:" << endl;
		getline(cin, f);
		cout << "������� ��� �����:" << endl;
		getline(cin, l); 
		cout << "������� ��� ������:" << endl;		
		while (true) {//���������� �����
			c = _getch();
			if (c == 0)	c = _getch();
			if (c == '\r' || c == '\n')	break;
			cout << '*'; p += c;
		} cout << endl;		
		User N(im, a, f, l, p); User n; int z = 0; 		
		ofstream out; out.open("User.txt", ios::app); out.close();//���� ���� � �������������� �� ������, ������� ���
		do {
			ifstream in("User.txt"); char buff[200]; z = 0; 
			while (!in.eof()) {//�������� �� ���������� �������������
				in.getline(buff, 200); n.name = buff;
				in.getline(buff, 200); n.adress = buff;
				in.getline(buff, 200); n.fone = buff;
				in.getline(buff, 200); n.log = buff; 
				in.getline(buff, 200); n.passw = buff; 
				if (n.log == l)z++;       
			}	in.close();
			if (z != 0) {cout << "����� ����� ��� ����������, ���������� ������� ������ �����: " << endl;getline(cin, l); N.log = l; }			
		} while (z != 0);		
		out.open ("User.txt", ios::app); //���������� ������ ������������
		out << N.name << endl;out << N.adress << endl;	out << N.fone << endl;	out << N.log << endl;	out << t(N.passw) << endl;	out.close();		
		cout << "����������� ������� ���������!" << endl; p = "";//������� ������ 		
		int temp = kolpolzov + 1; ofstream Oout; Oout.open("Kolp.txt"); Oout << temp; Oout.close();//��������� ���������� �������������
	}
	void vhod()
	{
		double ps; hash<string> t;	int c3 = 0;
		cout << "������� ���� �����:" << endl;
		getline(cin, login); 
		cout << "������� ���� ������:" << endl;
		while (true) {//���������� �����
			c3 = _getch();
			if (c3 == 0)	c3 = _getch();
			if (c3 == '\r' || c3 == '\n')	break;
			cout << '*'; parol += c3;
		} cout << endl;	
		ps = t(parol);	
		ofstream out; out.open("User.txt", ios::app); out.close();//���� ���� � �������������� �� ������, ������� ���
		ifstream in("User.txt");char buff[200]; User n; int z = 0; char ch;
		while (!in.eof()) {//�������� ������ � ������
			in.getline(buff, 200); n.name = buff;
			in.getline(buff, 200); n.adress = buff;
			in.getline(buff, 200); n.fone = buff;
			in.getline(buff, 200); n.log = buff; 
			in.getline(buff, 200); n.passw = buff; double val2 = atof(buff); 
			if (login == n.log && val2 == ps)z++;
		}	in.close();
		if (z == 1) {
			do	{
				cout << "1 - ����������� ���� ���������� ���������� ������������;\n";
				cout << "2 - ����� ����� ������������;\n";
				cout << "0 - ����� � ���� �����������.\n";
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
		else cout << "�� ������� �������� ����� ��� ������!" << endl; parol = "";//������� ������ 
	}
	void showres()
	{
		string file = login + ".txt";ofstream out; out.open(file, ios::app); out.close(); //���� ���� ������������ �� ������, ������� ���
		ifstream in(file);	char buff[200];	while (!in.eof()) {	in.getline(buff, 200); cout << buff << endl;}in.close();//���������� ������ � ����� ������������		
	}
	void testirovanie()
	{
		ifstream Iin; Iin.open("Kolkat.txt"); Iin >> nkateg; Iin.close();//���������� �� ����� ���������� ���������
		kategorii = new Kategor[nkateg];//�������� ������ ���������
		ifstream in("Kategg.txt");	char buff[200]; 		
		for (size_t i = 0; i < nkateg; i++)	{in.getline(buff, 200); kategorii[i].nazvkateg = buff;	}in.close(); //���������� ������ ��������� �� �����
		for (size_t i = 0; i < nkateg; i++)	{cout << i + 1 << "." << " " << kategorii[i].nazvkateg << endl;	}//����� ��������� �� �����
		cout << "������� ����� ���������, � ������� �� ������ ������ ������������:" << endl;
		string np; cin >> np; cin.ignore(); 
		string file = np + "razd.txt"; 
		ofstream out; out.open(file, ios::app); out.close();//���� ���� � ��������� �� ������, ������� ���
		ifstream inn(file);	int i = 0;	while (!inn.eof()) { inn.getline(buff, 200); i++; }	inn.close();//������� ���������� �������� � �����
		tests* razd = new tests[i - 1];//�������� ������ ��������
		ifstream in2(file); for (size_t z = 0; z < i - 1; z++){	in2.getline(buff, 200); razd[z].nazv = buff;}in2.close();//���������� ������ �������� �� ����� 
		cout << "������� ����� �������, ��� ����������� ������������:" << endl;
		for (size_t z = 0; z < i - 1; z++){	cout << z + 1 << "." << " " << razd[z].nazv << endl;}//����� �������� �� �����
		string nk; cin >> nk; cin.ignore(); 
		string file2 = np + nk + "vopr.txt"; ifstream in3(file2);
		int y = -1;	while (!in3.eof()) { in3.getline(buff, 200); y++; } in3.close();//������� ���������� �������� � �������
		Vopros* voprosy = new Vopros[y / 6]; //�������� ������ ��������
		ifstream in4(file2); string ot;
		for (size_t i = 0; i < y/6; i++){//���������� ������ �������� �� �����
			in4.getline(buff, 200); voprosy[i].vopr = buff;
			in4.getline(buff, 200); voprosy[i].var1 = buff;
			in4.getline(buff, 200); voprosy[i].var2 = buff;
			in4.getline(buff, 200); voprosy[i].var3 = buff;
			in4.getline(buff, 200); voprosy[i].var4 = buff;
			in4.getline(buff, 200); voprosy[i].prav = buff;
		}	in4.close(); 		
		for (size_t i = 0; i < y/6; i++){//������������
			cout << voprosy[i].vopr << endl;
			cout << voprosy[i].var1 << endl;
			cout << voprosy[i].var2 << endl;
			cout << voprosy[i].var3 << endl;
			cout << voprosy[i].var4 << endl;
			cin >> ot;if(ot== voprosy[i].prav) { kolpr++; }//������� ���������� ���������� �������
		}
		cout << "���� ��������!" << endl;
		cout << "���������� ��������� ���������� ��������: " << kolpr << endl;
		double p = ((float)kolpr / (y / 6)) * 100;	prozpr = p;
		cout << "������� ���������� �������: " << prozpr << "%" << endl;
		double b = (float)kolpr * (12/((float)y/6)); ozenka = b;
		cout << "���������� ������: " << ozenka << endl;

		const time_t timer = time(0); int k1 = atoi(np.c_str()); int k = atoi(nk.c_str());
		ofstream out3; string file3 = login + ".txt"; out3.open(file3, ios::app);//���������� ����������� ������������ � ���� ����������� ������������
		out3 <<kategorii[k1-1].nazvkateg<<" "<< razd[k - 1].nazv<<" "<< ctime(&timer);
		out3 << "���������� ��������� ���������� ��������: " << kolpr << endl;
		out3 << "������� ���������� �������: " << prozpr << "%" << endl;
		out3 << "���������� ������: " << ozenka << endl; out3.close();
		string file5 = np + ".txt"; ofstream Oout; Oout.open(file5, ios::app);//���������� ����������� ������������ � ���� ���������� ���������
		Oout << login << " " << razd[k-1].nazv<<" "<<ctime(&timer);
		Oout << "���������� ��������� ���������� ��������: " << kolpr << endl;
		Oout << "������� ���������� �������: " << prozpr << "%" << endl;
		Oout << "���������� ������: " << ozenka << endl; Oout.close();
		string file4 = np + nk + ".txt"; ofstream Kout;	Kout.open(file4, ios::app);//���������� ����������� ������������ � ���� ����������� �������
		Kout << login<<" "<<ctime(&timer);
		Kout << "���������� ��������� ���������� ��������: " << kolpr << endl;
		Kout << "������� ���������� �������: " << prozpr << "%" << endl;
		Kout << "���������� ������: " << ozenka << endl; Kout.close();
		delete[]razd; delete[]voprosy;
	}
	void clear() { kolpr = 0, prozpr = 0, ozenka = 0; }//������� ����������
};

Test* Test::obj = nullptr;