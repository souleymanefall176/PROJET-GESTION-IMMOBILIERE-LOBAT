#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "lobat.h"




// Procédure pour ajouter un contrat

void ajouterContrat1() {
    int co = incrementerContrat();
    char chaineDate[10];
    char chaine[10];
    int choixPaie;
    int choix;
    DATES dateActuelle;
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    dateActuelle.jours = now->tm_mday;
    dateActuelle.mois = now->tm_mon + 1;
    dateActuelle.annee = now->tm_year + 1900;
    CLIENT clients[100];  // Tableau pour stocker les clients
    LOCATION locations[100];  // Tableau pour stocker les locations
    FILE* file=NULL;
    int nbClients = 0;  // Nombre de clients lus
    int nbLocations = 0;  // Nombre de locations lues
    int estAnterieure;
    do{
        printf("\t1-Nouveau Client\n");
        printf("\t2-Client Existant\n");
        printf("\t0-Quitter\n");
        printf("Choix : ");
        choix=verifInt(chaine);
        Sleep(2000);
        system("cls");
    }while(choix<0 || choix>2);
    switch(choix){
        case 1:
            ajouterClient();
            break;
        case 2:
            // Lire les données des fichiers clients et locations



            // Lire les clients depuis le fichier client.bin
            file = fopen("client.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier client.bin.\n");
                return;
            }

            while (fread(&clients[nbClients], sizeof(CLIENT), 1, file) == 1) {
                nbClients++;
            }

            fclose(file);

            // Lire les locations depuis le fichier location.bin
            file = fopen("location.bin", "rb");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier location.bin.\n");
                return;
            }

            while (fread(&locations[nbLocations], sizeof(LOCATION), 1, file) == 1) {
                nbLocations++;
            }

            fclose(file);

            // Parcourir les locations pour vérifier si elles ont un contrat
            int nbLocationsDisponibles = 0;  // Nombre de locations disponibles
            int locationsDisponiblesIndex[100];  // Index des locations disponibles

            for (int i = 0; i < nbLocations; i++) {
                int locationDejaLouee = 0;

                // Comparer l'ID de la location avec les IDs présents dans le fichier contrat.bin
                file = fopen("contrat.bin", "rb");
                if (file != NULL) {
                    CONTRAT contrat;

                    while (fread(&contrat, sizeof(CONTRAT), 1, file) == 1) {
                        if (strcmp(contrat.idLocation, locations[i].id) == 0) {
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
                printf("Aucune location disponible pour la creation d'un contrat.\n");
                Sleep(2000);
                system("cls");
                return;
            }

            // Afficher les ID des locations disponibles
            printf("Liste des locations disponibles :\n");
            for (int i = 0; i < nbLocationsDisponibles; i++) {
                printf("%d. %s\n", i + 1, locations[locationsDisponiblesIndex[i]].id);
                printf("\tLibelle %s\n\tType Logement : %s\n\tAdresse : %s %s %s %s\n\tPrix : %f\n",locations[locationsDisponiblesIndex[i]].libelle,locations[locationsDisponiblesIndex[i]].typeLogement,locations[locationsDisponiblesIndex[i]].adresse.pays,locations[locationsDisponiblesIndex[i]].adresse.region,locations[locationsDisponiblesIndex[i]].adresse.departement,locations[locationsDisponiblesIndex[i]].adresse.commune,locations[locationsDisponiblesIndex[i]].prix);
            }
            printf("\n");

            // Demander à l'utilisateur de choisir une location
            int choixLocation;
            printf("Choisissez une location (0 pour quitter) : ");
            scanf("%d", &choixLocation);

            // Vérifier si l'utilisateur a choisi de quitter
            if (choixLocation == 0) {
                Sleep(2000);
                system("cls");
                accueilGestionnaire();
                return;
            }

            // Vérifier si le choix est valide
            if (choixLocation < 1 || choixLocation > nbLocationsDisponibles) {
                printf("Choix invalide.\n");
                return;
            }

            // Sélectionner la location choisie
            int locationIndex = locationsDisponiblesIndex[choixLocation - 1];
            LOCATION locationChoisie = locations[locationIndex];

            // Afficher les ID des clients
            printf("\nListe des clients :\n");
            for (int i = 0; i < nbClients; i++) {
                printf("%d. %s\n", i + 1, clients[i].id);
            }
            printf("\n");

            // Demander à l'utilisateur de choisir un client
            int choixClient;
            printf("Choisissez un client (0 pour quitter) : ");
            scanf("%d", &choixClient);

            // Vérifier si l'utilisateur a choisi de quitter
            if (choixClient == 0) {
                Sleep(2000);
                system("cls");
                accueilGestionnaire();
                return;
            }

            // Vérifier si le choix est valide
            if (choixClient < 1 || choixClient > nbClients) {
                printf("Choix invalide.\n");
                return;
            }

            // Sélectionner le client choisi
            int clientIndex = choixClient - 1;
            CLIENT clientChoisi = clients[clientIndex];

            // Créer un nouveau contrat
            CONTRAT nouveauContrat;

            printf("\nInformations du contrat :\n");




            nouveauContrat.modifie = 0;

            // Demander la date de début du contrat
            do{
                printf("Saisir la Date de Debut du contrat au format JJ/MM/AAAA : ");
                nouveauContrat.date_DEB = scanDate(chaineDate);
                estAnterieure = estDateAnterieure(nouveauContrat.date_DEB, dateActuelle);
                if (estAnterieure) {
                    printf("La date saisie est anterieure a la date actuelle du systeme.\n");

                }
            }while (estAnterieure);
            //printf("Saisir la Date de Debut du contrat au format JJ/MM/AAAA : ");
            //nouveauContrat.date_DEB = scanDate(chaineDate);
            nouveauContrat.date_FIN.jours = 0;
            nouveauContrat.date_FIN.mois = 0;
            nouveauContrat.date_FIN.annee = 0;
            // Générer un nouvel ID de contrat
            sprintf(nouveauContrat.id, "CT%d%d",nouveauContrat.date_DEB.annee,co);//CT + id location + id client + annee + co
            printf("ID CONTRAT : %s\n",nouveauContrat.id);

            // Demander le mode de paiement du contrat
            choixPaie = menuPaiement();
            switch (choixPaie) {
                case 1:
                    strcpy(nouveauContrat.modePaiement, "CARTE");
                    break;
                case 2:
                    strcpy(nouveauContrat.modePaiement, "ESPECE");
                    break;
            }

            // Copier l'ID du client choisi dans le contrat
            strcpy(nouveauContrat.idClient, clientChoisi.id);

            // Copier l'ID de la location choisie dans le contrat
            strcpy(nouveauContrat.idLocation, locationChoisie.id);

            // Ajouter le nouveau contrat au fichier contrat.bin
            file = fopen("contrat.bin", "ab");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier contrat.bin.\n");
                return;
            }

            fseek(file, 0, SEEK_CUR);
            fwrite(&nouveauContrat, sizeof(CONTRAT), 1, file);
            fclose(file);

            printf("\nLe contrat a ete ajoute avec succes.\n");
            Sleep(2000);
            system("cls");
            break;
        default:
            Sleep(2000);
            system("cls");
            accueilGestionnaire();
    }


}

void ajouterContrat2(char idClient[]) {
    int co = incrementerContrat();
    char chaineDate[10];
    int choixPaie;
    DATES dateActuelle;
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    dateActuelle.jours = now->tm_mday;
    dateActuelle.mois = now->tm_mon + 1;
    dateActuelle.annee = now->tm_year + 1900;


    int estAnterieure;

    // Lire les données des fichiers et locations

    LOCATION locations[100];  // Tableau pour stocker les locations
    FILE* file=NULL;
    int nbLocations = 0;  // Nombre de locations lues

    // Lire les locations depuis le fichier location.bin
    file = fopen("location.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier location.bin.\n");
        return;
    }

    while (fread(&locations[nbLocations], sizeof(LOCATION), 1, file) == 1) {
        nbLocations++;
    }

    fclose(file);

    // Parcourir les locations pour vérifier si elles ont un contrat
    int nbLocationsDisponibles = 0;  // Nombre de locations disponibles
    int locationsDisponiblesIndex[100];  // Index des locations disponibles

    for (int i = 0; i < nbLocations; i++) {
        int locationDejaLouee = 0;

        // Comparer l'ID de la location avec les IDs présents dans le fichier contrat.bin
        file = fopen("contrat.bin", "rb");
        if (file != NULL) {
            CONTRAT contrat;

            while (fread(&contrat, sizeof(CONTRAT), 1, file) == 1) {
                if (strcmp(contrat.idLocation, locations[i].id) == 0) {
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
        printf("Aucune location disponible pour la creation d'un contrat.\n");
        Sleep(2000);
        system("cls");
        return;
    }

    // Afficher les ID des locations disponibles
    printf("Liste des locations disponibles :\n");
    for (int i = 0; i < nbLocationsDisponibles; i++) {
        printf("%d. %s\n", i + 1, locations[locationsDisponiblesIndex[i]].id);
    }
    printf("\n");

    // Demander à l'utilisateur de choisir une location
    int choixLocation;
    printf("Choisissez une location (0 pour quitter) : ");
    scanf("%d", &choixLocation);

    // Vérifier si l'utilisateur a choisi de quitter
    if (choixLocation == 0) {
        Sleep(2000);
        system("cls");
        accueilGestionnaire();
        return;
    }

    // Vérifier si le choix est valide
    if (choixLocation < 1 || choixLocation > nbLocationsDisponibles) {
        printf("Choix invalide.\n");
        return;
    }

    // Sélectionner la location choisie
    int locationIndex = locationsDisponiblesIndex[choixLocation - 1];
    LOCATION locationChoisie = locations[locationIndex];



    // Créer un nouveau contrat
    CONTRAT nouveauContrat;

    printf("\nInformations du contrat :\n");




    nouveauContrat.modifie = 0;


    // Demander la date de début du contrat
    do{
        printf("Saisir la Date de Debut du contrat au format JJ/MM/AAAA : ");
        nouveauContrat.date_DEB = scanDate(chaineDate);
        estAnterieure = estDateAnterieure(nouveauContrat.date_DEB, dateActuelle);
        if (estAnterieure) {
            printf("La date saisie est anterieure a la date actuelle du systeme.\n");
        }
    }while (estAnterieure);
    //printf("Saisir la Date de Debut du contrat au format JJ/MM/AAAA : ");
    //nouveauContrat.date_DEB = scanDate(chaineDate);
    nouveauContrat.date_FIN.jours = 0;
    nouveauContrat.date_FIN.mois = 0;
    nouveauContrat.date_FIN.annee = 0;
    // Générer un nouvel ID de contrat
    sprintf(nouveauContrat.id, "CT%d%d",nouveauContrat.date_DEB.annee,co);//CT + id location + id client + annee + co
    printf("ID CONTRAT : %s\n",nouveauContrat.id);

    // Demander le mode de paiement du contrat
    choixPaie = menuPaiement();
    switch (choixPaie) {
        case 1:
            strcpy(nouveauContrat.modePaiement, "CARTE");
            break;
        case 2:
            strcpy(nouveauContrat.modePaiement, "ESPECE");
            break;
    }



    // Copier l'ID de la location choisie dans le contrat
    strcpy(nouveauContrat.idLocation, locationChoisie.id);

    // Ajouter le nouveau contrat au fichier contrat.bin
    file = fopen("contrat.bin", "ab");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier contrat.bin.\n");
        return;
    }

    fseek(file, 0, SEEK_CUR);
    fwrite(&nouveauContrat, sizeof(CONTRAT), 1, file);
    fclose(file);

    printf("\nLe contrat a ete ajoute avec succes.\n");
    Sleep(2000);
    system("cls");
}



void afficherMenuContrat() {
    FILE* file = fopen("contrat.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    CONTRAT c;
    int index = 1;

    printf("========== MENU ==========\n");
    printf("Liste des id des contrats :\n");

    while (fread(&c, sizeof(CONTRAT), 1, file) == 1) {
        printf("%d. %s\n", index, c.id);
        index++;
    }


    printf("0. Accueil\n");
    printf("==========================\n");

    fclose(file);
}
void faireChoixContrat(char idSelectionne[]) {
    int choix;
    printf("Choisissez un Contrat (0 pour quitter) : ");
    scanf("%d", &choix);

    if (choix != 0) {
        FILE* file = fopen("contrat.bin", "rb");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return;
        }

        CONTRAT c;
        int index = 1;

        while (fread(&c, sizeof(CONTRAT), 1, file) == 1) {
            if (index == choix) {
                fclose(file);
                strcpy(idSelectionne, c.id);
                return;
            }
            index++;
        }

        fclose(file);

        printf("Choix invalide.\n");
    }else{
        Sleep(2000);
        system("cls");
        accueilGestionnaire();
    }
}
void afficherIdMenuModContrat(char idSelectionne[]) {
    afficherMenuContrat();
    faireChoixContrat(idSelectionne);
    Sleep(2000);
    system("cls");
    modifierContrat(idSelectionne);

}
void modifierContrat(char id[] ) {
    int estAnterieure;
    FILE* file = fopen("contrat.bin", "r+b");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    CONTRAT c;
    int index = 1;

    while (fread(&c, sizeof(CONTRAT), 1, file) == 1) {
        if (strcmp(c.id, id) == 0) {
            if (c.modifie==1) {
                printf("Ce contrat a deja ete modifie et ne peut pas être modifie a nouveau.\n");
                fclose(file);
                Sleep(2000);
                system("cls");
                return;
            }

            fseek(file, -sizeof(CONTRAT), SEEK_CUR);

            // Récupérer la date du système
            time_t t = time(NULL);
            struct tm* timeinfo = localtime(&t);

            // Mettre à jour la date de fin du contrat
            do{
                c.date_FIN.jours = timeinfo->tm_mday;
                c.date_FIN.mois = timeinfo->tm_mon + 1;
                c.date_FIN.annee = timeinfo->tm_year + 1900;
                estAnterieure=estDateAnterieure(c.date_FIN,c.date_DEB);
                if(estAnterieure){
                    printf("Le contrat n'a pas encore debuter.\n");
                    Sleep(2000);
                    system("cls");
                    return;
                }
            }while(estAnterieure);
            strcpy(c.idClient,"");
            strcpy(c.idLocation,"");

            c.modifie = 1; // Définir l'indicateur de modification à 1

            fseek(file, 0, SEEK_CUR);
            fwrite(&c, sizeof(CONTRAT), 1, file);
            fclose(file);
            printf("Contrat modifie avec succes.\n");
            Sleep(2000);
            system("cls");
            return;
        }


        index++;
    }


    fclose(file);
}
int menuPaiement(){
    int choix;
    char charInt[2];
    do{
        printf("\t1-Par Carte\n");
        printf("\t2-Par Espece\n");
        printf("Choix : ");
        choix=verifInt(charInt);
    }while(choix<1 || choix>2);
    return choix;

}




































/*

void afficher_informations_contrats() {
    FILE* fichier = fopen("contrat.bin", "rb");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    CONTRAT c;

    printf("Informations des locations :\n");
    printf("---------------------------\n");

    while (fread(&c, sizeof(CONTRAT), 1, fichier) == 1) {
        printf("ID : %s\n", c.id);
        printf("dejaPAYER : %d\n", c.dejaPayer);
        printf("MODIFIE : %d\n", c.modifie);
        // Afficher les autres informations du contrat

        printf("---------------------------\n");
    }

    fclose(fichier);
    fichier = fopen("paiement.bin", "rb");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    CONTRAT c;

    printf("Informations des locations :\n");
    printf("---------------------------\n");

    while (fread(&c, sizeof(CONTRAT), 1, fichier) == 1) {
        printf("ID : %s\n", c.id);
        printf("dejaPAYER : %d\n", c.dejaPayer);
        printf("MODIFIE : %d\n", c.modifie);
        // Afficher les autres informations du contrat

        printf("---------------------------\n");
    }

    fclose(fichier);

}*/


void rechercherContrats() {
    int choix;
    char chaine[2];
    do{
        printf("Choisissez le critere de recherche :\n");
        printf("1. Rechercher par client\n");
        printf("2. Rechercher par location\n");
        printf("Votre choix : ");
        choix=verifInt(chaine);
    }while(choix<1 || choix>2);

    FILE* fichierContrats = fopen("contrat.bin", "rb");
    if (fichierContrats == NULL) {
        printf("Erreur lors de l'ouverture du fichier contrat.bin\n");
        return;
    }

    CONTRAT contrat;
    CLIENT client;
    LOCATION location;

    switch (choix) {
        case 1:
            printf("Entrez l'ID du client : ");
            char idClient[20];
            scanf("%s", idClient);

            FILE* fichierClients = fopen("client.bin", "rb");
            if (fichierClients == NULL) {
                printf("Erreur lors de l'ouverture du fichier client.bin\n");
                Sleep(2000);
                system("cls");
                fclose(fichierContrats);
                return;
            }
            int index=0;
            while (fread(&client, sizeof(CLIENT), 1, fichierClients) == 1) {
                if (strcmp(client.id, idClient) == 0) {
                    rewind(fichierContrats);
                    while (fread(&contrat, sizeof(CONTRAT), 1, fichierContrats) == 1) {
                        if (strcmp(contrat.idClient, idClient) == 0) {
                            printf("Contrat ID: %s\n", contrat.id);
                            printf("Location ID: %s\n", contrat.idLocation);
                            printf("Gestionnaire ID: %s\n", contrat.idGestionnaire);
                            printf("Client ID: %s\n", contrat.idClient);
                            printf("Mode Paiement ID: %s\n", contrat.modePaiement);
                            printf("Date Debut: %d/%d/%d\n", contrat.date_DEB.jours,contrat.date_DEB.mois,contrat.date_DEB.annee);
                            printf("Date Fin: %d/%d/%d\n", contrat.date_FIN.jours,contrat.date_FIN.mois,contrat.date_FIN.annee);
                            index=1;
                            Sleep(2000);
                            system("cls");
                        }
                    }
                    if(index==0){
                        printf("Aucun contrat\n");
                        Sleep(2000);
                        system("cls");
                        accueilGestionnaire();
                    }
                    break;
                }
            }

            fclose(fichierClients);
            break;

        case 2:
            printf("Entrez l'ID de la location : ");
            char idLocation[20];
            scanf("%s", idLocation);

            FILE* fichierLocations = fopen("location.bin", "rb");
            if (fichierLocations == NULL) {
                printf("Erreur lors de l'ouverture du fichier location.bin\n");
                fclose(fichierContrats);
                return;
            }
            index=0;
            while (fread(&location, sizeof(LOCATION), 1, fichierLocations) == 1) {
                if (strcmp(location.id, idLocation) == 0) {
                    rewind(fichierContrats);
                    while (fread(&contrat, sizeof(CONTRAT), 1, fichierContrats) == 1) {
                        if (strcmp(contrat.idLocation, idLocation) == 0) {
                            printf("Contrat ID: %s\n", contrat.id);
                            printf("Location ID: %s\n", contrat.idLocation);
                            printf("Gestionnaire ID: %s\n", contrat.idGestionnaire);
                            printf("Client ID: %s\n", contrat.idClient);
                            printf("Mode Paiement ID: %s\n", contrat.modePaiement);
                            printf("Date Debut: %d/%d/%d\n", contrat.date_DEB.jours,contrat.date_DEB.mois,contrat.date_DEB.annee);
                            printf("Date Fin: %d/%d/%d\n", contrat.date_FIN.jours,contrat.date_FIN.mois,contrat.date_FIN.annee);
                            index=1;
                            Sleep(2000);
                            system("cls");
                        }
                    }
                    if(index==0){
                        printf("Aucun contrat\n");
                        Sleep(2000);
                        system("cls");
                        accueilGestionnaire();
                    }
                    break;
                }
            }

            fclose(fichierLocations);
            break;

        default:
            printf("Choix invalide\n");
            break;
    }

    fclose(fichierContrats);
}
