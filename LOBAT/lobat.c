#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lobat.h"
 /*
    C'est dans cette page qu'on fera la gestion
    1/ (je veux faire d'en sorte que le compte des gestionnaires soient creer par un administrateur
        un administrateur peut creer un compte administrateur et un compte gestionnaire
        un gestionnaire ne peut pas creer de compte mais peut se connecter
 */



 //CHOIX DEBUT
int choix(){
    int numChoix;
    char charInt[20];
    numChoix=verifInt(charInt);
    Sleep(2000);
    system("cls");
    return numChoix;
}
//CHOIX FIN



//CHOIXCONNECTE DEBUT
void choixConnecte(int connecte){


    if(connecte==1){
        accueilAdministrateur();

    }else if(connecte==2){
        accueilGestionnaire();

    }

}
//CHOIXCONNECTE FIN
 //ACCUEIL DEBUT

 /*
    Dans accueil on mettra un menu de connexion ou d'inscription l'utilisateurs aura me droit de se connecter, ou de s'inscrire
    je pense que je vais la remplacer par ce connecter :  donc la suprrimer d'ici
 */
void accueil(){
    int connecte;

    puts("======================================== LOBAT ========================================");

    FILE *file=NULL;
    if(verifFile(file)==1){
        puts("Aucun Utilisateur : Veuillez creer un compte.");
        inscription();
        connecte=connexion();
        choixConnecte(connecte);

    }else{
        connecte=connexion(cpyIdGestionnaire);
        choixConnecte(connecte);

    }




}

//ACCUEIL DEBUT



