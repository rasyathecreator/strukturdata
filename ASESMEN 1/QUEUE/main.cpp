#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    
    Paket p1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket p2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket p3 = {"345678", "Bennet", 7, "Natlan"};
    Paket p4 = {"456789", "Furina", 16, "Liyue"};
    Paket p5 = {"567890", "Nefer", 6, "Inazuma"};

    Q.Tail = 4;
    Q.Head = 0;
    Q.dataPaket[0] = p1;
    Q.dataPaket[1] = p2;
    Q.dataPaket[2] = p3;
    Q.dataPaket[3] = p4;
    Q.dataPaket[4] = p5;

    cout << "Queue sebelum deQueue:" << endl;
    viewQueue(Q);

    deQueue(Q);

    cout << "\nQueue setelah 1x deQueue:" << endl;
    viewQueue(Q);

    cout << "\nTotal Biaya Pengiriman: Rp " << TotalBiayaPengiriman(Q) << endl;

    return 0;
}
