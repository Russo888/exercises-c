#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	char nome_skipper[20];
	char cognome_skipper[20];
	int num_cabine;
	int giorni_prenotati[100];
	int mesi_prenotati[100];
	int anni_prenotati[100];
}barche;

typedef struct{
	char nome[20];
	char cognome[20];
	int num_cabine_pren;
	int giorno_prenotazione[100];
	int mese_prenotazione[100];
	int anno_prenotazione[100];
}prenotazioni;

barche barca[100];
prenotazioni prenotazione[100];

int num_barche=0;

void inserimento(){
	int flag=false;
	int j=0, i=0;
	printf("Inserisci il numero di barche: ");
	scanf("%d", &num_barche);
	for(i=1;i<=num_barche;i++)
	{
		if(i==1)
		{
			printf("Inserisci il nome dello skipper: ");
			scanf("%s", barca[i].nome_skipper);
			printf("Inserisci il cognome dello skipper: ");
			scanf("%s", barca[i].cognome_skipper);
		}
		else	
		{
			do
			{	
				if(j>0)
				{
					printf("Quello skipper guida gia'' un'altra barca!!\n': ");
				}
				printf("Inserisci il nome dello skipper: ");
				scanf("%s", barca[i].nome_skipper);
				printf("Inserisci il cognome dello skipper: ");
				scanf("%s", barca[i].cognome_skipper);
				for(j=1; j<i;j++)
				{
					if(barca[i].nome_skipper==barca[j].nome_skipper & barca[i].cognome_skipper==barca[j].cognome_skipper)
					{
						flag=true;
					}
				}
			}while(flag=true);
		}
		flag=false;
		j=0;
		printf("Inserisci il numero di cabine della barca: ");
		scanf("%d", &barca[i].num_cabine);
	}
}


void ricerca_skipper()
{
	int indice=0;
	int nome_ricerca;
	int cognome_ricerca;
	bool flag=false;
	for(int i=1;i<=num_barche;i++)
	{
		if(nome_ricerca==barca[i].nome_skipper){
			if(nome_ricerca==barca[i].nome_skipper){
				flag=true;
				indice=i;
			}
		}
	}
	if(flag==true)
	{
		printf("Nome skipper:  ");
		printf("%s", barca[indice].nome_skipper);
		printf(", ");
		printf("Cognome skipper:  ");
		printf("%s", barca[indice].cognome_skipper);
		printf(", ");
		printf("Numero cabine:  ");
		printf("%d", barca[indice].num_cabine);
		printf("\n\n");
	}
}


int main(int argc, char *argv[]) {
	
	inserimento();
	ricerca_skipper();
	
	return 0;
}