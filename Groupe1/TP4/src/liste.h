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
}    ;  



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