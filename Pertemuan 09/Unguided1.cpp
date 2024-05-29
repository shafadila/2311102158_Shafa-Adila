#include <iostream>
#include <vector>
#include <iomanip> // untuk std::setw

using namespace std;

int main() {
    // Meminta pengguna untuk memasukkan jumlah simpul
    int jmlSimpul_2311102158;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jmlSimpul_2311102158;

    // Mendeklarasikan vektor untuk menyimpan nama simpul
    vector<string> namaSimpul_2311102158(jmlSimpul_2311102158);
    cout << "Silakan masukan nama simpul" << endl;
    // Meminta pengguna untuk memasukkan nama-nama simpul
    for(int i = 0; i < jmlSimpul_2311102158; ++i) {
        cout << "Simpul " << i+1 << " : ";
        cin >> namaSimpul_2311102158[i];
    }

    // Matriks untuk menyimpan bobot antar simpul
    vector<vector<int>> matriksBobot(jmlSimpul_2311102158, vector<int>(jmlSimpul_2311102158));

    // Meminta pengguna untuk memasukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for(int i = 0; i < jmlSimpul_2311102158; ++i) {
        for(int j = 0; j < jmlSimpul_2311102158; ++j) {
            cout << namaSimpul_2311102158[i] << "--> " << namaSimpul_2311102158[j] << " = ";
            cin >> matriksBobot[i][j];
        }
    }

    // Menampilkan matriks bobot
    cout << "\n\t";
    for(int i = 0; i < jmlSimpul_2311102158; ++i) {
        cout << setw(6) << namaSimpul_2311102158[i];
    }
    cout << endl;

    for(int i = 0; i < jmlSimpul_2311102158; ++i) {
        cout << setw(6) << namaSimpul_2311102158[i];
        for(int j = 0; j < jmlSimpul_2311102158; ++j) {
            cout << setw(6) << matriksBobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
