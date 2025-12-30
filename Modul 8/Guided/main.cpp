#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\nEnqueuing 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\nDequeued 1 elemen " << endl;
    cout << "Elemen keluar " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\nEnqueuing 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\nDequeued 2 elemen " << endl;
    cout << "Elemen keluar " << dequeue(Q) << endl;
    cout << "Elemen keluar " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}