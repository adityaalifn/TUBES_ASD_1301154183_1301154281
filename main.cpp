#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

List_parent LP;
List_child LC;
List_relasi LR;
address_child AC;
address_parent AP;
address_relasi AR;
infotype_parent XP;
infotype_child XC;

void mainMenu();
void clrscr();
void registerAccount();
void loginAccount();
void loginAdmin();
void menuUser(List_parent &L,address_parent &P);
void postStatus(List_parent &L,address_parent &P);
void Timeline(List_parent &L,address_parent &P);
void menuAdmin();
void createGroup(List_parent &L, address_parent &P);
void menuGroup(List_parent &L, address_parent &P);
void editGroup(List_parent &L,address_parent &P);

int main()
{
    createList(LP);
    createList(LC);
    createList(LR);
    mainMenu();
    return 0;
}

void clrscr(){
    system("cls");
}

void mainMenu(){
    clrscr();
    int pil;
    cout<<"***************************************************************"<<endl;
    cout<<"*           WELCOME TO TELKOM UNIVERSITY SOCIAL MEDIA         *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. Register an account"<<endl;
    cout<<"   2. Login"<<endl;
    cout<<"   3. ADMIN"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"   99. Exit"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch (pil){
    case 1:
        registerAccount();
        break;
    case 2:
        loginAccount();
        break;
    case 3:
        loginAdmin();
        break;
    case 99:
        exit(99);
        break;
    }
    if (pil != 99){
        mainMenu();
    }
}

void registerAccount(){
    clrscr();
    infotype_parent x;
    cout<<"***************************************************************"<<endl;
    cout<<"*                     REGISTER AN ACCOUNT                     *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   NIM (ID)      : "; cin>>x.NIM;
    if (findElm(LP,x) != NULL){
        cout<<"NIM already exist."<<endl;
        getch();
        mainMenu();
    }
    else{
        cout<<"   Password      : "; cin>>x.password;
        cout<<"   Name          : "; cin>>x.account_name;
        /*cout<<"   Address       : "; cin>>x.address;
        cout<<"   Phone Number  : "; cin>>x.contact_no;*/
        for (int i=0; i<10; i++){
            x.post[i] = " ";
        }
        address_parent Q = first(LP);
        address_parent tempP = first(LP);
        address_parent P = alokasi(x);
        if (first(LP) == NULL){
            insertFirst(LP,P);
        }
        else{
            while (next(Q) != first(LP)){
                /*if (next(Q) == first(LP)){
                    insertLast(LP,P);
                }*/
                if (info(next(Q)).NIM < x.NIM){
                    //cout<<"A"<<x.NIM;
                    tempP = next(tempP);
                }
                Q = next(Q);
            }
            insertAfter(LP,tempP,P);
        }
        cout<<"Congratulations! You've been registered"<<endl;
        getch();
        mainMenu();
    }
}

void loginAccount(){
    clrscr();
    infotype_parent x;
    address_parent P;
    cout<<"***************************************************************"<<endl;
    cout<<"*                  LOGIN INTO YOUR ACCOUNT                    *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   NIM (ID)  : "; cin>>x.NIM;
    cout<<"   Password  : "; cin>>x.password;
    P = findElm(LP,x);
    if (P != NULL){
        if (info(P).password == x.password){
            menuUser(LP,P);
        }
        else{
            cout<<"Wrong password!"<<endl;
            getch();
            loginAccount();
        }
    }
    else{
        cout<<"Username is not registered!"<<endl;
        getch();
        mainMenu();
    }
}

void menuUser(List_parent &L,address_parent &P){
    int pil;
    //int j = 0;
    infotype_parent x;
    clrscr();
    cout<<"***************************************************************"<<endl;
    cout<<"*   H O M E     H O M E     H O M E     H O M E     H O M E   *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   Welcome back, "<<info(P).account_name<<" ("<<info(P).NIM<<")!"<<endl;
    cout<<"   What will you do?"<<endl;
    cout<<"   1. Timeline"<<endl;
    cout<<"   2. Post status"<<endl;
    cout<<"   3. Group Menu"<<endl;
    cout<<"   4. Friend Menu"<<endl;
    cout<<"   5. Edit Profile"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch (pil){
    case 1:
        Timeline(LP,P);
        break;
    case 2:
        postStatus(LP,P);
        break;
    case 3:
        menuGroup(LP,P);
        break;
    case 4:
        cout<<"Coming Soon! Please follow my GitHub:)\ngithub.com/adityaalifn"<<endl;
        getch();
        break;
    case 5:
        cout<<"Name: "; cin>>info(P).account_name;
        cout<<"Password: "; cin>>info(P).password;
        cout<<"Address: "; cin>>info(P).address;
        cout<<"Phone Number: "; cin>>info(P).contact_no;
        cout<<"Edit Profile successful!"<<endl;
        getch();
        menuUser(L,P);
        break;
    }
}

void Timeline(List_parent &L,address_parent &P){
    clrscr();
    cout<<"*****************************************************"<<endl;
    cout<<"*                      TIMELINE                     *"<<endl;
    cout<<"*****************************************************"<<endl;
    int i = 0;
    address_parent Q = first(LP);
    //if (first(LP) != NULL){
        /*do{
            cout<<info(tempP).account_name<<endl;
            while ((i < 10) && (info(AP).post[i] != " ")){
                cout<<info(tempP).post[i]<<endl;
                i++;
            }
            tempP = next(tempP);
        }while (tempP != first(LP));*/
    //}
    if(first(L)!=NULL) {
        do {
            if (info(Q).post[0] != " "){
                i = 0;
                cout<<endl<<"Name: "<<info(Q).account_name<<endl;
                //cout<<"Status   : "<<endl;
                //cout<<"--> "<<info(Q).post[0];
                while ((info(Q).post[i] != " ") && (i<10)){
                    cout<<"--> "<<info(Q).post[i]<<endl;
                    i++;
                }
            }
            Q = next(Q);
        } while(info(Q).NIM != info(first(LP)).NIM);
    }    getch();
    menuUser(LP,P);
}

void postStatus(List_parent &L,address_parent &P){
    clrscr();
    infotype_parent x;
    int i=0;
    while ((i < 10) && (info(P).post[i] != " ")){
        i++;
    }
    cout<<"********************************************"<<endl;
    cout<<"*               POST  STATUS               *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"What are you thinking now?"<<endl;
    cout<<"-> "; cin>>x.post[i];
    info(P).post[i] = x.post[i];
    cout<<"Success! Your mind has been posted."<<endl;
    cout<<"Your mind is '"<<info(P).post[i]<<"'."<<endl;
    getch();
    menuUser(LP,P);
}

void loginAdmin(){
    clrscr();
    string username,pass;
    cout<<"***************************************************************"<<endl;
    cout<<"*                        ADMIN NOT GOD                        *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   Username  : "; cin>>username;
    cout<<"   Password  : "; cin>>pass;
    if (username == "aditbaik"){
        if (pass == "defajahat"){
            cout<<"Hello! Sok kamu mau ngapain"<<endl;
            getch();
            menuAdmin();
        }
    }
    else{
        cout<<"Sorry!"<<endl;
        getch();
        mainMenu();
    }
}

void menuAdmin(){
    clrscr();
    int pil;
    cout<<"***************************************************************"<<endl;
    cout<<"*                    M E N U    A D M I N                     *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. View User"<<endl;
    cout<<"   2. Delete User"<<endl;
    cout<<"--------------------------------------------------------------*"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch(pil){
    case 1:
        printInfo(LP);
        getch();
        menuAdmin();
        break;
    }
}

void menuGroup(List_parent &L,address_parent &P){
    clrscr();
    int pil;
    infotype_child XC;
    //address_child C;
    cout<<"***************************************************************"<<endl;
    cout<<"*                       GROUP  MENU                           *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. Create Group"<<endl;
    cout<<"   2. Edit Group"<<endl;
    cout<<"   3. Join Group"<<endl;
    cout<<"   4. View Group"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch(pil){
    case 1:
        createGroup(LP,P);
        break;
    case 2:
        editGroup(LP,P);
        break;
    case 4:
        printInfo(child(P));
        getch();
        menuUser(L,P);
        break;
    }
}

void createGroup(List_parent &L, address_parent &P){
    clrscr();
    infotype_child x;
    cout<<"***************************************************************"<<endl;
    cout<<"*                     REGISTER AN GROUP                       *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"  GROUP ID         : "; cin>>x.group_id;
    if (findElm(LC,x) != NULL){
        cout<<"ID already exist."<<endl;
        getch();
        menuGroup(L,P);
    }
    else{
        cout<<"   GROUP NAME        : "; cin>>x.group_name;
        cout<<"   GROUP DESCRIPTION : "; cin>>x.group_desc;
        cout<<info(P).NIM;
        x.group_admin = info(P).NIM;
        for (int i=0; i<10; i++){
            x.group_post[i] = " ";
        }
        address_child Q = first(LC);
        address_child tempC = first(LC);
        address_child C = alokasi(x);
        address_relasi R = alokasi(C);
        insertFirst(child(P),R);
        if (first(LC) == NULL){
            insertFirst(LC,C);
        }
        else{
            while (Q != last(LC)){
                //cout<<"A";
                if (first(LC) == last(LC)){
                    if (info(first(LC)).group_id > x.group_id){
                        insertLast(LC,C);
                    }
                    else if (info(first(LC)).group_id < x.group_id){
                        insertFirst(LC,C);
                    }
                }
                else if(info(next(Q)).group_id < x.group_id){
                    tempC = next(tempC);
                    //cout<<"A";
                }
                Q = next(Q);
            }
            insertAfter(LC,tempC,C);
        }
        cout<<"You've been created group."<<endl;
        getch();
        menuGroup(LP,P);
    }
}

void editGroup(List_parent &L,address_parent &P){
    clrscr();
    printInfo(child(P));
    cout<<"Input Group ID: "; cin>>XC.group_id;
    cout<<"-------------------------------------------"<<endl;
    address_child C = findElm(LC,XC);
    if (C == NULL){
        cout<<"Group doesn't exist!"<<endl;
        getch();
        menuGroup(L,P);
    }
    else{
        if (info(P).NIM != info(C).group_admin){
            cout<<"You are not admin on this group!"<<endl;
            getch();
            menuGroup(L,P);
        }
        else{
            cout<<"------------------------------------------------------"<<endl;
            cout<<"Group Name           : "; cin>>info(C).group_name;
            cout<<"Group Description    : "; cin>>info(C).group_desc;
            cout<<"Edit successful!"<<endl;
            getch();
            menuGroup(L,P);
        }
    }
    getch();
    menuGroup(L,P);
    //editGroup();
}
