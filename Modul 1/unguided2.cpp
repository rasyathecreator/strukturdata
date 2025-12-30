#include <iostream>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                   "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
                    "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
                    "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

string terbilang(int n) {
    if (n == 0) return "nol";
    else if (n < 10) return satuan[n];
    else if (n < 20) return belasan[n - 10];
    else if (n < 100) return puluhan[n / 10] + (n % 10 != 0 ? " " + satuan[n % 10] : "");
    else if (n == 100) return "seratus";
    return "";
}

int main() {
    int angka;
    cout << "masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "input harus antara 0 sampai 100." << endl;
    } else {
        cout << angka << " : " << terbilang(angka) << endl;
    }

    return 0;
}