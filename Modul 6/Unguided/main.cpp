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