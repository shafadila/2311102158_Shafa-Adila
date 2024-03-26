#include <iostream>
#include <iomanip> //untuk setpresicion
using namespace std;

// Deklarasi struktur Node
struct Node {
    string nama_158;
    int usia_158;
    Node* next;
};

// Kelas LinkedList
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = NULL;
    }

    // Method untuk menambahkan node di belakang
    void tambahBelakang(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama_158 = nama;
        newNode->usia_158 = usia;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }

    // Method untuk menambahkan node setelah node tertentu
    void tambahDataUrutan(string namaSebelum, string nama, int usia) {
        Node* temp = head;
        while (temp != NULL && temp->nama_158 != namaSebelum) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node tidak ditemukan." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->nama_158 = nama;
        newNode->usia_158 = usia;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Method untuk menambahkan node di depan
    void tambahDepan(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama_158 = nama;
        newNode->usia_158 = usia;
        newNode->next = head;
        head = newNode;
    }

    // Method untuk menghapus node dengan nama tertentu
    void hapus(string nama) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->nama_158 == nama) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->nama_158 != nama) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Data tidak ditemukan." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Method untuk mengubah data nama dan usia
    void ubahData(string namaLama, string namaBaru, int usiaBaru) {
        Node* temp = head;
        while (temp != NULL && temp->nama_158 != namaLama) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Data tidak ditemukan." << endl;
            return;
        }

        temp->nama_158 = namaBaru;
        temp->usia_158 = usiaBaru;
    }

    // Method untuk menampilkan seluruh data
    void tampilkan() {
        cout << "-----------------------------" << endl;
        cout << "| " << setw(15) << left << "Nama" << "| " << setw(8) << left << "Usia" << " |" << endl;
        cout << "-----------------------------" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << "| " << setw(15) << left << temp->nama_158  << "| " << setw(8) << left << temp->usia_158 << " |" << endl;
            temp = temp->next;
        }
        cout << "-----------------------------" << endl;
    }
};

int main() {
    LinkedList linkedList;
    int pilihan;
    string nama, namaSebelum, namaBaru;
    int usia;

    do {
        cout << "\nMenu Operasi:" << endl;
        cout << "1. Masukkan data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Tambahkan data pada urutan tertentu" << endl;
        cout << "4. Tambahkan Nama paling awal" << endl;
        cout << "5. Ubah data nama dan usia" << endl;
        cout << "6. Tampilkan seluruh data" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1 :
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                linkedList.tambahBelakang(nama, usia);
                break;
            case 2 :
                cout << "Masukkan nama yang ingin dihapus: ";
                cin >> nama;
                linkedList.hapus(nama);
                break;
            case 3 :
                cout << "Masukkan nama node sebelumnya: ";
                cin >> namaSebelum;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                linkedList.tambahDataUrutan(namaSebelum, nama, usia);
                break;
            case 4:
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan usia baru: ";
                cin >> usia;
                linkedList.tambahDepan(namaBaru, usia);
                break;
            case 5:
                cout << "Masukkan nama yang ingin diubah: ";
                cin >> nama;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan usia baru: ";
                cin >> usia;
                linkedList.ubahData(nama, namaBaru, usia);
                break;
            case 6:
                cout << "\nData mahasiswa:" << endl;
                linkedList.tampilkan();
                break;
            case 7:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 'f');

    return 0;
}
