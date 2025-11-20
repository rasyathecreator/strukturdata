#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>

typedef struct Product {
    std::string Nama;
    std::string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
} Product;

typedef struct Node *address;

typedef struct Node {
    Product info;
    address next;
} Node;

typedef struct {
    address head;
} List;

bool isEmpty(const List &L);
void createList(List &L);
address allocate(const Product &P);
void deallocate(address P);

void insertFirst(List &L, const Product &P);
void insertLast(List &L, const Product &P);
void insertAfter(List &L, address Q, const Product &P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Q);

void updateAtPosition(List &L, int pos, const Product &newData);
void viewList(const List &L);
void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice);
void MaxHargaAkhir(const List &L);

float hitungHargaAkhir(const Product &P);

#endif // SLLINVENTORY_H





