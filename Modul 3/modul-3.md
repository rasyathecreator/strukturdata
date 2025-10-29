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

    

### 2. Soal 2
#### soal-2.cpp
```C++
#include <iostream>
#include "pelajaran-2.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}
```
#### pelajaran-2.cpp
```C++
#include <iostream>
#include "pelajaran-2.h"
using namespace std;

// Implementasi fungsi untuk membuat pelajaran
pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

// Implementasi fungsi untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
#### pelajaran-2.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);

#endif
```
#### Output:
<img width="726" height="339" alt="image" src="https://github.com/user-attachments/assets/da4b42d6-479a-4cfa-afbd-df929c4b999a" />

Program C++ ini mengilustrasikan manipulasi array dua dimensi $3 \times 3$ ($A$ dan $B$) dan penggunaan pointer untuk pertukaran nilai. Awalnya, array $A$ berisi bilangan $1$ hingga $9$ dan array $B$ berisi $10$ hingga $18$. Setelah pemanggilan fungsi tukarElemen(A, B, 0, 0), nilai pada posisi $A[0][0]$ ($1$) dan $B[0][0]$ ($10$) ditukar, sehingga $A[0][0]$ menjadi $10$ dan $B[0][0]$ menjadi $1$. Selanjutnya, ptr1 menunjuk ke $A[1][1]$ ($5$) dan ptr2 menunjuk ke $B[2][2]$ ($18$); pemanggilan tukarPointer(ptr1, ptr2) menukar nilai yang ditunjuk oleh kedua pointer tersebut, mengakibatkan $A[1][1]$ berubah dari $5$ menjadi $18$, dan $B[2][2]$ berubah dari $18$ menjadi $5$, menghasilkan output akhir yang menunjukkan $A$ dengan nilai $18$ dan $B$ dengan nilai $5$ pada posisi yang bersangkutan.

#### Full code Screenshot:
<img width="959" height="372" alt="image" src="https://github.com/user-attachments/assets/2b7085e8-d383-42fa-9c24-58550211b8c2" />
<img width="999" height="464" alt="image" src="https://github.com/user-attachments/assets/9df52987-d946-4599-a558-7f5ba11c2e78" />
<img width="922" height="426" alt="image" src="https://github.com/user-attachments/assets/6d69d04e-a72a-4140-87a2-b28c75691e26" />




### 3. Soal 3

#### soal-3.cpp
```C++
#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar isi 2 array 2D pada posisi tertentu
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar isi dari variabel yang ditunjuk oleh 2 pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *ptr1, *ptr2;
    ptr1 = &A[1][1];  // menunjuk ke elemen A[1][1] = 5
    ptr2 = &B[2][2];  // menunjuk ke elemen B[2][2] = 18

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    // Menukar isi A[0][0] dengan B[0][0]
    tukarElemen(A, B, 0, 0);

    cout << "\nSetelah menukar elemen A[0][0] dengan B[0][0]:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    // Menukar isi dari pointer
    tukarPointer(ptr1, ptr2);

    cout << "\nSetelah menukar nilai yang ditunjuk pointer:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    return 0;
}
```
#### Output
<img width="1037" height="841" alt="image" src="https://github.com/user-attachments/assets/558b0cdb-98dd-4640-8192-b8ed4b286a22" />

Kode program C++ ini mendemonstrasikan operasi pada array dua dimensi (2D) dan penggunaan pointer untuk menukar nilai. Program ini mendefinisikan dua array $3 \times 3$ bernama $A$ dan $B$, dan dilengkapi dengan tiga fungsi: tampilArray untuk menampilkan isi array $2D$, tukarElemen untuk menukar elemen pada posisi yang sama antara dua array $2D$ menggunakan parameter pass-by-reference implisit, dan tukarPointer untuk menukar nilai yang ditunjuk oleh dua pointer integer. Dalam fungsi main, program menginisialisasi $A$ dan $B$, kemudian menukar elemen $A[0][0]$ dan $B[0][0]$ menggunakan tukarElemen, dan terakhir menukar nilai yang ditunjuk oleh ptr1 (yang menunjuk ke $A[1][1]=5$) dan ptr2 (yang menunjuk ke $B[2][2]=18$) menggunakan tukarPointer, lalu menampilkan array $A$ dan $B$ setelah setiap operasi

#### Full Code Screenshot
<img width="1512" height="972" alt="image" src="https://github.com/user-attachments/assets/575448d1-c710-450f-a79f-f3eb684b2bd2" />




## Kesimpulan
Praktikum ini berhasil mengimplementasikan struktur data **singly linked list** dalam C++, mencakup definisi node (`ElmList`) dan kepala list (`List`), serta seluruh operasi manipulasi esensial seperti inisialisasi (`createList`), manajemen memori dinamis (`alokasi`, `dealokasi`), penyisipan (`insertFirst`), pencarian (`search`), dan berbagai jenis penghapusan (`deleteFirst`, `deleteLast`, `deleteAfter`). Program utama menguji fungsionalitas ini dengan membangun list awal **9, 12, 8, 0, 2** dan kemudian secara berurutan menghapus elemen pertama (9), elemen terakhir (2), dan elemen setelah 12 (8), menyisakan **12, 0**. Pembelajaran utama yang didapat adalah pemahaman mendalam tentang peran **pointer (`address`)** dalam menghubungkan node secara non-sekuensial, efisiensi waktu $O(1)$ untuk operasi di awal list, kompleksitas $O(n)$ untuk operasi di akhir list, dan pentingnya **manajemen memori eksplisit** untuk mencegah *memory leak*.

