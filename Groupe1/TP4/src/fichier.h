#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int lire_fichier(char *nom_de_fichier){

    char content;
    int fd, size;

    fd = open(nom_de_fichier, O_RDONLY); //on ouvre le fichier en lecture seule
    while (1)
    {
    
        size = read(fd, &content, 1); //on lit caractère par caractère et on récupère dans size le nombre de charactère restant
        if(size<1){
            break; //si il reste moins de 1 caractère on arrete tout 
        }
        printf("%c", content); //on affiche le caractère
    }
    close(fd); //on ferme le fichier

    return 0;
}

int ecrire_fichier(char *nom_de_fichier, char *message, char option){
    int fd;
    if (option == 'A'){
        fd = open(nom_de_fichier,O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR); //on ouvre le fichier en écriture ou on le créer s'il existe pas 
    } else{
        fd = open(nom_de_fichier,O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR); //on ouvre le fichier en écriture ou on le créer s'il existe pas 
    }
    write(fd, message, strlen(message)); // on écrit dans le fichier
    close(fd);// on ferme le fichier
    return 0;
}