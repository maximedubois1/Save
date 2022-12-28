#include <stdio.h>


int octet(char * nomvar, char * ptr, int oct){
    printf("size of %i \n",oct);

    for (int i=0; i<oct; i++){

        printf("Variable %s Octet n° %i : %hhx \n",nomvar, i, *(ptr+i));

    }
    return 0;
}

int main(){

    short vshort = 0x2e;
    int vint = 0x2e45;
    long int vlint = 678L;
    float vfloat = 3.15;
    double vdouble = 456.132;
    long double vldouble = 4567.45L;
    char cha = 'a';

    octet("char",(void *)&cha,sizeof(cha));
    octet("short",(void *)&vshort,sizeof(vshort));
    octet("int",(void *)&vint,sizeof(vint));
    octet("long int",(void *)&vlint,sizeof(vlint));
    octet("float",(void *)&vfloat,sizeof(vfloat));
    octet("double",(void *)&vdouble,sizeof(vdouble));
    octet("longue double",(void *)&vldouble,sizeof(vldouble));


    return 0;
}