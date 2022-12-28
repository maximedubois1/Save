#include <stdio.h>
#include <stdlib.h>

struct couleur //on définit la structure d'une couleurs
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

struct liste_couleurs {           //on définit la structure d'une liste      
    struct couleur couleur; //on inclut une couleur 
    struct liste_couleurs *next; // et le pointeur vers l'élement suivant
};  

void insertion (struct couleur * cptr, struct liste_couleurs * lptr);
void parcours (struct liste_couleurs * ptr);