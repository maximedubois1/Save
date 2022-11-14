#include <stdio.h>

int main() {
    while(0==0){
        int d;
        
        printf("Nombre : ");
        scanf("%d",&d);

        //int mask = 0b00010000000000000001000000000000;
        int maskf = 0b00000000000000000001000000000000;
        //int maskf = 0b00000000000000000000000000001000;
        //int maskv = 0b00000000000000000000000000000010;
        int maskv = 0b00010000000000000000000000000000;
        
        if((d & maskf) && (d & maskv)){
            printf("1");
        }else{
            printf("0");
        }
        printf("\n");
    };

    return 0;
};