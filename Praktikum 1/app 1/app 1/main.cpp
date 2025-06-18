#include <iostream>

using namespace std;

struct pemilik {
    string nama, alamat, kota;
};

struct transportasi {
    string plat, jenis;
    pemilik pemegang;
} kendaraan;

int main()
{
    // Input data
    cout<<"Nama pemilik : ";
    getline(cin, kendaraan.pemegang.nama);
    cout<<"Alamat : ";
    getline(cin, kendaraan.pemegang.alamat);
    cout<<"Kota : ";
    getline(cin, kendaraan.pemegang.kota);
    cout<<"\n\n";
    cout<<"Jenis kendaraan : ";
    getline(cin, kendaraan.jenis);
    cout<<"Plat kendaraan : ";
    getline(cin, kendaraan.plat);
    system("cls");

    cout<<"Plat Nomor Kendaraan : "<<kendaraan.plat
        <<"\nJenis Kendaraan : "<<kendaraan.jenis
        <<"\nNama Pemilik : "<<kendaraan.pemegang.nama
        <<"\nAlamat : "<<kendaraan.pemegang.alamat
        <<"\nKota : "<<kendaraan.pemegang.kota
        <<endl;
    return 0;
}
