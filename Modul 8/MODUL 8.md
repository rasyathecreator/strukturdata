# <h1 align="center">Laporan Praktikum Modul 8 QUEUE</h1>
<p align="center">Rasya Syahri Ramadhan - 103112430189</p>

## Dasar Teori

Queue merupakan struktur data linier yang mengikuti prinsip First In First Out (FIFO), di mana elemen pertama yang dimasukkan akan menjadi yang pertama dikeluarkan. Operasi utama terjadi pada dua ujung: front (depan untuk penghapusan) dan rear (belakang untuk penambahan).

### Definisi
Queue berfungsi seperti antrean nyata, dengan elemen disusun secara horizontal dan akses terbatas pada front serta rear untuk menjaga urutan FIFO. Implementasi umum menggunakan array atau linked list, cocok untuk simulasi proses seperti printer job atau scheduling CPU.

### Jenis Queue
- **Simple/Linear Queue**: Penyisipan di rear dan penghapusan di front secara linier.
- **Circular Queue**: Ujung rear terhubung ke front untuk penggunaan memori efisien, menghindari pemborosan ruang.
- **Priority Queue**: Elemen dikeluarkan berdasarkan prioritas, bukan urutan masuk.
- **Double-Ended Queue (Deque)**: Operasi insert/delete di kedua ujung.

### Operasi Dasar
- **Enqueue**: Menambahkan elemen ke rear.
- **Dequeue**: Menghapus elemen dari front.
- **Peek/Front**: Melihat elemen front tanpa menghapus.
- **IsEmpty/IsFull**: Cek kondisi antrian kosong atau penuh.

### Kelebihan dan Kekurangan
Queue efisien untuk operasi FIFO dengan O(1) waktu akses ujung, mendukung aplikasi real-time seperti buffering data, tetapi tidak fleksibel untuk akses elemen tengah. Circular queue mengatasi kekurangan memori linear queue.


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
<img width="801" height="469" alt="image" src="https://github.com/user-attachments/assets/c6a5ae39-d0c6-46fb-bb13-e2b72f9e1fb2" />

Program ini terdiri dari tiga file yang bekerja secara modular untuk mengimplementasikan struktur data Circular Queue (Antrean Melingkar) dengan kapasitas maksimal lima elemen. Unit pertama adalah file queue.h yang berfungsi sebagai header untuk mendefinisikan struktur data queue yang mencakup array info, indeks head dan tail, serta variabel count untuk melacak jumlah elemen. File ini juga mendeklarasikan prototipe fungsi-fungsi penting seperti enqueue, dequeue, dan pengecekan kondisi antrean. Implementasi teknis dari fungsi-fungsi tersebut ditulis di dalam file queue.cpp, yang menggunakan operasi modulo (% MAX_QUEUE) untuk memungkinkan indeks head dan tail kembali ke posisi awal saat mencapai batas maksimal, sehingga penggunaan memori array menjadi lebih efisien tanpa perlu menggeser elemen secara manual. Terakhir, file main.cpp berperan sebagai program utama yang menguji seluruh fungsionalitas tersebut melalui skenario penambahan (enqueuing) dan penghapusan (dequeued) data secara bertahap, sekaligus menampilkan isi antrean secara visual untuk memastikan logika program berjalan dengan benar.

### Full code screenshot
<img width="1647" height="975" alt="image" src="https://github.com/user-attachments/assets/82e6cc88-1440-40a6-a311-2f3f1de4c3b8" />




## Unguided 
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;
#define MAX 5

struct Queue {
   infotype info[MAX];
   int head;
   int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
#### queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
   Q.head = -1;
   Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
   return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
   return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
   if (isFullQueue(Q)) {
      cout << "queue penuh, tidak bisa menambah data" << endl;
   } else {
      if (isEmptyQueue(Q)) {
         Q.head = 0;
         Q.tail = 0;
      } else {
         Q.tail++;
      }
      Q.info[Q.tail] = x;
   }
}

infotype dequeue(Queue &Q) {
   if (isEmptyQueue(Q)) {
      cout << "queue kosong, tidak ada yang bisa dihapus" << endl;
      return -1;
   }

   infotype hasil = Q.info[Q.head];

   if (Q.head == Q.tail) {
      Q.head = -1;
      Q.tail = -1;
   } else {
      for (int i = Q.head; i < Q.tail; i++) {
         Q.info[i] = Q.info[i + 1];
      }
      Q.tail--;
   }

   return hasil;
}

void printInfo(Queue Q) {
   if (isEmptyQueue(Q)) {
      cout << Q.head << "  - " << Q.tail << "  | empty queue" << endl;
   } else {
      cout << " " << Q.head << "  -  " << Q.tail << "  | ";
      for (int i = Q.head; i <= Q.tail; i++) {
         cout << Q.info[i] << " ";
      }
      cout << endl;
   }
}
```
#### main.cpp
```C++
#include "queue.h"

int main() {
   cout << "Hello world!" << endl;

   cout<<"-----------------------"<<endl;
   cout<<" H  -  T  | Queue Info"<<endl;
   cout<<"-----------------------"<<endl;

   Queue Q;
   createQueue(Q);

   printInfo(Q);
   enqueue(Q,5); printInfo(Q);
   enqueue(Q,2); printInfo(Q);
   enqueue(Q,7); printInfo(Q);
   dequeue(Q); printInfo(Q);
   enqueue(Q,4); printInfo(Q);
   dequeue(Q); printInfo(Q);
   dequeue(Q); printInfo(Q);

   cout<<"-1  - -1  | empty queue"<<endl;

   return 0;
}
```
#### Output:
<img width="734" height="336" alt="image" src="https://github.com/user-attachments/assets/1e0eaf49-3e09-4fa1-a2f8-9fade9967ce1" />

Program ini terdiri dari tiga file yang bekerja secara modular untuk mengelola struktur data Queue dengan kapasitas maksimal 5 elemen. File queue.h berfungsi sebagai header yang mendefinisikan struktur Queue yang terdiri dari array info serta penanda head dan tail, sekaligus mendeklarasikan prototipe fungsi dasar seperti enqueue dan dequeue. Implementasi logika dari fungsi-fungsi tersebut berada di file queue.cpp, yang mengatur mekanisme penambahan data di posisi belakang (tail) dan penghapusan data dari posisi depan (head) dengan pergeseran elemen untuk menjaga urutan antrean. Terakhir, file main.cpp berperan sebagai program utama yang mensimulasikan penggunaan antrean tersebut, mulai dari inisialisasi, pengisian beberapa data angka, hingga penghapusan data, sambil menampilkan status indeks head dan tail secara visual ke layar di setiap tahapannya.

#### Full code Screenshot:
##### queue.h
<img width="1146" height="585" alt="image" src="https://github.com/user-attachments/assets/cf04d151-897d-4200-af9c-25801d42e090" />

##### queue.cpp
<img width="1559" height="907" alt="image" src="https://github.com/user-attachments/assets/f1674d80-d09e-464c-89d8-3c5a99b0b2de" />

##### main.cpp
<img width="1276" height="649" alt="image" src="https://github.com/user-attachments/assets/7379abde-e543-4e50-8489-15e9de078c74" />

## Kesimpulan
Program ini mengimplementasikan konsep antrean linier menggunakan array statis dengan kapasitas maksimal 5 elemen. Struktur ini bekerja berdasarkan prinsip **First In First Out (FIFO)**, di mana data yang pertama kali masuk akan menjadi yang pertama kali keluar. Melalui pemisahan ke dalam tiga file modular (`queue.h`, `queue.cpp`, dan `main.cpp`), program ini menunjukkan manajemen kode yang terorganisir antara definisi tipe data, logika operasional, dan eksekusi pengujian.

**Poin-Poin Utama Program:**

* **Mekanisme Pergeseran (Shifting):** Pada fungsi `dequeue`, program tidak hanya menghapus data, tetapi juga menggeser seluruh elemen yang tersisa ke arah depan untuk mengisi kekosongan indeks. Hal ini memastikan bahwa posisi `head` selalu berusaha kembali ke indeks awal setelah operasi penghapusan.
* **Manajemen Indeks:** Program menggunakan dua penanda, yaitu `head` dan `tail`, yang diinisialisasi pada nilai -1 untuk menunjukkan kondisi antrean kosong.
* **Validasi Kapasitas:** Terdapat pengecekan kondisi penuh (`isFullQueue`) dan kosong (`isEmptyQueue`) untuk mencegah kesalahan saat menambah data ke antrean yang sudah penuh atau menghapus data dari antrean yang tidak berisi.
* **Visualisasi Status:** Fungsi `printInfo` memberikan transparansi mengenai pergerakan indeks `head` dan `tail` setiap kali terjadi perubahan data, yang memudahkan dalam pelacakan status memori antrean.

## Daftar Pustaka
- Dicoding. (2023, 28 November). *Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya*. https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/[1]
- Trivusi. (2022, Juli). *Struktur Data Queue: Pengertian, Jenis, dan Kegunaannya*. https://www.trivusi.web.id/2022/07/struktur-data-queue.html[2]
- Course-Net. (2025, 6 Maret). *Struktur Data Queue: Pengertian, Jenis & Contoh Struktur Data Queue Dalam Mengolah Data*. https://course-net.com/blog/struktur-data-queue-pengertian-jenis-contoh-struktur-data-queue-dalam-mengolah-data/[3]
- Staditek. (n.d.). *Mengenal Struktur Data Queue: Jenis, Fungsi, Keuntunganya*. https://www.staditek.id/insight/arti-struktur-data-queue/[4]
- FIKTI UMSU. (2023, 17 Agustus). *Struktur Data Queue: Pengertian, Fungsi dan Jenisnya*. https://fikti.umsu.ac.id/struktur-data-queue-pengertian-fungsi-dan-jenisnya/[6]


