#include <iostream>// Header untuk input-output standar
#include <stack> // Header untuk struktur data stack
#include <string> // Header untuk struktur data string
using namespace std;

// Fungsi untuk membalikkan kata dengan menggunakan stack
string Katadiblaik_158(string kalimat_158) {
    stack<char> s; // Membuat objek stack dengan tipe data char
    string hasil_158; // String untuk menyimpan hasil akhir (kata terbalik)

    // Memasukkan setiap karakter ke dalam stack
    for (char c : kalimat_158) { // Looping untuk setiap karakter dalam kalimat
        s.push(c); // Menambahkan karakter ke dalam stack
    }

    // Mengambil karakter dari stack untuk membentuk kata terbalik
    while (!s.empty()) { // Looping sampai stack kosong
        hasil_158 += s.top(); // Menambahkan karakter teratas stack ke hasil
        s.pop(); // Menghapus karakter teratas dari stack
    }

    return hasil_158; // Mengembalikan kata terbalik
}

// Fungsi main
int main() {

    string kalimat;
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat); // Mengambil input kalimat dari pengguna

    // Membagi kalimat menjadi kata-kata
    string kata_158;
    string hasil; // String untuk menyimpan hasil akhir (kalimat dengan kata terbalik)
    for (char c : kalimat) { // Looping untuk setiap karakter dalam kalimat
        if (c == ' ') { // Jika karakter adalah spasi, maka itu menandakan akhir kata
            // Memasukkan kata yang telah dibalikkan
            hasil += Katadiblaik_158(kata_158) + " "; // Menambahkan kata terbalik ke hasil dengan spasi diakhirnya
            kata_158 = ""; // Reset kata untuk kata berikutnya
        } else {
            kata_158 += c; // Menambahkan karakter ke kata
        }
    }

    // Memasukkan kata terakhir
    hasil += Katadiblaik_158(kata_158); // Menambahkan kata terakhir yang sudah dibalik

    cout << "Data stack Array :\n";
    cout << "Data : " << hasil << endl; // Menampilkan hasil akhir

    return 0; // Mengembalikan nilai 0
}
