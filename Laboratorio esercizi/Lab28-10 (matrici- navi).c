#include <stdio.h>
#define M 5 //righe
#define N 4 //colonne
int main ()
{
    int matrice [4] [5]; //array 0,1,2,3 di array 0,1,2,3,4: {00 01 02 03 04  10 11 12 13 14  20 21 ...}

    matrice [1] [1] = 17;

    printf("prova matrice [1] [1] : %d \n\n\n", matrice [1] [1]);


/*Battagli navale*/
//0 = acqua 1 = nave
//dato matrice MxN con 1 e 0 quante navi sono presenti nel mare (matrice)
printf("Battaglia navale: \n\n");


int mappa[M] [N];
int i, j ;
int nave = 0;

srand ( time(NULL));

for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
        mappa [i] [j] = rand() %2; // assegnamento random matrice
        }
    }


for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
        printf(" %d ", mappa [i] [j] );  //stampa della matrice
        if (mappa [i] [j] == 1) {
            nave+=1;
            }
        }
    printf("\n");
    }
printf("\n\nnavi : %d", nave);

// calcolare le coppie che ci sono

 int coppie = 0;


for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
        if (mappa [i] [j] == 1) {
            if (mappa [i+1] [j] == 1 && i <M-1) { //riga successiva (cella sotto) == 1
            coppie += 1;
            }
            if (mappa [i] [j+1] == 1 && j<N-1) { //colonna successiva (cella dx) == 1
            coppie += 1;
            }
            }
        }
    }

printf("\n\ncoppie : %d", coppie);

//calcolare coppie senza coppie sovrapposte
int coppieNS = 0;
//se quella  colonna prima è 1 allora no
//se quella della riga superiore è uno allora no

for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
        if (mappa [i] [j] == 1) {
            if (mappa [i+1] [j] == 1 && i <M-1 && mappa [i-1] [j] != 1) {   //riga successiva (cella sotto) == 1 E riga preedente (cella sopra) diversa da 1
            coppieNS += 1;
            }
            if (mappa [i] [j+1] == 1 && j<N-1 && mappa [i] [j-1] != 1) {    //colonna successiva (cella dx) == 1 E colonna preedente (cella sx) diversa da 1
            coppieNS += 1;
            }
            }
        }
    }
printf("\n\ncoppie non sovrapposte: %d", coppieNS); // difettoso ne calcola di più se sono troppe vicine
//conviene onvertire in 0 le celle esaminate oppure fare il controllo anche sugli angoli?

printf("\n\n\n");
return 0;
}
