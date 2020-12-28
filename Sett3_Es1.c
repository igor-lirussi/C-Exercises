#include <stdio.h>
#include <stdlib.h>


main () {

int righe = -1;         //righe e colonne sono inizializzate non valide in modo da far partire il ciclo di input
int colonne = -1;
int valore_max = 15;    //valore massimo ammissibile di righe e colonne
int i, z;

printf("Tavole pitagoriche\n\n");
printf("La prima riga e la prima colonna riguardanti rispettivamente il primo e il secondo termine dell'operazione non vengono conteggiati. \n\n");
printf("Entrambe le tabelle partono da 0 come primo termine. \n\n");

//input righe e colonne
while (righe <= 0 || righe > valore_max) {      //controlli sull'input dell'utente riguardo le righe
    printf("inserisci numero di righe:");       //il ciclo continua fino a quando l'utente inserisce un numero valido
    scanf("%d", &righe);
    fflush(stdin);          //permette di non far andare il ciclo in loop infinito nel caso, esempio, in cui l'utente inserisca un carattere

    if (righe <= 0 || righe > valore_max) {
    printf("\nIl numero di righe deve essere compreso tra 1 e %d. \n\n", valore_max); //avviso in caso di inserimento non valido
    }

}

while (colonne <=0 || colonne > valore_max) {   //controlli sull'input riguardo le colonne
    printf("inserisci numero di colonne:");
    scanf("%d", &colonne);
    fflush(stdin);

    if (colonne <= 0 || colonne > valore_max) {                                     //se i valiori sono errati avvisa l'utente e riparte il ciclo
    printf("\nIl numero di colonne deve essere compreso tra 1 e %d. \n\n", valore_max);
    }

}



//spaziatura prima delle tabelle
printf("\n\n");



//FOR
printf("\nUtilizzando FOR:\n\n");

/*Addizione*/
printf("Addizione:\n\n");

printf("%5c", '+'); //stampa l'operatore usato in alto a sinistra

for ( i = 0; i < colonne; i++)      //stampa la prima riga equivalente al primo membro dell' addizione
    {
        printf("%5d", i);
    }
printf("\n");                       //va a capo e inizia la tabella

//stampa tabella
for (z = 0; z< righe; z++)
    {
    printf("%5d", z); //stampa il primo membro la prima colonna equivalente al secondo membro dell'addizione
    for (i = 0; i < colonne; i++)
        {

        printf("%5d", i + z); //somma il numero della colonna con il numero della riga
        }

    printf("\n"); //alla fine del ciclo delle colonne va alla riga successiva per ricominciarlo

    }


printf("\n\n"); //spaziatura tra le tabelle




/*Moltiplicazione*/
printf("Moltiplicazione:\n\n");

printf("%5c", '*'); //stampa l'operatore usato in alto a sinistra

for ( i = 0; i < colonne; i++)      //stampa la prima riga equivalente al primo membro della moltiplicazione
    {
        printf("%5d", i);
    }
printf("\n");                       //va a capo e inizia la tabella

//stampa tabella
for (z = 0; z< righe; z++)
    {
    printf("%5d", z); //stampa il primo membro la prima colonna equivalente al secondo membro della moltiplicazione

    for (i = 0; i < colonne; i++)
        {

        printf("%5d", i * z); //moltiplica il numero della colonna con il numero della riga
        }

    printf("\n"); //alla fine del ciclo delle colonne va alla riga successiva per ricominciarlo

    }


printf("\n\n\n\n"); //spaziatura tra le tabelle




//WHILE
printf("\nUtilizzando WHILE:\n\n");

/*Addizione*/
printf("Addizione:\n\n");

printf("%5c", '+'); //stampa l'operatore usato in alto a sinistra
i = 0;
while ( i < colonne)      //stampa la prima riga equivalente al primo membro dell' addizione
    {
        printf("%5d", i);
        i += 1;
    }
printf("\n");                       //va a capo e inizia la tabella

//stampa tabella
z = 0;
while (z < righe)
    {
    printf("%5d", z); //stampa il primo membro la prima colonna equivalente al secondo membro dell'addizione

    i=0;
    while ( i < colonne )
        {

        printf("%5d", i + z); //somma il numero della colonna con il numero della riga
        i += 1;
        }

    z += 1;
    printf("\n"); //alla fine del ciclo delle colonne va alla riga successiva per ricominciarlo

    }


printf("\n\n"); //spaziatura tra le tabelle




/*Moltiplicazione*/
printf("Moltiplicazione:\n\n");

printf("%5c", '*'); //stampa l'operatore usato in alto a sinistra

i = 0;
while ( i < colonne )      //stampa la prima riga equivalente al primo membro della moltiplicazione
    {
        printf("%5d", i);
        i += 1;
    }
printf("\n");                       //va a capo e inizia la tabella

//stampa tabella
z = 0;
while ( z < righe )
    {
    printf("%5d", z); //stampa il primo membro la prima colonna equivalente al secondo membro della moltiplicazione

    i = 0;
    while ( i < colonne )
        {

        printf("%5d", i * z); //moltiplica il numero della colonna con il numero della riga
        i++;
        }


    z ++;
    printf("\n"); //alla fine del ciclo delle colonne va alla riga successiva per ricominciarlo

    }



printf("\n\n"); //spaziatura finale

return 0;

}
