#include <iostream>
#include <iomanip>

using namespace std;

void tampilkanMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(5) << matriks[i][j];
        }
        cout << endl;
    }
}

int main() {
    int matriksA[3][3];
    int matriksB[3][3];
    int hasil[3][3];

    cout << "--- Masukkan Elemen Matriks A (3x3) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Masukkan elemen baris " << i + 1 << " kolom " << j + 1 << ": ";
            cin >> matriksA[i][j];
        }
    }

    cout << "\n--- Masukkan Elemen Matriks B (3x3) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Masukkan elemen baris " << i + 1 << " kolom " << j + 1 << ": ";
            cin >> matriksB[i][j];
        }
    }

    cout << "\nMatriks A:" << endl;
    tampilkanMatriks(matriksA);
    cout << "\nMatriks B:" << endl;
    tampilkanMatriks(matriksB);

    cout << "\n--- Hasil Penjumlahan (A + B) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
    tampilkanMatriks(hasil);

    cout << "\n--- Hasil Pengurangan (A - B) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
    tampilkanMatriks(hasil);

    cout << "\n--- Hasil Perkalian (A * B) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
    tampilkanMatriks(hasil);

    return 0;
}