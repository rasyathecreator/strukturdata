#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi &Q) {
    return (Q.Tail == -1);
}

bool isFull(QueueEkspedisi &Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    Paket P;
    cout << "Kode Resi: "; cin >> P.KodeResi;
    cout << "Nama Pengirim: "; cin >> P.NamaPengirim;
    cout << "Berat Barang (kg): "; cin >> P.BeratBarang;
    cout << "Tujuan: "; cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
    } else {
        Q.Tail++;
    }
    Q.dataPaket[Q.Tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    for (int i = 0; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }
    Q.Tail--;
    if (Q.Tail < 0) {
        Q.Head = -1;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    for (int i = 0; i <= Q.Tail; i++) {
        cout << "====================" << endl;
        cout << "Kode Resi: " << Q.dataPaket[i].KodeResi << endl;
        cout << "Nama Pengirim: " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "Berat Barang: " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << "Tujuan: " << Q.dataPaket[i].Tujuan << endl;
    }
}

int TotalBiayaPengiriman(QueueEkspedisi &Q) {
    int total = 0;
    for (int i = 0; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}
