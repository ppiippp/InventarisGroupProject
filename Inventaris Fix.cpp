#include <iostream>
#include <string>
#include <fstream> // Untuk melakukan system("cls")

using namespace std;

const int MAX_ITEMS = 100;

string temp;

struct InventoryItem {
    string name;
    double price;
    int quantity;
};

// Fungsi untuk menampilkan banner
void banner(){
    system("cls");
    cout << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.    .--.      .-'. " << endl;
    cout << ":::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::.\\::::::::.\\" << endl;
    cout << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `'      `--'      `" << endl;
    cout << "  _____                                       _____                      _             _     " << endl;
    cout << " |  __ \\                                     |_   _|                    | |           (_)    " << endl;
    cout << " | |__) | __ ___   __ _ _ __ __ _ _ __ ___     | |  _ ____   _____ _ __ | |_ __ _ _ __ _ ___ " << endl;
    cout << " |  ___/ '__/ _ \\ / _` | '__/ _` | '_ ` _ \\    | | | '_ \\ \\ / / _ \\ '_ \\| __/ _` | '__| / __|" << endl;
    cout << " | |   | | | (_) | (_| | | | (_| | | | | | |  _| |_| | | \\ V /  __/ | | | || (_| | |  | \\__ \\" << endl;
    cout << " |_|   |_|  \\___/ \\__, |_|  \\__,_|_| |_| |_| |_____|_| |_|\\_/ \\___|_| |_|\\__\\__,_|_|  |_|___/" << endl;
    cout << "                   __/ |                                                                     " << endl;
    cout << "                  |___/                                                                      " << endl;
    cout << "  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.    .--.      .-'. " << endl;
    cout << ":::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::::.\\::::::.\\::::::::.\\" << endl;
    cout << "'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `'      `--'      `" << endl;
}

// Fungsi untuk meminta user menekan Enter untuk melanjutkan
void pressEnterToContinue() {
    cout << "====================================================" << endl;
    cout << "Tekan ENTER untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// Fungsi untuk menampilkan informasi item
void displayItemInfo(const InventoryItem& item) {
    cout << "Informasi Item:" << endl;
    cout << "Nama: " << item.name << endl;
    cout << "Harga: " << item.price << endl;
    cout << "Jumlah: " << item.quantity << endl;
}

// Fungsi untuk menampilkan daftar item
void displayInventory(const InventoryItem inventory[], int size) {
    cout << "Daftar Inventaris:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "[" << i + 1 << "] "
             << "Nama: " << inventory[i].name << ", Harga: " << inventory[i].price << ", Jumlah: " << inventory[i].quantity << endl;
    }
}

// Fungsi untuk menambahkan item ke dalam inventaris
void addItem(InventoryItem inventory[], int& size) {
    if (size < MAX_ITEMS) {
        cout << "Masukkan nama barang: ";
        cin >> inventory[size].name;
        cout << "Masukkan harga barang: ";
        cin >> inventory[size].price;
        cout << "Masukkan jumlah barang: ";
        cin >> inventory[size].quantity;
        size++;
        cout << "Barang berhasil ditambahkan ke inventaris." << endl;
    } else {
        cout << "Inventaris penuh, tidak dapat menambahkan barang baru." << endl;
        
    }
}

// Fungsi untuk mengurutkan item berdasarkan harga (bubble sort)
void sortInventoryByPrice(InventoryItem inventory[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (inventory[j].price > inventory[j + 1].price) {
                // Tukar posisi jika harga lebih tinggi
                swap(inventory[j], inventory[j + 1]);
            }
        }
    }
    cout << "Inventaris diurutkan berdasarkan harga." << endl;
    
}

// Fungsi untuk mencari item berdasarkan nama
int searchInventoryByName(const InventoryItem inventory[], int size, const string& name) {
    for (int i = 0; i < size; ++i) {
        if (inventory[i].name == name) {
            return i;
        }
    }
    return -1; // Tidak ditemukan
}

// Fungsi untuk mengurangi jumlah item tertentu
void reduceItemQuantity(InventoryItem& item, int amount) {
    if (amount >= 0 && amount <= item.quantity) {
        item.quantity -= amount;
        cout << "Jumlah barang berhasil dikurangi." << endl;
    } else {
        cout << "Jumlah yang diminta tidak valid atau melebihi stok barang." << endl;
    }
}

int main() {
    InventoryItem inventory[MAX_ITEMS];
    int inventorySize = 0;

    int choice;
    do {
    	banner();
        cout << "MENU :" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Lihat Daftar Barang (diurutkan berdasarkan harga)" << endl;
        cout << "3. Cari dan Kelola Barang" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(inventory, inventorySize);
                pressEnterToContinue();
                break;
            case 2:
                sortInventoryByPrice(inventory, inventorySize);
                displayInventory(inventory, inventorySize);
                pressEnterToContinue();
                break;
            case 3: {
                string searchItemName;
                cout << "Masukkan nama barang yang ingin dicari: ";
                cin >> searchItemName;

                int foundIndex = searchInventoryByName(inventory, inventorySize, searchItemName);

                if (foundIndex != -1) {
                    displayItemInfo(inventory[foundIndex]);

                    int reduceAmount;
                    cout << "Masukkan jumlah barang yang ingin dikurangi: ";
                    cin >> reduceAmount;

                    reduceItemQuantity(inventory[foundIndex], reduceAmount);
                } else {
                    cout << "Barang tidak ditemukan dalam inventaris." << endl;
                }
                pressEnterToContinue();
                break;
            }
            case 4:
                cout << "Program selesai." << endl;
                pressEnterToContinue();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}

