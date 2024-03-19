/*
 * stringhe.c
 *
 *  Created on: 13/dic/2010
 *      Author: Acer
 */
#include <stdio.h>
#include <stdlib.h>


int
main()
{
     /* char nome[20] = {'m','a','r','i','o',' ','r','o','s','s','i','\0'}; questa è una possibile inizializzazione della stringa */

    char nome[20] ; /* = "Mario Rossi"; questa rappresenta una possibile inizializzazione della stringa*/
    printf("Inserire il nome di max 20 caratteri (senza spazi) --> ");
    scanf("%s", nome);
    //nome="Mario Rossi"; questa istruzione restituisce un errore in compilazione..provate
    printf("****%s****\n", nome);
    printf("****%4s****\n", nome);
    printf("****%20s****\n", nome);
    printf("****%-20s****\n", nome);
    system("pause");
    return 0;
}

