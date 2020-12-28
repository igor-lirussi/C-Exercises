#include <stdio.h>
#include <stdlib.h>

#include "lista_strutture_collegate.h"


void stampa_lista(Nodo * testa){
    if (testa == NULL) {
        printf("vuota");
        return;
    }
    else {
    while (testa != NULL){
        printf(" %d ", testa->elem);
        testa = testa->next; //posso spostare la testa dato che è solo una copia
    }
    }
    return;
}


void push(Nodo** lis, int elem_ins) {
    Nodo* paux;
    paux = (Nodo *) malloc( sizeof (Nodo));
    if (paux == NULL) {
        printf("Errore allocazione memoria");
        system("pause");
        exit(1);
    }
    paux->elem = elem_ins;
    paux->next = *lis;
    *lis = paux;
}


void inserisci_coda(Nodo** lis, int elem_ins) {
    Nodo* paux;
    Nodo* tmp;
    paux = (Nodo *) malloc( sizeof (Nodo));
    if (paux == NULL) {
        printf("Errore allocazione memoria");
        system("pause");
        exit(1);
    }
    paux->elem = elem_ins;
    paux->next = NULL;
    //il nuovo nodo è stato creato ora lo devo inserire in coda
    if (*lis == NULL) { //se la lista è vuota lo inserisco come primo
        *lis = paux;
        return;
    }
    else{
        tmp = *lis;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = paux;
    }
    return;

}


void inserisci_dopo(Nodo* testa, int elem_ins, int elem_ric) {

    //controllo se la lista è vuota
    if (testa == NULL){
        printf("La Lista e' vuota!\n");
        system("pause");
        return;
    }


    Nodo* paux;
    Nodo* tmp; //devo tenere traccia dell'elemento precedente

    paux = (Nodo *) malloc( sizeof (Nodo));
    if (paux == NULL) {
        printf("Errore allocazione memoria");
        system("pause");
        exit(1);
    }
    paux->elem = elem_ins;
    paux->next = NULL;
    //il nuovo nodo è stato creato ora lo devo inserire dopo ric
    tmp = testa;
    while (tmp != NULL){    //finchè ci sono elementi nella lista
        if (tmp ->elem == elem_ric){ //se trovo elemento ricercato allora il nodo verrà posto dopo questo
            paux->next = tmp->next;
            tmp->next = paux;
            return;
        }
        tmp = tmp->next;
    }

        printf("Elemento non trovato!");
        system("pause");

    return;
}

int top(Nodo* testa){
    if ( testa== NULL)
        return -1;
    else
        return testa->elem;
}

void pop(Nodo** lis) {
    if (*lis == NULL) {
        printf("La lista e' vuota!\n");
        system("pause");
        return;
    }
    Nodo *tmp;
    tmp = *lis;
    *lis = tmp->next;
    free(tmp);
    return;
}

void cancella_coda(Nodo** lis) {
    if (*lis == NULL) {
        printf("La lista e' vuota!\n");
        system("pause");
        return;
    }
    Nodo *paux;
    paux = *lis;    //ora paux punta al primo Nodo
    Nodo * prev;
    prev = NULL;
    while (paux->next != NULL){
        prev = paux;
        paux = paux->next;
    }
    if (prev == NULL) { //se è presente un solo elemento paux non viene modificato e devo modificare la testa
        *lis = NULL;
        free(paux);
        return;
    }
    //altimenti modifico il precedente
    prev->next = NULL;
    free(paux);
    return;
}


void cancella_elem(Nodo** lis, int elem_ric){
    if (*lis == NULL) {
        printf("La lista e' vuota!\n");
        system("pause");
        return;
    }

    Nodo* tmp;
    tmp = *lis; //tmp punta al primo
    Nodo* prev;
    prev = NULL;    //prev punta a null
    while (tmp != NULL){ //finche ci sono elementi
        if(tmp->elem == elem_ric) {
            //se siamo al primo
            if (prev == NULL){
                *lis = tmp->next;
                free(tmp);
                return;
            }
            //altrimenti modifico l'elemento precedente
            prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    printf("L'elemento non è presente.\n");
    system("pause");
    return;
}

void cancella_tutti_elem(Nodo** lis, int elem_ric){
    if (*lis == NULL) {
        printf("La lista e' vuota!\n");
        system("pause");
        return;
    }

    Nodo * tmp; //creo puntatore al primo nodo
    tmp = *lis;

    Nodo * prev;    //creo puntatore a null
    prev = NULL;

    int conta = 0; //tiene il conto delle occorrenze
    Nodo * elimina; //creo puntatore a Nodo da eliminare altrimenti quando faccio il free poi non posso eliminare altri

    while (tmp != NULL){
        if (tmp->elem == elem_ric) {    //se trovo l'elemento nel nodo a cui punta tmp
            conta ++;
            if (prev == NULL) { //se è il primo elemento modifico la testa
                *lis = tmp->next;
            }
            else {              //altrimenti modifico il precendente nodo
                prev->next = tmp->next;
            }
            elimina = tmp;  //lo assegno da eliminare
            tmp = tmp->next; //sposto tmp al prossimo , prev rimane li poichè eliminando un elemento è sempre dietro
            free(elimina);
        }

        else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    if (conta == 0){
        printf("L'elemento non è presente.\n");
        system("pause");
    }
    return;
}

int isEmpty(Nodo* testa){
    int lunghezza;
    for( lunghezza = 0 ; testa != NULL ; lunghezza++){  //lavoro sulla testa perchè è una copia
        testa = testa->next;
    }
    return lunghezza;
}
//FINE
