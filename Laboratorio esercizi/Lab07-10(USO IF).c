#include <stdio.h>

main()
{

/*esercizio*/
/*presi 3 numeri interi stamparli in ordine crescente*/

int a,b,c;
printf("inserisci 3 numeri:\n");
scanf("%d%d%d",&a,&b,&c);

printf("\ni numeri sono a:%d\tb:%d\tc:%d\n\n",a,b,c);

if (a>b){
        if (b>c){
                 if (a>c){
                printf("ordinati:%d %d %d",c,b,a);
                }
                else { /*a<c*/
                printf("impossibile");
                }

                }
        else { /*b<c*/
             if (a>c){
                printf("ordinati:%d %d %d",b,c,a);
                }
                else { /*a<c*/
                printf("ordinati:%d %d %d",b,a,c);
                }

            }
        }
else { /* a<b */
     if (b>c){
             if (a>c){
                printf("ordinati:%d %d %d",c,a,b);
                }
                else { /*a<c*/
                printf("ordinati:%d %d %d",a,c,b);
                }
        }
        else { /*b<c*/
            if (a>c){
                printf("impossibile");
                }
                else { /*a<c*/
                printf("ordinati:%d %d %d\n\n",a,b,c);
                }
        }
    }


/*Metodo migliore*/

printf("\n\n\n");
printf("***METODO MIGLIORE:***\n");

int A,B,C,tmp;
printf("inserisci 3 numeri:\n");
scanf("%d%d%d",&A,&B,&C);

printf("\ni numeri sono A:%d\tB:%d\tC:%d\n\n",A,B,C);

if (A>B) {
        tmp=A;
        A=B;
        B=tmp;
        }
if (A>C) {
        tmp=A;
        A=C;
        C=tmp;
        }
if (B>C) {
        tmp=B;
        B=C;
        C=tmp;
        }
printf("ordine: %d %d %d",A,B,C);
}
