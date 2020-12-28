#include <stdio.h>
#include <stdlib.h>

#include "pila_statica.h"

int Full (TipoLista lista)
{
    return ( lista.last == N-1);
}

int Empty (TipoLista lista)
{
    return (lista.last == EMPTYLIST);
}

void Delete (TipoLista* lista,int i)
{
    for (;i<lunghezza_lista(*lista);i++)
        lista->elem[i] = lista->elem[i+1];  //sposta indietro tutti gli elementi di indice superiore
    lista->last--;
}

void stampa_lista(TipoLista lista){
    if (lista.last == EMPTYLIST) {
        printf("vuota");
        return;
    }
    else {
    int i;
    for (i=0; i < lunghezza_lista(lista); i++){
        printf(" %d ", lista.elem[i]);
        }
    }
    return;
}


int lunghezza_lista(TipoLista lista){

    return (lista.last + 1);
}

int inserisci_testa (TipoLista* lista,int elem_ins ){
    int i;
    if(!Full(*lista))
    {
        for(i=lista->last; i>=0 ;i--)
            lista->elem[i+1] = lista->elem[i];  //sposto tutti in avanti
        lista->elem[0] = elem_ins;  //inserisco all inizio
        lista->last++; //aumento il contatore lunghezza lista
        return 1;
    }
    return 0;
}

int inserisci_coda (TipoLista* lista,int elem_ins){
    if(!Full(*lista))
    {
        lista->last++;//aumento il contatore
        lista->elem[lista->last]= elem_ins;//nell ultima posizione aggiornata inserisco l'elemento
        return 1;
    }
    return 0;
}

int Cerca (TipoLista* lista ,int elem_ric)  //ritorna l'indice della posizione dell elemento cercato
{
    int i;
    for (i=0;i<lunghezza_lista(*lista);i++)
        if(elem_ric == lista->elem[i])
            return i;

    return -1;
}


int inserisci_dopo (TipoLista* lista,int elem_ins, int elem_ric){
    int i, k;
    if (!Full(*lista))
    {
        k = Cerca(lista, elem_ric); //trovo l indice dell elemento ricercato
        if (k!=-1){
            for (i = lista->last; i>k;i--){
                lista->elem[i+1] = lista->elem[i]; //aumento di una posizione tutti quelli dopo
            }
            lista->elem[k+1] = elem_ins;    //inserisco l elemento dopo quello trovato
            lista->last++; //aumento il contatore di 1
            return 1;
        }
    }
    return 0;
}

int cancella_testa (TipoLista* lista){
    if (lunghezza_lista(*lista)>0)
    {
        Delete(lista, 0);
        return 1;
    }
    return 0;
}

int top(TipoLista lista){
    if (lista.last == -1)
        return -1;
    else
        return lista.elem[0];
}

int cancella_coda (TipoLista* lista){
    if (lunghezza_lista(*lista)>0) //se non è vuota
    {
        Delete(lista, lista->last); //cancella ultimo
        return 1;
    }
    return 0;
}

int cancella_elem (TipoLista* lista, int elem_ric){
    int j;
    j = Cerca(lista,elem_ric); //j ha l indice dell elemento da ricercare
    if (j != -1){
        Delete(lista, j);
        return 1;
    }
    return 0;
}

int cancella_tutti_elem (TipoLista* lista,int elem_ric){
    int i;
    int conta = 0;
    while ( ( i = Cerca(lista, elem_ric) ) != -1){
        Delete(lista, i);
        conta++;
    }
    return conta;
}

int pop(TipoLista* lista){
    int i;
    i = cancella_testa(lista);
    return i;
}

int push( TipoLista* lista , int elem_ins){
 int i;
 i = inserisci_testa(lista, elem_ins);
 return i;
}
//FINE
