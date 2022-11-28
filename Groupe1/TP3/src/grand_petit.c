#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int tab[100];
    int mini;
    int max;
    //Génération d'un tableau de 100 entier 
    srand( time( NULL ) );
    for (int i=0; i<100; i++){
        tab[i] = rand() % 1000;
        printf("tab %i\n", tab[i]);
        if (mini > tab[i]) mini = tab[i]; //si l'entier générer est inférieur à la dernière valeur mini stocker il prend sa place
        if (max < tab[i]) max = tab[i];//si l'entier générer est supérieur à la dernière valeur max stocker il prend sa place

    }
    printf("mini %i\n", mini);
    printf("max %i\n", max);
    return 0;
}