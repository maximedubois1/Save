#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int recherche_fichier(char *nom_de_fichier, char *chaine){

    char content;
    int fd, size;
    int numligne=1;
    int count=0;
    int i=0;

    fd = open(nom_de_fichier, O_RDONLY); //on ouvre le fichier en lecture seule
    while (1)
    {
        size = read(fd, &content, 1); //on lit caractère par caractère et on récupère dans size le nombre de charactère restant
        if(size<1){
            break; //si il reste moins de 1 caractère on arrete tout 
        }
       // printf("%c", content); //on affiche le caractère
    
        if (content == chaine[i]) //si le caractère correspond au caracrtère de ma chaine 
        {
            i++; //on passe au caracère suivant
            if (i == (int)strlen(chaine)){ //si ma chaine a été complété
                count++; //on compte l'occurance
            }
        } else{
            i=0; // si le caractère ne correspond pas 

        }
        
        if(content == '\n'){ //si on trouve un retour à la ligne
            if (count > 0 ) printf("Ligne %i, %i fois\n", numligne, count); //si on a trouver une fois la chaine on affiche le numéro de la ligne et combien de fois on la trouvé
            count=0;
            numligne ++;
        }
    }
    close(fd); //on ferme le fichier

    return numligne;
}



int main (int argc, char** argv){
    
    if (argc < 3) //si il n'y as pas les 2 arguments
    {
        printf("Erreur veulliez entrer 2 argument");
        return 1;
    }
    
    char * chaine = argv[1];
    char * fichier = argv[2];
    recherche_fichier(fichier,chaine);


    return 0;
}