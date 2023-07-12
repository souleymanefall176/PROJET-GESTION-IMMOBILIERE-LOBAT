#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "lobat.h"

/*
    Dans cette page nous allons mettre toutes les fonctions et procedures de creation de Location
*/


void ajouterLocation1(){
    LOCATION loc;
    BAILLEUR b;
    int choice2;
    int l=0;
    char price[200];
    incrementerClient(&l);
    FILE *file = NULL;
    puts("============================== CREATION LOCATION ==============================");
    loc.aContrat=0;
    do{
        fflush(stdin);
        printf("Libelle : ");
        gets(loc.libelle);
        if(myStrlen(loc.libelle)>19 || verifLetter(loc.libelle)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.libelle)>19 || verifLetter(loc.libelle)!=0);

    do{
        fflush(stdin);
        printf("Pays : ");
        gets(loc.adresse.pays);
        if(myStrlen(loc.adresse.pays)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.pays)>19);
    do{
        fflush(stdin);
        printf("Region : ");
        gets(loc.adresse.region);
        if(myStrlen(loc.adresse.region)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.region)>19);
    do{
        fflush(stdin);
        printf("Departement : ");
        gets(loc.adresse.departement);
        if(myStrlen(loc.adresse.departement)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.departement)>19);
    do{
        fflush(stdin);
        printf("Commune : ");
        gets(loc.adresse.commune);
        if(myStrlen(loc.adresse.commune)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.commune)>19);

    do{
        fflush(stdin);
        printf("Type Logement : ");
        gets(loc.typeLogement);
        if(strcasecmp(loc.typeLogement,"MAISON")!=0 && strcasecmp(loc.typeLogement,"STUDIO")!=0 && strcasecmp(loc.typeLogement,"APPARTEMENT")!=0){
            puts("Erreur : Logement non disponible.");
        }

    }while(strcasecmp(loc.typeLogement,"MAISON")!=0 && strcasecmp(loc.typeLogement,"STUDIO")!=0 && strcasecmp(loc.typeLogement,"APPARTEMENT")!=0);

    sprintf(loc.id,"L%c%c%c%c%c%c%d",myUpperCase(loc.libelle[0]),myUpperCase(loc.typeLogement[0]),myUpperCase(loc.adresse.pays[0]),myUpperCase(loc.adresse.region[0]),myUpperCase(loc.adresse.departement[0]),myUpperCase(loc.adresse.commune[0]),l);
    printf("ID : %s\n",loc.id);
    do{
        fflush(stdin);
        printf("Prix : ");
        loc.prix=verifInt(price);
    }while(loc.prix<=0);
    file = fopen("bailleur.bin", "rb"); // Ouverture du fichier en mode lecture binaire

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");

    }
    printf("Choisir un bailleur : ");
    afficherMenuBailleur();
    do{
        printf("Choix : ");
        choice2=choix();
    }while(choice2<0 || choice2>2);
    fseek(file, (choice2 - 1) * sizeof(BAILLEUR), SEEK_SET); // Déplacement à la position correspondante dans le fichier

    fread(&b, sizeof(BAILLEUR), 1, file); // Lecture des informations du bailleur
    strcpy(loc.idBailleur, b.id);
    fclose(file);
    printf("Id Bailleur : %s\n",loc.idBailleur);
    file=fopen("location.bin","ab");
    fwrite(&loc,sizeof(LOCATION),1,file);
    fclose(file);
    puts("location ajoute avec succe!!!");
    Sleep(2000);
    system("cls");


}
void ajouterLocation2(char idClient[]){
    LOCATION loc;
    BAILLEUR b;
    int l=0;

    int choice2;
    char price[200];
    incrementerClient(&l);
    FILE *file = NULL;
    puts("============================== CREATION LOCATION ==============================");
    loc.aContrat=0;
    do{
        fflush(stdin);
        printf("Libelle : ");
        gets(loc.libelle);
        if(myStrlen(loc.libelle)>19 || verifLetter(loc.libelle)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.libelle)>19 || verifLetter(loc.libelle)!=0);

    do{
        fflush(stdin);
        printf("Pays : ");
        gets(loc.adresse.pays);
        if(myStrlen(loc.adresse.pays)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.pays)>19);
    do{
        fflush(stdin);
        printf("Region : ");
        gets(loc.adresse.region);
        if(myStrlen(loc.adresse.region)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.region)>19);
    do{
        fflush(stdin);
        printf("Departement : ");
        gets(loc.adresse.departement);
        if(myStrlen(loc.adresse.departement)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.departement)>19);
    do{
        fflush(stdin);
        printf("Commune : ");
        gets(loc.adresse.commune);
        if(myStrlen(loc.adresse.commune)>19){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(loc.adresse.commune)>19);

    do{
        fflush(stdin);
        printf("Type Logement : ");
        gets(loc.typeLogement);
        if(strcasecmp(loc.typeLogement,"MAISON")!=0 && strcasecmp(loc.typeLogement,"STUDIO")!=0 && strcasecmp(loc.typeLogement,"APPARTEMENT")!=0){
            puts("Erreur : Logement non disponible.");
        }

    }while(strcasecmp(loc.typeLogement,"MAISON")!=0 && strcasecmp(loc.typeLogement,"STUDIO")!=0 && strcasecmp(loc.typeLogement,"APPARTEMENT")!=0);

    sprintf(loc.id,"L%c%c%c%c%c%c%d",myUpperCase(loc.libelle[0]),myUpperCase(loc.typeLogement[0]),myUpperCase(loc.adresse.pays[0]),myUpperCase(loc.adresse.region[0]),myUpperCase(loc.adresse.departement[0]),myUpperCase(loc.adresse.commune[0]),l);
    printf("ID : %s\n",loc.id);
    do{
        fflush(stdin);
        printf("Prix : ");
        loc.prix=verifInt(price);
    }while(loc.prix<=0);
    file = fopen("bailleur.bin", "rb"); // Ouverture du fichier en mode lecture binaire

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");

    }
    printf("Choisir un bailleur : \n");
    afficherMenuBailleur();
    do{
        printf("Choix : ");
        choice2=choix();
    }while(choice2<0 || choice2>2);
    fseek(file, (choice2 - 1) * sizeof(BAILLEUR), SEEK_SET); // Déplacement à la position correspondante dans le fichier

    fread(&b, sizeof(BAILLEUR), 1, file); // Lecture des informations du bailleur
    strcpy(loc.idBailleur, b.id);
    fclose(file);
    printf("Id Bailleur : %s\n",loc.idBailleur);
    file=fopen("location.bin","ab");
    fwrite(&loc,sizeof(LOCATION),1,file);
    fclose(file);
    puts("location ajoute avec succe!!!");
    Sleep(2000);
    system("cls");



}

 //MENU location DEBUT

void afficherMenuLocation() {
    FILE* file = fopen("location.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    LOCATION loc;
    int index = 1;

    printf("========== MENU ==========\n");
    printf("Liste des id des Locations :\n");

    while (fread(&loc, sizeof(LOCATION), 1, file) == 1) {
        printf("%d. %s\n", index, loc.id);
        printf("\tLibelle %s\n\tType Logement : %s\n\tAdresse : %s %s %s %s\n\tPrix : %f\n",loc.libelle,loc.typeLogement,loc.adresse.pays,loc.adresse.region,loc.adresse.departement,loc.adresse.commune,loc.prix);
        index++;
    }

    printf("0. Accueil\n");
    printf("==========================\n");

    fclose(file);
}

void faireChoixLocation(char idSelectionne[]) {
    int choix;
    printf("Choisissez un location (0 pour quitter) : ");
    scanf("%d", &choix);

    if (choix != 0) {
        FILE* file = fopen("location.bin", "rb");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return;
        }

        LOCATION loc;
        int index = 1;

        while (fread(&loc, sizeof(LOCATION), 1, file) == 1) {
            if (index == choix) {
                fclose(file);
                strcpy(idSelectionne, loc.id);
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

 void modifierLocation(char id[] ) {

    LOCATION loc;
    BAILLEUR b;
    int choice2;
    int index = 1;
    char price[200];
    FILE* file = fopen("location.bin", "r+b");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }




    while (fread(&loc, sizeof(LOCATION), 1, file) == 1) {
        if (strcmp(loc.id, id) == 0) {
            fseek(file, -sizeof(LOCATION), SEEK_CUR);
            do{
                fflush(stdin);
                printf("Libelle : ");
                gets(loc.libelle);
                if(myStrlen(loc.libelle)>19 || verifLetter(loc.libelle)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(loc.libelle)>19 || verifLetter(loc.libelle)!=0);

            do{
                fflush(stdin);
                printf("Pays : ");
                gets(loc.adresse.pays);
                if(myStrlen(loc.adresse.pays)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(loc.adresse.pays)>19);
            do{
                fflush(stdin);
                printf("Region : ");
                gets(loc.adresse.region);
                if(myStrlen(loc.adresse.region)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(loc.adresse.region)>19);
            do{
                fflush(stdin);
                printf("Departement : ");
                gets(loc.adresse.departement);
                if(myStrlen(loc.adresse.departement)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(loc.adresse.departement)>19);
            do{
                fflush(stdin);
                printf("Commune : ");
                gets(loc.adresse.commune);
                if(myStrlen(loc.adresse.commune)>19){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(loc.adresse.commune)>19);

            do{
                fflush(stdin);
                printf("Type Logement : ");
                gets(loc.typeLogement);
                if(strcasecmp(loc.typeLogement,"MAISON")!=0 && strcasecmp(loc.typeLogement,"STUDIO")!=0 && strcasecmp(loc.typeLogement,"APPARTEMENT")!=0){
                    puts("Erreur : Logement non disponible.");
                }

            }while(strcasecmp(loc.typeLogement,"MAISON")!=0 && strcasecmp(loc.typeLogement,"STUDIO")!=0 && strcasecmp(loc.typeLogement,"APPARTEMENT")!=0);
            do{
                fflush(stdin);
                printf("Prix : ");
                loc.prix=verifInt(price);
            }while(loc.prix<=0);
            file = fopen("bailleur.bin", "rb"); // Ouverture du fichier en mode lecture binaire

            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");

            }
            printf("Choisir un bailleur : ");
            afficherMenuBailleur();
            do{
                printf("Choix : ");
                choice2=choix();
            }while(choice2<0 || choice2>2);
            fseek(file, (choice2 - 1) * sizeof(BAILLEUR), SEEK_SET); // Déplacement à la position correspondante dans le fichier

            fread(&b, sizeof(BAILLEUR), 1, file); // Lecture des informations du bailleur
            strcpy(loc.idBailleur, b.id);
            fclose(file);
            printf("Id Bailleur : %s\n",loc.idBailleur);
            fseek(file, 0, SEEK_CUR);
            fwrite(&loc, sizeof(LOCATION), 1, file);
            fclose(file);
            printf("Location modifie avec succes.\n");
            return;
        }


        index++;
    }


    fclose(file);
}
void afficherIdMenuModLocation(char idSelectionne[]) {
    afficherMenuLocation();
    faireChoixLocation(idSelectionne);
    Sleep(2000);
    system("cls");
    modifierLocation(idSelectionne);

}

//VERIFICATION FICHIER VIDE OU PAS DEBUT
int verifFileBailleur(FILE* file){

    file=fopen("bailleur.bin","rb");
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

void trouverLocation(){

     // Tableau pour stocker les clients
    LOCATION locations[100];  // Tableau pour stocker les locations
    FILE* file=NULL;
    char chaine[20];
    int choix;  // Nombre de clients lus
    int nbLocations = 0;  // Nombre de locations lues
    int nbLocationsDisponibles;
    int locationsDisponiblesIndex[100];  // Index des locations disponibles
    int choixLocation;

    do{
        choixAdmin5();
        printf("Choix : ");
        choix=verifInt(chaine);
    }while(choix<0 || choix>3);

    switch(choix){
        case 1:
            // Lire les locations depuis le fichier location.bin
            file = fopen("location.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier location.bin.\n");
                return;
            }

            while (fread(&locations[nbLocations], sizeof(LOCATION), 1, file) == 1) {
                if(strcasecmp(locations[nbLocations].typeLogement,"maison")==0){
                    nbLocations++;
                }
            }
            fclose(file);
            // Parcourir les locations pour vérifier si elles ont un contrat
            nbLocationsDisponibles = 0;  // Nombre de locations disponibles

            for (int i = 0; i < nbLocations; i++) {
                int locationDejaLouee = 0;
                // Comparer l'ID de la location avec les IDs présents dans le fichier contrat.bin
                file = fopen("contrat.bin", "rb");
                if (file != NULL) {
                    CONTRAT contrat;
                    while (fread(&contrat, sizeof(CONTRAT), 1, file) == 1) {
                        if (strcmp(contrat.idLocation, locations[i].id) == 0 && strcasecmp(locations[i].typeLogement,"maison")==0) {
                            locationDejaLouee = 1;
                            break;
                        }
                    }
                    fclose(file);
                }
                if (!locationDejaLouee) {
                    locationsDisponiblesIndex[nbLocationsDisponibles] = i;
                    nbLocationsDisponibles++;
                }
            }
            // Vérifier s'il y a des locations disponibles
            if (nbLocationsDisponibles == 0) {
                printf("Aucune location de type maison disponible.\n");
                Sleep(2000);
                system("cls");
                accueilAdministrateur();
                return;
            }
            // Afficher les ID des locations disponibles
            printf("Liste des locations disponibles :\n");
            for (int i = 0; i < nbLocationsDisponibles; i++) {
                if(strcasecmp(locations[locationsDisponiblesIndex[i]].typeLogement,"maison")==0){
                    printf("%d. %s\n", i + 1, locations[locationsDisponiblesIndex[i]].id);
                    printf("\tLibelle %s\n\tType Logement : %s\n\tAdresse : %s %s %s %s\n\tPrix : %f\n",locations[locationsDisponiblesIndex[i]].libelle,locations[locationsDisponiblesIndex[i]].typeLogement,locations[locationsDisponiblesIndex[i]].adresse.pays,locations[locationsDisponiblesIndex[i]].adresse.region,locations[locationsDisponiblesIndex[i]].adresse.departement,locations[locationsDisponiblesIndex[i]].adresse.commune,locations[locationsDisponiblesIndex[i]].prix);
                }

            }
            printf("\n");
            // Demander à l'utilisateur de choisir une location

            printf("0 pour quitter : ");
            scanf("%d", &choixLocation);
            // Vérifier si l'utilisateur a choisi de quitter
            if (choixLocation == 0) {
                Sleep(2000);
                system("cls");
                accueilAdministrateur();
                return;
            }

        break;
        case 2:

            // Lire les locations depuis le fichier location.bin
            file = fopen("location.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier location.bin.\n");
                return;
            }

            while (fread(&locations[nbLocations], sizeof(LOCATION), 1, file) == 1) {
                if(strcasecmp(locations[nbLocations].typeLogement,"appartement")==0){
                    nbLocations++;
                }
            }
            fclose(file);
            // Parcourir les locations pour vérifier si elles ont un contrat
            nbLocationsDisponibles = 0;  // Nombre de locations disponibles
            for (int i = 0; i < nbLocations; i++) {
                int locationDejaLouee = 0;
                // Comparer l'ID de la location avec les IDs présents dans le fichier contrat.bin
                file = fopen("contrat.bin", "rb");
                if (file != NULL) {
                    CONTRAT contrat;
                    while (fread(&contrat, sizeof(CONTRAT), 1, file) == 1) {
                        if (strcmp(contrat.idLocation, locations[i].id) == 0 && strcasecmp(locations[i].typeLogement,"appartement")==0) {
                            locationDejaLouee = 1;
                            break;
                        }
                    }
                    fclose(file);
                }
                if (!locationDejaLouee) {
                    locationsDisponiblesIndex[nbLocationsDisponibles] = i;
                    nbLocationsDisponibles++;
                }
            }
            // Vérifier s'il y a des locations disponibles
            if (nbLocationsDisponibles == 0) {
                printf("Aucune location de type appartement disponible .\n");
                Sleep(2000);
                system("cls");
                accueilAdministrateur();
                return;
            }
            // Afficher les ID des locations disponibles
            printf("Liste des locations disponibles :\n");
            for (int i = 0; i < nbLocationsDisponibles; i++) {
                if(strcasecmp(locations[locationsDisponiblesIndex[i]].typeLogement,"appartement")==0){
                    printf("%d. %s\n", i + 1, locations[locationsDisponiblesIndex[i]].id);
                    printf("\tLibelle %s\n\tType Logement : %s\n\tAdresse : %s %s %s %s\n\tPrix : %f\n",locations[locationsDisponiblesIndex[i]].libelle,locations[locationsDisponiblesIndex[i]].typeLogement,locations[locationsDisponiblesIndex[i]].adresse.pays,locations[locationsDisponiblesIndex[i]].adresse.region,locations[locationsDisponiblesIndex[i]].adresse.departement,locations[locationsDisponiblesIndex[i]].adresse.commune,locations[locationsDisponiblesIndex[i]].prix);
                }

            }
            printf("\n");
            // Demander à l'utilisateur de choisir une location

            printf("0 pour quitter : ");
            scanf("%d", &choixLocation);
            // Vérifier si l'utilisateur a choisi de quitter
            if (choixLocation == 0) {
                Sleep(2000);
                system("cls");
                accueilAdministrateur();
                return;
            }
        break;
        case 3:

            // Lire les locations depuis le fichier location.bin
            file = fopen("location.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier location.bin.\n");
                return;
            }

            while (fread(&locations[nbLocations], sizeof(LOCATION), 1, file) == 1) {
                if(strcasecmp(locations[nbLocations].typeLogement,"studio")==0){
                    nbLocations++;
                }
            }
            fclose(file);
            // Parcourir les locations pour vérifier si elles ont un contrat
            nbLocationsDisponibles = 0;  // Nombre de locations disponibles
            for (int i = 0; i < nbLocations; i++) {
                int locationDejaLouee = 0;
                // Comparer l'ID de la location avec les IDs présents dans le fichier contrat.bin
                file = fopen("contrat.bin", "rb");
                if (file != NULL) {
                    CONTRAT contrat;
                    while (fread(&contrat, sizeof(CONTRAT), 1, file) == 1) {
                        if (strcmp(contrat.idLocation, locations[i].id) == 0 && strcasecmp(locations[i].typeLogement,"studio")==0) {
                            locationDejaLouee = 1;
                            break;
                        }
                    }
                    fclose(file);
                }
                if (!locationDejaLouee) {
                    locationsDisponiblesIndex[nbLocationsDisponibles] = i;
                    nbLocationsDisponibles++;
                }
            }
            // Vérifier s'il y a des locations disponibles
            if (nbLocationsDisponibles == 0) {
                printf("Aucune location de type studio disponible.\n");
                Sleep(2000);
                system("cls");
                accueilAdministrateur();
                return;
            }
            // Afficher les ID des locations disponibles
            printf("Liste des locations disponibles :\n");
            for (int i = 0; i < nbLocationsDisponibles; i++) {
                if(strcasecmp(locations[locationsDisponiblesIndex[i]].typeLogement,"studio")==0){
                    printf("%d. %s\n", i + 1, locations[locationsDisponiblesIndex[i]].id);
                    printf("\tLibelle %s\n\tType Logement : %s\n\tAdresse : %s %s %s %s\n\tPrix : %f\n",locations[locationsDisponiblesIndex[i]].libelle,locations[locationsDisponiblesIndex[i]].typeLogement,locations[locationsDisponiblesIndex[i]].adresse.pays,locations[locationsDisponiblesIndex[i]].adresse.region,locations[locationsDisponiblesIndex[i]].adresse.departement,locations[locationsDisponiblesIndex[i]].adresse.commune,locations[locationsDisponiblesIndex[i]].prix);
                }

            }
            printf("\n");
            // Demander à l'utilisateur de choisir une location

            printf("0 pour quitter : ");
            scanf("%d", &choixLocation);
            // Vérifier si l'utilisateur a choisi de quitter
            if (choixLocation == 0) {
                Sleep(2000);
                system("cls");
                accueilAdministrateur();
                return;
            }
        break;
        default:
            Sleep(2000);
            system("cls");
            accueilAdministrateur();
    }


}
