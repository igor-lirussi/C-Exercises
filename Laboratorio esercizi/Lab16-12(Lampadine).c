//matrice di interi NxM righe = fili sulla strada colonne = Lampadine su ogni filo,
//nella matrice 1 corrisponde a lampadina accesa, 0 spenta

//funzione che presa in ingresso la matrice restituisca una lista di liste di lampadine accese
//lista principale contiene elenco fili, lista secondarie lampadine accese
#include "stdio.h"

#define M 2 //2 fili
#define N 6 //6 lampadine per filo


typedef struct _Lampadina{
    int posizione ;
    struct _Lampadina * next;
}Lampadina;

typedef struct _Filo{
    int posizione;
    Lampadina * lampadina;
    struct _Filo *next;
}Filo;


int main () {
int mappa [M] [N] = {0,1,0,0,1,0,1,0,0,1,0,0};

Filo * testa = NULL; // creo puntatore alla testa dei fili!!!

testa = trasforma( int mappa [M] [N] ) ;

return 0;
}

Filo *    trasforma( int mappa [M] [N] ) {
    Filo * testa = NULL;
    int i = 0;
    int j = 0;
    testa = (Filo *) malloc (sizeof(Filo));
    if (testa == NULL) {
        exit(1);
    }
    for (i = 0; i < M; i++ )  {

        for (j = 0; j < N; j++) {

        }
    }
}
