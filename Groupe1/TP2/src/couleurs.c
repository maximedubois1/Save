#include <stdio.h>

int main(){
    struct color{
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned char A;

    };
    struct color color[10];
    color[0].R=0x12;
    color[0].G=0x57;
    color[0].B=0x25;
    color[0].A=0x01;

    color[1].R=0x15;
    color[1].G=0x78;
    color[1].B=0x95;
    color[1].A=0x12;

    color[2].R=0x45;
    color[2].G=0x57;
    color[2].B=0x65;
    color[2].A=0x87;

    color[3].R=0x12;
    color[3].G=0x35;
    color[3].B=0x28;
    color[3].A=0x91;

    color[4].R=0x54;
    color[4].G=0x15;
    color[4].B=0x14;
    color[4].A=0x86;

    color[5].R=0x25;
    color[5].G=0x75;
    color[5].B=0x19;
    color[5].A=0x37;

    color[6].R=0x12;
    color[6].G=0x57;
    color[6].B=0x25;
    color[6].A=0x01;

    color[7].R=0x15;
    color[7].G=0x78;
    color[7].B=0x95;
    color[7].A=0x12;

    color[8].R=0x45;
    color[8].G=0x57;
    color[8].B=0x65;
    color[8].A=0x87;

    color[9].R=0x12;
    color[9].G=0x35;
    color[9].B=0x28;
    color[9].A=0x00;

    for (int i=0; i<10 ; i++){
        printf("----- Couleur %d ------- \n",i);
        printf("R: %d\nG: %d\nB: %d\nA: %d\n\n", color[i].R, color[i].G, color[i].B, color[i].A );
    }
    return 0;
}