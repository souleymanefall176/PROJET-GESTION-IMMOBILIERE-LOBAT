#include <stdio.h>
#include <stdlib.h>
#include "lobat.h"

/*
pour la modification de l'utilisateur je veux changer le nom,le prenom,le mot de passe et regenerer l'url en se basant sur :  sprintf(user.login,"U%c%c%c%c%d",myUpperCase(user.prenom[0]),myUpperCase(user.nom[0]),myUpperCase(user.nom[1]),(myStrlen(user.nom)>3)?myUpperCase(user.nom[2]):'@',i);*/
int main()
{


    accueil();
    //afficher_informations_contrats();
    //enregistrementPaiement();

    //printf("Verif %d\n",verifierMotDePasse("Passer123@"));

    /*FILE *file = fopen("user.bin", "rb");

    if (file == NULL) {
        printf("Impossible d'ouvrir le file.\n");
        return 1;
    }

    USER utilisateur;

    fread(&utilisateur,sizeof(USER),1,file);
    fread(&utilisateur,sizeof(USER),1,file);
        // Utilisation des valeurs lues
    printf("Nom: %s\n", utilisateur.nom);
    printf("Prenom: %s\n", utilisateur.prenom);
    printf("Login: %s\n", utilisateur.login);
    printf("Mot de passe: %s\n", utilisateur.password);
    printf("Telephone: %s\n", utilisateur.tel);
    printf("Email: %s\n", utilisateur.email);
    printf("\n");


    fclose(file);*/

    return 0;
}
