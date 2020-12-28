#include <stdio.h>
#include <stdlib.h>



typedef struct _Cella {
    int valore;
    struct _Cella * next;
} Cella;

void inserisci(Cella **t, int valore);

int main () {
    Cella * testa = NULL;

    inserisci (&testa, 1);

    return 0;
}

void inserisci (Cella ** t , int valore){
    Cella * nuovo;  //menatiene riferimento nuova cella che allochiamo
    Cella * tmp;
    nuovo = (Cella*) malloc(sizeof(Cella));     //creo la cella da inserire
    if (nuovo == NULL) {
        exit(1);
    }

    nuovo->valore = valore; //rimepio la cella da inserire con il valore

    if (*t == NULL) {   //se la lista è vuota
        nuovo->next= nuovo; //il puntatore dentro nuovo punta a se stesso
        *t = nuovo; //il puntatore di testa punta a nuovo
    }
    else {  //se la lista non è vuota
        tmp = *t;   //creo puntatore che permette lo scorrimento della lista
        while (tmp->next != *t) {   //lo faccio scorrere fino a che il contenuto del next della cella a cui punta è la testa
            tmp = tmp->next;
        }   //ora tmp punta all'ultimo elemento prima di quellp puntato dalla testa
        nuovo->next = *t;   //faccio puntare il puntatore della nuova cella alla cella a cui puntava la testa
        *t = nuovo;     //la testa retrocede e punta al nuovo elemento che doventa primo
        tmp->next = nuovo;  //l'ultima cella punta al nuovo
    }
}
