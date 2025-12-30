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