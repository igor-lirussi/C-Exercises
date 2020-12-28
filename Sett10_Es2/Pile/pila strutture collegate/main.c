
#include <stdio.h>
#include <stdlib.h>

#include "lista_strutture_collegate.h"

void stampa_menu(); //per stampare il menu


int main()
{
int scelta = -1;
int elem_ins ; //elemento da inserire
int elem_ric ; //elemento da ricercare
int vuota;
Nodo* testa;    //testa è n puntatore a nodo
testa = NULL;   //inizializzo a NULL

while (scelta != 0){

    stampa_menu();

    printf("\nLa pila e' : (l'elemento affirorante e' a sinistra)\n");
    stampa_lista(testa);

    printf("\n\nInserici l'azione scelta: ");
    scanf("%d", &scelta);
    fflush(stdin);

    switch (scelta)
     {
        case 1 :
            printf("Elemento da inserire: ");
            scanf("%d", &elem_ins);
            fflush(stdin);

            push(&testa, elem_ins); //funzione a cui passo puntatore alla testa (ossia il suo indirizzo) e elemento

            break;

        case 2 :
            if (top(testa) != -1)
                printf("L' elemento in cima e': %d .\n", top(testa)); //ritorna -1 se non è presente
            else
                printf("Non ci sono elementi nella pila! \n");
            system("pause");
            break;

        case 3 :
            vuota = isEmpty(testa);
            if (vuota == 0){
                printf("\nLa pila e' VUOTA. \n\n");
            }
            else{
                printf("\nLa pila CONTIENE DEGLI ELEMENTI. (%d)\n\n", vuota);
            }
            system("pause");
            break;

        case 4 :
            pop(&testa);//funzione a cui passo puntatore alla testa (quindi indirizzo della testa)
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
    printf("##### Menu Pila #####\n\n");
    printf("[1] - Inserisci elemento (push)\n");
    printf("[2] - Mostra elemento (top)\n");
    printf("[3] - Verifica se la pila e' vuota (isEmpty)\n");
    printf("[4] - Cancella elemento(pop)\n");
    printf("[0] - Esci\n");


}
