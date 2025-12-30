#include <iostream>
#include "multilist.h"
using namespace std;

bool list_empty(listinduk L) {
	return L.first == Nil;
}

bool list_empty_anak(listanak L) {
	return L.first == Nil;
}

void create_list(listinduk &L) {
	L.first = Nil;
	L.last = Nil;
}

void create_list_anak(listanak &L) {
	L.first = Nil;
	L.last = Nil;
}

address alokasi(infotypeinduk P) {
	address Q = new elemen_list_induk;
	Q->info = P;
	create_list_anak(Q->lanak);
	Q->next = Nil;
	Q->prev = Nil;
	return Q;
}

address_anak alokasi_anak(infotypeanak P) {
	address_anak Q = new elemen_list_anak;
	Q->info = P;
	Q->next = Nil;
	Q->prev = Nil;
	return Q;
}

void dealokasi(address P) {
	delete P;
}

void dealokasi_anak(address_anak P) {
	delete P;
}

address find_elm(listinduk L, infotypeinduk X) {
	address P = L.first;
	while (P != Nil && P->info != X) {
		P = P->next;
	}
	return P;
}

address_anak find_elm_anak(listanak L, infotypeanak X) {
	address_anak P = L.first;
	while (P != Nil && P->info != X) {
		P = P->next;
	}
	return P;
}

bool ffind_elm(listinduk L, address P) {
	address Q = L.first;
	while (Q != Nil) {
		if (Q == P) return true;
		Q = Q->next;
	}
	return false;
}

bool ffind_elm_anak(listanak L, address_anak P) {
	address_anak Q = L.first;
	while (Q != Nil) {
		if (Q == P) return true;
		Q = Q->next;
	}
	return false;
}

address find_before(listinduk L, address P) {
	if (L.first == P) return Nil;
	address Q = L.first;
	while (Q != Nil && Q->next != P) {
		Q = Q->next;
	}
	return Q;
}

address_anak find_before_anak(listanak L, infotypeanak X, address_anak P) {
	if (L.first == P) return Nil;
	address_anak Q = L.first;
	while (Q != Nil && Q->next != P) {
		Q = Q->next;
	}
	return Q;
}

void insert_first(listinduk &L, address P) {
	if (list_empty(L)) {
		L.first = P;
		L.last = P;
	} else {
		P->next = L.first;
		L.first->prev = P;
		L.first = P;
	}
}

void insert_after(listinduk &L, address P, address Prec) {
	P->next = Prec->next;
	P->prev = Prec;
	if (Prec->next != Nil) Prec->next->prev = P;
	Prec->next = P;
	if (L.last == Prec) L.last = P;
}

void insert_last(listinduk &L, address P) {
	if (list_empty(L)) {
		insert_first(L, P);
	} else {
		P->prev = L.last;
		L.last->next = P;
		L.last = P;
	}
}

void insert_first_anak(listanak &L, address_anak P) {
	if (list_empty_anak(L)) {
		L.first = P;
		L.last = P;
	} else {
		P->next = L.first;
		L.first->prev = P;
		L.first = P;
	}
}

void insert_after_anak(listanak &L, address_anak P, address_anak Prec) {
	P->next = Prec->next;
	P->prev = Prec;
	if (Prec->next != Nil) Prec->next->prev = P;
	Prec->next = P;
	if (L.last == Prec) L.last = P;
}

void insert_last_anak(listanak &L, address_anak P) {
	if (list_empty_anak(L)) {
		insert_first_anak(L, P);
	} else {
		P->prev = L.last;
		L.last->next = P;
		L.last = P;
	}
}

void del_first(listinduk &L, address &P) {
	P = L.first;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.first = P->next;
		L.first->prev = Nil;
	}
}

void del_last(listinduk &L, address &P) {
	P = L.last;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.last = P->prev;
		L.last->next = Nil;
	}
}

void del_after(listinduk &L, address &P, address Prec) {
	P = Prec->next;
	Prec->next = P->next;
	if (P->next != Nil) P->next->prev = Prec;
	if (L.last == P) L.last = Prec;
}

void delp(listinduk &L, infotypeinduk X) {
	address P = find_elm(L, X);
	if (P != Nil) {
		if (P == L.first) {
			del_first(L, P);
			dealokasi(P);
		} else if (P == L.last) {
			del_last(L, P);
			dealokasi(P);
		} else {
			address Q;
			del_after(L, Q, P->prev);
			dealokasi(Q);
		}
	}
}

void del_first_anak(listanak &L, address_anak &P) {
	P = L.first;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.first = P->next;
		L.first->prev = Nil;
	}
}

void del_last_anak(listanak &L, address_anak &P) {
	P = L.last;
	if (L.first == L.last) {
		L.first = Nil;
		L.last = Nil;
	} else {
		L.last = P->prev;
		L.last->next = Nil;
	}
}

void del_after_anak(listanak &L, address_anak &P, address_anak Prec) {
	P = Prec->next;
	Prec->next = P->next;
	if (P->next != Nil) P->next->prev = Prec;
	if (L.last == P) L.last = Prec;
}

void delp_anak(listanak &L, infotypeanak X) {
	address_anak P = find_elm_anak(L, X);
	if (P != Nil) {
		if (P == L.first) {
			del_first_anak(L, P);
			dealokasi_anak(P);
		} else if (P == L.last) {
			del_last_anak(L, P);
			dealokasi_anak(P);
		} else {
			address_anak Q;
			del_after_anak(L, Q, P->prev);
			dealokasi_anak(Q);
		}
	}
}

void print_info_anak(listanak L) {
	address_anak P = L.first;
	while (P != Nil) {
		cout << " -> " << P->info;
		P = P->next;
	}
}

void print_info(listinduk L) {
	address P = L.first;
	while (P != Nil) {
		cout << P->info;
		print_info_anak(P->lanak);
		cout << endl;
		P = P->next;
	}
}

int nb_list(listinduk L) {
	int c = 0;
	address P = L.first;
	while (P != Nil) {
		c++;
		P = P->next;
	}
	return c;
}

int nb_list_anak(listanak L) {
	int c = 0;
	address_anak P = L.first;
	while (P != Nil) {
		c++;
		P = P->next;
	}
	return c;
}

void del_all(listinduk &L) {
	address P;
	while (L.first != Nil) {
		del_first(L, P);
		dealokasi(P);
	}
}