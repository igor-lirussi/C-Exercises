//programma che sia in grado di acquisire tutto il testo che l'utente digita fino a quando preme un tasto per terminare
//il programma POI conta quante vocali ci sono
#include <stdio.h>
#define MAX 10
main () {
char c;
char stringa [MAX];
int i;

do{
    c = getchar();
    stringa[i] = c;
    i++;
} while (c == '\n' || i < MAX);
stringa [i-1] =  '\0';











return 0;
}
