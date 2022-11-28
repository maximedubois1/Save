#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//fontion de tris à bulle
int tri(int *tab, int len_tab){
    int n=1;
    int tmp=0;
    //tant qu'on fait des changement 
    while (n != 0){
        n=0;
        for (int i=0; i<len_tab; i++){ //pour chaque valeur du tableau
            if (*(tab+i) > *(tab+i+1)){ // si la valeur est supérieur à la valeur suivante
                //on inverse les 2 valeurs
                tmp = *(tab+i);
                *(tab+i) = *(tab+i+1);
                *(tab+i+1) = tmp;
                n=1; //on note qu'on à fait un changement 
            }
        }
    }
    return 0;
}


int main (){
    int len_tab = 100;
    int tab[len_tab];

    //srand( time( NULL ) );
    //Génération d'une liste de 100 entier
    for (int i=0; i<=len_tab; i++){
        *(tab+i) = rand() % 1000;
    }
    
    //on trie la liste 
    tri(tab, len_tab);
    

    int ent = 980; //l'entier à tester
    int n=0;
    //on affiche la liste trié
    printf("---------------------liste trié \n");
    for (int i=0; i<len_tab; i++){
        printf("tab %d\n", *(tab+i));
    }
    printf("---------------------Réponse\n");
    int imoit = len_tab/2;
    int imax = 100;
    int imin= 0;
    int count = 0;
    // on test au maximum 50 fois
    while (count <50){
        count++;
        if (*(tab+imoit) == ent){   //si on trouve l'entier au change n et on s'arrete
            n=1;
            printf("l'entier %d est présent\n", ent);
            return 0;
        }else if (*(tab+imoit) > ent)     //si la valeur fait partie de la partie haute de la liste
        {
            imoit = (imax + imin )/ 2; //on récupère l'index du milieu de la partie supérieur 
            if (*(tab+imoit) < ent){    //on rédéfinit les index max et min 
                imin = imoit;
            }else{
                imax = imoit;
            }
            
        } else if (*(tab+imoit) < ent)  //si la valeur fait partie de la partie basse de la liste
        {
            imoit = (imax + imin )/ 2; //on récupère l'index du milieu de la partie inférieur 

            if (*(tab+imoit) < ent){  //on rédéfinit les index max et min 
                imin = imoit;
            }else{
                imax = imoit;
            }
            
        }         
    }

    printf("l'entier %d est absent\n", ent);
    

    return 0;
}