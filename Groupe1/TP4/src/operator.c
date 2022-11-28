#include <stdio.h>
#include "operator.h"

int main(){
    int num1 = 10;
    int num2 = 5;
    char op;
    
    
    printf("Opération entre %d et %d : ", num1, num2);
    scanf("%c",&op);

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