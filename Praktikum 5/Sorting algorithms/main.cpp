#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void bubble();
void selection();
void insertion();
void shell();
void quick(int rendah, int tinggi);
string mergeSort(string arr);



int partisi(int rendah, int tinggi);
string mergeArr(string kiri, string kanan);
string slice(int start, int over, string arr);
void print(string data);

string nama;
string nim;

int main()
{
    while(true)
    {
        nama = "M. Rizki Dinar";
        nim =  "2410817310020";
        cout<<"By "<<nama<<endl
            <<"-------------------\n"
            <<"|     SORTING     |\n"
            <<"-------------------\n"
            <<"1. Insertion Sort\n"
            <<"2. Merge Sort\n"
            <<"3. Shell Sort\n"
            <<"4. Quick Sort\n"
            <<"5. Bubble Sort\n"
            <<"6. Selection Sort\n"
            <<"7. Exit\n"
            <<"-----------------\n"
            <<"Masukan Pilihan : ";
        int pilih;
        cin>>pilih;

        system("cls");
        switch(pilih){
            case 1:
                insertion();
                break;
            case 2:
                print(mergeSort(nama));
                break;
            case 3:
                shell();
                break;
            case 4:
                quick(0, nim.length()-1);
                print(nim);
                break;
            case 5:
                bubble();
                break;
            case 6:
                selection();
                break;
            default:
                return 0;
        }
        system("pause");
        system("cls");
    }
}

void print(string data){
    cout<<data;
    cout<<"\n";
}

void bubble(){
    for(int i=nim.length()-1; i>0; i--)
    {
        for(int j=nim.length()-1; j>0; j--)
        {
            if(nim[j] < nim[j-1]){
                    swap(nim[j - 1], nim[j]);
            }
        }
    }
    print(nim);
}

// S
void selection(){
    for(int i=0; i<nim.length()-1; i++)
    {
        int sedikit = i;

        for(int j=i; j<nim.length(); j++)
        {
            if(nim[j] != ' ' && nim[j] < nim[sedikit]){
                    sedikit = j;
            }
        }
        swap(nim[i], nim[sedikit]);
    }

    print(nim);
}

void insertion(){
    for(int i=1; i<nama.length(); i++)
    {
        char key = nama[i];
        int j = i - 1;

        while (j >= 0 && nama[j] > key) {
            swap(nama[j+1], nama[j]);
            j -= 1;
        }

        nama[j + 1] = key;
    }
    print(nama);
}

void shell(){
    for (int gap = nama.length()/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < nama.length(); i += 1)
        {
            char temp = nama[i];

            int j;
            for (j = i; j >= gap && nama[j - gap] > temp; j -= gap)
                nama[j] = nama[j - gap];
            nama[j] = temp;
        }
    }
    print(nama);
}

int partisi(int rendah, int tinggi){
    char pivot = nim[tinggi];
    int i = rendah - 1;

    for(int j = rendah; j<=tinggi; j++){
        if(nim[j] < pivot){
            i++;
            swap(nim[i], nim[j]);
        }
    }
    swap(nim[i + 1], nim[tinggi]);
    return i+1;
}

void quick(int rendah, int tinggi){
    if(rendah < tinggi){
        int pivotIdx = partisi(rendah, tinggi);
        quick(rendah, pivotIdx-1);
        quick(pivotIdx+1, tinggi);
    }
}


string mergeSort(string arr){
    if(arr.length() <= 1){
        return arr;
    }

    int mid = arr.length()/2;

    string kiri = arr.substr(0, mid);
    string kanan = arr.substr(mid);
    kiri = mergeSort(kiri);
    kanan = mergeSort(kanan);
    return mergeArr(kiri, kanan);
}

string mergeArr(string kiri, string kanan){
    string namaSorted;

    int i = 0, j = 0, k = 0;

    while (i < kiri.length() && j < kanan.length()) {
        if (kiri[i] <= kanan[j]) {
            namaSorted.push_back(kiri[i]);
            i++;
        }
        else {
            namaSorted.push_back(kanan[j]);
            j++;
        }
        k++;
    }

    string temp;

    temp = kiri.substr(i);
    namaSorted.append(temp);

    temp = kanan.substr(j);
    namaSorted.append(temp);

    return namaSorted;
}
