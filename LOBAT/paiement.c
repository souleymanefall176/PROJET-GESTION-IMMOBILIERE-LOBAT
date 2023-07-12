#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "lobat.h"
/*
void enregistrementPaiement(){
    PAIEMENT p;
    char idSelectionneClient[20],idSelectionneContrat[20],nomFichier[50];
    int pa=incrementerPaiement();
    FILE *file= NULL;
    // Récupérer la date du système
            time_t t = time(NULL);
            struct tm* timeinfo = localtime(&t);

            // Mettre à jour la date de fin du contrat
            p.datePaiement.jours = timeinfo->tm_mday;
            p.datePaiement.mois = timeinfo->tm_mon + 1;
            p.datePaiement.annee = timeinfo->tm_year + 1900;
            strcpy(p.idGestionnaire,cpyIdGestionnaire);
            printf("Choisir un Contrat : \n");
            afficherMenuContrat2();
            faireChoixContrat(idSelectionneContrat);
            copieIdContrat(idSelectionneContrat,idSelectionneClient);
            strcpy(p.idContrat,idSelectionneContrat);
            sprintf(p.id,"P%d%d%d%d",p.datePaiement.jours,p.datePaiement.mois,p.datePaiement.annee,pa);
            printf("ID : %s\n",p.id);
            sprintf(nomFichier,"%d%d%d_%s_%s.txt",p.datePaiement.annee,p.datePaiement.mois,p.datePaiement.jours,idSelectionneContrat,idSelectionneClient);
            printf("Nom : %s\n",nomFichier);

            //fichier texte pour nomFichier
            file=fopen(nomFichier,"a");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier %s.\n",nomFichier);
                return;
            }
            fprintf(file,"ID PAIEMENT : %s\nDATE PAIEMENT : %d/%d/%d\nID CONTRAT : %s\nID GESTIONNAIRE : %s\n",p.id,p.datePaiement.jours,p.datePaiement.mois,p.datePaiement.annee,p.idContrat,p.idGestionnaire);
            fclose(file);
            file = fopen("paiement.bin", "ab");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier %s.\n",nomFichier);
                return;
            }
            fseek(file, 0, SEEK_CUR);
            fwrite(&p, sizeof(PAIEMENT), 1, file);
            fclose(file);


            printf("\nLe payement a ete ajoute avec succes.\n");
            Sleep(2000);
            system("cls");




}*/
void enregistrementPaiement() {
    PAIEMENT p;
    char idSelectionneClient[20], idSelectionneContrat[20], nomFichier[50],nomFacture[50],idLocation[20];
    int pa = incrementerPaiement();
    int montantPaie;
    FILE* file = NULL;
    LOCATION l;
    // Récupérer la date du système
    time_t t = time(NULL);
    struct tm* timeinfo = localtime(&t);

    // Mettre à jour la date de fin du contrat
    p.datePaiement.jours = timeinfo->tm_mday;
    p.datePaiement.mois = timeinfo->tm_mon + 1;
    p.datePaiement.annee = timeinfo->tm_year + 1900;
    strcpy(p.idGestionnaire, cpyIdGestionnaire);
    printf("Choisir un Contrat : \n");
    afficherMenuContrat2();
    faireChoixContrat(idSelectionneContrat);
    copieIdContrat(idSelectionneContrat, idSelectionneClient, idLocation);

    // Vérifier si le paiement pour ce contrat et ce mois existe déjà
    if (verifierPaiementExistant(idSelectionneContrat, p.datePaiement.mois, p.datePaiement.annee)) {
        printf("Un paiement pour ce contrat et ce mois existe deja. Le paiement ne peut etre enregistre.\n");
        Sleep(2000);
        system("cls");
        return;
    }

    strcpy(p.idContrat, idSelectionneContrat);
    sprintf(p.id, "P%d%d%d%d", p.datePaiement.jours, p.datePaiement.mois, p.datePaiement.annee, pa);
    printf("ID : %s\n", p.id);
    sprintf(nomFacture,"FACTURE%d%d%d%d.txt",p.datePaiement.annee, p.datePaiement.mois, p.datePaiement.jours,pa);
    file=fopen("location.bin","rb");


    while (fread(&l, sizeof(LOCATION), 1, file) == 1) {
        if (strcmp(idLocation,l.id)==0) {
            montantPaie=l.prix;
            break;
        }
    }
    fclose(file);
    file=fopen(nomFacture,"a");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return;
    }
    fprintf(file, "ID PAIEMENT : %s\nID CLIENT : %s \nMONTANT PAIEMENT : %d\nDATE PAIEMENT : %d/%d/%d\nID CONTRAT : %s\nID LOCATION : %s\nID GESTIONNAIRE : %s\n", p.id, idSelectionneClient, montantPaie, p.datePaiement.jours, p.datePaiement.mois, p.datePaiement.annee,p.idContrat,idLocation, p.idGestionnaire);
    fclose(file);
    sprintf(nomFichier, "%d%d%d_%s_%s.txt", p.datePaiement.annee, p.datePaiement.mois, p.datePaiement.jours, idSelectionneContrat, idSelectionneClient);
    printf("Nom : %s\n", nomFichier);
    //recuperation du montant paiement




    // Fichier texte pour nomFichier
    file = fopen(nomFichier, "a");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return;
    }
    fprintf(file, "ID PAIEMENT : %s\nDATE PAIEMENT : %d/%d/%d\nID CONTRAT : %s\nID GESTIONNAIRE : %s\n", p.id, p.datePaiement.jours, p.datePaiement.mois, p.datePaiement.annee, p.idContrat, p.idGestionnaire);
    fclose(file);

    file = fopen("paiement.bin", "ab");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier paiement.bin.\n");
        return;
    }
    fseek(file, 0, SEEK_CUR);
    fwrite(&p, sizeof(PAIEMENT), 1, file);
    fclose(file);

    printf("\nLe paiement a ete ajoute avec succes.\n");
    Sleep(2000);
    system("cls");
}



int verifierPaiementExistant(const char* idContrat, int mois, int annee) {
    FILE* fichierPaiement = fopen("paiement.bin", "rb");

    if (fichierPaiement == NULL) {
        printf("Erreur lors de l'ouverture du fichier paiement.bin.\n");
        return 0;
    }

    PAIEMENT p;

    while (fread(&p, sizeof(PAIEMENT), 1, fichierPaiement) == 1) {
        if (strcmp(p.idContrat, idContrat) == 0 && p.datePaiement.mois == mois && p.datePaiement.annee == annee) {
            fclose(fichierPaiement);
            return 1; // Paiement existant trouvé pour le contrat et le mois donnés
        }
    }

    fclose(fichierPaiement);
    return 0; // Aucun paiement existant pour le contrat et le mois donnés
}

void copieIdContrat(char id1[], char id2[], char id3[]) {
    FILE* file = fopen("contrat.bin", "r+b");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    CONTRAT c;
    int index = 1;

    while (fread(&c, sizeof(CONTRAT), 1, file) == 1) {
        if (strcmp(c.id, id1) == 0) {
            fseek(file, -sizeof(CONTRAT), SEEK_CUR);
            strcpy(id1, c.id);
            strcpy(id2, c.idClient);
            strcpy(id3,c.idLocation);
            fseek(file, -sizeof(CONTRAT), SEEK_CUR); // Revenir à la position de départ
            fwrite(&c, sizeof(CONTRAT), 1, file);
            fclose(file);
            return;
        }

        index++;
    }

    fclose(file);
}


void afficherMenuContrat2() {
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
        //AFFICHER UNIQUEMENT LES CONTRATS EN COURS
        if(c.date_FIN.jours==0 && c.date_FIN.mois==0 && c.date_FIN.annee==0){
            printf("%d. %s\n", index, c.id);
            index++;
        }
    }

    printf("0. Accueil\n");
    printf("==========================\n");

    fclose(file);
}
