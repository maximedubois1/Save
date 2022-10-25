#include <stdio.h>

int main(){
    int a = 16;
    int b = 3;
    printf("arithmétiques : \n");
    printf("a + b : %d \n", a + b);
    printf("a - b : %d \n", a - b);
    printf("a * b : %d \n", a * b);
    printf("a / b : %d \n", a / b);
    printf("a \% b : %d \n", a % b);

    printf("\nLogiques : \n");

    printf("!a : %d \n", !a);
    printf("a && b : %d \n", a && b);
    printf("a || b : %d \n", a || b);

    
}

/*Algorithmes et C appliqués aux Systèmes Numériques | John Samuel 58 < | >
1.15. Les opérateurs logiques
int a = 20, b = 0;
Opérateur Objectif Exemple Résultat
! Négation !a 0
&& Et a && b 0
|| Ou a || b*/