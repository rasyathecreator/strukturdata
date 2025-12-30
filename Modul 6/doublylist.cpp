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