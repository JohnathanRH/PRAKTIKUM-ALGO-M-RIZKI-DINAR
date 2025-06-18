#include <iostream>

using namespace std;

int maks = 5;

struct Stack {
    int atas;
    int data[5];
} Tumpuk;

int penuh()
    {
        if(Tumpuk.atas == maks){return 1;}
        else{return 0;}
    }

int kosong()
{
    if(Tumpuk.atas <= 0){return 1;}
    else{return 0;}
}

void input (int data)
{
    if(kosong()==1)
    {
        Tumpuk.data[Tumpuk.atas] = data;
        Tumpuk.atas++;
        cout << "Data "<< Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack \n";
    }
    else if(penuh() == 0)
    {
        Tumpuk.data[Tumpuk.atas] = data;
        Tumpuk.atas++;
        cout << "Data "<< Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack \n";
    }
    else{cout << "Tumpukan penuh";}
}

void hapus()
{
    if(kosong()== 0)
    {
        Tumpuk.data[Tumpuk.atas] = NULL;
        cout << "Data Teratas sudah terambil\n";
        Tumpuk.atas--;
    }
    else cout<<" Data Kosong";
}

void tampil()
{
    if(kosong()== 0)
    {
        for(int i = Tumpuk.atas-1; i>=0; i--)
        {
            cout<<"\nTumpukan Ke "<< i << " = "
            <<Tumpuk.data[i];
        }
        cout<<endl;
    }
    else{cout<<"Tumpukan Kosong\n";}
}

void bersih ()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

int main()
{
    int user_input;
    bool running = true;
    while(running)
    {
        tampil();
        cout<<"Input atau masukan 1212 untuk menghapus: ";
        cin>>user_input;
        system("cls");
        if(user_input == 1212)
        {
            hapus();
            continue;
        }
        input(user_input);
    }
}
