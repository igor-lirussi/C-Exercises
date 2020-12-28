#include <stdio.h>

#define MAX 50
//PRESI 2 ARRAY DIRE SE SONO UGUALI E EVENTUALMENTE QUALI CELLE
int main() {
int elenco1[MAX];
int elenco2[MAX];
int dim1, dim2, i;

//ricordarsi di fare i controlli sull input
dim1 = -1;
dim2 = -1;

while (dim1 < 1 || dim1 > MAX) {  //fino a che l'utente inserisce valori sbagliati il programma chiede di reinserirli
    printf("dimensione 1: ");
    scanf("%d", &dim1);
    fflush(stdin);
}

for(i = 0 ; i < dim1 ; i++) {
    printf("valore %d :", i);
    scanf("%d", &elenco1[i]);
    fflush(stdin);
    }

printf("\n");

while (dim2 < 1 || dim2 > MAX) {
    printf("dimensione 2: ");
    scanf("%d", &dim2);
    fflush(stdin);
}

for(i = 0 ; i < dim2 ; i++) {
    printf("valore %d :", i);
    scanf("%d", &elenco2[i]);
    fflush(stdin);
    }





return 0;
}

