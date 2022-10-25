#include <stdio.h>

int main() {
    /*signed short, signed int, signed long, signed
    long long, unsigned short, unsigned int,
    unsigned long, unsigned long long
    */
    printf("signed char : %ld octets \n", sizeof(signed char));
    printf("unsigned char : %ld octets \n", sizeof(unsigned char));
    printf("signed short : %ld octets \n", sizeof(signed short));
    printf("unsigned short : %ld octets \n", sizeof(unsigned short));
    printf("signed int : %ld octets \n", sizeof(signed int));
    printf("unsigned int : %ld octets \n", sizeof(unsigned int));
    printf("signed longint : %ld octets \n", sizeof(signed long int));
    printf("unsigned longint : %ld octets \n", sizeof(unsigned long int));
    printf("signed long long int : %ld octets \n", sizeof(signed long long int));
    printf("unsigned long long int : %ld octets \n", sizeof(unsigned long long int));
    printf("float : %ld octets \n", sizeof(float));
    printf("double : %ld octets \n", sizeof(double));
    printf("long double : %ld octets \n", sizeof(long double));
    return 0;
};