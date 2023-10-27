#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) {
    *l = NULL;
}

boolean isEmpty(List l) {
    return (l == NULL);
}

ElType getElmt(List l, int idx) {
    int cnt = 0;
    Address p = l;
    while(cnt < idx){
        cnt++;
        p = p->next;
    }
    return(p->info);
}

void setElmt(List *l, int idx, ElType val) {
    int cnt = 0;
    Address p = *l;
    while(cnt < idx){
        cnt++;
        p = p->next;
    }
    p->info = val;
}

int indexOf(List l, ElType val) {
    int cnt = 0;
    Address p = l;
    boolean found = false;
    while(p != NULL && !found){
        if(p->info == val){
            found=true;
        }
        else{
            cnt++;
            p = p->next;
        }
    }
    if(found){
        return cnt;
    }
    else{
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType val) {
    Address p;
    p = newNode(val);
    if(p != NULL){
        p->next = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        Address p, last;
        p = newNode(val);
        if(p != NULL){
            last = *l;
            while(last->next != NULL){
                last = last->next;
            }
            last->next = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    int cnt = 0;
    Address p, loc;
    if(idx==0){
        insertFirst(l, val);
    }
    else{
        p = newNode(val);
        if(p != NULL){
            loc = *l;
            while(cnt<idx-1){
                cnt++;
                loc = loc->next;
            }
            p->next = loc->next;
            loc->next = p;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p = *l;
    *val = p->info;
    *l = p->next;
    free(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = *l;
    Address loc = NULL;
    while(p->next != NULL){
        loc = p;
        p = p->next;
    }
    if(loc==NULL){
        *l = NULL;
    }
    else{
        loc->next = NULL;
    }
    *val = p->info;
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    if(idx == 0){
        deleteFirst(l, val);
    }
    else{
        int cnt = 0;
        Address p, loc;
        loc = *l;
        while(cnt<idx-1){
            cnt++;
            loc = loc->next;
        }
        p = loc->next;
        *val = p->info;
        loc->next = p->next;
        free(p);
    }
}

void displayList(List l) {
    Address p = l;
    printf("[");
    while(p != NULL){
        if(p->next == NULL){
            printf("%i", p->info);
        }
        else{
            printf("%i,", p->info);
        }
        p = p->next;
    }
    printf("]");
}

int length(List l) {
    int cnt = 0;
    Address p = l;
    if(isEmpty(l)){
        return cnt;
    }
    else{
        while(p != NULL){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p = l1;
    while(p != NULL){
        insertLast(&l3, p->info);
        p = p->next;
    }
    p = l2;
    while(p != NULL){
        insertLast(&l3, p->info);
        p = p->next;
    }
    return l3;
}
