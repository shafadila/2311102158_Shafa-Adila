#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi; //deklarasi variabel untuk nilai maksimum, panjang array, indeks, dan lokasi nilai maksimum
    cout << "Masukkan panjang array: ";//Meminta pengguna untuk menginputkan panjang array
    cin >> a;
    int array[a]; //Mendeklarasikan sesuai dengan panjang yang telah diinputkan oleh pengguna
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++) //Perulangan untuk memasukkan nilai nilai array
    {
        cout << "Array ke-" << (i) << ": "; //Meminta pengguna untuk menginputkan array ke-i
        cin >> array[i];
    }
    maks = array[0]; //Inialisasi nilai maksimum dengan nilai pertama array
    for (i = 0; i < a; i++) //Perulangan untuk mencari nilai maksimum
    {
        if (array[i] > maks) //Menyeleksi jika array ke-i lebih besar dari nilai maksimum
        {
            maks = array[i]; //Update nilai maksimum dengan nilai array ke-i
            lokasi = i; //Update lokasi nilai maksimum dengan indeks i
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl; //Menampilkan output yang berpa nilai maksimum beserta lokasinya
}