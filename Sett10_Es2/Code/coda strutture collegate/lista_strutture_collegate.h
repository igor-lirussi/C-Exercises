
typedef struct _nodo {
    int elem;
    struct _nodo * next;
} Nodo;

void stampa_lista(Nodo*);

void inserisci_testa(Nodo**, int );

void inserisci_coda(Nodo**, int );

void inserisci_dopo(Nodo*, int , int);

void cancella_testa(Nodo**);

void cancella_coda(Nodo**);

void cancella_elem(Nodo**, int);

void cancella_tutti_elem(Nodo**, int);

int lunghezza_lista(Nodo*);
