
# <h1 align="center">Laporan Praktikum Modul 1 PENGENALAN CODE BLOCKS</h1>
<p align="center">Rasya Syahri Ramadhan - 103112430189</p>

## Dasar Teori

Code::Blocks merupakan Integrated Development Environment (IDE) gratis dan open-source yang ideal untuk pemrograman C++ dalam mata kuliah struktur data, menyediakan editor, compiler, debugger, dan fitur project management dalam satu antarmuka. IDE ini memudahkan implementasi struktur data seperti linked list atau tree melalui template project dan syntax highlighting.​

Instalasi dan Setup
Unduh Code::Blocks dari situs resmi codeblocks.org, pilih versi dengan compiler MinGW untuk Windows agar siap pakai. Buat project baru via File > New > Project > Console Application, pilih C++ dan compiler GNU GCC, lalu tulis kode di main.cpp dengan include <iostream> dan using namespace std;.
​
Struktur Program Dasar C++
Program C++ dimulai dengan #include <iostream> untuk input/output, diikuti int main() sebagai entry point yang dibatasi kurung kurawal { }. Contoh dasar:


## Guided 

### Guided 1
`guided1.cpp`
```C++
#include <iostream>
using namespace std;

int main(){
    int inp;
    cin >> inp;
    cout << "nilai = " << inp;
    return 0;
}
```
### Screenshot Output
<img width="680" height="287" alt="image" src="https://github.com/user-attachments/assets/4a274220-57ee-453a-b385-9256a958b173" />

Program C++ di atas adalah sebuah kode dasar yang mendemonstrasikan fungsi input dan output standar menggunakan pustaka iostream. Program ini dimulai dengan mendeklarasikan sebuah variabel bertipe data integer bernama inp yang berfungsi sebagai wadah untuk menyimpan bilangan bulat. Proses utama dalam program ini melibatkan instruksi cin untuk menerima input angka dari pengguna melalui keyboard, diikuti oleh instruksi cout untuk menampilkan kembali nilai tersebut ke layar dengan teks pendahulu "nilai = ".

Secara teknis, program ini berjalan secara sekuensial atau berurutan di dalam fungsi main, yang merupakan titik awal eksekusi program. Penggunaan std::cin dan std::cout menunjukkan penerapan objek aliran (stream) yang sangat umum dalam pemrograman C++ untuk interaksi antara pengguna dan mesin. Program kemudian diakhiri dengan pernyataan return 0, yang menandakan bahwa eksekusi telah selesai dengan sukses tanpa adanya kesalahan sistem.

### Full code screenshot
<img width="865" height="275" alt="image" src="https://github.com/user-attachments/assets/5f79ccce-5f82-4c2a-9d83-d39581ece887" />

### Guided 2
`guided2.cpp`
```C++
#include <iostream>
using namespace std;
int main(){
    char ch;
    cout << "masukkan sebuah karakter : ";
    ch = getchar(); // getchar() untuk membaca satu karakter
    cout << "Karakter yang anda masukkan adalah : " << ch <<  endl;
}
```
### Screenshot Output
<img width="688" height="269" alt="image" src="https://github.com/user-attachments/assets/88a24f1d-97de-491d-bcf6-4f78e59ad677" />
Kesimpulan untuk seluruh program yang Anda tanyakan adalah bahwa penggunaan **Linked List** (baik *Single*, *Double*, maupun *Multilist*) memberikan fleksibilitas tinggi dalam manajemen memori dinamis karena memungkinkan penambahan, pembaruan, dan penghapusan data secara efisien tanpa batasan ukuran tetap seperti array statis. Setiap elemen atau `node` berfungsi sebagai unit penyimpanan mandiri yang saling terhubung melalui *pointer*, yang pada implementasi **Queue** (antrean) memastikan alur kerja **FIFO** (*First-In, First-Out*) yang teratur, sementara pada **Multilist** memungkinkan pengorganisasian data yang lebih kompleks dengan hubungan hierarki antara induk dan anak. Secara teknis, keberhasilan program-program ini bergantung pada ketepatan manipulasi alamat memori dan pembersihan data menggunakan operator `delete` untuk mencegah kebocoran memori, menjadikannya solusi struktur data yang sangat adaptif untuk berbagai skenario aplikasi nyata.

### Full code screenshot
<img width="1015" height="384" alt="image" src="https://github.com/user-attachments/assets/1046ae4e-de01-40cd-883d-f83d353aa465" />

### Guided 3
`guided3.cpp`
```C++
#include <iostream>
using namespace std;
int main(){
    char x;
    float y;
    cout<< "ukuran variable char " << sizeof(x) << endl;
    cout<< "ukuran variable float " << sizeof(y) << endl;
    cout<< "ukuran variable int " << sizeof(int) << endl;
    return 0;
}
```
### Screenshot Output
<img width="740" height="310" alt="image" src="https://github.com/user-attachments/assets/a134dc77-3e83-473d-be2e-fe0d591b0dd4" />

Program terakhir tersebut bertujuan untuk mendemonstrasikan konsep penggunaan memori dalam bahasa C++ dengan memanfaatkan operator sizeof() untuk mengukur besaran bita (byte) dari berbagai tipe data. Melalui kode ini, pengguna dapat melihat secara langsung bahwa setiap variabel, baik itu char yang biasanya berukuran 1 bita maupun float yang berukuran 4 bita, membutuhkan alokasi ruang yang berbeda di memori komputer tergantung pada jenis informasinya. Pengetahuan tentang ukuran variabel ini sangat penting dalam optimasi program, karena membantu pengembang dalam memilih tipe data yang paling efisien untuk menyimpan informasi guna menghindari pemborosan sumber daya sistem. Secara teknis, program mengeksekusi perintah pencetakan secara sekuensial dan memberikan pemahaman dasar mengenai bagaimana kompilator menginterpretasikan objek serta tipe data primitif dalam bentuk fisik di memori.

### Full code screenshot
<img width="944" height="394" alt="image" src="https://github.com/user-attachments/assets/4012d3ce-6d9e-43c7-b581-0dbeb45a85d9" />

### Guided 4
`guided4.cpp`
```C++
#include <iostream>
using namespace std;
int main(){
    int r = 10;
    int s;
    s=10 + ++r;
    cout << "Nilai r = " <<r<<endl;
    cout << "Nilai s = " <<s<<endl;
    return 0;
}
```
### Screenshot Output
<img width="766" height="289" alt="image" src="https://github.com/user-attachments/assets/c3e3b156-04c2-480e-a04e-4578b95e49b6" />

Program C++ tersebut mendemonstrasikan konsep operasi pre-increment dalam aritmetika pemrograman, di mana nilai variabel r dinaikkan terlebih dahulu sebelum digunakan dalam perhitungan. Dalam satu paragraf, alur kerjanya dimulai dengan inisialisasi r bernilai 10, lalu pada baris kalkulasi s = 10 + ++r, sistem menambahkan angka satu ke variabel r sehingga nilainya menjadi 11, baru kemudian menjumlahkannya dengan 10 yang menghasilkan nilai 21 untuk variabel s. Hasil akhirnya, melalui perintah cout, program menampilkan nilai terbaru dari kedua variabel tersebut ke layar untuk menunjukkan bagaimana operator ++ di depan variabel secara langsung mengubah isi memori sebelum ekspresi matematika diselesaikan.

### Screenshot Full Program
<img width="829" height="393" alt="image" src="https://github.com/user-attachments/assets/a4e40738-19a3-4a07-8de7-ced8b2498fb4" />




## Unguided 
### Unguided 1
`unguided1.cpp`
```C++
#include <iostream>
using namespace std;

// function to read two float numbers from user input
void readNumbers (float &a, float &b) {
   cout << "Masukkan float number : ";
   cin >> a;
   cout << "Masukkan float number kedua : ";
   cin >> b;
   cout << "Kita punya " << a << " dan " << b << endl;
}

// function to add two numbers
float addition (float a, float b) {
   return a + b;
}

// function to subtract two numbers
float subtraction (float a, float b) {
   return a - b;
}

// function to multiply two numbers
float multiplication (float a, float b) {
   return a * b;
}

// function to divide two numbers
float division (float a, float b) {
   return a / b;
}

int main() {
   // declare two floats
   float a, b;
   // read input values from user
   readNumbers(a, b);

   // perform calculations
   float add = addition(a, b);
   float sub = subtraction(a, b);
   float mul = multiplication(a, b);
   float div = division(a, b);

   // print results
   cout << a << " + " << b << " = " << add  << endl;
   cout << a << " - " << b << " = " << sub << endl;
   cout << a << " * " << b << " = " << mul << endl;
   cout << a << " / " << b << " = " << div << endl;

   return 0;
}
```

#### Screenshot Output
<img width="773" height="392" alt="image" src="https://github.com/user-attachments/assets/e5a62bdb-69e6-4673-85de-47e6a3c814b3" />

Program C++ tersebut merupakan implementasi kalkulator sederhana yang menggunakan modularitas fungsi untuk memisahkan logika input, perhitungan, dan output. Dalam satu paragraf, alur kerjanya dimulai dengan pemanggilan fungsi `readNumbers` yang menggunakan parameter *pass-by-reference* (`&`) untuk mengambil dua angka desimal dari pengguna dan menyimpannya langsung ke variabel di fungsi utama. Selanjutnya, program secara sistematis memproses kedua angka tersebut melalui empat fungsi aritmetika terpisah, yaitu `addition`, `subtraction`, `multiplication`, dan `division`, yang masing-masing mengembalikan hasil operasi penjumlahan, pengurangan, perkalian, dan pembagian. Akhirnya, seluruh hasil kalkulasi tersebut ditampilkan ke layar secara berurutan, menunjukkan bagaimana penggunaan fungsi dapat membuat struktur kode menjadi lebih rapi, terorganisir, dan mudah untuk dikelola.

#### Full code Screenshot:
<img width="1642" height="981" alt="image" src="https://github.com/user-attachments/assets/ab13a0a7-09fc-48e1-b2c5-593477427e61" />


### Unguided 2
`unguided2.cpp`
```C++

```

#### ScreenShot Output
<img width="671" height="261" alt="image" src="https://github.com/user-attachments/assets/34dc21c8-8604-424a-98f4-8409d468fbed" />

Program C++ ini merupakan sebuah aplikasi konversi bilangan yang berfungsi untuk mengubah angka numerik dalam rentang 0 hingga 100 menjadi format teks atau terbilang dalam bahasa Indonesia. Dalam satu paragraf, alur kerjanya dimulai dengan pendefinisian tiga array string sebagai basis data kata untuk satuan, belasan, dan puluhan, yang kemudian diproses melalui fungsi rekursif atau percabangan `terbilang` untuk menentukan kategori angka berdasarkan rentang nilainya. Program menggunakan logika pembagian dan sisa bagi (modulus) untuk memisahkan angka puluhan dan satuan, serta menangani kondisi khusus seperti angka nol, belasan, dan seratus secara spesifik. Di dalam fungsi `main`, sistem akan meminta input dari pengguna, melakukan validasi agar angka berada dalam batas yang ditentukan, dan akhirnya mencetak hasil konversi tersebut ke layar, memberikan kemudahan dalam memahami representasi tekstual dari sebuah bilangan.

#### Full code Screenshot:
<img width="1283" height="795" alt="image" src="https://github.com/user-attachments/assets/ec8a23ab-d81f-45ea-af2a-2eec1c55e880" />


### Unguided 3
`unguided3.cpp`
```C++
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "input : ";
    cin >> n;

    cout << "output:\n\n";
    for (int i = n; i >= 1; i--){
        for (int j = i; j >= 1; j--) cout << j << " ";
        cout << "* ";

        for (int j = 1; j <= i; j++) cout<< j << " ";
        cout << "\n";
    }
    cout << "*" << endl;

    return 0;
}
```

#### Output:
<img width="856" height="516" alt="image" src="https://github.com/user-attachments/assets/a79ecace-cc47-4b10-92a6-58515ddd7875" />

Program C++ tersebut merupakan implementasi dari algoritma perulangan bersarang (nested loop) yang dirancang untuk mencetak sebuah pola angka simetris berbentuk segitiga terbalik dengan karakter bintang sebagai pembatas. Dalam satu paragraf, alur kerja program ini dimulai dengan meminta input bilangan bulat n dari pengguna, yang kemudian digunakan sebagai batas awal perulangan luar untuk menentukan jumlah baris yang akan dicetak. Pada setiap barisnya, program menjalankan tiga tahap pencetakan: pertama, melakukan hitung mundur dari angka baris saat itu hingga satu; kedua, mencetak karakter bintang sebagai pusat simetri; dan ketiga, melakukan hitung maju dari angka satu kembali ke angka baris tersebut. Proses ini berulang dengan jumlah angka yang semakin berkurang di setiap baris bawahnya hingga diakhiri dengan pencetakan satu buah bintang di bagian paling bawah, sehingga menciptakan visualisasi pola angka yang mengecil secara teratur dan simetris secara horizontal.

#### Full code Screenshot:
<img width="856" height="516" alt="image" src="https://github.com/user-attachments/assets/05bf3565-5608-4792-99f0-da581ff1c285" />

## Daftar Pustaka
Slideshare. (2014, 21 Oktober). Algoritma dan Struktur Data - Pengenalan Bahasa C++. 
https://www.slideshare.net/slideshow/algoritma-dan-struktur-data-pengenalan-bahasa-c-40580224/40580224
​

Dicoding. (2024, 18 April). Memahami Esensi Bahasa Pemrograman C++. 
https://www.dicoding.com/blog/memahami-esensi-bahasa-pemrograman-c/
​

Scribd. (2025). JOBSHEET 3 Code Blocks Pengenalan. 
https://id.scribd.com/document/544506424/JOBSHEET-3-Code-Blocks-Pengenalan
​

Slideshare. (2018). Pertemuan 1 Pengenalan Code Blocks. 
https://www.slideshare.net/slideshow/pertemuan-1-pengenalan-code-blocks/90146159

