/*
 ============================================================================
 Name        : gestione.c
 Author      : Nicola Russo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define min_voto 18
#define max_voto 31
#define num_studenti 1
#define num_voti 20

typedef enum{True, False}bool_t;

typedef struct{
	int giorno;
	int mese;
	int anno;
}data_nascita_t;

typedef struct{
	char nome[20];
	char cognome[20];
	char matricola[6];
	data_nascita_t data_nascita;
	int voti[num_voti];
}studente;

void inserimento_dati(studente studenti[num_studenti], float medie_studenti[num_studenti], int cont_voti[14])
{

	int somma_voti=0, indice_studente_max_media, moda=0, max_num_voti=-1;
	float max_media=0;
	bool_t flag;
	int i=0, j=0;
	for(i=0; i<num_studenti;i++)
	{
		somma_voti=0;
		printf("\nInserisci il nome dello studente numero %d: ", i+1);
		scanf("%s", studenti[i].nome);
		printf("Inserisci il cognome dello studente numero %d: ", i+1);
		scanf("%s", studenti[i].cognome);
		printf("Inserisci la matricola dello studente numero %d: ", i+1);
		scanf("%s", studenti[i].matricola);

		do
		{
			printf("Inserisci l'anno di nascita dello studente numero %d: ", i+1);
			scanf("%d", &studenti[i].data_nascita.anno);
		}while((studenti[i].data_nascita.anno>2004) | (studenti[i].data_nascita.anno<1900));

		do
		{
			printf("Inserisci il mese di nascita dello studente numero %d: ", i+1);
			scanf("%d", &studenti[i].data_nascita.mese);
		}while((studenti[i].data_nascita.mese>12) | (studenti[i].data_nascita.mese<1));

		do
		{
			flag=False;
			printf("Inserisci il giorno di nascita dello studente numero %d: ", i+1);
			scanf("%d", &studenti[i].data_nascita.giorno);

			if((studenti[i].data_nascita.mese==4) & (studenti[i].data_nascita.giorno>30))    flag=True;
			if((studenti[i].data_nascita.mese==6) & (studenti[i].data_nascita.giorno>30))    flag=True;
			if((studenti[i].data_nascita.mese==9) & (studenti[i].data_nascita.giorno>30))    flag=True;
			if((studenti[i].data_nascita.mese==11) & (studenti[i].data_nascita.giorno>30))    flag=True;

			if((studenti[i].data_nascita.mese==1) & (studenti[i].data_nascita.giorno>31))    flag=True;
			if((studenti[i].data_nascita.mese==3) & (studenti[i].data_nascita.giorno>31))    flag=True;
			if((studenti[i].data_nascita.mese==5) & (studenti[i].data_nascita.giorno>31))    flag=True;
			if((studenti[i].data_nascita.mese==7) & (studenti[i].data_nascita.giorno>31))    flag=True;
			if((studenti[i].data_nascita.mese==12) & (studenti[i].data_nascita.giorno>31))    flag=True;

			if((studenti[i].data_nascita.mese==2) & (studenti[i].data_nascita.giorno>28))
			{
				flag=True;
				if((studenti[i].data_nascita.giorno==29) & (studenti[i].data_nascita.anno%4==0))
				{
					flag=False;
				}
			}
		}while(flag==True);

		for(j=0;j<num_voti;j++)
		{
			studenti[i].voti[j]=rand()%(max_voto-min_voto+1)+min_voto;
			cont_voti[studenti[i].voti[j]-18]++;
			printf("%d, ", studenti[i].voti[j]);
			somma_voti+=studenti[i].voti[j];
		}
		medie_studenti[i]=somma_voti/num_voti;
		if(max_media<medie_studenti[i])
		{
			indice_studente_max_media=i;
			max_media=medie_studenti[i];
		}
	}

	for(i=0; i<14;i++)
	{
		if (max_num_voti<cont_voti[i])
		{
			max_num_voti=cont_voti[i];
			moda=i+18;
		}
	}

	printf("\nIl massimo media e' dello studente %s %s ed e': %.2f: ", studenti[indice_studente_max_media].nome, studenti[indice_studente_max_media].cognome, max_media);
	printf("\nLa moda e': %d: ", moda);
}

int main(void) {
	float medie_studenti[num_studenti];
	int seed=time(NULL), i=0, cont_voti[14];
	srand(seed);
	studente studenti[num_studenti];

	for(i=0; i<14;i++)
	{
		cont_voti[i]=0;
	}

	inserimento_dati(studenti, medie_studenti, cont_voti);

	system("pause");
	return EXIT_SUCCESS;
}
