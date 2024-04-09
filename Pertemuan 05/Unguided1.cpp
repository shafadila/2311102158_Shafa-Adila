#include <iostream> // Library standar untuk input-output
#include <list> // Library untuk struktur data list
#include <string> // Library untuk tipe data string
using namespace std; // Menggunakan namespace std untuk menghindari penulisan std:: sebelum setiap fungsi dari library yang digunakan

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string NIM_158;
    int nilai_158;
};

// Class untuk hash table
class HashTable {
private:
    static const int tableSize = 100; // Ukuran tabel hash
    list<Mahasiswa> table[tableSize]; // Tabel hash

    // Fungsi hashFunction mengambil string sebagai kunci dan mengembalikan indeks hashnya
    int hashFunction(string key) {
        int hash = 0; // Inisialisasi variabel hash sebagai 0
        for (char c : key) { // Loop melalui setiap karakter dalam kunci
            hash += c;
        }
        return hash % tableSize; // Menambahkan nilai ASCII dari setiap karakter ke variabel hash
    }

public:
    // Fungsi untuk menambahkan data mahasiswa
    void tambahData(string NIM, int nilai) { 
        int index = hashFunction(NIM); // Menggunakan fungsi hash untuk mendapatkan indeks tabel
        Mahasiswa mhs; // Membuat objek Mahasiswa untuk menyimpan data
        mhs.NIM_158 = NIM;// Menyimpan NIM dalam objek Mahasiswa
        mhs.nilai_158 = nilai; // Menyimpan nilai dalam objek Mahasiswa
        table[index].push_back(mhs); // Memasukkan objek Mahasiswa ke dalam tabel pada indeks yang sesuai
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(string NIM) {
        int index = hashFunction(NIM); // Menggunakan fungsi hash untuk mendapatkan indeks dalam tabel hash
        for (auto it = table[index].begin(); it != table[index].end(); ++it) { // Iterasi melalui semua elemen pada slot indeks yang didapat
            if (it->NIM_158 == NIM) { 
                table[index].erase(it); // Jika cocok, hapus elemen dari tabel hash dan keluar dari loop
                break;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void caridataNIM(string NIM) {
        int index = hashFunction(NIM);  // Calculate the index using a hash function
        bool found = false; // Flag to track if the student with the given NIM is found
        for (auto& mhs : table[index]) { // Iterate through the linked list at the calculated index
            if (mhs.NIM_158 == NIM) { // Check if the NIM of the current student matches the given NIM
                cout << "NIM: " << mhs.NIM_158 << endl; 
                cout << "Nilai: " << mhs.nilai_158 << endl;
                found = true; // Set found flag to true and exit the loop
                break;
            }
        }
        if (!found) { // If the student with the given NIM is not found, print a message
            cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan nilai
    void caridataNilai(int nilai) {
        for (int i = 0; i < tableSize; ++i) {  // Iterasi melalui setiap elemen dalam array table
            for (auto& mhs : table[i]) { // Iterasi melalui setiap mahasiswa dalam table[i]
                if (mhs.nilai_158 == nilai) { // Memeriksa apakah nilai mahasiswa sama dengan nilai yang diberikan
                    cout << "NIM: " << mhs.NIM_158 << endl; //mencetak NIM mahasiswa ke layar
                    cout << "Nilai: " << mhs.nilai_158 << endl; //mencetak nilai mahasiswa ke layar
                }
            }
        }
    }
};

int main() {
    HashTable hashTable; // Membuat objek hashTable dari kelas HashTable
    int pilihan; // Mendeklarasikan variabel pilihan
    string NIM; // Mendeklarasikan variabel NIM
    int nilai; // Mendeklarasikan variabel nilai

    do {
        cout << endl;
        cout << "==================Menu Hash Table=================" << endl;
        cout << "|1.|Tambah data mahasiswa                        |" << endl;
        cout << "|2.|Hapus data mahasiswa                         |" << endl;
        cout << "|3.|Cari data mahasiswa berdasarkan NIM          |" << endl;
        cout << "|4.|Cari data mahasiswa berdasarkan nilai        |" << endl;
        cout << "|5.|Keluar                                       |" << endl;
        cout << "==================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: { // Menambah data mahasiswa
                cout << "Masukkan NIM mahasiswa: ";
                cin >> NIM;
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                hashTable.tambahData(NIM, nilai);
                cout << "Data mahasiswa berhasil ditambahkan." << endl;
                break;
            }
            case 2: { // Menghapus data mahasiswa
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> NIM;
                hashTable.hapusData(NIM);
                cout << "Data mahasiswa berhasil dihapus." << endl;
                break;
            }
            case 3: { // Mencari data mahasiswa berdasarkan NIM
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> NIM;
                hashTable.caridataNIM(NIM);
                break;
            }
            case 4: { // Mencari data mahasiswa berdasarkan nilai
                cout << "Masukkan Nilai Mahasiswa yang ingin dicari:";
                cin >> nilai;
                hashTable.caridataNilai(nilai);
                break;
            }
            case 5: { // Mengakhiri program
                cout << "Terima kasih, program selesai." << endl;
                break;
            }
            default: { // Menampilkan pesan jika pilihan tidak valid
                cout << "Pilihan tidak valid." << endl;
                break;
            }
        }
    } while (pilihan != 5);

    return 0;  // Mengembalikan nilai 0 yang menunjukkan program berakhir dengan sukses
}
