

#include <stdio.h>
#include <stdlib.h>

//FUNZIONI

int inserimento_num_venditori ();       //ritorna il numero dei venditori

int inserimento_num_prodotti ();        //ritorna il numero dei prodotti

void stampa_venditori(int); //stampa la lista dei codici dei venditori

void stampa_prodotti(int);  //stampa la lista dei codici dei prodotti


//VARIABILE GLOBALE CHE TIENE IL CONTO DEI GIORNI
static int giorno = 0;



main () {

int somma;

int cod_vend = -1;  //codici temporanei
int cod_prod = -1;

int i, j, h, k, f, c;   //variabili per cicli

int quant = 0;      //variabile quantitativo venduto

int num_vend = 0;   //variabili numero dei venditori e dei prodotti
int num_prod = 0;

char menu = 'm';    //ristampa il menu'
int scelta = 0;     //la scelta nel menu'
char new_day = 'n';     //evita la richiesta di uscita quando si sceglie nuovo giorno



printf("\n\t\t>>> Benvenuto <<<\n");

printf("\n\nQuesto programma prende in considerazione 2 fattori:\n");
printf("\n -In genere in un azienda ci sono piu' prodotti che venditori\n");
printf("\n -In genere in un azienda e' piu' facile che vari il numero di venditori\n");
printf("\n\nIl programma e' stato ottimizzato per essere modificato facilmente nel caso \n vari tale numero e funziona comunque con piu' venditori che prodotti.\n\n\n\n\n\n");

system("PAUSE");
system("cls");

printf("\n\t\t>>> Introduzione <<<\n");

num_vend = inserimento_num_venditori ();    //inserimento con controllo numero venditori
stampa_venditori(num_vend); //funzione stampa

num_prod = inserimento_num_prodotti ();     //inserimento con controllo numero prodotti
stampa_prodotti(num_prod);      //funzione stampa prodotti

struct Giorni {
    int matrice [num_vend][num_prod];   //creazione della struttura con matrice venditori (righe) X prodotti(colonne)
};

struct Giorni * p ; //puntatore a struttura

p = (struct Giorni * )malloc(sizeof(struct Giorni));    //allocazione prima struttura
if ( p == NULL) {
    printf("\n\nErrore allocazione memoria\n\n");
    exit(1);
}

//inizializzo matrice a 0
for (i = 0; i < num_vend; i++ ) {
    for (j = 0; j < num_prod; j++) {
        (*p).matrice [i] [j] = 0;   //pongo la cella corrente a 0
    }
}


system("PAUSE");
system("cls");


while (menu == 'm') {
    cod_vend = -1;  //codici resettati ad ogni comparsa del menu'
    cod_prod = -1;

    new_day = 'n';  //reset della richiesta di uscita
    system("cls");
    printf("\n\t\t>>> Menu' <<<\n");

    printf("\n\t\t\t\t\tGiorno %d\n", giorno);

    printf("\n1>Inserisci vendite di oggi.\n");
    printf("\n2>Vendite totali.\n");
    printf("\n3>Classifiche.\n");
    printf("\n4>Prossimo giorno.\n");
    printf("\n5>Esci dal programma.\n");

    printf("\n\n\nDigita il numero corrispondente all'azione scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:                 //inserimento vendite
            system("cls");
            printf("\n\t>Inserisci vendite di oggi.\n\n");
            printf("\nLe vendite sono aggiornabili nell'arco di tutta la giornata.\n\n");
            stampa_venditori(num_vend); //FUNZIONE STAMPA VENDITORI
            while (cod_vend < 0 || cod_vend > num_vend-1) {
                printf("Inserisci codice venditore valido(da 0 a %d): ", num_vend-1);
                scanf("%d", &cod_vend);     //memorizzo nelle variabili
                fflush(stdin);
            }
            stampa_prodotti(num_prod);      //FUNZIONE STAMPA PRODOTTI
            while (cod_prod < 0 || cod_prod > num_prod-1){
                printf("Inserisci codice prodotto valido(da 0 a %d): ", num_prod-1);
                scanf("%d", &cod_prod);
                fflush(stdin);
            }
            printf("Inserisci quantita' prodotto venduta: ");
            scanf("%d", &quant);
            fflush(stdin);
            (*(p+giorno)).matrice [cod_vend] [cod_prod] = quant;    //inserimento nella matrice del quantitativo
            printf("\n Il venditore codice %d ha venduto %d quantita' del codice prodotto %d.\n", cod_vend, quant, cod_prod);
            printf("\n Le quantita' sono state aggiornate correttamente.\n\n");

            break;

        case 2:
            system("cls");
            //totali
            printf("\n\t>Vendite totali.\n\n");
            printf("\nVendite dei venditori:\n");
            for (i = 0; i < num_vend; i++) {
                somma = 0;
                for (j = 0; j < num_prod; j++) {
                        for (h = 0; h <= giorno; h++){      //scorro anche i giorni
                            somma += (*(p+h)).matrice [i] [j];
                        }
                }
                printf("\tLe vendite totali del venditore con codice %d sono: %d \n", i, somma);    //stampo la somma vendite per ogni venditore
            }
            printf("\nVendite Prodotti:\n");
            for (i=0; i<num_prod; i++) {
                somma = 0;
                for (j=0;j<num_vend; j++) {
                        for (h = 0; h <= giorno; h++){
                            somma += (*(p+h)).matrice [j] [i];
                        }
                }
                printf("\tLe vendite totali del prodotto con codice %d sono: %d \n", i, somma);
            }
            //odierne
            printf("\n\n\n\t>Vendite odierne.\n\n");
            printf("\nVendite dei venditori:\n");
            for (i=0; i<num_vend; i++) {
                somma = 0;
                for (j=0;j<num_prod; j++) {
                    somma += (*(p+giorno)).matrice [i] [j];
                }
                printf("\tLe vendite odierne del venditore con codice %d sono: %d \n", i, somma);
            }
            printf("\nVendite Prodotti:\n");
            for (i=0; i<num_prod; i++) {
                somma = 0;
                for (j=0;j<num_vend; j++) {
                    somma += (*(p+giorno)).matrice [j] [i];
                }
                printf("\tLe vendite odierne del prodotto con codice %d sono: %d \n", i, somma);
            }

            break;

        case 3:
            system("cls");
            printf("\n\t>Classifiche odierne.\n\n");
            h=0;
            k=0;
            for (i=0; i<num_vend; i++) {
                for (j=0;j<num_prod; j++) {
                    if ( (*(p+giorno)).matrice [i] [j] > (*(p+giorno)).matrice [h] [k] ){
                        h = i;
                        k = j;
                    }
                }
            }
            printf("\nIl venditore che ha venduto piu' prodotti oggi e' stato quello con il codice : %d \n", h);        //stampa venditore e prodotto con vendite più alte
            printf("\nIl prodotto che e' stato venduto di piu' oggi e' stato quello con il codice : %d \n ", k);
            printf("\t ...e' stato venduto %d volte dal venditore %d. \n \n ", (*(p+giorno)).matrice [h] [k], h );

            printf("\n\t>Classifiche totali.\n\n");
            h=0;
            k=0;
            c=0;
            for (i=0; i<num_vend; i++) {
                for (j=0;j<num_prod; j++) {
                    for (f = 0; f <= giorno; f++) {
                        if ( (*(p+f)).matrice [i] [j] > (*(p+c)).matrice [h] [k] ){
                            h = i;
                            k = j;
                            c = f;
                        }
                    }
                }
            }
            printf("\nIl venditore che ha venduto piu' in assoluto e' stato quello con il codice : %d \n", h);
            printf("\nIl prodotto piu' venduto in assoluto e' stato quello con il codice : %d \n ", k);
            printf("\t ... oggi il suo massimo e' stato: %d volte dal venditore %d. \n \n ", (*(p+c)).matrice [h] [k] , h);

            break;

        case 4:
            new_day = 's'; //nuovo giorno con aumento variabile globale
            giorno++;
            p = (struct Giorni * )realloc(p, (giorno + 1 ) * sizeof(struct Giorni ));   //aumento l'allocazione di una struttura in più
            if ( p == NULL) {
                printf("\n\nErrore allocazione memoria\n\n");
                exit(1);
            }
            //inizializzo matrice a 0
            for (i = 0; i < num_vend; i++ ) {
                for (j = 0; j < num_prod; j++) {
                    (*(p+giorno)).matrice [i] [j] = 0;
                }
            }

            break;
        case 5:
            system("cls");
            printf("\n\t\t\tUSCITA\n");
            break;
        default:
            printf("\nScelta non valida!\n\n");
    }

if (new_day != 's') {
    printf("Premi m per tornare al menu' o qualsiasi altro tasto per uscire. ");
    menu = tolower(getch());
    fflush(stdin);
    }

}

system("cls");
printf("\n\n\t\t\tCHIUSURA PROGRAMMA");
printf("\n\n\n");
free(p);
return 0;
}


//FUNZIONI


int inserimento_num_venditori () {

    int num_vend = 0;

    printf("\n\nInserisci il numero di venditori: ");
    scanf("%d", &num_vend);
    fflush(stdin);
    printf("\n Hai inserito %d venditori.\n\n", num_vend);
    while (num_vend < 1 || num_vend > 20) {
        printf("\n\nInserisci il numero di venditori tra 1 e 20: ");
        scanf("%d", &num_vend);
        fflush(stdin);
        printf("\n Hai inserito %d venditori.\n\n", num_vend);
    }

    return num_vend;
}


int inserimento_num_prodotti() {

    int num_prod = 0;

    printf("\nInserisci il numero di prodotti: ");
    scanf("%d", &num_prod);
    fflush(stdin);
    printf("\n Hai inserito %d prodotti.\n\n", num_prod);
    while (num_prod < 1 || num_prod > 50) {
        printf("\nInserisci il numero di prodotti tra 1 e 50: ");
        scanf("%d", &num_prod);
        fflush(stdin);
        printf("\n Hai inserito %d prodotti.\n\n", num_prod);
    }

    return num_prod;
}


void stampa_venditori(int numero) {
    int i;
    printf("I codici dei venditori sono : ");
    for (i=0; i<numero; i++) {
        printf(" %d ,", i);
    }
    printf("\n\n");
}

void stampa_prodotti(int numero) {
    int i;
    printf("I codici dei prodotti sono : ");
    for (i=0; i<numero; i++) {
        printf(" %d ,", i);
    }
    printf("\n\n");
}

