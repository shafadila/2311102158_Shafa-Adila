#include <iostream>
using namespace std;

int main() {
    // Data yang diberikan
    int data_158[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Array integer yang berisi data
    int size = sizeof(data_158) / sizeof(data_158[0]); // Menghitung jumlah elemen dalam array
    int angka = 4;  // Angka yang akan dihitung
    int count = 0; // Variabel untuk menyimpan jumlah kemunculan angka 4

    // Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < size; ++i) { // Looping melalui setiap elemen dalam array
        if (data_158[i] == angka) { // Jika elemen saat ini sama dengan angka yang dicari
            ++count; // Tambahkan jumlah kemunculan angka
        }
    }

    // Menampilkan hasil
    cout<<"\tProgram Sequential Search Sederhana\n"<<endl; // Pesan judul program
    cout << "Jumlah angka " << angka << " dalam data: " << count << endl; // Menampilkan jumlah kemunculan angka

    return 0;
}
