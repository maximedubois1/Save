struct couleur //on définit la strucuture d'une couleurs
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

struct liste_couleurs {           //on définit       
   // Remplissez ça pour gérer une liste (simplement chainée) de couleurs.
    struct couleur couleur;
    struct liste_couleurs *next;
}    ;  



void insertion (struct couleur * cptr, struct liste_couleurs * lptr){
    struct liste_couleurs *newc;
    newc = malloc(sizeof(*newc));
    newc->couleur = *cptr;
    newc->next = lptr->next;
    lptr->next = newc;
    printf("----- insertion------- \n");

};

void parcours (struct liste_couleurs * ptr){
    while(ptr != NULL) { //navigation
        printf("----- Couleur------- \n");
        printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", ptr->couleur.R, ptr->couleur.G, ptr->couleur.B, ptr->couleur.A );
        ptr = ptr->next; //couleur suivante
    }
    printf("----- Fin------- \n");

};