#include <stdio.h>

int main() {
    
    char vchar;
    short vshort;
    int vint;
    long int vlint;
    long long int vllint;
    float vfloat;
    double vdouble;
    long double vldouble;

    char *a = &vchar;
    short *b = &vshort;
    int *c = &vint;
    long int *d = &vlint;
    long long int *e = &vllint;
    float *f = &vfloat;
    double *g = &vdouble;
    long double *h = &vldouble;

    *a = 'v';
    *b = 12;
    *c = 45;
    *d = 456;
    *e = 2001;
    *f = 3.14;
    *g = 5.15;
    *h = 1.456;

    printf("Char valeur %c / address : %p\n", vchar,&vchar);
    printf("short valeur %d / address : %p\n", vshort,&vshort);
    printf("int valeur %d / address : %p\n", vint,&vint);
    printf("long int valeur %ld / address : %p\n", vlint,&vlint);
    printf("long long int valeur %lld / address : %p\n", vllint,&vllint);
    printf("float valeur %f / address : %p\n", vfloat,&vfloat);
    printf("double valeur %f / address : %p\n", vdouble,&vdouble);
    printf("long double valeur %Lg / address : %p\n", vldouble,&vldouble);

    return 0;
};