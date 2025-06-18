#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 5
using namespace std;

char Q[n];
int PIL, F, R;

void RESET()
{
    fill_n(Q, n, 0);
    F = 0;
    R = -1;
}

bool isFull()
{
    if((R+1 == F && R!=-1) || (F==0 && R==4)){return true;}
    else{return false;}
}

bool isEmpty()
{
    if(R==-1){return true;}
    else{return false;}
}

void INSERT()
{
    if(isFull()){cout<<"Queue full";}
    else
    {
        R++;
        if(R>= n){R=0;}
        char data;
        system("cls");
        cout<<"Masukan data: ";cin>>data;
        Q[R] = data;
    }
}

void DELETE()
{
    if(isEmpty()){cout<<"Queue kosong";}
    else
    {
        if(F>= n){F=0;}
        Q[F]= NULL;
        if(F==R){RESET();}
        else{F++;}
    }
}

void CETAKLAYAR()
{
    for(int i = 0; i != n; i++)
    {
        if(i>= n){i=0;}
        cout<<"Data ke "<<i<<" = "<<Q[i]<<endl;
    }
}
void inisialisasi()
{
    F = 0;
    R = -1;
}
char PILIHAN [1], HURUF;

int main()
{
    inisialisasi();
    do
    {
        cout<<"QUEUE"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. QUIT"<<endl;
        cout<<"PILIHAN : "<<endl; cin>> PILIHAN;
        PIL=atoi(PILIHAN);

        switch(PIL)
        {
        case 1:
            INSERT();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR();
            break;
        default:
            cout<<"TERIMA KASIH"<<endl;
            break;
        }
        cout<<"press any key to continue"<<endl;
        getch();
        system("cls");
    }
    while (PIL<4);
}
