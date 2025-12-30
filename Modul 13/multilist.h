#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak {
	infotypeanak info;
	address_anak next;
	address_anak prev;
};

struct listanak {
	address_anak first;
	address_anak last;
};

struct elemen_list_induk {
	infotypeinduk info;
	listanak lanak;
	address next;
	address prev;
};

struct listinduk {
	address first;
	address last;
};

bool list_empty(listinduk L);
bool list_empty_anak(listanak L);

void create_list(listinduk &L);
void create_list_anak(listanak &L);

address alokasi(infotypeinduk P);
address_anak alokasi_anak(infotypeanak P);

void dealokasi(address P);
void dealokasi_anak(address_anak P);

address find_elm(listinduk L, infotypeinduk X);
address_anak find_elm_anak(listanak L, infotypeanak X);

bool ffind_elm(listinduk L, address P);
bool ffind_elm_anak(listanak L, address_anak P);

address find_before(listinduk L, address P);
address_anak find_before_anak(listanak L, infotypeanak X, address_anak P);

void insert_first(listinduk &L, address P);
void insert_after(listinduk &L, address P, address Prec);
void insert_last(listinduk &L, address P);

void insert_first_anak(listanak &L, address_anak P);
void insert_after_anak(listanak &L, address_anak P, address_anak Prec);
void insert_last_anak(listanak &L, address_anak P);

void del_first(listinduk &L, address &P);
void del_last(listinduk &L, address &P);
void del_after(listinduk &L, address &P, address Prec);
void delp(listinduk &L, infotypeinduk X);

void del_first_anak(listanak &L, address_anak &P);
void del_last_anak(listanak &L, address_anak &P);
void del_after_anak(listanak &L, address_anak &P, address_anak Prec);
void delp_anak(listanak &L, infotypeanak X);

void print_info(listinduk L);
int nb_list(listinduk L);

void print_info_anak(listanak L);
int nb_list_anak(listanak L);

void del_all(listinduk &L);

#endif