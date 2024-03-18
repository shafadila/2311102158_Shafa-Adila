#include <iostream> // Library untuk input-output
using namespace std; // Menggunakan namespace std agar tidak perlu menuliskan std:: sebelum cin, cout, dll.

int main() {
    int size;

    // Meminta pengguna untuk memasukkan ukuran atau jumlah elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> size;

    // Deklarasi array sesuai dengan ukuran yang dimasukkan pengguna
    int arr[size];

    // Meminta pengguna untuk memasukkan elemen-elemen array
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i_158 = 0; i_158 < size; i_158++) {
        cout << "Elemen ke-" << i_158 + 1 << ": ";
        cin >> arr[i_158];
    }

    // Menu
    do{
        cout << endl;
        int pilihan;
        cout << "Pilih operasi yang ingin dilakukan:" << endl;
        cout << "1. Cari Nilai Maksimum" << endl;
        cout << "2. Cari Nilai Minimum" << endl;
        cout << "3. Cari Nilai Rata-rata" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: // Cari nilai maksimum
            {
                int max = arr[0];
                for (int i_158 = 1; i_158 < size; i_158++) {
                    if (arr[i_158] > max) {
                        max = arr[i_158];
                    }
                }
                cout << "Nilai Maksimum: " << max << endl;
                break;
            }
            case 2: // Cari nilai minimum
            {
                int min = arr[0];
                for (int i_158 = 1; i_158 < size; i_158++) {
                    if (arr[i_158] < min) {
                        min = arr[i_158];
                    }
                }
                cout << "Nilai Minimum: " << min << endl;
                break;
            }
            case 3: // Cari nilai rata-rata
            {
                int total = 0;
                for (int i_158 = 0; i_158 < size; i_158++) {
                    total += arr[i_158];
                }
                double average = static_cast<double>(total) / size;
                cout << "Nilai Rata-rata: " << average << endl;
                break;
            }
            default: // Pilihan tidak valid

                cout << "Pilihan tidak valid!" << endl;
        }
    }while (true);

    return 0; // Mengembalikan nilai 0 untuk menandakan bahwa program berakhir dengan sukses
}
