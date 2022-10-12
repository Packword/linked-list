#include <fstream>
#include <iostream>
#include "types.h"
#include "strokawork.h"
using namespace std;

Stroka* readStr(fstream& finput, bool& isFileEnd)
{
    Stroka* newStr = NULL;
    char curChar = '\0';
    finput >> curChar;
    if (curChar == '\n')
    {
        newStroka(newStr, 1);
        SetChar(newStr, 0, '\0');
        cout << "Строка пустая" << endl;
        return newStr;
    }
    else
    {
        finput.seekg(-1, ios::cur);
    }

    int i = 0;
    while (true)
    {
        finput >> curChar;
        if (curChar == '\n')
        {
            newStroka(newStr, i);
            finput.seekg(-(newStr->length + 2), ios::cur);
            break;
        }
        if ((finput.peek() == EOF))
        {
            i++;
            newStroka(newStr, i);
            finput.clear();
            finput.seekg(-(newStr->length), ios::cur);
            isFileEnd = true;
            break;
        }
        i++;
    }

    for (int i = 0; i < GetLength(newStr); i++)
    {
        finput >> curChar;
        SetChar(newStr, i, curChar);
    }
    finput >> curChar;

    return newStr;
}


void newStroka(Stroka*& str, int i)
{
    str = new Stroka(i);
}


void SetLength(Stroka* str, int len)
{
    str->length = len;
}


void SetNext(Stroka* s1, Stroka* s2)
{
    s1->next = s2;
}


void formFirstElem(Stroka*& head, Stroka*& last, Stroka* string)
{
    SetNext(string, NULL);
    head = string;
    last = string;
}


bool ifPointerEmpty(Stroka* str)
{
	if (str == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void SetStr(Stroka* s1, Stroka* s2)
{
    s1->str = s2->str;
}

Stroka* GetNext(Stroka* str)
{
	return str->next;
}

int GetLength(Stroka* str)
{
	return str->length;
}




char GetChar(Stroka* str, int i)
{
	return *(str->str + i);
}

void SetChar(Stroka* str, int i, char c)
{
	*(str->str + i) = c;
}

void printSpisok(Stroka* head, fstream& foutput)
{
	while (!ifPointerEmpty(head))
	{
		int i = 0;
		while (true)
		{
			if (i == GetLength(head))
			{
				foutput << endl;
				cout << endl;
				break;
			}
			foutput << GetChar(head, i) << " ";
			cout << GetChar(head, i) << " ";
			i++;
		}
		head = GetNext(head);
	}
}



void delSpisok(Stroka*& head)
{
	Stroka* base = new Stroka();
	Stroka* p;
	while (!ifPointerEmpty(head))
	{
		p = head;
		head = GetNext(head);

		if (ifPasted(p))
		{
			base = p;
		}
		else
		{
			delStroka(p);
		}
	}
	delStroka(base);
}

void delStroka(Stroka* str)
{
	delete[] str->str;
	delete str;
}

void printStroka(Stroka* str, fstream& foutput)
{
	for (int i = 0; i < str->length; i++)
	{
		cout << GetChar(str, i) << " ";
		foutput << GetChar(str, i) << " ";
	}
	cout << endl << endl;
	foutput << endl << endl;
}

bool badfile(fstream& finput)
{
	if (finput.bad() || finput.peek() == ifstream::traits_type::eof())
	{
		finput.close();
		return true;
	}
	finput.close();
	return false;
}



void insertEnd(Stroka*& last, Stroka* string)
{
	SetNext(string, NULL);
	SetNext(last, string);
	last = string;
}

void inserMid(Stroka* tmp, Stroka* input)
{
	SetNext(input, GetNext(tmp));
	SetNext(tmp, input);
}

bool equalStrings(Stroka* s1, Stroka* s2)
{
	if (GetLength(s1) != GetLength(s2))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < GetLength(s1); i++)
		{
			if (GetChar(s1, i) != GetChar(s2, i))
			{
				return false;
			}
		}
		return true;
	}
}

void setPasted(Stroka* str)
{
	str->pasted = true;
}

bool ifPasted(Stroka* str)
{
	return str->pasted;
}

void editSpisok(Stroka* head, Stroka* input, Stroka* paste, int num)
{
	Stroka* tmp = head;
	while (true)
	{
		if (ifPointerEmpty(tmp))
		{
			break;
		}

		if (equalStrings(input, tmp))
		{
			Stroka* buf = tmp;
			tmp = GetNext(tmp);
			for (int i = 0; i < num; i++)
			{
				Stroka* copy = new Stroka();
				SetStr(copy, paste);
				setPasted(copy);
				SetLength(copy, paste->length);
				inserMid(buf, copy);
			}
			continue;
		}
		tmp = GetNext(tmp);
	}
}