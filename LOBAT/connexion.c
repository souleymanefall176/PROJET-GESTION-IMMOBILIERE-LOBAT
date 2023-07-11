#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "lobat.h"

/*
    Dans cette page nous allons mettre toutes les fonctions et procedures de connexions
    // je definis un administrateur avec login admin et password passer
*/
//VERIFICATION FICHIER VIDE OU PAS DEBUT
int verifFile(FILE* file){
    file=fopen("user.bin","rb");
    if (file == NULL) {
        printf("Le fichier n'existe pas.\n");
        return 0;
    }

    // Se déplacer à la fin du fichier
    fseek(file, 0, SEEK_END);
    // Récupérer la position actuelle dans le fichier
    long taille = ftell(file);

    fclose(file);

    if (taille == 0) {
        return 1;  // Le fichier est vide
    } else {
        return 0;  // Le fichier n'est pas vide
    }
}

//VERIFICATION FICHIER VIDE OU PAS FIN

//CONNEXION DEBUT
/*int connexion(){
    USER user;
    char reponse;
    int connected;

    puts("======================================== CONNEXION ========================================");
    puts("Pour acceder a nos services, veuillez vous connecter : ");
    do{
    connected = 1;
        fflush(stdin);
        reponse='o';
        printf("Login : ");
        gets(user.login);
        printf("Mot de Passe : ");
        gets(user.password);
        if(myStrCmp(user.login,"admin")!=1 || myStrCmp(user.password,"passer")!=1){
            puts("LOGIN ou MOT DE PASSE errone.");//si les identifiants ne sont pas respecter
            do{
                fflush(stdin);
                printf("Voulez vous reessayer (o/n) : ");
                scanf("%c",&reponse);
            }while(myLowerCase(reponse)!='o' && myLowerCase(reponse)!='n');//ici on redemande à l'utilisateur s'il veut reessayer
            if(reponse=='n'){
                puts("Au revoir!!!");
            }

        }else if(1){//dans le cas ou
            puts("Connexion reussie !!!");
            Sleep(2000);
            system("cls");
            if(myStrCaseCmp(user.typeUser,"ADMINISTRATEUR")==1){
                connected=1;//quand l'utilisateur est un admin
            }else if(myStrCaseCmp(user.typeUser,"GESTIONNAIRE")==1){
                connected=2;//quand l'utilisateur est un gestionnaire
            }
        }else{
            connected = 0;//quand la connexion n'a pas reussie
        }
    }while((myStrCmp(user.login,"admin")!=1 || myStrCmp(user.password,"passer")!=1) && reponse=='o' );//apres on comparera si les identifiants existe dans un tableau d'utilisateurs

    return connected;//je retourne cette valeur pour voir si l'utilisateur a reussi a se connecter ou pas
}*/
//pour verifier si la connexion est bonne
int connected(FILE* file, char login[],char password[]){
    file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    USER user;

    while (fread(&user, sizeof(USER), 1, file) == 1) {
        if (strcmp(user.login, login) == 0 && strcmp(user.password, password) == 0 && strcmp(user.typeUser,"administrateur")==0) {
            fclose(file);
            return 1; // Les identifiants correspondent
        }
        if (strcmp(user.login, login) == 0 && strcmp(user.password, password) == 0 && strcmp(user.typeUser,"gestionnaire")==0) {
            strcpy(cpyIdGestionnaire,user.id);
            fclose(file);
            return 2; // Les identifiants correspondent
        }
    }

    fclose(file);
    return 0;
}
int verifTypeUser(FILE* file, char ch[]){
    file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    USER user;

    while (fread(&user, sizeof(USER), 1, file) == 1) {
        if (strcmp(user.typeUser, ch) == 0){
            fclose(file);
            return 1; // Les identifiants correspondent
        }
    }

    fclose(file);
    return 0;
}

int connexion() {
    char login[30], password[30];


    char reponse;
    int connecte = 0;
    int isUserConnected;

    FILE* file = NULL;
    puts("============================== CONNEXION ==============================");
    puts("Pour acceder a nos services, veuillez vous connecter : ");
    do {
        connecte = 1;
        fflush(stdin);
        reponse = 'o';
        printf("Login : ");
        gets(login);
        printf("Mot de Passe : ");
        gets(password);

        isUserConnected = connected(file, login, password);

        if (isUserConnected == 0) {
            puts("LOGIN ou MOT DE PASSE errone.");
            do {
                fflush(stdin);
                printf("Voulez vous reessayer (o/n) : ");
                scanf("%c", &reponse);
            } while (myLowerCase(reponse) != 'o' && myLowerCase(reponse) != 'n');

            if (reponse == 'n'){
                puts("Au revoir!!!");
            }

        } else if (isUserConnected == 1) {
            puts("Connexion reussie !!!");

            connecte = 1;
            Sleep(2000);
            system("cls");

        } else if (isUserConnected == 2) {
            puts("Connexion reussie !!!");
            connecte = 2;
            Sleep(2000);
            system("cls");
        }

    } while (isUserConnected == 0 && reponse == 'o');

    return connecte;
}


