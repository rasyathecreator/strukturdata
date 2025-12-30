
# <h1 align="center">Laporan Praktikum Modul 5 Singly Linked List(1)</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori
Single linked list merupakan struktur data linier dinamis yang terdiri dari node-node yang saling terhubung secara searah melalui pointer next. Setiap node menyimpan data dan referensi ke node berikutnya, dengan node terakhir menunjuk ke NULL sebagai penanda akhir list.[1][2][3][5]

### Definisi
Single linked list, juga disebut singly linked list, adalah senarai berantai unidirectional di mana navigasi hanya dari head ke tail, berbeda dengan array yang memerlukan memori kontigu. Akses elemen dimulai dari head pointer, cocok untuk operasi insert/delete dinamis tanpa shifting elemen.[2][5][7][1]

### Komponen Node
Setiap node memiliki dua field utama: data (nilai seperti int atau string) dan next (pointer ke node berikutnya). Struktur node biasanya didefinisikan sebagai struct dengan alokasi memori dinamis.[3][4][6][1]

### Operasi Dasar
- **Insertion**: Di awal (update head), akhir (traverse ke tail), atau posisi tengah dengan O(n) traversal.[5][2]
- **Deletion**: Hapus node dengan menyesuaikan pointer next tetangga, efisien di head tapi O(n) di posisi lain.[6][3]
- **Traversal/Search**: Mulai dari head hingga NULL, kompleksitas O(n).[7][1]
- **IsEmpty**: Cek head == NULL.[5]

### Kelebihan dan Kekurangan
Single linked list hemat memori dibanding array untuk ukuran dinamis, mendukung insert/delete O(1) di head, tetapi tidak efisien untuk akses acak atau navigasi mundur. Overhead pointer menambah ukuran per node sekitar 4-8 byte.[2][3][7][5]

### Guided 

### 1. Linked List 1
`guided.cpp   `
```C++
#include <iostream>
using namespace std;

struct Node {
   int    isbn;
   string judul;
   string penulis;
   Node*  next;
};

Node* head = nullptr;

Node* buat_node(int isbn, string judul, string penulis) {
   Node* newNode    = new Node();

   newNode->isbn    = isbn;
   newNode->judul   = judul;
   newNode->penulis = penulis;

   newNode->next    = nullptr;

   return newNode;
}

void tambah_buku(int isbn, string judul, string penulis) {
   Node* newNode = buat_node(isbn, judul, penulis);

   if (head == nullptr) {
      head = newNode;
   } else {
      Node* temp = head;
      while (temp->next != nullptr) {
         temp = temp->next;
      }
      temp->next = newNode;
   }

   cout << "buku \"" << judul << "\" oleh " << penulis << " dengan isbn " << isbn << " berhasil ditambahkan.\n";
}

void hapusNode(int isbn) {
   if (head == nullptr) {
      cout << "list kosong!\n";
      return;
   }

   Node* temp = head;
   Node* prev = nullptr;

   if (temp != nullptr && temp->isbn == isbn) {
      head = temp->next;
      delete temp;
      cout << "buku dengan isbn " << isbn << 
      " berhasil dihapus.\n";
      return;
   }

   while (temp != nullptr && temp->isbn != isbn) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == nullptr) {
      cout << "isbn " << isbn << " nggak ditemukan!\n";
      return;
   }

   prev->next = temp->next;
   delete temp;
   cout << "buku dengan isbn " << isbn << " berhasil dihapus.\n";
}

void updateNode(int isbnLama, int isbnBaru, string judulBaru, string penulisBaru) {
   Node* temp = head;

   while (temp != nullptr && temp->isbn != isbnLama) {
      temp = temp->next;
   }

   if (temp == nullptr) {
      cout << "isbn " << isbnLama << " nggak ditemukan!\n";
   } else {
      temp->isbn = isbnBaru;
      temp->judul = judulBaru;
      temp->penulis = penulisBaru;
      cout << "buku berhasil diupdate jadi: "
           << judulBaru << " oleh " << penulisBaru 
           << " (isbn " << isbnBaru << ")\n";
   }
}

void tampilkanList() {
   if (head == nullptr) {
      cout << "list kosong!\n";
      return;
   }

   Node* temp = head;
   cout << "isi linked list:\n";

   while (temp != nullptr) {
      cout << "isbn: " << temp->isbn 
           << ", judul: " << temp->judul 
           << ", penulis: " << temp->penulis << endl;
      temp = temp->next;
   }
}

void cari_buku_berdasarkan_isbn(int isbn) {
   Node* temp = head;

   while (temp != nullptr) {
      if (temp->isbn == isbn) {
         cout << "buku ditemukan: "
              << temp->judul << " oleh " << temp->penulis 
              << " (isbn " << temp->isbn << ")\n";
         return;
      }
      temp = temp->next;
   }

   cout << "buku dengan isbn " << isbn << " tidak ditemukan!\n";
}

int main() {
   int pilihan, isbn, isbnBaru;
   string judul, penulis, judulBaru, penulisBaru;

   do {
      cout << "\n=== menu single linked list buku ===\n";
      cout << "1. insert belakang\n";
      cout << "2. hapus isbn\n";
      cout << "3. update buku\n";
      cout << "4. tampilkan list\n";
      cout << "5. cari buku berdasarkan isbn\n";
      cout << "0. keluar\n";
      cout << "pilih: ";
      cin >> pilihan;

      switch (pilihan) {
         case 1:
            cout << "masukkan isbn: ";
            cin >> isbn;
            cin.ignore();
            cout << "masukkan judul: ";
            getline(cin, judul);
            cout << "masukkan penulis: ";
            getline(cin, penulis);
            tambah_buku(isbn, judul, penulis);
            break;
         case 2:
            cout << "masukkan isbn yang ingin dihapus: ";
            cin >> isbn;
            hapusNode(isbn);
            break;
         case 3:
            cout << "masukkan isbn lama: ";
            cin >> isbn;
            cout << "masukkan isbn baru: ";
            cin >> isbnBaru;
            cin.ignore();
            cout << "masukkan judul baru: ";
            getline(cin, judulBaru);
            cout << "masukkan penulis baru: ";
            getline(cin, penulisBaru);
            updateNode(isbn, isbnBaru, judulBaru, penulisBaru);
            break;
         case 4:
            tampilkanList();
            break;
         case 5:
            cout << "masukkan isbn yang dicari: ";
            cin >> isbn;
            cari_buku_berdasarkan_isbn(isbn);
            break;
         case 0:
            cout << "program selesai.\n";
            break;
         default:
            cout << "pilihan nggak valid!\n";
      }
   } while (pilihan != 0);

   return 0;
}
```
### Output
<img width="1083" height="754" alt="image" src="https://github.com/user-attachments/assets/f3d2e064-db1c-458c-a84f-29512352cb67" />

Program C++ di atas merupakan implementasi struktur data Single Linked List yang digunakan untuk mengelola sistem pendataan buku sederhana secara dinamis di memori. Data setiap buku disimpan dalam sebuah struct Node yang mencakup informasi berupa nomor ISBN, judul buku, dan nama penulis, serta sebuah pointer next untuk menghubungkan satu buku ke buku berikutnya. Program ini menggunakan manajemen memori manual dengan operator new untuk mengalokasikan data baru dan delete untuk menghapus data, sehingga daftar buku dapat bertambah atau berkurang sesuai kebutuhan tanpa dibatasi oleh ukuran array statis.

Secara fungsionalitas, program ini menyediakan antarmuka berbasis menu interaktif yang memungkinkan pengguna melakukan operasi CRUD (Create, Read, Update, Delete). Pengguna dapat menambahkan buku ke urutan paling belakang melalui fungsi tambah_buku, mencari buku spesifik berdasarkan nomor ISBN, serta memperbarui detail informasi buku yang sudah ada. Selain itu, terdapat mekanisme penghapusan buku berdasarkan ISBN yang bekerja dengan cara mengatur ulang sambungan pointer dari node sebelumnya agar melompati node yang akan dihapus sebelum memori tersebut dibebaskan. Program akan terus berjalan dalam siklus perulangan do-while hingga pengguna memilih opsi untuk keluar.

### Screenshot Fullcode
<img width="1689" height="1006" alt="image" src="https://github.com/user-attachments/assets/1a651b08-ba4e-410e-91ad-f608b7fe6955" />

## Unguided 

### 1. Buatlah searcing untuk mencari nama pembeli pada unguided sebelumnya.
`unguided1.cpp`
```C++
#include <iostream>
using namespace std;

struct node {
   string nama;
   string pesanan;
   node*  next;
};

node* head = nullptr;
node* tail = nullptr;

node* tambah_node(string nama, string pesanan) {
   node* new_node    = new node();
   new_node->nama    = nama;
   new_node->pesanan = pesanan;
   new_node->next    = nullptr;
   return new_node;
}

void tambah_antrian(string nama, string pesanan) {
   node* new_node = tambah_node(nama, pesanan);

   if (head == nullptr) {
      head = tail = new_node;
   } else {
      tail->next = new_node;
      tail       = new_node;
   }

   cout << "antrian atas nama " << nama << " dengan pesanan " << pesanan << " berhasil ditambahkan.\n";
}

void layani_antrian() {
   if (head == nullptr) {
      cout << "antrian kosong, bikin antrian dulu.\n";
      return;
   }

   node* temp = head;

   cout << "melayani antrian atas nama " << temp->nama << " dengan pesanan " << temp->pesanan << ".\n";

   head = head->next;

   delete temp;

   if (head == nullptr) {
      tail = nullptr;
   }
}

void tampilkan_antrian() {
   if (head == nullptr) {
       cout << "antrian kosong.\n";
       return;
   }

   node* temp = head;
   int nomor = 1;

   cout << "\n=== daftar antrian ===\n";

   while (temp != nullptr) {
       cout << nomor++ << ". nama: " << temp->nama << ", pesanan: " << temp->pesanan << endl;
       temp = temp->next;
   }
}

void cari_pembeli(string nama_dicari) {
   if (head == nullptr) {
      cout << "antrian kosong, tidak ada data untuk dicari.\n";
      return;
   }

   node* temp = head;
   int posisi = 1;

   bool ketemu = false;

   while (temp != nullptr) {
      if (temp->nama == nama_dicari) {
         cout << "pembeli ada di posisi ke-" << posisi 
              << " dengan pesanan " << temp->pesanan << endl;
         ketemu = true;
         break;
      }
      temp = temp->next;
      posisi++;
   }

   if (!ketemu) {
      cout << "pembeli dengan nama " << nama_dicari << " tidak ditemukan dalam antrian.\n";
   }
}

int main() {
   int pilihan;
   string nama, pesanan;

   do {
       cout << "\n=== menu antrian pembeli ===\n";
       cout << "1. tambah antrian\n";
       cout << "2. layani antrian\n";
       cout << "3. tampilkan antrian\n";
       cout << "4. cari pembeli\n"; // menu baru untuk searching
       cout << "0. keluar\n";
       cout << "pilih: ";
       cin >> pilihan;
       cin.ignore();

       switch (pilihan) {
           case 1:
               cout << "masukkan nama pembeli: ";
               getline(cin, nama); // input bisa pakai spasi
               cout << "masukkan pesanan: ";
               getline(cin, pesanan);
               tambah_antrian(nama, pesanan);
               break;

           case 2:
               layani_antrian(); // hapus antrian paling depan
               break;

           case 3:
               tampilkan_antrian(); // tampilkan semua antrian
               break;

           case 4:
               cout << "masukkan nama pembeli yang ingin dicari: ";
               getline(cin, nama);
               cari_pembeli(nama); // panggil fungsi baru
               break;

           case 0:
               cout << "program selesai.\n";
               break;

           default:
               cout << "pilihan tidak valid!\n";
       }
   } while (pilihan != 0); // berhenti kalau user milih 0

   return 0;
}
```

#### Output:
<img width="916" height="709" alt="image" src="https://github.com/user-attachments/assets/0f532ab9-d21b-416c-a9bf-6749b113438b" />

Program C++ ini mengimplementasikan konsep struktur data Queue (antrean) menggunakan Single Linked List untuk mensimulasikan sistem pelayanan pembeli secara dinamis. Setiap elemen dalam antrean direpresentasikan oleh sebuah node yang menyimpan informasi berupa nama pembeli dan jenis pesanan, serta sebuah pointer next untuk menyambungkan ke pengantre berikutnya. Berbeda dengan implementasi list biasa, program ini menggunakan dua pointer khusus, yaitu head untuk menandai bagian depan antrean dan tail untuk menandai bagian belakang, sehingga proses penambahan data menjadi lebih efisien.

Operasi utama dalam program ini mengikuti prinsip FIFO (First-In, First-Out), di mana pembeli yang pertama kali datang akan dilayani terlebih dahulu. Fungsi tambah_antrian memasukkan data melalui posisi tail, sementara fungsi layani_antrian menghapus data dari posisi head dan membebaskan memorinya menggunakan instruksi delete. Selain manajemen antrean dasar, program ini juga dilengkapi dengan fitur tambahan seperti tampilkan_antrian untuk melihat daftar seluruh pengantre dan cari_pembeli untuk melakukan pencarian linear guna menemukan posisi spesifik seorang pembeli berdasarkan namanya. Seluruh fitur tersebut diatur dalam sebuah menu interaktif berbasis teks yang memungkinkan pengguna mengelola data secara fleksibel hingga program dihentikan.

#### Full code Screenshot:
<img width="1690" height="974" alt="image" src="https://github.com/user-attachments/assets/a012349c-1bf9-4734-b6c2-64a23236c217" />

### 2. gunakan latihan pada pertemuan minggun ini dan tambahkan searching untuk mencari buku berdasarkan judul, penulis, dan ISBN.
`unguided2.cpp`
```C++
#include <iostream>
using namespace std;

struct Node {
   int isbn;
   string judul;
   string penulis;
   Node* next;
};

Node* head = nullptr;

Node* buat_node(int isbn, string judul, string penulis) {
   Node* newNode = new Node();
   newNode->isbn = isbn;
   newNode->judul = judul;
   newNode->penulis = penulis;
   newNode->next = nullptr;
   return newNode;
}

void tambah_buku(int isbn, string judul, string penulis) {
   Node* newNode = buat_node(isbn, judul, penulis);
   if (head == nullptr) {
      head = newNode;
   } else {
      Node* temp = head;
      while (temp->next != nullptr) temp = temp->next;
      temp->next = newNode;
   }
   cout << "buku \"" << judul << "\" oleh " << penulis << " dengan isbn " << isbn << " berhasil ditambahkan.\n";
}

void hapusNode(int isbn) {
   if (head == nullptr) {
      cout << "list kosong!\n";
      return;
   }
   Node* temp = head;
   Node* prev = nullptr;
   if (temp != nullptr && temp->isbn == isbn) {
      head = temp->next;
      delete temp;
      cout << "buku dengan isbn " << isbn << " berhasil dihapus.\n";
      return;
   }
   while (temp != nullptr && temp->isbn != isbn) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == nullptr) {
      cout << "isbn " << isbn << " tidak ditemukan!\n";
      return;
   }
   prev->next = temp->next;
   delete temp;
   cout << "buku dengan isbn " << isbn << " berhasil dihapus.\n";
}

void updateNode(int isbnLama, int isbnBaru, string judulBaru, string penulisBaru) {
   Node* temp = head;
   while (temp != nullptr && temp->isbn != isbnLama) temp = temp->next;
   if (temp == nullptr) {
      cout << "isbn " << isbnLama << " tidak ditemukan!\n";
   } else {
      temp->isbn = isbnBaru;
      temp->judul = judulBaru;
      temp->penulis = penulisBaru;
      cout << "buku berhasil diupdate jadi: " << judulBaru << " oleh " << penulisBaru << " (isbn " << isbnBaru << ")\n";
   }
}

void tampilkanList() {
   if (head == nullptr) {
      cout << "list kosong!\n";
      return;
   }
   Node* temp = head;
   cout << "isi linked list:\n";
   while (temp != nullptr) {
      cout << "isbn: " << temp->isbn << ", judul: " << temp->judul << ", penulis: " << temp->penulis << endl;
      temp = temp->next;
   }
}

void cariBuku() {
   if (head == nullptr) {
      cout << "list kosong!\n";
      return;
   }
   int pilihan;
   cout << "\n1. cari berdasarkan ISBN\n2. cari berdasarkan Judul\n3. cari berdasarkan Penulis\npilih: ";
   cin >> pilihan;
   cin.ignore();
   Node* temp = head;
   bool ditemukan = false;

   if (pilihan == 1) {
      int cariISBN;
      cout << "masukkan ISBN: ";
      cin >> cariISBN;
      while (temp != nullptr) {
         if (temp->isbn == cariISBN) {
            cout << "ditemukan: " << temp->judul << " oleh " << temp->penulis << endl;
            ditemukan = true;
         }
         temp = temp->next;
      }
   } else if (pilihan == 2) {
      string cariJudul;
      cout << "masukkan judul: ";
      getline(cin, cariJudul);
      while (temp != nullptr) {
         if (temp->judul == cariJudul) {
            cout << "ditemukan: ISBN " << temp->isbn << ", penulis: " << temp->penulis << endl;
            ditemukan = true;
         }
         temp = temp->next;
      }
   } else if (pilihan == 3) {
      string cariPenulis;
      cout << "masukkan penulis: ";
      getline(cin, cariPenulis);
      while (temp != nullptr) {
         if (temp->penulis == cariPenulis) {
            cout << "ditemukan: " << temp->judul << " (ISBN " << temp->isbn << ")\n";
            ditemukan = true;
         }
         temp = temp->next;
      }
   } else {
      cout << "pilihan tidak valid!\n";
      return;
   }

   if (!ditemukan) cout << "data tidak ditemukan!\n";
}

int main() {
   int pilihan, isbn, isbnBaru;
   string judul, penulis, judulBaru, penulisBaru;
   do {
      cout << "\n=== menu single linked list buku ===\n";
      cout << "1. insert belakang\n";
      cout << "2. hapus isbn\n";
      cout << "3. update buku\n";
      cout << "4. tampilkan list\n";
      cout << "5. cari buku\n";
      cout << "0. keluar\n";
      cout << "pilih: ";
      cin >> pilihan;

      switch (pilihan) {
         case 1:
            cout << "masukkan isbn: ";
            cin >> isbn;
            cin.ignore();
            cout << "masukkan judul: ";
            getline(cin, judul);
            cout << "masukkan penulis: ";
            getline(cin, penulis);
            tambah_buku(isbn, judul, penulis);
            break;
         case 2:
            cout << "masukkan isbn yang ingin dihapus: ";
            cin >> isbn;
            hapusNode(isbn);
            break;
         case 3:
            cout << "masukkan isbn lama: ";
            cin >> isbn;
            cout << "masukkan isbn baru: ";
            cin >> isbnBaru;
            cin.ignore();
            cout << "masukkan judul baru: ";
            getline(cin, judulBaru);
            cout << "masukkan penulis baru: ";
            getline(cin, penulisBaru);
            updateNode(isbn, isbnBaru, judulBaru, penulisBaru);
            break;
         case 4:
            tampilkanList();
            break;
         case 5:
            cariBuku();
            break;
         case 0:
            cout << "program selesai.\n";
            break;
         default:
            cout << "pilihan tidak valid!\n";
      }
   } while (pilihan != 0);
   return 0;
}
```

#### Output
<img width="1018" height="598" alt="image" src="https://github.com/user-attachments/assets/727b530e-c8e1-4e6f-ac02-91368671b853" />

Program C++ ini merupakan pengembangan dari sistem manajemen buku berbasis Single Linked List yang mengelola koleksi pustaka secara dinamis di dalam memori. Inti dari program ini terletak pada struktur Node yang menyimpan tiga jenis informasi utama, yaitu ISBN, judul buku, dan penulis, serta sebuah pointer next yang menghubungkan elemen satu ke elemen lainnya. Penggunaan linked list memungkinkan program untuk menambah atau menghapus data buku tanpa perlu mendefinisikan kapasitas maksimal di awal, memberikan fleksibilitas yang lebih besar dibandingkan penggunaan struktur array statis.

Secara fungsional, program ini menawarkan kontrol penuh terhadap data melalui sistem menu interaktif. Fitur unggulan dalam versi ini adalah fungsi cariBuku yang lebih kompleks, di mana pengguna tidak hanya bisa mencari berdasarkan ISBN, tetapi juga memiliki opsi pencarian berdasarkan judul atau nama penulis melalui sub-menu khusus. Selain itu, program menyediakan logika penghapusan data yang aman (hapusNode) dengan menyambungkan kembali rantai pointer sebelum memori dibebaskan, serta fitur pembaruan data (updateNode) yang memungkinkan modifikasi total pada informasi buku yang sudah terdaftar. Seluruh operasi ini dilakukan dalam siklus perulangan yang akan terus berjalan hingga pengguna memilih untuk keluar dari program.
#### Full Code Screenshot
<img width="1690" height="980" alt="image" src="https://github.com/user-attachments/assets/df5cdf21-278e-470a-8e10-d7b4dda18455" />



## Kesimpulan
Praktikum ini berhasil mengimplementasikan struktur data **singly linked list** dalam C++, mencakup definisi node (`ElmList`) dan kepala list (`List`), serta seluruh operasi manipulasi esensial seperti inisialisasi (`createList`), manajemen memori dinamis (`alokasi`, `dealokasi`), penyisipan (`insertFirst`), pencarian (`search`), dan berbagai jenis penghapusan (`deleteFirst`, `deleteLast`, `deleteAfter`). Program utama menguji fungsionalitas ini dengan membangun list awal **9, 12, 8, 0, 2** dan kemudian secara berurutan menghapus elemen pertama (9), elemen terakhir (2), dan elemen setelah 12 (8), menyisakan **12, 0**. Pembelajaran utama yang didapat adalah pemahaman mendalam tentang peran **pointer (`address`)** dalam menghubungkan node secara non-sekuensial, efisiensi waktu $O(1)$ untuk operasi di awal list, kompleksitas $O(n)$ untuk operasi di akhir list, dan pentingnya **manajemen memori eksplisit** untuk mencegah *memory leak*.


## Daftar Pustaka
- Daimabali. (2019, 27 Desember). *Mengenal Single Linked List dalam Struktur Data*. https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html[1]
- Dosen UPI-YAI. (n.d.). *STRUKTUR DATA Linked List*. https://dosen.upi-yai.ac.id/v5/dokumen/materi/011061/73_20230527020432_Pert%2008%20-%20Linked%20List.pdf[2]
- Rumah Coding. (2024, 24 Mei). *Linked List: Pengertian dan Implementasi Dasar*. https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/[3]
- Trivusi. (2022, Juli). *Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya*. https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html[5]
- FIKTI UMSU. (2023, 24 Juli). *Pengertian Linked List: Struktur Data dalam Pemrograman*. https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/[7]

[1](https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html)
[2](https://dosen.upi-yai.ac.id/v5/dokumen/materi/011061/73_20230527020432_Pert%2008%20-%20Linked%20List.pdf)
[3](https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/)
[4](http://arliansyahazhary.blogspot.com/2015/06/struktur-data-singly-linked-list.html)
[5](https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html)
[6](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20&%20DELETE.pdf)
[7](https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/)
[8](https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F86227%2Fmod_resource%2Fcontent%2F1%2FModul+Struktur+Data-Linked+List.pdf)
[9](https://socs.binus.ac.id/2017/03/15/single-linked-list/)
[10](https://id.scribd.com/doc/122367708/Single-Linked-List-Circular)
