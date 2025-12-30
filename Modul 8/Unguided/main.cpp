#include "queue.h"

int main() {
   cout << "Hello world!" << endl;

   cout<<"-----------------------"<<endl;
   cout<<" H  -  T  | Queue Info"<<endl;
   cout<<"-----------------------"<<endl;

   Queue Q;
   createQueue(Q);

   printInfo(Q);
   enqueue(Q,5); printInfo(Q);
   enqueue(Q,2); printInfo(Q);
   enqueue(Q,7); printInfo(Q);
   dequeue(Q); printInfo(Q);
   enqueue(Q,4); printInfo(Q);
   dequeue(Q); printInfo(Q);
   dequeue(Q); printInfo(Q);

   cout<<"-1  - -1  | empty queue"<<endl;

   return 0;
}