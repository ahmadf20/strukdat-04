/*
Nama program 	: Program Input Pegawai
Nama			: Ahmad Faaiz Al-auza'i
NPM				: 140810180023
Tanggal dibuat	: 19/03/2019
***********************************************/

#include <iostream>
#include <iomanip>
using namespace std;

struct ElemtList {              
    string Nama;
    string bidang;
    long int gaji;
    ElemtList* next;            
};

typedef ElemtList* pointer;         
typedef pointer List;  

void createList(List& First){
    First = NULL;
}

void createElemt (pointer& pBaru){
    pBaru = new ElemtList;
    cin.ignore();
    cout << "NAMA   : "; getline(cin, pBaru->Nama);
    cout << "BIDANG : "; getline(cin, pBaru->bidang);
    cout << "GAJI    : "; cin >> pBaru->gaji;
    pBaru->next = NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First == NULL){
        First = pBaru; 
    } else {
        pBaru->next = First;
        First = pBaru;
    }
}

void insertLast(List& First, pointer pBaru){
    pointer last;
    
    if (First == NULL){            
        First = pBaru;
    } else {                        
        last = First;               
        while(last->next != NULL){
            last = last->next;
        }
        last->next=pBaru;          
    }
}

void traversal (List First){
    pointer pBantu;
    pBantu = First;
    if (pBantu == NULL) {
        cout << "DATA KOSONG!" << endl;        
    } else {
        cout << "---------------------------------------------" << endl;
        cout << left << setw(15) << "NAMA" << setw(15) << "BIDANG" << "GAJI" << endl;
        cout << "---------------------------------------------" << endl;
        while(pBantu != NULL){
            cout << left << setw(15) << pBantu->Nama << setw(15) << pBantu->bidang << "Rp." << pBantu->gaji << endl;
            pBantu = pBantu->next;
        }
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First == NULL){
        pHapus = NULL;
        cout << "BELUM ADA DATA!" << endl;
    } else if (First->next == NULL){
        pHapus = First;
        First = NULL;
    } else {
        pHapus = First;
        First = First->next;
        pHapus->next=NULL;
    }
}

void deleleteLast(List& First, pointer& pHapus){
    pointer last, precLast;
    if (First == NULL){
        pHapus=NULL;
        cout << "BELUM ADA DATA!" << endl;
    } else if (First->next == NULL){
        pHapus = First;
        First = NULL;
    } else {
        last = First;
        precLast = NULL;
        while(last->next!=NULL){
            precLast = last;
            last = last->next;
        }
        pHapus=last;
        precLast->next = NULL;
    }
}

int main(){
    pointer p;
    List currentList;

    createList(currentList);

    int menu;
    while(1){
        system("CLS");
        cout << "--------------------------------------------------" << endl;
        cout << "PROGRAM INPUT DATA KARYAWAN PT PADJADJARAN BANDUNG" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "MENU : " << endl;
        cout << "1. INSERT FIRST" << endl;
        cout << "2. INSERT LAST" << endl;
        cout << "3. PRINT DATA" << endl;
        cout << "4. DELETE FIRST DATA " << endl;
        cout << "5. DELETE LAST DATA" << endl;
        cout << "6. EXIT" << endl;
        
        cout << "MASUKKAN MENU : "; cin >> menu;
        switch (menu)
        {
            case 1:
                system("CLS");
                cout << "MENAMBAHKAN DATA DI AWAL" << endl;
                createElemt(p);
                insertFirst(currentList, p);
                system("PAUSE");
                break;
            case 2:
                system("CLS");
                cout << "MENAMBAHKAN DATA DI AKHIR" << endl;
                createElemt(p);
                insertLast(currentList, p);
                system("PAUSE");
                break;
            case 3:
                system("CLS");
                cout << "CETAK DATA" << endl;
                traversal(currentList);
                system("PAUSE");
                break;
            case 4:
                system("CLS");
                deleteFirst(currentList, p);
                cout << "DATA AWAL BERHASIL DIHAPUS!" << endl;
                system("PAUSE");
                break;
            case 5:
                system("CLS");
                deleleteLast(currentList, p);
                cout << "DATA AKHIR BERHASIL DIHAPUS!" << endl;
                system("PAUSE");
                break;
            case 6:
                return 0;

            default:
            system("CLS");
            cout << "MENU TIDAK TERSEDIA!" << endl << endl;
            system("PAUSE");
            break;
        }
    }
}