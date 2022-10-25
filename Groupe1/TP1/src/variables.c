#include <stdio.h>

int main() {
    
   signed char vschar = 'a';
   unsigned char vuchar = 234;
   signed short vsshort = -12;
   unsigned short vushort = 65535;
    signed int vsint = -2147483648;
    unsigned int vuint = 4294967295;
    signed long int vslint = -922337203685477508L;
    unsigned long int vulint = 1844674407370955615UL;
    signed long long int vsllint = -9223372036854758080LL;
    unsigned long long int vullint = 184467403705516150ULL;
    float vfloat = 3.14;
    double vdouble = 1.7E308;
    long double vldouble = 3.4E38;

    printf("signed char : %c \n", vschar);
    printf("unsigned char : %hhu \n", vuchar);
    printf("signed short : %hd \n", vsshort);
    printf("unsigned short : %hu \n", vushort);
    printf("signed int : %d \n", vsint);
    printf("unsigned int : %u \n", vuint);
    printf("signed longint : %ld \n", vslint);
    printf("unsigned longint : %lu \n", vulint);
    printf("signed long long int : %lld \n", vsllint);
    printf("unsigned long long int : %llu \n", vullint);
    printf("float : %f \n", vfloat);
    printf("double : %g \n", vdouble);
    printf("long double : %Lg \n", vldouble);
    return 0;
};