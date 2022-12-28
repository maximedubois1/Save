#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "repertoire.h"

void lire_dossier(char *rep){
    struct dirent *pDirent; //on créer une strucure de type dirent
    DIR *dir = opendir(rep); //ouverture du dossier à l'aide de la fonction opendir

    if (dir == NULL) {
        printf ("'%s' n'est pas un répertoire\n", rep);
    } else {
        while ((pDirent = readdir(dir)) != NULL) { //tant qu'on a pas atteint la fin du dossier
            printf ("%s\n", pDirent->d_name);
        }
    }
    closedir(dir); //fermeture du fichier

}


void lire_dossier_recursif(char * rep){
    struct dirent *pDirent;//on créer une strucure de type dirent
    DIR *dir = opendir(rep);//ouverture du dossier à l'aide de la fonction opendir

    if (dir == NULL) {
        printf ("'%s' n'est pas un répertoire\n", rep);
    } else {
        //tant qu'on trouve des éléments dans le répertoire
        while ((pDirent = readdir(dir)) != NULL) {
            //on oublie "." et ".."
            if (strcmp(pDirent->d_name,".") == 0 || strcmp(pDirent->d_name,"..") == 0){
                continue;
            }
                if (pDirent->d_type == DT_DIR) { //si c'est un répertoire
                    char path[1024];
                    snprintf(path, sizeof(path), "%s/%s", rep, pDirent->d_name); //on rajoute ce repertoire a path
                    printf ("%s\n", path);

                    lire_dossier_recursif(path); //on rappel la fonction avec le nouveau path
                } else{
                    printf("%s\n",pDirent->d_name);
                }
        }
    }
    closedir(dir); //fermeture du fichier
}

struct directory { //on créer une list chainer de repertoire
    char path[1024];
    struct directory *next;
};

void lire_dossier_iteratif(char *rep){
    struct dirent *pDirent;
    DIR *dir = opendir(rep);

    if (dir == NULL) {
        printf("'%s' n'est pas un répertoire\n", rep);
        return;
    }

    // Création d'une pile pour stocker les répertoires à parcourir
    struct directory *directories = NULL;
    struct directory *current_dir = malloc(sizeof(struct directory));
    strcpy(current_dir->path, rep);
    current_dir->next = NULL;
    directories = current_dir;

    while (directories != NULL) {
        // Récupération du répertoire courant à partir de la pile
        current_dir = directories;
        directories = current_dir->next;

        // Ouverture du répertoire courant
        dir = opendir(current_dir->path);

        // Parcours du répertoire courant
        while ((pDirent = readdir(dir)) != NULL) {
            // On oublie "." et ".."
            if (strcmp(pDirent->d_name,".") == 0 || strcmp(pDirent->d_name,"..") == 0) {
                continue;
            }

            // Si c'est un répertoire, on le stocke dans la pile pour le parcourir plus tard
            if (pDirent->d_type == DT_DIR) {
                char path[1024];
                strncpy(path, pDirent->d_name, sizeof(path));
                struct directory *new_dir = malloc(sizeof(struct directory));
                strcpy(new_dir->path, path);
                new_dir->next = directories;
                directories = new_dir;
                printf("%s\n", path);
            } else {
                // Sinon, c'est un fichier, on l'affiche
                printf("%s\n", pDirent->d_name);
            }
        }

        // Fermeture du répertoire courant
        closedir(dir);

        // Libération de la mémoire allouée pour le répertoire courant
        free(current_dir);
    }
}



int main(){

    lire_dossier_iteratif("..");
    
    return 0;
}