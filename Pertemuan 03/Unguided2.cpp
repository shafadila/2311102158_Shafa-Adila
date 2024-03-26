#include <iostream>
#include <iomanip> // Untuk setprecision
#include <string>
using namespace std;

// Node structure
struct Node {
    string namaProduk_158;
    double harga_158;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Tambah data di awal
    void push(string nama_produk, double harga) {
        Node* newNode = new Node;
        newNode->namaProduk_158 = nama_produk;
        newNode->harga_158 = harga;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }


    // Tambah data di tengah setelah node tertentu
    void insertTengah(string produkSebelum, string produkBaru, double harga_baru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk_158 == produkSebelum) {
                Node* newNode = new Node;
                newNode->namaProduk_158 = produkBaru;
                newNode->harga_158 = harga_baru;
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk dengan nama " << produkSebelum << " tidak ditemukan." << endl;
    }

    // Hapus data
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Update data tertentu
    bool update(string nama_produk_lama, string nama_produk_baru, double harga_baru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk_158 == nama_produk_lama) {
                current->namaProduk_158 = nama_produk_baru;
                current->harga_158 = harga_baru;
                return true;
            }
            current = current->next;
        }
        return false;
    }


     // Hapus data di urutan tertentu
    void hapusDataUrutanTertentu(int urutan) {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        Node* current = head;
        int count = 1;
        while (current != nullptr && count != urutan) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Data tidak ditemukan pada urutan tersebut." << endl;
            return;
        }

        if (current == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Data pada urutan " << urutan << " berhasil dihapus." << endl;
    }

    // Hapus semua data
    void hapusData() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Tampilkan semua data dalam bentuk tabel
    void TampilkanData() {
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "| " << setw(15) << left << "Nama Produk" << "| " << setw(8) << left << "Harga" << " |" << endl;
        cout << "-----------------------------" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << "| " << setw(15) << left << current->namaProduk_158 << "| " << setw(8) << left << current->harga_158 << " |" << endl;
            current = current->next;
        }
        cout << "-----------------------------" << endl;
        cout << endl;
    }
};

int main() {
    DoubleLinkedList list;
    while (true) {
        cout << endl;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        switch (choice) { //switch case untuk menu
            case 1: {
                string nama_produk;
                double harga;
                cout << "Masukkan nama produk: ";
                cin.ignore(); // Membersihkan buffer keyboard
                getline(cin, nama_produk);
                cout << "Masukkan harga: ";
                cin >> harga;
                list.push(nama_produk, harga);
                break;
            }
            case 2: {
                list.pop();
                break;
            }

            case 3: {
                string nama_produk_lama, nama_produk_baru;
                double harga_baru;
                cout << "Masukkan nama produk yang ingin diubah: ";
                cin.ignore(); // Membersihkan buffer keyboard
                getline(cin, nama_produk_lama);
                cout << "Masukkan nama produk baru: ";
                getline(cin, nama_produk_baru);
                cout << "Masukkan harga produk baru: ";
                cin >> harga_baru;
                bool updated = list.update(nama_produk_lama, nama_produk_baru, harga_baru);
                if (!updated) {
                    cout << "Data tidak ditemukan" << endl;
                } else {
                    cout << "Data produk berhasil diperbarui." << endl;
                }
                break;
        }

            case 4: {
                string nama_produk_sebelum, nama_produk_baru;
                double harga_baru;
                cout << "Masukkan nama produk sebelum produk baru: ";
                cin.ignore(); // Membersihkan buffer keyboard
                getline(cin, nama_produk_sebelum);
                cout << "Masukkan nama produk baru: ";
                getline(cin, nama_produk_baru);
                cout << "Masukkan harga produk baru: ";
                cin >> harga_baru;
                list.insertTengah(nama_produk_sebelum, nama_produk_baru, harga_baru);
                break;
            }
            case 5: {
                int urutan;
                cout << "Masukkan urutan data yang ingin dihapus: ";
                cin >> urutan;
                list.hapusDataUrutanTertentu(urutan);
                break;
            }
            case 6: {
                list.hapusData();
                break;
            }
            case 7: {
                list.TampilkanData();
                break;
            }
            case 8: {
                return 0;
            }

            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    return 0;
}








