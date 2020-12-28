#include <stdio.h>
#include <stdlib.h>



typedef struct _Cella {
    int valore;
    struct _Cella * next;
    struct _Cella * prev;
} Cella;

void inserisci(Cella **t, int valore);

int main () {
    Cella *  testa = NULL;

    inserisci (&testa, 1);
    inserisci (&testa, 2);
    inserisci (&testa, 3);
    inserisci (&testa, 4);

    return 0;
}

void inserisci (Cella ** t , int valore){
    Cella * nuovo;  //menatiene riferimento nuova cella che allochiamo

    nuovo = (Cella*) malloc(sizeof(Cella));     //creo la cella da inserire
    if (nuovo == NULL) {
        exit(1);
    }

    nuovo->valore = valore; //rimepio la cella da inserire con il valore

    nuovo->next = *t;   //facio puntare il next di nuovo a quello a cui punta la testa
    nuovo->prev = NULL; //il precedente punta a null

    if (*t != NULL) {   //se la lista è piena
            (*t)->prev = nuovo;     //faccio puntare il puntatore prec dell'elemento successivo a nuovo
    }
    *t = nuovo; //faccio puntare la testa al nuovo
}
