#include "bstree.h"

address alokasi(infotype x) {
	address p = new node;
	p->info = x;
	p->left = nil;
	p->right = nil;
	return p;
}

void insertnode(address &root, infotype x) {
	if (root == nil) {
		root = alokasi(x);
	}
	else if (x < root->info) {
		insertnode(root->left, x);
	}
	else if (x > root->info) {
		insertnode(root->right, x);
	}
}

address findnode(infotype x, address root) {
	if (root == nil || root->info == x) {
		return root;
	}
	if (x < root->info) {
		return findnode(x, root->left);
	}
	return findnode(x, root->right);
}

void inorder(address root) {
	if (root != nil) {
		inorder(root->left);
		cout << root->info << " -> ";
		inorder(root->right);
	}
}

int hitungjumlahnode(address root) {
	if (root == nil) {
		return 0;
	}
	return 1 + hitungjumlahnode(root->left) + hitungjumlahnode(root->right);
}

int hitungtotalinfo(address root) {
	if (root == nil) {
		return 0;
	}
	return root->info + hitungtotalinfo(root->left) + hitungtotalinfo(root->right);
}

int hitungkedalaman(address root, int start) {
	if (root == nil) {
		return start;
	}
	int kiri = hitungkedalaman(root->left, start + 1);
	int kanan = hitungkedalaman(root->right, start + 1);
	return (kiri > kanan ? kiri : kanan);
}

void preorder(address root) {
	if (root != nil) {
		cout << root->info << " -> ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(address root) {
	if (root != nil) {
		postorder(root->left);
		postorder(root->right);
		cout << root->info << " -> ";
	}
}