#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

// Menampilkan isi linked list
void tampilkan(Node* head) {
    Node* bantu = head;

    cout << "Isi Linked List: ";

    while (bantu != nullptr) {
        cout << bantu->nilai << " ";
        bantu = bantu->next;
    }

    cout << endl;
}

// Tambah node di depan
void tambahDepan(Node*& head, int nilai) {
    Node* baru = new Node();

    baru->nilai = nilai;
    baru->next = head;

    head = baru;
}

// Tambah node di belakang
void tambahBelakang(Node*& head, int nilai) {
    Node* baru = new Node();

    baru->nilai = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } 
    else {
        Node* bantu = head;

        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }
}

// Tambah node setelah nilai tertentu
void tambahSetelah(Node* head, int nilaiCari, int nilaiBaru) {
    Node* bantu = head;

    while (bantu != nullptr && bantu->nilai != nilaiCari) {
        bantu = bantu->next;
    }

    if (bantu != nullptr) {
        Node* baru = new Node();

        baru->nilai = nilaiBaru;
        baru->next = bantu->next;

        bantu->next = baru;
    } 
    else {
        cout << "Nilai tidak ditemukan." << endl;
    }
}

// Hapus node berdasarkan nilai
void hapusNode(Node*& head, int nilaiCari) {

    if (head == nullptr) {
        cout << "Linked List kosong." << endl;
        return;
    }

    // Jika yang dihapus adalah head
    if (head->nilai == nilaiCari) {
        Node* hapus = head;
        head = head->next;

        delete hapus;
        return;
    }

    Node* bantu = head;

    while (bantu->next != nullptr &&
           bantu->next->nilai != nilaiCari) {
        bantu = bantu->next;
    }

    if (bantu->next != nullptr) {
        Node* hapus = bantu->next;

        bantu->next = hapus->next;

        delete hapus;
    } 
    else {
        cout << "Nilai tidak ditemukan." << endl;
    }
}


int main() {

    Node* head = nullptr;

    // ==========================================
    // MEMASUKKAN 10 NILAI MAHASISWA
    // ==========================================

    cout << "Masukkan 10 nilai mahasiswa:" << endl;

    for (int i = 1; i <= 10; i++) {

        int nilai;

        cout << "Nilai mahasiswa " << i << ": ";
        cin >> nilai;

        tambahBelakang(head, nilai);
    }

    cout << endl;

    cout << "=== DATA AWAL ===" << endl;
    tampilkan(head);


    // ==========================================
    // TAMBAH DI DEPAN
    // ==========================================

    int nilai;

    cout << endl;
    cout << "Masukkan nilai untuk ditambah di depan: ";
    cin >> nilai;

    tambahDepan(head, nilai);

    cout << "Setelah tambah di depan:" << endl;
    tampilkan(head);


    // ==========================================
    // TAMBAH DI BELAKANG
    // ==========================================

    cout << endl;
    cout << "Masukkan nilai untuk ditambah di belakang: ";
    cin >> nilai;

    tambahBelakang(head, nilai);

    cout << "Setelah tambah di belakang:" << endl;
    tampilkan(head);


    // ==========================================
    // TAMBAH SETELAH NILAI TERTENTU
    // ==========================================

    int nilaiCari;
    int nilaiBaru;

    cout << endl;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> nilaiCari;

    cout << "Masukkan nilai baru: ";
    cin >> nilaiBaru;

    tambahSetelah(head, nilaiCari, nilaiBaru);

    cout << "Setelah tambah node:" << endl;
    tampilkan(head);


    // ==========================================
    // HAPUS NODE
    // ==========================================

    cout << endl;
    cout << "Masukkan nilai yang ingin dihapus: ";
    cin >> nilaiCari;

    hapusNode(head, nilaiCari);

    cout << "Setelah menghapus node:" << endl;
    tampilkan(head);


    return 0;
}