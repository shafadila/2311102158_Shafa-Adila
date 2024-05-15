#include <iostream> // Library untuk input-output
using namespace std;

struct Node { // Deklarasi struktur Node untuk linked list
    string data_158; // Data yang disimpan dalam simpul
    Node* next; // Pointer ke simpul berikutnya
};

Node* front = nullptr; // Pointer ke simpul pertama dalam antrian
Node* back = nullptr; // Pointer ke simpul terakhir dalam antrian

bool isEmpty() { // Fungsi untuk memeriksa apakah antrian kosong
    return front == nullptr; // Kembalikan true jika front bernilai nullptr
}

void enqueueAntrian(string data) { // Fungsi untuk menambahkan data ke antrian
    Node* newNode = new Node; // Buat simpul baru
    newNode->data_158 = data; // Isi data simpul dengan data yang diberikan
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
        cout << "Antrian kosong" << endl; // Tampilkan pesan kesalahan
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
        count++; // Tambahkan jumlah data
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
    cout << "Data antrian teller:" << endl; // Tampilkan judul
    Node* temp = front; // Pointer sementara
    int i = 1; // Variabel untuk nomor antrian
    while (temp != nullptr) { // Selama belum mencapai akhir antrian
        cout << i << ". " << temp->data_158 << endl; // Tampilkan nomor dan data
        temp = temp->next; // Geser ke simpul berikutnya
        i++;
    }
    for (; i <= 5; i++) { // Tampilkan "kosong" untuk slot yang tidak terisi
        cout << i << ". (kosong)" << endl;
    }
}

int main() {
    enqueueAntrian("Andi"); // Menambahkan data "Andi" ke antrian
    enqueueAntrian("Maya"); // Menambahkan data "Maya" ke antrian
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
