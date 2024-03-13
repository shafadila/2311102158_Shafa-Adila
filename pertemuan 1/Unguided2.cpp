#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struct untuk data mahasiswa
struct MahasiswaData {
    string nama_shafa158;
    string jurusan_shafa158;
    string NIM_shafa158;
};

// Mendefinisikan class Mahasiswa
class Mahasiswa {
private:
    MahasiswaData data; // Objek MahasiswaData sebagai atribut private

public:
    // Constructor untuk class Mahasiswa
    Mahasiswa(string nama, string jurusan, string NIM) {
        data.nama_shafa158 = nama;
        data.jurusan_shafa158 = jurusan;
        data.NIM_shafa158 = NIM;
    }

    // Prosedur untuk menampilkan data mahasiswa
    void tampilkanData() {
        cout << "Data Mahasiswa" << endl;
        cout << "Nama : " << data.nama_shafa158 << endl;
        cout << "NIM : " << data.NIM_shafa158 << endl;
        cout << "Jurusan : " << data.jurusan_shafa158 << endl;
    }

    // Metode untuk mengambil data mahasiswa
    MahasiswaData getData() {
        return data;
    }

    // Metode untuk mengatur data mahasiswa
    void setData(string nama, string jurusan, string NIM) {
        data.nama_shafa158 = nama;
        data.jurusan_shafa158 = jurusan;
        data.NIM_shafa158 = NIM;
    }
};

int main() {
    // Membuat objek mhs dari class Mahasiswa dengan data yang telah ditentukan
    Mahasiswa mhs("Shafa Adila Santoso", "Teknik Informatika", "2311102158");

    // Memanggil prosedur tampilkanData untuk menampilkan data mahasiswa pada output
    mhs.tampilkanData();

    return 0;
}
