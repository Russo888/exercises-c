#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int v1[1000], v2[1000], v3[1000];
int n=10, m=12;


//algoritmo di fusione merge------------------------------------------------------------------------------
void merge(int v1[1000], int v2[1000], int v3[1000], int n, int m){
	int i=1, j=1, k=0;
	do
	{
		k++;
		if(v1[i]<v2[j])
		{
			v3[k]=v1[i];
			i++;	
		}
		else
		{
			v3[k]=v2[j];
			j++;
		}
	}while(i<n|j<m);
	
	if(i>n)
	{
		do{
			k++;
			v3[k]=v2[j];
			j++;
		}while(j<m);
	}	
	else
	{
		do{
			k++;
			v3[k]=v1[i];
			i++;
		}while(i<n);	
	}
}
//algoritmo di ordinamento bubble sort-------------------------------------------------------------------
void bubble_sort(int vet[1000], int num_elementi){
	int p=num_elementi, scambia, i;
	bool scambio;
	do{
		scambio=false;
		i=0;
		do{
			i=i+1;
			if(vet[i]>vet[i+1])
			{
				scambia=vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=scambia;
				scambio=true;
			}
		}while(i<p-1);
		p=p-1;
	}while(scambio==true);
}



//algoritmo di selection sort----------------------------------------------------------------------------
void selection_sort(int vet[1000], int num_elementi){
	int i=0, k=0, j=0, min=0, scambia=0;
	do{
		i=i+1;
		min=vet[i];
		k=i;
		j=i+1;
		do{
			if(min>vet[j])
			{
				min=vet[j];
				k=j;
			}
			j=j+1;
		}while(j<=num_elementi);
		scambia=vet[i];
		vet[i]=vet[k];
		vet[k]=scambia;
	}while(i<num_elementi-1);	
}

//funzione di visualizzazione degli array-----------------------------------------------------------------------
void visualizza(int vet[1000], int num_elementi){
	for(int saba=1; saba<=num_elementi; saba++){
		printf("%d", vet[saba]);
		printf(", ");
	}
	printf("\n");
}

//main----------------------------------------------------
int main(int argc, char *argv[]) {
	
	for(int saba=1; saba<=n; saba++){
		printf("Inserisci v1: ");
		scanf("%d", &v1[saba]);
	}
	
	for(int saba=1; saba<=m; saba++){
		printf("Inserisci v2: ");
		scanf("%d", &v2[saba]);
	}
	
	selection_sort(v1, n);
	selection_sort(v2, m);
	
	//bubble_sort(v2, m);
	//bubble_sort(v1, n);
	
	merge(v1, v2, v3, n, m);
		
	printf("v1: ");
	visualizza(v1, n);
	printf("v2: ");	
	visualizza(v2, m);
	printf("v3: ");
	visualizza(v3, 22);
	
	return 0;
}