#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct node {
	infotype info;
	node *left, *right;
};

typedef node* address;

#define nil NULL

address alokasi(infotype x);
void insertnode(address &root, infotype x);
address findnode(infotype x, address root);
void inorder(address root);
void preorder(address root);
void postorder(address root);
int hitungjumlahnode(address root);
int hitungtotalinfo(address root);
int hitungkedalaman(address root, int start);

#endif