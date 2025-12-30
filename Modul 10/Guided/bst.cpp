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