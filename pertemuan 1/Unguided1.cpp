#include <iostream>
using namespace std;

// Fungsi integer untuk menjumlahkan dua bilangan bulat
int penjumlahan_shafa158(int angka1_shafa158, int angka2_shafa158) {
    return angka1_shafa158 + angka2_shafa158;
}

// Fungsi float untuk menghitung luas lingkaran dengan pi yang merupakan bilangan desimal
float LuasLingkaran_shafa158(float Jarijari_shafa158) {
    const float pi = 3.14; // Nilai pi
    return pi * Jarijari_shafa158 * Jarijari_shafa158; // Rumus luas lingkaran
}

int main() {
    // Deklarasi dan inisialisasi variabel
    int angka1 = 8, angka2 = 4;
    float jarijari = 10;

    //output nama, nim, dan kelas 
    cout << "Nama  : Shafa Adila Santoso" << endl;
    cout << "NIM   : 2311102158" << endl;
    cout << "Kelas : IF-11-D" << endl;
    cout << endl;

    // Memanggil fungsi tambah dan menampilkan output hasil penjumlahan
    cout << "Hasil penjumlahan: " << penjumlahan_shafa158(angka1, angka2) << endl;

    // Memanggil fungsi LuasLingkaran dan menampilkan output hasil luas lingkaran
    cout << "Luas lingkaran adalah: " << LuasLingkaran_shafa158(jarijari) << endl;
    return 0;
}
