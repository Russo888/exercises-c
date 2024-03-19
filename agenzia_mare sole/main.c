#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codice;
	int numerocabine;
	char nome_skipper[30];
	int giorno_libero;
	int mese_libero;
	int anno_libero;
}barche;

barche barca[1000];
int maxcod_barca=0;

void inserimento(){
	maxcod_barca++;
	barca[maxcod_barca].codice=maxcod_barca;
	int apponum;
	char appochar[30];
		
	printf("Inserisci il numero di cabine della barca:\n");
	scanf("%d", &barca[maxcod_barca].numerocabine);
	
	printf("Inserisci il nome dello skipper:\n");
	scanf("%s", barca[maxcod_barca].nome_skipper);
	
	printf("Inserisci da quando la barca sara' libera:\n");
	printf("Inserisci il giorno:\n");
	scanf("%d", &barca[maxcod_barca].giorno_libero);
	printf("Inserisci il mese:\n");
	scanf("%d", &barca[maxcod_barca].mese_libero);
	printf("Inserisci l'anno':\n");
	scanf("%d", &barca[maxcod_barca].anno_libero);
	
}
	
void verifica_richiesta(){
	int giorno_prenotazione;
	int mese_prenotazione;
	int anno_prenotazione;
	
	printf("Quando vuole prenotare l'uscita?\n");
	printf("Inserisci il giorno:\n");
	scanf("%d", &anno_prenotazione);
	printf("Inserisci il mese:\n");
	scanf("%d", &mese_prenotazione);
	printf("Inserisci l'anno':\n");
	scanf("%d", &anno_prenotazione);
	
	for(int i=1; i<=maxcod_barca;i++){
		if(anno_prenotazione>=barca[i].anno_libero)
		{
			if(mese_prenotazione>=barca[i].mese_libero)
			{
				if(giorno_prenotazione>=barca[i].giorno_libero)
				{
					printf("La prenotazione e' disponibile\n");
				}
				else	printf("Non ci sono barche disponibili per quel giorno':\n");
			}
			else	printf("Non ci sono barche disponibili per quel mese':\n");
		}
		else	printf("Non ci sono barche disponibili per quell'anno':\n");
	}
	
};

void info_skipper(){

};
	                                
	

void menu(){
	int scelta=0;
	
	do{
		printf("Benvenuto in agenzia viaggi Mare-Sole \nschiaccia: \n 1 per inserire una nuova barca \n 2 per effettuare una richiesta \n 3 per avere informazioni su uno skipper \n 4 per chiudere il programma\n");
		scanf("%d", &scelta);   
		
		if(scelta<1 | scelta>4)	printf("Inserisci una scelta valida\n");		
		if(scelta==1) inserimento();		
		if(scelta==2) verifica_richiesta();
		if(scelta==3) info_skipper();
		
	}while(scelta!=4);
};

int main(int argc, char *argv[]) {
	menu();
	return 0;
}