#include <stdio.h>
#define GM 10           //Grandezza Matrice: numero colonne e righe matrice: (GM-1 sar� l'ultima colonna o riga)

main() {

char matrice [GM] [GM];
int i , j;              //variabili per stampare la matrice
int mossa;              //variabile mossa: 0 in alto / 1 destra / 2 basso / 3 sinistra

srand(time(NULL));

for( i = 0; i < GM; i++) {      //inizializzazione e stampa matrice di punti
    for (j = 0; j < GM; j++) {
        matrice [i] [j] = '.';
        printf(" %c ", matrice [i] [j]);
    }
    printf("\n\n");
}
printf("\n");

/*PARTENZA*/
//punto di partenza
int r = 0;      //indicatore posizione riga
int c = 0;      //indicatore posizione colonna
//carattere di partenza
char carattere = 'A';

//posizionamento del primo carattere
matrice [r] [c] = carattere;


for( i = 0; i < GM; i++) {  //stampa matrice
    for (j = 0; j < GM; j++) {
        printf(" %c ", matrice [i] [j]);
    }
    printf("\n\n");
}
printf("\n");



/*MOSSE SUCCESSIVE*/
while (carattere < 'Z') {       //ciclo che si protrae fino a che il carattere non � quello precedente a Z

    mossa = rand() % 4;         //la prossima mossa assume un valore casuale da 0 a 3 compresi per le direzioni

    printf("Mossa : %d r:%d c:%d \n", mossa,r,c);               //stampa della mossa con le coordinate di partenza

    if (mossa == 0 && matrice [r-1][c] == '.' && r > 0) {       //per ogni mossa controllo se la cella di destinazione � libera ed esiste
            carattere += 1;                                     //il carattere aumenta
            r -= 1;                                             //uno dei valori di riferimento per la cella si sposta
            matrice [r] [c] = carattere;                        //il carattere viene assegnato alla matrice
    }
    if (mossa == 1&& matrice [r][c+1] == '.' && c < GM-1 ) {
            carattere += 1;
            c += 1;
            matrice [r] [c] = carattere;
    }
    if (mossa == 2 && matrice [r+1][c] == '.' && r < GM-1 ) {
            carattere += 1;
            r += 1;
            matrice [r] [c] = carattere;
    }
    if (mossa == 3 && matrice [r][c-1] == '.' && c > 0) {
            carattere += 1;
            c -= 1;
            matrice [r] [c] = carattere;
    }
    if ( (matrice [r][c-1] != '.' || c == 0) && (matrice [r][c+1] != '.' || c == GM-1) && (matrice [r-1][c] != '.' || r == 0) && (matrice [r+1][c] != '.' || r == GM-1) ) {
        //la seconda opzione evita che sul bordo della matrice si creino loop indesiderati se il programma legge la cella oltre il bordo come un punto
        carattere = 'Z';     //se non ci sono pi� possibilit� il ciclo termina
    }

    for( i = 0; i < GM; i++) {  //stampa matrice
        for (j = 0; j < GM; j++) {
            printf(" %c ", matrice [i] [j]);
        }
        printf("\n\n");
    }
    printf("\n");

}


return 0;
}

