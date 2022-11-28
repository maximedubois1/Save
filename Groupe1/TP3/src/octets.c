#include <stdio.h>

int main(){

    short vshort = 45;
    int vint = 65534;
    long int vlint = 678L;
    float vfloat = 3.15;
    double vdouble = 456.132;
    long double vldouble = 4567.45L;
    char cha = "a";

    printf("short : %x \n", *((char *)&vshort));
    printf("int : %x\n", *((char *)&vint));
    printf("long int : %x\n", *((char *)&vlint));
    printf("double : %x\n", *((char *)&vdouble));
    printf("longue double : %x\n", *((char *)&vldouble));
    printf("char : %x \n", *((char *)&cha));



    return 0;
}