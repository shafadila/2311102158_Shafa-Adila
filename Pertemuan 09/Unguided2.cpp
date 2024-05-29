#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk merepresentasikan node pada pohon
struct Pohon {
    char data_2311102158;  // Data yang disimpan pada node
    Pohon *left, *right, *parent;  // Pointer ke child kiri, child kanan, dan parent node
};

// Deklarasi global untuk root pohon
Pohon *root = NULL;

// Fungsi untuk inisialisasi pohon
void init() {
    root = NULL;
}

// Fungsi untuk memeriksa apakah pohon kosong
bool isEmpty() {
    return root == NULL;
}

// Fungsi untuk membuat node baru sebagai root
void buatNode(char data) {
    if (isEmpty()) {
        // Jika pohon kosong, buat root baru
        root = new Pohon();
        root->data_2311102158 = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\nTree sudah ada!" << endl;
    }
}

// Fungsi untuk menambahkan node di sebelah kiri suatu node
Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data_2311102158 << " sudah memiliki child kiri!" << endl;
            return NULL;
        } else {
            // Buat node baru dan hubungkan sebagai child kiri
            Pohon* baru = new Pohon();
            baru->data_2311102158 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data_2311102158 << endl;
            return baru;
        }
    }
}

// Fungsi untuk menambahkan node di sebelah kanan suatu node
Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data_2311102158 << " sudah memiliki child kanan!" << endl;
            return NULL;
        } else {
            // Buat node baru dan hubungkan sebagai child kanan
            Pohon* baru = new Pohon();
            baru->data_2311102158 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data_2311102158 << endl;
            return baru;
        }
    }
}

// Fungsi untuk mengupdate data suatu node
void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!" << endl;
        } else {
            char temp = node->data_2311102158;
            node->data_2311102158 = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Fungsi untuk mengambil data suatu node
void retrieve(Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node: " << node->data_2311102158 << endl;
        }
    }
}

// Fungsi untuk mencari informasi suatu node
void find(Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node: " << node->data_2311102158 << endl;
            cout << "Root: " << root->data_2311102158 << endl;
            if (!node->parent) cout << "Parent: (tidak punya parent)" << endl;
            else cout << "Parent: " << node->parent->data_2311102158 << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) cout << "Sibling: " << node->parent->left->data_2311102158 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) cout << "Sibling: " << node->parent->right->data_2311102158 << endl;
            else cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left) cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else cout << "Child Kiri: " << node->left->data_2311102158 << endl;
            if (!node->right) cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else cout << "Child Kanan: " << node->right->data_2311102158 << endl;
        }
    }
}

// Penelusuran preOrder
void preOrder(Pohon* node) {
    if (node != NULL) {
        cout << " " << node->data_2311102158;
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Penelusuran inOrder
void inOrder(Pohon* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data_2311102158;
        inOrder(node->right);
    }
}

// Penelusuran postOrder
void postOrder(Pohon* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data_2311102158;
    }
}

// Fungsi untuk menampilkan child dari suatu node
void tampilkanChild(Pohon* node) {
    if (node) {
        if (node->left) cout << "Child Kiri: " << node->left->data_2311102158 << endl;
        else cout << "Child Kiri: (tidak punya Child kiri)" << endl;
        if (node->right) cout << "Child Kanan: " << node->right->data_2311102158 << endl;
        else cout << "Child Kanan: (tidak punya Child kanan)" << endl;
    } else {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
}

// Fungsi untuk menampilkan descendant dari suatu node
void tampilkanDescendants(Pohon* node) {
    if (node) {
        preOrder(node);
    } else {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
}

// Fungsi untuk mencari node berdasarkan data
Pohon* searchNode(Pohon* node, char data) {
    if (node == NULL || node->data_2311102158 == data) {
        return node;
    }
    Pohon* leftSearch = searchNode(node->left, data);
    if (leftSearch) return leftSearch;
    return searchNode(node->right, data);
}

// Fungsi untuk menghitung ukuran pohon
int size(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Fungsi untuk menghitung total nilai node pada pohon
int totalNodeValue(Pohon* node) {
    if (node == NULL) {
        return 0;
    }
    return (node->data_2311102158 - '0') + totalNodeValue(node->left) + totalNodeValue(node->right);
}

// Fungsi untuk menghitung tinggi pohon
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik pohon
void characteristic() {
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

// Fungsi utama
int main() {
    int pilihan_2311102158;
    char data_2311102158;
    char ParentData_2311102158;
    Pohon* node;

    do {
        cout << "\n========Menu Program Tree========" << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Tambah Child Kiri" << endl;
        cout << "3. Tambah Child Kanan" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Retrieve Node" << endl;
        cout << "6. Find Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Tampilkan Child" << endl;
        cout << "11. Tampilkan Descendant" << endl;
        cout << "12. Characteristic Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Menu: ";
        cin >> pilihan_2311102158;

        switch (pilihan_2311102158) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data_2311102158;
                buatNode(data_2311102158);
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                if (node) {
                    cout << "Masukkan data untuk child kiri: ";
                    cin >> data_2311102158;
                    insertLeft(data_2311102158, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                if (node) {
                    cout << "Masukkan data untuk child kanan: ";
                    cin >> data_2311102158;
                    insertRight(data_2311102158, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 4:
                cout << "Masukkan data node yang akan di-update: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                if (node) {
                    cout << "Masukkan data baru: ";
                    cin >> data_2311102158;
                    update(data_2311102158, node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 5:
                cout << "Masukkan data node yang akan diretrieve: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                retrieve(node);
                break;
            case 6:
                cout << "Masukkan data node yang akan dicari: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                find(node);
                break;
            case 7:
                cout << "\nPreOrder Traversal:" << endl;
                preOrder(root);
                cout << "\n" << endl;
                break;
            case 8:
                cout << "\nInOrder Traversal:" << endl;
                inOrder(root);
                cout << "\n" << endl;
                break;
            case 9:
                cout << "\nPostOrder Traversal:" << endl;
                postOrder(root);
                cout << "\n" << endl;
                break;
            case 10:
                cout << "Masukkan data node yang akan ditampilkan child-nya: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                if (node) {
                    tampilkanChild(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 11:
                cout << "Masukkan data node yang akan ditampilkan descendant-nya: ";
                cin >> ParentData_2311102158;
                node = searchNode(root, ParentData_2311102158);
                if (node) {
                    cout << "Descendants dari node " << ParentData_2311102158 << ": ";
                    tampilkanDescendants(node);
                    cout << endl;
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 12:
                characteristic();
                break;
            case 0:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Opsi tidak valid!" << endl;
                break;
        }
    } while (pilihan_2311102158 != 0);

    return 0;
}
