
#include <stdio.h>
#include <stdlib.h>

#include "coda_vettori_dinamici.h"

void stampa_menu(); //per stampare il menu


int main()
{
int scelta = -1;
int elem_ins ; //elemento da inserire

int valore;

TipoLista lista;
lista.last = -1;
lista.elem = (int *) malloc (sizeof(int) * N);
if(!lista.elem)
        exit(0);
lista.dim = N;

while (scelta != 0){

    stampa_menu();

    printf("\nLa Coda e' : \n");
    stampa_lista(lista);

    printf("\n\nInserici l'azione scelta: ");
    scanf("%d", &scelta);
    fflush(stdin);

    switch (scelta)
     {

        case 1 :
            printf("Elemento da inserire in coda: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            valore = EnQueue(&lista, elem_ins); //restituisce 0 se piena
            if (valore == 0){
                printf("Coda piena !\n");
                system("pause");
            }
            break;

        case 2 :
            valore = DeQueue(&lista);
            if (valore == 0){
                printf("Coda vuota !\n");
                system("pause");
            }
            break;

        case 3 :
            if (first(lista) == -1)
                printf("Non ci sono elementi nella coda \n");
            else
                printf("L elemento in cima e' %d \n", first(lista));
            system("pause");
            break;

        case 4 :
            if (Empty(lista)==0)
                printf("\nLa coda ha degli elementi, non e' vuota . \n\n");
            else
                printf("\nLa coda e' vuota! \n");
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
    free((&lista)->elem);
    (&lista)->elem = NULL;
    return 0;

}

//funzione stampa menu
void stampa_menu() {

    system("cls");
    printf("##### Menu Coda Vettori Dinamici #####\n\n");
    printf("[1] - Inserimento in coda (EnQueue)\n");
    printf("[2] - Rimuovi dalla coda (DeQueue)\n");
    printf("[3] - Primo elemento (first)\n");
    printf("[4] - Verifica presenza elementi (isEmpty)\n");
    printf("[0] - Esci\n");



}
