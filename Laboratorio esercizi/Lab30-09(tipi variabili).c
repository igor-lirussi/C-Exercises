#include <stdio.h>
#include <stdlib.h>

int main()
{

    int A;

    printf("VarA non dichiarata: %d\n", A);


    A = 10;

    printf("VarA_dich10: %d\n", A);

    A = 4 + A;

    printf("VarA_som4 %d\n\n\n", A);


    // altre variabili

    float A1;
    double B;


    printf("Var A1 non dichiarata: %d\n", A1);
    printf("Var B non dichiarata: %d\n", B);


    A1 = 7.25;
    B = 21.328768275683242;
    printf("\nDichiarate \n\n");

    printf("  - solo Perc_f A1, B -\n");
    printf("%f \t %f \n", A1, B);

    printf("\n\nprec.2\t prec.15\n");
    printf("%.2f \t %.15f", A1, B);

    printf("\n\nprec.1\t prec.5\n");
    printf("%.1f \t %.5f\n\n\n", A1, B);


    //variabili singolo carattere

    char lettera;
    lettera = 'k';

    printf("K con Perc_c:  %c \n", lettera);

    printf("K con Perc_d:  %d \n", lettera);

    int numero;
    numero = 107;

    printf("107 con Perc_c:  %c \n", numero);

    printf("107 con Perc_d:  %d \n\n\n\n", numero);



    //esercizio su SIZE OF

    unsigned long int A2;

    printf("Int: \t\t%d byte \n", sizeof(int));

    printf("unsigned Int: \t%d byte \n", sizeof(unsigned int));

    printf("long Int: \t%d byte \n", sizeof(long int));

    printf("short Int: \t%d byte \n", sizeof(short int));

    printf("Long Long Int: \t%Ld byte \n", sizeof(long long int));



    // Spazia alla fine
    printf("\n\n\n");
    return 0;


}
