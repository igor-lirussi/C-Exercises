#include <stdio.h>

main()
{
//dichiarazione due variabili ed assegnati ad esse i valori
int a = 4;
int b = 7;
float f = 3.1415;

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
printf("Operazione: b += 3 \n");
b += 3;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore size of
printf("Operatore: size of \n");
printf("Variabili:\ta=%d\tb=%d \tDimensioni di b: %d Byte\n\n",a,b,sizeof(b));

//operatore cast
printf("Operatore cast: a = 7 + parte intera di f \n");
a = 7 + (int)f;
printf("Variabili:\ta=%d\tb=%d\tf=%f\n\n",a,b,f);

//operatore <
printf("Operatore <\n");
if (b < a) {
    b = a ;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore <=
printf("Operatore <=\n");
if (a <= b) {
    a = a - b/2;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore >
printf("Operatore >\n");
if (a > b) {
    b = a + b;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore >=
printf("Operatore >=\n");
if (b >= a) {
    a = a + b -5;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore ==
printf("Operatore ==\n");
if (a == b) {
    b = b-7;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore !=
printf("Operatore !=\n");
if (a != b) {
    b = 0;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore !
printf("Operatore !\n");
if (!b) {       /* verifica b=0 */
    b = 8;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore &&
printf("Operatore &&\n");
if (a > b && b>2) {
    a = 6;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore ||
printf("Operatore ||\n");
if (a > b || b>2) {
    a = 7;
    }
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore &
printf("Operatore & bit a bit\n");
b = a & b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore |
printf("Operatore | inclusivo bit a bit\n");
a = a | b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore ^
printf("Operatore ^ esclusivo bit a bit\n");
b = a ^ b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore unario ~
printf("Operatore unario ~\n");
b = ~b;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore <<
printf("Operatore <<\n");
b = a<<4 ;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore >>
printf("Operatore >>\n");
a = a>>3;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

//operatore condizionale ternario
printf("Operatore condizionale ternario\n");
b = b > a ? 9 : 6;
printf("Variabili:\ta=%d\tb=%d\n\n",a,b);

return 0;

}
