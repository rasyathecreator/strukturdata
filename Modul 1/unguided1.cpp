#include <iostream>
using namespace std;

void readNumbers (float &a, float &b) {
   cout << "Masukkan float number : ";
   cin >> a;
   cout << "Masukkan float number kedua : ";
   cin >> b;
   cout << "Kita punya " << a << " dan " << b << endl;
}

float addition (float a, float b) {
   return a + b;
}

float subtraction (float a, float b) {
   return a - b;
}

float multiplication (float a, float b) {
   return a * b;
}

float division (float a, float b) {
   return a / b;
}

int main() {
   float a, b;
   readNumbers(a, b);

   float add = addition(a, b);
   float sub = subtraction(a, b);
   float mul = multiplication(a, b);
   float div = division(a, b);

   cout << a << " + " << b << " = " << add  << endl;
   cout << a << " - " << b << " = " << sub << endl;
   cout << a << " * " << b << " = " << mul << endl;
   cout << a << " / " << b << " = " << div << endl;

   return 0;
}