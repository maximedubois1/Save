#include <stdio.h>

int main(){
    printf("sizeof %lu\n", sizeof (int));
    printf("sizeof %lu\n", sizeof (int *));
    printf("sizeof %lu\n", sizeof (int **));
    printf("sizeof %lu\n", sizeof (char *));
    printf("sizeof %lu\n", sizeof (char **));
    printf("sizeof %lu\n", sizeof (char ***));
    printf("sizeof %lu\n", sizeof (float *));
    printf("sizeof %lu\n", sizeof (float **));
    printf("sizeof %lu\n", sizeof (float ***));

    return 0;
}