#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	int codice;
	char descrizione[50];
	int eta_minima;
	int eta_massima;
	int pezzi_disponibili;
	int pezzi_minimi;
	float costo_pezzo;
}giocattolo;

typedef struct{
	int codice_ric;
	int num_richieste;
}conta_richiesta;

giocattolo giocattoli[1000];
conta_richiesta conta_richieste[1000];

int num_giocattoli=0;

void inserimento(){
	printf("Inserisci il numero di giocattoli");
	
	do{
		scanf("%d", &num_giocattoli);
	}while(num_giocattoli<=0);
	
	int i=0;
	do{
		i=i+1;
		printf("Inserisci il codice:");
		scanf("%d", &giocattoli[i].codice);
		printf("Inserisci la descrizione:");
		scanf("%s", giocattoli[i].descrizione);
		printf("Inserisci l'eta' minima':");
		scanf("%d", &giocattoli[i].eta_minima);
		do{
			printf("Inserisci l'eta' massima':");
			scanf("%d", &giocattoli[i].eta_massima);
		}while(giocattoli[i].eta_minima>giocattoli[i].eta_massima);
		printf("Inserisci il costo al pezzo:");
		scanf("%f", &giocattoli[i].costo_pezzo);
		printf("Inserisci i pezzi disponibili:");
		scanf("%d", &giocattoli[i].pezzi_disponibili);
		printf("Inserisci i pezzi minimi in magazzino:");
		scanf("%d", &giocattoli[i].pezzi_minimi);
		
	}while(i<num_giocattoli);
}

void visualizza(){
	int i;
	for(i=1; i<=num_giocattoli; i++)
	{		
		printf("Codice: ");
		printf("%d", giocattoli[i].codice);
		printf("  Descrizione:");
		printf("%s", giocattoli[i].descrizione);
		printf("  Eta minima':");
		printf("%d", giocattoli[i].eta_minima);
		printf("  Eta massima':");
		printf("%d", giocattoli[i].eta_massima);
		printf("  Costo al pezzo:");
		printf("%f", giocattoli[i].costo_pezzo);
		printf("  Pezzi disponibili:");
		printf("%d", giocattoli[i].pezzi_disponibili);
		printf("  Pezzi minimi in magazzino':");
		printf("%d", giocattoli[i].pezzi_minimi);
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	inserimento();
	
	visualizza();
	
	return 0;
}