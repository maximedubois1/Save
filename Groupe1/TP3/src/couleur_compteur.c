#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    srand( time( NULL ) );
    //On définit le nombre de couleurs
    int nbr_color = 100;
    //On définit la strucuture d'une couleur
    struct Color{
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned char A;

    };
    struct Color color[nbr_color]; //Création d'un tableau de couleurs vide
    
    //définition d'une strucuture d'une couleurs avec un compteur de doublons
    struct Colorcount{
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned char A;
        unsigned int count;
    };

    struct Colorcount colorcount[nbr_color]; //Création d'un tableau de couleurs vide
    //Génération de couleurs aléatoire
    for(int i=0; i<nbr_color; i++){
        color[i].R=rand()%255+1;
        color[i].G=rand()%255+1;
        color[i].B=rand()%255+1;
        color[i].A=rand()%255+1;
    }
    
/*  Génération de couleurs fix pour les tests
   color[1].R=0x12;
    color[1].G=0x57;
    color[1].B=0x25;
    color[1].A=0x01;

    color[0].R=0x15;
    color[0].G=0x78;
    color[0].B=0x95;
    color[0].A=0x12;

    color[2].R=0x12;
    color[2].G=0x57;
    color[2].B=0x25;
    color[2].A=0x01;

    color[3].R=0x12;
    color[3].G=0x57;
    color[3].B=0x25;
    color[3].A=0x01;

    color[4].R=0x16;
    color[4].G=0x78;
    color[4].B=0x95;
    color[4].A=0x12;
    */
    int doublons = 0;
    int nbrnondoublons=0;
    //pour chaque couleur 
    for (int i=0; i<nbr_color ; i++){
        //Pour chaque couleur déjà testé
        for (int y=0; y<nbr_color;y++){ 
            //si la couleurs est déjà testé
            if (color[i].R == colorcount[y].R &&
                color[i].G == colorcount[y].G &&
                color[i].B == colorcount[y].B &&
                color[i].A == colorcount[y].A ) {
                printf("----- Couleur doublons %d avec %d------- \n",i, y);
                printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", color[i].R, color[i].G, color[i].B, color[i].A );
                printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", colorcount[y].R, colorcount[y].G, colorcount[y].B, colorcount[y].A );
                doublons = y+1; // on récupère l'index de la couleurs déjà testé +1 (Pour éviter de créer une 2eme variable de test)
            }
        }
        //si aucun doublons est détecté
        if (doublons == 0){
            //on l'ajoute au valeur testé
            colorcount[nbrnondoublons].R = color[i].R;
            colorcount[nbrnondoublons].G = color[i].G;
            colorcount[nbrnondoublons].B = color[i].B;
            colorcount[nbrnondoublons].A = color[i].A;
            colorcount[nbrnondoublons].count = 1;
            //on incrément le nombre de non doublons
            nbrnondoublons++;
        }else{
        //si c'est un doublons on ajoute 1 à son compteur 
        colorcount[doublons-1].count ++;
        doublons = 0;
        }
    }

    //on affiche le tableau de base
    printf("----- Tableau de couleurs de base ------- \n");

    for (int i=0; i<nbr_color ; i++){
        printf("----- Couleur %d ------- \n",i);
        printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", color[i].R, color[i].G, color[i].B, color[i].A );
    }
    //Affichage le tableau avec les compteur 
    printf("----- Couleur count ------- \n");

    for (int i=0; i<nbrnondoublons ; i++){
        printf("----- Couleur count %d apparait %d fois------- \n",i, colorcount[i].count);
        printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", colorcount[i].R, colorcount[i].G, colorcount[i].B, colorcount[i].A );
    }
    //Affichage des couleurs en doublons
    printf("----- Couleur en doublons  ------- \n");

    for (int i=0; i<nbrnondoublons ; i++){
        if (colorcount[i].count > 1){
            printf("----- Couleur count %d apparait %d fois------- \n",i, colorcount[i].count);
            printf("R: 0x%02hhX\nG: 0x%02hhX\nB: 0x%02hhX\nA: 0x%02hhX\n\n", colorcount[i].R, colorcount[i].G, colorcount[i].B, colorcount[i].A );
        }
    }

    printf("----- Nombre de valeur unique %d ------- \n", nbrnondoublons);
    printf("----- Nombre de doublons %d ------- \n", nbr_color - nbrnondoublons);

    
    return 0;
}