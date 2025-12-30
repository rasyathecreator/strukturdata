# <h1 align="center">Laporan Praktikum Modul 13 MULTI LINKED LIST</h1>
<p align="center">Rasya Syahri Ramadhan - 103112430189</p>

## Dasar Teori
Multi linked list merupakan varian linked list yang lebih kompleks, di mana setiap node memiliki lebih dari dua pointer untuk menghubungkan ke multiple node lain, memungkinkan struktur relasional seperti one-to-many atau many-to-many. Struktur ini sering digunakan untuk merepresentasikan hubungan data yang tidak linier sederhana, berbeda dari single atau doubly linked list.[2][4][5][8]

### Definisi
Multi linked list, juga disebut multiple linked list, adalah senarai berantai dengan multiple link atau pointer per node, memungkinkan navigasi ke beberapa arah atau kelompok node terkait. Contohnya, node pegawai dapat memiliki pointer ke multiple node anak, membentuk hubungan 1-N tanpa duplikasi data.[4][5][9]

### Komponen Node
Setiap node berisi data dan beberapa pointer (lebih dari dua), seperti ptr1, ptr2, dst., yang masing-masing menunjuk ke node berbeda dalam list terpisah tapi saling terkait. Ini memerlukan manajemen pointer kompleks untuk traversal antar list.[7][8][2]

### Jenis dan Contoh
- **Multi Linked List 1-N**: Satu node parent terhubung ke banyak child, seperti pegawai dan anak-anaknya.[9][10]
- **Multi Linked List N-M**: Multiple parent ke multiple child, mirip graf berarah.[5]
Traversal dilakukan dengan mengikuti pointer spesifik, misal dari pegawai ke daftar anak.[4]

### Operasi Dasar
- **Insertion**: Tambah node child ke pointer spesifik parent.[8]
- **Deletion**: Hapus hubungan pointer tanpa hilang data terkait.[7]
- **Traversal**: Ikuti pointer tertentu untuk akses subset data.[2]

### Kelebihan dan Kekurangan
Multi linked list fleksibel untuk data relasional seperti database sederhana atau family tree, tetapi kompleks dalam implementasi dan traversal O(n) per pointer. Overhead memori tinggi karena multiple pointer.[5][8][4]



## Guided 

### Program Push, Pop, serta Menampilkan Isi Stack
#### mll.cpp
```C++
#include <iostream>
#include <string>
using namespace std;

struct child_node
{
   string info;
   child_node* next;
};

struct parent_node
{
   string info;
   child_node* child_head;
   parent_node* next;
};

parent_node *create_parent(string info)
{
   parent_node* new_node = new parent_node;
   new_node->info = info;
   new_node->child_head = NULL;
   new_node->next = NULL;
   return new_node;
};

child_node *create_child(string info)
{
   child_node* new_node = new child_node;
   new_node->info = info;
   new_node->next = NULL;
   return new_node;
};

void insert_parent(parent_node *&head, string info)
{
   parent_node* new_node = create_parent(info);
   if (head == NULL)
   {
      head = new_node;
   }
   else
   {
      parent_node* temporary = head;
      while (temporary->next != NULL)
      {
         temporary = temporary->next;
      }
      temporary->next = new_node;
   }
}

void insert_child(parent_node *head, string parent_info, string child_info)
{
   parent_node *parent_temp = head;
   while (parent_temp != NULL && parent_temp->info != parent_info)
   {
      parent_temp = parent_temp->next;
   }
   if (parent_temp != NULL)
   {
      child_node *new_child = create_child(child_info);
      if (parent_temp->child_head == NULL)
      {
         parent_temp->child_head = new_child;
      }
      else
      {
         child_node *child_temp = parent_temp->child_head;
         while (child_temp->next != NULL)
         {
            child_temp = child_temp->next;
         }
         child_temp->next = new_child;
      }
   }
}

void print_all(parent_node *head)
{
   parent_node *parent_temp = head;
   while (parent_temp != NULL)
   {
      cout << parent_temp->info;
      child_node *child_temp = parent_temp->child_head;
      if (child_temp != NULL)
      {
         while (child_temp != NULL)
         {
            cout << " -> " << child_temp->info;
            child_temp = child_temp->next;
         }
      }
      cout << endl;
      parent_temp = parent_temp->next;
   }
}

int main()
{
   parent_node *list = NULL;

   insert_parent(list, "parent node 1");
   insert_parent(list, "parent node 2");

   print_all(list);
   cout << "\n";

   insert_child(list, "parent node 1", "child node a");
   insert_child(list, "parent node 1", "child node b");
   insert_child(list, "parent node 2", "child node c");

   print_all(list);

   return 0;
}
```
### Screenshot Output
<img width="1054" height="185" alt="image" src="https://github.com/user-attachments/assets/f8a2d0d9-bf41-4034-ad04-e47b0e9c3e7c" />

Program di atas merupakan implementasi dari struktur data Multi Linked List yang menggunakan relasi satu-ke-banyak (one-to-many) antara simpul induk dan simpul anak. Program ini mendefinisikan dua jenis struktur, yaitu parent_node sebagai list utama dan child_node sebagai sub-list yang terhubung ke setiap induk melalui penunjuk child_head. Mekanisme kerjanya memungkinkan pengguna untuk menyisipkan elemen induk baru ke dalam daftar utama, serta menambahkan elemen anak secara spesifik ke bawah induk tertentu berdasarkan pencarian informasi string. Melalui fungsi insert_child, program akan mencari lokasi induk yang sesuai terlebih dahulu sebelum menautkan simpul anak di akhir rantai sub-list induk tersebut. Terakhir, program menyediakan fungsi print_all untuk memvisualisasikan seluruh struktur data, di mana setiap induk ditampilkan bersama deretan anak-anaknya yang saling terhubung menggunakan tanda panah, memberikan gambaran hierarki data yang jelas.

### Full code screenshot
<img width="1642" height="969" alt="image" src="https://github.com/user-attachments/assets/5d0003c3-10c2-46fd-b657-fc2f4a588956" />

## Unguided 
### buat multilist.cpp untuk implementasi semua fungsi pada multilist.h. Buat main.cpp untuk pemanggilan fungsi-fungsi tersebut.
`multilist.h`
```C++
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak {
	infotypeanak info;
	address_anak next;
	address_anak prev;
};

struct listanak {
	address_anak first;
	address_anak last;
};

struct elemen_list_induk {
	infotypeinduk info;
	listanak lanak;
	address next;
	address prev;
};

struct listinduk {
	address first;
	address last;
};

bool list_empty(listinduk L);
bool list_empty_anak(listanak L);

void create_list(listinduk &L);
void create_list_anak(listanak &L);

address alokasi(infotypeinduk P);
address_anak alokasi_anak(infotypeanak P);

void dealokasi(address P);
void dealokasi_anak(address_anak P);

address find_elm(listinduk L, infotypeinduk X);
address_anak find_elm_anak(listanak L, infotypeanak X);

bool ffind_elm(listinduk L, address P);
bool ffind_elm_anak(listanak L, address_anak P);

address find_before(listinduk L, address P);
address_anak find_before_anak(listanak L, infotypeanak X, address_anak P);

void insert_first(listinduk &L, address P);
void insert_after(listinduk &L, address P, address Prec);
void insert_last(listinduk &L, address P);

void insert_first_anak(listanak &L, address_anak P);
void insert_after_anak(listanak &L, address_anak P, address_anak Prec);
void insert_last_anak(listanak &L, address_anak P);

void del_first(listinduk &L, address &P);
void del_last(listinduk &L, address &P);
void del_after(listinduk &L, address &P, address Prec);
void delp(listinduk &L, infotypeinduk X);

void del_first_anak(listanak &L, address_anak &P);
void del_last_anak(listanak &L, address_anak &P);
void del_after_anak(listanak &L, address_anak &P, address_anak Prec);
void delp_anak(listanak &L, infotypeanak X);

void print_info(listinduk L);
int nb_list(listinduk L);

void print_info_anak(listanak L);
int nb_list_anak(listanak L);

void del_all(listinduk &L);

#endif
```
`multilist.cpp`
```C++
#include <iostream>
#include "multilist.h"
using namespace std;

bool list_empty(listinduk L) {
	return L.first == Nil;
}

bool list_empty_anak(listanak L) {
	return L.first == Nil;
}

void create_list(listinduk &L) {
	L.first = Nil;
	L.last = Nil;
}

void create_list_anak(listanak &L) {
	L.first = Nil;
	L.last = Nil;
}

address alokasi(infotypeinduk P) {
	address Q = new elemen_list_induk;
	Q->info = P;
	create_list_anak(Q->lanak);
	Q->next = Nil;
	Q->prev = Nil;
	return Q;
}

address_anak alokasi_anak(infotypeanak P) {
	address_anak Q = new elemen_list_anak;
	Q->info = P;
	Q->next = Nil;
	Q->prev = Nil;
	return Q;
}

void dealokasi(address P) {
	delete P;
}

void dealokasi_anak(address_anak P) {
	delete P;
}

address find_elm(listinduk L, infotypeinduk X) {
	address P = L.first;
	while (P != Nil && P->info != X) {
		P = P->next;
	}
	return P;
}

address_anak find_elm_anak(listanak L, infotypeanak X) {
	address_anak P = L.first;
	while (P != Nil && P->info != X) {
		P = P->next;
	}
	return P;
}

bool ffind_elm(listinduk L, address P) {
	address Q = L.first;
	while (Q != Nil) {
		if (Q == P) return true;
		Q = Q->next;
	}
	return false;
}

bool ffind_elm_anak(listanak L, address_anak P) {
	address_anak Q = L.first;
	while (Q != Nil) {
		if (Q == P) return true;
		Q = Q->next;
	}
	return false;
}

address find_before(listinduk L, address P) {
	if (L.first == P) return Nil;
	address Q = L.first;
	while (Q != Nil && Q->next != P) {
		Q = Q->next;
	}
	return Q;
}

address_anak find_before_anak(listanak L, infotypeanak X, address_anak P) {
	if (L.first == P) return Nil;
	address_anak Q = L.first;
	while (Q != Nil && Q->next != P) {
		Q = Q->next;
	}
	return Q;
}

void insert_first(listinduk &L, address P) {
	if (list_empty(L)) {
		L.first = P;
		L.last = P;
	} else {
		P->next = L.first;
		L.first->prev = P;
		L.first = P;
	}
}

void insert_after(listinduk &L, address P, address Prec) {
	P->next = Prec->next;
	P->prev = Prec;
	if (Prec->next != Nil) Prec->next->prev = P;
	Prec->next = P;
	if (L.last == Prec) L.last = P;
}

void insert_last(listinduk &L, address P) {
	if (list_empty(L)) {
		insert_first(L, P);
	} else {
		P->prev = L.last;
		L.last->next = P;
		L.last = P;
	}
}

void insert_first_anak(listanak &L, address_anak P) {
	if (list_empty_anak(L)) {
		L.first = P;
		L.last = P;
	} else {
		P->next = L.first;
		L.first->prev = P;
		L.first = P;
	}
}

void insert_after_anak(listanak &L, address_anak P, address_anak Prec) {
	P->next = Prec->next;
	P->prev = Prec;
	if (Prec->next != Nil) Prec->next->prev = P;
	Prec->next = P;
	if (L.last == Prec) L.last = P;
}

void insert_last_anak(listanak &L, address_anak P) {
	if (list_empty_anak(L)) {
		insert_first_anak(L, P);
	} else {
		P->prev = L.last;
		L.last->next = P;
		L.last = P;
	}
}

void del_first(listinduk &L, address &P) {
	P = L.first;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.first = P->next;
		L.first->prev = Nil;
	}
}

void del_last(listinduk &L, address &P) {
	P = L.last;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.last = P->prev;
		L.last->next = Nil;
	}
}

void del_after(listinduk &L, address &P, address Prec) {
	P = Prec->next;
	Prec->next = P->next;
	if (P->next != Nil) P->next->prev = Prec;
	if (L.last == P) L.last = Prec;
}

void delp(listinduk &L, infotypeinduk X) {
	address P = find_elm(L, X);
	if (P != Nil) {
		if (P == L.first) {
			del_first(L, P);
			dealokasi(P);
		} else if (P == L.last) {
			del_last(L, P);
			dealokasi(P);
		} else {
			address Q;
			del_after(L, Q, P->prev);
			dealokasi(Q);
		}
	}
}

void del_first_anak(listanak &L, address_anak &P) {
	P = L.first;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.first = P->next;
		L.first->prev = Nil;
	}
}

void del_last_anak(listanak &L, address_anak &P) {
	P = L.last;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.last = P->prev;
		L.last->next = Nil;
	}
}

void del_after_anak(listanak &L, address_anak &P, address_anak Prec) {
	P = Prec->next;
	Prec->next = P->next;
	if (P->next != Nil) P->next->prev = Prec;
	if (L.last == P) L.last = Prec;
}

void delp_anak(listanak &L, infotypeanak X) {
	address_anak P = find_elm_anak(L, X);
	if (P != Nil) {
		if (P == L.first) {
			del_first_anak(L, P);
			dealokasi_anak(P);
		} else if (P == L.last) {
			del_last_anak(L, P);
			dealokasi_anak(P);
		} else {
			address_anak Q;
			del_after_anak(L, Q, P->prev);
			dealokasi_anak(Q);
		}
	}
}

void print_info_anak(listanak L) {
	address_anak P = L.first;
	while (P != Nil) {
		cout << " -> " << P->info;
		P = P->next;
	}
}

void print_info(listinduk L) {
	address P = L.first;
	while (P != Nil) {
		cout << P->info;
		print_info_anak(P->lanak);
		cout << endl;
		P = P->next;
	}
}

int nb_list(listinduk L) {
	int c = 0;
	address P = L.first;
	while (P != Nil) {
		c++;
		P = P->next;
	}
	return c;
}

int nb_list_anak(listanak L) {
	int c = 0;
	address_anak P = L.first;
	while (P != Nil) {
		c++;
		P = P->next;
	}
	return c;
}

void del_all(listinduk &L) {
	address P;
	while (L.first != Nil) {
		del_first(L, P);
		dealokasi(P);
	}
}
```
`main.cpp`
```C++
#include <iostream>
#include "multilist.h"
using namespace std;

int main() {
	listinduk L;
	create_list(L);

	insert_last(L, alokasi(1));
	insert_last(L, alokasi(2));

	cout << "list induk:" << endl;
	print_info(L);
	cout << endl;

	address P = find_elm(L, 1);
	insert_last_anak(P->lanak, alokasi_anak(10));
	insert_last_anak(P->lanak, alokasi_anak(20));

	P = find_elm(L, 2);
	insert_last_anak(P->lanak, alokasi_anak(30));

	cout << "list multilist:" << endl;
	print_info(L);

	return 0;
}
```
#### Output:
<img width="1216" height="442" alt="image" src="https://github.com/user-attachments/assets/4e6f4618-346e-45cb-b4fc-d2d31dd61111" />

Program tersebut merupakan implementasi dari struktur data **Multi Linked List** (Daftar Bertaut Majemuk) yang menggunakan relasi satu-ke-banyak antara entitas induk dan entitas anak. Secara struktural, program ini terbagi menjadi tiga file modular, dimulai dengan **`multilist.h`** yang berfungsi sebagai *header* untuk mendefinisikan struktur `elemen_list_induk` dan `elemen_list_anak`, serta mendeklarasikan prototipe berbagai fungsi manajemen list seperti alokasi, pencarian, penyisipan, dan penghapusan. Logika operasional dari seluruh fungsi tersebut diimplementasikan secara mendalam di dalam file **`multilist.cpp`**, yang mengatur bagaimana simpul induk terhubung secara *double linked list* (memiliki penunjuk `next` dan `prev`) dan bagaimana setiap simpul induk memiliki daftar anak tersendiri yang juga dikelola dengan mekanisme serupa. Terakhir, file **`main.cpp`** berperan sebagai program utama yang mengintegrasikan kedua file sebelumnya untuk mensimulasikan pembuatan daftar induk, pencarian elemen spesifik, serta penyisipan elemen anak ke bawah induk yang sesuai sebelum menampilkan seluruh struktur hierarki tersebut ke layar melalui fungsi `print_info`.
### Ringkasan Peran Setiap File:

* **`multilist.h`**: Mendefinisikan struktur data induk dan anak serta mendeklarasikan kontrak fungsi yang tersedia untuk digunakan oleh modul lain.
* **`multilist.cpp`**: Menyediakan implementasi teknis untuk manipulasi list, termasuk pengecekan kondisi kosong (`list_empty`), alokasi memori dinamis, dan operasi penambahan atau penghapusan elemen.
* **`main.cpp`**: Menjadi titik masuk eksekusi program untuk mempraktikkan penggunaan *multilist* dengan data nyata, seperti menghubungkan "child node 10" dan "20" ke bawah "parent node 1".

#### Full code Screenshot:
##### multilist.h
<img width="1644" height="961" alt="image" src="https://github.com/user-attachments/assets/940ced63-bea2-4035-91a6-43b5f2be1858" />

##### multilist.cpp
<img width="1649" height="1004" alt="image" src="https://github.com/user-attachments/assets/0d8bb5c4-1a95-44cc-a123-56e9114e0f12" />

##### main.cpp
<img width="1064" height="673" alt="image" src="https://github.com/user-attachments/assets/44c0127b-f513-4a80-b554-d19c912aaf84" />

## Kesimpulan
Program ini berhasil mengimplementasikan struktur data *Multi Linked List* dengan relasi **1-to-N (One-to-Many)**, di mana setiap elemen induk (*parent*) dapat memiliki banyak elemen anak (*child*). Implementasi ini menggunakan struktur *Double Linked List* baik pada daftar induk maupun daftar anak, yang ditandai dengan adanya penunjuk `next` dan `prev` pada setiap elemennya.

**Poin-Poin Utama Kesimpulan:**

* **Hierarki Data Terstruktur**: Program memungkinkan pengelompokan data secara hierarkis, di mana setiap `elemen_list_induk` memiliki daftar anak sendiri melalui variabel `lanak` (tipe `listanak`).
* **Manajemen Memori Dinamis**: Program menggunakan alokasi memori dinamis untuk setiap pembuatan elemen baru (`alokasi` dan `alokasi_anak`) dan menyediakan mekanisme `dealokasi` serta `del_all` untuk mencegah kebocoran memori (*memory leak*).
* **Fleksibilitas Operasi**: Tersedia operasi yang lengkap mulai dari penyisipan (`insert_first`, `insert_last`, `insert_after`), penghapusan elemen tertentu (`delp`, `delp_anak`), hingga pencarian elemen berdasarkan nilai informasinya.
* **Visualisasi Hubungan**: Fungsi `print_info` secara efektif menampilkan hubungan antara induk dan anak, memudahkan pengguna melihat data mana yang menjadi bawahan dari induk tertentu.
* **Efisiensi Penelusuran**: Dengan adanya penunjuk `last` pada struktur `listinduk` dan `listanak`, operasi penambahan data di akhir (`insert_last`) dapat dilakukan dengan lebih cepat tanpa harus menelusuri seluruh list dari awal.

## Daftar Pustaka
- FIKTI UMSU. (2023, 24 Juli). *Pengertian Linked List: Struktur Data dalam Pemrograman*. https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/[2]
- Firman Informatika. (2014). *Multiple Linked List (Multi List)_Struktur Data*. http://firmaninformatika.blogspot.com/2014/11/referensi-multiple-linked-list-multi.html[4]
- Suci Antinovi. (2014). *STRUKTUR DATA - Linked List*. http://suciantinovi.blogspot.com/2014/03/linked-list-i_14.html[5]
- Slideshare. (2018). *8. Multi List (Struktur Data)*. https://www.slideshare.net/slideshow/8-multi-list-struktur-data/114941552[7]

[1](https://dosen.upi-yai.ac.id/v5/dokumen/materi/011061/73_20230527020432_Pert%2008%20-%20Linked%20List.pdf)
[2](https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/)
[3](https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html)
[4](http://firmaninformatika.blogspot.com/2014/11/referensi-multiple-linked-list-multi.html)
[5](http://suciantinovi.blogspot.com/2014/03/linked-list-i_14.html)
[6](https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F86227%2Fmod_resource%2Fcontent%2F1%2FModul+Struktur+Data-Linked+List.pdf)
[7](https://www.slideshare.net/slideshow/8-multi-list-struktur-data/114941552)
[8](https://id.scribd.com/presentation/435994107/Linked-List)
[9](https://www.scribd.com/document/733120041/Detail-Multi-Linked-List-1-N)
[10](https://www.slideshare.net/slideshow/detail-multi-linked-list-1-n__detail-multi-linked-list-1-n-pdf/272933944)
