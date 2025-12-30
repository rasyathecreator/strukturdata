# <h1 align="center">Laporan Praktikum Modul 10 TREE</h1>
<p align="center">Rasya Syahri Ramadhan - 103112430189</p>

## Dasar Teori

Tree merupakan struktur data hierarkis nnon-linier yang terdiri dari kumpulan node yang terhubung melalui edge, dengan satu node khusus bernama root sebagai titik awal. Setiap node dapat memiliki zero atau lebih child node, membentuk subtree, dan tidak ada siklus (acyclic).[1][2][3][4]

### Definisi
Tree merepresentasikan hubungan parent-child dalam hierarki, di mana leaf adalah node tanpa child, sedangkan path menghubungkan node melalui edge. Height tree diukur dari root ke leaf terdalam, dan depth node dari root ke node tersebut.[2][3][1]

### Komponen Utama
- **Root**: Node paling atas tanpa parent.[4][1]
- **Node/Vertex**: Elemen penyimpan data dengan pointer ke child.[3]
- **Edge**: Hubungan antar node.[4]
- **Leaf**: Node terminal tanpa child.[2]

## Jenis Tree
- **General Tree**: Node boleh punya banyak child tanpa batas.[3][4]
- **Binary Tree**: Maksimal dua child per node (left, right).[1][2]
- **Binary Search Tree (BST)**: Left child < parent < right child untuk pencarian efisien.[2][3]
- **Balanced Tree**: Keseimbangan height subtree (AVL, Red-Black).[3]

## Operasi Dasar
- **Traversal**: Preorder (root-left-right), Inorder (left-root-right), Postorder (left-right-root), Level Order (BFS).[1][2]
- **Insertion/Deletion**: Menambah/menghapus node sambil jaga properti tree.[3]
- **Search**: Efisien pada BST dengan O(log n) rata-rata.[2]

## Kelebihan dan Kekurangan
Tree efisien untuk hierarki data seperti file system atau database index, dengan akses cepat O(log n) pada balanced tree, tetapi rentan tidak seimbang jika insertion acak. Aplikasi termasuk HTML DOM, decision tree, dan file directory.[4][1][2][3]



## Guided 

### Program Push, Pop, serta Menampilkan Isi Stack
#### bstguided.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
   int data;
   Node *kiri, *kanan;
};

// bikin node baru
Node *membuat_node(int data) {
   Node *node_baru = new Node();
   node_baru->data = data;  
   // karena masih baru, jadi belum punya anak
   node_baru->kiri = node_baru->kanan = NULL;
   return node_baru;
}

// masukin data ke pohon
Node *insert(Node *root, int nilai) {
   // kalo masih kosong, langsung bikin node, belum mikirin kiri kanan
   if (root == NULL) {
      return membuat_node(nilai);
   }
   // kalo udah ada isinya, bandingin nilainya kiri kanan
   // kalo nilainya lebih kecil dari nilai yang di atasnya, berarti masuk ke kiri
   if (nilai < root->data) {
      // rekursif ke kiri
      root->kiri = insert(root->kiri, nilai);
   }
   // kalo lebih besar, berarti masuk ke kanan
   else if (nilai > root->data) {
      // rekursif ke kanan
      root->kanan = insert(root->kanan, nilai);
   }

   return root;
}

// nyari nilai
Node *search(Node *root, int nilai) {
   if (root == NULL || root->data == nilai) {
      return root;
   }
   // lanjut ke subtree kiri
   if (nilai < root->data) {
      return search(root->kiri, nilai);
   }
   // lanjut ke subtree kanan
   return search(root->kanan, nilai);
}

Node *nilai_terkecil(Node *root) {
   Node *sekarang = root;
   while (sekarang && sekarang->kiri != NULL) {
      // geser terus ke kiri buat nyari nilai paling kecil
      sekarang = sekarang->kiri;
   }
   return sekarang;
}

Node *hapus(Node *root, int nilai) {
   if (root == NULL) {
      return root;
   }
   if (nilai < root->data) {
      // hapus dari subtree kiri
      root->kiri = hapus(root->kiri, nilai);
   } else if (nilai > root->data) {
      // hapus dari subtree kanan
      root->kanan = hapus(root->kanan, nilai);
   } else {
      // kasus node dengan hanya 1 anak atau tidak punya anak
      if (root->kiri == NULL) {
         Node *sementara = root->kanan;
         delete root;
         return sementara;
      }
      else if (root->kanan == NULL) {
         Node *sementara = root->kiri;
         delete root;
         return sementara;
      }
      // kasus dua anak: cari nilai terkecil di subtree kanan
      Node *sementara = nilai_terkecil(root->kanan);
      root->data = sementara->data;
      root->kanan = hapus(root->kanan, sementara->data);
   }
   return root;
}

// ubah data
Node *update(Node *root, int lama, int baru) {
   if (search(root, lama) != NULL) {
      // hapus data lama
      root = hapus(root, lama);
      // masukin data baru
      root = insert(root, baru);
      cout << "data " << lama << " diganti jadi " << baru << endl;
   }
   else {
      cout << "data " << lama << " ngga ketemu" << endl;
   }
   return root;
}

// menampilkan data dengan cara traversal
// traversal tuh maksudnya ngecek semua node di pohon satu per satu
void pre_order(Node *root) {
   if (root != NULL) {
      cout << root->data << " ";   // tampilkan node saat masuk
      pre_order(root->kiri);       // lanjut kiri dulu
      pre_order(root->kanan);      // terakhir kanan
   }
}

void in_order(Node *root) {
   if (root != NULL) {
      in_order(root->kiri);        // cek kiri dulu
      cout << root->data << " ";   // tampilkan data setelah kiri selesai
      in_order(root->kanan);       // lanjut kanan
   }
}

void post_order(Node *root) {
   if (root != NULL) {
      post_order(root->kiri);      // proses kiri dulu
      post_order(root->kanan);     // lalu kanan
      cout << root->data << " ";   // tampilkan data paling terakhir
   }
}

int main() {
   Node *root = NULL;

   cout << "=== 1. insert data ===" << endl;
   root = insert(root, 10);
   insert(root, 5);
   insert(root, 20);
   insert(root, 3);
   insert(root, 7);
   insert(root, 15);
   insert(root, 25);
   cout << "data berhasil dimasukkan!" << endl;

   cout << "\n=== 2. traversal tree ===" << endl;
   cout << "pre-order : ";
   pre_order(root);
   cout << endl;
   cout << "in-order  : ";
   in_order(root);
   cout << endl;
   cout << "post-order: ";
   post_order(root);
   cout << endl;

   cout << "\n=== 3. search data ===" << endl;
   int cari1 = 7, cari2 = 99;
   cout << "mencari " << cari1 << ": " << (search(root, cari1) ? "ketemu" : "ngga ketemu") << endl;
   cout << "mencari " << cari2 << ": " << (search(root, cari2) ? "ketemu" : "ngga ketemu") << endl;
   cout << endl;

   cout << "=== 4. update data ===" << endl;
   root = update(root, 5, 8);
   cout << "in-order setelah update: ";
   in_order(root);
   cout << endl;

   cout << "pre-order : ";
   pre_order(root);
   cout << endl;
   cout << "in-order  : ";
   in_order(root);
   cout << endl;
   cout << "post-order: ";
   post_order(root);
   cout << endl;

   cout << "\n=== 5. delete data ===" << endl;
   cout << "menghapus 20" << endl;
   root = hapus(root, 20);

   cout << "pre-order : ";
   pre_order(root);
   cout << endl;
   cout << "in-order  : ";
   in_order(root);
   cout << endl;
   cout << "post-order: ";
   post_order(root);
   cout << endl;
   return 0;
}
```
### Screenshot Output
<img width="919" height="585" alt="image" src="https://github.com/user-attachments/assets/5d18b9a4-cce3-42a3-98d2-896e27685c07" />

Program di atas merupakan implementasi struktur data **Binary Search Tree (BST)** atau Pohon Pencarian Biner menggunakan bahasa pemrograman C++ yang dirancang untuk mengelola data secara hierarkis. Program ini mendefinisikan sebuah objek `Node` yang memiliki komponen data serta penunjuk (*pointer*) ke anak kiri dan anak kanan, di mana setiap penambahan data baru selalu mengikuti aturan utama BST, yakni nilai yang lebih kecil dari induk akan ditempatkan di sebelah kiri dan nilai yang lebih besar di sebelah kanan. Fitur utama yang ditawarkan mencakup operasi manipulasi data yang lengkap, mulai dari penyisipan simpul secara rekursif, pencarian nilai spesifik, hingga penghapusan simpul dengan penanganan kasus yang kompleks (seperti menghapus simpul dengan dua anak dengan mencari nilai terkecil di sub-pohon kanan). Selain itu, program ini menyediakan mekanisme pembaruan data yang unik dengan cara menghapus nilai lama dan memasukkan nilai baru guna menjaga integritas struktur pohon. Untuk keperluan visualisasi dan verifikasi, program mengimplementasikan tiga metode penelusuran (*traversal*), yaitu *Pre-order*, *In-order* (yang menghasilkan urutan data terurut), dan *Post-order*, yang dijalankan melalui fungsi `main` untuk mendemonstrasikan seluruh siklus hidup pengelolaan data dalam pohon tersebut.

---

### Komponen Utama Program:

* **Struktur Node**: Menggunakan *struct* untuk menyimpan `data` dan alamat memori simpul anak.
* **Logika Rekursif**: Sebagian besar fungsi seperti `insert`, `search`, dan `hapus` menggunakan teknik rekursi untuk menavigasi cabang-cabang pohon.
* **Efisiensi Pencarian**: Karena mengikuti aturan BST, proses pencarian data menjadi lebih cepat karena program dapat mengabaikan setengah bagian pohon di setiap langkahnya.
* **Metode Traversal**: Memberikan perspektif berbeda dalam membaca isi pohon, baik dari akar ke daun maupun sebaliknya.

Apakah Anda ingin saya membantu menjelaskan lebih detail mengenai bagaimana proses penghapusan simpul yang memiliki dua anak bekerja dalam logika program tersebut?
### Full code screenshot
<img width="1860" height="972" alt="image" src="https://github.com/user-attachments/assets/1d741356-97ed-4208-8bff-0757e49827f9" />




## Unguided 
### Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”. Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
#### bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct node {
	infotype info;
	node *left, *right;
};

typedef node* address;

#define nil NULL

address alokasi(infotype x);
void insertnode(address &root, infotype x);
address findnode(infotype x, address root);
void inorder(address root);
void preorder(address root);
void postorder(address root);
int hitungjumlahnode(address root);
int hitungtotalinfo(address root);
int hitungkedalaman(address root, int start);

#endif
```
#### bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
	address p = new node;
	p->info = x;
	p->left = nil;
	p->right = nil;
	return p;
}

void insertnode(address &root, infotype x) {
	if (root == nil) {
		root = alokasi(x);
	}
	else if (x < root->info) {
		insertnode(root->left, x);
	}
	else if (x > root->info) {
		insertnode(root->right, x);
	}
}

address findnode(infotype x, address root) {
	if (root == nil || root->info == x) {
		return root;
	}
	if (x < root->info) {
		return findnode(x, root->left);
	}
	return findnode(x, root->right);
}

void inorder(address root) {
	if (root != nil) {
		inorder(root->left);
		cout << root->info << " -> ";
		inorder(root->right);
	}
}

int hitungjumlahnode(address root) {
	if (root == nil) {
		return 0;
	}
	return 1 + hitungjumlahnode(root->left) + hitungjumlahnode(root->right);
}

int hitungtotalinfo(address root) {
	if (root == nil) {
		return 0;
	}
	return root->info + hitungtotalinfo(root->left) + hitungtotalinfo(root->right);
}

int hitungkedalaman(address root, int start) {
	if (root == nil) {
		return start;
	}
	int kiri = hitungkedalaman(root->left, start + 1);
	int kanan = hitungkedalaman(root->right, start + 1);
	return (kiri > kanan ? kiri : kanan);
}

void preorder(address root) {
	if (root != nil) {
		cout << root->info << " -> ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(address root) {
	if (root != nil) {
		postorder(root->left);
		postorder(root->right);
		cout << root->info << " -> ";
	}
}
```
#### main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
	cout << "=== TREE ===" << endl;
	address root = nil;
	insertnode(root,1);
	insertnode(root,2);
	insertnode(root,6);
	insertnode(root,4);
	insertnode(root,5);
	insertnode(root,3);
	insertnode(root,6);
	insertnode(root,7);
	cout << "inorder    : ";
	inorder(root);
	cout << endl;
	cout << "preorder   : ";
	preorder(root);
	cout << endl;
	cout << "postorder  : ";
	postorder(root);
	cout << endl;
	cout << "kedalaman      : " << hitungkedalaman(root,0) << endl;
	cout << "jumlah node    : " << hitungjumlahnode(root) << endl;
	cout << "total          : " << hitungtotalinfo(root) << endl;
	return 0;
}
```
#### Output:
<img width="944" height="249" alt="image" src="https://github.com/user-attachments/assets/baa42e3c-46e1-44ce-bf6a-ad4c3a72a7dc" />

Program ini terdiri dari tiga file yang bekerja secara modular untuk mengimplementasikan struktur data Binary Search Tree (BST) atau Pohon Biner Pencarian. Komponen pertama adalah file bstree.h yang berfungsi sebagai header untuk mendefinisikan struktur data node (terdiri dari elemen info, serta penunjuk left dan right) dan mendeklarasikan berbagai prototipe fungsi untuk manipulasi pohon. Implementasi mendalam dari logika program tersebut berada di dalam file bstree.cpp, yang mencakup fungsi alokasi memori, penyisipan simpul secara rekursif berdasarkan aturan BST (nilai lebih kecil ke kiri, lebih besar ke kanan), pencarian simpul, hingga metode penelusuran pohon seperti inorder, preorder, dan postorder. Selain itu, file ini juga memuat fungsi perhitungan statistik pohon seperti kedalaman maksimum, jumlah total node, dan akumulasi nilai seluruh info. Terakhir, file main.cpp berperan sebagai program utama yang menguji seluruh fungsionalitas tersebut dengan menyusun sebuah pohon dari sekumpulan angka, lalu menampilkan hasil penelusuran dan statistik pohon tersebut ke layar secara terstruktur.

#### Full code Screenshot:
##### bstree.h
<img width="969" height="700" alt="image" src="https://github.com/user-attachments/assets/29cd1ff2-61e9-4ce2-98d1-a0503ef69145" />

##### bstree.cpp
<img width="1644" height="969" alt="image" src="https://github.com/user-attachments/assets/a947efc2-cc58-43b5-bca1-b6f1b9d6a1c6" />

##### main.cpp
<img width="1182" height="765" alt="image" src="https://github.com/user-attachments/assets/82de0ac2-6f89-44f6-aa59-ea8bcd4a274a" />

## Kesimpulan
Program ini berhasil mengimplementasikan struktur data pohon biner pencarian yang memungkinkan penyimpanan data secara hierarkis dengan aturan penempatan yang terstruktur. Melalui pemisahan kode secara modular, program ini menunjukkan manajemen memori yang dinamis melalui fungsi alokasi dan pemanfaatan teknik rekursi yang efisien untuk mengelola data.

**Poin-Poin Utama Kesimpulan:**

* **Aturan Penempatan Data**: Program secara otomatis mengatur posisi data berdasarkan nilainya; nilai yang lebih kecil dari *root* akan diletakkan di sub-pohon kiri, sementara nilai yang lebih besar diletakkan di sub-pohon kanan.
* **Metode Penelusuran (Traversal)**: Program menyediakan tiga metode pembacaan data, yaitu *Preorder*, *Inorder*, dan *Postorder*, yang memberikan fleksibilitas dalam mengakses informasi sesuai kebutuhan urutan.
* **Analisis Statistik Pohon**: Terdapat fungsi khusus untuk menghitung metrik penting seperti kedalaman (*depth*), jumlah total simpul (*node*), dan akumulasi nilai data, yang sangat berguna untuk memantau keseimbangan dan statistik pohon.
* **Struktur Modular**: Penggunaan file `.h` untuk definisi dan `.cpp` untuk logika memisahkan abstraksi data dari implementasinya, sehingga memudahkan dalam pengembangan dan pemeliharaan kode.

## Daftar Pustaka
- BDS Telkom University. (2025, 29 Juni). *Struktur Data Tree: Konsep, Jenis, dan Aplikasinya*. https://bds.telkomuniversity.ac.id/struktur-data-tree-konsep-jenis-dan-aplikasinya/[1]
- BSE Telkom University. (2025, 24 Juni). *Struktur Data Tree: Jenis, Fungsi, dan Contoh Aplikasinya*. https://bse.telkomuniversity.ac.id/tree-data-structure/[2]
- FIKTI UMSU. (2023, 31 Agustus). *Struktur Data Tree*. https://fikti.umsu.ac.id/struktur-data-tree/[3]
- Trivusi. (2022, Juli). *Struktur Data Tree: Pengertian, Jenis, dan Kegunaannya*. https://www.trivusi.web.id/2022/07/struktur-data-tree.html[4]



