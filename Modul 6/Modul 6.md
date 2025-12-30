# <h1 align="center">Laporan Praktikum Modul 6 Doubly Linked List(1)</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori

Doubly linked list merupakan struktur data linier yang memungkinkan navigasi dua arah antar node. Setiap node menyimpan data beserta dua pointer: prev untuk node sebelumnya dan next untuk node berikutnya
### Definisi
Doubly linked list adalah perluasan dari single linked list, di mana setiap node memiliki referensi ke node sebelumnya dan sesudahnya, sehingga traversal maju atau mundur lebih efisien. Struktur ini terdiri dari head (pointer awal) dan tail (pointer akhir), dengan node null di kedua ujung untuk menandai batas

### Komponen Node
Setiap node doubly linked list memiliki tiga elemen utama: data (nilai yang disimpan), pointer prev (menunjuk ke node sebelumnya), dan pointer next (menunjuk ke node berikutnya). Ini memerlukan lebih banyak memori dibanding single linked list karena tambahan pointer prev.

### Operasi Utama
1. Insertion: Dapat dilakukan di awal, akhir, atau tengah dengan menyesuaikan pointer prev dan next pada node terkait.​
2. Deletion: Lebih fleksibel karena akses dua arah memudahkan penghapusan dari posisi mana pun tanpa traversal penuh.​
3. Traversal: Navigasi forward (via next) atau backward (via prev) dengan kompleksitas O(n).
​
### Kelebihan dan Kekurangan
Doubly linked list lebih fleksibel untuk operasi insert/delete dibanding array atau single linked list, tetapi memiliki overhead memori lebih tinggi. Cocok untuk aplikasi seperti browser history atau undo/redo feature.

## Guided 

###
#### mainguided1.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node *ptr_first = NULL;
Node *ptr_last = NULL;

void add_first(int value) {
    Node *newNode = new Node {value, NULL, ptr_first};
    
    // if (ptr_first == NULL)
        ptr_last = newNode;
    }
    else {
        ptr_first->prev = newNode;
    }
    ptr_first = newNode;
}

void add_last(int value) {
    Node *newNode = new Node{value, ptr_last, NULL};
    if (ptr_last == NULL) {
        ptr_first = newNode;
    } else {
        ptr_last -> next = newNode;
    }
    ptr_last = newNode;
}

void add_target(int targetValue, int newValue){
    Node *current = ptr_first;
    while (current != NULL && current->data != targetValue){
        current = current->next;
    }

    if (current != NULL){
        add_last(newValue);
    }
    else{
        Node *newNode = new Node{newValue, current, current->next};
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void view(){
    Node *current = ptr_first;
    if (current == NULL){
        cout << "List Kosong\n";
        return;
    }
    while (current != NULL)
    {
        cout << current->data << (current->next != NULL ? " <-> " : "");
        current = current->next;
    }
    cout<< endl;
}

void delete_first(){
    if (ptr_first == NULL)
    return;

    Node *temp = ptr_first;

    if (ptr_first == ptr_last){
        ptr_first = NULL;
        ptr_last = NULL;
    }
    else{
        ptr_first = ptr_first->next;
        ptr_first->prev = NULL;
    }
    delete temp;
}

void delete_last(){
    if (ptr_last == NULL)
    return;

    Node *temp = ptr_last;

    if (ptr_first == ptr_last){
        ptr_first = NULL;
        ptr_last = NULL;
    }
    else{
        ptr_last = ptr_last->prev;
        ptr_last->next = NULL;
    }
    delete temp;
}

void delete_target(int targetValue){
    Node *current = ptr_first;
    while (current != NULL && current->data != targetValue){
        current = current->next;
    }

    if (current != NULL){
        if (current == ptr_first){
            delete_first();
            return;
        }
        if (current == ptr_last)
        {
           delete_last();
           return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;

    }
}

void edit_node(int targetVaue, int newValue){
    Node *current = ptr_first;
    while (current != NULL && current->data != targetVaue)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        current->data = newValue;
    }
    
    
}

int main() {
    add_first(10);
    add_first(5);
    add_last(20);
    cout << "Awal\t\t\t: ";
    view();

    delete_first();
    cout << "Setelah delete_first\t: ";
    view();
    delete_last();
    cout << "Setelah delete_last\t: ";
    view();

    add_last(30);
    add_last(40);
    cout << "Setelah tambah\t\t: ";
    view();

    delete_target(30);
    cout << "Setelah delete_target\t: ";
    view();
    
}
```
Program C++ di atas mengimplementasikan **struktur data doubly linked list** dengan menggunakan pointer `prev` dan `next` pada setiap node untuk menghubungkan elemen secara dua arah. Program ini memiliki dua pointer global, yaitu `ptr_first` sebagai penunjuk node pertama dan `ptr_last` sebagai penunjuk node terakhir. Berbagai operasi dasar disediakan, seperti penambahan node di awal (`add_first`), di akhir (`add_last`), dan setelah node tertentu (`add_target`), penghapusan node di awal (`delete_first`), di akhir (`delete_last`), maupun berdasarkan nilai tertentu (`delete_target`), serta pengubahan data node (`edit_node`). Fungsi `view` digunakan untuk menampilkan isi linked list dari awal hingga akhir dengan format berantai. Pada fungsi `main`, beberapa operasi dilakukan secara berurutan untuk mendemonstrasikan proses penambahan dan penghapusan node, sehingga memperlihatkan bagaimana struktur doubly linked list berubah setelah setiap operasi dijalankan.

### Full code screenshot
<img width="1551" height="965" alt="image" src="https://github.com/user-attachments/assets/39623c87-83f2-4ed3-97e2-783a526489f5" />
<img width="1551" height="966" alt="image" src="https://github.com/user-attachments/assets/0aa0e52d-3d79-4dd9-8beb-a10e5c65b6c9" />

### Screenshot Output
<img width="1054" height="184" alt="image" src="https://github.com/user-attachments/assets/a3bbf39a-7ae3-4a4d-9323-56812ce357d4" />


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
#### doublylist.h
```C++
#ifndef doublylist_h
#define doublylist_h

#include <string>
using namespace std;
#define nil NULL

typedef struct kendaraan {
    string nomor_polisi;
    string warna;
    int tahun_buat;
} tipe_data_kendaraan;

typedef struct elemen_list *alamat_elemen;

struct elemen_list {
    tipe_data_kendaraan info_kendaraan;
    alamat_elemen elemen_berikutnya;
    alamat_elemen elemen_sebelumnya;
};

struct list_utama {
    alamat_elemen elemen_pertama;
    alamat_elemen elemen_terakhir;
};

void tambah_list(list_utama &list_kendaraan);
alamat_elemen alokasi(tipe_data_kendaraan data_kendaraan);
void dealokasi(alamat_elemen &elemen_kendaraan);
void print_info(list_utama list_kendaraan);
void insert_depan(list_utama &list_kendaraan, alamat_elemen elemen_kendaraan);
alamat_elemen cari_elemen(list_utama list_kendaraan, string nomor_polisi);
void hapus_depan(list_utama &list_kendaraan, alamat_elemen &elemen_kendaraan);
void hapus_belakang(list_utama &list_kendaraan, alamat_elemen &elemen_kendaraan);
void hapus_setelah(alamat_elemen elemen_sebelumnya, alamat_elemen &elemen_kendaraan);

#endif
```
#### doublylist.cpp
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void tambah_list(list_utama &list_kendaraan) {
    list_kendaraan.elemen_pertama = nil;
    list_kendaraan.elemen_terakhir = nil;
}

alamat_elemen alokasi(tipe_data_kendaraan data_kendaraan) {
    alamat_elemen elemen_kendaraan = new elemen_list;
    elemen_kendaraan->info_kendaraan = data_kendaraan;
    elemen_kendaraan->elemen_berikutnya = nil;
    elemen_kendaraan->elemen_sebelumnya = nil;
    return elemen_kendaraan;
}

void dealokasi(alamat_elemen &elemen_kendaraan) {
    delete elemen_kendaraan;
    elemen_kendaraan = nil;
}

void insert_depan(list_utama &list_kendaraan, alamat_elemen elemen_kendaraan) {
    if (list_kendaraan.elemen_pertama == nil) {
        list_kendaraan.elemen_pertama = elemen_kendaraan;
        list_kendaraan.elemen_terakhir = elemen_kendaraan;
    } else {
        elemen_kendaraan->elemen_sebelumnya = list_kendaraan.elemen_terakhir;
        (list_kendaraan.elemen_terakhir)->elemen_berikutnya = elemen_kendaraan;
        list_kendaraan.elemen_terakhir = elemen_kendaraan;
    }
}

void print_info(list_utama list_kendaraan) {
    if (list_kendaraan.elemen_pertama == nil) {
        cout << "list kosong" << endl;
    } else {
        alamat_elemen elemen_kendaraan = list_kendaraan.elemen_pertama;
        while (elemen_kendaraan != nil) {
            cout << "nomor polisi : " << elemen_kendaraan->info_kendaraan.nomor_polisi << endl;
            cout << "warna        : " << elemen_kendaraan->info_kendaraan.warna << endl;
            cout << "tahun buat   : " << elemen_kendaraan->info_kendaraan.tahun_buat << endl;
            cout << endl;
            elemen_kendaraan = elemen_kendaraan->elemen_berikutnya;
        }
    }
}

alamat_elemen cari_elemen(list_utama list_kendaraan, string nomor_polisi) {
    alamat_elemen elemen_kendaraan = list_kendaraan.elemen_pertama;
    while (elemen_kendaraan != nil) {
        if (elemen_kendaraan->info_kendaraan.nomor_polisi == nomor_polisi) {
            return elemen_kendaraan;
        }
        elemen_kendaraan = elemen_kendaraan->elemen_berikutnya;
    }
    return nil;
}

void hapus_depan(list_utama &list_kendaraan, alamat_elemen &elemen_kendaraan) {
    if (list_kendaraan.elemen_pertama == nil) {
        elemen_kendaraan = nil;
    } else if (list_kendaraan.elemen_pertama == list_kendaraan.elemen_terakhir) {
        elemen_kendaraan = list_kendaraan.elemen_pertama;
        list_kendaraan.elemen_pertama = nil;
        list_kendaraan.elemen_terakhir = nil;
    } else {
        elemen_kendaraan = list_kendaraan.elemen_pertama;
        list_kendaraan.elemen_pertama = (list_kendaraan.elemen_pertama)->elemen_berikutnya;
        (list_kendaraan.elemen_pertama)->elemen_sebelumnya = nil;
        elemen_kendaraan->elemen_berikutnya = nil;
    }
}

void hapus_belakang(list_utama &list_kendaraan, alamat_elemen &elemen_kendaraan) {
    if (list_kendaraan.elemen_pertama == nil) {
        elemen_kendaraan = nil;
    } else if (list_kendaraan.elemen_pertama == list_kendaraan.elemen_terakhir) {
        elemen_kendaraan = list_kendaraan.elemen_terakhir;
        list_kendaraan.elemen_pertama = nil;
        list_kendaraan.elemen_terakhir = nil;
    } else {
        elemen_kendaraan = list_kendaraan.elemen_terakhir;
        list_kendaraan.elemen_terakhir = (list_kendaraan.elemen_terakhir)->elemen_sebelumnya;
        (list_kendaraan.elemen_terakhir)->elemen_berikutnya = nil;
        elemen_kendaraan->elemen_sebelumnya = nil;
    }
}

void hapus_setelah(alamat_elemen elemen_sebelumnya, alamat_elemen &elemen_kendaraan) {
    if (elemen_sebelumnya == nil || elemen_sebelumnya->elemen_berikutnya == nil) {
        elemen_kendaraan = nil;
    } else {
        elemen_kendaraan = elemen_sebelumnya->elemen_berikutnya;
        elemen_sebelumnya->elemen_berikutnya = elemen_kendaraan->elemen_berikutnya;
        if (elemen_kendaraan->elemen_berikutnya != nil) {
            (elemen_kendaraan->elemen_berikutnya)->elemen_sebelumnya = elemen_sebelumnya;
        }
        elemen_kendaraan->elemen_berikutnya = nil;
        elemen_kendaraan->elemen_sebelumnya = nil;
    }
}
```
#### main.cpp
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    list_utama daftar_kendaraan;
    tambah_list(daftar_kendaraan);

    int pilihan_menu;
    do {
        cout << "\n=== menu doubly linked list kendaraan ===" << endl;
        cout << "1. input data kendaraan" << endl;
        cout << "2. tampilkan semua data" << endl;
        cout << "3. cari data berdasarkan nomor polisi" << endl;
        cout << "4. hapus data berdasarkan nomor polisi" << endl;
        cout << "0. keluar" << endl;
        cout << "pilih menu: ";
        cin >> pilihan_menu;

        if (pilihan_menu == 1) {
            tipe_data_kendaraan data_kendaraan_baru;
            cout << "masukkan nomor polisi : ";
            cin >> data_kendaraan_baru.nomor_polisi;
            cout << "masukkan warna        : ";
            cin >> data_kendaraan_baru.warna;
            cout << "masukkan tahun buat   : ";
            cin >> data_kendaraan_baru.tahun_buat;

            alamat_elemen elemen_kendaraan_baru = alokasi(data_kendaraan_baru);
            insert_depan(daftar_kendaraan, elemen_kendaraan_baru);
            cout << "data berhasil dimasukkan.\n";

        } else if (pilihan_menu == 2) {
            print_info(daftar_kendaraan);

        } else if (pilihan_menu == 3) {
            string nomor_polisi_dicari;
            cout << "masukkan nomor polisi yang ingin dicari: ";
            cin >> nomor_polisi_dicari;

            alamat_elemen elemen_ditemukan = cari_elemen(daftar_kendaraan, nomor_polisi_dicari);
            if (elemen_ditemukan != nil) {
                cout << "data ditemukan:\n";
                cout << "nomor polisi : " << elemen_ditemukan->info_kendaraan.nomor_polisi << endl;
                cout << "warna        : " << elemen_ditemukan->info_kendaraan.warna << endl;
                cout << "tahun buat   : " << elemen_ditemukan->info_kendaraan.tahun_buat << endl;
            } else {
                cout << "data tidak ditemukan.\n";
            }

        } else if (pilihan_menu == 4) {
            string nomor_polisi_dihapus;
            cout << "masukkan nomor polisi yang ingin dihapus: ";
            cin >> nomor_polisi_dihapus;

            alamat_elemen elemen_dihapus = cari_elemen(daftar_kendaraan, nomor_polisi_dihapus);
            alamat_elemen elemen_sementara;

            if (elemen_dihapus == nil) {
                cout << "data tidak ditemukan.\n";
            } else if (elemen_dihapus == daftar_kendaraan.elemen_pertama) {
                hapus_depan(daftar_kendaraan, elemen_sementara);
                dealokasi(elemen_sementara);
                cout << "data berhasil dihapus (elemen pertama).\n";
            } else if (elemen_dihapus == daftar_kendaraan.elemen_terakhir) {
                hapus_belakang(daftar_kendaraan, elemen_sementara);
                dealokasi(elemen_sementara);
                cout << "data berhasil dihapus (elemen terakhir).\n";
            } else {
                hapus_setelah(elemen_dihapus->elemen_sebelumnya, elemen_sementara);
                dealokasi(elemen_sementara);
                cout << "data berhasil dihapus (elemen tengah).\n";
            }
        }
    } while (pilihan_menu != 0);

    cout << "program selesai.\n";
    return 0;
}
```
#### Output:
<img width="489" height="867" alt="image" src="https://github.com/user-attachments/assets/5d71d9fb-def4-4eea-840b-da73517b45be" />
<img width="546" height="894" alt="image" src="https://github.com/user-attachments/assets/5104d3b0-c6b9-4613-b606-1771a5eaebdf" />


Ketiga file program tersebut saling terhubung untuk membangun dan menjalankan **doubly linked list** secara terstruktur dan modular. File **header (`doublylist.h`)** berfungsi sebagai deklarasi, yang berisi definisi struktur `Node`, deklarasi pointer global untuk node pertama dan terakhir, serta prototipe seluruh fungsi operasi linked list, sehingga dapat diakses oleh file lain tanpa duplikasi kode. File **implementasi (`doublylist.cpp`)** berisi realisasi dari fungsi-fungsi yang telah dideklarasikan di header, seperti penambahan node di awal, akhir, dan posisi tertentu, penghapusan node, pengeditan data, serta penampilan isi linked list, dengan mengelola pointer `prev` dan `next` agar hubungan antar node tetap konsisten. Sementara itu, file **utama (`main.cpp`)** berperan sebagai driver program yang menggunakan fungsi-fungsi dari `doublylist.cpp` untuk mendemonstrasikan cara kerja doubly linked list melalui serangkaian operasi, seperti penambahan, penghapusan, dan penampilan data. Pembagian program ke dalam tiga file ini membuat kode lebih rapi, mudah dipelihara, dan mencerminkan penerapan konsep modularitas dalam pemrograman C++.

#### Full code Screenshot:
<img width="1788" height="973" alt="image" src="https://github.com/user-attachments/assets/d5643318-74c9-4558-9753-683a3a476537" />
<img width="996" height="926" alt="image" src="https://github.com/user-attachments/assets/7ba01dd9-a32a-4bde-a167-69427065038a" />
<img width="1861" height="971" alt="image" src="https://github.com/user-attachments/assets/08e7f6fc-5382-4e2d-90de-b009221c8ac6" />

## Kesimpulan
Penerapan struktur data doubly linked list dapat dilakukan secara efektif dan terorganisir dengan membagi program ke dalam tiga file yang saling terhubung, yaitu header, file implementasi, dan file utama. Pendekatan modular ini memudahkan pengelolaan kode, meningkatkan keterbacaan, serta memungkinkan pengembangan dan perawatan program menjadi lebih efisien. Melalui implementasi berbagai operasi seperti penambahan, penghapusan, pengeditan, dan penelusuran data, program mampu memperlihatkan cara kerja doubly linked list secara menyeluruh, khususnya dalam pengelolaan pointer prev dan next. Dengan demikian, struktur program ini tidak hanya membantu memahami konsep linked list dua arah, tetapi juga memperkuat pemahaman tentang praktik pemrograman C++ yang baik dan terstruktur.

## Referensi
Rumah Coding. (2024, 24 Mei). Linked List: Pengertian dan Implementasi Dasar. 
https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/

Rizki Doank. (2016, 17 Oktober). Double Linked List. 
https://rizkidoank.com/2016/10/17/double-linked-list/

Scribd. (2025, 22 Oktober). Laporan Hasil Diskusi Double Linked List. 
https://id.scribd.com/document/698919519/c0f0f1f5-7bfe-4835-8711-533ecfb6d6b1-1

Daismabali. (n.d.). Memahami Doubly Linked List dalam Struktu Data dengan mudah. 
https://daismabali.com/artikel_detail/63/1/Memahami-Doubly-Linked-List-dalam-Struktu-Data-dengan-mudah.html
