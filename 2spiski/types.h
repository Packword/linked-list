#ifndef TYPES_H
#define TYPES_H

struct Stroka
{
public:
	bool pasted;
	int length;
	char* str;
	Stroka* next;

	Stroka(int len = 0)
	{
        pasted = false;
        next = NULL;
        length = len;
        str = new char[len];
	}
};


#endif