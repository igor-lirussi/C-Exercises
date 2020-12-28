#include <stdio.h>

main() {

// verificare se una digitazione sia un numero o una lettera
char lettera;
printf(" LETTERA O NUMERO? \n");
printf("inserisci una singola lettera o un singolo numero: \n");

scanf ("%c", &lettera );

    switch (lettera)
        {
        case 65 ... 90:
            printf("hai inserito lettera maiuscola");
            break;
        case 97 ... 122: // oppure case 'a' ... 'z' :
            printf("hai inserito lettera minuscola");
            break;
        case 48 ... 57:
            printf("hai inserito numero");
            break;
        default:
            printf("nessun riscontro");
        }





//dati n valori fare la media
/*media valori*/
printf("\n\n CALCOLO MEDIA \n");
int i, somma;
int voto, check;
float media;
somma = 0;
check = 1;

for (i=0;check == 1;i++)
    {
    check = scanf("%d", &voto); // check assume valore 0 se voto non è un intero

    if (check == 1)
        {
         somma +=voto;
        }
    }


if (i>1) {
    media = (float)somma / (i-1);
    printf("media :%f", media);
    }
else{
    printf("nessun valore inserito");
    }






//preso in ingresso num intero maggiore di 0 indicare tutti i divisori
/*DIVISORI*/

printf("\n\n DIVISORI \n\n");
int num, divisore, resto;
fflush(stdin);
printf("inserisci un numero maggiore di 0:");
scanf("%d", &num);

if (num <= 0)
    printf("\nnon valido");

printf("\ndivisori:\n");

printf("\n%d",num); //divisibile per se stesso
divisore = num/2;

while (divisore>0)
    {
    resto = num % divisore;
    if (resto==0)
        {
        printf("\n%d", divisore);
        }
    divisore -= 1;
    }
// variante con il FOR
/*
for (i=2;i<=n/2;i++) {
    if (n%i==0) {
        printf("%d\n",i);
    }

    }
printf("%d",n);
*/




//dato un numero indicare se e' primo oppure no (primo = maggiore di uno e divisibile solo per se stesso)
printf("\n\n NUMERO PRIMO?\n\ninserisci un numero:");
int prim;
scanf("%d", &prim);
if (num<=1)
    printf("\nnon valido\n");

divisore = prim/2;
while (divisore > 1){
    if (prim%divisore==0)
        {
        printf("\n non e' primo!\n");
        divisore = 0;
        }
    else
    divisore-=1;
    }

if (divisore==1) {
    printf(" E' primo!");
    }




//dato un numero indicare tutti i numeri primi inferiori
printf("\n NUMERI PRIMI INFERIORI A  \n");

int z, ha_divisori;
printf("dammi un numero: ");
scanf("%d", &z);

for (ha_divisori=0;z>1 ; z--){
    ha_divisori=0;
    for (divisore=z/2; divisore>=2 && ha_divisori ==0 ; divisore--)

    if ( z % divisore == 0 ) {
        ha_divisori++;
        }

    }

if (ha_divisori==0) {
    printf("%d \n", z);
    }



return 0;
}
