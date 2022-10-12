#include <iostream>
#include <fstream>
#include "strokawork.h"


#define N 50
using namespace std;

int main()
{
	bool isFileEnd = false;
	int num = 0;
	char c = '\0';
	setlocale(LC_ALL, "Russian");

	fstream finput;
	finput.unsetf(ios::skipws);
	fstream fdata;

	finput.open("input.txt", ios::in);
	fdata.open("data.txt", ios::in);
	fstream foutput("output.txt", ios::out | ios::trunc);

	fdata >> num;
	cout << "количество вставок: " << num << endl << endl;
	foutput << "количество вставок: " << num << endl << endl;
	fdata.unsetf(ios::skipws);
	fdata >> c; //пропуск \n

	Stroka* head, * last;
	head = NULL;
	last = NULL;

	formFirstElem(head, last, readStr(finput, isFileEnd));
	while (true)
	{
		if (isFileEnd)
		{
			finput.close();
			break;
		}
		insertEnd(last, readStr(finput, isFileEnd));
	}

	Stroka* input = readStr(fdata, isFileEnd);
	cout << "Строка, после которой идёт вставка: \n";
	foutput << "Строка, после которой идёт вставка: \n";
	printStroka(input, foutput);

	Stroka* paste = readStr(fdata, isFileEnd);
	cout << "Элемент для вставки: \n";
	foutput << "Элемент для вставки: \n";
	printStroka(paste, foutput);

	editSpisok(head, input, paste, num);
	printSpisok(head, foutput);

	delStroka(input);
	delSpisok(head);
}