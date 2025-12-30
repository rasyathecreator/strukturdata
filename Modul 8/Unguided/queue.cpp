#include "queue.h"

void createQueue(Queue &Q) {
   Q.head = -1;
   Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
   return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
   return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
   if (isFullQueue(Q)) {
      cout << "queue penuh, tidak bisa menambah data" << endl;
   } else {
      if (isEmptyQueue(Q)) {
         Q.head = 0;
         Q.tail = 0;
      } else {
         Q.tail++;
      }
      Q.info[Q.tail] = x;
   }
}

infotype dequeue(Queue &Q) {
   if (isEmptyQueue(Q)) {
      cout << "queue kosong, tidak ada yang bisa dihapus" << endl;
      return -1;
   }

   infotype hasil = Q.info[Q.head];

   if (Q.head == Q.tail) {
      Q.head = -1;
      Q.tail = -1;
   } else {
      for (int i = Q.head; i < Q.tail; i++) {
         Q.info[i] = Q.info[i + 1];
      }
      Q.tail--;
   }

   return hasil;
}

void printInfo(Queue Q) {
   if (isEmptyQueue(Q)) {
      cout << Q.head << "  - " << Q.tail << "  | empty queue" << endl;
   } else {
      cout << " " << Q.head << "  -  " << Q.tail << "  | ";
      for (int i = Q.head; i <= Q.tail; i++) {
         cout << Q.info[i] << " ";
      }
      cout << endl;
   }
}