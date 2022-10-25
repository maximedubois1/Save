#include <stdio.h>
#include <math.h>

int main() {
    int rayon = 5;
    //aire :pi * r * r 
    //périmètre ! 2pi r 
    printf("l'aire d'un cercle de rayon %d est %f \n",rayon , M_PI * rayon * rayon);
    printf("le périmètre d'un cercle de rayon %d est %f \n",rayon, 2* M_PI * rayon);
    
    return 0;
};