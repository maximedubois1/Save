#include <stdio.h>

int main() {
    for (int i=0; i<=1000;i++){
        if (i%2==0 && i%15==0){
            printf("Divisible par 2 et 15 :%d\n", i);
            continue;
        }
        if (i%103==0 || i%107==0){
            printf("Divisible par 103 ou 107 :%d\n", i);
            continue;
        }
        if (i%7==0 || i%5==0){
            if (i%3!=0)
            {
                printf("Divisible par 7 ou 5 mais pas par 3 :%d\n", i);
                continue;
            }
        }
    }
    return 0;
}