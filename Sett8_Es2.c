#include <stdio.h>
#include <stdlib.h>

#define NUM_ESAMI 3             //numero esami di default da inserire nell'aggiunta studente ( deve essere compreso tra 1 e MAX_ESAMI )
#define MAX_ESAMI 10            //elementi del vettore piano di studi ossia numero massimo di voti/esami
#define LUNGHEZZA_CARATTERI 20  //caratteri massimi per nome materia, nome, cognome studente
#define MAX_STUDENTI 10         //elementi del vettore iniziale ( 10 strutture )

struct Piano_studi {                                //definisco la struttura piano di studi
    char insegnamento[LUNGHEZZA_CARATTERI + 1];
    int voto;
};

struct Informazioni_studente {                      //definisco la struttura informazioni_studente
    int numero_matricola;
    char nome[LUNGHEZZA_CARATTERI + 1];
    char cognome[LUNGHEZZA_CARATTERI + 1];
    int anno_immatricolazione;
    struct Piano_studi esami[MAX_ESAMI + 1];
};

//FUNZIONI

/*FUNZIONE CONTROLLO*/
/*RESTITUISCE 1 se � presente , 0 se non � presente la matricola (ins_mat) all'interno del vettore studenti riempito fino a (pien)*/
int controllo (int , struct Informazioni_studente *, int);

/*FUNZIONE STAMPA*/
/*STAMPA I DATI DI UNO STUDENTE E I SUOI VOTI, NECESSITA DELLA POSIZIONE DELLO STUDENTE NEL VETTORE, RITORNA IL NUMERO DEL PROSSIMO ESAME NON DATO*/
int stampa ( struct Informazioni_studente * , int );


main () {

char ripeti = 's';                  //variabile per l'accesso al ciclo iniziale
int vet_studenti = MAX_STUDENTI;    //variabile per dimensione memoria da allocare

//ALLOCAZIONE DINAMICA MEMORIA
struct Informazioni_studente    *studenti;
studenti = (struct Informazioni_studente *) malloc( vet_studenti * sizeof(struct Informazioni_studente));

//CONTROLLO MALLOC
if (studenti == NULL) {
    printf("\n Impossibile allocare la memoria! \n");
    char ripeti = 'n';  //impostando la variabile di accesso ad un'altra lettera il programma non viene eseguito
}


int i, j , k;               //contatori per cicli
ripeti = 's';               //gestisce il ripetersi del programma fino a quando vuole l'utente
int scelta;                 //memorizza scelta nel men� iniziale
int ins_mat = 0;            //matricola da inserire o confrontare
int pien = 0;                  //contatore elementi pieni vettore
int ripetizione = 0;           //controlla che non ci siano ripetizioni
int aggiungi = 1;              //variabile per l'aggiunta di esami

while (ripeti == 's') {     //finch� l'utente digita s alla fine del ciclo esso si ripete e torna al menu principale
    system("cls");
    printf("\nREGISTRO STUDENTI:\n\n");
    printf("Numero studenti presenti: %d \n", pien);
    printf("\n\tScegli un'azione da fare: \n\n");
    printf("Premi 1 per aggiungere un nuovo studente\n");
    printf("Premi 2 per trovare informazioni su uno studente\n");
    printf("Premi 3 per modificare informazioni di uno studente\n");
    scanf("%d", &scelta);                   //insermento scelta iniziale
    fflush(stdin);

    switch (scelta) {

        case 1 :                    //caso Aggiunta studente
            system("cls");
            printf("\n\tAggiungi studente\n\n");

            printf("Inserisci numero matricola:");      //insermento numero matricola
            scanf("%d", &ins_mat);      //memorizzo matricola inserita
            fflush(stdin);

            /*FUNZIONE CONTROLLO RIPETIZIONE*/
            ripetizione = controllo (ins_mat, studenti, pien );  /*USO LA FUNZIONE CONTROLLO : RESTITUISCE 1 se � presente , 0 se non � presente*/

            if (pien == vet_studenti) {
                printf("\nSpazio limite vettore raggiunto! \n");   //avvertimento se il vettore � pieno
                printf("\n\t\tRialloco la memoria per ottenere piu' spazio....\n");
                //RIALLOCAZIONE Della MEMORIA
                //rialloco la memoria al doppio di prima
                studenti = (struct Informazioni_studente *) realloc(studenti, 2 * vet_studenti * sizeof(struct Informazioni_studente));
                vet_studenti *= 2; //memorizzo il raddoppio
                //CONTROLLO REALLOC
                if (studenti == NULL) {
                    printf("\n Impossibile allocare nuovamente la memoria! \n");
                    char ripeti = 'n';  //impostando la variabile di accesso ad un'altra lettera il programma non viene eseguito
                }

            }

            if (ripetizione == 0) {       //se la matricola non � presente
                printf("\nLa matricola NON e' gia' presente, puoi procedere:\n");
                studenti[pien].numero_matricola = ins_mat;      //INSERIMENTO dati

                for (k = 0; k < MAX_ESAMI; k++) {   //inizializzo a 0 tutti i voti di questa matricola
                        studenti[pien].esami[k].voto = 0;
                }


                printf("\nInserisci NOME studente:");
                scanf("%s", studenti[pien].nome);
                fflush(stdin);
                printf("\nInserisci COGNOME studente:");
                scanf("%s", studenti[pien].cognome);
                fflush(stdin);
                printf("\nInserisci ANNO immatricolazione studente:");
                scanf("%d", &studenti[pien].anno_immatricolazione);
                fflush(stdin);
                for (i = 0; i < NUM_ESAMI; i++) {                   //inserimento degli esami settati di default
                    printf("\nInserisci nome ESAME %d:", i+1);
                    scanf("%s", studenti[pien].esami[i].insegnamento);
                    fflush(stdin);
                    printf("Inserisci VOTO ESAME %d:", i+1);
                    scanf("%d", &studenti[pien].esami[i].voto);
                    fflush(stdin);
                }
                for (aggiungi = 1; aggiungi == 1 && i < MAX_ESAMI; i++){ //ciclo di richiesta per aggiunta altro esame
                    printf("\nPer aggiungere un altro esame premi 1. \nDigita 0 per terminare l'inserimeto:");
                    scanf("%d", &aggiungi);
                    fflush(stdin);
                    if (aggiungi == 1) {
                        printf("\nInserisci nome ESAME %d:", i+1);
                        scanf("%s", studenti[pien].esami[i].insegnamento);
                        fflush(stdin);
                        printf("Inserisci VOTO ESAME %d:", i+1);
                        scanf("%d", &studenti[pien].esami[i].voto);
                        fflush(stdin);
                    }
                }
                if (i == MAX_ESAMI){
                    printf("\nNumero massimo di esami inseribili raggiunto!\n");
                }

                if (i < MAX_ESAMI){
                        i++;
                    studenti[pien].esami[i].voto = 0;     //pone a 0 il voto successivo se � nel vettore
                }
                printf("\n---Inserimento completato.---\n");
                pien += 1;      //aumenta di 1 il contatore studenti dato che ne ha aggiunto 1
            }

            else {
                printf("\nATTENZIONE: La matricola e' gia' presente!\n");   //se la matricola � gi� presente avverte
            }
            aggiungi = 1;  //viene settato nuovamente di default la richiesta di aggiunta
            ripetizione = 0;    //torno ad azzerare il controllo ripetizione della matricola studente per sicurezza
            break;

        case 2 :                    //caso Cerca studente
            system("cls");
            printf("\n\tCerca studente\n\n");
            printf("Inserisci numero matricola da cercare:");      //insermento numero matricola da cercare
            scanf("%d", &ins_mat);      //memorizzo matricola inserita
            fflush(stdin);

            /*Funzione CONTROLLO RIPETIZIONE*/
            ripetizione = controllo (ins_mat, studenti, pien );  /*USO LA FUNZIONE CONTROLLO : RESTITUISCE 1 se � presente , 0 se non � presente*/

            if (ripetizione == 1) {
                for (j = 0, ripetizione = 0; j < pien ; j++ ) { //controllo se matricola � presente

                    if (studenti[j].numero_matricola == ins_mat) {       //se la matricola � presente
                        printf("\nLa matricola e' stata trovata:\n");
                        ripetizione = 1; //memorizzo il fatto di aver trovato la matricola

                        /*FUNZIONE STAMPA*/
                        stampa(studenti, j); /*STAMPA I DATI DI UNO STUDENTE E I SUOI VOTI, NECESSITA DELLA POSIZIONE DELLO STUDENTE NEL VETTORE*/
                        //IN QUESTO CASO NON SERVE UTILIZZARE IL RITORNO DELLA STAMPA

                        printf("\n---Ricerca completata.---\n");
                    }
                }
            }
            if (ripetizione == 0) {
                printf("\nATTENZIONE: La matricola NON e' presente!\n");   //se la matricola non � presente avverte
            }

            ripetizione = 0;    //torno ad azzerare il controllo ripetizione per sicurezza
            break;

        case 3:                    //caso Modifica studente
            system("cls");
            printf("\n\tModifica studente\n\n");
            printf("Inserisci numero matricola da modificare:");      //insermento numero matricola da modificare
            scanf("%d", &ins_mat);      //memorizzo matricola inserita
            fflush(stdin);

            /*FUNZIONE CONTROLLO*/
            ripetizione = controllo (ins_mat, studenti, pien );  /*USO LA FUNZIONE CONTROLLO : RESTITUISCE 1 se � presente , 0 se non � presente*/

            if (ripetizione == 1) {
                for (j = 0, ripetizione = 0; j < pien ; j++ ) { //se matricola � presente

                    if (studenti[j].numero_matricola == ins_mat) {       //se la matricola � presente
                        printf("\nLa matricola e' stata trovata:\n");
                        ripetizione = 1; //memorizzo il fatto di aver trovato la matricola

                        /*FUNZIONE STAMPA*/
                        i = stampa(studenti, j); /*STAMPA I DATI DI UNO STUDENTE E I SUOI VOTI, NECESSITA DELLA POSIZIONE DELLO STUDENTE NEL VETTORE, RITORNA IL NUMERO DEL PROSSIMO ESAME NON DATO */
                        //PER MODIFICARE I VOTI i DEVE CORRISPONDERE AL PROSSIMO ESAME DA AGGIUNGERE

                        //modifica
                        for (aggiungi = 1; aggiungi == 1 && i < MAX_ESAMI; i++){ //aggiunta esami
                            printf("\nPer aggiungere un altro esame premi 1. \nDigita 0 per terminare l'inserimeto:");
                            scanf("%d", &aggiungi);
                            fflush(stdin);
                            if (aggiungi == 1) {
                                printf("\nInserisci nome ESAME %d:", i+1);
                                scanf("%s", studenti[j].esami[i].insegnamento);
                                fflush(stdin);
                                printf("Inserisci VOTO ESAME %d:", i+1);
                                scanf("%d", &studenti[j].esami[i].voto);
                                fflush(stdin);
                            }
                        }

                        if (i == MAX_ESAMI){
                            printf("\nNumero massimo di esami inseribili raggiunto!\n");
                        }
                        if (i < MAX_ESAMI){
                            studenti[j].esami[i+1].voto = 0;     //pone a 0 il voto successivo se � nel vettore
                        }
                        printf("\n---Modifica completata.---\n");
                    }
                }
            }
            if (ripetizione == 0) {
                printf("\nATTENZIONE: La matricola NON e' presente!\n");   //se la matricola non � presente avverte
            }
            aggiungi = 1;
            ripetizione = 0;    //torno ad azzerare il controllo ripetizione per sicurezza
            break;

        default :
            printf("Scelta non valida ! \n\n");
    }
    printf("\nPer tornare al menu iniziale premere: s \nPer uscire premere qualsiasi altro tasto\n");
    ripeti = tolower(getch());
    fflush(stdin);

}
free(studenti);
printf("\n\n\n");
return 0;
}



/*FUNZIONE CONTROLLO*/
/*RESTITUISCE 1 se � presente , 0 se non � presente la matricola (ins_mat) all'interno del vettore studenti riempito fino a (pien)*/

int controllo (int ins_mat, struct Informazioni_studente *studenti, int pien) {
    printf("\nControllo...\n");
    int j;
    for (j = 0; j < pien ; j++ ) { //controllo se matricola gi� presente
        if (studenti[j].numero_matricola == ins_mat) {
            return 1;   //memorizzo il fatto che la matricola � gi� presente
        }
    }
    return 0;
}



/*FUNZIONE STAMPA*/
/*STAMPA I DATI DI UNO STUDENTE E I SUOI VOTI, NECESSITA DELLA POSIZIONE DELLO STUDENTE NEL VETTORE, RITORNA IL NUMERO DEL PROSSIMO ESAME NON DATO*/

int stampa ( struct Informazioni_studente *studenti , int posizione) {
    printf("\nNOME studente: %s", studenti[posizione].nome);
    printf("\nCOGNOME studente: %s", studenti[posizione].cognome);
    printf("\nANNO immatricolazione studente: %d", studenti[posizione].anno_immatricolazione);
    int i;
    for (i = 0; studenti[posizione].esami[i].voto != 0 && i < MAX_ESAMI; i++) { //stampa tutti esami
        printf("\n\nNome ESAME %d: %s", i+1, studenti[posizione].esami[i].insegnamento);
        printf("\nVOTO ESAME %d: %d", i+1, studenti[posizione].esami[i].voto);
    }
    return i;
}


