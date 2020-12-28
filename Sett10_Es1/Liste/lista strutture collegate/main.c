
#include <stdio.h>
#include <stdlib.h>

#include "lista_strutture_collegate.h"

void stampa_menu(); //per stampare il menu


int main()
{
int scelta = -1;
int elem_ins ; //elemento da inserire
int elem_ric ; //elemento da ricercare

Nodo* testa;    //testa è n puntatore a nodo
testa = NULL;   //inizializzo a NULL

while (scelta != 0){

    stampa_menu();

    printf("\nLa Lista e' : \n");
    stampa_lista(testa);

    printf("\n\nInserici l'azione scelta: ");
    scanf("%d", &scelta);
    fflush(stdin);

    switch (scelta)
     {
        case 1 :
            printf("Elemento da inserire in testa: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            inserisci_testa(&testa, elem_ins); //funzione a cui passo puntatore alla testa (ossia il suo indirizzo) e elemento
            break;

        case 2 :
            printf("Elemento da inserire in coda: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            inserisci_coda(&testa, elem_ins); //funzione a cui passo indirizzo testa (devo modificarlo se la lista è vuota) e elemento
            break;

        case 3 :
            printf("Elemento da inserire: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            printf("dopo l'elemento: ");
            scanf("%d", &elem_ric);
            fflush(stdin);
            inserisci_dopo(testa, elem_ins, elem_ric);//funzione a cui passo testa , elemento ricercato e elemento inserito
            break;

        case 4 :
            cancella_testa(&testa);//funzione a cui passo puntatore alla testa (quindi indirizzo della testa)
            break;

        case 5 :
            cancella_coda(&testa);//funzione a cui passo puntatore alla testa (nel caso ci sia un solo Nodo)
            break;

        case 6 :
            printf("Elemento la cui prima occorrenza da cancellare: ");
            scanf("%d", &elem_ric);
            fflush(stdin);
            cancella_elem(&testa, elem_ric); //funzione a cui passo puntatore alla testa e elemento ric
            break;

        case 7 :
            printf("Elemento di cui tutte le occorrenze da cancellare: ");
            scanf("%d", &elem_ric);
            fflush(stdin);
            cancella_tutti_elem(&testa, elem_ric);//funzione a cui passo puntatore alla testa e elemento ric
            break;

        case 8 :
            printf("\nLa lunghezza della lista e' %d . \n\n", lunghezza_lista(testa)); //alla funzione lunghezza passo la testa
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

//funzione stampa menu
void stampa_menu() {

    system("cls");
    printf("##### Menu #####\n\n");
    printf("[1] - Inserimento in testa\n");
    printf("[2] - Inserimento in coda\n");
    printf("[3] - Inserimento dopo elemento\n");
    printf("[4] - Cancella in testa\n");
    printf("[5] - Cancella in coda\n");
    printf("[6] - Cancella prima occorrenza di elemento \n");
    printf("[7] - Cancella tutte le occorenze di elemento \n");
    printf("[8] - Calcola lunghezza\n");
    printf("[0] - Esci\n");


}
