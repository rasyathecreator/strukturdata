#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    S.Top++; S.dataMahasiswa[S.Top] = {"Venti", "11111", 75.7, 82.1, 65.5};
    S.Top++; S.dataMahasiswa[S.Top] = {"Xiao", "22222", 87.4, 88.9, 81.9};
    S.Top++; S.dataMahasiswa[S.Top] = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    S.Top++; S.dataMahasiswa[S.Top] = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    S.Top++; S.dataMahasiswa[S.Top] = {"Lynette", "55555", 77.7, 65.4, 79.9};
    S.Top++; S.dataMahasiswa[S.Top] = {"Chasca", "66666", 99.9, 93.6, 87.3};

    cout << "=== DATA STACK AWAL ===\n";
    View(S);

    cout << "\n=== POP 1x ===\n";
    Pop(S);

    cout << "=== DATA SETELAH POP ===\n";
    View(S);

    cout << "\n=== UPDATE POSISI KE-3 ===\n";
    S.dataMahasiswa[2] = {"Heizou", "77777", 99.9f, 88.8f, 77.7f};

    cout << "=== DATA SETELAH UPDATE ===\n";
    View(S);

    cout << "\n=== SEARCH NILAI AKHIR 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    cout << "\n=== NILAI AKHIR TERBESAR ===\n";
    MaxNilaiAkhir(S);

    return 0;
}
