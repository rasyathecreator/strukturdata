
# <h1 align="center">Laporan Praktikum Modul 5 Singly Linked List(1)</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori

Singly Linked List (SLL) adalah struktur data fleksibel yang elemen-elemennya terhubung secara non-sekuensial menggunakan pointer. Pendekatan berbasis pointer (dinamis) ini dipilih karena lebih sesuai untuk menangani list yang dapat tumbuh dan mengerut dibandingkan Array (statis). SLL dicirikan hanya memiliki satu arah pointer , di mana setiap elemen (node) terdiri dari dua komponen: Data (Info), yaitu informasi yang disimpan, dan Successor (Next), yaitu pointer yang menunjuk ke elemen berikutnya. List ini dikendalikan oleh pointer first yang menunjuk ke node awal, sementara node terakhir selalu ditandai dengan Nil atau NULL.

Operasi pada SLL meliputi penciptaan list kosong (CreateList) dan manajemen memori dinamis melalui alokasi() (untuk menyediakan memori, menggunakan new di C++) serta dealokasi() (untuk membebaskan memori, menggunakan delete). Manipulasi data utama dilakukan melalui operasi Insert (di awal, akhir, atau setelah node tertentu) dan Delete (di awal, akhir, atau setelah node tertentu), yang merupakan inti dari ADT Linked List. Selain itu, terdapat operasi penelusuran (printInfo) dan pencarian (Searching) untuk mengakses data dalam list.

### Guided 

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
Berdasarkan kode yang dilampirkan, ketiga file tersebut saling berhubungan untuk mengimplementasikan dan menguji sebuah *linked list* tunggal dengan data bertipe `mahasiswa`. File **list1.h** bertindak sebagai *header* yang mendefinisikan struktur data (`mahasiswa`, `node`, dan `linkedlist`), alias tipe data (`dataMahasiswa`, `address`), serta mendeklarasikan semua fungsi dan prosedur yang akan diimplementasikan untuk operasi *linked list*. File **listguided1.cpp** berisi implementasi dari fungsi-fungsi yang dideklarasikan di `list1.h`, seperti `isEmpty`, `createList`, `alokasi`, `dealokasi`, `insertFirst`, `insertAfter`, `insertLast`, dan `printList`, yang semuanya berfungsi untuk memanipulasi *linked list* (misalnya membuat, menambah elemen, dan menampilkan isinya). Terakhir, file **mainguided1.cpp** adalah program utama (`main`) yang menggunakan fungsi-fungsi dari kedua file sebelumnya; ia menginisialisasi *linked list* kosong, mengalokasikan beberapa *node* mahasiswa, memasukkannya ke dalam list menggunakan berbagai prosedur `insert`, dan kemudian menampilkan isi list yang dihasilkan untuk menguji implementasi.
    
## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) -> address
procedure dealokasi( input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst( input/output L : List, input P : address )
```
### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :
```C++
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    
    return 0;
}
```
### KODE PROGRAM
#### main.cpp
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
#### list.cpp
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
#### singlylist.h
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
<img width="396" height="973" alt="image" src="https://github.com/user-attachments/assets/18bdbe7c-186b-4db6-a430-1fa75c405cc9" />
<img width="453" height="529" alt="image" src="https://github.com/user-attachments/assets/8e3a6fff-76d9-4802-857d-f10419fcb3c9" />
<img width="667" height="855" alt="image" src="https://github.com/user-attachments/assets/3d07b937-0873-4703-9f60-e9d3d8b240a2" />

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

#### main.cpp
```C++
// File: unguided1main.cpp

#include "ungu2singlist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(&L);

    P1 = alokasi(2); insertFirst(&L, P1);
    P2 = alokasi(0); insertFirst(&L, P2);
    P3 = alokasi(8); insertFirst(&L, P3);
    P4 = alokasi(12); insertFirst(&L, P4);
    P5 = alokasi(9); insertFirst(&L, P5);

    cout << "List Awal (untuk verifikasi): ";
    printInfo(L);
    cout << endl << endl;

    address P_del;
    
    deleteFirst(&L, &P_del);
    dealokasi(P_del);
    
    deleteLast(&L, &P_del); 
    dealokasi(P_del);
    
    address Prec = search(L, 12); 

    if (Prec != NULL && Prec->next != NULL && Prec->next->info == 8) {
        deleteAfter(&L, &P_del, Prec);
        dealokasi(P_del);
    }

    printInfo(L);
    cout << endl; 
    
    cout << "Jumlah node : " << nbList(L) << endl; 

    deleteList(&L);
    cout << endl << "- List Berhasil Terhapus -" << endl;

    cout << "Jumlah node : " << nbList(L) << endl; 

    return 0;
}
```
#### list.cpp
```C++
// File: unguided1list.cpp

#include "ungu2singlist.h"
#include <iostream>

using namespace std;

void createList(List *L) {
    (*L).First = NULL;
}

address alokasi(infotype X) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List *L, address P) {
    if (P != NULL) {
        P->next = (*L).First;
        (*L).First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == NULL) return; 

    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
}

address search(List L, infotype X) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteFirst(List *L, address *P) {
    *P = (*L).First;
    if (*P != NULL) {
        (*L).First = (*L).First->next;
        (*P)->next = NULL; 
    }
}

void deleteLast(List *L, address *P) {
    address Last = (*L).First;
    address Prec = NULL;
    
    if (Last != NULL && Last->next == NULL) {
        *P = Last;
        (*L).First = NULL;
        return;
    }

    while (Last != NULL && Last->next != NULL) {
        Prec = Last;
        Last = Last->next;
    }

    if (Last != NULL) {
        *P = Last;
        Prec->next = NULL;
    }
}

void deleteAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        *Pdel = Prec->next;
        Prec->next = (*Pdel)->next;
        (*Pdel)->next = NULL;
    } else {
        *Pdel = NULL;
    }
}

void deleteList(List *L) {
    address P;
    while ((*L).First != NULL) {
        deleteFirst(L, &P);
        dealokasi(P);
    }
}
```
#### singlylist.h
```C++
// File: unguided1list.h

#ifndef UNGUIDED1LIST_H
#define UNGUIDED1LIST_H

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

int nbList(List L);
address search(List L, infotype X); 
void deleteFirst(List *L, address *P);
void deleteLast(List *L, address *P);
void deleteAfter(List *L, address *Pdel, address Prec);
void deleteList(List *L);

#endif // UNGUIDED1LIST_H
```

#### Output
<img width="830" height="187" alt="image" src="https://github.com/user-attachments/assets/b739ad86-870c-4cea-8407-ccb006ff0660" />
Ketiga berkas tersebut membentuk implementasi **struktur data *singly linked list*** dalam bahasa C++. Berkas **`ungu2singlist.h`** mendefinisikan tipe data dasar (*`infotype`* sebagai *`int`*, *`address`* sebagai pointer ke *`ElmList`*, dan struktur *`ElmList`* serta *`List`*) dan mendeklarasikan semua fungsi/prosedur operasi *list*. Berkas **`ungu2list.cpp`** berisi implementasi lengkap dari prosedur-prosedur yang dideklarasikan, seperti inisialisasi (*`createList`*), alokasi/dealokasi elemen (*`alokasi`*, *`dealokasi`*), penyisipan (*`insertFirst`*), pencarian (*`search`*), perhitungan jumlah elemen (*`nbList`*), pencetakan (*`printInfo`*), dan penghapusan elemen dari awal, akhir, dan setelah elemen tertentu (*`deleteFirst`*, *`deleteLast`*, *`deleteAfter`*, serta *`deleteList`* untuk menghapus seluruh list). Terakhir, berkas **`ungu2main.cpp`** berfungsi sebagai program utama yang menggunakan semua operasi tersebut: ia membuat list `L`, menyisipkan lima nilai (9, 12, 8, 0, 2) menggunakan `insertFirst`, lalu melakukan serangkaian operasi penghapusan (*`deleteFirst`*, *`deleteLast`*, *`deleteAfter`* untuk menghapus elemen 8), mencetak sisa list, menghitung jumlah node, dan akhirnya menghapus seluruh list menggunakan `deleteList`.

#### Full Code Screenshot
<img width="1451" height="870" alt="image" src="https://github.com/user-attachments/assets/d86758a1-0937-4dc6-99d1-bd3d270bdaa1" />
<img width="1455" height="865" alt="image" src="https://github.com/user-attachments/assets/fb66fd2e-2f0f-47dd-a664-a10a558fb63a" />
<img width="1646" height="937" alt="image" src="https://github.com/user-attachments/assets/7fc91afa-901e-488d-9cea-e868acdac44b" />



## Kesimpulan
Praktikum ini berhasil mengimplementasikan struktur data **singly linked list** dalam C++, mencakup definisi node (`ElmList`) dan kepala list (`List`), serta seluruh operasi manipulasi esensial seperti inisialisasi (`createList`), manajemen memori dinamis (`alokasi`, `dealokasi`), penyisipan (`insertFirst`), pencarian (`search`), dan berbagai jenis penghapusan (`deleteFirst`, `deleteLast`, `deleteAfter`). Program utama menguji fungsionalitas ini dengan membangun list awal **9, 12, 8, 0, 2** dan kemudian secara berurutan menghapus elemen pertama (9), elemen terakhir (2), dan elemen setelah 12 (8), menyisakan **12, 0**. Pembelajaran utama yang didapat adalah pemahaman mendalam tentang peran **pointer (`address`)** dalam menghubungkan node secara non-sekuensial, efisiensi waktu $O(1)$ untuk operasi di awal list, kompleksitas $O(n)$ untuk operasi di akhir list, dan pentingnya **manajemen memori eksplisit** untuk mencegah *memory leak*.
