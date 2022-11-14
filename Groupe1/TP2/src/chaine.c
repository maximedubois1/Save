#include <stdio.h>

int cont(char text[]){
    int n =0;
    while (text[n]!= '\0'){
        n++;
    }
    return n;
}

int main() {
    char text1[50], text2[50], text3[50];

    printf("Text 1 : ");
    scanf("%s",text1);
    int n = cont(text1);

    printf("Taille Text 1 : %d \n", n);

    for(int i=0; i<n;i++){
        text2[i]= text1[i];
    }

    printf("Text 2 : %s \n", text2);


    printf("Text 3 : ");
    scanf("%s",text3);
    int n3 = cont(text3);

    int n4 = n + n3;
    
    char res[n4];
    int i=0;
    while(i<n){
        res[i]=text1[i];
        i++;
    }
    while(i<n4){
        res[i]=text3[i-n];
        i++;
    }
    printf("Text 3 : %s \n", res);
    return 0;
};