#include <stdio.h>



int factorielle (int num) { //on créer la fonction récurcive factoriel
  if (num == 0) {
    return 1;
  }
  else {
    return (num * factorielle (num-1));
  }
}


int main(){

    //on l'appèle avec différente valeurs
    printf("%i \n",factorielle(1));
    printf("%i \n",factorielle(9));
    printf("%i \n",factorielle(2));
    printf("%i \n",factorielle(4));
    printf("%i \n",factorielle(0));

    return 0;
}