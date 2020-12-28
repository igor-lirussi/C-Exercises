
#include <stdio.h>
#include <stdlib.h>

#include "lista_vettori_dinamici.h"

void stampa_menu(); //per stampare il menu


int main()
{
int scelta = -1;
int elem_ins ; //elemento da inserire
int elem_ric ; //elemento da ricercare

int valore;

TipoLista lista;
lista.last = -1;
lista.elem = (int *) malloc (sizeof(int) * N);
if(!lista.elem)
        exit(0);
lista.dim = N;

while (scelta != 0){

    stampa_menu();

    printf("\nLa Lista e' : \n");
    stampa_lista(lista);

    printf("\n\nInserici l'azione scelta: ");
    scanf("%d", &scelta);
    fflush(stdin);

    switch (scelta)
     {
        case 1 :
            printf("Elemento da inserire in testa: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            valore = inserisci_testa(&lista, elem_ins); //restituisce 1 se è andata a buon fine, 0 se piena
            if (valore == 0){
                printf("Lista piena !\n");
                system("pause");
            }
            break;

        case 2 :
            printf("Elemento da inserire in coda: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            valore = inserisci_coda(&lista, elem_ins); //restituisce 0 se piena
            if (valore == 0){
                printf("Lista piena !\n");
                system("pause");
            }
            break;

        case 3 :
            printf("Elemento da inserire: ");
            scanf("%d", &elem_ins);
            fflush(stdin);
            printf("dopo l'elemento: ");
            scanf("%d", &elem_ric);
            fflush(stdin);
            valore = inserisci_dopo(&lista, elem_ins, elem_ric);
            if (valore == 0){
                printf("Lista piena o elemento non trovato !\n");
                system("pause");
            }
            break;

        case 4 :
            valore = cancella_testa(&lista);
            if (valore == 0){
                printf("Lista vuota !\n");
                system("pause");
            }
            break;

        case 5 :
            valore = cancella_coda(&lista);
            if (valore == 0){
                printf("Lista vuota !\n");
                system("pause");
            }
            break;

        case 6 :
            printf("Elemento la cui prima occorrenza da cancellare: ");
            scanf("%d", &elem_ric);
            fflush(stdin);
            valore = cancella_elem(&lista, elem_ric);
            if (valore == 0){
                printf("L'elemento non e' presente !\n");
                system("pause");
            }
            break;

        case 7 :
            printf("Elemento di cui tutte le occorrenze da cancellare: ");
            scanf("%d", &elem_ric);
            fflush(stdin);
            valore = cancella_tutti_elem(&lista, elem_ric);   //valore assume il numero degli elementi cancellati all occorrenza
            if (valore == 0){
                printf("L'elemento non e' presente !\n");
                system("pause");
            }
            break;

        case 8 :
            printf("\nLa lunghezza della lista e' %d . \n\n", lunghezza_lista(lista));
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
