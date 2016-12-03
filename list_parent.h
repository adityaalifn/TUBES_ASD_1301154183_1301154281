#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#include "list_relasi.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child

typedef struct account infotype_parent;
/*struct friends{
    string name;
    string chat[10];
};*/

struct account{
    int NIM;
    string password;
    string account_name;
    string account_class;
    string post[10];
    //string chat[10];
    //string friends[10];
    string address;
    int contact_no;
};


typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    List_relasi child;
    address_parent next;
};

struct List_parent {
    address_parent first;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);


/** PERLU MODIFIKASI */
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
void printInfo(List_parent L);


#endif // LIST_PARENT_H_INCLUDED
