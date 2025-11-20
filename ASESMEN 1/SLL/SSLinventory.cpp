

#include "sslinventory.h"
#include <iostream>

// boleh menggunakan using di file .cpp saja
using std::cout;
using std::endl;

bool isEmpty(const List &L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
}

address allocate(const Product &P) {
    address Q = new Node;
    Q->info = P;
    Q->next = nullptr;
    return Q;
}

void deallocate(address P) {
    delete P;
}

float hitungHargaAkhir(const Product &P) {
    return P.HargaSatuan * (1.0f - P.DiskonPersen / 100.0f);
}

void insertFirst(List &L, const Product &P) {
    address Q = allocate(P);
    Q->next = L.head;
    L.head = Q;
}

void insertLast(List &L, const Product &P) {
    address Q = allocate(P);
    if (isEmpty(L)) {
        L.head = Q;
    } else {
        address temp = L.head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = Q;
    }
}

void insertAfter(List &L, address Q, const Product &P) {
    if (Q != nullptr) {
        address R = allocate(P);
        R->next = Q->next;
        Q->next = R;
    }
}

void deleteFirst(List &L) {
    if (!isEmpty(L)) {
        address Q = L.head;
        L.head = Q->next;
        deallocate(Q);
    }
}

void deleteLast(List &L) {
    if (isEmpty(L)) return;
    if (L.head->next == nullptr) {
        deallocate(L.head);
        L.head = nullptr;
    } else {
        address temp = L.head;
        while (temp->next->next != nullptr) temp = temp->next;
        deallocate(temp->next);
        temp->next = nullptr;
    }
}

void deleteAfter(List &L, address Q) {
    if (Q != nullptr && Q->next != nullptr) {
        address R = Q->next;
        Q->next = R->next;
        deallocate(R);
    }
}

void updateAtPosition(List &L, int pos, const Product &newData) {
    if (pos <= 0) return;
    address temp = L.head;
    int idx = 1;
    while (temp != nullptr && idx < pos) {
        temp = temp->next;
        idx++;
    }
    if (temp != nullptr) {
        temp->info = newData;
    }
}

void viewList(const List &L) {
    address temp = L.head;
    int pos = 1;
    while (temp != nullptr) {
        float hargaAkhir = hitungHargaAkhir(temp->info);
        cout << pos << ". " << temp->info.Nama << " | " << temp->info.SKU
             << " | Jumlah: " << temp->info.Jumlah
             << " | Harga Satuan: " << temp->info.HargaSatuan
             << " | Diskon: " << temp->info.DiskonPersen
             << "% | Harga Akhir: " << hargaAkhir << endl;
        temp = temp->next;
        pos++;
    }
}

void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice) {
    address temp = L.head;
    int pos = 1;
    while (temp != nullptr) {
        float hargaAkhir = hitungHargaAkhir(temp->info);
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << "Posisi " << pos << ": " << temp->info.Nama
                 << " | Harga Akhir: " << hargaAkhir << endl;
        }
        temp = temp->next;
        pos++;
    }
}

void MaxHargaAkhir(const List &L) {
    if (isEmpty(L)) return;
    float maxH = hitungHargaAkhir(L.head->info);
    address temp = L.head->next;

    while (temp != nullptr) {
        float h = hitungHargaAkhir(temp->info);
        if (h > maxH) maxH = h;
        temp = temp->next;
    }

    cout << "Produk dengan Harga Akhir terbesar:" << endl;
    temp = L.head;
    int pos = 1;
    while (temp != nullptr) {
        if (hitungHargaAkhir(temp->info) == maxH) {
            cout << pos << ". " << temp->info.Nama << " | Harga Akhir: " << maxH << endl;
        }
        temp = temp->next;
        pos++;
    }
}
