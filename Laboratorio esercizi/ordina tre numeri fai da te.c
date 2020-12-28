#include<stdio.h>
main()
{
int a,b,c;
printf("inserisci 3 numeri:\n");
scanf("%d%d%d",&a,&b,&c);

printf("\ni numeri sono a:%d\tb:%d\tc:%d\n\n",a,b,c);
if (a>b)
    {if (b>c){
    printf("ordinati:%d %d %d",a,b,c);}else;}
else
printf("scrivi il piu' piccolo:");
scanf("%d",&a);
printf("scrivi non il piu' piccolo e non il piu' grande:");
scanf("%d",&b);
printf("scrivi il piu' grande:");
scanf("%d",&c);
printf("ordinati:%d %d %d\n",a,b,c);
}
