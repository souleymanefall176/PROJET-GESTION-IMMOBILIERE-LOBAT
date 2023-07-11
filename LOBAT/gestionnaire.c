#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lobat.h"



//CHOIX GESTIONNAIRE DEBUT
void choixGestionnaire(){
    char idSelectionne[20];
    int choice1,choice2;
    do{
        printf("Choix : ");
        choice1=choix();
    }while(choice1<0 || choice1>5);
    switch(choice1){
        case 1 :
            choixGestion1();
            do{
                printf("Choix : ");
                choice2=choix();
            }while(choice2<0 || choice2>2);
            switch(choice2){
                case 1:
                    ajouterClient();
                    accueilGestionnaire();
                    break;
                case 2:
                    afficherIdMenuModClient(idSelectionne);
                    Sleep(2000);
                    system("cls");
                    accueilGestionnaire();
                    break;
                default:
                    accueilGestionnaire();
            }
            break;
        case 2:
            choixGestion2();
            do{
                printf("Choix : ");
                choice2=choix();
            }while(choice2<0 || choice2>2);
            switch(choice2){
                case 1:
                    ajouterContrat1();
                    accueilGestionnaire();
                    break;
                case 2:
                    afficherIdMenuModContrat(idSelectionne);
                    accueilGestionnaire();
                    break;
                default:
                    accueilGestionnaire();
            }
            break;
        case 3:
            enregistrementPaiement();
            accueilGestionnaire();
            break;
        case 4:
            printf("\t4-Lister Informations\n");
            break;
        default:
            puts("Vous allez etre deconnecter dans 2 secondes");
            Sleep(2000);
            system("cls");
            accueil();
    }
}
//CHOIX GESTIONNAIRE FIN

//ACCUEIL GESTIOONAIRE DEBUT

void accueilGestionnaire(){

    puts("MENU : ");
    printf("\t1-Ajouter/modifier un Client\n");
    printf("\t2-Ajouter/modifier un Contrat\n");
    printf("\t3-Enregistrer un payement\n");
    printf("\t4-Lister Informations\n");
    printf("\t0-Deconnexion\n");
    choixGestionnaire();
    Sleep(2000);
    system("cls");
}

void choixGestion1(){
    puts("GESTION D'UTILISATEUR");
    printf("\t1-Ajouter un Client\n");
    printf("\t2-Modifier un Client\n");
    printf("\t0-Quitter\n");
}

void choixGestion2(){
    printf("\t1-Ajouter un Contrat\n");
    printf("\t2-Modifier un Contrat\n");
    printf("\t0-Quitter\n");
}

