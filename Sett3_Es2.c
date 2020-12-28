#include <stdio.h>
#include <stdlib.h>

int main () {

int voto_max = 10;          //il voto massimo inseribile
int numero_max = 30;        //il numero massimo di voti inseribili degli studenti
int numero_studenti = -1;   //il numero di studenti è inizializzato non valido affinchè il seguente ciclo di richiesta parta la prima volta
int i, voto;
int somma = 0;              //la somma complessiva è inizializzata a 0, poi verranno sommati i voti


for (;numero_studenti <= 0 || numero_studenti > numero_max;)    //inizia un ciclo che si ripete fino a che non viene inserito un numero di studenti valido
    {
    printf ("Inserire il numero totale degli studenti:");       //chiede all' utente di inserire il numero totale di studenti
    scanf ("%d", &numero_studenti);
    fflush(stdin);      //evita che inserendo un carattere vada in loop infinito il ciclo
    if (numero_studenti <= 0) {
        printf("il numero degli studenti non deve essere negativo o nullo!\n"); //se l'utente ha inserito un numero negativo viene avvisato e il ciclo riparte
        }
    if (numero_studenti > numero_max){
        printf("il numero degli studenti non deve essere maggiore di %d.\n", numero_max); // se l'utente ha inserito un numero oltre il massimo viene avvisato e il ciclo riparte
        }
    }


for (i = 1; i <= numero_studenti; i++)              //inizia un ciclo che si ripete fino al numero di studenti inserito
    {
    printf("inserisci il voto numero %d: ", i);     //viene inserito un voto e numerato a seconda del numero di cicli fatti
    scanf("%d", &voto);
    fflush(stdin);

    if (voto > 0 && voto <= voto_max){              //se il voto è valido viene aggiunto alla somma complessiva
        somma += voto;
        }

    else {                                          //se il voto non è valido non viene sommato
        printf ("voto non valido, deve essere maggiore di 0 e minore di %d \n", voto_max);
        i--;             //fa si che il voto venga reinserito senza perderlo sul numero totale, il ciclo si ripete una volta in più poichè questo giro viene scartato
        }
    }


printf("\nLa media dei %d voti e': %.2f \n\n",numero_studenti, (float)somma/numero_studenti); //viene stampata la media ossia la somma fratto il numero di studenti






/*Con il WHILE*/
printf("\n\n\nUtilizzando il while:\n");

numero_studenti = 0;    //il numero di studenti è inizializzato nullo affinchè il ciclo di richiesta riparta la seconda volta
somma = 0;              //la somma complessiva è nuovamente azzerata


while (numero_studenti <= 0 || numero_studenti > numero_max)    //inizia un ciclo che si ripete fino a che non viene inserito un numero di studenti valido
    {
    printf ("Inserire il numero totale degli studenti:");       //chiede all'utente di inserire il numero totale di studenti
    scanf ("%d", &numero_studenti);
    fflush(stdin);
    if (numero_studenti <= 0) {
        printf("il numero degli studenti non deve essere negativo o nullo!\n"); //se l'utente ha inserito un numero negativo viene avvisato e il ciclo riparte
        }
    if (numero_studenti > numero_max){
        printf("il numero degli studenti non deve essere maggiore di %d.\n", numero_max); // se l'utente ha inserito un numero oltre il massimo viene avvisato e il ciclo riparte
        }
    }

i = 1;       //scelto come i il contatore viene posto a 1 per il primo voto
while ( i <= numero_studenti )              //inizia un ciclo che si ripete fino al numero di studenti inserito
    {
    printf("inserisci il voto numero %d: ", i);     //viene inserito un voto e numerato a seconda del numero di cicli fatti
    scanf("%d", &voto);
    fflush(stdin);

    if (voto > 0 && voto <= voto_max){              //se il voto è valido viene aggiunto alla somma complessiva
        somma += voto;
        i++;                                        //aumenta di uno il contatore di ciclo
        }

    else {                                          //se il voto non è valido non viene sommato e il ciclo si ripete
        printf ("voto non valido, deve essere maggiore di 0 e minore di %d \n", voto_max);
        }

    }


printf("\nLa media dei %d voti e': %.2f \n\n",numero_studenti, (float)somma/numero_studenti); //viene stampata la media ossia la somma fratto il numero di studenti


return 0;

}
