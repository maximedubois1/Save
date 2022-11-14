#include <stdio.h>
int main(){
    int num1 = 10;
    int num2 = 5;
    char op;

    printf("Opération entre %d et %d : ", num1, num2);
    scanf("%c",&op);


    switch (op)
    {
    case '+':
        printf("somme : %d\n",num1 + num2);
        break;
    case '-':
        printf("moins : %d\n",num1 - num2);
        break;
    case '*':
        printf("multiplier : %d\n",num1 * num2);
        break;
    case '/':
        printf("diviser : %d\n",num1 / num2);
        break;
    case '%':
        printf("modulo : %d\n",num1 % num2);
        break;
    case '&':
        printf("ET : %d\n",num1 && num2);
        break;
    case '|':
        printf("OU : %d\n",num1 || num2);
        break;
    case '~':
        printf("~ num1: %d ~ num2 : %d\n",~num1, ~num2);
        break;
    default:
        printf("Erreur");
        return 1;
        break;
    }


    return 0;
}