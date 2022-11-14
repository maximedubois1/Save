#include <stdio.h>
#include <stdlib.h>

int main(){
    int tab[20];
    float tab2[20];

    for (int i=0; i<20 ; i++){
        *(tab+i)= rand() % 100;
        *(tab2+i) = (float)rand()/((float)RAND_MAX/100);

        printf("tab int %i \n", *(tab+i));
        printf("tab float %f \n", *(tab2+i));
    }

    for (int i=0; i<20; i++){
        if (i%2 == 0){
            printf("tab int %i \n", *(tab+i));
            *(tab+i) *= 3;
            printf("tab int * 3 %i \n", *(tab+i));
            printf("tab float %f \n", *(tab2+i));
            *(tab2+i) *= 3;
            printf("tab float *3 %f \n", *(tab2+i));
        }
    }
    


}