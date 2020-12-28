#include <stdio.h>

int* cerca(int vettore[], int dimensione, int elem);
int* cerca_ordinato (int vettore[], int dimensione, int elem);

main () {

int l, l_o;         //lunghezza vettore e lunghezza vettore ordinato
int *p_vett;        //puntatore a vettore
int *p_vett_o;      //puntatore a vettore ordinato

int i;              //contatori per cicli
int num;            //numero da cercare

int *posizioni;     //memorizza posizioni
int *posizioni_o;   //memorizza posizioni vettore ordinato

printf("Inserisci lunghezza del vettore :");
scanf("%d", &l);

p_vett = ( int * ) malloc(l * sizeof(int));     //allocazione dinamica memoria del vettore
if (p_vett == NULL) {   //controllo malloc
    printf("Errore allocazione memoria vettore principale");
    exit(1);
}
//riempimento vettore
for ( i = 0 ; i < l; i++) {
    printf("Inserisci elemento cella %d del vettore: ", i );
    scanf("%d", p_vett + i);
}
//stampa vettore
printf("\nIl vettore inserito e' : \n");
for ( i = 0 ; i < l; i++) {
    printf(" %d ", *(p_vett + i));
}

printf("\n\n\n-------------- Utilizzando la funzione cerca --------------\n");

printf("Inserisci il numero da cercare: ");
scanf("%d", &num);

//funzione per cercare
posizioni = cerca(p_vett, l, num);

if (posizioni[0] == -1 ) { //se il ritorno è -1 non ci sono riscontri
    printf("\nNon e' stato trovato nessun elemento nel vettore! \n");
}
else {  //altrimenti
    printf("\nL'elemento si trova nella cella: ");
    for (i = 1; i <= posizioni[0]; i++){
            printf(" %d ", posizioni[i]);
    }
}

free(p_vett);
free(posizioni);


/*ricerca in un vettore ordinato in maniera crescente*/

printf("\n\n\nInserisci lunghezza del vettore ordinato in maniera crescente:");
scanf("%d", &l_o);

p_vett_o = ( int * ) malloc(l_o * sizeof(int));     //allocazione dinamica memoria del vettore
if (p_vett_o == NULL) {   //controllo malloc
    printf("Errore allocazione memoria vettore ordinato principale");
    exit(1);
}
//riempimento vettore
for ( i = 0 ; i < l_o; i++) {
    printf("Inserisci elemento cella %d del vettore: ", i );
    scanf("%d", p_vett_o + i);
}
//stampa vettore
printf("\nIl vettore ordinato in maniera crescente inserito e' : \n");
for ( i = 0 ; i < l_o; i++) {
    printf(" %d ", *(p_vett_o + i));
}

printf("\n\n\n-------------- Utilizzando la funzione cerca ordinato --------------\n");

printf("Inserisci il numero da cercare: ");
scanf("%d", &num);

//funzione per cercare
posizioni_o = cerca(p_vett_o, l_o, num);

if (posizioni_o[0] == -1 ) { //se il ritorno è -1 non ci sono riscontri
    printf("\nNon e' stato trovato nessun elemento nel vettore! \n");
}
else {  //altrimenti
    printf("\nL'elemento si trova nella cella: ");
    for (i = 1; i <= posizioni_o[0]; i++){
            printf(" %d ", posizioni_o[i]);
    }
}

free(p_vett_o);
free(posizioni_o);


printf("\n\n\n");
return 0;
}




int* cerca(int vettore[], int dimensione, int elem) {
    int i, k;      //contatori
    int trovati = 0;    //contatore elementi trovati
    int * puntatore;    //puntatore restituito, conterrà nella prima cella la sua lunghezza
    //conta quanti elementi corrispondono nel vettore
    for (i = 0; i < dimensione ; i++) {
        if (vettore[i] == elem) {
            trovati += 1;
        }
    }
    if (trovati == 0) {     //se non c'è riscontro
        puntatore = (int *) malloc( sizeof(int));  //alloco memoria per memorizzare -1
        if (puntatore == NULL) {
            printf("Errore allocazione vettore con numeri celle "); exit(1);
        }
        puntatore[0] = -1;
        return puntatore;
    }

    else {                  //altrimenti se c'è riscontro
        puntatore = (int *) malloc( (trovati + 1) * sizeof(int));  //alloco memoria per memorizzare il numero riguardante la lunghezza del vettore e gli apici delle celle
        if (puntatore == NULL) {
            printf("Errore allocazione vettore con numeri celle "); exit(1);
        }
        puntatore[0] = trovati; //nella cella iniziale memorizzo quanti elementi sono stati trovati

        for (i = 0, k = 1; i < dimensione ; i++) {
            if (vettore[i] == elem) {
                puntatore[k]= i;    //riempio il vettore con gli apici delle celle corrispondenti
                k++;
            }
        }
        return puntatore;
    }

}




int* cerca_ordinato(int vettore[], int dimensione, int elem) {
    int i, k;      //contatori
    int trovati = 0;    //contatore elementi trovati
    int * puntatore;
    //conta quanti elementi corrispondono nel vettore
    for (i = 0; i < dimensione && vettore[i] <= elem ; i++) {   /*facendo così viene ottimizzato perchè non controlla gli elementi il cui contenuto è superiore al valore cercato*/
        if (vettore[i] == elem) {
            trovati += 1;
        }
    }
    if (trovati == 0) {
        puntatore = (int *) malloc( sizeof(int));  //alloco memoria per memorizzare -1
        if (puntatore == NULL) {
            printf("Errore allocazione vettore con numeri celle "); exit(1);
        }
        puntatore[0] = -1;
        return puntatore;
    }

    else {
        puntatore = (int *) malloc( (trovati + 1) * sizeof(int));  //alloco memoria per memorizzare il numero riguardante la lunghezza del vettore e gli apici delle celle
        if (puntatore == NULL) {
            printf("Errore allocazione vettore con numeri celle "); exit(1);
        }
        puntatore[0] = trovati;

        for (i = 0, k = 1; i < dimensione && vettore[i] <= elem ; i++) {     /*sapendo che sono in ordine crescente viene ottimizzato perchè non ricontrolla gli elementi il cui contenuto è superiore al valore cercato*/
            if (vettore[i] == elem) {
                puntatore[k]= i;
                k++;
            }
        }
        return puntatore;
    }

}




