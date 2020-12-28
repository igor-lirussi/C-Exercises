#include <stdio.h>

main()
{
int Var_int =5;
printf("Var_int=%d\n",Var_int);
printf("indirizzo memoria: %d \n\n\n",&Var_int); /*stampa indirizzo memoria della variabile*/

printf("inserisci un numero:");
scanf("%d",&Var_int);       //blocco esecuzione programma attendo input
printf("Ora Var_int=%d\n",Var_int);

fflush(stdin);                                  //utilizzo fflush(standardinput) per pulire il buffer dell input standard
char A,B;
printf("inserisci una lettera:");               //se non si pulisce il buffer le lettere precedenti (compreso invio)
scanf("%c",&A);                                 //vengono prese nella scanf
fflush(stdin);
printf("inserisci una seconda lettera:");
scanf("%c",&B);

printf("hai inserito: %c e %c",A,B);

//per inserire date:
int gg,mm,aaaa,vc;
printf("\n\ninserisci una data:\n");
fflush(stdin);
vc = scanf("%d/%d/%d",&gg,&mm,&aaaa);

printf("Valori corretti:%d",vc);
printf("\nhai inserito %d-%d-%d\n\n\n",gg,mm,aaaa);

return 0;
}
