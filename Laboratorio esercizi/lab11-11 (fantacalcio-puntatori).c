#include <stdio.h>
#define SQUADRA 11

struct Caratteristiche {
    char ruolo;
    char nome[10];
    char cognome[10];
};


main () {

int i;
struct Caratteristiche   *  giocatore[SQUADRA];


for (i=0;i<11;i++) {
    giocatore[i] = (struct Caratteristiche*)
        malloc(sizeof(struct Caratteristiche));
    if (giocatore[i] == NULL) {
        exit(1);
    }

}


printf("GIOCATORI E RUOLI\n");
printf("p=portiere, d=difensore, c=centrocampista, a=attacante \n");





for (i=0; i<SQUADRA; i++){
    printf("Inserisci nome giocatore %d:", i+1);
    scanf("%s", &giocatore[i]->nome);
    printf("Inserisci cognome giocatore %d:", i+1);
    scanf("%s", &giocatore[i]->cognome);
    fflush(stdin);
    printf("Inserisci ruolo giocatore %d:", i+1);
    scanf("%c", &giocatore[i]->ruolo);
    fflush(stdin);
    printf("\n");
}

printf("Hai inserito: \n");
for (i=0; i<SQUADRA; i++){
printf("\nGiocatore %d: \n", i+1);
printf("Nome : %s\tCognome: %s\tRuolo: %c\n",giocatore[i].nome, giocatore[i].cognome, giocatore[i].ruolo);
}

printf("\n\nIN ORDINE:\n");

printf("\nPortieri:\n");

for (i=0; i<SQUADRA; i++){
    if (giocatore[i].ruolo == 'p'){
        printf("\n Giocatore %d: \n", i+1);
        printf(" Nome : %s\tCognome: %s\tRuolo: %c\n",giocatore[i].nome, giocatore[i].cognome, giocatore[i].ruolo);
    }
}

printf("\nDifensori:\n");

for (i=0; i<SQUADRA; i++){
    if (giocatore[i].ruolo == 'd'){
        printf("\n Giocatore %d: \n", i+1);
        printf(" Nome : %s\tCognome: %s\tRuolo: %c\n",giocatore[i].nome, giocatore[i].cognome, giocatore[i].ruolo);
    }
}

printf("\nCentroacampisti:\n");

for (i=0; i<SQUADRA; i++){
    if (giocatore[i].ruolo == 'c'){
        printf("\n Giocatore %d: \n", i+1);
        printf(" Nome : %s\tCognome: %s\tRuolo: %c\n",giocatore[i].nome, giocatore[i].cognome, giocatore[i].ruolo);
    }
}
printf("\nAttaccanti:\n");

for (i=0; i<SQUADRA; i++){
    if (giocatore[i].ruolo == 'a'){
        printf("\n Giocatore %d: \n", i+1);
        printf(" Nome : %s\tCognome: %s\tRuolo: %c\n",giocatore[i].nome, giocatore[i].cognome, giocatore[i].ruolo);
    }
}






return 0;
}
