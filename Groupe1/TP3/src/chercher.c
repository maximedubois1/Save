#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fonction de hash
int hash(char *string){
    int hashed =0;
    for(int i = 0; string[i] != '\0'; i++){
        hashed += string[i];
    }
    return hashed;
}


int main (){
    int len_tab = 100;
    int tab[len_tab];

    srand( time( NULL ) );
    //On définit le tableau avec des valeurs aléatoire
    for (int i=0; i<=len_tab; i++){
        *(tab+i) = rand() % 1000;
        printf("tab %d\n", *(tab+i));
    }
    
    int ent = 10; //l'entier à tester
    int n=0;
    //Pour chaque entier de la liste 
    for (int i=0; i<len_tab; i++){
        if (ent == *(tab+i)){ //on le compare à l'entier et s'il est présent on change n et on s'arrete
            n=1;
            break;
        }
    }
    //on affiche la réponse en fonction de n
    printf("---------------------Réponse--------------------\n");
    if(n==1){
        printf("l'entier %d est présent\n", ent);
    } else {
        printf("l'entier %d est absent\n", ent);
    }

    printf("---------------------Test de pharse--------------------\n");

    n=0;

    int nbrdepharse = 10;
    char* tabchaine[10] = {"Phrase 1", "Phrase 2", "Phrase 3", "Phrase 4", "Phrase 5", "Phrase 6", "Phrase 7", "Phrase 8", "Phrase 9", "Phrase 10"};
    char* phrase = "Phrase 1";
    int hashphrase = hash(phrase);

    //pour chaqu'une des pharses
    for (int i =0; i< nbrdepharse; i++){
        if(hashphrase == hash(*(tabchaine+i))){ //on vérifier si le hash de la pharse correspond à celle chercher gràce à la fonction
            printf("la pharse '%s' est présente \n", phrase);
            return 0;

        }
    }
    printf("la pharse '%s' est absente \n", phrase);

    return 0;
}