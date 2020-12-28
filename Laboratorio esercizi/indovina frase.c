#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define LUNGHEZZA_FRASE 20
#define MASSIMO_TENTATIVI 3

int main()
{
	char fraseCrittografata[LUNGHEZZA_FRASE+1];
	char frase[LUNGHEZZA_FRASE+1];
	char fraseUtente[LUNGHEZZA_FRASE+1];
	int i, trovato;
	char carattere, lettera, ch;
	int numeroMassimoInserimentiLettere;
	int numeroLettere, numeroTentativi;
	int elencoLettereAlfabeto[26];

	system("cls");
	printf("Inserire la frase da indovinare e premere INVIO [- esci]:\n");
	i = 0;
	do
	{
		fflush(stdin);
		while ((ch=getche()) != '\n' && ch != '\r' && i < LUNGHEZZA_FRASE)
		{
			if (ch == '-')
			{
				exit(0);
				system("pause");
      		}
			frase[i++] = ch;
		}
		if (i == 0)
			printf("\nHai inserito una frase vuota! \n");
	}
	while(i == 0);
	frase[i] = '\0';


	for (i = 0; i < LUNGHEZZA_FRASE && frase[i] != '\0'; i++)
	{
		carattere = tolower(frase[i]);
		if (frase[i] >= 97 && frase[i] <= 122)
		{
			if (carattere == 'a' || carattere == 'e' ||
				carattere == 'i' || carattere == 'o' ||
				carattere == 'u')
				fraseCrittografata[i] = '+';
			else
				fraseCrittografata [i] = '-';
		}
		else
			fraseCrittografata[i] = frase[i];
	}
	fraseCrittografata[i] = '\0';


	for (i = 0; i < 26; i++)
		elencoLettereAlfabeto[i] = 0;

	numeroMassimoInserimentiLettere = 0;
	for (i = 0; i < LUNGHEZZA_FRASE && frase[i] != '\0'; i++)
	{
		lettera = tolower(frase[i]);
		if (lettera >= 97 && lettera <= 122)
		{
			if (elencoLettereAlfabeto[lettera-97] != 1)
				numeroMassimoInserimentiLettere++;
			elencoLettereAlfabeto[lettera-97] = 1;
		}
	}

	numeroLettere = 0;
	numeroTentativi = 0;

	system("cls");
	do
	{
		do
		{

			printf("\n\nFrase da indovinare: \n%s\n\n", fraseCrittografata);
			printf("Iserire una lettera [- esci; ? indovina]: ");
			fflush(stdin);
			lettera = tolower(getche());
			if (lettera == '-')
			{
				exit(0);
				system("pause");
      		}
			if (lettera != '?' && (lettera < 97 || lettera > 122))
				printf("\nErrore di inserimento: carattere non valido\n");
		}
		while(lettera != '?' && (lettera < 97 || lettera > 122));

		if (lettera == '?')
		{
			printf("\nInserisci la frase nascosta e premere INVIO: ");
			i = 0;
			while ((ch =getche()) != '\n' && ch != '\r' && i < LUNGHEZZA_FRASE)
				fraseUtente[i++] = ch;
    		fraseUtente[i] = '\0';
			numeroTentativi++;
			if (strcmp(strlwr(frase), strlwr(fraseUtente)) == 0)
			{
				printf("\nHai indovinato!");
				system("pause");
				exit(0);
			}
			else
				printf("\nFrase non corretta!");

			if (numeroTentativi >= MASSIMO_TENTATIVI)
			{
				printf("\nHai esaurito i tentativi a tua disposizione!");
				system("pause");
				exit(0);
			}
		}
		else
		{
			numeroLettere++;

			trovato = 0;
			for (i = 0; i < LUNGHEZZA_FRASE && frase[i] != '\0'; i++)
			{
				if (tolower(frase[i]) == lettera)
				{
					fraseCrittografata[i] = frase[i];
					trovato = 1;
				}
			}

			if (trovato)
				printf("\nLettera trovata!");
			else
				printf("\na lettera non e' presente nella frase!");

			if (numeroLettere >= numeroMassimoInserimentiLettere)
			{
				printf("\nHai raggiunto il numero massimo di inserimenti!");
				printf("\nProva a indovinare la frase nascosta: ");
    			i = 0;
				while ((ch=getche())!='\n' && ch!='\r' && i <LUNGHEZZA_FRASE)
					fraseUtente[i++] = ch;

				if (strcmp(strlwr(frase), strlwr(fraseUtente)) == 0)
					printf("\nHai indovinato!");
				else
					printf("\nFrase non corretta! Hai perso!");
				system("pause");
				exit(0);
			}
		}
	}
	while(1);

    return 0;
}
