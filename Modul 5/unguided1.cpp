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