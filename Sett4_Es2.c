#include <stdio.h>

#define MAX 31          //in un mese ci possono essere massimo 31 giorni

int main() {

int giorni1[MAX+1] = {0};       //gli array sono inizializzati completamente a 0.
int giorni2[MAX+1] = {0};       //lunghezza dei 2 array: la cella 31 è l'ultima di un arrai di 32 celle

int k, sum, none;


printf("Giorni di disponibilità di due persone. \n");

/* Il metodo scelto è far assumere il valore 1 alle celle dei vettori che corrispondono ai giorni di disponibilità */
//motivazioni:
// -viene effettuato un numero minore di passaggi (31) per confrontare parallelamente le celle con la stessa posizione tra due vettori
//  (prima con la prima .. fino alla trentunesima con la trentunesima)
//  rispetto a confrontare tutte le celle di un vettore con tutte le altre di un altri vettore (passaggi: 31 elevato al numero di persone), in riunioni con tante persone il volume di calcoli sarebbe insostenibile.
// -Inoltre questo metodo permette un più veloce controllo sulle date già inserite.
// -Può facilmente essere modificato per lavorare con più persone



//input prima persona
printf("\nPersona 1 : \nInserisci i giorni in cui sei disponibile : \n");

int i = 1;                  //la i fa partire il ciclo while
while ( i > 0 ) {           //finchè l'utente non termina l'acquisizione inserendo un numero negativo può continuare a inserire giorni di disponibilità
    scanf("%d", &i);        //input dell'utente

    if ( i > MAX){                  //se è maggiore del massimo lo avverte e il ciclo ricomincia
              printf("Il numero inserito non deve essere maggiore di %d \n", MAX);
            }
    else if (i > 0){                //altrimenti se è minore del massimo e positivo il programma va in esecuzione e memorizza la sua disponibilità
        if (giorni1[i] == 1){           //dove la giornata è già stata inserita l'utente viene avvertito
            printf("Hai gia' inserito questa data! Inseriscine un'altra: \n");
            }
        else {                          //altrmenti la disponibilità fa cambiare il valore della cella del giorno a 1
            giorni1[i] = 1;
            printf("Sei disponibile il %d del mese, per terminare l'acquisizione: -1 oppure prosegui\n", i);
            }
        }
    }


//input seconda persona
printf("\nPersona 2 : \nInserisci i giorni in cui sei disponibile : \n");

i = 1;                  //la i a 1 fa partire il ciclo while
while ( i > 0 ) {           //finchè l'utente non termina l'acquisizione inserendo un numero negativo può inserire giorni di disponibilità
    scanf("%d", &i);        //input dell'utente

    if ( i > MAX){          //se è maggiore del massimo lo avverte e il ciclo ricomincia
              printf("Il numero inserito non deve essere maggiore di %d \n", MAX);
            }
    else if (i > 0){        //altrimenti se è minore del massimo e positivo il programma va in esecuzione e memorizza la sua disponibilità
        if (giorni2[i] == 1){       //dove la giornata è già stata inserita l'utente viene avvertito
            printf("Hai gia' inserito questa data! Inseriscine un'altra: \n");
            }
        else {                      //altrmenti la disponibilità fa cambiare il valore della cella del giorno a 1
            giorni2[i] = 1;
            printf("Sei disponibile il %d del mese, per terminare l'acquisizione: -1 oppure prosegui\n", i);
            }
        }
    }


printf("\n\nI giorni possibili sono : ");

none = 1; //dato per vero il fatto che non ci siano giorni di disponibilità
for (k = 1; k <= MAX; k++ ) {           // per tutti i giorni da 1 a 31 (MAX)
    sum = giorni1[k] + giorni2[k];      //viene eseguita la somma delle celle di una posizione

    if (sum == 2) {                     //se la somma è uguale  a 2 viene stampato il giorno
        printf(" %d ", k);
        none = 0;                       //se in un giorno c'è disponibilità di tutti allora il fatto che non ci siano giorni di disponibilità viene tolto
    }
}

if (none == 1) {        //se alla fine dei calcoli non vengono trovati giorni di disponibilità viene restituito il fatto che non ci siano
    printf("nessuno");
    }

printf("\n\n");
return 0;
}
