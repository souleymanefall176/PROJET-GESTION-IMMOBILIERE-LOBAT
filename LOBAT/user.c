#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lobat.h"


void inscription(){
    USER user;
    FILE *file = NULL;
    int i=0;
    char tel[10],mail[75];
    incrementerUser(&i);
    puts("============================== INSCRIPTION ==============================");
    do{
        fflush(stdin);
        printf("Nom : ");
        gets(user.nom);
        if(myStrlen(user.nom)>19 || verifLetter(user.nom)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(user.nom)>19 || verifLetter(user.nom)!=0);
    do{
        fflush(stdin);
        printf("Prenom : ");
        gets(user.prenom);
        if(myStrlen(user.prenom)>19 || verifLetter(user.prenom)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(user.prenom)>19 || verifLetter(user.prenom)!=0);
    sprintf(user.id,"U%c%c%c%c%d",myUpperCase(user.prenom[0]),myUpperCase(user.nom[0]),myUpperCase(user.nom[1]),(myStrlen(user.nom)>3)?myUpperCase(user.nom[2]):'@',i);
    do{
        fflush(stdin);
        printf("Password : ");
        gets(user.password);//à hacher

    }while(verifierMotDePasse(user.password)!=0);
    do{
        fflush(stdin);
        printf("Tel : ");
        gets(user.tel);
        if(verifPhoneNumber(user.tel)!=0){
            puts("Numero de Telephone incorrecte");
        }
        strcpy(tel, user.tel);
    }while(verifPhoneNumber(user.tel)!=0 || verifUniciteTelUser(tel,user.id)==1);
    do{
        fflush(stdin);
        printf("Email : ");
        gets(user.email);
        if(verifMail(user.email)!=0){
            puts("Adresse Mail incorrecte");
        }
        strcpy(mail,user.email);
    }while(verifMail(user.email)!=0 || verifUniciteMailUser(mail,user.email)==1);
    if(verifFile(file)==1){
        strcpy(user.typeUser,"administrateur");
    }else{
        do{
            fflush(stdin);
            printf("Type d'utilisateur : ");
            gets(user.typeUser);
            if(strcasecmp(user.typeUser,"administrateur")!=0 && strcasecmp(user.typeUser,"gestionnaire")!=0){
                printf("Utilisateur indisponible(administrateur/gestionnaire)");
            }

        }while(strcasecmp(user.typeUser,"administrateur")!=0 && strcasecmp(user.typeUser,"gestionnaire")!=0);
    }
    sprintf(user.login,"%c%s%s%d",(strcasecmp(user.typeUser,"administrateur")==0)?'A':'G',strupr(user.prenom),strupr(user.nom),i);
    printf("Login : %s\n",user.login);


    file=fopen("user.bin","ab");
    fwrite(&user,sizeof(USER),1,file);
    fclose(file);
    puts("Compte cree avec succe!!!");
    Sleep(4000);
    system("cls");

}



void afficherMenuLoginUser() {
    FILE* file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    USER user;
    int index = 1;

    printf("========== MENU ==========\n");
    printf("Liste des logins d'utilisateurs :\n");

    while (fread(&user, sizeof(USER), 1, file) == 1) {
        printf("%d. %s\n", index, user.login);
        index++;
    }

    printf("0. Accueil\n");
    printf("==========================\n");

    fclose(file);
}
//choixMenu
void faireChoixUtilisateur(char loginSelectionne[]) {
    int choix;
    printf("Choisissez un utilisateur (0 pour quitter) : ");
    scanf("%d", &choix);

    if (choix != 0) {
        FILE* file = fopen("user.bin", "rb");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return;
        }

        USER user;
        int index = 1;

        while (fread(&user, sizeof(USER), 1, file) == 1) {
            if (index == choix) {
                fclose(file);
                strcpy(loginSelectionne, user.login);
                return;
            }
            index++;
        }

        fclose(file);

        printf("Choix invalide.\n");
    }else{
        accueilAdministrateur();
    }
}
 //MODIFIER UTILISATEUR DEBUT
 void modifierUtilisateur(char login[] ) {
    //char nom[20],prenom[20],password[65],tel[10],email[75],userType[15];
    int i=0;
    incrementerUser(&i);
    char tel[10],mail[75];
    FILE* file = fopen("user.bin", "r+b");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    USER user;
    int index = 1;

    while (fread(&user, sizeof(USER), 1, file) == 1) {
        if (strcmp(user.login, login) == 0) {
            fseek(file, -sizeof(USER), SEEK_CUR);
            do{
                fflush(stdin);
                printf("Nouveau nom : ");
                gets(user.nom);
                if(myStrlen(user.nom)>19 || verifLetter(user.nom)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(user.prenom)>19 || verifLetter(user.prenom)!=0);
            do{
                fflush(stdin);
                printf("Nouveau Prenom : ");
                gets(user.prenom);
                if(myStrlen(user.prenom)>19 || verifLetter(user.prenom)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(user.prenom)>19 || verifLetter(user.prenom)!=0);

            do{
                fflush(stdin);
                printf("Password : ");
                gets(user.password);//à hacher

            }while(verifierMotDePasse(user.password)!=0);
            do{
                fflush(stdin);
                printf("Tel : ");
                gets(user.tel);
                if(verifPhoneNumber(user.tel)!=0){
                    puts("Numero de Telephone incorrecte");
                }
                strcpy(tel, user.tel);
            }while(verifPhoneNumber(user.tel)!=0 || verifUniciteTelUser(tel,user.id)==1);
            do{
                fflush(stdin);
                printf("Email : ");
                gets(user.email);
                if(verifMail(user.email)!=0){
                    puts("Adresse Mail incorrecte");
                }
                strcpy(mail,user.email);
            }while(verifMail(user.email)!=0 || verifUniciteMailUser(mail,user.email)==1);
            do{
                fflush(stdin);
                printf("Type d'utilisateur : ");
                gets(user.typeUser);
                if(strcasecmp(user.typeUser,"administrateur")!=0 && strcasecmp(user.typeUser,"gestionnaire")!=0){
                    printf("Utilisateur indisponible(administrateur/gestionnaire)");
                }

            }while(strcasecmp(user.typeUser,"administrateur")!=0 && strcasecmp(user.typeUser,"gestionnaire")!=0);
            sprintf(user.login,"%c%s%s%d",(strcasecmp(user.typeUser,"administrateur")==0)?'A':'G',strupr(user.prenom),strupr(user.nom),i);
            printf("Login : %s\n",user.login);
            fseek(file, 0, SEEK_CUR);
            fwrite(&user, sizeof(USER), 1, file);
            fclose(file);
            printf("Utilisateur modifie avec succes.\n");
            return;
        }


        index++;
    }

    fclose(file);
}
 //MODIFIER UTILISATEUR FIN

 //SUPPRIMER UTILISATEUR DEBUT

 void supprimerUtilisateur(char login[]) {
    FILE* file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    FILE* tempFile = fopen("temp.bin", "wb");
    if (tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        fclose(file);
        return;
    }

    USER user;

    while (fread(&user, sizeof(USER), 1, file) == 1) {
        if (strcmp(user.login, login) != 0) {
            fwrite(&user, sizeof(USER), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (remove("user.bin") != 0) {
        printf("Erreur lors de la suppression du fichier.\n");
        return;
    }

    if (rename("temp.bin", "user.bin") != 0) {
        printf("Erreur lors du renommage du fichier temporaire.\n");
        return;
    }

    printf("L'utilisateur avec le login '%s' a ete supprime.\n", login);
}

 //SUPPRIMER UTILISATEUR FIN

//afficher Menu
void afficherLoginsMenuSuprUser(char loginSelectionne[]) {
    afficherMenuLoginUser();
    faireChoixUtilisateur(loginSelectionne);
    supprimerUtilisateur(loginSelectionne);
    Sleep(2000);
    system("cls");
}
void afficherLoginsMenuModUser(char loginSelectionne[]) {
    afficherMenuLoginUser();
    faireChoixUtilisateur(loginSelectionne);
    Sleep(2000);
    system("cls");
    modifierUtilisateur(loginSelectionne);

}

int verifUniciteTelUser(char tel[], char id[]) {
  USER u;
  FILE *file = fopen("user.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&u, sizeof(USER), 1, file) == 1) {
    if (strcmp(u.tel, tel) == 0 && strcmp(u.id, id) != 0) {
      fclose(file);
      printf("Ce numero existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}

int verifUniciteMailUser(char mail[], char id[]) {
  USER u;
  FILE *file = fopen("user.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&u, sizeof(USER), 1, file) == 1) {
    if (strcmp(u.email, mail) == 0 && strcmp(u.id, id) != 0) {
      fclose(file);
      printf("Ce mail existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}




