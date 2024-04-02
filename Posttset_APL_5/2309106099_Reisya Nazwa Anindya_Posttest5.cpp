#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Pengunjung {
    string nama;
    int nim;
    int umur;
    string alamat;
    string nomor_hp;
    string jenis_ps;
    int jam_awal_peminjaman;
    int lama_peminjaman;
    int jam_pengembalian;
};

vector<Pengunjung> daftarPengunjung;

void tampilkanMenuUtama();
bool loginAdmin();
void tampilkanMenuAdmin();
void tampilkanMenuPengunjung();
void tampilkanBiodata(const Pengunjung &pengunjung);
void tambahPengunjung();
void hapusPengunjung();
void editPengunjung();
void totalTagihan(int index, int total);

void tampilkanMenuUtama() {
    cout << "\nMenu Utama:\n";
    cout << "1. Admin\n";
    cout << "2. Pengunjung\n";
    cout << "3. Keluar\n";
}

bool loginAdmin() {
    string nama, nim;
    int attempt = 0;
    while (attempt < 3) {
        cout << "\nMasukkan nama anda untuk login sebagai Admin:\n";
        cout << "Nama: ";
        cin.ignore(); //untuk membersihkan newline character dari input sebelumnya
        getline(cin, nama);
        cout << "Nim: ";
        getline(cin, nim);
        
        if (nama == "Reisya Nazwa Anindya" && nim == "2309106099") {
            cout << "Login anda berhasil sebagai Admin.\n";
            return true;
        } else {
            cout << "Nama atau Nim anda salah. Silakan dicoba lagi.\n";
            attempt++;
        }
    }
    cout << "Anda telah melebihi batas percobaan login. Kembali ke menu utama.\n";
    return false;
}

void tampilkanMenuAdmin() {
    cout << "\nMenu Admin:\n";
    cout << "1. Lihat Daftar Pengunjung\n";
    cout << "2. Tambah Pengunjung\n";
    cout << "3. Edit Pengunjung\n";
    cout << "4. Hapus Pengunjung\n";
    cout << "5. Keluar\n";
}

void tampilkanMenuPengunjung() {
    cout << "\nMenu Pengunjung:\n";
    cout << "1. Isi Biodata Diri dan Peminjaman\n";
    cout << "2. Lihat Biodata dan Tagihan\n";
    cout << "3. Keluar\n";
}

void tampilkanBiodata(const Pengunjung *pengunjung) {
    cout << "\nBiodata Pengunjung:\n";
    cout << "Nama: " << pengunjung->nama << endl;
    cout << "NIM: " << pengunjung->nim << endl;
    cout << "Umur: " << pengunjung->umur << endl;
    cout << "Alamat: " << pengunjung->alamat << endl;
    cout << "Nomor HP: " << pengunjung->nomor_hp << endl;
    cout << "Jenis Peminjaman PS: " << pengunjung->jenis_ps << endl;
    cout << "Jam Awal Peminjaman: " << pengunjung->jam_awal_peminjaman << endl;
    cout << "Jam Pengembalian: " << pengunjung->jam_pengembalian << endl;
    cout << "Lama Peminjaman: " << pengunjung->lama_peminjaman << " jam" << endl;

    int harga_per_jam;
    if (pengunjung->jenis_ps == "PS3") {
        harga_per_jam = 6000;
    } else if (pengunjung->jenis_ps == "PS4") {
        harga_per_jam = 8000;
    } else if (pengunjung->jenis_ps == "PS5") {
        harga_per_jam = 12000;
    } else {
        cout << "Jenis PS tidak valid untuk pengunjung: " << pengunjung->nama << endl;
        return;
    }

    int tagihan = harga_per_jam * pengunjung->lama_peminjaman;
    cout << "Tagihan: Rp." << tagihan << endl;
}


void tampilkanBiodata(Pengunjung *pengunjung) {
    cout << "\nBiodata Pengunjung:\n";
    cout << "Nama: " << pengunjung->nama << endl;
    cout << "NIM: " << pengunjung->nim << endl;
    cout << "Umur: " << pengunjung->umur << endl;
    cout << "Alamat: " << pengunjung->alamat << endl;
    cout << "Nomor HP: " << pengunjung->nomor_hp << endl;
    cout << "Jenis Peminjaman PS: " << pengunjung->jenis_ps << endl;
    cout << "Jam Awal Peminjaman: " << pengunjung->jam_awal_peminjaman << endl;
    cout << "Jam Pengembalian: " << pengunjung->jam_pengembalian << endl;
    cout << "Lama Peminjaman: " << pengunjung->lama_peminjaman << " jam" << endl;

    int harga_per_jam;
    if (pengunjung->jenis_ps == "PS3") {
        harga_per_jam = 6000;
    } else if (pengunjung->jenis_ps == "PS4") {
        harga_per_jam = 8000;
    } else if (pengunjung->jenis_ps == "PS5") {
        harga_per_jam = 12000;
    } else {
        cout << "Jenis PS tidak valid untuk pengunjung: " << pengunjung->nama << endl;
        return;
    }

    int tagihan = harga_per_jam * pengunjung->lama_peminjaman;
    cout << "Tagihan: Rp." << tagihan << endl;
}

void tambahPengunjung() {
    Pengunjung pengunjungBaru;
    cout << "\nIsi Biodata Diri dan Peminjaman Anda:\n";
    cout << "Nama: ";
    cin.ignore(); // Membersihkan newline karakter dari buffer
    getline(cin, pengunjungBaru.nama);
    cout << "NIM: ";
    while (!(cin >> pengunjungBaru.nim)) {
        cout << "Masukkan NIM dengan benar: ";
        cin.clear(); // Menghapus status kesalahan pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer
    }
    cin.ignore(); // Membersihkan newline karakter dari buffer
    cout << "Umur: ";
    while (!(cin >> pengunjungBaru.umur)) {
        cout << "Masukkan umur dengan benar: ";
        cin.clear(); // Menghapus status kesalahan pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer
    }
    cin.ignore(); // Membersihkan newline karakter dari buffer
    cout << "Alamat: ";
    cin.ignore(); // Membersihkan newline karakter dari buffer
    getline(cin, pengunjungBaru.alamat);
    cout << "Nomor HP: ";
    getline(cin, pengunjungBaru.nomor_hp);
    cout << "Pilih Jenis Peminjaman PS:\n";
    cout << "1. PS3\n";
    cout << "2. PS4\n";
    cout << "3. PS5\n";
    int pilihan;
    cout << "Masukkan pilihan Anda: ";
    while (!(cin >> pilihan) || pilihan < 1 || pilihan > 3) {
        cout << "Pilihan tidak valid. Masukkan kembali: ";
        cin.clear(); // Menghapus status kesalahan pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer
    }
    cin.ignore(); // Membersihkan newline karakter dari buffer
    switch (pilihan) {
        case 1:
            pengunjungBaru.jenis_ps = "PS3";
            break;
        case 2:
            pengunjungBaru.jenis_ps = "PS4";
            break;
        case 3:
            pengunjungBaru.jenis_ps = "PS5";
            break;
    }
    
    cout << "Masukkan jam awal peminjaman: ";
    while (!(cin >> pengunjungBaru.jam_awal_peminjaman) || pengunjungBaru.jam_awal_peminjaman < 0 || pengunjungBaru.jam_awal_peminjaman > 23) {
        cout << "Masukkan jam yang valid (0-23): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Masukkan jam pengembalian: ";
    while (!(cin >> pengunjungBaru.jam_pengembalian) || pengunjungBaru.jam_pengembalian < 0 || pengunjungBaru.jam_pengembalian > 23) {
        cout << "Masukkan jam yang valid (0-23): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Masukkan lama peminjaman (dalam jam) anda: ";
    while (!(cin >> pengunjungBaru.lama_peminjaman)) {
        cout << "Masukkan lama peminjaman dengan benar: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int harga_per_jam;
    if (pengunjungBaru.jenis_ps == "PS3") {
        harga_per_jam = 6000;
    } else if (pengunjungBaru.jenis_ps == "PS4") {
        harga_per_jam = 8000;
    } else if (pengunjungBaru.jenis_ps == "PS5") {
        harga_per_jam = 12000;
    } else {
        cout << "Jenis PS tidak valid.\n";
        return;
    }

    int tagihan = harga_per_jam * pengunjungBaru.lama_peminjaman;
    cout << "Tagihan: Rp." << tagihan << endl;

    daftarPengunjung.push_back(pengunjungBaru);
    cout << "Pengunjung berhasil ditambahkan.\n";
}

void hapusPengunjung() {
    int nim;
    cout << "Masukkan NIM pengunjung yang ingin anda hapus: ";
    cin >> nim;
    bool pengunjungDitemukan = false;
    for (auto it = daftarPengunjung.begin(); it != daftarPengunjung.end(); ++it) {
        if (it->nim == nim) {
            it = daftarPengunjung.erase(it);
            cout << "Pengunjung dengan NIM " << nim << " berhasil dihapus.\n";
            pengunjungDitemukan = true;
            break;
        }
    }
    if (!pengunjungDitemukan) {
        cout << "Pengunjung dengan NIM " << nim << " tidak ditemukan.\n";
    }
}

void editPengunjung() {
    int nim;
    cout << "Masukkan NIM pengunjung yang ingin anda edit: ";
    cin >> nim;
    bool pengunjungDitemukan = false;
    for (auto &pengunjung : daftarPengunjung) {
        if (pengunjung.nim == nim) {
            cout << "\nEdit Biodata Pengunjung:\n";
            cout << "Nama: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, pengunjung.nama);
            cout << "Umur: ";
            cin >> pengunjung.umur;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Alamat: ";
            getline(cin, pengunjung.alamat);
            cout << "Nomor HP: ";
            getline(cin, pengunjung.nomor_hp);
            cout << "Pilih Jenis Peminjaman PS:\n";
            cout << "1. PS3\n";
            cout << "2. PS4\n";
            cout << "3. PS5\n";
            int pilihan;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;
            switch (pilihan) {
                case 1:
                    pengunjung.jenis_ps = "PS3";
                    break;
                case 2:
                    pengunjung.jenis_ps = "PS4";
                    break;
                case 3:
                    pengunjung.jenis_ps = "PS5";
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
                    continue; // Melanjutkan iterasi ke loop
            }

            cout << "Masukkan jam awal peminjaman: ";
            while (!(cin >> pengunjung.jam_awal_peminjaman) || pengunjung.jam_awal_peminjaman < 0 || pengunjung.jam_awal_peminjaman > 23) {
                cout << "Masukkan jam yang valid (0-23): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Masukkan jam pengembalian: ";
            while (!(cin >> pengunjung.jam_pengembalian) || pengunjung.jam_pengembalian < 0 || pengunjung.jam_pengembalian > 23) {
                cout << "Masukkan jam yang valid (0-23): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Masukkan lama peminjaman (dalam jam): ";
            cin >> pengunjung.lama_peminjaman;

            int harga_per_jam;
            if (pengunjung.jenis_ps == "PS3") {
                harga_per_jam = 6000;
            } else if (pengunjung.jenis_ps == "PS4") {
                harga_per_jam = 8000;
            } else if (pengunjung.jenis_ps == "PS5") {
                harga_per_jam = 12000;
            } else {
                cout << "Jenis PS tidak valid.\n";
                return;
            }
            int tagihan = harga_per_jam * pengunjung.lama_peminjaman;
            cout << "Tagihan: Rp." << tagihan << endl;

            cout << "Pengunjung berhasil diedit.\n";
            pengunjungDitemukan = true;
            break;
        }
    }
    if (!pengunjungDitemukan) {
        cout << "Pengunjung dengan NIM " << nim << " tidak ditemukan.\n";
    }
}

void totalTagihan(int index, int total, vector<Pengunjung> &pengunjungVector) {
    if (index == pengunjungVector.size()) {
        cout << "Total Tagihan untuk Semua Pengunjung: Rp." << total << endl;
        return;
    }

    int harga_per_jam;
    if (pengunjungVector[index].jenis_ps == "PS3") {
        harga_per_jam = 6000;
    } else if (pengunjungVector[index].jenis_ps == "PS4") {
        harga_per_jam = 8000;
    } else if (pengunjungVector[index].jenis_ps == "PS5") {
        harga_per_jam = 12000;
    } else {
        cout << "Jenis PS tidak valid untuk pengunjung: " << pengunjungVector[index].nama << endl;
        totalTagihan(index + 1, total, pengunjungVector);
        return;
    }

    int tagihan = harga_per_jam * pengunjungVector[index].lama_peminjaman;
    total += tagihan;
    totalTagihan(index + 1, total, pengunjungVector);
}

bool validasiJenisPS(const string &jenis) {
    return (jenis == "PS3" || jenis == "PS4" || jenis == "PS5");
}

int main() {
    bool isAdmin = false;
    while (true) {
        tampilkanMenuUtama();
        int pilihanUtama;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihanUtama;

        switch (pilihanUtama) {
            case 1: {
                if (!isAdmin) {
                    isAdmin = loginAdmin();
                    if (!isAdmin)
                        break; // Kembali ke menu utama jika gagal login sebagai admin
                }

                while (true) {
                    tampilkanMenuAdmin();
                    int pilihanAdmin;
                    cout << "Masukkan pilihan Anda: ";
                    cin >> pilihanAdmin;

                    switch (pilihanAdmin) {
                        case 1:
                            cout << "\nDaftar Pengunjung:\n";
                            for (const auto &pengunjung : daftarPengunjung) {
                                tampilkanBiodata(&pengunjung);
                            }
                            break;
                        case 2:
                            tambahPengunjung();
                            break;
                        case 3:
                            editPengunjung();
                            break;
                        case 4:
                            hapusPengunjung();
                            break;
                        case 5:
                            cout << "Keluar dari Menu Admin.\n";
                            break;
                        default:
                            cout << "Pilihan anda tidak valid.\n";
                            break;
                    }

                    if (pilihanAdmin == 5) {
                        isAdmin = false; 
                        break;
                    }
                }
                break;
            }
            case 2: {
                while (true) {
                    tampilkanMenuPengunjung();
                    int pilihanPengunjung;
                    cout << "Masukkan pilihan Anda: ";
                    cin >> pilihanPengunjung;

                    switch (pilihanPengunjung) {
                        case 1:
                            tambahPengunjung();
                            break;
                        case 2:
                            cout << "\nBiodata dan Tagihan:\n";
                            for (const auto &pengunjung : daftarPengunjung) {
                                tampilkanBiodata(&pengunjung);
                            }
                            break;
                        case 3:
                            cout << "Keluar dari Menu Pengunjung.\n";
                            break;
                        default:
                            cout << "Pilihan anda tidak valid.\n";
                            break;
                    }

                    if (pilihanPengunjung == 3) {
                        break;
                    }
                }
                break;
            }
            case 3:
                totalTagihan(0, 0, daftarPengunjung); // memanggil fungsi rekursif untuk menampilkan total tagihan
                cout << "Terima kasih kawan! dan Sampai jumpa lagi.\n";
                return 0;
            default:
                cout << "Pilihan anda tidak valid.\n";
                break;
        }
    }

    return 0;
} 
