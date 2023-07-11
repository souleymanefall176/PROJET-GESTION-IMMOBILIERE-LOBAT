#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lobat.h"


//ajouter un nouveau client
/*
void ajouterClient(){
    CLIENT cl;
    int c = 0;
    char tel[10],CIN[14],mail[75];
    char idClient[20];
    incrementerClient(&c);
    puts("============================== NOUVEAU CLIENT ==============================");

    do{
        fflush(stdin);
        printf("Nom : ");
        gets(cl.nom);
        if(myStrlen(cl.nom)>19 || verifLetter(cl.nom)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(cl.nom)>19 || verifLetter(cl.nom)!=0);
    do{
        fflush(stdin);
        printf("Prenom : ");
        gets(cl.prenom);
        if(myStrlen(cl.prenom)>19 || verifLetter(cl.prenom)){
            printf("Erreur : Veuillez reessayer\n");
        }
    }while(myStrlen(cl.prenom)>19 || verifLetter(cl.prenom)!=0);
    do {
        fflush(stdin);
        printf("Tel : ");
        gets(cl.tel);
        if (verifPhoneNumber(cl.tel) != 0) {
            puts("Numero de Telephone incorrecte");
        }
        strcpy(tel, cl.tel);
    } while (verifPhoneNumber(cl.tel) != 0 || verifUniciteTelClient(tel, cl.id) == 1);
    do{
        fflush(stdin);
        printf("Email : ");
        gets(cl.email);
        if(verifMail(cl.email)!=0){
            puts("Adresse Mail incorrecte");
        }
        strcpy(mail,cl.email);
    }while(verifMail(cl.email)!=0 || verifUniciteMailClient(mail,cl.id)==1);
    do{
        fflush(stdin);
        printf("CIN : ");
        gets(cl.CIN);
        if(verifCIN(cl.CIN)!=0){
            puts("CIN incorrecte");
        }
        strcpy(CIN,cl.CIN);
    }while(verifCIN(cl.CIN)!=0 || verifUniciteCINClient(CIN, cl.id) == 1);
    strcpy(cl.idGestionnaire,cpyIdGestionnaire);
    sprintf(cl.id,"C%c%c%c%c%d",myUpperCase(cl.prenom[0]),myUpperCase(cl.nom[0]),myUpperCase(cl.nom[1]),(myStrlen(cl.nom)>3)?myUpperCase(cl.nom[2]):'@',c);
    printf("ID : %s\n",cl.id);
    strcpy(idClient,cl.id);
    FILE *file=fopen("client.bin","ab");
    fwrite(&cl,sizeof(CLIENT),1,file);
    fclose(file);
    puts("client ajouter avec succe!!!");
    Sleep(2000);
    system("cls");
    ajouterContrat2(idClient);
}
*/
void ajouterClient() {
    CLIENT cl;
    int c = 0;
    char tel[10], CIN[14], mail[75];
    char idClient[20];
    incrementerClient(&c);
    puts("============================== NOUVEAU CLIENT ==============================");
     // Vérification des contrats pour les locations
    int tousContratsExistants = 1; // Variable pour vérifier si tous les contrats existent pour les locations

    FILE* fichierContrat = fopen("contrat.bin", "rb");
    FILE* fichierLocation = fopen("location.bin", "rb");

    if (fichierContrat != NULL && fichierLocation != NULL) {
        LOCATION location;
        while (fread(&location, sizeof(LOCATION), 1, fichierLocation) == 1) {
            int contratExiste = 0;
            fseek(fichierContrat, 0, SEEK_SET);
            CONTRAT contrat;
            while (fread(&contrat, sizeof(CONTRAT), 1, fichierContrat) == 1) {
                if (strcmp(location.id, contrat.idLocation) == 0) {
                    contratExiste = 1;
                    break;
                }
            }

            if (!contratExiste) {
                tousContratsExistants = 0;
                break;
            }
        }

        fclose(fichierContrat);
        fclose(fichierLocation);
    } else {
        printf("Impossible d'ouvrir les fichiers contrat.bin et location.bin.\n");
        return;
    }

    if (tousContratsExistants) {
        printf("Impossible d'ajouter un client. Toutes les locations ont un contrat.\n");
        Sleep(2000);
        system("cls");
        return;
    }
    do {
        fflush(stdin);
        printf("Nom : ");
        gets(cl.nom);
        if (myStrlen(cl.nom) > 19 || verifLetter(cl.nom)) {
            printf("Erreur : Veuillez réessayer\n");
        }
    } while (myStrlen(cl.nom) > 19 || verifLetter(cl.nom) != 0);

    do {
        fflush(stdin);
        printf("Prenom : ");
        gets(cl.prenom);
        if (myStrlen(cl.prenom) > 19 || verifLetter(cl.prenom)) {
            printf("Erreur : Veuillez réessayer\n");
        }
    } while (myStrlen(cl.prenom) > 19 || verifLetter(cl.prenom) != 0);

    do {
        fflush(stdin);
        printf("Tel : ");
        gets(cl.tel);
        if (verifPhoneNumber(cl.tel) != 0) {
            puts("Numero de Telephone incorrecte");
        }
        strcpy(tel, cl.tel);
    } while (verifPhoneNumber(cl.tel) != 0 || verifUniciteTelClient(tel, cl.id) == 1);

    do {
        fflush(stdin);
        printf("Email : ");
        gets(cl.email);
        if (verifMail(cl.email) != 0) {
            puts("Adresse Mail incorrecte");
        }
        strcpy(mail, cl.email);
    } while (verifMail(cl.email) != 0 || verifUniciteMailClient(mail, cl.id) == 1);

    do {
        fflush(stdin);
        printf("CIN : ");
        gets(cl.CIN);
        if (verifCIN(cl.CIN) != 0) {
            puts("CIN incorrecte");
        }
        strcpy(CIN, cl.CIN);
    } while (verifCIN(cl.CIN) != 0 || verifUniciteCINClient(CIN, cl.id) == 1);

    strcpy(cl.idGestionnaire, cpyIdGestionnaire);
    sprintf(cl.id, "C%c%c%c%c%d", myUpperCase(cl.prenom[0]), myUpperCase(cl.nom[0]), myUpperCase(cl.nom[1]), (myStrlen(cl.nom) > 3) ? myUpperCase(cl.nom[2]) : '@', c);
    printf("ID : %s\n", cl.id);
    strcpy(idClient, cl.id);
    FILE* file = fopen("client.bin", "ab");
    fwrite(&cl, sizeof(CLIENT), 1, file);
    fclose(file);
    puts("client ajouter avec succes!!!");
    Sleep(2000);
    system("cls");
    ajouterContrat2(idClient);
}




void afficherMenuIdClient() {
    FILE* file = fopen("client.bin", "rb");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    CLIENT cl;
    int index = 1;

    printf("========== MENU ==========\n");
    printf("Liste des id des clients :\n");

    while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
        printf("%d. %s\n", index, cl.id);
        index++;
    }

    printf("0. Accueil\n");
    printf("==========================\n");

    fclose(file);
}
//choixMenu
void faireChoixClient(char idSelectionne[]) {
    int choix;
    printf("Choisissez un utilisateur (0 pour quitter) : ");
    scanf("%d", &choix);

    if (choix != 0) {
        FILE* file = fopen("client.bin", "rb");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return;
        }

        CLIENT cl;
        int index = 1;

        while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
            if (index == choix) {
                fclose(file);
                strcpy(idSelectionne, cl.id);
                return;
            }
            index++;
        }

        fclose(file);

        printf("Choix invalide.\n");
    }else{
        accueilGestionnaire();
    }
}
 //MODIFIER UTILISATEUR DEBUT
 void modifierClient(char idSelectionne[] ) {
    //char nom[20],prenom[20],password[65],tel[10],email[75],userType[15];

    FILE* file = fopen("client.bin", "r+b");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    CLIENT cl;
    char tel[10],CIN[14],mail[75];
    int index = 1;

    while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
        if (strcmp(cl.id, idSelectionne) == 0) {
            fseek(file, -sizeof(CLIENT), SEEK_CUR);
            do{
                fflush(stdin);
                printf("Nom : ");
                gets(cl.nom);
                if(myStrlen(cl.nom)>19 || verifLetter(cl.nom)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(cl.nom)>19 || verifLetter(cl.nom)!=0);
            do{
                fflush(stdin);
                printf("Prenom : ");
                gets(cl.prenom);
                if(myStrlen(cl.prenom)>19 || verifLetter(cl.prenom)){
                    printf("Erreur : Veuillez reessayer\n");
                }
            }while(myStrlen(cl.prenom)>19 || verifLetter(cl.prenom)!=0);
            do {
                fflush(stdin);
                printf("Tel : ");
                gets(cl.tel);
                if (verifPhoneNumber(cl.tel) != 0) {
                  puts("Numero de Telephone incorrecte");
                }
                strcpy(tel, cl.tel);
            } while (verifPhoneNumber(cl.tel) != 0 || verifUniciteTelClient(tel, cl.id) == 1);
            do{
                fflush(stdin);
                printf("Email : ");
                gets(cl.email);
                if(verifMail(cl.email)!=0){
                    puts("Adresse Mail incorrecte");
                }
                strcpy(mail,cl.email);
            }while(verifMail(cl.email)!=0 || verifUniciteMailClient(mail,cl.id)==1);
            do{
                fflush(stdin);
                printf("CIN : ");
                gets(cl.CIN);
                if(verifCIN(cl.CIN)!=0){
                    puts("CIN incorrecte");
                }
                strcpy(CIN,cl.CIN);
            }while(verifCIN(cl.CIN)!=0 || verifUniciteCINClient(CIN, cl.id) == 1);
            strcpy(cl.idGestionnaire,cpyIdGestionnaire);
            fseek(file, 0, SEEK_CUR);
            fwrite(&cl, sizeof(CLIENT), 1, file);
            fclose(file);
            printf("Client modifie avec succes.\n");
            return;
        }


        index++;
    }

    fclose(file);
}

void afficherIdMenuModClient(char idSelectionne[]) {
    afficherMenuIdClient();
    faireChoixClient(idSelectionne);
    Sleep(2000);
    system("cls");
    modifierClient(idSelectionne);

}

int verifUniciteTelClient(char tel[], char id[]) {
  CLIENT cl;
  FILE *file = fopen("client.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
    if (strcmp(cl.tel, tel) == 0 && strcmp(cl.id, id) != 0) {
      fclose(file);
      printf("Ce numero existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}
int verifUniciteCINClient(char CIN[], char id[]) {
  CLIENT cl;
  FILE *file = fopen("client.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
    if (strcmp(cl.CIN, CIN) == 0 && strcmp(cl.id, id) != 0) {
      fclose(file);
      printf("Ce CIN existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}
int verifUniciteMailClient(char mail[], char id[]) {
  CLIENT cl;
  FILE *file = fopen("client.bin", "rb");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  while (fread(&cl, sizeof(CLIENT), 1, file) == 1) {
    if (strcmp(cl.email, mail) == 0 && strcmp(cl.id, id) != 0) {
      fclose(file);
      printf("Ce mail existe deja.\n");
      return 1;
    }
  }

  fclose(file);
  return 0;
}

