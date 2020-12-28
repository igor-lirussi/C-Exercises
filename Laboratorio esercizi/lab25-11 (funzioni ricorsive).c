//(1)stampa di array di interi da 0 a n-1
//(2)stampa di array da n-1 a 0
//(3)somma di un array di interi
//(4)media di un array di interi
//(5)minimo di un array di interi
//(6)reverse di un array di interi

// PER COSTRUIRE UNA FUNZIONE RICORSIVA
//in gerale:
    //bisogna trovare il passo ricorsivo, blocco di codice che si ripete tutte le volte,
    //attenzione a imporre la condizione d'arresto (l' if in questo caso)
//passo passo:
    // 1) Trovare l'azione che si farebbe la prima volta (ES: se  elenco[3] < min  allora  min = elenco [3]
    // 2) Portare l'azione a diventare generale  (ES: se elenco[variabile passata nella funzione] < min passato dalla funzione  allora  passa come minimo elenco[var]
    // 3) Richiamare la funzione con il valore successivo (ES: funzione_minimo(elenco, i+1, min)
    // 4) Cercare di bloaccare il ciclo infinito che si è creato con una condizione d'arresto (ES:  se ( i < dimensione vettore) allora esegui, quando supera la dimensione vettore non sesguire nulla


#include <stdio.h>
#include <stdlib.h>

#define DIM 5 //lunghezza array

main() {

int elenco[DIM] = { 2, 4, 6 , 8, 10 };
int i;


/*(1)*/
printf("(1)stampa di array di interi da 0 a n-1\n");

    printf("\nParte iterativa \n");
    for (i = 0; i< DIM; i++) {
        printf("%d ", elenco[i]);
    }

    printf("\nParte ricorsiva \n");

    stampa (elenco, 0, DIM);

    printf("\n\n\n");

/*(2)*/
printf("(2)stampa di array da n-1 a 0");

    printf("\nParte iterativa \n");
    for (i = DIM-1; i >= 0; i--) {
        printf("%d ", elenco[i]);
    }

    printf("\nParte ricorsiva \n");
    stampareverse (elenco, 0, DIM);

    printf("\n\n\n");


/*(3)*/
printf("(3)somma di un array di interi");


    printf("\nParte iterativa \n");
    int sum=0;
    for (i = 0; i< DIM; i++) {
        sum += elenco[i];
    }
    printf("Somma: %d", sum);


    printf("\nParte ricorsiva ");

    printf("\n Metodo 1 [Modifica puntatore passato]\n");
    sum = 0;
    int *sum1;
    sum1 = &sum;
    somma(elenco, 0, DIM, sum1);
    printf("  Somma: %d", *sum1);


    printf("\n Metodo 2 [Ritorno valore]\n");
    int sum2 = 0;
    sum2 = somma2 (elenco, 0, DIM);
    printf("  Somma: %d", sum2);

    printf("\n\n\n");

/*(4)*/
//la media si fa come la somma solo / la dimensione (DIM in questo caso)
printf("(4)media di un array di interi");

    printf("\nLa media viene fatta come la (3)somma \n basta solo dividerla per la dimensione vettore");


    printf("\n\n\n");

/*(5)*/
printf("(5)minimo di un array di interi");

    printf("\nParte iterativa \n");
    int min = elenco[0];
    for (i = 0; i < DIM; i++) {
        if(elenco[i] < min){
            min = elenco[i];
        }
    }
    printf("  Minimo: %d", min);


    printf("\nParte ricorsiva ");

    printf("\n Metodo 1 [Modifica puntatore passato]\n");
    min = elenco[0];
    int *p_min;
    p_min = &min;
    minimo (elenco, 0, DIM, p_min);
    printf("  Minimo: %d", *p_min);

    printf("\n Metodo 2 [Ritorno valore]\n");
    int min2 = elenco[i];
    min2 = minimo2(elenco, 0, DIM);
    printf("  Minimo: %d", min2);

    printf("\n\n\n");



/*(6)*/
printf("(6)reverse di un array di interi");

    printf("\nParte iterativa \n");
    int tmp;
    for (i = 0; i < DIM/2; i++){
        tmp = elenco[i];
        elenco[i] = elenco[(DIM-1)-i];    // DIM-1 è l'ultima cella di un vettore[DIM]
        elenco[(DIM-1)-i] = tmp;          // DIM-1 è l'ultima cella di un vettore[DIM]
    }
    stampa (elenco, 0, DIM);

    printf("\nParte ricorsiva \n");

    reverse (elenco, 0, DIM);

    stampa (elenco, 0, DIM);



    printf("\n\n\n");

    return 0;
}



/*FUNZIONI*/



void stampa(int elenco[], int i, int d) {
    if (i < d){
        printf("%d ", elenco[i]);
        stampa (elenco, i+1,  d);
    }
}
void stampareverse(int elenco[], int i, int d) {
    if (i < d){
        printf("%d ", elenco[d-1]);
        stampareverse (elenco, i,  d-1);
    }
}

 void somma(int elenco[], int i, int d, int *sum) {
    if (i<d) {
    *sum += elenco[i];
    somma(elenco, i+1, d, sum);
    }
}

int somma2(int elenco[], int i, int d) {
    if (i<d) {
     return elenco[i] + somma2(elenco, i + 1 , d);
    }
    return 0;
}

void minimo(int elenco[], int i, int d, int *min) {
    if(i<d) {
        if(elenco[i] < *min) {
            *min = elenco[i];
        }
        minimo(elenco, i+1 , d , min);
    }
}

int minimo2(int elenco[], int i, int d) {
    if(i < d-1) {
        int min;
        min = minimo2(elenco, i+1, d);
        if(elenco [i] < min) {
            return elenco[i];
        }
        else {
            return min;
        }
    }
    else {
        return elenco[i];
    }
}

void reverse (int elenco[], int i, int d) {
if (i < d) {
    //SWAP
    int tmp;
    tmp = elenco[i];
    elenco[i] = elenco[d-1];    // d-1 è l'ultima cella di un vettore[d]
    elenco[d-1] = tmp;          // d-1 è l'ultima cella di un vettore[d]

    reverse (elenco, i+1 , d-1);
    }
}







