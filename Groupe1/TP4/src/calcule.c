#include <stdio.h>
#include "operator.h"

int main(int argc, char ** argv){
    printf("test");
    

    //char op = '+';
  //  int num1 = 45;
    int num2 = 78;

    
    char op = *argv[1];
    int num1 = (int)argv[2];
  //  int num2 = (long)argv[3];


    printf("val : %d %i %i\n",op, num1 , num2);
    switch (op)
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
    default:
        printf("Erreur");
        return 1;
        break;
    }
    return 0;
}