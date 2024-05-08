#include <iostream>
using namespace std;

string arrayBuku[5]; // Array untuk menyimpan data buku
int maksimal = 5, top = 0;  // Variabel untuk batas maksimum dan posisi teratas stack

bool isFull() { // Fungsi untuk memeriksa apakah stack penuh
    return (top == maksimal); // Mengembalikan true jika stack penuh, false jika tidak
}

bool isEmpty() { // Fungsi untuk memeriksa apakah stack kosong
    return (top == 0); // Mengembalikan true jika stack kosong, false jika tidak
}

void pushArrayBuku(string data) { // Fungsi untuk menambahkan data ke stack
    if (isFull()) { // Jika stack penuh
        cout << "Data telah penuh" << endl; // Tampilkan pesan bahwa data penuh
    } else { // Jika tidak penuh
        arrayBuku[top] = data; // Tambahkan data ke stack
        top++; // Pindahkan posisi top
    }
}

void popArrayBuku() { // Fungsi untuk menghapus data dari stack
    if (isEmpty()) { // Jika stack kosong
        cout << "Tidak ada data yang dihapus" << endl; // Tampilkan pesan bahwa tidak ada data yang dihapus
    } else { // Jika tidak kosong
        arrayBuku[top - 1] = ""; // Hapus data dari stack
        top--; // Pindahkan posisi top
    }
}

void peekArrayBuku(int posisi) { // Fungsi untuk melihat data pada posisi tertentu dari stack
    if (isEmpty()) { // Jika stack kosong
        cout << "Tidak ada data yang bisa dilihat" << endl; // Tampilkan pesan bahwa tidak ada data yang bisa dilihat
    } else { // Jika tidak kosong
        int index = top; // Inisialisasi index dengan posisi top
        for (int i = 1; i <= posisi; i++) { // Loop untuk mencari posisi yang diminta
            index--; // Kurangi index
    }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl; // Tampilkan data pada posisi tersebut
    }
}

int countStack() { // Fungsi untuk menghitung jumlah data di stack
    return top; // Mengembalikan jumlah data di stack
}

void changeArrayBuku(int posisi, string data) { // Fungsi untuk mengubah data pada posisi tertentu di stack
    if (posisi > top) { // Jika posisi melebihi jumlah data di stack
        cout << "Posisi melebihi data yang ada" << endl; // Jika posisi melebihi jumlah data di stack
    } else { // Jika tidak melebihi
        int index = top; // Inisialisasi index dengan posisi top
        for (int i = 1; i <= posisi; i++) { // Loop untuk mencari posisi yang diminta
            index--; // Kurangi index
        }
        arrayBuku[index] = data; // Ubah data pada posisi tersebut
    }
}

void destroyArraybuku() { // Fungsi untuk menghapus semua data di stack
    for (int i = top; i >= 0; i--) { // Loop untuk menghapus data satu per satu
        arrayBuku[i] = ""; // Menghapus data
    }
    top = 0; // Mengatur posisi top menjadi 0
}

void cetakArrayBuku() { // Fungsi untuk mencetak semua data di stack
    if (isEmpty()) { // Jika stack kosong
        cout << "Tidak ada data yang dicetak" << endl; // Tampilkan pesan bahwa tidak ada data yang dicetak
    } else { // Jika tidak kosong
        for (int i = top - 1; i >= 0; i--) { // Loop untuk mencetak data dari atas ke bawah
            cout << arrayBuku[i] << endl; // Cetak data
        }
    }
}

 // Fungsi main
int main() {

     // Menambahkan data buku ke stack
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

     // Mencetak semua data di stack
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;// Memeriksa apakah stack penuh
    cout << "Apakah data stack kosong? " << isEmpty() << endl; // Memeriksa apakah stack kosong

    peekArrayBuku(2); // Melihat data pada posisi tertentu dari stack
    popArrayBuku(); // Menghapus data dari stack

    cout << "Banyaknya data = " << countStack() << endl; // Menghitung jumlah data distack

    changeArrayBuku(2, "Bahasa Jerman"); // Mengubah data pada posisi tertentu di stack
    cetakArrayBuku(); // Mencetak semua data distack

    cout << "\n";

    destroyArraybuku(); // Menghapus semua data di stack
    cout << "Jumlah data setelah dihapus: " << top << endl; // Menampilkan jumlah data setelah dihapus

    cetakArrayBuku(); // Mencetak semua data di stack

    return 0; // Mengembalikan nilai 0
}

