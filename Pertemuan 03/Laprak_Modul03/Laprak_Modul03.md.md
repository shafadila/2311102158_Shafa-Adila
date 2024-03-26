# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Shafa Adila Santoso - 2311102158</p>

## Dasar Teori

Linked list adalah suatu bentyk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaitan atau dihubungkan dengan elemen lain melalui suatu pointer. Pointer itu sendiri adalah alamat elmen data yang tersimpan di memori. Penggunaan pointer untuk mengacu lemen berakibat elemen elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori. Linked loist terdiri dari node node (simmpul simpul) yang saling terhubung (linked). Simpul berupa struct, sedangkan link berupa komponen yang bertipe pointer ke simpul. Ada dua jenis pointer yang digunakan, yaitu head (menunjukkan alamat pinter paling depan) dan tail (menunjukkan simpul terakhir). Operasi penambahan atau penghapusan sebuah simpul akan mengubah nilai pointer link nya. Sedangkan pointer link disimpul terakhir diberi niali null.
1.	Single linked list
Isngle Linked List adalah sekumpulan node yang saling berhubungan dengan node lain melalui sebuah pointer. Single Linked List hanya meimiliki satu arah. Pada list jenis ini, tiap node nya memiliki field yang berisi pointer ke node berikutnya dan juga memiliki field yang berisi data. Akhir linked list ditandai dengan node terakhir yang menunjuk ke null yang akan digunakan sebagai kondisi berhenti saat pembacaan linked list.
2.	Double Linked List
Salah satu kelemahan Single Linked List adalah pointer hanya dapat bergerak satu arah, yaitu maju atau mundur saja atau kana dan kiri sehingga pencarian data pada Singled Linked List hanya dapat bergerak dalam satu arah. Untuk mengatasi kelemahan ini, kita bisa menggunakan metode Double Linked List, yang dikenal juga Linked List berpointer ganda atau Double Linked List. Double Linked List adalah sebuah Linked List dengan node yang memiliki data dan dua buah reference link yang menunjuk kenode sebelum dan node sesudahnya. 


## Guided 

### 1. [Program Single Linked List Non-Circular]

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}

//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
        if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
        }else{
        baru->next = head;
        head = baru;
        }
}

//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
        if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
        }
        else{
        tail->next = baru;
        tail = baru;
        }
}

//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
                bantu = head;
                int nomor = 1;
        while( nomor < posisi - 1 ){
                bantu = bantu->next;
                nomor++;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node *hapus;
        if (isEmpty() == false){
            if (head->next != NULL){
                hapus = head;
                head = head->next;
                delete hapus;   
        }
        else{
        head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
    void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
        }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi){
Node *bantu;
if (isEmpty() == false){
    if( posisi < 1 || posisi > hitungList() ){
    cout << "Posisi di luar jangkauan" <<
    endl;
    }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" <<
    endl;
    }else{
    bantu = head;
    int nomor = 1;
        while (nomor < posisi){
        bantu = bantu->next;nomor++;
        }
        bantu->data = data;
    }
}else{
    cout << "List masih kosong!" << endl;
}
}

//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}

//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
      while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    return 0;
}
```
Program diatas adalah program c++ yang mengimplementasikan Linked List jenis satu arah atau Single Linked List, karenaterlihat dari struktur tiap simpulnya hanya memiliki satu pointer saja yaitu "next" yang menunjuk kesimpul berikutnya dalam urutan.pada program diatas menggunakan banyak fungsi untuk mengelola Linked List termasuk penambahan node didepan "insertDepan", di belakang "insertBelakang", atau di tengah "insertTengah", penghapusan node dari depan `hapusDepan`, belakang "hapusBelakang", dan tengah `hapusTengah`. Kemudian pengubahan data pada node pertama ``ubahDepan`, tengah `ubahTengah`, dan belakang `ubahBelakang`, serta dungsi untuk menghitung jumlah node dalam Linked List yaitu `hitungList` dan menampilkan isi Linked ist yaitu `tampil`.

### 2. [Program Double Linked List]

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    public:
    Node* head;
    Node* tail;

DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void push(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;
        if (head != nullptr) {
        head->prev = newNode;
        }
        else {
        tail = newNode;
        }
        head = newNode;
}

void pop() {
    if (head == nullptr) {
    return;
    }
    Node* temp = head;
    head = head->next;
        if (head != nullptr) {
        head->prev = nullptr;
        }
        else {
        tail = nullptr;
        }
        delete temp;
}

bool update(int oldData, int newData) {
    Node* current = head;while (current != nullptr) {
        if (current->data == oldData) {
        current->data = newData;
        return true;
        }
        current = current->next;
        }
    return false;
}

void deleteAll() {
    Node* current = head;
    while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void display() {
    Node* current = head;
    while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
    }
    cout << endl;
}
};

int main() {
    DoublyLinkedList list;
    while (true) {
    cout << "1. Add data" << endl;
    cout << "2. Delete data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Clear data" << endl;
    cout << "5. Display data" << endl;
    cout << "6. Exit" << endl;int choice;
    cout << "Enter your choice: ";
    cin >> choice;
        switch (choice) {
        case 1: {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
        break;
        }
        case 2: {
            list.pop();
        break;
        }
        case 3: {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData,
            newData);
                if (!updated) {
                cout << "Data not found" << endl;
                }
        break;
        }
        case 4: {
            list.deleteAll();
        break;
        }
        case 5: {
            list.display();
        break;
        }
        case 6: {
        return 0;
        }
        default: {
         cout << "Invalid choice" << endl;
        break;
        }
        }
    }
    
    return 0;
}
```
Program yang diberikan adalah implementasi dari struktur data Doubly Linked List dalam bahasa pemrograman C++. Dalam program ini, dua kelas utama didefinisikan: kelas Node, yang merepresentasikan simpul dalam Doubly Linked List, dan kelas DoublyLinkedList, yang menyediakan operasi-operasi dasar untuk mengelola Doubly Linked List. Kelas Node memiliki tiga anggota data yaitu data, prev, dan next. Data digunakan untuk menyimpan nilai integer dalam simpul, sedangkan prev dan next adalah pointer yang menunjuk ke simpul sebelumnya dan berikutnya secara berturut-turut. Kelas DoublyLinkedList memiliki dua pointer utama yaitu head dan tail, yang masing-masing menunjuk ke simpul pertama dan terakhir dalam daftar. Konstruktor kelas ini menginisialisasi pointer-head dan pointer-tail ke nullptr, menandakan bahwa daftar saat ini kosong.


## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user]

```C++
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

```
#### Output:
![unguided1](Unguided1(1).png)
![unguided1](Unguided1(2).png)
![unguided1](Unguided1(3).png)
![unguided1](Unguided1(4).png)
![unguided1](Unguided1(5).png)
![unguided1](Unguided1(6).png)
![unguided1](Unguided1(7).png)

Program di atas merupakan program c++ yang mengimplmentasikan single linked list non-circular. Kelas `LinkedList` memiliki berbagai metode untuk melakukan operasi pada linked list. Pertama, metode `tambahBelakang` digunakan untuk menambahkan node baru di belakang linked list dengan data nama dan usia yang diberikan. Selanjutnya, metode `tambahDataUrutan` digunakan untuk menambahkan node baru setelah node dengan nama yang ditentukan. Metode `tambahDepan` digunakan untuk menambahkan node baru di depan linked list. Metode `hapus` digunakan untuk menghapus node dengan nama yang ditentukan dari linked list. Metode `ubahData` digunakan untuk mengubah data nama dan usia pada node dengan nama yang ditentukan. Terakhir, metode `tampilkan()` digunakan untuk menampilkan seluruh data mahasiswa yang tersimpan dalam linked list. Di dalam fungsi `main()`, terdapat sebuah perulangan `do-while` yang bertujuan agar pengguna dapat memilih operasi yang ingin dilakukan pada linked list melalui menu yang disediakan. Opsi-opsi pada menu meliputi memasukkan data, menghapus data, menambahkan data pada urutan tertentu, menambahkan nama paling awal, mengubah data nama dan usia, serta menampilkan seluruh data mahasiswa. Program akan terus berjalan hingga pengguna memilih opsi untuk keluar dari program.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]

```C++
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
```
#### Output:
![unguided2](Unguided2(1).png)
![unguided2](Unguided2(2).png)
![unguided2](Unguided2(3).png)
![unguided2](Unguided2(4).png)
![unguided2](Unguided2(5).png)
![unguided2](Unguided2(6).png)

Program diatas merupakan progranm c++ yang mengimplementasikan double linked list.
Struktur node `Node` didefinisikan dengan atribut `namaProduk_158` untuk menyimpan nama produk (bertipe string), `harga_158` untuk menyimpan harga produk (bertipe double), serta dua pointer `prev` dan `next` yang menunjukkan ke node sebelumnya dan selanjutnya dalam double linked list. Kelas `DoubleLinkedList` mengimplementasikan berbagai operasi pada double linked list, termasuk penambahan (metode `push()`), penyisipan di tengah (metode `insertTengah()`), penghapusan (metode `pop()`), pembaruan (metode `update()`), penghapusan pada urutan tertentu (metode `hapusDataUrutanTertentu()`), penghapusan semua data (metode `hapusData()`), dan penampilan data (metode `TampilkanData()`). Atribut `head` dan `tail` digunakan untuk menunjukkan node pertama dan terakhir dalam double linked list. Dalam fungsi `main()`, pengguna diberikan pilihan untuk melakukan berbagai operasi pada double linked list, seperti menambah, menghapus, memperbarui, atau menampilkan data. Pilihan akan terus muncul hingga pengguna memilih untuk keluar dari program. Ini memberikan fungsionalitas untuk mengelola data produk dalam sebuah toko skincare menggunakan double linked list.


## Kesimpulan
Bagi saya dengan dilaksanakannya praktikum mengenai Double Linked List dan Single Linked List ini sangat membantu saya dalam memahami dari perbedaan konsep single linked list dan double linked list serta dapat menerapkan single linked list dan double linked list kedalam pemrograman [1].

## Referensi
[1] Mulyana, A. (2023). E-Books Cara Mudah Mempelajari Algoritma dan Struktur Data.<br/>
[2] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.<br/>