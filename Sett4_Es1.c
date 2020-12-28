#include <stdio.h>
#include <math.h>   //serve per l'elevamento alla potenza
#define LNG 15      //LNG definisce la lunghezza scelta per il vettore che memorizza il numero in binario, da qui è facilmente modificabile
                    //inserendo il numero decimale massimo (es:per 15 è 32767) tutte le celle saranno riempite da 1

int main ()
{
int n, i, m;
int vet[LNG] = {0}; //vettore di LNG celle: da 0 a LNG - 1 , tutte inizializzate a 0.


printf ("Inserisci il numero da convertire in binario: ");
scanf ("%d", &n);                   //ingresso numero intero n
fflush(stdin);

//controlli
m = pow(2,LNG) - 1;     //il numero massimo decimale inseribile è correlato al numero di celle del vettore tramite questa formula
                        //ossia 2 elevato al numero di celle (LNG) meno 1

if ( n < 0 || n > m)  {     //nel caso in cui il numero inserito sia negativo o maggiore della lunghezza scelta del vettore
        printf("il numero deve essere compreso tra 0 e %d, inserisci nuovamente: ", m);
        scanf ("%d", &n);   //dopo aver dato l'avviso il programma torna a far inserire il numero all'utente
        }

//calcolo numero binario
i = 0;                          //inizializzato a 0 il contatore di cicli che definisce le celle del vattore su cui memorizzare
while ( n > 0 ){                //fino a che n è positivo

        vet[i]= n % 2;          //viene calcolato il resto del numero diviso 2 e memorizzato nella cella del vettore a partire dalla prima (0)
        n /= 2;                 //il numero viene diviso per due

        if (n > 0 ) {           //se il n è un intero maggiore di 0 anche dopo la divisione si passa alla prossima cella
            i++;                //serve nel caso in cui dopo la divisione n sia 0 e non venga incrementato i
            }
    }

printf("\nIl numero in binario corrisponde a : \n");

while (i >= 0){                   //stampa a ritroso fino alla cella 0, la prima (che dovrà contenere necessariamente un 1 se n > 0 )
        printf("%d", vet[i]);
        i--;
    }

return 0;
}
