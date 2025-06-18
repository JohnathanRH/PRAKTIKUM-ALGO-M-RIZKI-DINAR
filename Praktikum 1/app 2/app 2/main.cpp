#include <iostream>

using namespace std;

struct group {
    char huruf;
    string kata;
    int angka;
} var_group;

int main()
{
    // Input
    cout << "Masukan sebuah huruf=";
    cin>>var_group.huruf;
    cout<<"Masukan sebuah kata=";
    cin>>var_group.kata;
    cout<<"Masukan sebuah angka=";
    cin>>var_group.angka;
    cout<<"Huruf yang anda masukan adalah "<<var_group.huruf<<endl;
    cout<<"Kata yang anda masukan adalah "<<var_group.kata<<endl;
    cout<<"Angka yang anda masukan adalah "<<var_group.angka<<endl;
    return 0;
}
