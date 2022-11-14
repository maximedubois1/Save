#include <stdio.h>

int main() {
    int nbr = 78;
    int i;

    int res[4*8];

    if(nbr == 0){
        printf("0\n");
        return 0;

    }

    for (i=0;nbr > 0;i++){
        res[i]=nbr%2;
        nbr=nbr/2;
    }

    for (i=i-1;i>=0;i--){
        printf("%d ",res[i]);
    }

    //printf("%d",res);
    printf("\n");
    return 0;
}
