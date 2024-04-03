# <h1 align="center">Laporan Praktikum Modul Linked List Circular dan Non-Circular </h1>
<p align="center">Shafa adila Santoso - 2311102158</p>

## Dasar Teori

Linked list adalah suatu bentyk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaitan atau dihubungkan dengan elemen lain melalui suatu pointer. Pointer itu sendiri adalah alamat elmen data yang tersimpan di memori. Penggunaan pointer untuk mengacu lemen berakibat elemen elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori. Linked loist terdiri dari node node (simmpul simpul) yang saling terhubung (linked). Simpul berupa struct, sedangkan link berupa komponen yang bertipe pointer ke simpul. Ada dua jenis pointer yang digunakan, yaitu head (menunjukkan alamat pinter paling depan) dan tail (menunjukkan simpul terakhir). Operasi penambahan atau penghapusan sebuah simpul akan mengubah nilai pointer link nya. Sedangkan pointer link disimpul terakhir diberi niali null.
1.	Linked list Non-Circular
Linked list non-circular adalah sebuah struktur data berantai dimana setiap elemen disimpan dalam sebuah node yang terhubung satu sama lain dengan menggunakan referensi ke node berikutnya dalam urutan. Dalam linked list non-circular tiap node memiliki ponter ke node berikutnya, kecuali untuk node terakhir yang menunjuk ke nilai null, menandakan akhir dari daftar.
2.	Linked List Circular
Linked list circular adalah struktur data berantai di mana setiap elemen disimpan dalam node yang terhubung satu sama lain dengan menggunakan referensi ke node berikutnya dalam urutan. Namun, pada linked list circular, node terakhir tidak menunjuk ke nilai null. Sebaliknya, node terakhir menunjuk kembali ke node pertama, membentuk lingkaran atau sirkuit. Linked List Circular juga merupakan suatu linked list yang tidak memiliki nilai null dimana setiap elemen disebut node dan setiap node terdiri dari dua bagian yaitu data itu sendiri dan pointer yang menunjuk ke node berikutnya dalam urutan.

## Guided 

### 1. [Linked List Non Circular]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;   //pointer ke kepala list
    Node *next; //pointer ke ekor list
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL; //inialisasi pointer head dengan NULL
    tail = NULL; // inialisasi pointer tail dengan NULL
}
// Pengecekan list kosong atau tidak
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
        if (isEmpty() == true){
            head = tail = baru;
            tail->next = NULL;
        }else {
            tail->next = baru;
            tail = baru;
        }
}

// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
        while (hitung != NULL){
            jumlah++;
            hitung = hitung->next;
        }
        return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList()){
        cout << "Posisi diluar jangkauan" << endl;
    }else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
       
        // tranversing
        bantu = head;
        int nomor = 1;
            while (nomor < posisi - 1){
                bantu = bantu->next;
                nomor++;
            }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan(){
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }else {
            head = tail = NULL;
        }
    }else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang(){
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
            }else {
                head = tail = NULL;
            }
        }else {
            cout << "List kosong!" << endl;
        }
}

// Hapus Tengah
void hapusTengah(int posisi){
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList()){
        cout << "Posisi di luar jangkauan" << endl;
    }else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan(3);
    tampil();
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
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    clearList();
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Program diatas merupakan program c++ yang mengimplementasikan linked list non-circular. Program diatas dimulai dengan menginialisasi linked list. Kemudian fungsi-fungsi diberikan untuk melakukan operasi dasar seperti penambahan, penghapusan, dan pengubahan data dalam linked list. Operasi-operasi tersebut mencakup penambahan didepan dan dibelakang, penghapusan didepan, dibelakang dan ditengah serta pengubahan nilai data. Program diatas juga menyiadiakan fungsi untuk menghitung jumlah elemen dalam linked list, membersihkan linked list, dan menampilkan isi linked list. Seluruh operasi ini dapat dijalankan melalui fungsi main() yang juga digunakan untuk menampilkan hasil dari operasi yang sudah dijalankan pada linked list.

### 2. [Linked List Circular]

```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
head = NULL;
tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
    return 1; // true
    else
    return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
        while (bantu != NULL)
        {
            jumlah++;
            bantu = bantu->next;
        }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);
        if (isEmpty() == 1)
        {
            head = baru;
        tail = head;
        baru->next = head;
        }
        else
        {
            while (tail->next != head){
            tail = tail->next;
            }
        baru->next = head;
        head = baru;
        tail->next = head;
        }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);
        if (isEmpty() == 1)
        {
        head = baru;
        tail = head;
        baru->next = head;
        }
        else
        {
            while (tail->next != head)
            {
            tail = tail->next;
            }
        tail->next = baru;
        baru->next = head;
        }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
    head = baru;
    tail = head;
    baru->next = head;
    }
    else
    {
    baru->data = data;
    // transversing
    int nomor = 1;
    bantu = head;
        while (nomor < posisi - 1)
        {
        bantu = bantu->next;
        nomor++;
        }
    baru->next = bantu->next;
    bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
    if (hapus->next == head)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
    delete hapus;
        while (tail->next != hapus)
        {
        tail = tail->next;
        }
    head = head->next;
    tail->next = head;
    hapus->next = NULL;
    delete hapus;
    }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
            if (hapus->next == head)
            {
                head = NULL;
                tail = NULL;
            }
    else
    {
    delete hapus;
        while (hapus->next != head)
        {
            hapus = hapus->next;
        }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
        tail->next = head;
        hapus->next = NULL;
    delete hapus;
    }
    }
    else
    {
    cout << "List masih kosong!" << endl;
    }
    }
    
// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
    // transversing
    int nomor = 1;
    bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
    hapus = bantu->next;
    bantu->next = hapus->next;
    delete hapus;
    }
    else
    {
    cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL){}
}

// Tampilkan List
 void tampil()
    {
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
            cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program diatas merupakan program c++ yang mengimplementasikan linked list circular. Program diatas menginialisasi linked list dengan mengatur head dan tail menjadi NULL. Fungsi isEmpty() memeriksa apakah linked list kosong. Proda program tersebut insertDepan(), insertBelakang(), dan insertTengah() digunakan untuk menambahkan data ke linked list. Sedangkan fungsi-fungsi hapusDepan(), hapusBelakang(), dan hapusTengah() pada program diatas digunakan untuk menghapus data dari linked list. Kemudian pada program tersebut fungsi tampil() menampilkan isi linked list dan dalam fungsi main() program akan menjalankan operasi pada linked list dan menampilkan hasilnya pada output.


## Unguided 

### 1. [Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user]

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi struct Node untuk menyimpan informasi nama dan NIM mahasiswa
struct Node
{
    string nama_158; // variabel untuk menyimpan nama mahasiswa
    string nim_158; // variabel untuk menyimpan NIM mahasiswa
    Node *next; // pointer yang menunjuk ke Node selanjutnya dalam linked list
};

// pointer ke head dan tail dari linked list
Node *head = NULL;
Node *tail = NULL;

// fungsi untuk inialisasi linked list
void init(){
    head = NULL; // pointer head diatur menjadi NULL
    tail = NULL; // pointer tail diatur menjadi NULL
}

// fungsi untuk memeriksa apakah linked list kosong atau tidak
bool isEmpty(){
    return (head == NULL); // mengembalikan true jika head bernilai NULL dan false jika tidak
}

// fungsi tambah depan
void tambahDepan(string nama, string nim){
    Node *baru = new Node; // buat node baru
    baru->nama_158 = nama; // isi data nama pada node baru
    baru->nim_158 = nim; // isi data nim pada node baru
    baru->next = NULL;

    if (isEmpty()) // jika list kosong
    {
        head = tail = baru; // node baru menjadi head dan tail
    }
    else
    {
        baru->next = head; // node baru merujuk ke head yang lama
        head = baru; // node baru menjadi head yang baru
    }
}

// tambah Belakang
void tambahBelakang(string nama, string nim){
    Node *baru = new Node; // buat node baru
    baru->nama_158 = nama; // isi data nama pada node baru
    baru->nim_158 = nim; // isi data nim pada node baru
    baru->next = NULL;

    if (isEmpty()){ // jika list kosong
        head = tail = baru; // node baru menjadi head dan tail
    }else {
        tail->next = baru; // node baru ditambahkan setelah tail
        tail = baru; // node baru menjadi tail yang baru
    }
}

// hitung jumlah node di list
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
        while (hitung != NULL){
            jumlah++;
            hitung = hitung->next;
        }
    return jumlah;
}

// Tambah Node di posisi tengah dengan nama dan nim
void tambahTengah(string nama, string nim, int posisi){
    if (posisi < 1 || posisi > hitungList() + 1){
        cout << "Posisi diluar jangkauan" << endl;
    }else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }else {
        Node *baru = new Node; // Buat Node baru
        baru->nama_158 = nama; // Isi data nama pada Node baru
        baru->nim_158 = nim; // Isi data nim pada Node baru

        Node *bantu = head;
        for (int i = 1; i < posisi - 1; i++){
            bantu = bantu->next;
        }

        baru->next = bantu->next; // Node baru menunjuk ke Node setelah Node bantu
        bantu->next = baru; // Node bantu menunjuk ke Node baru
    }
}

// fungsi hapus depan
void hapusDepan(){
    if (!isEmpty()) // Cek apakah list tidak kosong
    {
        Node *hapus = head; // Simpan node yang akan dihapus
        if (head == tail) // Jika hanya ada satu node di list
        {
            head = tail = NULL;  // Atur head dan tail menjadi NULL
        }
        else
        {
            head = head->next; // Geser head ke node berikutnya
        }
        delete hapus;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// fungsi hapus belakang
void hapusBelakang(){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        Node *hapus = tail; // Simpan node yang akan dihapus
        if (head == tail) {  // Jika hanya ada satu node di list
            head = tail = NULL; // Atur head dan tail menjadi NULL
        }else {
            Node *bantu = head; // Variabel bantu untuk traverse list
            while (bantu->next != tail){ // Cari node sebelum tail
                bantu = bantu->next;
            }
            tail = bantu; // Atur tail menjadi node sebelumnya
            tail->next = NULL; // Putuskan hubungan dengan node terakhir
        }
        delete hapus; // Hapus node yang telah disimpan
    }else {
        cout << "List kosong!" << endl;
    }
}

// fungsi hapus tengah
void hapusTengah(int posisi){ 
    if (posisi < 1 || posisi > hitungList()){   //Cek apakah posisi valid
        cout << "Posisi di luar jangkauan" << endl;// Tampilkan pesan jika tidak valid
    }else {
        Node *hapus;
        if (posisi == 1){
            hapus = head;
            head = head->next;
        }else {
            Node *bantu = head; // Variabel bantu untuk traverse list
            for (int i = 1; i < posisi - 1; i++){
                bantu = bantu->next;
            }
            hapus = bantu->next;  // Simpan node yang akan dihapus

            bantu->next = hapus->next; // Hubungkan node sebelumnya dengan node sesudahnya
        }
        delete hapus;
    }
}

void ubahDepan(string nama, string nim){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        head->nama_158 = nama; // Ubah data pada node pertama
        head->nim_158 = nim;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(string nama, string nim){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        tail->nama_158 = nama; // Ubah data pada node terakhir
        tail->nim_158 = nim;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(string nama, string nim, int posisi){
    Node *bantu;
    if (isEmpty() == 0){ // Cek apakah list tidak kosong
        if (posisi < 1 || posisi > hitungList()){// Cek apakah posisi valid
            cout << "Posisi di luar jangkauan" << endl;
        }else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;

        }else {
            bantu = head;
            int nomor = 1;
                while (nomor < posisi){
                    bantu = bantu->next;
                    nomor++;
                }
            bantu->nama_158 = nama; // Ubah data pada node yang ditemukan
            bantu->nim_158 = nim;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void hapusList(){
    Node *bantu, *hapus;
    bantu = head;
        while (bantu != NULL){
            hapus = bantu; // Simpan node yang akan dihapus
            bantu = bantu->next; // Geser ke node berikutnya
            delete hapus; // Hapus node yang telah disimpan
        }
    head = tail = NULL; // Atur head dan tail menjadi NULL
    cout << "List berhasil terhapus!" << endl;
}

void tampilkan(){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        cout << "------------------------------" << endl;
        cout << "| " << setw(15) << left << "Nama" << "| " << setw(9) << left << "NIM" << " |" << endl;
        cout << "------------------------------" << endl;
        Node *bantu = head;
            while (bantu != NULL){
                cout << "| " << setw(15) << left << bantu->nama_158  << "| " << setw(9) << left << bantu->nim_158 << " |" << endl;
                bantu = bantu->next; // Geser ke node berikutnya
            }
        cout << "------------------------------" << endl;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

//fungsi main
int main(){
    init(); // Inisialisasi list

    int operasi;
    string nama;
    string nim;
    int posisi;

    do{
        cout << endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> operasi;

        switch (operasi){
        case 1:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            tambahDepan(nama, nim); // Memanggil fungsi tambahDepan dengan parameter nama dan nim
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            tambahBelakang(nama, nim); // Memanggil fungsi tambahBelakang dengan parameter nama dan nim
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            tambahTengah(nama, nim, posisi);  // Memanggil fungsi tambahTengah dengan parameter nama, nim, dan posisi

            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            ubahDepan(nama, nim); // Memanggil fungsi ubahDepan dengan parameter nama dan nim
            cout << "Nama telah diganti dengan nama " << nama << endl;
            break;
        case 5:
            cout << "Masukkan nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahBelakang(nama, nim); // Memanggil fungsi ubahBelakang dengan parameter nama dan nim
            cout << "Nama telah diganti dengan nama " << nama << endl;
            break;
        case 6:
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            cout << "Masukkan nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahTengah(nama, nim, posisi); // Memanggil fungsi ubahTengah dengan parameter nama, nim, dan posisi
            cout << "Nama telah diganti dengan nama " << nama << endl;
            break;
        case 7:
            hapusDepan(); // Memanggil fungsi hapusDepan
            cout << "Nama berhasil dihapus" << endl;
            break;
        case 8:
            hapusBelakang(); // Memanggil fungsi hapusBelakang
            cout << "Nama berhasil dihapus " << endl;
            break;
        case 9:
            cout << "Masukkan posisi : ";
            cin >> posisi;
            cout << "Masukkan nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            hapusTengah(posisi);  // Memanggil fungsi hapusTengah dengan parameter posisi
            cout << "Nama berhasil dihapus" << endl;
            break;
        case 10:
            hapusList(); // Memanggil fungsi hapusList
            break;
        case 11:
            tampilkan(); // Memanggil fungsi tampilkan
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Operasi tidak valid!" << endl;
        }

    } while (operasi != 0);

    return 0;
}
```
#### Output:
![unguided1](Unguided1(1).png)
![unguided1](Unguided1(2).png)
![unguided1](Unguided1(3).png)

Program di atas merupakan program c++ yang mengimplementasikan Linked list.  Pertama, program mendefinisikan struktur Node yang memiliki dua string nama_158 dan nim_158 sebagai data, serta pointer next yang menunjuk ke simpul berikutnya. Selain itu, program juga menginisialisasi head dan tail menjadi NULL dalam fungsi init(). Kemudian Fungsi isEmpty() digunakan untuk memeriksa apakah linked list kosong. Fungsi-fungsi lainnya seperti tambahDepan(), tambahBelakang(), dan tambahTengah() pada program diatas bertujuan untuk menambahkan simpul baru ke linked list dengan data yang sesuai. Sedangkan fungsi-fungsi penghapusan seperti hapusDepan(), hapusBelakang(), dan hapusTengah() pada program tersebut digunakan untuk menghapus simpul dari linked list. Program diatas  juga menyediakan fungsi-fungsi untuk mengubah data pada simpul tertentu dalam linked list, yaitu ubahDepan(), ubahBelakang(), dan ubahTengah(). Kemudian Fungsi hitungList() digunakan untuk menghitung jumlah simpul dalam linked list. Selanjutnya  Dalam fungsi main(), program menampilkan menu pilihan operasi yang dapat dilakukan kepada pengguna. Pengguna dapat memilih untuk menambah, menghapus, mengubah, atau menampilkan data pada linked list. Loop do-while menjalankan program hingga pengguna memilih untuk keluar dengan menetapkan operasi = 0.



## Kesimpulan
Dengan dilaksankannya praktikum mengenai Linked List Non-Circular dan Circular sangat membantu dalam memberikan pemahaman mendalam dari implementasi struktur data linked list dalam pemrograman[1].

## Referensi
[1] Agung Budi Prasetyo, "Implementasi Circular Linked List Pada Pembuatan Game Permainan Tradisional Congklak".<br/>
[1] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.<br/>