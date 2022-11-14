#include <stdio.h>

int main() {
    unsigned int a;
    unsigned int b;
    printf("Nombre : ");
    scanf("%d",&a);
    printf("Puissance : ");
    scanf("%d",&b);
    
    unsigned int res=a;
    for (unsigned int i = 1 ; i<b;i++){
        res = res * a;
    }
    printf("Résulat de %d puissance %d : %d \n", a,b,res);

    return 0;
};