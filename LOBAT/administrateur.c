#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lobat.h"

//CHOIX ADMINISTRATEUR DEBUT
void choixAdministrateur(){
    int choice1,choice2;
    FILE *file=NULL;
    char loginSelectionne[20], idSelectionne[20];
    do{
        printf("Choix : ");
        choice1=choix();
    }while(choice1<0 || choice1>5);
    switch(choice1){
        case 1 :
            choixAdmin1();
            do{
                printf("Choix : ");
                choice2=choix();
            }while(choice2<0 || choice2>3);
            switch(choice2){
                case 1:
                    inscription();
                    accueilAdministrateur();
                    break;
                case 2:
                    afficherLoginsMenuModUser(loginSelectionne);
                    Sleep(2000);
                    system("cls");
                    accueilAdministrateur();
                    break;
                case 3:
                    afficherLoginsMenuSuprUser(loginSelectionne);
                    Sleep(2000);
                    system("cls");
                    accueilAdministrateur();
                    break;

                default:
                    accueilAdministrateur();
            }
            break;
        case 2:
            choixAdmin2();
            do{
                printf("Choix : ");
                choice2=choix();
            }while(choice2<0 || choice2>2);
            switch(choice2){
                case 1:
                    ajouterBailleur();
                    accueilAdministrateur();
                    break;
                case 2:
                    afficherIdMenuModBailleur(idSelectionne);
                    Sleep(2000);
                    system("cls");
                    accueilAdministrateur();
                    break;
                default:
                    accueilAdministrateur();
            }
            break;

        case 3:
            choixAdmin3();

            do{
                printf("Choix : ");
                choice2=choix();
            }while(choice2<0 || choice2>2);
            switch(choice2){
                case 1:

                    if(verifFileBailleur(file)==1){//verifier d'abord s'il y'a des bailleurs
                        puts("Aucun Bailleur : Veuillez en ajouter un.");
                        ajouterBailleur();
                        accueilAdministrateur();
                    }else{
                        ajouterLocation1();
                        accueilAdministrateur();
                    }


                    break;
                case 2:
                    afficherIdMenuModLocation(idSelectionne);
                    Sleep(2000);
                    system("cls");
                    accueilAdministrateur();
                    break;
                default:
                    accueilAdministrateur();
                }
            break;
        case 4:
             choixAdmin4();
              do{
                    printf("Choix : ");
                    choice2=choix();
              }while(choice2<0 || choice2>2);
              switch(choice2){
                    case 1:
                        afficherContratClient();
                        break;
                    case 2:
                        printf("Location\n");
                        break;
                    default:
                        Sleep(2000);
                        system("cls");
                        accueilAdministrateur();
              }
              break;
        case 5:
              choixAdmin5();
              do{
                    printf("Choix : ");
                    choice2=choix();
              }while(choice2<0 || choice2>3);
              switch(choice2){
                    case 1:
                        printf("maison\n");
                        break;
                    case 2:
                        printf("Studio\n");
                        break;
                    case 3:
                        printf("Appartement\n");
                        break;
                    default:
                        Sleep(2000);
                        system("cls");
                        accueilAdministrateur();
              }
              break;
        case 6:
              choixAdmin6();
              do{
                    printf("Choix : ");
                    choice2=choix();
              }while(choice2<0 || choice2>2);
              switch(choice2){
                    case 1:
                        printf("login\n");
                        break;
                    case 2:
                        printf("email\n");
                        break;
                    default:
                        Sleep(2000);
                        system("cls");
                        accueilAdministrateur();
              }
              break;
        default:
            puts("Vous allez etre deconnecter dans 2 secondes");
            Sleep(2000);
            system("cls");
            accueil();
    }
}
//CHOIX ADMINISTRATEUR FIN


//ACCUEIL ADMINISTRATEUR DEBUT

void accueilAdministrateur(){
    puts("MENU : ");
    printf("\t1-Creer/Modifier/Supprimer un Utilisateur\n");
    printf("\t2-Ajouter/Modifier un Bailleur\n");
    printf("\t3-Ajouter/Modifier une Location\n");
    printf("\t4-Trouver les Contrats\n");
    printf("\t5-Trouver les Locations disponibles\n");
    printf("\t6-Trouver un Utilisateur\n");
    printf("\t0-Deconnexion\n");
    choixAdministrateur();
    Sleep(2000);
    system("cls");

}

void choixAdmin1(){
    puts("GESTION D'UTILISATEUR");
    printf("\t1-Creer un Utilisateur\n");
    printf("\t2-Modifier un Utilisateur\n");
    printf("\t3-Supprimer un Utilisateur\n");
    printf("\t0-Quitter\n");
}

void choixAdmin2(){
    printf("\t1-Ajouter Bailleur\n");
    printf("\t2-Modifier Bailleur\n");
    printf("\t0-Quitter\n");

}
void choixAdmin4(){
    printf("\t1-Client\n");
    printf("\t2-Location\n");
    printf("\t0-Quitter\n");
}
void choixAdmin3(){
    printf("\t1-Ajouter Location\n");
    printf("\t2-Modifier Location\n");
    printf("\t0-Quitter\n");
}
void choixAdmin5(){
    printf("\t1-MAISON\n");
    printf("\t2-APPARTEMENT\n");
    printf("\t3-STUDIO\n");
    printf("\t0-Quitter\n");
}

void choixAdmin6(){
    printf("\t1-LOGIN\n");
    printf("\t2-MAIL\n");
    printf("\t0-Quitter\n");
}


//ACCUEIL ADMINISTRATEUR FIN


