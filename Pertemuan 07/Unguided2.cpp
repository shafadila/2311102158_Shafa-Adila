#include <iostream> // Library untuk input-output
using namespace std;

struct Node { // Deklarasi struktur Node untuk linked list
    string nama_158; // Data yang disimpan dalam simpul
    string nim_158; // Data yang disimpan dalam simpul
    Node* next; // Pointer ke simpul berikutnya
};

Node* front = nullptr; // Pointer ke simpul pertama dalam antrian
Node* back = nullptr; // Pointer ke simpul terakhir dalam antrian

bool isEmpty() { // Fungsi untuk memeriksa apakah antrian kosong
    return front == nullptr; // Kembalikan true jika front bernilai nullptr
}

void enqueueAntrian(string nama_158, string nim_158) { // Fungsi untuk menambahkan data ke antrian
    Node* newNode = new Node; // Buat simpul baru
    newNode->nama_158 = nama_158; // Isi data simpul dengan nama_158 yang diberikan
    newNode->nim_158 = nim_158; // Isi data simpul dengan nim_158 yang diberikan
    newNode->next = nullptr; // Set pointer next menjadi nullptr
    if (isEmpty()) { // Jika antrian kosong
        front = back = newNode; // Jadikan simpul baru sebagai front dan back
    } else { // Jika antrian tidak kosong
        back->next = newNode; // Tautkan simpul baru di belakang
        back = newNode; // Perbarui pointer back
    }
}

void dequeueAntrian() { // Fungsi untuk menghapus data dari antrian
    if (isEmpty()) { // Jika antrian kosong
        cout << "Antrian kosong" << endl; // Menampilkan pesan kesalahan
    } else {
        Node* temp = front; // Simpan pointer ke simpul pertama
        front = front->next; // Geser front ke simpul berikutnya
        delete temp; // Hapus simpul pertama
    }
}

int countQueue() { // Fungsi untuk menghitung jumlah data dalam antrian
    int count = 0; // Variabel untuk menyimpan jumlah data
    Node* temp = front; // Pointer sementara untuk traversal
    while (temp != nullptr) { // Selama belum mencapai akhir antrian
        count++; // Menambahkan jumlah data
        temp = temp->next; // Geser ke simpul berikutnya
    }
    return count; // Kembalikan jumlah data
}

void clearQueue() { // Fungsi untuk menghapus semua data dalam antrian
    while (!isEmpty()) { // Selama antrian belum kosong
        dequeueAntrian(); // Hapus data pertama dalam antrian
    }
}

void viewQueue() { // Fungsi untuk menampilkan isi antrian
    cout << "Data antrian Mahasiswa:" << endl; // Menampilkan judul
    Node* temp = front; // Pointer sementara untuk traversal
    int i = 1; // Variabel untuk nomor antrian
    while (temp != nullptr) { // Selama belum mencapai akhir antrian
        cout << i << temp->nama_158 << " - " << temp->nim_158 << endl; // Menampilkan nomor dan data
        temp = temp->next; // Geser ke simpul berikutnya
        i++; // Tingkatkan nomor antrian
    }
    for (; i <= 5; i++) { // Menampilkan "kosong" untuk slot yang tidak terisi
        cout << i << ". (kosong)" << endl;
    }
}

int main() {
    enqueueAntrian("Shafa", "2311102158"); // Menambahkan data "Andi" ke antrian
    enqueueAntrian("Adila", "2311102156"); // Menambahkan data "Adila" ke antrian
    viewQueue(); // Menampilkan isi antrian
    cout << "Jumlah antrian = " << countQueue() << endl; // Menampilkan jumlah data dalam antrian
    dequeueAntrian(); // Hapus data pertama dari antrian
    viewQueue(); // Menampilkan isi antrian setelah penghapusan
    cout << "Jumlah antrian = " << countQueue() << endl; // Menampilkan jumlah data dalam antrian
    clearQueue(); // Hapus semua data dalam antrian
    viewQueue(); // Menampilkan isi antrian setelah penghapusan semua data
    cout << "Jumlah antrian = " << countQueue() << endl; // Menampilkan jumlah data dalam antrian
    return 0; // Kembalikan nilai 0 untuk menandakan program berakhir dengan sukses
}
