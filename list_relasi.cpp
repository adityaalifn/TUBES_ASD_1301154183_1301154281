#include "list_relasi.h"
using namespace std;

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_child C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if (first(L) == NULL){
        first(L) = P;
        next(P) = NULL;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(List_relasi &L,address_relasi P){
    address_relasi Q = first(L);
    while (next(Q) != NULL){
        Q = next(Q);
    }
    next(Q) = P;
}

void deleteFirst(List_relasi &L,address_relasi &P){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List_relasi &L,address_relasi &P){
    address_relasi Q = first(L);
    while (next(Q) != NULL){
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;
}

void deleteAfter(List_relasi &L,address_relasi Prec,address_relasi &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void insertAfter(address_relasi Prec,address_relasi P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    cout<<"<------- USER JOINED GROUP ------>"<<endl;
    if (first(L) == NULL){
        cout<<"   NOT JOINED ANY GROUP"<<endl;
    }
    else{
        while(P !=NULL) {
            cout<<"    Group ID             : "<<info(info(P)).group_id<<endl;
            cout<<"    Group Name           : "<<info(info(P)).group_name<<endl;
            cout<<"    Group Description    : "<<info(info(P)).group_desc<<endl<<endl;
            P = next(P);
        }
    }
}

address_relasi findElm(List_relasi L, address_child C) {
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(P) == C) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
