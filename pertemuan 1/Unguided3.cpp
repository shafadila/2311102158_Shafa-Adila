#include <iostream> //Library untuk input-output stream
#include <map> //Library untuk map
using namespace std; //namespace std digunakan agar tidka perlu menuliskan std::

int main() {
    // Membuat map dengan pasangan kunci-nilai bertipe string dan int
    map<string, int> dataMap_shafa158;

    // Memasukkan elemen ke dalam map
    dataMap_shafa158["John"] = 25;
    dataMap_shafa158["Alice"] = 30;
    dataMap_shafa158["Bob"] = 20;

    // Mengakses dan mencetak nilai yang terkait dengan kunci tertentu
    cout << "Umur John: " << dataMap_shafa158["John"] << endl;
    cout << "Umur Alice: " << dataMap_shafa158["Alice"] << endl;
    cout << "Umur Bob: " << dataMap_shafa158["Bob"] << endl;

    return 0;
}
