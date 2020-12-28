//calcolo fattoriale
//per ogni chiamata ricorsiva l' OUTPUT deve essere su RIGA SEPARATA e CON LIVELLO DI RIENTRO

#include <stdio.h>

//funzione
int fattoriale(int);

main () {

int num = 0;        //numero inserito dall'utente
int fatt_num = 0;   //fattoriale del numero

printf("\nInseirsci un numero del quale fare il fattoriale: ");   //inserimeno numero
scanf("%d", &num);
fflush(stdin);

//controllo input
while (num < 0 || num > 12) {
    printf("\nIl numero puo' variare da 0 a 12; reinseirscilo: ");
    scanf("%d", &num);
    fflush(stdin);
}

printf("\n\nChiamo la funzione ricorsiva fattoriale con %d\n\n", num);

fatt_num = fattoriale(num);     //chaiamata a funzione che ritorna il risulato

printf("La funzione restituisce %d\n\n", fatt_num);


printf("\n\nAssegno a una variabile (fatt_num) il numero restituito.");


printf("\n\nStampo la variabile:\n");

printf("\nIl fattoriale di %d e' %d", num, fatt_num);   //stampa del risultato

printf("\n\n\n");
return 0;
}


//FUNZIONI

int fattoriale (int numero) {

    int i, j;       //variabili per cicli
    static int rientro = 0;     //imposto una variabile statica per il rientro

    if (numero > 0) {   //se la funzione è chiamata con valore > di 0 allora viene richiamata con valore - 1

        for (i = 0; i < rientro ; i++) {    //ciclo stampa spazi fino al numero di rientro
            printf(" ");
        }
        printf("Il numero ricevuto e' %d, memorizzo e chiamo la stessa funzione con %d\n\n", numero, numero - 1);   //stampo VARIABILE LOCALE memorizzata e PARAMETRI della CHIAMATA RICORSIVA
        i = numero;

        rientro++;  //dato che chiamo una funzione aumento il rientro spaziatura

        numero = numero * fattoriale ( numero - 1);

        rientro--;  //dato che la funzione ha tornato il controllo a questa abbasso il rientro spaziatura

        for (j = 0; j < rientro ; j++) {
            printf(" ");
        }
        printf("Moltiplico il numero  %d memorizzato per restituito , restituisco %d\n\n", i ,numero);

        return numero;
    }

    if (numero == 0) {  //se la funzione è chiamata con 0 allora restituisco valore 1

        for (i = 0; i < rientro ; i++) {    //spaziatura
            printf(" ");
        }

        printf(">Il numero ricevuto e' 0, restituisco 1\n\n");
        return 1;   //valore restituito
    }

    else {
        exit(1);    //uscita in caso di problemi
    }
}



