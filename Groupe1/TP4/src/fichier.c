#include <stdio.h>
#include "fichier.h"


int main(){

    lire_fichier("test.txt");
    ecrire_fichier("test2.txt", "ceci \nest un test\n");
    lire_fichier("test2.txt");
    return 0;
}