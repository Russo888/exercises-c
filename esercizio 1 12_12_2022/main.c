#include <stdio.h>
#include <stdlib.h>

/* Scrivere un algoritmo e il relativo
programma che generi e memorizzi i
primi n>=1(definito in input dall’utente)
elementi della successione di Fibonacci
in un vettore e che lo visualizzi all’utente
I primi due termini sono 0 e 1
Ogni termine successivo è ottenuto come
somma degli ultimi 2 termini
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, …*/

int main()
{
    int n=0;

    do
    {
        printf("inserire un numero maggiore di 1: ");
        scanf("%d", &n);
    }
    while(n<2);

    int vett[n];

    vett[0]=0;
    vett[1]=1;

    for(int i=2; i<=n; i++)
    {
        vett[i]=vett[i-1]+vett[i-2];
    }

    for(int i=0; i<=n; i++)
    {
        printf("%d", vett[i]);

        if(i!=n)
        {
            printf(", ");
        }
    }
}
