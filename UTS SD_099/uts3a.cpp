
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    float persentase;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertTail() {
    Node* baru = new Node;

    cout << "Nama : ";
    cin >> baru->nama;

    cout << "Persentase (%) : ";
    cin >> baru->persentase;

    baru->next = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void deleteHead() {
    if (head == NULL) return;

    Node* hapus = head;
    head = head->next;

    if (head == NULL) tail = NULL;

    delete hapus;
}

void deleteTail() {
    if (head == NULL) return;

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* bantu = head;

    while (bantu->next != tail) {
        bantu = bantu->next;
    }

    delete tail;
    tail = bantu;
    tail->next = NULL;
}

void tampilkan() {
    Node* bantu = head;

    while (bantu != NULL) {
        if (bantu->persentase < 80) {
            cout << "\nNama : " << bantu->nama;
            cout << "\nStatus : Tidak Layak Ujian\n";
        }

        bantu = bantu->next;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n MENU KEHADIRAN MAHASISWA\n";
        cout << "1. Insert Tail\n";
        cout << "2. Delete Head\n";
        cout << "3. Delete Tail\n";
        cout << "4. Tampilkan Mahasiswa Tidak Layak Ujian\n";
        cout << "Pilihan : ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: insertTail(); break;
            case 2: deleteHead(); break;
            case 3: deleteTail(); break;
            case 4: tampilkan(); break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}
