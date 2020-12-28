#include <time.h>
#include <stdio.h>
#include <stdlib.h>
main ()
{
int a,b;
srand(time(NULL));
a = rand()%10+1;
printf("indovina un numero da uno a 10:\n ");
scanf("%d",&b);
if (b==a)
    {printf("*****hai indovinato*****");}
else{
    if (b>a){printf("troppo grande, hai un altro tentativo:\n");}
    if (b<a) {printf("troppo piccolo, hai un altro tentativo:\n");}
    scanf("%d",&b);
    if (b==a)
        {printf("**hai indovinato**, con 2 tentativi");}
    else{
        printf("sei scarso, era %d",a);
        }
    }

return 0;
}
