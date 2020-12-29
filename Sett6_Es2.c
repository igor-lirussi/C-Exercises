#include <stdio.h>

main() {
int a, b;       //dichiaro le variabili
char carattere; //tipo carattere
float num;      //tipo float
int vettore [5] = {7, 3, 5, 73, 23};    //vettore
int i ;         //contatore per il vettore


a = 4;          //assegno un valore alle variabili
b = 9;
carattere = 'h';
num = 1.583871;

int *p_a;       //dichiaro i puntatori dello stesso tipo delle variabili a cui punteranno
int *p_b;
char *p_carattere;
float *p_num;
int *p_vettore;

p_a = &a;       //assegno ai puntatori il loro valore sulla base delle variabiil a cui puntano
p_b = &b;
p_carattere = &carattere;
p_num = &num;
p_vettore = vettore;

//stampo a video i valori tramite i puntatori
printf("\nIl valore di b e' : %d  Quello del suo puntatore e' : %p \n\n", *p_b, p_b);
printf("Valori espressi attraverso puntatori: \n");
printf(" Valore di a : %d \n Valore di carattere : %c \n Valore di num: %f \n\n", *p_a, *p_carattere, *p_num );

printf("Il vettore contiene: ");    //lavoro sul vettore tramite i puntatori
for (i = 0; i < 5; i++) {

    printf("%d ",*p_vettore);
    p_vettore += 1;     //aumento con senso il valore del puntatore

}

//il puntatore da ora se lo si vuole utilizzare punterà all'ultimo elemento del vettore

printf("\n\n\n");
return 0;
}

