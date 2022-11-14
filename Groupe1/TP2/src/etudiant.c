#include <stdio.h>

int main(){

    char* etudiant[5][5]={
        {
            "DUPONT",
            "Jean",
            "1 rue des petites soeurs Lyon",
            "15",
            "20"
        },
        {
            "POKELIN",
            "Baptiste",
            "2 chemin de part dieu Lyon",
            "10",
            "11"
        },
        {
            "TOTO",
            "TATA",
            "la bas Lyon",
            "5",
            "15"
        },
        {
            "TITI",
            "TUTU",
            "pas ici Lyon",
            "20",
            "18"
        },
        {
            "LEconnus",
            "Francis",
            "CPE Lyon",
            "8",
            "2"
        }
    };


    for (int i = 0 ; i < 5; ++i)
    {
        printf("----- Nouvelle étudiant ------- \n");
        printf("Nom : %s \n", etudiant[i][0]);
        printf("Prénom : %s \n", etudiant[i][1]);
        printf("Adresse : %s \n", etudiant[i][2]);
        printf("Note de C : %s \n", etudiant[i][3]);
        printf("Note de système d'exploitation : %s \n", etudiant[i][4]);
        

    }

    return 0;
}