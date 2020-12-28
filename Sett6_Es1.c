#include <stdio.h>
#include <stdlib.h>
//valori booleani
#define BOOL int
#define FALSE 0
#define TRUE 1

main() {
//dichiaro le veariabili

int *p;                 //puntatore
int c;                  //contatore per il ciclo for
int num_elementi;       //conterrà il numero degli elementi del vettore
int num_ric;            //numero ricercato
BOOL riscontro = FALSE; //cambia in 1 se il numero cercato è presente
int minimo, massimo;    //dichiaro due variabili per minimo e massimo

printf("Inserisci il numero degli elementi da memorizzare: ");
scanf("%d", &num_elementi);

//controllo input
while (num_elementi < 3){       //ciclo in loop finchè l'utente inserisce il valore corretto
    printf("Il numero degli elementi da memorizzare non puo' essere minore di 3. Inseriscilo nuovamente: ");
    scanf("%d", &num_elementi);
}

//malloc
p = (int*) malloc(num_elementi * sizeof(int));  //alloco una dimensione di byte pari a quella di un intero per il numero di interi
//malloc restituisce puntatore a VOID per questo uso il cast e controllo se restituisce NULL:
if (p == NULL){
        printf("Non è possibile allocare tali byte in memoria!\n");
        return 0;
}


//inserimento valori

printf("\nInserisci gli elementi: \n");
for (c = 0; c < num_elementi; c++) {            //tramite il contatore (c) aumento la cella puntata dal puntatore
        printf(" %d^ numero :", c + 1);
        scanf("%d", p + c);                     //con la scanf in tale cella inserisco il valore che scrive l'utente
} //ora l'array è riempito con i valori che ha inserito l'utente


/*Ricerca valore*/
printf("\nRicerca valore \n");
//ricerca di un valore (aritmetica dei puntatori)
printf("\nInserisci il numero da trovare tramite aritmetica dei puntatori:");
scanf("%d", &num_ric);      //acquisisco il numero ricercato

for (c = 0; c < num_elementi; c++) {    //faccio un ciclo che controlla tutti gli elementi dell'array
        if (*(p + c) == num_ric) {                //se la cella corrente (cella prima puntata dal puntatore p sommata con senso al valore del contatore c)
            printf("Il numero e' il %d^ che si trova nella cella : %d \n",c+1, c); //ha lo stesso velore di quello cercato la stampa (Funziona anche se il numero è presente in più celle)
            riscontro = TRUE;   //viene definito il fatto che almento un numero sia stato trovato
            }
}

if (riscontro == FALSE) {   //se nessun numero viene trovato viene stampata la frase di notifica
    printf("Non e' presente tale numero! \n");
}

//ricerca di un valore (notazione vettoriale)
printf("\nInserisci il numero da trovare tramite notazoine vettoriale:");
scanf("%d", &num_ric);
riscontro = FALSE;  //il riscontro se viene trovato un numero diventerà TRUE

for (c = 0; c < num_elementi; c++) {    //faccio un ciclo che controlla tutti gli elementi dell'array
        if (p[c] == num_ric) {                                          //se la cella corrente del vettore
            printf("Il numero e' il %d^ che si trova nella cella : %d \n", c+1, c);    //ha lo stesso velore di quello cercato la stampa (Funziona anche se il numero è presente in più celle)
            riscontro = TRUE;   //viene definito il fatto che almento un numero sia stato trovato
            }
}

if (riscontro == FALSE) {   //se nessun numero viene trovato viene stampata la frase di notifica
    printf("Non e' presente tale numero! \n");
}
printf("\n");
system("PAUSE");


/*Ricerca minimo e massimo*/
printf("\nMassimo e minimo: \n\n");
//aritmetica dei puntatori
minimo = *p;        //minimo e massimo assumono il valore delle prima cella, se una è inferiore o minore vengono aggiornati
massimo = *p;

for (c = 0 ; c < num_elementi; c++) {       //ciclo che scorre tutti i valori del puntatore
        if (*(p+c) < minimo) {              //aggiornamento valori minimo e massimo
            minimo = *(p + c);
        }
        if (*(p+c) > massimo) {
            massimo = *(p + c);
        }
}

printf("Con aritmetica dei puntatori: \n");
printf("Minimo: %d  Massimo : %d \n\n", minimo, massimo);

//notazione vettoriale
minimo = p[0];        //minimo e massimo assumono il valore delle prima cella nuovamente
massimo = p[0];

for (c = 0 ; c < num_elementi; c++) { //ciclo che scorre e aggiorna gli elementi massimo e minimo
        if (p[c] < minimo) {
            minimo = p[c];
        }
        if (p[c] > massimo) {
            massimo = p[c];
        }
}

printf("Con notazione vettoriale: \n");
printf("Minimo: %d  Massimo : %d \n\n", minimo, massimo);

printf("\n");
system("PAUSE");

/*Reverse degli elementi*/
int supp;       //variabile di supporto

//con notazione vettoriale
printf("\nReverse elementi vettore con notazione vettoriale:\n");
//stampa elementi vettore
printf("Stampa elementi di partenza del vettore:\n");
for (c = 0 ; c < num_elementi; c++) {
    printf(" %d ", p[c]);
}
//reverse
printf("\nReverse... \n");
for (c = 0 ; c < (num_elementi/2); c++) {   //il ciclo avanza di celle fino a metà
    supp = p[c];                                // il contenuto della cella di sinistra viene copiato nella variabile di supporto
    p[c] = p[num_elementi - c - 1];             // il contenuto della cella di destra viene copiato nella cella di sinistra
    p[num_elementi - c - 1] = supp;             // il contenuto della variabile di supporto viene copiato nella cella di destra
}
printf("Stampa elementi vettore:\n");
for (c = 0 ; c < num_elementi; c++) {
    printf(" %d ", p[c]);
}
printf("\n\n");

//con aritmetica dei puntatori
printf("\nReverse elementi vettore con aritmetica dei puntatori:\n");
//stampa elementi vettore
printf("Stampa elementi di partenza del vettore:\n");
for (c = 0 ; c < num_elementi; c++) {
    printf(" %d ", *(p + c) );
}
//reverse
printf("\nReverse... \n");
for (c = 0 ; c < (num_elementi/2); c++) {
    supp = *( p + c ) ;                             //alla variabile supporto assegno il contenuto della cella designata dal puntatore + il contatore
    * ( p + c ) = * ( p + num_elementi - c - 1) ;   // PUNTO COMPLICATO: il puntatore viene fatto scorrere fino alla fine meno uno e meno la cella di sinistra, il valore puntato viene assegnato al contenuto della cella di sinistra
    * ( p + num_elementi - c - 1 ) = supp;          //alla cella di destra assegno il contenut della variabile di supporto
}
printf("Stampa elementi vettore:\n");
for (c = 0 ; c < num_elementi; c++) {
    printf(" %d ", *( p + c) );
}

printf("\n\n");
return 0;
}

