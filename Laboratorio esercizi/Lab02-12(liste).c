#include <stdio.h>
#include <stdlib.h>

struct Cella {
    char lettera;

    struct Cella * next;
};


typedef  struct Cella    stCella;

main () {
struct Cella *   testa;    //defnisco il punatatore di testa

inserisci (&testa, 'a');  //passo puntatora a testa e il carattere che sarà presente nella cella inserita in testa

//testa = inserisci2(testa, 'd');



return 0;
}

//controllare
//-lista vuota
//-lista che contiene elementi e lavoriamo su uno in mezzo
//-lista che contiene un solo elemento
//-l elemento che andiamo a modificare è all inizio
//-l'elemento che andiamo a modificare è l' ultimo


//FUNZIONE INSERISCI IN TESTA
void inserisci (struct Cella * * t, char lett) {    //puntatore al puntatore di testa altrimenti quest'ultimo non sarebbe modificabile

struct Cella * nuovo;

nuovo = (struct Cella*) malloc ( sizeof(struct Cella) );
if (nuovo == NULL) {
    exit(1);
}
nuovo->lettera = lett;

nuovo->next = *t;
*t = nuovo;

}

/*
//FUNZIONE INSERISCI IN TESTA RESTITUENDO PUNTATORE TESTA
struct Cella *  inserisci2 (struct Cella  * testa, char lett) {

struct Cella * nuovo;

nuovo = (struct Cella*) malloc ( sizeof(struct Cella) );
if (nuovo == NULL) {
    exit(1);
}

nuovo->lettera = lett;

nuovo->next = testa;
testa = nuovo;

return testa;

}
*/

//FUNZIONE STAMPA LISTA
void stampa (struct Cella *testa) {
struct Cella * tmp;
tmp = testa;
while(tmp!= NULL) {
    printf("%c", tmp->lettera);
    tmp = tmp -> next;
    }
}

//FUNZIONE ELIMINARE ELEMENTO LISTA
int elimina (stCella **t, char da_eliminare) {
    stCella *tmp, *prec;
    tmp = *t;
    prec = NULL;
    while (tmp != NULL) {
        if (tmp->lettera == da_eliminare) {
            if (prec == NULL) {
                *t = tmp->next;
            }
            else {
                prec->next = tmp->next;
            }
            tmp->next = NULL;
            free(tmp);
            return 1;
        }
        prec = tmp;
        tmp = tmp->next;
    }
    return 0;
}

//FUNZIONE ELIMINA TUTTI GLI ELEMENTI DELLA LISTA
/*....*/

//FUNZIONE INSERICI IN CODA
