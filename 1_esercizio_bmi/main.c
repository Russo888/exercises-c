/* Il Body Mass Index (BMI) è calcolato come il rapporto tra il peso e il quadrato dell’altezza (espresso in metri) 
di un individuo. Gli individui sovrappeso hanno un BMI superiore a 25BMI = peso / (altezza_in_metri * altezza_in_metri) 

Scrivere un algoritmo che generi random età, altezza e peso di dieci individui e calcoli il BMI di ciascuno 
di essi e lo mostri sullo schermo.
L’algoritmo deve calcolare il massimo di altezza e peso e la media del BMI, distinguendo over 40 e under 40
L’algoritmo deve anche stampare in output i valori massimi di altezza e peso (per le due categorie) 
L'algoritmo deve stampare un messaggio sullo schermo del tipo «Il campione è mediamente sovrappeso/normopeso/sovrappeso» 
a seconda del BMI medio del campione (sia per gli under 40 che per gli over). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int seed=time(NULL);
    srand(seed);
    int eta, i, conta_over40=0, conta_under40=0;
    float altezza, peso, bmi, altezza_max_over40=0, altezza_max_under40=0, peso_max_over40=0, peso_max_under40=0, media_bmi_over40, media_bmi_under40, somma_bmi_over40, somma_bmi_under40;
    int const max_altezza=180, min_altezza=155, max_peso=1200, min_peso=450, max_eta=80, min_eta=20;
    
    for(i=0;i<10;i++)
    {
        eta=rand()%(max_eta-min_eta+1)+min_eta;
        peso=rand()%(max_peso-min_peso+1)+min_peso;
        altezza=rand()%(max_altezza-min_altezza+1)+min_altezza;
        
        altezza=altezza/100.0;
        peso=peso/10.0;
        bmi=peso/(altezza*altezza);
        
        printf("\nEta--->'%d", eta);
        printf("\nPeso--->%.2f", peso);
        printf("\nAltezza--->%.2f", altezza);
        printf("\nBMI--->%.2f", bmi);
        
        if(bmi<18)  printf("\nIl soggetto è sottopeso");
        if(bmi>=18 & bmi<25)  printf("\nIl soggetto è normopeso");
        if(bmi>=25 & bmi<30)  printf("\nIl soggetto è sovrapeso");
        if(bmi>=30 & bmi<40)  printf("\nIl soggetto è obeso");
        if(bmi>=40)  printf("\nIl soggetto è gravemente obeso");
        
        if(eta>=40)
        {
            if(altezza>altezza_max_over40)  altezza_max_over40=altezza;
            if(peso>peso_max_over40)  peso_max_over40=peso;
            somma_bmi_over40+=bmi;
            conta_over40++;
        }
        if(eta<40)
        {
            if(altezza>altezza_max_under40)  altezza_max_under40=altezza;
            if(peso>peso_max_under40)  peso_max_under40=peso;
            somma_bmi_under40+=bmi;
            conta_under40++;
        }
    }
    
    media_bmi_over40=somma_bmi_over40/conta_over40;
    media_bmi_under40=somma_bmi_under40/conta_under40;
    
    printf("\nLa media del BMI dei soggetti over 40 e': %.2f", media_bmi_over40);
    printf("\nLa media del BMI dei soggetti under 40 e': %.2f", media_bmi_under40);
    printf("\nL'altezza massima dei soggetti over 40 e': %.2f", altezza_max_over40);
    printf("\nIl peso massimo dei soggetti over 40 e': %.2f", peso_max_over40);
    printf("\nL'altezza massima dei soggetti under 40 e': %.2f", altezza_max_under40);
    printf("\nIl peso massimo dei soggetti under 40 e': %.2f", peso_max_under40);
    
    
    
    return EXIT_SUCCESS;
}
