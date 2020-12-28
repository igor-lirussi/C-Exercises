#include <stdio.h>
#include <stdlib.h>

//nella pila si usano le funzioni di pop e push

typedef struct _Cella {
    int valore;
    struct _Cella * next;
} Cella;

int push (Cella **t, Cella * nuovo);

Cella* pop(Cella **t);

int main () {
    Cella * testa = NULL;

    Cella *tmp, *appoggio;

    do{
        tmp = pop(&testa);  //con la pop l'elemento viene sganciato
        if(tmp != NULL) {
            printf("%d ", tmp->valore);
            push(&appoggio, tmp);
        }
    }
    while (tmp != NULL);

    do{
        tmp = pop(&appoggio);
        push(&testa, tmp);
    }
    while (tmp != NULL);


    return 0;
}

//FUNZIONI
int push (Cella **t, Cella * nuovo) {
    if (nuovo == NULL) {
        return 0;
    }

    nuovo->next = *t;
    *t = nuovo;

    return 1;
}

Cella* pop(Cella **t) {
    if (*t == NULL) {
        return NULL;
    }
    Cella *tmp;
    tmp = *t;
    *t = (*t) -> next;
    tmp->next = NULL;
    return tmp;

}

