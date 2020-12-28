#include <stdio.h>


void funzione_1();
char funzione_2();
int somma(int a, int b);

void stampa_array(int array[], int dim);


int G;  //varaibile globale
int i;


int main () {

    int A, R, i;
    char C;
    int *p;

    funzione_1();
    C = funzione_2();

    R = somma(5, 6);
    printf(" %d ",R);

    int numeri[] = {1,2,3};
//stampa vettore
    stampa_array(numeri, 3);



    printf("\n\n");
    return 0;
}

void funzione_1() {
    printf("A");


}

char funzione_2() {
    char K = 'p';
    funzione_1();
    printf("B");
    return K;
}

int somma (int a, int b) {
    int sum;
    sum = a + b;
    return sum;
}

void stampa_array(int array[], int dim) {
    int i = 0;
    for (i=0; i<dim; i++) {
            printf(" %d ", array[i]);
    }
}

