#include "stack.h"

int main() {
   cout << "Program Stack Modul 7" << endl;

   Stack S;
   createStack(S);
   
   cout << "\n=== Tugas 1 ===" << endl;

   push(S, 3);
   push(S, 4);
   push(S, 8);
   pop(S);
   push(S, 2);
   push(S, 3);
   pop(S);
   push(S, 9);

   printInfo(S);

   cout << "balik stack" << endl;
   balikStack(S);
   printInfo(S);

   cout << "\n=== PushAscending ===" << endl;
   createStack(S);

   pushAscending(S, 3);
   pushAscending(S, 4);
   pushAscending(S, 8);
   pushAscending(S, 2);
   pushAscending(S, 3);
   pushAscending(S, 9);
   printInfo(S);
   cout << "balik stack" << endl;
   balikStack(S);
   printInfo(S);

   cout << "\n=== getInputStream ===" << endl;
   createStack(S);
   getInputStream(S);

   cout << "Isi Stack" << endl;
   printInfo(S);

   cout << "balik stack" << endl;
   balikStack(S);
   printInfo(S);
   return 0;
}