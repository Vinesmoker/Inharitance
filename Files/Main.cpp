#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	ofstream fout;                 // 1) Создаем поток
	fout.open("File.txt", std::ios_base::app);         // 2) Открываем поток
	fout << "Hello files" << endl; // 3) Пишем в поток
	fout.close();                  // 4) Закрываем поток
	system("notepad File.txt");
}