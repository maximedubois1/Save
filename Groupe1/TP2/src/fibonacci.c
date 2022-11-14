#include <stdio.h>

int main() {
    int U0= 0;
    int U1= 1;
    int res;
    int n;
    printf("Choisir votre n eime termes : ");
    scanf("%d",&n);
    printf("U0 = %d \n",U0);
    printf("U1 = %d \n",U1);

    for(int i=2;i<=n;i++){
        res = U1 + U0;
        U0 = U1;
        U1 = res;
        printf("U%d = %d \n",i,res);
    }


    return 0;
};