#include <iostream>
#include "multilist.h"
using namespace std;

int main() {
	listinduk L;
	create_list(L);

	insert_last(L, alokasi(1));
	insert_last(L, alokasi(2));

	cout << "list induk:" << endl;
	print_info(L);
	cout << endl;

	address P = find_elm(L, 1);
	insert_last_anak(P->lanak, alokasi_anak(10));
	insert_last_anak(P->lanak, alokasi_anak(20));

	P = find_elm(L, 2);
	insert_last_anak(P->lanak, alokasi_anak(30));

	cout << "list multilist:" << endl;
	print_info(L);

	return 0;
}