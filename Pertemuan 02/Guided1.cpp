#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{

    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++) //Perulanan untuk matriks ke-2
    {
        for (int y = 0; y < 3; y++) //Perulangan untuk baris
        {
            for (int z = 0; z < 3; z++) //Perulangan untuk kolom
            {
                cout << "Input Array[" << x << "][" << y << "][" <<
z << "] = ";
        cin >> arr[x][y][z]; //Meminta pengguna untuk menginputkan nilai array
        }
    }
    cout << endl;
  }
    // Output Array
    for (int x = 0; x < 2; x++) //Perulangan untuk matriks ke-2
    {
        for (int y = 0; y < 3; y++) //Perulangan untuk baris
        {
            for (int z = 0; z < 3; z++) //Perulangan untuk kolom
            {
                cout << "Data Array[" << x << "][" << y << "][" << z
<< "] = " << arr[x][y][z] << endl; //Menampilkan nilai array
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++) //Perulangan untuk matriks ke-2
    {
        for (int y = 0; y < 3; y++) //Perulangan untuk baris
        {
            for (int z = 0; z < 3; z++) //Perulangan untuk kolom
            {
                cout << arr[x][y][z] << ends; 
            }
            cout << endl;
        }
        cout << endl;
    }
}
