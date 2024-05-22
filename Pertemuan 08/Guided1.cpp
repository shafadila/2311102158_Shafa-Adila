#include <iostream>
using namespace std;

int main(){
    int n = 10; // Mendefinisikan ukuran array
    int data[n] = {9,4,1,7,5,12,4,13,4,10}; // Inisialisasi array dengan data
    int cari = 10; // Angka yang akan dicari
    bool ketemu = false; // Variabel penanda apakah angka ditemukan
    int i; // Variabel untuk iterasi dalam loop

    //Algoritma Sequential Search
    for ( i=0; i<n; i++ ) {
        if (data[i] == cari) {
            ketemu = true;
            break; // Jika nilai ditemukan, keluar dari loop
        }
    }

    // Menampilkan output
    cout<<"\tProgram Sequential Search Sederhana\n"<<endl;
    cout<<"data:{9,4,1,7,5,12,4,13,4,10}"<<endl;
    if(ketemu){
        cout<<"\nAngka"<<cari<<"ditemukanpadaindekske-"<<i<<endl;
    }else{
        cout << cari << " tidak dapat ditemukan pada data." <<endl;
    }
    return 0;
 }