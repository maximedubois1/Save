#include <stdio.h>

int operatore(char op, float num1, float num2)
{
    float result = 0;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        printf("somme : %f + %f = %f\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("moins : %f - %f = %f\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("multiplier : %f * %f = %f\n", num1, num2, result);
        break;
    case '/':
        result = num1 / num2;
        printf("diviser : %f / %f = %f\n", num1, num2, result);
        break;
    default:
        printf("Erreur : opérateur non valide.\n");
        return 1;
        break;
    }
    return result;
}
