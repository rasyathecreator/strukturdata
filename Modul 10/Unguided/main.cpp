#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
	cout << "=== TREE ===" << endl;
	address root = nil;
	insertnode(root,1);
	insertnode(root,2);
	insertnode(root,6);
	insertnode(root,4);
	insertnode(root,5);
	insertnode(root,3);
	insertnode(root,6);
	insertnode(root,7);
	cout << "inorder    : ";
	inorder(root);
	cout << endl;
	cout << "preorder   : ";
	preorder(root);
	cout << endl;
	cout << "postorder  : ";
	postorder(root);
	cout << endl;
	cout << "kedalaman      : " << hitungkedalaman(root,0) << endl;
	cout << "jumlah node    : " << hitungjumlahnode(root) << endl;
	cout << "total          : " << hitungtotalinfo(root) << endl;
	return 0;
}