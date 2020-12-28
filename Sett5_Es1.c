#include <stdio.h>

#define NUM 3   //numero colonne e righe della matrice

main() {

int matrice[NUM][NUM] = {0};    //matrice inizializzata a 0
int i, j;
int somma_d1 = 0;   //somma di riferimento diagonale primaria
int somma = 0;      //per le altre somme da confrontare con quella di riferimento
int magic = 1;      //la matrice è presa come magica di default

printf("Matrice %d * %d : \n", NUM, NUM);

for ( i = 0; i < NUM; i++) {    //contatore righe
    for (j = 0; j < NUM; j++) { //contatore colonne
        printf("Inserisci il numero della riga %d e colonna %d:", i+1, j+1);    //inserimento valori della matrice
        scanf("%d", &matrice [i] [j]);
        fflush(stdin);
    }
}

//stampa matrice
printf("\nMatrice: \n");
for ( i = 0; i < NUM; i++) {    //ciclo che aumenta righe
    for (j = 0; j < NUM; j++) { //ciclo che aumenta colonne
        printf(" %5d ", matrice [i] [j]);   //stampa valore
    }
    printf("\n\n");               // a capo riga quando finiscono le colonne di una riga
}



//Controlli sulla matrice

//calcolo valore di riferimento somma_d1 (somma della diagonale primaria della matrice)
for ( i = 0, j = 0; i < NUM; i++,j++) {
    somma_d1+= matrice [i] [j];
    }

//confronto delle somme delle righe
for ( i = 0; i < NUM; i++) {

    for (j = 0; j < NUM; j++) {
        somma+= matrice [i] [j];//alla somma nulla viene aggiunto il valore di ogni elemento della riga
    }

    if (somma != somma_d1) {    //se la somma di ogni riga è diversa da quella della diagonale primaria
        magic = 0;              //allora la matrice non è magica
    }

    somma = 0;  //la somma viene azzerata prima di ogni nuova riga
}


//confronto delle somme delle colonne
for ( j = 0; j < NUM; j++) {    //aumento colonna

    for (i = 0; i < NUM; i++) { //aumento delle righe per ogni colonna
        somma+= matrice [i] [j];
    }
    if (somma != somma_d1) {    //se le somme non sono uguali a quella di riferimento allora la matrice non è magica
        magic = 0;
    }
    somma = 0;
}


//confronto delle somma della diagonale secondaria
j = NUM-1; //il contatore delle colonne parte dalla fine
for ( i = 0; i < NUM; i++,j--) {    //all aumentare delle righe decresce la colonna presa in considerazione
    somma+= matrice [i] [j];        //calcolata la somma della diagonale secondaria
    }

if (somma != somma_d1) {            //se la somma è diversa da quella primaria allora la matrice non è magica
        magic = 0;
    }

//se la variabile è rimasta 1 allora la matrice è magica altrimenti non lo è
if (magic == 1) {
    printf("\nMatrice magica di somma %d. \n\n", somma_d1);
    }
if (magic == 0) {
    printf("\nLa matrice non e' magica. \n\n");
    }


return 0;
}

