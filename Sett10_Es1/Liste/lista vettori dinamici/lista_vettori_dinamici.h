#define N 20

#define EMPTYLIST -1
#define UNDEFINED -2

typedef struct _listastatica {
    int* elem;
    int last; //posizione ultimo elemento lista
    int dim;    //DIMENSIONE
} TipoLista;


void stampa_lista (TipoLista);

int lunghezza_lista (TipoLista);

int inserisci_testa (TipoLista *,int );

int inserisci_coda (TipoLista *,int );

int inserisci_dopo (TipoLista *,int, int );

int cancella_testa (TipoLista *);

int cancella_coda (TipoLista *);

int cancella_elem (TipoLista *, int );

int cancella_tutti_elem (TipoLista *,int );

