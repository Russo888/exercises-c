/*
 ============================================================================
 Name        : Battaglia_navale.c
 Author      : Nicola Russo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	int seed=time(NULL);
	srand(seed);

	//inizializzazione variabili
    int campo [6][6];
    int campo_visibile [6][6];
    int coord_x[6], coord_y[6];
    int i=0, j=0, conta_navi=0, conta_mosse=0, lettere_campo=65, numero_campo=1, scelta_y;
    char scelta_x, scelta_x_maiuscola;      
	bool flag=false;
    
    //riempimento matrici
    for (i=0;i<6;i++)
    {
	    for(j=0; j<6; j++)
	    {
	    	campo[i][j]=0;
		}
	}
	
	for (i=0;i<6;i++)
    {
	    for(j=0; j<6; j++)
	    {
	    	campo_visibile[i][j]=120;
		}
	}
	
	//generazione navi
    for (i=0;i<6;i++)
    {
    	do
    	{
    		flag=false;
			coord_x[i]=rand()%6;
			coord_y[i]=rand()%6;

			if(i!=0){
				for(j=0; j<i; j++){
					if(coord_x[i]==coord_x[j] && coord_y[i]==coord_y[j])   flag=true;
				}
			}

    	}while(flag==true);
    	campo[coord_x[i]][coord_y[i]]=1;
    }
    
	//gestione dei tentativi
	do{	
	    system("cls");
	    
	    puts("Le x sono le posizioni ancora non colpite\nGli 0 sono le posizioni senza navi\nGli 1 sono le posizioni in cui ci sono navi");
	    
		numero_campo=1;
		lettere_campo=65;
		
		//visualizzazione campo
	    for (i=0;i<7;i++)
	    { 
	    	
	    	if (i==0)
	    	{
	    			printf("\n%c   ", 32);
			}
			else
			{
				printf("%c   ", lettere_campo);
		    	lettere_campo++;
			}
			
	    	for(j=0; j<6; j++)
	    	{
	    		if(i==0){
	    			printf("%d   ", numero_campo);
					numero_campo++;	
				} 
	    		else printf("%c   ", campo_visibile[i-1][j]);
			}
			puts("\n");
		}
		
		printf("Hai fatto %d mosse\n", conta_mosse);
		printf("Hai preso %d navi\n\n", conta_navi);
		
		//inserimento coordinate
		puts("Inserisci le coordinate");
		do
		{
			flag=false;			
			puts("Inserisci la lettera (tra \"A\" e \"F\")");
			scanf("%s", &scelta_x);
			scelta_x_maiuscola=toupper(scelta_x);
			scelta_x_maiuscola=scelta_x_maiuscola-65; 
			if(scelta_x_maiuscola<0 || scelta_x_maiuscola>6)
			{
				flag=true;
			}
		}while(flag!=false);
		do
		{
			flag=false;
			puts("Inserisci il numero (tra 1 e 6)\n");
			scanf("%d", &scelta_y);
			scelta_y--;
			if(scelta_y<0 || scelta_y>5)
			{
				flag=true;
			}
		}while(flag!=false);
			
			
		//controllo navi colpite
		if(campo[scelta_x_maiuscola][scelta_y]==1)
		{
			campo_visibile[scelta_x_maiuscola][scelta_y]=49;
			conta_navi++;
		} 
		else 
		{
			campo_visibile[scelta_x_maiuscola][scelta_y]=48;
		}
		
		conta_mosse++;	
		flag=false;
		if(conta_mosse==10 || conta_navi==6) flag=true;
		
	}while(flag==false);
	

	printf("\nHai preso %d navi in %d mosse\n", conta_navi, conta_mosse);
	
    system("pause");
	return EXIT_SUCCESS;
}
