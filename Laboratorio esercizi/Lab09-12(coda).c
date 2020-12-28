#include <stdio.h>
#include <stdlib.h>
//NELLE PILE E CODE SI USANO ESCLUSIVAMENTE PUSH E POP!

//Nella coda non c'è solo il riferimento al primo elemento ma anche all'ultimo

typedef struct {
    struct Coda * primo;
    struct Coda * ultimo;
} Coda;

int push (Coda *c, Coda * nuovo);


int main () {
    Coda c;
    c.primo = NULL;
    c.ultimo = NULL;

    Coda *tmp;
    Coda appoggio;
    appoggio.primo = NULL;
    appoggio.ultimo = NULL;


    do {
        tmp = pop(&c);
        if(tmp != NULL) {
            printf("%d " );
            push(&appoggio, tmp);
        }
    }
    while (tmp != NULL);

    c = appoggio;


    return 0;
}

//FUNZIONI


int push (Coda * c, Coda *nuovo) {
    if (nuovo == NULL) {
        return 0;
    }
    if (c->ultimo != NULL) { // se esiste elemento aggancio l'ultimo al nuovo , ultimo lo punto al nuovo e nuovo lo punto a NULL
        c->ultimo->next = nuovo;
    }
    c->ultimo = nuovo;
    if (c->ultimo == NULL) {
        c->primo = nuovo;
    }


}

//pop : tmp punta al primo, sganciamo puntatore dal primo al secondo, free del primo da tmp
Coda* pop (Coda *c) {
    if (c->primo == NULL) {
        return NULL;
    }
    Cella * tmp;
    tmp = c->primo;
    c->primo = c->primo->next;
    if (c->primo == NULL) {
        c->ultimo = NULL;
    }
}
