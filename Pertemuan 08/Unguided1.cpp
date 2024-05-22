#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Fungsi untuk melakukan binary search pada array karakter
int binarySearch(char arr[], int size, char key) {
    int kiri_158 = 0;
    int kanan_158 = size - 1;

    while (kiri_158 <= kanan_158) {
        int mid = kiri_158 + (kanan_158 - kiri_158) / 2;
        // Jika elemen ditemukan pada tengah
        if (arr[mid] == key)
            return mid;
        // Jika elemen lebih besar, abaikan bagian kiri_158
        if (arr[mid] < key)
            kiri_158 = mid + 1;
        // Jika elemen lebih kecil, abaikan bagian kanan_158
        else
            kanan_158 = mid - 1;
    }

    // Elemen tidak ditemukan
    return -1;
}

int main() {
    string kalimat;
    char cariKarakter;

    cout<<"Program Binary Search Sederhana\n"<<endl;
    // User diminta menginputkan kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // User diminta menginputkan huruf yang akan dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cariKarakter;
    cout << endl;

    // Konversi string ke array karakter dan urutkan
    int n = kalimat.length();
    char arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = kalimat[i];
    }
    sort(arr, arr + n); // Mengurutkan array karakter

    // Mencetak array karakter yang telah diurutkan
    cout << "Kalimat setelah diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << endl;

    // Melakukan binary search pada array karakter
    int index = binarySearch(arr, n, cariKarakter);

    if (index != -1) {
        cout << "Huruf '" << cariKarakter << "' ditemukan dalam kalimat pada indeks ke-" << index << "." << endl;
    } else {
        cout << "Huruf '" << cariKarakter << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
