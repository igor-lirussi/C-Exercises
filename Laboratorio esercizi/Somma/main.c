#include <stdio.h>
#include <stdlib.h>

// Il file .h e il file.c per convenzione hanno lo stesso nome

//Il file .c ha la definizione delle funzioni (tutto ciò che deve fare)

//Il file .h ha la dichiarazione delle funzioni (solo quella) si usa come riferimento di inclusione

//File -> New -> Project -> Console Application

//file nuovo nome.c e dentro tutte le implementazioni delle funzioni
//file nuovo nome.h e dentro ci mettiamo i prototipi delle funzioni

#include "somma.h"

int somma ( int a, int b);

int main()
{
    int ris;

    ris = somma ( 5 , 4);

    printf("%d", ris);

    return 0;


}


//è possibile l'esecuzione in modalità debug freccia rossa, se si mettono i break point (pallini rossi) il prgramma si blocca a quella riga
//per andare avanti si usa il tasto vicino alla frecia che ti permette di fare il passo successivo

//si fa partire la modalità debug, si seleziona una variabile e con il tasto destro si fa Whatch
// in Debug -> Debugghing Windows -> Watches si vedono le variabili correnti
