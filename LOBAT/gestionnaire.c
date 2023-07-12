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
            ListerInfos();
            accueilGestionnaire();
            break;
        case 5:
            rechercherContrats();
            accueilGestionnaire();
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
    printf("\t5-Trouver un contrat\n");
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
void choixGestion3(){
    printf("\t1-Client\n");
    printf("\t2-Contrat\n");
    printf("\t3-Paiement\n");
    printf("\t0-Quitter\n");
}

void ListerInfos(){
    FILE* file=NULL;
    char chaine[20];
    int choix,index=0,choixQuit;
    CLIENT cl, tabClient[TM];
    CONTRAT co, tabContrat[TM];
    PAIEMENT p;

    do{
        choixGestion3();
        printf("Choix : ");
        choix=verifInt(chaine);
    }while(choix<0 || choix>3);

    switch(choix){
        case 1:
            puts("================================ CLIENT ================================");
            file = fopen("client.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier client.bin.\n");
                Sleep(2000);
                system("cls");
                accueilGestionnaire();
                return;
            }

            while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
                    tabClient[index]=cl;
                    index++;
                    printf("Client %d\n",index);
                    printf("\tID : %s\n\tNOM : %s\n\tPRENOM : %s\n\tTEL : %s\n\tEMAIL : %s\n\tCIN : %s\n\tID GESTIONNAIRE : %s\n",cl.id,cl.nom,cl.prenom,cl.tel,cl.email,cl.CIN,cl.idGestionnaire);

            }

            fclose(file);
            do{

                printf("\t1- Modifier\n");
                printf("\t0- Quitter\n");
                printf("Choix : ");
                scanf("%d", &choixQuit);
            }while(choixQuit<0 || choixQuit>1);
            switch(choixQuit){
                case 1:
                    do{
                        printf("Choix Client : ");
                        choix=verifInt(chaine);
                    }while(choix<1 || choix>=index);
                    modifierClient(tabClient[choix-1].id);
                    Sleep(2000);
                    system("cls");
                    accueilGestionnaire();
                    break;
                default:
                    Sleep(2000);
                    system("cls");
                    accueilGestionnaire();
            }
            break;
        case 2:
            puts("================================ CONTRAT ================================");
            file = fopen("contrat.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier contrat.bin.\n");
                Sleep(2000);
                system("cls");
                accueilGestionnaire();
                return;
            }

            while (fread(&co, sizeof(CONTRAT), 1, file) == 1) {
                    tabContrat[index]=co;
                    index++;
                    printf("Client %d\n",index);
                    printf("\tID : %s\n\tID CLIENT : %s\n\tID LOCATION : %s\n\tID GESTIONNAIRE : %s\n\tMODE PAIEMENT : %s\n\tDATE DEBUT  : %d/%d/%d\n\tDATE FIN  : %d/%d/%d\n",co.id,co.idClient,co.idLocation,co.idGestionnaire,co.modePaiement,co.date_DEB.jours,co.date_DEB.mois,co.date_DEB.annee,co.date_FIN.jours,co.date_FIN.mois,co.date_FIN.annee);
                }

            fclose(file);
            do{

                printf("\t1- Modifier\n");
                printf("\t0- Quitter\n");
                printf("Choix : ");
                scanf("%d", &choixQuit);
            }while(choixQuit<0 || choixQuit>1);
            switch(choixQuit){
                case 1:
                    do{
                        printf("Choix Contrat : ");
                        choix=verifInt(chaine);
                    }while(choix<1 || choix>=index);
                    modifierContrat(tabContrat[choix-1].id);
                    Sleep(2000);
                    system("cls");
                    accueilGestionnaire();
                    break;
                default:
                    Sleep(2000);
                    system("cls");
                    accueilGestionnaire();
            }
            break;
        case 3:
            puts("================================ PAIEMENT ================================");
            file = fopen("paiement.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier paiement.bin.\n");
                Sleep(2000);
                system("cls");
                accueilGestionnaire();
                return;
            }

            while (fread(&p, sizeof(PAIEMENT), 1, file) == 1) {

                    index++;
                    printf("Client %d\n",index);
                    printf("\tID : %s\n\tID CONTRAT : %s\n\tID GESTIONNAIRE : %s\n\tDATE PAIEMENT  : %d/%d/%d\n",p.id,p.idContrat,p.idGestionnaire,p.datePaiement.jours,p.datePaiement.mois,p.datePaiement.annee);
                }

            fclose(file);
            do{

                printf("\t0- Quitter\n");
                printf("Choix : ");
                scanf("%d", &choixQuit);
            }while(choixQuit!=0);
            if(choixQuit==0){
                Sleep(2000);
                system("cls");
                accueilGestionnaire();
            }
            break;
        default:
            Sleep(2000);
            system("cls");
            accueilAdministrateur();


    }
}


