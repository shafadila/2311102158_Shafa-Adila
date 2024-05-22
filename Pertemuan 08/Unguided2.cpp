#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool isVowel(char ch) {
    ch = tolower(ch); // Mengubah karakter menjadi huruf kecil untuk memudahkan pengecekan
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    string input;
    int vowelCount = 0;

    // Memasukkan kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);

    // Sequential Search untuk menghitung jumlah huruf vokal
    for (int i = 0; i < input.length(); ++i) {
        if (isVowel(input[i])) {
            ++vowelCount;
        }
    }

    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount << endl;

    return 0;
}