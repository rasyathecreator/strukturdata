# <h1 align="center">Laporan Praktikum Modul 7 STACK</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori

Stack merupakan struktur data linier yang mengikuti prinsip Last In First Out (LIFO), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Struktur ini sering diimplementasikan menggunakan array atau linked list, dengan operasi utama terjadi hanya pada satu ujung yang disebut top.

### Definisi
Stack didefinisikan sebagai tumpukan data di mana akses terbatas pada elemen teratas, mirip susunan piring yang harus diambil dari atas. Prinsip LIFO membuatnya ideal untuk mengelola data sementara seperti panggilan fungsi atau riwayat undo.

### Komponen Node
Setiap stack memiliki pointer top yang menunjuk posisi elemen teratas, serta batas maksimum kapasitas untuk implementasi array-based. Jenisnya meliputi register stack (kapasitas kecil) dan memory stack (fleksibel untuk data besar).

### Operasi Utama
1. Push: Menambahkan elemen baru ke top stack.
2. Pop: Menghapus dan mengembalikan elemen dari top.​
3. Peek/Top: Melihat elemen top tanpa menghapusnya.
4. IsEmpty/IsFull: Memeriksa kondisi stack kosong atau penuh.
​
### Kelebihan dan Kekurangan
Stack efisien untuk operasi LIFO dengan kompleksitas O(1), mendukung rekursi dan manajemen memori otomatis, tetapi tidak mendukung akses acak elemen. Kekurangannya termasuk ukuran tetap pada array dan overhead pointer pada linked list.

## Guided 

### Program Push, Pop, serta Menampilkan Isi Stack
#### stackguided.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node *top) {
    return top == NULL;
}

void push(Node *&top, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop(Node *&top) {
    if (isEmpty(top)) {
        cout << "Stack kosong.tidak bisa pop." << endl;
        return 0;
    }
    
    int poppedData = top->data;
    Node *temp = top;
    top = top->next;

    delete temp;
    return poppedData;
}

void show(Node *top) {
    if (isEmpty(top)) {
        cout << "Stack kosong." << endl;
        return;
    }

    cout << "TOP -> ";
    Node *temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node *stack = nullptr;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "Menampilkan isi stack: " << endl;
    show(stack);

    cout << "Pop: " << pop(stack) << endl;
    show(stack);

    cout << "Menampilkan isi stack: " << endl;
    show(stack);

    return 0;
}
```
### Screenshot Output
<img width="927" height="197" alt="image" src="https://github.com/user-attachments/assets/acddc102-ff86-4bae-bcce-4742d8a4f586" />

Kode program di atas merupakan implementasi **struktur data stack** menggunakan **linked list satu arah** dalam bahasa C++. Struktur `Node` digunakan untuk merepresentasikan setiap elemen stack yang berisi data dan pointer `next` yang menunjuk ke node berikutnya. Stack direpresentasikan oleh pointer `top` yang selalu menunjuk ke elemen teratas. Fungsi `isEmpty` digunakan untuk mengecek apakah stack kosong, sedangkan fungsi `push` berfungsi menambahkan elemen baru ke bagian atas stack dengan mengatur pointer agar node baru menjadi `top`. Fungsi `pop` digunakan untuk menghapus dan mengambil data dari elemen teratas stack, disertai pengecekan kondisi kosong untuk mencegah kesalahan. Fungsi `show` menampilkan seluruh isi stack dari atas ke bawah. Pada fungsi `main`, program mendemonstrasikan penggunaan stack dengan menambahkan beberapa elemen, menampilkan isi stack, melakukan operasi pop, dan menampilkan kembali kondisi stack setelah perubahan, sehingga memperlihatkan prinsip kerja stack dengan konsep **Last In First Out (LIFO)**.

### Full code screenshot
<img width="1647" height="975" alt="image" src="https://github.com/user-attachments/assets/82e6cc88-1440-40a6-a311-2f3f1de4c3b8" />




## Unguided 

### Buatlah ADT Stack menggunakan ARRAY dalam file “stack.h”, “stack.cpp”, dan “main.cpp”
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// tipe data int diganti namanya jadi infotype
typedef int infotype;

// ukuran maksimum stack
#define MAX 20

struct Stack {
   infotype info[MAX];
   int top;
};

// deklarasi semua fungsi dan prosedur yang bakal dipake
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
#### stack.cpp
```C++
#include "stack.h"

void createStack(Stack &S) {
   S.top = -1;
}

void push(Stack &S, infotype x) {
   if (S.top == MAX - 1) {
      cout << "stack penuh, tidak bisa menambah data lagi" << endl;
      return;
   }

   S.top = S.top + 1;
   S.info[S.top] = x;
}

infotype pop(Stack &S) {
   if (S.top == -1) {
      cout << "stack kosong, tidak ada yang bisa di-pop" << endl;
      return -1;
   }

   infotype data = S.info[S.top];

   S.top = S.top - 1;

   return data;
}

void printInfo(Stack S) {
   if (S.top == -1) {
      cout << "stack kosong" << endl;
      return;
   }

   cout << "[TOP] ";

   for (int i = S.top; i >= 0; i--) {
      cout << S.info[i];
      if (i > 0) cout << " -> ";
   }

   cout << "" << endl;
}

void balikStack(Stack &S) {
   int i = 0;
   int j = S.top;

   while (i < j) {
      infotype temp = S.info[i];
      S.info[i] = S.info[j];
      S.info[j] = temp;
      i++;
      j--;
   }
}
void pushAscending(Stack &S, infotype x) {
   if (S.top == MAX - 1) {
      cout << "stack penuh, tidak bisa menambah data lagi" << endl;
      return;
   }

   Stack temp;
   createStack(temp);

   while (S.top != -1 && S.info[S.top] > x) {
      push(temp, pop(S));
   }

   push(S, x);

   while (temp.top != -1) {
      push(S, pop(temp));
   }
}

void getInputStream(Stack &S) {
   int x;
   cout << "input data (untuk berhenti tekan sembarang selain angka): " << endl;
   while (cin >> x) {
       push(S, x);
   }
   cout << "input sudah ada di stack!" << endl;
}

```
#### main.cpp
```C++
#include "stack.h"

int main() {
   cout << "Program Stack Modul 7" << endl;

   Stack S;
   createStack(S);
   
   cout << "\n=== Tugas 1 ===" << endl;

   push(S, 3);
   push(S, 4);
   push(S, 8);
   pop(S);
   push(S, 2);
   push(S, 3);
   pop(S);
   push(S, 9);

   printInfo(S);

   cout << "balik stack" << endl;
   balikStack(S);
   printInfo(S);

   cout << "\n=== PushAscending ===" << endl;
   createStack(S);

   pushAscending(S, 3);
   pushAscending(S, 4);
   pushAscending(S, 8);
   pushAscending(S, 2);
   pushAscending(S, 3);
   pushAscending(S, 9);
   printInfo(S);
   cout << "balik stack" << endl;
   balikStack(S);
   printInfo(S);

   cout << "\n=== getInputStream ===" << endl;
   createStack(S);
   getInputStream(S);

   cout << "Isi Stack" << endl;
   printInfo(S);

   cout << "balik stack" << endl;
   balikStack(S);
   printInfo(S);
   return 0;
}
```
#### Output:
<img width="776" height="509" alt="image" src="https://github.com/user-attachments/assets/0b88c6d7-a48d-461b-9ef6-aa9c6c520cc9" />


Program ini terdiri dari tiga file yang bekerja bersama untuk mengelola struktur data Stack berbasis array dengan kapasitas maksimal 20 elemen. Unit terkecil dari sistem ini dimulai dari file stack.h, yang berfungsi sebagai header file untuk mendefinisikan struktur data Stack (terdiri dari array info dan indeks top) serta mendeklarasikan prototipe fungsi-fungsi utama seperti push, pop, dan createStack. File ini menjadi jembatan agar komponen program lainnya mengenal tipe data infotype dan operasi-operasi yang tersedia.

Logika atau implementasi dari operasi tersebut ditulis secara mendalam di dalam file stack.cpp. Di sini, setiap prosedur dijalankan sesuai prinsip Last In First Out (LIFO), termasuk fitur tambahan seperti balikStack untuk membalik urutan elemen, pushAscending yang memungkinkan pengisian data secara terurut menggunakan bantuan stack sementara, serta getInputStream untuk menangani input dinamis dari pengguna. Terakhir, file main.cpp berperan sebagai titik masuk program (entry point) yang menguji seluruh fungsionalitas tersebut melalui serangkaian skenario tugas, mulai dari manipulasi tumpukan biasa hingga pencetakan hasilnya ke layar secara visual.

#### Full code Screenshot:
##### stack.h
<img width="761" height="695" alt="image" src="https://github.com/user-attachments/assets/2630b8fb-dac2-47ac-bc33-975e549d53c2" />

##### stack.cpp
<img width="1859" height="975" alt="image" src="https://github.com/user-attachments/assets/b49c11ab-df72-4729-a038-029f125fc867" />

##### main.cpp
<img width="1614" height="933" alt="image" src="https://github.com/user-attachments/assets/9b950a8d-9c90-4eca-a677-7180e85ce116" />

## Kesimpulan
Program ini merupakan implementasi struktur data **Stack (Tumpukan)** menggunakan array dengan kapasitas statis sebanyak 20 elemen. Program ini berhasil mengintegrasikan operasi dasar *stack* seperti `createStack`, `push`, dan `pop` dengan fitur tambahan yang lebih kompleks seperti pembalikan urutan elemen (`balikStack`) dan pengurutan data otomatis (`pushAscending`). Melalui pemisahan kode menjadi tiga file (`stack.h`, `stack.cpp`, dan `main.cpp`), program ini menunjukkan penerapan konsep pemrograman modular yang baik, di mana definisi data, implementasi logika, dan pengujian program dipisahkan untuk memudahkan pemeliharaan kode. Pengujian pada bagian utama program membuktikan bahwa tumpukan dapat dikelola secara dinamis, baik melalui input kode langsung maupun melalui input interaktif dari pengguna menggunakan fungsi `getInputStream`.

**Poin-poin utama program:**

* **Efisiensi Pengurutan:** Fungsi `pushAscending` memungkinkan data tersusun rapi di dalam *stack* dengan memanfaatkan bantuan *stack* sementara.
* **Fleksibilitas Data:** Penggunaan `typedef int infotype` memudahkan pengembang jika ingin mengganti tipe data isi *stack* di masa mendatang cukup dengan mengubah satu baris di file *header*.
* **Interaktivitas:** Program mampu menerima input terus-menerus dari pengguna hingga diberikan karakter non-angka, yang memberikan pengalaman pengguna yang lebih fleksibel.

## Referensi
Trivusi. (2022, Juli). Struktur Data Stack: Pengertian, Karakteristik, dan Kegunaannya. 
https://www.trivusi.web.id/2022/07/struktur-data-stack.html

DTE Telkom University. (2025, 4 Juli). Struktur Data Dasar: Array, Linked List, Stack, dan Queue. 
https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/​

Yuliana. (n.d.). Data Structure - Bab 3. 
https://yuliana.lecturer.pens.ac.id/Struktur%20Data%20C/Teori%20SD%20-%20pdf/Data%20Structure%20-%20Bab%203.pdf

Repository Unikom. (n.d.). BAB II STACK (TUMPUKAN). 
https://repository.unikom.ac.id/42254/1/pertemuan%202.pdf

