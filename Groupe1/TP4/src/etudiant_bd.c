#include <stdio.h>
#include <string.h>
#include "fichier.h"

int main(){
    char fichier[] = "etudiant.txt";
    struct etudiant{ //on définit la structure d'un étudiant
        char prenom[30];
        char nom[30];
        char adresse[50];
        short notes1;
        short notes2;
    };

    struct etudiant etudiant[5]; //on créer un tableau de 5 étudiants

    //On leurs donnes des valeurs
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


    char note[10];
      
    ecrire_fichier(fichier, "", 'W');

    for (int i = 0 ; i < 5; ++i)
    {
        //On utilise la fonction ecrire_fichier pour écrire les information nécéssaire
        ecrire_fichier(fichier, etudiant[i].nom,'A');
        ecrire_fichier(fichier, " , ",'A');
        ecrire_fichier(fichier, etudiant[i].prenom,'A');
        ecrire_fichier(fichier, " , ",'A');
        ecrire_fichier(fichier, etudiant[i].adresse,'A');
        ecrire_fichier(fichier, " , ",'A');
        sprintf(note, "%d", etudiant[i].notes1);
        ecrire_fichier(fichier, note,'A');
        ecrire_fichier(fichier, " , ",'A');
        sprintf(note, "%d", etudiant[i].notes2);
        ecrire_fichier(fichier, note,'A');
        ecrire_fichier(fichier, " \n",'A');

    }
    //on affiche le fichier
    lire_fichier(fichier);

    return 0;
}