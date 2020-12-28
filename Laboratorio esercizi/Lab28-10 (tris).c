#include <stdio.h>
#define M 3 //righe
#define N 3 //colonne
int main ()
{

/*Tris*/

printf("Tris: \n\n");

char parola1[10];
char parola2[10];


printf("\nParole uguali?\n");

printf("inserisci p1: ");
scanf("%s", parola1); // si ferma agli spazi
printf("p1: %s\n", parola1);

printf("\ninserisci p2: ");
scanf("%s", parola2);
printf("p2: %s\n", parola2);

//vedere se due stringhe sono uguali
int uguali, i;
uguali = 1;
for (i=0; i<10 && uguali ==1 && parola1[i] != '\0' && parola2[i] != '\0' ; i++) {
        if (parola1[i] != parola2[i] ){
            uguali = 0 ;
        }

}

if (uguali == 1 && i<10 && parola1[i] == '\0' && parola2[i] == '\0') {
printf("\n\nsono uguali\n\n");
}
else {
        printf("\n\n\nnon sono uguali\n\n");
        }

/* TRIS*/

char matrice[3] [3] = {'1','2','3','4','5','6','7','8','9'};
int j, mossa;
srand(time(NULL));
int turno = (rand()%2)+1; //il turno va a caso tra giocatore 1 o 2

printf("\nINIZIO!\n\nQuesta partita la inizia il giocatore %d : ", turno);
if (turno == 1) {
    printf("%s", parola1);
}
if (turno == 2) {
    printf("%s", parola2);
}
printf("\n>Inserisci il numero dove vuoi giocare:\n");
//matrice
for (i=0; i<3 ; i++) {
        for (j=0; j<3; j++) {
        printf(" %c ", matrice [i] [j]);
        }
        printf("\n");
}
//mosse
printf("\nMossa giocatore 1: ", turno);
fflush(stdin);
scanf("%d", &mossa);
switch (mossa) {
case 1:matrice [0] [0] = 'X'; break;
case 2:matrice [0] [1] = 'X'; break;
case 3:matrice [0] [2] = 'X'; break;
case 4:matrice [1] [0] = 'X'; break;
case 5:matrice [1] [1] = 'X'; break;
case 6:matrice [1] [2] = 'X'; break;
case 7:matrice [2] [0] = 'X'; break;
case 8:matrice [2] [1] = 'X'; break;
case 9:matrice [2] [2] = 'X'; break;
default: printf("Non valida!\n");
}
//matrice
for (i=0; i<3 ; i++) {
        for (j=0; j<3; j++) {
        printf(" %c ", matrice [i] [j]);
        }
        printf("\n");
}
//mosse
printf("\nMossa giocatore 2: ");
fflush(stdin);
scanf("%d", &mossa);
switch (mossa) {
case 1:matrice [0] [0] = 'O'; break;
case 2:matrice [0] [1] = 'O'; break;
case 3:matrice [0] [2] = 'O'; break;
case 4:matrice [1] [0] = 'O'; break;
case 5:matrice [1] [1] = 'O'; break;
case 6:matrice [1] [2] = 'O'; break;
case 7:matrice [2] [0] = 'O'; break;
case 8:matrice [2] [1] = 'O'; break;
case 9:matrice [2] [2] = 'O'; break;
default: printf("Non valida!\n");
}
//matrice
for (i=0; i<3 ; i++) {
        for (j=0; j<3; j++) {
        printf(" %c ", matrice [i] [j]);
        }
        printf("\n");
}




printf("\n\n\n");
return 0;
}
