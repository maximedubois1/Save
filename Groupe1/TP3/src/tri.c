#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fontion de tris à bulle
int tri(int *tab, int len_tab){
    int n=1;
    int tmp=0;
    //tant qu'on fait des changement 
    while (n != 0){
        n=0;
        for (int i=0; i<len_tab; i++){ //pour chaque valeur du tableau
            if (*(tab+i) > *(tab+i+1)){ // si la valeur est supérieur à la valeur suivante
                //on inverse les 2 valeurs
                tmp = *(tab+i);
                *(tab+i) = *(tab+i+1);
                *(tab+i+1) = tmp;
                n=1; //on note qu'on à fait un changement 
            }
        }
    }
    return 0;
}


int main (){
    int len_tab = 100;
    int tab[len_tab];

    //srand( time( NULL ) );
    //génération d'un tableau de 100 entiers
    for (int i=0; i<=len_tab; i++){
        *(tab+i) = rand() % 1000;
        //printf("tab %d\n", *(tab+i));
    }
    
    tri(tab, len_tab);
    
    printf("---------------------Réponse\n");
    //on affiche le tableau trié
    for (int i=0; i<len_tab; i++){
        printf("tab %d\n", *(tab+i));
    }

    return 0;
}