#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"

void insertion (struct couleur * cptr, struct liste_couleurs * lptr){
    struct liste_couleurs *newc; // on créé une nouvelle couleurs
    newc = malloc(sizeof(*newc)); // on lui affecte la mémoire nécéssaire
    newc->couleur = *cptr; // on lui donne l'élément couleur à ajouter
    newc->next = lptr->next; // on définit l'élément suivant qui était dans le 1er élément de la liste
    lptr->next = newc; // on redéfinit l'élément suivant du 1er vers celui créé
    printf("----- insertion------- \n");

};

void parcours (struct liste_couleurs * ptr){
    while(ptr != NULL) { //tant qu'on à un pointeur de définit
        printf("----- Couleur------- \n");
        printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", ptr->couleur.R, ptr->couleur.G, ptr->couleur.B, ptr->couleur.A );
        ptr = ptr->next; //On passe au pointeur suivant récupérer dans l'élément liste
    }
    printf("----- Fin------- \n");

};


int main(){

    struct couleur c1, c2, c3, c4,c5,c6,c7,c8,c9,c10; //on définit toute les couleurs de base
    struct liste_couleurs lc1, lc2, lc3, lc4,lc5,lc6,lc7,lc8,lc9,lc10; //on définit les lists de couleurs
    struct couleur n1, n2, n3, n4,n5,n6,n7,n8,n9,n10; // on définit les couleurs qui seront ajouté
//  Génération de couleurs fix
    c1.R=0x1;
    c1.G=0x57;
    c1.B=0x25;
    c1.A=0x01;
    lc1.couleur = c1; //on ajoute la couleur a la liste
    lc1.next = &lc2; // on donne le pointeur vers l'élément suivant

    c2.R=0x2;
    c2.G=0x78;
    c2.B=0x95;
    c2.A=0x12;
    lc2.couleur = c2;
    lc2.next = &lc3;

    c3.R=0x3;
    c3.G=0x57;
    c3.B=0x25;
    c3.A=0x01;
    lc3.couleur = c3;
    lc3.next = &lc4;

    c4.R=0x4;
    c4.G=0x57;
    c4.B=0x25;
    c4.A=0x01;
    lc4.couleur = c4;
    lc4.next = &lc5;

    c5.R=0x5;
    c5.G=0x78;
    c5.B=0x95;
    c5.A=0x12;
    lc5.couleur = c5;
    lc5.next = &lc6;

    c6.R=0x1;
    c6.G=0x57;
    c6.B=0x25;
    c6.A=0x01;
    lc6.couleur = c6;
    lc6.next = &lc7;

    c7.R=0x2;
    c7.G=0x78;
    c7.B=0x95;
    c7.A=0x12;
    lc7.couleur = c7;
    lc7.next = &lc8;

    c8.R=0x3;
    c8.G=0x57;
    c8.B=0x25;
    c8.A=0x01;
    lc8.couleur = c8;
    lc8.next = &lc9;

    c9.R=0x4;
    c9.G=0x57;
    c9.B=0x25;
    c9.A=0x01;
    lc9.couleur = c9;
    lc9.next = &lc10;

    c10.R=0x5;
    c10.G=0x78;
    c10.B=0x95;
    c10.A=0x12;
    lc10.couleur = c10;
    lc10.next = NULL;

// Génération des couleurs à ajouter 
    n1.R=0x1;
    n1.G=0x57;
    n1.B=0x25;
    n1.A=0x01;

    n2.R=0x2;
    n2.G=0x78;
    n2.B=0x95;
    n2.A=0x12;

    n3.R=0x3;
    n3.G=0x57;
    n3.B=0x25;
    n3.A=0x01;

    n4.R=0x4;
    n4.G=0x57;
    n4.B=0x25;
    n4.A=0x01;

    n5.R=0x5;
    n5.G=0x78;
    n5.B=0x95;
    n5.A=0x12;

    n6.R=0x1;
    n6.G=0x57;
    n6.B=0x25;
    n6.A=0x01;

    n7.R=0x2;
    n7.G=0x78;
    n7.B=0x95;
    n7.A=0x12;

    n8.R=0x3;
    n8.G=0x57;
    n8.B=0x25;
    n8.A=0x01;

    n9.R=0x4;
    n9.G=0x57;
    n9.B=0x25;
    n9.A=0x01;

    n10.R=0x5;
    n10.G=0x78;
    n10.B=0x95;
    n10.A=0x12;

    //appeles des fonctions
    parcours (&lc1); 
    insertion(&n1,&lc1);
    insertion(&n2,&lc1);
    insertion(&n3,&lc1);
    insertion(&n4,&lc1);
    insertion(&n5,&lc1);
    insertion(&n6,&lc1);
    insertion(&n7,&lc1);
    insertion(&n8,&lc1);
    insertion(&n9,&lc1);
    insertion(&n10,&lc1);

    parcours (&lc1);

 
    
    return 0;
}