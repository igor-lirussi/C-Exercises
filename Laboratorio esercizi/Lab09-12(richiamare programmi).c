#include <stdio.h>
#include <stdlib.h>



int main ( int argc, char *argv[], char *env[]) {   //la funzione main //numero parametri passati //array con elenco paramentri, la cella 0 è il nome del programma
    argv[0];    //nome programma
    argv[1];    //parametro 1
    argv[2];    //parametro 2
    //...
    argv[argc - 1];  //ultimo parametro
    argv[argc]  == NULL;     ////  '\0'

    int i;
    //stampo tutti i parametri di ingresso
    printf("Arogmenti passati: \n");
    printf("Usando il FOR: \n");
    for (i=0; i<argc; i++) {
        printf("%s \n", argv[i]);
    }

    printf("Usando il WHILE: \n");
    i = 0;
    while ( argv[i] != NULL) {
        printf("%s \n", argv[i]);
        i++;
    }

    printf("\nVariabili ambiente: \n");
    i=0;
    while ( env[i] != NULL) {
        printf("%s \n", env[i]);    //stampate nella forma : chiave =  valore
        i++;
    }

    printf("\nStampa di una varibile di ambiente specifica:");
    printf("\n%s\n", getenv("windir"));


    return 0;
}
