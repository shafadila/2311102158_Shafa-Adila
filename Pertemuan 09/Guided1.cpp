#include <iostream>
#include <iomanip>

using namespace std;

// Array nama kota (simpul)
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

// Matriks adjacency yang mewakili bobot busur antara simpul
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 7, 0, 3, 0},
    {0, 0, 0, 9, 4, 0, 0}
};

// Fungsi untuk menampilkan graph
void tampilGraph(){
    for(int baris = 0; baris < 7; baris++){
        // Cetak nama simpul
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++){
            // Jika ada busur, cetak simpul yang terhubung dan bobotnya
            if (busur[baris][kolom] != 0){
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main(){
    // Panggil fungsi untuk menampilkan graph
    tampilGraph();
    return 0;
}
