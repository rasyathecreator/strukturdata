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