#include <stdio.h>
#include "repertoire.h"
#include <dirent.h>
#include <string.h>

void lire_dossier(char *rep){
    struct dirent *pDirent;
    DIR *dir = opendir(rep);

    if (dir == NULL) {
        printf ("'%s' n'est pas un répertoire\n", rep);
    } else {
        while ((pDirent = readdir(dir)) != NULL) {
            printf ("%s\n", pDirent->d_name);
        }
    }
    closedir(dir);

}


void lire_dossier_recursif(char * rep){
    struct dirent *pDirent;
    DIR *dir = opendir(rep);

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
                    snprintf(path, sizeof(path), "%s/%s", rep, pDirent->d_name);
                    printf ("%s\n", path);

                    lire_dossier_recursif(path);
                } else{
                    printf("%s\n",pDirent->d_name);
                }
        }
    }
    closedir(dir);
}


void lire_dossier_iteratif(char *rep){
    lire_dossier_recursif (rep);
}



int main(){

    lire_dossier_iteratif("..");
    
    return 0;
}