#include <stdio.h>


struct Caratteristiche {
    int altezza;
    int peso;

};


struct Utente {         //in memoria non è stato allocato nessun dato
    int altezza;        //è come definire un tipo di dato.. int, char, struct Utente,
    int annoNascita;
    char nome [20];
    char cognome[20];
    struct Caratteristiche dati;    //variabile chiamata dati di tipo struct Caratteristiche (CHE DEVE ESSERE DICHIARATA PRIMA)
};


int main () {

struct Utente u1;       //con la dichiarazione si alloca spazio in memoria
struct Utente u2;
struct Utente u3;

u1.altezza = 175;
u2.altezza = 180;
u3.altezza = 160;



printf("Altezza u1;%d \n", u1.altezza);            //nella printf
printf("Altezza u2;%d \n", u2.altezza);
printf("Altezza u3;%d \n", u3.altezza);



printf("\nOra inserici tu altezza u1: ");

scanf("%d", &u1.altezza);       //con la scanf va sempre &


printf(" \nOra Altezza u1: %d  \n", u1.altezza);

printf("Iniziale u1: %c", u1.nome[0]);

//array di strutture
struct Utente  utenti[10];      //un array utenti con 10 strutture di tipo Utente
utenti[2].altezza =150;



//STRUTTURE ANNIDATE
struct Utente   u;
u.dati.altezza = 190;

utenti[2].dati.altezza = 169;

// (*u).dati.altezza    (è uguale a scrivere)  u->dati.altezza
struct Utente   *pu;

pu = (struct Utente*)
malloc(sizeof(struct Utente));
if (pu == NULL) {
    exit(1);
}

//array di puntatori a strutture utente

struct Utente *elenco[10];

int i;
for (i=0;i<10;i++) {
    elenco[i] = (struct Utente*)
        malloc(sizeof(struct Utente));
    if (elenco[i] == NULL) {
        exit(1);
    }

}

for (i=0; i < 10; i++) {
    free(elenco[i]);
}



//fine
printf("\n\n");
return 0;
}
