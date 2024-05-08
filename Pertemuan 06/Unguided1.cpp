#include <iostream> // Header untuk input-output
#include <stack> // Header untuk struktur data stack
#include <string> // Header untuk tipe data string
#include <locale> // Header untuk fungsi-fungsi lokalisasi
using namespace std;

// Menghapus spasi dan mengubah huruf menjadi lowercase
string ProsesAwal(string kata_158) {
    string result;
    for (char c : kata_158) { // Melakukan iterasi untuk setiap karakter dalam kata
        if (isalpha(c)) { // Memeriksa apakah karakter merupakan huruf
            result += tolower(c); // Jika huruf, ubah menjadi lowercase dan tambahkan ke hasil
        }
    }
    return result; // Mengembalikan hasil pengolahan
}

// Memeriksa apakah kalimat adalah palindrom
bool Polindrome(string kata_158) {
    stack<char> charStack; // Mendeklarasikan stack untuk menyimpan karakter
    int length = kata_158.length(); // Mendapatkan panjang kalimat
    int i;

    // Push setengah pertama karakter ke stack
    for (i = 0; i < length / 2; i++) { // Iterasi untuk setengah pertama karakter
        charStack.push(kata_158[i]); // Menyimpan karakter ke stack
    }

    // Jika panjang ganjil, lewati karakter tengah
    if (length % 2 != 0) {
        i++; // Lewati karakter tengah
    }

    // Bandingkan karakter dari setengah kedua dengan karakter dari stack
    while (i < length && !charStack.empty()) { // Iterasi untuk setengah kedua karakter dan stack tidak kosong
        if (kata_158[i] != charStack.top()) { // Membandingkan karakter
            return false; // Jika tidak sama, keluar dan mengembalikan false
        }
        charStack.pop(); // Jika sama, hapus karakter dari stack
        i++; // Lanjutkan ke karakter berikutnya
    }

    // Jika stack kosong, maka kalimat adalah palindrom
    return charStack.empty(); // Mengembalikan apakah stack kosong atau tidak
}

// Fungsi main
int main() {

    string kalimat;
    cout << "Masukkan kalimat: "; // Meminta pengguna untuk memasukkan kalimat
    getline(cin, kalimat); // Membaca kalimat dari input

    // Pra-pemrosesan string: hapus spasi dan ubah huruf menjadi lowercase
    string processedKalimat = ProsesAwal(kalimat);

    // Cek kalimat adalah palindrom
    if (Polindrome(processedKalimat)) { // Memanggil fungsi untuk memeriksa palindrom
        cout << "Kalimat tersebut adalah palindrom." << endl; // Jika palindrom
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl; // Jika bukan palindrom
    }

    return 0; // Mengembalikan nilai 0
}
