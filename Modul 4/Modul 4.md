# <h1 align="center">Laporan Praktikum Modul 4 Singly Linked List(1)</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. Linked List 1
#### mainguided1.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
#### listguided1.cpp
```C++
#include "list1.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
#### list1.h
```C++

//
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Membiarkan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sbg pointer ke struct node

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
<div style="text-align: justify;"> Berdasarkan kode yang dilampirkan, ketiga file tersebut saling berhubungan untuk mengimplementasikan dan menguji sebuah *linked list* tunggal dengan data bertipe `mahasiswa`. File **list1.h** bertindak sebagai *header* yang mendefinisikan struktur data (`mahasiswa`, `node`, dan `linkedlist`), alias tipe data (`dataMahasiswa`, `address`), serta mendeklarasikan semua fungsi dan prosedur yang akan diimplementasikan untuk operasi *linked list*. File **listguided1.cpp** berisi implementasi dari fungsi-fungsi yang dideklarasikan di `list1.h`, seperti `isEmpty`, `createList`, `alokasi`, `dealokasi`, `insertFirst`, `insertAfter`, `insertLast`, dan `printList`, yang semuanya berfungsi untuk memanipulasi *linked list* (misalnya membuat, menambah elemen, dan menampilkan isinya). Terakhir, file **mainguided1.cpp** adalah program utama (`main`) yang menggunakan fungsi-fungsi dari kedua file sebelumnya; ia menginisialisasi *linked list* kosong, mengalokasikan beberapa *node* mahasiswa, memasukkannya ke dalam list menggunakan berbagai prosedur `insert`, dan kemudian menampilkan isi list yang dihasilkan untuk menguji implementasi. </div>
## Unguided 

### 1. [Soal]
#### ungu1main.cpp
```C++
// File: main.cpp

#include "ungu1singlist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;

    createList(&L);

    P1 = alokasi(2);
    insertFirst(&L, P1);

    P2 = alokasi(0);
    insertFirst(&L, P2);

    P3 = alokasi(8);
    insertFirst(&L, P3);

    P4 = alokasi(12);
    insertFirst(&L, P4);

    P5 = alokasi(9);
    insertFirst(&L, P5);

    printInfo(L);

    // Bagian tambahan untuk membersihkan memori (dealokasi semua elemen)
    address current = L.First;
    address temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        dealokasi(temp);
    }
    L.First = NULL;

    return 0;
}
```
#### ungu1list.cpp
```C++
// File: Singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H
```
#### ungu1singlist.h
```C++
// File: Singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H
```
#### Output:
<img width="679" height="242" alt="image" src="https://github.com/user-attachments/assets/af8f3f5c-a963-40c4-9472-9ab0b221b23e" />


Ketiga file C++ ini bekerja sama untuk mengimplementasikan dan menguji **ADT (Abstract Data Type) Singly Linked List**. File **`unguided1list.h`** berfungsi sebagai *interface*, mendefinisikan struktur data (`List`, `ElmList`, `address`) dan mendeklarasikan *prototype* untuk operasi dasar (seperti `createList`, `alokasi`, `insertFirst`, dan `printInfo`). File **`unguided1list.cpp`** menyediakan **implementasi** konkret dari semua *prototype* yang ada di file header, berisi kode logis untuk manajemen memori dan manipulasi pointer. Terakhir, file **`unguided1main.cpp`** bertindak sebagai **program utama** yang menguji ADT tersebut dengan membuat sebuah *list* kosong, mengalokasikan dan menyisipkan lima elemen data (`2, 0, 8, 12, 9`) secara berurutan menggunakan prosedur `insertFirst`, dan kemudian mencetak isi *list* tersebut ke konsol.

#### Full code Screenshot:
<img width="667" height="855" alt="image" src="https://github.com/user-attachments/assets/3d07b937-0873-4703-9f60-e9d3d8b240a2" />
<img width="396" height="973" alt="image" src="https://github.com/user-attachments/assets/18bdbe7c-186b-4db6-a430-1fa75c405cc9" />
<img width="453" height="529" alt="image" src="https://github.com/user-attachments/assets/8e3a6fff-76d9-4802-857d-f10419fcb3c9" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
