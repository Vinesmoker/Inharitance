#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	ofstream fout;                 // 1) ������� �����
	fout.open("File.txt", std::ios_base::app);         // 2) ��������� �����
	fout << "Hello files" << endl; // 3) ����� � �����
	fout.close();                  // 4) ��������� �����
	system("notepad File.txt");
}