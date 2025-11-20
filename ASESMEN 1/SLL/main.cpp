#include "sslinventory.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    List L;
    createList(L);

    Product P1 = {"Pulpen", "A001", 20, 2500.0f, 0.0f};
    Product P2 = {"Buku Tulis", "A002", 15, 5000.0f, 10.0f};
    Product P3 = {"Penghapus", "A003", 30, 1500.0f, 0.0f};

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    cout << "===== LIST AWAL =====" << endl;
    viewList(L);

    deleteFirst(L);
    cout << "===== SETELAH deleteFirst =====" << endl;
    viewList(L);

    Product Pupdate = {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    updateAtPosition(L, 2, Pupdate);

    cout << "===== SETELAH UPDATE POSISI 2 =====" << endl;
    viewList(L);

    cout << "===== SEARCH RANGE 2000 - 7000 =====" << endl;
    searchByFinalPriceRange(L, 2000.0f, 7000.0f);

    cout << "===== MAX HARGA AKHIR =====" << endl;
    MaxHargaAkhir(L);

    return 0;
}