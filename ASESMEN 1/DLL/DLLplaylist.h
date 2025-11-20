// DLLPlaylist.h

#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept> 

using namespace std;


typedef struct {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; // skala 0.0 - 5.0
} Song;

typedef struct Node *address;

typedef struct Node {
    Song info;
    address prev;
    address next;
} Node;

typedef struct {
    address head;
    address tail;
} List;

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address &P);
address findNodeAtPosition(List L, int posisi); 

float calculatePopularityScore(Song S);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, Song S, int posisi);
void updateBefore(List &L, int posisi, Song S);

void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

#endif