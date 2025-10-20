# <h1 align="center">Laporan Praktikum Modul 3 Abstract Data Type</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori

SAbstract Data Type (ADT) adalah definisi statis dari sebuah Tipe beserta sekumpulan operasi dasar (primitif) terhadap tipe tersebut. Sebuah ADT yang lengkap juga menyertakan definisi invarian dari Tipe dan aksioma yang berlaku. Konsep ini memungkinkan sebuah ADT untuk mengandung definisi ADT lainnya, misalnya ADT waktu yang terdiri dari ADT JAM dan ADT DATE, atau ADT Garis yang terdiri dari dua ADT POINT. Primitif-primitif dalam ADT dikelompokkan menjadi beberapa jenis, di antaranya adalah Konstruktor (untuk membentuk nilai), Selektor (untuk mengakses komponen tipe), prosedur pengubah nilai, validator tipe, Destruktor (untuk menghancurkan nilai objek), fungsi Baca/Tulis untuk I/O, serta operator relasional dan aritmetika.

Dalam implementasinya, ADT biasanya diwujudkan menjadi dua modul utama ditambah satu modul antarmuka untuk program utama. Dua modul utama tersebut adalah file definisi/spesifikasi (.h) dan file badan/realisasi primitif (.c atau .cpp). File header (.h) berisi spesifikasi tipe, yang dalam bahasa C/C++ sering kali menggunakan struct, beserta spesifikasi dari fungsi atau prosedur primitifnya. Sementara itu, file implementasi (.c/.cpp) berisi kode program atau realisasi dari setiap fungsi dan prosedur yang telah didefinisikan, yang sedapat mungkin memanfaatkan selektor dan konstruktor yang ada.


### 1. Soal 1
#### soal-1.cpp
```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;
    if (n > 10) n = 10;  // batas maksimal

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore(); // membersihkan buffer
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=========================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "=========================================\n";
    cout << "Nama\t\tNIM\t\tNilai Akhir\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << "\t\t"
             << mhs[i].nim << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }

    cout << "=========================================\n";

    return 0;
}
```
#### OUTPUT
<img width="1091" height="635" alt="image" src="https://github.com/user-attachments/assets/2e17ddc6-170f-497d-8abe-5a67b6265d91" />

Program C++ tersebut dirancang untuk mengelola data nilai mahasiswa. Awalnya, program akan meminta pengguna memasukkan jumlah mahasiswa (maksimal 10) yang datanya akan diinput. Kemudian, untuk setiap mahasiswa, program akan meminta masukan berupa nama, NIM, nilai UTS, nilai UAS, dan nilai tugas. Setelah semua data diterima, program akan menghitung nilai akhir untuk setiap mahasiswa menggunakan formula pembobotan: 30% dari nilai UTS, 40% dari nilai UAS, dan 30% dari nilai tugas. Sebagai output akhir, program akan menampilkan sebuah tabel yang rapi berisi daftar nama, NIM, dan nilai akhir dari semua mahasiswa yang telah dimasukkan.

#### FULL CODE SCREENSHOT
<img width="1491" height="971" alt="image" src="https://github.com/user-attachments/assets/fde848f9-b748-484e-ac90-b9605699e84c" />

    
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

