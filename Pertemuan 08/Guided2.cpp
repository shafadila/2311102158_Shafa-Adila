#include <iostream> // Library untuk input-output stream
#include <conio.h>
#include <iomanip> // Library untuk manipulasi output
using namespace std;

int dataArray[7] = {1,8,2,5,4,9,7}; // Array yang akan diurutkan dan dicari
int cari; // Variabel untuk menyimpan nilai yang ingin dicari

void selection_sort(){ // Fungsi untuk melakukan selection sort
    int temp,min,i,j;
    for(i=0;i<7;i++){ // Looping untuk setiap elemen di array
        min=i; // Menginisialisasi nilai minimum
        for(j=i+1;j<7;j++){ // Looping untuk mencari nilai minimum di sub-array
            if(dataArray[j]<dataArray[min]){ // Jika ditemukan nilai yang lebih kecil
                min=j; // Simpan indeks nilai minimum
            }
        }
        temp=dataArray[i]; // Tukar nilai
        dataArray[i]=dataArray[min];
        dataArray[min]=temp;
    }
}

void binarySearch () { // Fungsi untuk pencarian biner
    int awal,akhir,tengah; // Variabel untuk indeks awal, akhir, dan tengah
    bool b_flag=false; // Flag untuk menandai apakah nilai ditemukan atau tidak
    awal=0; // Inisialisasi indeks awal
    akhir=6; // Inisialisasi indeks akhir (6 karena array berindeks dari 0 hingga 6)
    while(!b_flag&&awal<=akhir){ // Selama nilai belum ditemukan dan masih ada elemen yang belum diperiksa
        tengah=(awal+akhir)/2; // Hitung indeks tengah
        if(dataArray[tengah]==cari){ // Jika nilai ditemukan di tengah
            b_flag=true; // Set flag menjadi true
        }else if(dataArray[tengah]<cari){ // Jika nilai yang dicari lebih besar dari nilai di tengah
            awal=tengah+1; // Ubah indeks awal
        }else{ // Jika nilai yang dicari lebih kecil dari nilai di tengah
            akhir=tengah-1; // Ubah indeks akhir
        }
    }
    if (b_flag) // Jika nilai ditemukan
    {
        cout << "\nData ditemukan pada index ke- " << tengah << endl; // Tampilkan indeks tempat nilai ditemukan
    } else { // Jika nilai tidak ditemukan
        cout << "\nDATA TIDAK DITEMUKAN" << endl; // Tampilkan pesan bahwa nilai tidak ditemukan
    }
}

int main() { // Fungsi utama
    cout << "BINARY SEARCH" << endl; // Tampilkan judul program

    cout << "\nData : "; // Tampilkan pesan untuk data awal

    for (int x = 0; x < 7; x++) // Looping untuk menampilkan data awal
    {
        cout << setw(3) << dataArray[x]; // Tampilkan data dengan lebar 3 karakter
    }
    cout << endl; // Pindah baris

    cout << "Masukkan Data yang ingin dicari : "; // Tampilkan pesan untuk input data yang dicari
    cin >> cari; // Masukkan nilai yang dicari

    cout << "\nData diurutkan: "; // Tampilkan pesan untuk data yang diurutkan
    selection_sort(); // Panggil fungsi untuk mengurutkan data

    for (int x = 0; x < 7; x++) // Looping untuk menampilkan data yang sudah diurutkan
    {
        cout << setw(3) << dataArray[x]; // Tampilkan data dengan lebar 3 karakter
    }
    cout << endl; // Pindah baris
    binarySearch(); // Panggil fungsi untuk melakukan pencarian biner
    _getche(); // Tunggu input sebelum menutup program
    return 0; // Kembalikan nilai 0 untuk menandakan bahwa program berakhir dengan sukses
}
