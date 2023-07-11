#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "lobat.h"

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
            afficherMenuContrat();
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




}

void copieIdContrat(char id1[], char id2[]) {
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
            fseek(file, -sizeof(CONTRAT), SEEK_CUR); // Revenir à la position de départ
            fwrite(&c, sizeof(CONTRAT), 1, file);
            fclose(file);
            return;
        }

        index++;
    }

    fclose(file);
}
