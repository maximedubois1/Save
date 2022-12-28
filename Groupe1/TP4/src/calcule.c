#include <stdio.h>
#include <stdlib.h>

#include "operator.h"

int main(int argc, char ** argv){
    
    if (argc < 4) //si il y a pas les 3 arguments
    {
        printf("Erreur veulliez entrer 3 argument");
        return 1;
    }
    
    //on récupère les différents arguments
    char op = *argv[1];
    int num1 = atoi(argv[2]); //atoi pour transfort le string en int
    int num2 = atoi(argv[3]);


    printf("val : %c %i %i\n",op, num1 , num2); //affichage des différente valeurs
    switch (op) //en fonction de op on appelle la bonne fonction
    {
    case '+':
        printf("somme : %d\n",somme(num1, num2));
        break;
    case '-':
        printf("moins : %d\n", difference(num1 , num2));
        break;
    case '*':
        printf("multiplier : %d\n",produit(num1 , num2));
        break;
    case '/':
        printf("diviser : %d\n",quotient(num1 , num2));
        break;
    case '%':
        printf("modulo : %d\n",modulo(num1 , num2));
        break;
    case '&':
        printf("ET : %d\n",et(num1 , num2));
        break;
    case '|':
        printf("OU : %d\n",ou(num1 , num2));
        break;
    case '~':
        printf("~ num1: %d\n",negation(num1));
        break;
    default: //Si ça ne fait pas parti de ces cas
        printf("Erreur");
        return 1;
        break;
    }
    return 0;
}