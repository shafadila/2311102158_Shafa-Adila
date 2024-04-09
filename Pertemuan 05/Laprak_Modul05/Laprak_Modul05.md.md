# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Shafa Adila Santoso - 2311102158</p>

## Dasar Teori

Hash table adalah sebuah strukytur data yang digunakan untuk menyimpan dan mengelola data secara cepat serta efisien. Hash table ini adalah struktur data yang mengorganisisr data kedalam pasangan kunci-nilai. Dengan cara ini, akses ke data menjadi sangat cepat karena kita dapat langsung menghitung indeks tempat data disimpan. Ini cocok untuk pencarian, penyisipan, penghapusan, dan pembaruan data dalam waktu konstan , asalkan tidak ada konflik dalam fungsi hash (collision). Ini enggunakan fungsi hash untuk menkonversi kunci menjadi indeks kedalam array. Hash table ini berfungsi untuk memetakan nilai yang diberikan dengan kunci tertentu ke indeks dalam array. Dengan demikian, hash table memungkinkan akses langsungke lokasi penyimpanan data tanpa perlu mencari melalui seluruh sturktur data. Selain itu, hash table ini memiliki kemampuan untuk menyediakan operasi pencarian yang efisien, memastikan kecepatan dalam penyisipan dan penghapusan data, serta penggunaan memori yang efisien.
1.	Operasi Hash Table
1.	Insertion 
Operasi ini digunakan untuk menyisipkan elemen/data baru ke dalam Hash Table. Elemen baru akan ditempatkan pada indeks yang dihasilkan oleh fungsi hash.
2.	Deletion
Digunakan untuk menghapus elemen/data dari Hash Table berdasarkan kunci atau indeksnya. Elemen yang dihapus akan dihapus dari indeks yang dihasilkan oleh fungsi hash.
3.	Searching
Digunakan untuk mencari elemen/data dalam Hash Table berdasarkan kunci atau indeksnya. Pencarian dilakukan dengan menggunakan fungsi hash untuk menghasilkan indeks elemen yang dicari.
4.	Update
Operasi ini digunakan untuk mengubah nilai elemen/data yang sudah ada dalam Hash Table. Nilai elemen dapat diubah berdasarkan kunci atau indeksnya.
5.	Traversal 
Melalui seluruh hash table untuk memproses semua data yang ada dalam tabel.
6.	Collision Handling
Collision terjadi ketika dua atau lebih elemen memiliki indeks yang sama setelah melalui fungsi hash. Operasi ini digunakan untuk menangani collision dan memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar. Terdapat dua tekhnik untuk menyelesaikan permasalhan seperti diatas, yaitu;
1.	Open Hasing (Chaining)
Open hashing adalah salah satu teknik dalam hashing di mana setiap elemen dari tabel hash memiliki slot atau bucket yang dapat menampung beberapa elemen. Ketika kolisi terjadi, yaitu ketika dua kunci hashing diarahkan ke slot yang sama, elemen yang baru saja dimasukkan disisipkan ke dalam bucket yang sesuai. Ini berbeda dengan teknik hashing tertutup (closed hashing), di mana kolisi diatasi dengan menempatkan elemen di lokasi lain dalam tabel hash. Dalam open hashing, struktur data yang digunakan untuk menyimpan elemen yang bertabrakan biasanya adalah struktur data seperti daftar berantai. Ketika sebuah elemen baru dimasukkan ke dalam tabel hash dan menemukan kolisi, ia ditambahkan ke dalam daftar yang terkait dengan slot tersebut.
2.	Closed Hashing
Closed hashing adalah salah satu metode yang digunakan dalam implementasi struktur data tabel hash. Ini melibatkan penyimpanan elemen-elemen data secara langsung di dalam tabel hash, tanpa menggunakan struktur tambahan seperti linked list untuk menangani tabrakan hash. Dalam closed hashing, ketika terjadi tabrakan hash (yaitu, dua kunci hash berbeda memetakan ke indeks yang sama dalam tabel hash), algoritma penyelesaian tabrakan seperti "probing" atau "open addressing" digunakan. Dengan probing, sistem mencari slot kosong lainnya di dalam tabel hash untuk menempatkan elemen data yang bertabrakan. Beberapa metode probing yang umum digunakan dalam closed hashing termasuk:
1.	Linear probing
Linear Probing yaitu Sistem untuk mencari slot kosong berikutnya secara berurutan, mulai dari indeks di mana konflik terjadi.
2.	Quadratic probing
Quadratic Probing yaitu Sistem untuk mencari slot kosong dengan langkah yang bertambah secara kuadrat setiap kali konflik terjadi.
3.	Double hashing
Double Hashing adalah Sistem yang menggunakan dua buah fungsi hash untuk menentukan langkah-langkah probing.


## Guided 

### 1. [Program Hashtable]

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```
Program di atas adalah program C++ yang mengimplementasikan hash table.  Kelas HashTable memiliki metode insert untuk menyisipkan pasangan kunci-nilai, get untuk mencari nilai yang terkait dengan kunci tertentu, remove untuk menghapus pasangan kunci-nilai yang sesuai dengan kunci yang diberikan, dan traverse untuk mencetak semua pasangan kunci-nilai dalam hash table. Dalam fungsi main, hash table dibuat dan diisi dengan beberapa pasangan kunci-nilai menggunakan metode insert. Operasi pencarian (get) dan penghapusan (remove) digunakan untuk menguji fungsionalitas hash table. Akhirnya, isi dari hash table dicetak menggunakan metode traverse.

### 2. [Program Hashtable]

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11; // Ukuran tabel hash

string name; 
string phone_number; 

class HashNode
{
public:
    string name;
    string phone_number;

    // Konstruktor untuk inisialisasi node hash
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE]; // Tabel hash sebagai vektor dari pointer ke HashNode

public:
    // Fungsi hash untuk menghasilkan indeks dari sebuah kunci
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Fungsi untuk menambahkan data ke tabel hash
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name); 
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Fungsi untuk menghapus data dari tabel hash berdasarkan kunci
    void remove(string name)
    {
        int hash_val = hashFunc(name); 
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Fungsi untuk mencari nomor telepon berdasarkan nama
    string searchByName(string name)
    {
        int hash_val = hashFunc(name); 
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }

        return "";
    }

    // Fungsi untuk mencetak isi tabel hash
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map; // Membuat objek hashmap

    // Menambahkan data ke hashmap
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    // Mencari nomor telepon berdasarkan nama
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    // Menghapus data dari hashmap
    employee_map.remove("Mistah");

    // Mencetak hashmap setelah penghapusan
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print(); // Cetak isi hashmap

    return 0;
}
```
Program di atas adalah program C++ yang mengimplementasikan hashmap. Metode hashFunc digunakan untuk menghasilkan nilai hash dari nama karyawan dengan menjumlahkan nilai ASCII dari karakter-karakter dalam nama dan kemudian mengambil sisa hasil bagi dengan ukuran tabel hash. Selanjutnya Metode insert memasukkan pasangan kunci-nilai baru ke hashmap. Jika nama karyawan sudah ada, nilai nomor teleponnya diperbarui; jika tidak, pasangan baru ditambahkan. Selanjutnya Metode remove menghapus pasangan kunci-nilai yang terkait dengan nama karyawan tertentu dari hashmap. Selanjutnya  Metode searchByName mencari nomor telepon karyawan berdasarkan nama karyawan. Mengembalikan nomor telepon jika karyawan ditemukan; jika tidak, mengembalikan string kosong. Metode print mencetak isi hashmap, menampilkan setiap pasangan kunci-nilai. Di dalam fungsi main, hashmap diisi dengan beberapa nama karyawan dan nomor telepon mereka. Beberapa pencarian dilakukan, dan satu nama karyawan dihapus dari hashmap. Hasilnya kemudian dicetak pada output untuk memeriksa operasi-insert dan operasi-hapus yang dilakukan.

## Unguided 

### 1. [mplementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : Setiap mahasiswa memiliki NIM dan nilai, Program memiliki tampilan pilihan menu berisi poin C, Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai]

```C++
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

```
#### Output:
![unguided1](Unguided1(1).png)
![unguided1](Unguided1(2).png)

Program di atas merupakan program C++ yang mengimplementasikan struktur data hash table. Program ini memungkinkan pengguna untuk menambah, menghapus, dan mencari data mahasiswa berdasarkan Nomor Induk Mahasiswa (NIM) atau nilai mereka. Pada awalnya, program mendefinisikan struktur data Mahasiswa yang memiliki dua atribut: NIM_158 dan nilai_158. Selanjutnya, program mendefinisikan kelas HashTable yang memiliki tabel hash sebagai anggota privatnya. Setiap elemen dalam tabel hash merupakan daftar terkait (list) yang dapat menyimpan objek Mahasiswa. Kelas HashTable juga memiliki beberapa metode, termasuk untuk menambah, menghapus, dan mencari data mahasiswa berdasarkan NIM atau nilai mereka. Kemudian di dalam fungsi main(), program memberikan menu kepada pengguna untuk memilih operasi yang ingin dilakukan. Pengguna dapat memilih untuk menambahkan data mahasiswa, menghapus data mahasiswa, mencari data mahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan nilai, atau keluar dari program. Setiap pilihan memicu eksekusi fungsi yang sesuai dalam kelas HashTable. Program akan terus berjalan hingga pengguna memilih untuk keluar dengan memilih opsi nomor 5.


## Kesimpulan
Dengan dilaksanakannya praktikum ini dapat membantu mahasiswa bagaimana sebenarnya definisi dan konsep dari Hash Code serta membantu mahasiswa untuk mengimplementasikan Hash Code kedalam Pemrograman[1].

## Referensi
[1] Ramdhani, R., Fadlil, A., & Sunardi, S. (2022). Penerapan Algoritma Winnowing dan Word-Level Trigrams Untuk Mengidentifikasi Kesamaan Kata. JURIKOM (Jurnal Riset Komputer), 9(2), 427-435.</br>
[2] Syahrir, M., & Fatimatuzzahra, F. (2020). Association Rule Integrasi Pendekatan Metode Custom Hashing dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori. Matrik: Jurnal Manajemen, Teknik Informatika Dan Rekayasa Komputer, 20(1), 149-158.</br>
