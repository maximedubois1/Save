#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int lire_fichier(char *nom_de_fichier){

    char content;
    int fd, size;
    char note[2]  ;
    fd = open(nom_de_fichier, O_RDONLY); //on ouvre le fichier en lecture seule
    while (1)
    {
    
        size = read(fd, &content, 1); //on lit caractère par caractère et on récupère dans size le nombre de charactère restant
        if(size<1){
            break; //si il reste moins de 1 caractère on arrete tout 
        }
        printf("%c", content); //on affiche le caractère
        strcpy(note,content);
    }
    close(fd); //on ferme le fichier
    
    printf("re%c", note); //on affiche le caractère


    return 0;
}
