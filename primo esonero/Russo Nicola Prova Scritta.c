/*
 ============================================================================
 Name        : Russo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cod_articolo;
	int num_pezzi_venduti;
	int anno_vendita;
	int mese_vendita;
}vendite;

typedef struct{
	int cod_articolo;
	int tot_pezzi_venduti;
	float costo_pezzo;
	float tot_incassato;
	int anno_ultima_vendita;
	int mese_ultima_vendita;
}articoli;

vendite vendita[10000];
articoli articolo[10000];
int tot_articoli=0;
int tot_vendite=0;
int arrai[10000];

void ordina(){
	int i=1;
	int scambio=0;
	arrai[10000]=1;
	
	if(tot_articoli>1)
	{
		for(i=1;i<=tot_articoli;i++)
		{
			 arrai[i]=i;
		}
		for(i=1;i<tot_articoli;i++)
		{
			if(articolo[arrai[i]].tot_incassato>articolo[arrai[i+1]].tot_incassato)
			{
				scambio=arrai[i];
				arrai[i]=arrai[i+1];
				arrai[i+1]=scambio;
				i=0;
			}
		}	
	}
}

void inserimento(){
	int modifica_i=0;
	tot_vendite++;
	
	printf("\nInserisci il codice dell'articolo\n");
	scanf("%d", &vendita[tot_vendite].cod_articolo);
	printf("Inserisci il numero di pezzi venduti\n");
	scanf("%d", &vendita[tot_vendite].num_pezzi_venduti);
	printf("Inserisci il mese della vendita\n");
	scanf("%d", &vendita[tot_vendite].mese_vendita);
	printf("Inserisci l'anno della vendita\n");
	scanf("%d", &vendita[tot_vendite].anno_vendita);

	int flag=0;
	for(int j=1;j<=tot_articoli;j++)
	{
		if(vendita[tot_vendite].cod_articolo==articolo[j].cod_articolo)
		{
			flag=1;
			modifica_i=j;
		}
	}

	if(flag!=1)
	{
		tot_articoli++;
		articolo[tot_articoli].cod_articolo=vendita[tot_vendite].cod_articolo;
		articolo[tot_articoli].tot_pezzi_venduti=vendita[tot_vendite].num_pezzi_venduti;
		articolo[tot_articoli].mese_ultima_vendita=vendita[tot_vendite].mese_vendita;
		articolo[tot_articoli].anno_ultima_vendita=vendita[tot_vendite].anno_vendita;
		printf("Inserisci il costo di un pezzo\n");
	    scanf("%f", &articolo[tot_articoli].costo_pezzo);
	    articolo[tot_articoli].tot_incassato=articolo[tot_articoli].costo_pezzo*articolo[tot_articoli].tot_pezzi_venduti;

	}
	else
	{
		articolo[modifica_i].tot_pezzi_venduti=articolo[modifica_i].tot_pezzi_venduti+vendita[tot_vendite].num_pezzi_venduti;
		articolo[modifica_i].tot_incassato=articolo[modifica_i].costo_pezzo*articolo[modifica_i].tot_pezzi_venduti;
		
		if(articolo[modifica_i].anno_ultima_vendita<vendita[tot_vendite].anno_vendita)
		{
			articolo[modifica_i].anno_ultima_vendita=vendita[tot_vendite].anno_vendita;
			articolo[modifica_i].mese_ultima_vendita=vendita[tot_vendite].mese_vendita;
		}
		if(articolo[modifica_i].anno_ultima_vendita==vendita[tot_vendite].anno_vendita & articolo[modifica_i].mese_ultima_vendita<vendita[tot_vendite].mese_vendita)
		{			
			articolo[modifica_i].mese_ultima_vendita=vendita[tot_vendite].mese_vendita;
		}
	}

	ordina();
};

int main(void) {
	articolo[1]=articolo[2];
	int i=0;
	int scelta=0;
	int cerca_codice;
	int flag=0;
	do{
		printf("____________________________________:\n");
		printf("\nInserisci la tua scelta:\n\n");
		printf(" 1 per l'inserimento dei dati:\n");
		printf(" 2 per ricercare un articolo:\n");
		printf(" 3 per visualizzare la tabella:\n");
		printf(" 4 per chiudere il programma:\n");

		scanf("%d", &scelta);

		if(scelta<0|scelta>4) printf("\n\nInserisci una scelta valida!!!\n\n");
		if(scelta==1) inserimento();
		if(scelta==2) {
			printf("inserisci il codice dell'articolo:");
			scanf("%d", &cerca_codice);
			if(tot_articoli>0)
			{
				for(i=1; i<=tot_articoli;i++)
				{
					if(cerca_codice==articolo[i].cod_articolo)
					{
						flag=1;
						printf("Codice articolo:  ");
						printf("%d", articolo[i].cod_articolo);
						printf(", ");
						printf("Costo al pezzo:  ");
						printf("%f", articolo[i].costo_pezzo);
						printf(", ");
						printf("Totale dei pezzi venduti:  ");
						printf("%d", articolo[i].tot_pezzi_venduti);
						printf(", ");
						printf("Totale incassato:  ");
						printf("%f", articolo[i].tot_incassato);
						printf(", ");
						printf("data ultima vendita:  ");
						printf("%d", articolo[i].mese_ultima_vendita);
						printf("/");
						printf("%d", articolo[i].anno_ultima_vendita);
						printf("\n\n");
					}
				}
				if(flag==0)
				{
					printf("Questo articolo non è registrato");
				}
			}
			else
				printf("Non ci sono articoli registrati");
		}
		if(scelta==3) {
			if(tot_articoli>0)
			{
				for(i=1; i<=tot_articoli;i++)
				{
					printf("Codice articolo:  ");
					printf("%d", articolo[arrai[i]].cod_articolo);
					printf(", ");
					printf("Costo al pezzo:  ");
					printf("%f", articolo[arrai[i]].costo_pezzo);
					printf(", ");
					printf("Totale dei pezzi venduti:  ");
					printf("%d", articolo[arrai[i]].tot_pezzi_venduti);
					printf(", ");
					printf("Totale incassato:  ");
					printf("%f", articolo[arrai[i]].tot_incassato);
					printf(", ");
					printf("data ultima vendita:  ");
					printf("%d", articolo[arrai[i]].mese_ultima_vendita);
					printf("/");
					printf("%d", articolo[arrai[i]].anno_ultima_vendita);
					printf("\n");
				}
			}
			else
				printf("tabella vuota");
		}
	}while(scelta!=4);
	return EXIT_SUCCESS;
}
