/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "fichier.h"
#include "client.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd)
{

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caracteres): ('calcule:' pour faire une opération) ");
  fgets(message, sizeof(message), stdin);

  char code[10];

  sscanf(message, "%s:", code); //on récupere le code message ou calcule

  if(strcmp(code, "calcule") != 0){ //si il n'y a pas calcule au début 
    strcpy(data, "message: "); //on rajoute message:
  } 
  
  strcat(data, message);

  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);

  return 0;
}

float envoie_operateur_numeros(int socketfd, char op, int num1, int num2){
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  
  char num1_chaine[20];
  char num2_chaine[20];
  
//on converti les 2 int en chaine de caractère
  sprintf(num1_chaine, "%i", num1);
  sprintf(num2_chaine, "%i", num2);


  sprintf(data,"%c", op); // on met l'opérateur de data
  strcat(data, " ");//on rajoute l'espace
  strcat(data, num1_chaine); //on rajoute le numéro1
  strcat(data, " ");//on rajoute l'espace
  strcat(data, num2_chaine);//on rajoute le numéro2

  //On rajoute la chaine "calcule : " début de data
  char msg[] = "calcule : ";
  memmove(data + strlen(msg), data, strlen(data) + 1); // on déplace la data à la fin de la msg
  memcpy(data, msg, strlen(msg)); // on copie la msg au début de data
  
  
  // printf("data %s\n",data);

  int write_status = write(socketfd, data, strlen(data)); // on envoie le msg au serveur

  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("erreur lecture");
    return -1;
  }

   // printf("Message recu: %s\n", data);

  return atof(data); //on transforme le retour en float 
}

int start_connection(int socketfd, struct sockaddr_in server_addr) //fonction pour gérer la connection
{
  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }
  return socketfd;
}

int main()
{
  int socketfd = 0;

  struct sockaddr_in server_addr;

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  socketfd = start_connection(socketfd, server_addr);
  
  // appeler la fonction pour envoyer un message au serveur
 
  // envoie_recois_message(socketfd);
  
  
  char fichier[100];
  char temp[200];
  int somme = 0;
  float moy = 0;
  
  for (int etu=1; etu<=5; etu++) //pour chaque étudiant 
  {
    printf("--------Etudiant : %i\n", etu);
    for(int note=1; note<=5; note++) //pour chaque note de l'étudiant
    {
      //on génère le chemin d'accès à la note concerné
      strcpy(fichier, "../etudiant/");
      snprintf(temp, 150, "%s%d", fichier, etu);
      strcpy(fichier, temp);
      strcat(fichier, "/note");
      snprintf(temp, 150, "%s%d", fichier, note);
      strcpy(fichier, temp);
      strcat(fichier, ".txt");

      //on lit la note
      int num = lire_fichier(fichier);
      printf("Note : %i\n", num);
      somme = envoie_operateur_numeros(socketfd,'+',somme,num); //on l'ajoute par le serveur à somme

      close(socketfd); //on ferme la connection

      socketfd = start_connection(socketfd, server_addr); //on reouvre une connection
    }
    //affichage des résultats
    printf("Somme : %i\n", somme); 
    moy = envoie_operateur_numeros(socketfd,'/',somme,5); //on demande la moyenne au serveur
    printf("Moyenne : %f\n", moy);
    //on rénitialise somme
    somme = 0;
  }
}