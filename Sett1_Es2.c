#include <stdio.h>

main()
{
//dichiarazione due variabili ed assegnati ad esse i valori
int a = 4;
int b = 7;

//operazioni e stampa delle stesse
printf("\nVariabili:\ta=%d\tb=%d\n\n",a,b);

//operazione moltiplicazione
printf("Operazione: a = a*b \n");
a = a*b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione somma
printf("Operazione: a = a+b \n");
a = a+b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione sottrazione
printf("Operazione: a = a-2*b \n");
a = a-2*b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b); //Si osserva che la priorità della moltiplicazione viene rispettata

//operazione divisione
printf("Operazione: a = a/b \n");
a = a/b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione incremento destra
printf("Operazione: b = a++ \n");
b = a++;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione incremento sinistra
printf("Operazione: a = ++b \n");
a = ++b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione decremento destra
printf("Operazione: a = b-- \n");
a = b--;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione decremento sinistra
printf("Operazione: a = --b \n");
a = --b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione resto
printf("Operazione: a = a%%b \n");
a = a%b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione mantengo segno
printf("Operazione: a = +b \n");
a = +b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b); //non ha alcun effetto

//operazione cambio segno
printf("Operazione: b = -a \n");
b = -a;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione assegnamento
printf("Operazione: b = 9 \n");
b = 9;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione somma operatori
printf("Operazione: a += b \n");
a += b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione sottrazione operatori
printf("Operazione: b -= a \n");
b -= a;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione moltilicazione operatori
printf("Operazione: a *= b \n");
a *= b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione divisione operatori
printf("Operazione: a /= b \n");
a /= b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione resto operatori
printf("Operazione: a %%= b \n");
a %= b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operazione assegnamento composto
printf("Opeazione: b += 3 \n");
b += 3;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

return 0;

}
