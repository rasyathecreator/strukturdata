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

