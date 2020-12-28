
#include <stdio.h>
#include <stdlib.h>

#include "pila_statica.h"

void stampa_menu(); //per stampare il menu


int main()
{
int scelta = -1;
int elem_ins ; //elemento da inserire

int valore;

TipoLista lista;
lista.last = -1;


while (scelta != 0){

    stampa_menu();

    printf("\nLa Pila e' : \n");
    stampa_lista(lista);

    printf("\n\nInserici l'azione scelta: ");
    scanf("%d", &scelta);
    fflush(stdin);

    switch (scelta)
     {

        case 1 :
            printf("Elemento da inserire nella pila: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            valore = push(&lista, elem_ins); //restituisce 0 se piena
            if (valore == 0){
                printf("Pila piena !\n");
                system("pause");
            }
            break;

        case 2 :
            valore = pop(&lista);
            if (valore == 0){
                printf("Pila vuota !\n");
                system("pause");
            }
            break;

        case 3 :
            if (top(lista) == -1)
                printf("Non ci sono elementi nella pila \n");
            else
                printf("L elemento in cima e' %d \n", top(lista));
            system("pause");
            break;

        case 4 :
            if (Empty(lista) == 0)
                printf("\nLa pila possiede degli elementi . \n\n");
            else
                printf("\nLa pila e' vuota! \n");
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
    printf("##### Menu Pila Statica #####\n\n");
    printf("[1] - Inserimento nella pila (push)\n");
    printf("[2] - Cancella dalla pila (pop)\n");
    printf("[3] - Primo elemento (top)\n");
    printf("[4] - Verifica presenza elementi (isEmpty)\n");
    printf("[0] - Esci\n");



}
