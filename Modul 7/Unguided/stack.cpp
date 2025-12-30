#include "stack.h"
void createStack(Stack &S) {
   S.top = -1;
}
void push(Stack &S, infotype x) {
   if (S.top == MAX - 1) {
      cout << "stack penuh, tidak bisa menambah data lagi" << endl;
      return;
   }
   S.top = S.top + 1;
   S.info[S.top] = x;
}
infotype pop(Stack &S) {
   if (S.top == -1) {
      cout << "stack kosong, tidak ada yang bisa di-pop" << endl;
      return -1;
   }

   infotype data = S.info[S.top];

   S.top = S.top - 1;

   return data;
}

void printInfo(Stack S) {
   if (S.top == -1) {
      cout << "stack kosong" << endl;
      return;
   }

   cout << "[TOP] ";

   for (int i = S.top; i >= 0; i--) {
      cout << S.info[i];
      if (i > 0) cout << " -> ";
   }

   cout << "" << endl;
}

void balikStack(Stack &S) {
   int i = 0;
   int j = S.top;

   while (i < j) {
      infotype temp = S.info[i];
      S.info[i] = S.info[j];
      S.info[j] = temp;
      i++;
      j--;
   }
}
void pushAscending(Stack &S, infotype x) {
   if (S.top == MAX - 1) {
      cout << "stack penuh, tidak bisa menambah data lagi" << endl;
      return;
   }
   Stack temp;
   createStack(temp);

   while (S.top != -1 && S.info[S.top] > x) {
      push(temp, pop(S));
   }
   push(S, x);
   while (temp.top != -1) {
      push(S, pop(temp));
   }
}

void getInputStream(Stack &S) {
   int x;
   cout << "input data (untuk berhenti tekan sembarang selain angka): " << endl;
   while (cin >> x) {
       push(S, x);
   }
   cout << "input sudah ada di stack!" << endl;
}
