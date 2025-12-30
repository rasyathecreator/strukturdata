#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// tipe data int diganti namanya jadi infotype
typedef int infotype;

// ukuran maksimum stack
#define MAX 20

struct Stack {
   infotype info[MAX];
   int top;
};

// deklarasi semua fungsi dan prosedur yang bakal dipake
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif