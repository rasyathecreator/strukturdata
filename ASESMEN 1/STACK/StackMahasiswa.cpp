#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa &StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa &StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}

void Push(StackMahasiswa &StackMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh!\n";
        return;
    }

    Mahasiswa m;
    cout << "Nama: "; cin >> m.Nama;
    cout << "NIM: "; cin >> m.NIM;
    cout << "Nilai Tugas: "; cin >> m.NilaiTugas;
    cout << "Nilai UTS: "; cin >> m.NilaiUTS;
    cout << "Nilai UAS: "; cin >> m.NilaiUAS;

    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = m;
}

void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!\n";
        return;
    }
    StackMHS.Top--;
}

void Update(StackMahasiswa &StackMHS, int posisi) {
    if (posisi < 0 || posisi > StackMHS.Top) {
        cout << "Posisi tidak valid!\n";
        return;
    }

    cout << "Update data posisi ke-" << posisi << "\n";
    cout << "Nama: "; cin >> StackMHS.dataMahasiswa[posisi].Nama;
    cout << "NIM: "; cin >> StackMHS.dataMahasiswa[posisi].NIM;
    cout << "Nilai Tugas: "; cin >> StackMHS.dataMahasiswa[posisi].NilaiTugas;
    cout << "Nilai UTS: "; cin >> StackMHS.dataMahasiswa[posisi].NilaiUTS;
    cout << "Nilai UAS: "; cin >> StackMHS.dataMahasiswa[posisi].NilaiUAS;
}

void View(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!\n";
        return;
    }

    for (int i = StackMHS.Top; i >= 0; i--) {
        cout << "--- Data Mahasiswa Posisi " << i << " ---\n";
        cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << "\n";
        cout << "NIM: " << StackMHS.dataMahasiswa[i].NIM << "\n";
        cout << "Nilai Tugas: " << StackMHS.dataMahasiswa[i].NilaiTugas << "\n";
        cout << "Nilai UTS: " << StackMHS.dataMahasiswa[i].NilaiUTS << "\n";
        cout << "Nilai UAS: " << StackMHS.dataMahasiswa[i].NilaiUAS << "\n";
    }
}

float HitungNilaiAkhir(Mahasiswa m) {
    return 0.2 * m.NilaiTugas + 0.4 * m.NilaiUTS + 0.4 * m.NilaiUAS;
}

void SearchNilaiAkhir(StackMahasiswa &StackMHS, float min, float max) {
    cout << "Hasil pencarian nilai akhir antara " << min << " - " << max << "\n";
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = HitungNilaiAkhir(StackMHS.dataMahasiswa[i]);
        if (nilaiAkhir >= min && nilaiAkhir <= max) {
            cout << "Ditemukan di posisi " << i << ": " << StackMHS.dataMahasiswa[i].Nama
                 << " (" << nilaiAkhir << ")\n";
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!\n";
        return;
    }

    int posMax = 0;
    float maxNilai = HitungNilaiAkhir(StackMHS.dataMahasiswa[0]);

    for (int i = 1; i <= StackMHS.Top; i++) {
        float nilaiAkhir = HitungNilaiAkhir(StackMHS.dataMahasiswa[i]);
        if (nilaiAkhir > maxNilai) {
            maxNilai = nilaiAkhir;
            posMax = i;
        }
    }

    cout << "Nilai akhir terbesar ada di posisi " << posMax << "\n";
    cout << "Nama: " << StackMHS.dataMahasiswa[posMax].Nama << "\n";
    cout << "NIM: " << StackMHS.dataMahasiswa[posMax].NIM << "\n";
    cout << "Nilai Akhir: " << maxNilai << "\n";
}
