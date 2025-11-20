// DLLPlaylist.cpp

#include "DLLPlaylist.h"

bool isEmpty(List L) {
    return (L.head == nullptr);
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(Song S) {
    address P = new (nothrow) Node; 
    if (P) {
        P->info = S;
        P->prev = nullptr;
        P->next = nullptr;
    }
    return P;
}

void deallocate(address &P) {
    delete P;
    P = nullptr;
}

float calculatePopularityScore(Song S) {
    // Rumus: PopularityScore = 0.8 * PlayCount + 20.0 * Rating
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

// Fungsi Bantuan untuk mencari node berdasarkan posisi
address findNodeAtPosition(List L, int posisi) {
    if (posisi <= 0 || isEmpty(L)) return nullptr;

    address P = L.head;
    int count = 1;
    while (P != nullptr && count < posisi) {
        P = P->next;
        count++;
    }
    return P;
}

// Fungsi Bantuan untuk mencetak satu baris lagu
void printSongRow(Song S, int position) {
    float popularityScore = calculatePopularityScore(S);
    cout << "| " << setw(6) << left << position 
         << "| " << setw(15) << left << S.Title 
         << "| " << setw(10) << left << S.Artist 
         << "| " << setw(12) << right << S.DurationSec 
         << "| " << setw(10) << right << S.PlayCount 
         << "| " << setw(7) << right << fixed << setprecision(1) << S.Rating 
         << "| " << setw(15) << right << fixed << setprecision(2) << popularityScore 
         << " |" << endl;
}

void printHeader() {
    cout << "=========================================================================================" << endl;
    cout << "| Posisi | Title           | Artist     | DurationSec | PlayCount | Rating | PopularityScore |" << endl;
    cout << "=========================================================================================" << endl;
}


// --- Operasi View/Search ---

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    
    printHeader();

    address P = L.head;
    int position = 1;
    while (P != nullptr) {
        printSongRow(P->info, position);
        P = P->next;
        position++;
    }
    cout << "=========================================================================================" << endl;
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    cout << "\n*** Hasil Pencarian (PopularityScore antara " 
         << fixed << setprecision(2) << minScore << " dan " 
         << fixed << setprecision(2) << maxScore << ") ***" << endl;

    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    
    printHeader();

    address P = L.head;
    int position = 1;
    int foundCount = 0;
    while (P != nullptr) {
        float score = calculatePopularityScore(P->info);
        if (score >= minScore && score <= maxScore) {
            printSongRow(P->info, position);
            foundCount++;
        }
        P = P->next;
        position++;
    }
    cout << "=========================================================================================" << endl;
    if (foundCount == 0) {
        cout << "Tidak ditemukan lagu dalam rentang popularitas tersebut." << endl;
    }
}


// --- Operasi Insert ---

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (!P) return; // Alokasi gagal

    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (!P) return; // Alokasi gagal

    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q == nullptr) return;

    if (Q == L.head) {
        insertFirst(L, S);
        return;
    }
    
    address P = allocate(S);
    if (!P) return;

    P->prev = Q->prev;
    P->next = Q;
    Q->prev->next = P;
    Q->prev = P;
}

// --- Operasi Delete ---

void deleteFirst(List &L, Song &S) {
    if (isEmpty(L)) return;

    address P = L.head;
    S = P->info; 

    if (L.head == L.tail) { // Hanya 1 node
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.head = P->next;
        L.head->prev = nullptr;
    }
    deallocate(P);
}

void deleteLast(List &L, Song &S) {
    if (isEmpty(L)) return;

    address P = L.tail;
    S = P->info;

    if (L.head == L.tail) { // Hanya 1 node
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.tail = P->prev;
        L.tail->next = nullptr;
    }
    deallocate(P);
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q == nullptr || Q == L.head) {
        // Tidak ada node sebelumnya untuk dihapus
        S = {}; // Set Song kosong
        return;
    }

    if (Q->prev == L.head) {
        deleteFirst(L, S);
        return;
    }
    
    address P = Q->prev;
    S = P->info;

    P->prev->next = Q;
    Q->prev = P->prev;
    deallocate(P);
}


// --- Operasi Update ---

void updateAtPosition(List &L, Song S, int posisi) {
    address P = findNodeAtPosition(L, posisi);
    if (P == nullptr) {
        cout << "Posisi " << posisi << " tidak valid untuk update." << endl;
        return;
    }

    P->info = S;
    cout << "Node pada posisi ke-" << posisi << " berhasil diupdate." << endl;
}

void updateBefore(List &L, int posisi, Song S) {
    if (posisi <= 1) {
        cout << "UpdateBefore pada posisi ke-" << posisi << " tidak memungkinkan (tidak ada node sebelumnya)." << endl;
        return;
    }

    address Q = findNodeAtPosition(L, posisi);
    if (Q == nullptr) {
        cout << "Posisi " << posisi << " tidak ditemukan." << endl;
        return;
    }

    address P = Q->prev;
    P->info = S;
    cout << "Node sebelum posisi ke-" << posisi << " (yaitu posisi ke-" << posisi - 1 << ") berhasil diupdate." << endl;
}