#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

main ()
{
//dichiarazioni variabili

//tipo char
char carattere = 'a';
signed char carattere_segnato = 'b';
unsigned char carattere_non_segn = 'c';

//tipo int signed
int intero = -3;
short int intero_corto = 5;
long int intero_lungo = 35;

//tipo int unsigned
unsigned int intero_non_segn = 9;
unsigned short int intero_corto_non_segn = 13;
unsigned long int intero_lungo_non_segn = 17;

//tipo float e double
float virgola_mobile = 1.654;
double virgola_doppia = 3.2765;
long double lunga_virgola_doppia = 0.1;

//stampe a schermo

//variabili per il numero dei caratteri dei printf
int pr1,pr2,pr3,pr4,pr5,pr6,pr7,pr8,pr9,pr10,pr11,pr12;

pr1 = printf("Variab: carattere \t\tvalore: %c \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %i ",carattere,sizeof(carattere),CHAR_MIN,CHAR_MAX);  printf("|Caratteri:%d\n\n",pr1);
pr2 = printf("Variab: carattere_segnato \tvalore: %c \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %i ",carattere_segnato,sizeof(carattere_segnato),SCHAR_MIN,SCHAR_MAX);  printf("|Caratteri:%d\n\n",pr2);
pr3 = printf("Variab: carattere_non_segn \tvalore: %c \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %i ",carattere_non_segn,sizeof(carattere_non_segn),0,UCHAR_MAX);  printf("|Caratteri:%d\n\n",pr3);

pr4 = printf("Variab: intero \t\t\tvalore: %+i \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %i ",intero,sizeof(intero),INT_MIN,INT_MAX);  printf("|Caratteri:%d\n\n",pr4);
pr5 = printf("Variab: intero_corto \t\tvalore: %i \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %i ",intero_corto,sizeof(intero_corto),SHRT_MIN,SHRT_MAX);  printf("|Caratteri:%d\n\n",pr5);
pr6 = printf("Variab: intero_lungo \t\tvalore: %i \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %i ",intero_lungo,sizeof(intero_lungo),LONG_MIN,LONG_MAX);  printf("|Caratteri:%d\n\n",pr6);

pr7 = printf("Variab: intero_non_segn \tvalore: %u \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %u ",intero_non_segn,sizeof(intero_non_segn),0,UINT_MAX);  printf("|Caratteri:%d\n\n",pr7);
pr8 = printf("Variab: intero_corto_non_segn \tvalore: %u \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %u ",intero_corto_non_segn,sizeof(intero_corto_non_segn),0,USHRT_MAX);  printf("|Caratteri:%d\n\n",pr8);
pr9 = printf("Variab: intero_lungo_non_segn \tvalore: %u \t memoria:%d Byte \nVal.MIN: %i \tVal.MAX: %u ",intero_lungo_non_segn,sizeof(intero_lungo_non_segn),0,ULONG_MAX);  printf("|Caratteri:%d\n\n",pr9);

pr10 = printf("Variab: virgola_mobile \tvalore: %f \t memoria:%d Byte \nVal.MIN: %e \tVal.MAX: %e ",virgola_mobile,sizeof(virgola_mobile),FLT_MIN,FLT_MAX);  printf("|Caratteri:%d\n\n",pr10);
pr11 = printf("Variab: virgola_doppia \tvalore: %f \t memoria:%d Byte \nVal.MIN: %e \tVal.MAX: %e ",virgola_doppia,sizeof(virgola_doppia),DBL_MIN,DBL_MAX);  printf("|Caratteri:%d\n\n",pr11);
pr12 = printf("Variab: lunga_virgola_doppia \tvalore: %Lf \t memoria:%d Byte \nVal.MIN: %le \tVal.MAX: %le ",lunga_virgola_doppia,sizeof(lunga_virgola_doppia),LDBL_MIN,LDBL_MAX);  printf("|Caratteri:%d\n\n",pr12); //l'output dipende dalla macchina

//modificatori e specifiche di conversione sulle variabili precedentemente usate
printf("\nSpecifiche di conversione e modificatori\n");
printf("Variabile presa in considerazione: virgola_doppia: |%f| \n\n",virgola_doppia);

printf("Modificatore %%.2f:\t |%.2f|\n\n",virgola_doppia);

printf("Modificatore %%9f:\t |%9f|\n\n",virgola_doppia);

printf("Modificatore %%-9f:\t |%-9f|\n\n",virgola_doppia);

printf("Modificatore %%.1e:\t |%.1e|\n\n",virgola_doppia);

printf("Modificatore %%.9f:\t |%.9f|\n\n",virgola_doppia);

printf("Modificatore %%-8.0lf:\t |%-8.0lf|\n\n",virgola_doppia);

printf("Modificatore %%.2g:\t |%.2g|\n\n",virgola_doppia);

printf("Modificatore %%-6.4g:\t |%-6.4g|\n\n",virgola_doppia);


return 0;
}
