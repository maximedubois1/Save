#include <stdio.h>

int main(){
    int compteur = 15;

    for (int i = 0; i <= compteur; i++)
    {
        for (int y = 0; y<i; y++)
        {
            //printf("%d", y);
            if (y<i-1 && y!=0 && i!=compteur){
                printf("#");
            }else {
                printf("*");
            }
        }
        printf("\n");
    }

        int i =0;
    while(i <= compteur)
    {
        
        int y=0;
        while ( y<i)
        {
            
            if (y<i-1 && y!=0 && i!=compteur){
                printf("#");
            }else {
                printf("*");
            }
            y++;
        }
        printf("\n");
        i++;
    }

    return 0;   
    
}