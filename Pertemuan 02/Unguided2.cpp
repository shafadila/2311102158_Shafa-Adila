#include <iostream> //Library iostream untuk memasukkan header file kedalam program
using namespace std;//using namespace std digunakan agra tidak perlu menggunakan std::

int main() {
    int xSize, ySize, zSize;

    // Meminta pengguna untuk menginputkan ukuran atau jumlah elemen array
    cout << "Masukkan jumlah elemen untuk dimensi x: ";
    cin >> xSize;
    cout << "Masukkan jumlah elemen untuk dimensi y: ";
    cin >> ySize;
    cout << "Masukkan jumlah elemen untuk dimensi z: ";
    cin >> zSize;

    // Deklarasi array sesuai dengan ukuran yang dimasukkan pengguna
    int arr[xSize][ySize][zSize];

    // Input elemen array
    for (int x_158 = 0; x_158 < xSize; x_158++) { //Perulangan unruk mengakses elemen array
        for (int y_158 = 0; y_158 < ySize; y_158++) { //Perulangana untuk mengakses tiap baris array
            for (int z_158 = 0; z_158 < zSize; z_158++) { //Perulangan untuk mengakses tiap elemen dalam baris array
                cout << "Input Array[" << x_158 << "][" << y_158 << "][" << z_158 << "] = ";
                cin >> arr[x_158][y_158][z_158];
            }
        }
        cout << endl;
    }

    // Output elemen array
    for (int x = 0; x < xSize; x++) { //Perulangan untuk mengakses tiap elemen array
        for (int y = 0; y < ySize; y++) { //Perulangan untuk mengakses tiap baris array
            for (int z = 0; z < zSize; z++) { //Perulangan untuk mengakses taip elemen dalam baris array
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    cout << endl;

    // Tampilan array tanpa label
    for (int x = 0; x < xSize; x++) { //Perulangan untuk mengakses tiap elemen array
        for (int y = 0; y < ySize; y++) { //Perulangan untuk mengakses tiap baris array
            for (int z = 0; z < zSize; z++) { //Perulangan untuk mengakses tiap elemen dalam baris array
                cout << arr[x][y][z] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0; //Mengembalikan nilai 0 untuk menandakan berakhirnya program
}
