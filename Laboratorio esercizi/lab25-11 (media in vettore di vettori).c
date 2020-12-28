
/*programma per far inserire 3 risposte da 1 a 5 a ciascuno degli utenti che possono incrementare*/
/*Poi il programma fa la media delle risposta A, B , C; Poi in maniera statistica il programma deve dire quanti hanno risposto 1 alla domada A, 2 alla domanda A, 3... ecc..*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_DOMANDE 3
#define NUM_RISPOSTE 5

typedef struct {
    int risposta[NUM_DOMANDE];
} Risposte;


int main () {

int i, j, risposta;
int utente = 0;

char nuovo_u= 's';


Risposte *elenco;

char domande[NUM_DOMANDE][50] = {   //ogni domanda non potrà superare i 49 caratteri
    "Domanda 1",
    "Domanda 2",
    "Domanda 3"
};



elenco = (Risposte * ) malloc (sizeof(Risposte));
if(elenco == NULL) {
    exit(1);
}
for (i=0;i<NUM_DOMANDE; i++) {
    printf("Utente posizione %d :", utente);
    printf(domande[i]);
    printf(" >inserire 1,2,3,4,5 : ");
    scanf ("%d", &risposta);
    while (risposta < 1 || risposta > 5) {
        printf("Scelta non valida! reinserisci: ");
        scanf ("%d", &risposta);
    }
    elenco[utente].risposta[i] = risposta;
}

printf("\n Vuoi un altro? inserisci s per si  : ");
fflush(stdin);
scanf("%c", &nuovo_u);

while (nuovo_u == 's' || nuovo_u == 'S') {
    utente++;
    elenco = (Risposte * ) realloc (elenco , (utente + 1) * sizeof(Risposte));
    if(elenco == NULL) {
        exit(1);
    }
    for (i=0;i<NUM_DOMANDE; i++) {
        printf("Utente posizione %d :", utente);
        printf(domande[i]);
        printf(" >inserire 1,2,3,4,5 : ");
        scanf ("%d", &risposta);
        while (risposta < 1 || risposta > 5) {
            printf("Scelta non valida! reinserisci: ");
            scanf ("%d", &risposta);
        }
        elenco[utente].risposta[i] = risposta;
    }

    printf("\n Vuoi un altro? inserisci s per si  : ");
    fflush(stdin);
    scanf("%c", &nuovo_u);

}


//STATISTICHE

int somma[NUM_DOMANDE]; //array somma con il numero domande
int risposte [NUM_DOMANDE] [NUM_RISPOSTE];

for (j=0; j <= NUM_DOMANDE; j++){
    somma[j]= 0 ;

    for (i=0; i < NUM_RISPOSTE; i++) {
        risposte[j][i] = 0;
    }
    for (i = 0; i <= utente; i++){
        somma[i] += elenco[i].risposta[j];
        risposte [j] [elenco[i].risposta[j]-1]++;
    }

}
printf("\nLA MEDIA della domanda 1  e' : %d", somma[1]);



//fine
printf("\n\n");
return 0;
}
