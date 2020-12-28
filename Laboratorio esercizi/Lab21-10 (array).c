
#include <stdio.h>

int main() {

    int a, i;

    int arr[10];

    a = 12;

    arr[9] = 129;                // L'identificativo dell' array parte da 0; in questo caso è l'ultima cella disponibile

    printf("a = %d \n", a);
    printf("arr 9 = %d \n", arr[9]);                    //stampare un elemento di un array

    printf("inserisci a :");
    scanf("%d", &a);
    printf("inserisci arr 2 : ");       //inserire elemento in un array
    scanf("%d", &arr[2]);

    printf("Indirizzo prima cella: %d \n", &arr[0]);   //indirizzo di memoria della prima cella
    printf("Indirizzo quart cella: %d \n", &arr[3]);   //indirizzo di memoria della quarta cella

    printf("Indirizzo prima cella: %d \n", arr);       //indirizzo di memoria della prima cella
    printf("Indirizzo prima cella: %d \n", &arr);      //indirizzo di memoria della prima cella

    printf("\n\n\n");



/* inserimento dell'utente dei valori*/
    for (i=0; i<10; i++) {
        printf("inserisci valore di %d: ", i);
        scanf("%d ", &arr[i]);
        }
    for (i=0; i<10; i++) {
        printf("%d ", arr[i]);
        }


//INSERIMENTO IN ORDINE INVERSO

    for (i=9; i<=0; i--) {
        printf("inserisci valore di %d: ", i);
        scanf("%d ", &arr[i]);
        }
    for (i=9; i<=0; i--) {
        printf("%d ", arr[i]);
        }




//dato un array di valori interi acquisizione con for da parte di utente o a mano:
//  inizializzare array:
//  int elenco[10] = {1,12,34,55,23,12,8,0,6,7};  <- va fatto solo in caso di dichiarazione iniziale, NON si può fare dopo!

/* PROGRAMMA CHE FA IL REVERSE DEL CONTENUTO DELLE CELLE DELL' ARRAY */


#define MAX 10

//int elenco[MAX];
int tmp, k;
//riempito
int elenco[MAX] = {4,6,3,6,7,4,23,7,3,2};

for (k=9,i=0 ; i<MAX/2 ; i++) {             //il conatore non deve arrivare fino a MAX ma MAX/2
    tmp = elenco[k];                //k = MAX - 1 -i
    elenco[k] = elenco[i];
    elenco[i] = tmp;


    }



/*VALORE PIU' PICCOLO DELL' ARRAY*/
int minimo = 0;
minimo = elenco[0]; //se la variabile minimo è il primo volore dell'array allora rimane tale, altrimenti verrà sovrascritta, non serve mettere un valore alto apposta
for (i=0; i<MAX; i++) {
    if (elenco[i] < minimo) {
        minimo = elenco[i];
        }

    }


    //indice cella che contiene il minimo
int minimo_i = 0;

for (i=1; i < MAX; i++) {                   //di default la cella minima è la 0 poi la confronta con tutte le altre da 1 a MAX
    if (elenco[i] < elenco[minimo_i]){
        minimo_i = i;
        }


    }
    //stampare indice celle con il minimo

for (i = 1;  i < MAX; i++) {
    if (elenco[i] == elenco[minimo_i])
        printf("%d",i);

    }


// Dati dei valori in un array, ordinarli in modo crescente dal più piccolo al più grande.
/* ORDINAMENTO VALORI ARRAY */

int minim;

int ar2[5] = {3,4,5,7,4};       //array di n elementi


for ( k = 0 ; k< 5-1; k++) {   //k arriva fino a n-1 perchè non serve che trovi il minimo sull ultima cella

minim = k;

for (i= k+1; i<5; i++) {
    if (ar2[i]< ar2[minim]) {
        minim = i;
        }

    }
tmp = ar2[k];
ar2[0] = ar2[minim];
ar2[minim] = tmp;

}
return 0;
}
