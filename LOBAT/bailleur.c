#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "lobat.h"

/*
    Dans cette page nous allons mettre toutes les fonctions et procedures de creation de bailleurs
*/

void ajouterBailleur(){

    BAILLEUR b;
    int j=0;
    incrementerBailleur(&j);
    char idBailleur[20],tel[10],CIN[14];
    puts("============================== CREATION BAILLEUR ==============================");
    do{
        fflush(stdin);
        printf("Nom : ");
        gets(b.nom);
        if(myStrlen(b.nom)>19 || verifLetter(b.nom)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(b.nom)>19 || verifLetter(b.nom)!=0);
    do{
        fflush(stdin);
        printf("Prenom : ");
        gets(b.prenom);
        if(myStrlen(b.prenom)>19 || verifLetter(b.prenom)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(b.prenom)>19 || verifLetter(b.prenom)!=0);
    do{
        fflush(stdin);
        printf("Pays : ");
        gets(b.adresse.pays);
        if(myStrlen(b.adresse.pays)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(b.adresse.pays)>19);
    do{
        fflush(stdin);
        printf("Region : ");
        gets(b.adresse.region);
        if(myStrlen(b.adresse.region)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(b.adresse.region)>19);
    do{
        fflush(stdin);
        printf("Departement : ");
        gets(b.adresse.departement);
        if(myStrlen(b.adresse.departement)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(b.adresse.departement)>19);
    do{
        fflush(stdin);
        printf("Commune : ");
        gets(b.adresse.commune);
        if(myStrlen(b.adresse.commune)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(b.adresse.commune)>19);
    sprintf(b.id,"B%c%c%c%c%d",myUpperCase(b.prenom[0]),myUpperCase(b.nom[0]),myUpperCase(b.nom[1]),(myStrlen(b.nom)>3)?myUpperCase(b.nom[2]):'@',j);
    printf("ID : %s\n",b.id);
    strcpy(idBailleur,b.id);
    do{
        fflush(stdin);
        printf("Tel : ");
        gets(b.tel);
        if(verifPhoneNumber(b.tel)!=0){
            puts("Numero de Telephone incorrecte");
        }
        strcpy(tel,b.tel);
    }while(verifPhoneNumber(b.tel)!=0 || verifUniciteTelBailleur(tel,idBailleur)==1);
    do{
        fflush(stdin);
        printf("CIN : ");
        gets(b.CIN);
        if(verifCIN(b.CIN)!=0){
            puts("CIN incorrecte");
        }
        strcpy(CIN,b.CIN);
    }while(verifCIN(b.CIN)!=0 || verifUniciteCINBailleur(CIN, b.id) == 1);

    FILE *file=fopen("bailleur.bin","ab");
    fwrite(&b,sizeof(BAILLEUR),1,file);
    fclose(file);
    puts("Bailleur ajouter avec succe!!!");
    Sleep(2000);
    system("cls");
    ajouterLocation2(idBailleur);

}


 //MENU BAILLEUREUR DEBUT

void afficherMenuBailleur() {
    FILE* file = fopen("bailleur.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    BAILLEUR b;
    int index = 1;

    printf("========== MENU ==========\n");
    printf("Liste des id des bailleurs :\n");

    while (fread(&b, sizeof(BAILLEUR), 1, file) == 1) {
        printf("%d. %s\n", index, b.id);
        index++;
    }

    printf("0. Accueil\n");
    printf("==========================\n");

    fclose(file);
}
//choixMenu
void faireChoixBailleur(char idSelectionne[]) {
    int choix;
    printf("Choisissez un Bailleur (0 pour quitter) : ");
    scanf("%d", &choix);

    if (choix != 0) {
        FILE* file = fopen("bailleur.bin", "rb");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return;
        }

        BAILLEUR b;
        int index = 1;

        while (fread(&b, sizeof(BAILLEUR), 1, file) == 1) {
            if (index == choix) {
                fclose(file);
                strcpy(idSelectionne, b.id);
                return;
            }
            index++;
        }

        fclose(file);

        printf("Choix invalide.\n");
    }else{
        Sleep(2000);
        system("cls");
        accueilAdministrateur();
    }
}
void afficherIdMenuModBailleur(char idSelectionne[]) {
    afficherMenuBailleur();
    faireChoixBailleur(idSelectionne);
    Sleep(2000);
    system("cls");
    modifierBailleur(idSelectionne);

}


//MODIFIER BAILLEUR DEBUT
 void modifierBailleur(char id[] ) {
    //char nom[20],prenom[20],password[65],tel[10],email[75],userType[15];

    FILE* file = fopen("bailleur.bin", "r+b");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    BAILLEUR b;
    char tel[10],CIN[14];

    int index = 1;


    while (fread(&b, sizeof(BAILLEUR), 1, file) == 1) {
        if (strcmp(b.id, id) == 0) {
            fseek(file, -sizeof(BAILLEUR), SEEK_CUR);
            do{
                fflush(stdin);
                printf("Nom : ");
                gets(b.nom);
                if(myStrlen(b.nom)>19 || verifLetter(b.nom)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(b.nom)>19 || verifLetter(b.nom)!=0);
            do{
                fflush(stdin);
                printf("Prenom : ");
                gets(b.prenom);
                if(myStrlen(b.prenom)>19 || verifLetter(b.prenom)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(b.prenom)>19 || verifLetter(b.prenom)!=0);
            do{
                fflush(stdin);
                printf("Pays : ");
                gets(b.adresse.pays);
                if(myStrlen(b.adresse.pays)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(b.adresse.pays)>19);
            do{
                fflush(stdin);
                printf("Region : ");
                gets(b.adresse.region);
                if(myStrlen(b.adresse.region)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(b.adresse.region)>19);
            do{
                fflush(stdin);
                printf("Departement : ");
                gets(b.adresse.departement);
                if(myStrlen(b.adresse.departement)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(b.adresse.departement)>19);
            do{
                fflush(stdin);
                printf("Commune : ");
                gets(b.adresse.commune);
                if(myStrlen(b.adresse.commune)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(b.adresse.commune)>19);
            do {
                fflush(stdin);
                printf("Tel : ");
                gets(b.tel);
                if (verifPhoneNumber(b.tel) != 0) {
                  puts("Numero de Telephone incorrecte");
                }
                strcpy(tel, b.tel);
            } while (verifPhoneNumber(b.tel) != 0 || verifUniciteTelBailleur(tel, id) == 1);

            do{
                fflush(stdin);
                printf("CIN : ");
                gets(b.CIN);
                if(verifCIN(b.CIN)!=0){
                    puts("CIN incorrecte");
                }
                strcpy(CIN,b.CIN);
            }while(verifCIN(b.CIN)!=0 || verifUniciteCINBailleur(CIN, id) == 1);
            fseek(file, 0, SEEK_CUR);
            fwrite(&b, sizeof(BAILLEUR), 1, file);
            fclose(file);
            printf("Bailleur modifie avec succes.\n");
            return;
        }


        index++;
    }


    fclose(file);
}
 //MODIFIER bailleur FIN

int verifUniciteTelBailleur(char tel[], char id[]) {
  BAILLEUR b;
  FILE *file = fopen("bailleur.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&b, sizeof(BAILLEUR), 1, file) == 1) {
    if (strcmp(b.tel, tel) == 0 && strcmp(b.id, id) != 0) {
      fclose(file);
      printf("Ce numero existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}
 int verifUniciteCINBailleur(char CIN[], char id[]) {
  BAILLEUR b;
  FILE *file = fopen("bailleur.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&b, sizeof(BAILLEUR), 1, file) == 1) {
    if (strcmp(b.CIN, CIN) == 0 && strcmp(b.id, id) != 0) {
      fclose(file);
      printf("Ce CIN existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}
