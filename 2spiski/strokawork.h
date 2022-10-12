#ifndef STROKAWORK_H
#define STROKAWORK_H


#include <fstream>
#include "types.h"


using namespace std;


bool badfile(fstream& finput);

bool ifPointerEmpty(Stroka* str);

void SetNext(Stroka* s1, Stroka* s2);

Stroka* GetNext(Stroka* str);

int GetLength(Stroka* str);

void SetLength(Stroka* str, int len);

void Init(Stroka* str);

void newStroka(Stroka*& str, int i);

char GetChar(Stroka* str, int i);

void SetChar(Stroka* str, int i, char c);

void formFirstElem(Stroka*& head, Stroka*& last, Stroka* string);

void insertEnd(Stroka*& last, Stroka* string);

void printSpisok(Stroka* head, fstream& foutput);

Stroka* readStr(fstream& finput, bool& fileEnded);

void delSpisok(Stroka*& head);

void delStroka(Stroka* str);

void inserMid(Stroka* tmp, Stroka* input);

bool equalStrings(Stroka* s1, Stroka* s2);

void editSpisok(Stroka* head, Stroka* input, Stroka* paste, int  num);

void SetStr(Stroka* s1, Stroka* s2);

void setPasted(Stroka* str);

bool ifPasted(Stroka* str);

void printStroka(Stroka* str, fstream& foutput);
#endif