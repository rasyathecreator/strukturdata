# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Rasya Syahri Ramadhan</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 


```C++
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
```
#### Output:
<img width="463" height="903" alt="image" src="https://github.com/user-attachments/assets/2925a35b-8bcf-448c-9530-3ec9d5ccb82a" />



Program di atas adalah program C++ yang melakukan operasi dasar pada dua buah matriks berukuran 3x3, yaitu penjumlahan, pengurangan, dan perkalian. Program menggunakan library <iostream> untuk input-output dan <iomanip> untuk memformat tampilan agar hasil matriks terlihat rapi. Pengguna diminta untuk memasukkan elemen-elemen dari Matriks A dan Matriks B, kemudian program menampilkan kedua matriks tersebut. Setelah itu, program menghitung dan menampilkan hasil dari operasi A + B, A - B, dan A × B dengan menggunakan perulangan bersarang. Fungsi tampilkanMatriks() digunakan untuk menampilkan setiap matriks dengan jarak kolom yang seragam menggunakan manipulasi setw().

#### Full code Screenshot:
<img width="813" height="980" alt="image" src="https://github.com/user-attachments/assets/e7356c36-01cc-4c68-9471-a61deb5bd8ea" />




### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel


```C++
#include <iostream>
#include <iomanip>

using namespace std;

void tukar_pointer(int *p_x, int *p_y, int *p_z);
void tukar_reference(int &x, int &y, int &z);
void cetak_nilai(const string& kondisi, int a, int b, int c);

void tukar_pointer(int *p_x, int *p_y, int *p_z) {
    int temp; 

    temp = *p_x;
    *p_x = *p_y;
    *p_y = *p_z;
    *p_z = temp;
}

void tukar_reference(int &x, int &y, int &z) {
    int temp; 

    temp = x;
    x = y;
    y = z;
    z = temp;
}

void cetak_nilai(const string& kondisi, int a, int b, int c) {
    cout << "\n[" << kondisi << "]:" << endl;
    cout << "a = " << setw(5) << a << " | Alamat: " << &a << endl;
    cout << "b = " << setw(5) << b << " | Alamat: " << &b << endl;
    cout << "c = " << setw(5) << c << " | Alamat: " << &c << endl;
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    cout << "===CALL BY POINTER ===" << endl;
    cetak_nilai("Awal (a, b, c)", a, b, c);
    tukar_pointer(&a, &b, &c);
    cetak_nilai("Setelah Call by Pointer (a, b, c)", a, b, c);
    cout << "\n" << endl;
    
    a = 100;
    b = 200;
    c = 300;

    cout << "=== DEMO: CALL BY REFERENCE ===" << endl;
    cetak_nilai("Awal (a, b, c)", a, b, c);
    tukar_reference(a, b, c);
    cetak_nilai("Setelah Call by Reference (a, b, c)", a, b, c);
    return 0;
}


```
#### Output:
<img width="471" height="527" alt="image" src="https://github.com/user-attachments/assets/03155e34-324f-4697-8741-99de7ea0588f" />

Program di atas adalah program C++ yang mendemonstrasikan perbedaan antara call by pointer dan call by reference dalam pertukaran nilai tiga variabel. Program menggunakan fungsi tukar_pointer() yang menerima alamat variabel sebagai parameter (int*) dan tukar_reference() yang menggunakan referensi (int&). Kedua fungsi tersebut menukar nilai variabel a, b, dan c secara bergantian dengan menggunakan variabel sementara temp. Fungsi cetak_nilai() digunakan untuk menampilkan nilai dan alamat memori dari setiap variabel dengan format rapi menggunakan setw() dari library <iomanip>. Pada bagian main(), program pertama-tama menukar nilai a, b, dan c menggunakan metode pointer, lalu mengulangi proses dengan metode reference untuk menunjukkan bahwa keduanya dapat mengubah nilai variabel asli di luar fungsi.
#### Full code Screenshot:
<img width="682" height="979" alt="image" src="https://github.com/user-attachments/assets/30cce089-139f-4c4f-8d9a-e714910aebe0" />

### 2. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
'''C++
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata
'''


```C++
#include <iostream>
using namespace std;

// Fungsi mencari nilai minimum
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// Fungsi mencari nilai maksimum
int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

// Prosedur menghitung rata-rata
void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata array adalah: " << rata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;

            case 4:
                hitungRataRata(arrA, n);
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
```
#### Output:
<img width="478" height="928" alt="image" src="https://github.com/user-attachments/assets/b9da5769-a688-451f-aa6a-1945a4f966aa" />

Program di atas adalah program C++ yang menggunakan array untuk menampilkan, mencari, dan menghitung data numerik dengan beberapa pilihan menu. Program menyimpan 10 elemen bilangan dalam array arrA, kemudian menampilkan menu interaktif yang memungkinkan pengguna memilih operasi tertentu. Fungsi cariMaksimum() digunakan untuk mencari nilai terbesar dalam array, sedangkan cariMinimum() mencari nilai terkecil. Prosedur hitungRataRata() menghitung dan menampilkan nilai rata-rata elemen array. Program menggunakan struktur kontrol do-while dan switch untuk menjalankan menu berulang kali hingga pengguna memilih keluar (opsi 5). Dengan demikian, program ini menunjukkan cara dasar penggunaan fungsi, array, dan kontrol alur dalam C++.

#### Full code Screenshot:
<img width="798" height="972" alt="image" src="https://github.com/user-attachments/assets/81ebf6d8-0e9b-4fb8-a70c-2927eef5de0c" />




## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
