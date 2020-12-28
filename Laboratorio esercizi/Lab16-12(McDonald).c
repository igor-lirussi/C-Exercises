//in un Mc Donald ci sono delle casse e dei clienti, vogliamo mettere in fila di fronte ad ogni cassa i clienti e le casse
//dovranno servire i clienti nell'ordine giusto
//un nuovo cliente viene inserito nella cassa più vuota

//array di puntatori o puntatori di array??
//in una struttura quando si può puntare a se stessa?

#include "stdio.h"

#define N 3     //numero casse


typedef struct _Cliente {
    char nome [30];
    char cognome [30];
    struct _Cliente * next; //puntatore al prossimo cliente
} Cliente;

typedef struct {
    int numero; //identifica quante persone sono in coda
    struct Cliente *primo;  //puntatore alla prima persona
    struct Cliente *ultimo; //puntatore all ultima
} Coda;

typedef struct {
    int codice;         //codece cassa, il suo numero
    Coda coda_clienti;      //la cassa contiene le info sulla coda
} Cassa;


main () {
Cassa elenco_casse[N];
int i;

for (i=0; i<N; i++) {
    elenco_casse[i].codice = i + 1;
    elenco_casse[i].coda_clienti.numero = 0;
    elenco_casse[i].coda_clienti.primo = NULL;
    elenco_casse[i].coda_clienti.ultimo = NULL;
}



return 0;
}

//FUNZIONI

int inserisci (Cassa elenco_casse[N], char nome[30], char cognome[30]) {
    int i , minimo;
    minimo = 0;
    Cliente * nuovo;


    for (i=1 ; i<N ; i++) {
        if(elenco_casse[i].coda_clienti.numero < elenco_casse[minimo].coda_clienti.numero) {
            minimo = i;
        }
    }

    nuovo = (Cliente *) malloc (sizeof(Cliente));
    if (nuovo == NULL) {
        return 0;
    }
    nuovo -> next = NULL;
    strcpy(nome, nuovo->nome);
    strcpy(cognome, nuovo->cognome);

    push(&elenco_casse[minimo], nuovo);

    return elenco_casse[minimo].codice;
}


int inserisci2 (Cassa elenco_casse[N], char nome[30], char cognome[30]) {
    int minimo;
    minimo = calcola_minimo(elenco_casse);
    nuovo = crea_cliente(nome, cognome);
    if(nuovo == NULL) {
        return 0;
    }
    push (&elenco_casse[minimo], nuovo);
    return elenco_casse[minimo].codice;
}

int conta_clienti (Coda *c) {
    Cliente *tmp;
    Coda coda_tmp;
    int conta = 0;

    do {
        tmp = pop(coda);
        if (tmp |= NULL) {
            push (&coda_tmp, tmp);
            conta++;
        }
    }
}

int push (Coda *c , Cliente *nuovo) {
    if (nuovo == NULL) {
        return 0;
    }
    if (c->ultimo != NULL) {
        c->ultimo->next = nuovo;
    }
    else {
        c->primo = nuovo;
    }
    c->ultimo = nuovo;
    c->numero++;    //nuova riga per aumentare il contatore dei clienti
    return 1;
}
