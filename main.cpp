#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Contact {
    string name;
    string phone;
};

vector<Contact> contacts;

void displayMainMenu() {
    cout << "=========BUKU TELEPON=========" << endl;
    cout << "-Home" << endl;
    cout << "\n*------MENU PILIHAN------*" << endl;
    cout << "1. Tampilkan Data Buku Telepon" << endl;
    cout << "2. Cari nama -> telepon" << endl;
    cout << "3. Cari telepon -> nama" << endl;
    cout << "4. Credit (anggota kelompok)" << endl;
    cout << "5. Keluar" << endl;
    cout << "\nMasukan pilihan anda = ";
}

void displayContactList() {
    cout << "=========BUKU TELEPON=========" << endl;
    cout << "-Data Buku Telepon" << endl;
    if (contacts.empty()) {
        cout << "Kosong" << endl;
    } else {
        // Tentukan lebar maksimum untuk kolom "Nama" dan "Telepon"
        size_t maxNameWidth = 0;
        size_t maxPhoneWidth = 0;

        for (const auto& contact : contacts) {
            maxNameWidth = max(maxNameWidth, contact.name.length());
            maxPhoneWidth = max(maxPhoneWidth, contact.phone.length());
        }

        // Tampilkan data dengan lebar kolom yang dinamis
        cout << left << setw(maxNameWidth + 3) << "Nama" << setw(maxPhoneWidth + 3) << "Telepon" << endl;
        cout << setfill('-') << setw(maxNameWidth + maxPhoneWidth + 6) << "" << setfill(' ') << endl;

        for (const auto& contact : contacts) {
            cout << left << setw(maxNameWidth + 3) << contact.name << setw(maxPhoneWidth + 3) << contact.phone << endl;
        }
    }

    cout << "\n1. Tambahkan Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Kembali ke menu awal" << endl;
    cout << "\nPilihan : ";
}

void addContact() {
    Contact newContact;
    cout << "Masukan nama => ";
    // cin >> newContact.name;
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Masukan nomor => ";
    cin >> newContact.phone;
    system("cls");
    contacts.push_back(newContact);
    cout << "\n*Data berhasil dimasukan...\n" << endl;
}

void deleteContact() {
    string nameToDelete;
    cout << "Masukan nama => ";
    // cin >> nameToDelete;
    cin.ignore();
    getline(cin, nameToDelete);

    auto it = find_if(contacts.begin(), contacts.end(), [nameToDelete](const Contact& c) {
        return c.name == nameToDelete;
    });
    system("cls");
    if (it != contacts.end()) {
        contacts.erase(it);
        cout << "\n*Data berhasil dihapus...\n" << endl;
    } else {
        cout << "\n*Data tidak ditemukan...\n" << endl;
    }
}

void searchByName() {
    system("cls");
    string nameToSearch;
    cout << "Masukan nama => ";
    cin.ignore();
    getline(cin, nameToSearch);

    auto it = find_if(contacts.begin(), contacts.end(), [nameToSearch](const Contact& c) {
        return c.name == nameToSearch;
    });
    char searchAgain;
    if (it != contacts.end()) {
        cout << "\n*Data ditemukan..." << endl;
        cout << it->name << " = " << it->phone << endl;

        cout << "\nIngin cari lagi? (y/n) => ";
        cin >> searchAgain;

        if (searchAgain == 'y' || searchAgain == 'Y') {
            searchByName();
        } else {
            // Jika tidak ingin mencari lagi, kembali ke halaman utama
            return;
        }
    } else {
        cout << "\n*Data tidak tersedia..." << endl;

        cout << "\nIngin cari lagi? (y/n) => ";
        cin >> searchAgain;

        if (searchAgain == 'y' || searchAgain == 'Y') {
            searchByName();
        } else {
            // Jika tidak ingin mencari lagi, kembali ke halaman utama
            return;
        }
    }
}


void searchByPhone() {
    system("cls");
    string phoneToSearch;
    cout << "Masukan nomor => ";
    cin >> phoneToSearch;

    auto it = find_if(contacts.begin(), contacts.end(), [phoneToSearch](const Contact& c) {
        return c.phone == phoneToSearch;
    });
    char searchAgain;
    if (it != contacts.end()) {
        cout << "\n*Data ditemukan..." << endl;
        cout << phoneToSearch << " = " << it->name << endl;
        cout << "\nIngin cari lagi? (y/n) => ";
        cin >> searchAgain;

        if (searchAgain == 'y' || searchAgain == 'Y') {
            searchByPhone();
        } else {
            // Jika tidak ingin mencari lagi, kembali ke halaman utama
            return;
        }
    } else {
        cout << "\n*Data tidak tersedia..." << endl;
        cout << "\nIngin cari lagi? (y/n) => ";
        cin >> searchAgain;

        if (searchAgain == 'y' || searchAgain == 'Y') {
            searchByPhone();
        } else {
            // Jika tidak ingin mencari lagi, kembali ke halaman utama
            return;
        }
    }
}

void displayCredit() {
    system("cls");
    cout << "=========BUKU TELEPON=========" << endl;
    cout << "-Credit" << endl;
    cout << "\nAnggota Kelompok 5" << endl;
    cout << "--------------------------" << endl;
    cout << "- YEFTA YOSIA ASYEL\t\t\t220211060372" << endl;
    cout << "- LEANDRO SEVANYA RUMONDOR\t\t220211060298" << endl;
    cout << "- RAFAEL RENALDY RAWUNG\t\t\t220211060299" << endl;
    cout << "- BARCA AZABU SEMBENG\t\t\t220211060311" << endl;
    cout << "- BAYU PRAMANA ZULGIHARTO ABDJUL\t220211060312" << endl;
    cout << "- ANSYE ANGELINA LENSEHE\t\t220211060318" << endl;
    cout << "- FEYKHA NURULILLAH AMALIA KOEM\t\t220211060326" << endl;
    cout << "- MARVELL YEHEZKIEL PALENEWEN\t\t220211060335" << endl;
    cout << "\nLihat source code - Redirect to GitHub (y/n=kembali) ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        const char* url = "https://github.com/yeftakun/Tugas-Database-Tokopedia";
        system(("start \"\" \"" + string(url) + "\"").c_str());
        displayCredit();
    }
}

int main() {
    while (true) {
        system("cls");
        displayMainMenu();

        int choice;
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                while (true) {
                    displayContactList();

                    int subChoice;
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            addContact();
                            break;
                        case 2:
                            deleteContact();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "\n*Pilihan tidak valid. Silakan coba lagi." << endl;
                    }

                    if (subChoice == 3) {
                        break;
                    }
                }
                break;

            case 2:
                searchByName();
                break;

            case 3:
                searchByPhone();
                break;

            case 4:
                displayCredit();
                break;

            case 5:
                cout << "\nTerminate program? (y/n) ";
                char terminateChoice;
                cin >> terminateChoice;
                if (terminateChoice == 'y' || terminateChoice == 'Y') {
                    return 0;
                }
                break;

            default:
                cout << "\n*Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
