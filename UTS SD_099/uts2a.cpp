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
    cin >> ws;
    getline(cin, baru->nama);

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
    if (head == NULL) {
        return;
    }

    Node* hapus = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete hapus;
}

void deleteTail() {
    if (head == NULL) {
        return;
    }

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
            cout << "Nama : " << bantu->nama << endl;
            cout << "Status : Tidak Layak Ujian" << endl;
        }

        bantu = bantu->next;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nPilih menu (1 - 4)" << endl;
        cout << "1. Insert tail" << endl;
        cout << "2. Delete head" << endl;
        cout << "3. Delete tail" << endl;
        cout << "4. Tampilkan Mahasiswa Tidak Layak Ujian" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                insertTail();
                break;

            case 2:
                deleteHead();
                break;

            case 3:
                deleteTail();
                break;

            case 4:
                tampilkan();
                break;

            default:
                break;
        }

    } while (pilihan != 4);

    return 0;
}
