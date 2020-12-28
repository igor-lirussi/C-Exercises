#include <stdio.h>


/*GIOCO della VITA*/
//REGOLE
//cella morta (0) viene trasformata in una cella viva (1) se attorno ad essa ci sono esattamente 3 celle vive
//cella viva con 2 o 3 celle vive vicine sopravvive altrimenti muore per solitudine o sovraffollamento

#define BOOL int
#define MORTA 0
#define VIVA 1
#define DENS 2  //più cala più cellule ci sono : il minimo è 2 (50%), 3 da (33%)vive, 4 da (25%)vive, 5 da (20%), 10 da (10%), 20 da (5%), ... 100/dens = percentuale cellule vive

main ()
{
int i,j;
BOOL cella;
int righe = 15;
int colonne = 15;
int matrice [righe] [colonne];
char c;
int dado;
srand(time(NULL));
int somma;  //calcola gli elementi attorno

printf("\nGenero mondo:\n");
for (i=0; i < righe; i++) {         //matrice inizializzata a 0 e stampata
    for (j=0; j < righe; j++) {
            matrice [i] [j] = 0;
            printf(" %d", matrice [i] [j] );
    }
    printf("\n");
}

//input
printf("\nInserimento casuale cellule vive:\n");
for (i=0; i < righe; i++) {
    for (j=0; j < righe; j++) {
            dado = rand()% DENS;        //resituisci un valore random da 0 a n-1;
            if (dado == 0) {
            matrice [i] [j] = 1;
            }
            printf(" %d", matrice [i] [j] );
    }
    printf("\n");
}






printf("Premi s per continuare gli stati o qualsiasi altra lettera per terminare: \n");
scanf("%c", &c);

while (c == 's') {

    fflush(stdin);
    system("CLS");
    printf("Premi s per continuare gli stadi o qualsiasi altra lettera per terminare: \n");


    //nascite e morti
    for (i=0; i < righe; i++) {
        for (j=0; j < righe; j++) {
            somma = matrice [i-1] [j-1] + matrice [i-1] [j] + matrice [i-1] [j+1] + matrice [i] [j-1] + matrice [i] [j+1] + matrice [i+1] [j-1] + matrice [i+1] [j] + matrice [i+1] [j+1] ;
            if (somma == 3 ) {
             matrice [i] [j] = 1;
            }
            else  {
             matrice [i] [j] = 0;
            }

        }
    }

    //stampa matrice
    for (i=0; i < righe; i++) {
        for (j=0; j < righe; j++) {

            printf(" %d", matrice [i] [j] );
        }
        printf("\n");
    }



    scanf("%c", &c);


}


return 0;
}
