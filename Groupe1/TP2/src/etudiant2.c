#include <stdio.h>
#include <string.h>

int main(){

    struct etudiant{
        char prenom[30];
        char nom[30];
        char adresse[50];
        short notes1;
        short notes2;
    };

    struct etudiant etudiant[5];
    strcpy(etudiant[0].prenom, "DUPONT");
    strcpy(etudiant[0].nom, "Jean");
    strcpy(etudiant[0].adresse, "1 rue des petites soeurs Lyon");
    etudiant[0].notes1 = 15;
    etudiant[0].notes2 = 20;

    strcpy(etudiant[1].prenom, "POKELIN");
    strcpy(etudiant[1].nom, "Baptiste");
    strcpy(etudiant[1].adresse, "2 chemin de part dieu Lyon");
    etudiant[1].notes1 = 10;
    etudiant[1].notes2 = 11;

    strcpy(etudiant[2].prenom, "TOTO");
    strcpy(etudiant[2].nom, "TATA");
    strcpy(etudiant[2].adresse, "la bas Lyon");
    etudiant[2].notes1 = 5;
    etudiant[2].notes2 = 15;

    strcpy(etudiant[3].prenom, "TITI");
    strcpy(etudiant[3].nom, "TUTU");
    strcpy(etudiant[3].adresse, "pas ici Lyon");
    etudiant[3].notes1 = 20;
    etudiant[3].notes2 = 18;

    strcpy(etudiant[4].prenom, "LEconnus");
    strcpy(etudiant[4].nom, "Francis");
    strcpy(etudiant[4].adresse, "CPE Lyon");
    etudiant[4].notes1 = 8;
    etudiant[4].notes2 = 2;



    for (int i = 0 ; i < 5; ++i)
    {
        printf("----- Nouvelle étudiant ------- \n");
        printf("Nom : %s \n", etudiant[i].nom);
        printf("Prénom : %s \n", etudiant[i].prenom);
        printf("Adresse : %s \n", etudiant[i].adresse);
        printf("Note de C : %hd \n", etudiant[i].notes1);
        printf("Note de système d'exploitation : %hd \n", etudiant[i].notes2);
        

    }

    return 0;
}