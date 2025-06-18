#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void binary();
void sequential();
void penjelasan();

int main()
{
    while(true)
    {

        system("cls");
        int pilih;
        cout<<"Pilih menu\n"
            <<"1. Sequential Searching\n"
            <<"2. Binary Searching\n"
            <<"3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n"
            <<"4. Exit\n"
            <<"Pilih : ";
        cin>>pilih;
        system("cls");
        switch(pilih)
        {
            case 1:
                sequential();
                break;
            case 2:
                binary();
                break;
            case 3:
                penjelasan();
                break;
            default:
                return 0;
        }
    }


}

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void sequential()
{
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . . \n");
    for(int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
    }
    printf("\ndone.\n");

    for(int i = 0; i<100; i++)
    {
        if(data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if(flag == 1)
    {
        printf("Data ada, sebanyak %d\n", counter);
        printf("Pada indeks ke-%d", save);
    }
    else
    {
        printf("Data tidak ada!");
    }
    cout<<endl;
    system("pause");
}

void binary()
{
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout<<"Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Angka ke - ["<<i<<"] : ";
        cin >> angka[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "==============================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for(int i = 0; i<n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n==============================================================\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n-1;
    while(kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if(key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }
    if(ketemu == true)
    {
        cout << "Angka ditemukan! ";
    }
    else
    {
        cout << "Angka tidak ditemukan!\n";
    }
    system("pause");
}

void penjelasan()
{
    cout<<"-- Perbedaan Sequential dan Binary Searching --\n"
        <<"Sequential Search mencari elemen dengan cara membandingkan\n"
        <<"Elemen patokan dengan semua elemen yang ada di dalam array.\n\n";

    cout<<"Binary Searching mencari elemen dilakukan terhadap suatu array\n"
        <<"Yang sudah di sorting sehingga memerlukan algoritma sorting. Untuk\n"
        <<"Proses pencarian nya sendiri dilakukan dengan membelah array memilih\n"
        <<"Belahan yang mendekati elemen patokan.\n\n";

    cout<<"-- Kelebihan dan Kekurangan --\n"
        <<"SEQUENTIAL SEARCH\n"
        <<"+ Simplisitas\n"
        <<"+ Sesuai untuk data sedikit\n"
        <<"- Lambat jika data banyak O(N^2)\n\n";

    cout<<"BINARY SEARCH\n"
        <<"+ Efisien dan Cepat O(Log N)\n"
        <<"+ Cocok untuk data banyak\n"
        <<"- Kompleks, memerlukan algoritma sorting\n";

    system("pause");
}
