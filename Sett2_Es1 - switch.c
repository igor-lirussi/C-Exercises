#include <stdio.h>


main () {

int ore, minuti;
printf ("Inserire un orario di arrivo all'aeroporto \nin formato 24 ore separato dai due punti : (esempio 18:13) \n"); //stampa istruzioni

scanf ("%d:%d",&ore,&minuti); //inserimento ora e minuti
fflush(stdin);

//controllo correttezza orario
if ( ore > 24 || minuti > 60) {
    printf("\n orario non valido!\n");
    return 0;
    }
if ( ore < 0 || minuti < 0) {
    printf("\n orario non valido!\n");
    return 0;
    }

//feedback orario aquisito
printf("\n Orario inserito: %.2d : %.2d  \n\n", ore, minuti);

//responso dei voli
printf("Il prossimo volo in partenza decolla alle ");

switch (ore) //nel caso in cui bastino l'ora per definire il volo stampa subito la risposta, se servono i minuti è presente un if.
{
    case 0 : case 1 : case 2 : case 3 : case 4 : case 5 : case 6 : case 7 :
            printf("\nore 08:00 am e raggiunge destinazione alle ore 10:16 am."); break;

    case 8 :if ( minuti == 0 )
            printf("\nore 08:00 am e raggiunge destinazione alle ore 10:16 am.");
            else
            printf("\nore 09:43 am e raggiunge destinazione alle ore 11:52 am."); break;

    case 9: if ( minuti <=43 )
            printf("\nore 09:43 am e raggiunge destinazione alle ore 11:52 am.");
            else
            printf("\nore 11:19 am e raggiunge destinazione alle ore 01:31 pm.");break;

    case 10:
            printf("\nore 11:19 am e raggiunge destinazione alle ore 01:31 pm.");break;

    case 11: if ( minuti <=19 )
            printf("\nore 11:19 am e raggiunge destinazione alle ore 01:31 pm.");
            else
            printf("\nore 12:47 am e raggiunge destinazione alle ore 03:00 pm.");break;

    case 12: if ( minuti <=47 )
            printf("\nore 12:47 am e raggiunge destinazione alle ore 03:00 pm.");
            else
            printf("\nore 02:00 pm e raggiunge destinazione alle ore 04:08 pm.");break;

    case 13:
            printf("\nore 02:00 pm e raggiunge destinazione alle ore 04:08 pm.");break;

    case 14: if ( minuti == 00 )
            printf("\nore 02:00 pm e raggiunge destinazione alle ore 04:08 pm.");
            else
            printf("\nore 03:45 pm e raggiunge destinazione alle ore 05:55 pm.");break;

    case 15: if ( minuti <=45 )
            printf("\nore 03:45 pm e raggiunge destinazione alle ore 05:55 pm.");
            else
            printf("\nore 07:00 pm e raggiunge destinazione alle ore 09:20 pm.");break;

    case 16: case 17: case 18:
            printf("\nore 07:00 pm e raggiunge destinazione alle ore 09:20 pm.");break;

    case 19: if ( minuti ==00 )
            printf("\nore 07:00 pm e raggiunge destinazione alle ore 09:20 pm.");
            else
            printf("\nore 09:45 pm e raggiunge destinazione alle ore 11:58 pm.");break;

    case 20:
            printf("\nore 09:45 pm e raggiunge destinazione alle ore 11:58 pm.");break;

    case 21: if ( minuti <=45 )
            printf("\nore 09:45 pm e raggiunge destinazione alle ore 11:58 pm.");
            else
            printf("\nore 08:00 am e raggiunge destinazione alle ore 10:16 am.");break;

    case 22: case 23: case 24: //osservazione: vengono considerati orari da 0:00 fino a 24:59 compresi ma in questo caso non è influente
            printf("\nore 08:00 am e raggiunge destinazione alle ore 10:16 am.");break;

    default: printf("Hai inserito un caso non contemplato !"); // se viene inserito un orario non preso in esame viene segnalato l'errore

}

printf("\n\n\n"); //spaziatura finale
return 0;
}
