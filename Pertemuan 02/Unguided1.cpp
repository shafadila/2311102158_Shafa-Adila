#include <iostream> //Library iostream untuk fungsi input-output
using namespace std; //Menggunakan using namespace std agar tidak perlu menuliskan std:: 

int main() {
    const int maksSize = 10; //Mendefinisikan konstanta untuk ukuran maksimum array
    int angka_158[maksSize]; //Mendeklarasikan array untuk menyimpan angka angka yang dimasukkan oleh penggun
    int angkaGanjil_158[maksSize], angkaGenap_158[maksSize]; //Mendeklarasikan array untuk menyimpan angka angka ganjil dan genap
    int jmlGanjil_158 = 0, jmlGenap_158 = 0; //Mendeklarasikan variabel untuk menghitung jumlah angka ganjil dan genap

    // Meminta pengguna untuk menginputkan angka
    cout << "Masukkan " << maksSize << " angka: ";
        for (int i = 0; i < maksSize; ++i) {
        cin >> angka_158[i];
            if (angka_158[i] % 2 == 0) {
                angkaGenap_158[jmlGenap_158] = angka_158[i]; //Menympan angka genap ke dalam array angkaGenap_158
                jmlGenap_158++; //Mengurutkan angka ganjil secara Descending
            } else {
                angkaGanjil_158[jmlGanjil_158] = angka_158[i]; //Menyimpan angka ganjil kedalam array angkaGanjil_158
                jmlGanjil_158++; //Mengurutkan angka ganjil secara Desecending
            }
        }

    // Menampilkan output angka ganjil
    cout << "Angka Ganjil: ";
    for (int i = 0; i < jmlGanjil_158; i++) { //Perulangan untuk mengakses setiap elemen angkaGanjil_158
        cout << angkaGanjil_158[i] << " ";
    }
    cout << endl;

    //Menampilkan output angka genap
    cout << "Angka Genap: ";
    for (int i = 0; i < jmlGenap_158; i++) { //Perulangan untuk mengakses setiap elemen angkaGenap_158
        cout << angkaGenap_158[i] << " ";
    }
    cout << endl;

    return 0;
}
