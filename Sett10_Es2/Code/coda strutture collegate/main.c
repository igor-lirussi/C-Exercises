
#include <stdio.h>
#include <stdlib.h>

#include "lista_strutture_collegate.h"

void stampa_menu(); //per stampare il menu

void EnQueue(Nodo**, int );
int isEmpty(Nodo*);
int first(Nodo*);
int DeQueue(Nodo**);

int main()
{
int scelta = -1;
int elem_ins ; //elemento da inserire
int valore; //variabile di appoggio

Nodo* testa;    //testa è n puntatore a nodo
testa = NULL;   //inizializzo a NULL

while (scelta != 0){

    stampa_menu();

    printf("\nLa Coda e' : \n");
    stampa_lista(testa);

    printf("\n\nInserici l'azione scelta: ");
    scanf("%d", &scelta);
    fflush(stdin);

    switch (scelta)
     {
        case 1 :
            printf("Elemento da inserire in coda: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            EnQueue(&testa, elem_ins); //funzione a cui passo puntatore alla testa (ossia il suo indirizzo) e elemento
            break;

        case 2 :
            valore = DeQueue(&testa);//funzione a cui passo puntatore alla testa (nel caso ci sia un solo Nodo)
            if (valore != -1){
                printf("E' stato cancellato l'elemento : %d \n", valore);
                system("pause");
            }
            break;
        case 3 :
            valore = first(testa);
            if (valore == -1) {
                printf("\nLa Coda e'VUOTA\n");
            }
            else{
            printf("\nIl primo elemento e' %d . \n\n", valore);
            }
            system("pause");
            break;

        case 4 :
            valore = isEmpty(testa);
            if (valore == 0) {
                printf("\nLa Coda e'VUOTA");
            }
            else{
            printf("\nLa Coda possiede degli elementi. (%d) . \n\n", valore);
            }
            system("pause");
            break;

        case 0 :
             scelta = 0;
             break;

        default:
            printf("\nInserimento non valido!\n");
            system("pause");
            break;
     }

}

    system("cls");
    printf("\n\n\n\n\t\t\t\tUscita\n\n\n\n\n\n");
    return 0;

}

int DeQueue(Nodo** lis) {
    int i;
    i = first(*lis);
    cancella_testa(lis);
    return i;
}

void EnQueue(Nodo** lis, int elem){
    inserisci_coda(lis, elem );
}
int isEmpty(Nodo* testa){
    return lunghezza_lista(testa);
}
int first(Nodo* testa){
    if (testa== NULL)
        return -1;
    else
        return testa->elem;
}
//funzione stampa menu
void stampa_menu() {

    system("cls");
    printf("##### Menu Coda #####\n\n");
    printf("[1] - Inserimento in coda (EnQueue)\n");
    printf("[2] - Cancella dalla coda (DeQueue)\n");
    printf("[3] - Primo elemento (first)\n");
    printf("[4] - Verifica presenza elementi (isEmpty)\n");
    printf("[0] - Esci\n");


}
