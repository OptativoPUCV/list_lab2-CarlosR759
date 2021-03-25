#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *lista = (List *) malloc(sizeof(List) );
    if(lista == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;

     return lista;
}

void * firstList(List * list) {
    list->current = list->head; 
    return (void *)list->head->data;
}

void * nextList(List * list) {
    if( (list->current) && (list->current->next != NULL) )
        list->current = list->current->next;
    else
        return NULL;

    return (void *)list->current->data;
}

void * lastList(List * list) {
    list->current = list->tail; 
    return (void *)list->tail->data;
}

void * prevList(List * list) {
    if( (list->current) && (list->current->prev != NULL) )
        list->current = list->current->prev; 
    else
        return NULL;

    return (void *) list->current->data;
}

void pushFront(List * list, const void * data) {
    Node *nuevoNodo = createNode( (void *) data); 

    if(nuevoNodo == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }
  
    nuevoNodo->next = list->head;
    list->head->prev = nuevoNodo;
    list->head = nuevoNodo;

    return;
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}