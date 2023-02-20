#include<iostream>
#include<fstream>
using namespace std;

#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	char filename[_MAX_FNAME] = {};
	cout << "Введите имя файла: ";
	cin.getline(filename, _MAX_FNAME);
	if (strcmp(filename + strlen(filename) - 4, ".txt"))
		strcat_s(filename, _MAX_FNAME, ".txt");

	ofstream fout;									 // 1) Создаем поток
	fout.open(filename, std::ios_base::app);         // 2) Открываем поток
	fout << "Hello files" << endl;					 // 3) Пишем в поток
	fout.close();									 // 4) Закрываем поток

	char sz_command[_MAX_FNAME] = "notepad ";
	strcat_s(sz_command, _MAX_FNAME, filename);
	system(sz_command);
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 1024 * 500;
		char sz_buffer[SIZE]{};
		//https://habr.com/ru/post/25375/
		while (!fin.eof())
		{
			//fin >> sz_buffer; // есть перенос
			fin.getline(sz_buffer, SIZE); // нет переноса
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file nit found" << endl;
	}
#endif // READ_FROM_FILE

}