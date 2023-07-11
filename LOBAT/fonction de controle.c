#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lobat.h"


/*
    Dans cette page nous allons mettre toutes les fonctions
    et procedures qui permettront de mettre les verifications necessaires et
    les controles des donnees à saisir
*/

//VERIFINT DEBUT
/*
    permet de verifier si la saisie est un entier
*/
int verifInt(char charInt[]){
    int i,verif,numInt;

    do{
        fflush(stdin);
        gets(charInt);
        verif=0;
        for(i=0;i<myStrlen(charInt);i++){
            if(charInt[i]<'0' || charInt[i]>'9'){
                verif=1;
                break;
            }
        }
        if(verif==1){
            printf("Faut saisir un entier\n");
        }

    }while(verif==1);
    numInt = atoi(charInt);
    return numInt;

}
int verifCIN(char ch[]){
    int i;
    if(myStrlen(ch)!=13){
        return 1;
    }else{
        for(i=0;i<myStrlen(ch);i++){
            if(ch[i]<'0' && ch[i]>'9'){
                return 1;
            }
        }
    }
    return 0;
}

//VERIFINT FIN

//MYSTRLEN DEBUT

int myStrlen(char ch[]){
    int length=0;
    while(ch[length]!='\0'){
        length++;
    }
    return length;
}

//MYSTRLEN FIN

//CONVERTION MINUSCULE DEBUT
char myLowerCase(char ch){

    if(ch>='A' && ch<='Z'){
        ch=ch+32;
    }

    return ch;
}

//CONVERTION MINUSCULE FIN
//CONVERTION MINUSCULE DEBUT
char myUpperCase(char ch){

    if(ch>='a' && ch<='z'){
        ch=ch-32;
    }

    return ch;
}

//CONVERTION MINUSCULE FIN

//MYSTRCMP DEBUT
int myStrCmp(char ch1[], char ch2[]){
    int i;
    if(myStrlen(ch1)>myStrlen(ch2)){
        return 1;
    }else if(myStrlen(ch1)<myStrlen(ch2)){
        return -1;
    }else{
        for(i=0;i<myStrlen(ch1);i++){
            if(ch1[i]!=ch2[i]){
                return -1;
            }
        }
    }
    return 1;
}
//MYSTRCMP FIN

//MYSTRNCMP DEBUT
int myStrnCmp(char ch1[], char ch2[],int n){
    int i;
    for(i=0;i<n;i++){
        if(ch1[i]!=ch2[i]){
            return -1;
        }
    }

    return 1;
}
//MYSTRNCMP FIN
//MYSTRSTR DEBUT
/*
    compar
*/
int myStrStr(char ch1[], char ch2[]) {
    int i, j, k;

    for (i = 0; ch1[i] != '\0'; i++) {
        j = 0;
        k = i;

        while (ch1[k] == ch2[j] && ch2[j] != '\0') {
            k++;
            j++;
        }

        if (ch2[j] == '\0') {
            return 0; // Sous-chaîne trouvée
        }
    }

    return 1; // Sous-chaîne non trouvée
}
//MYSTRSTR FIN

//MYSTRCASECMP DEBUT
int myStrCaseCmp(char ch1[], char ch2[]){
    int i;
    if(myStrlen(ch1)>myStrlen(ch2)){
        return 1;
    }else if(myStrlen(ch1)<myStrlen(ch2)){
        return -1;
    }else{
        for(i=0;i<myStrlen(ch1);i++){
            if(myLowerCase(ch1[i])!=myLowerCase(ch2[i])){
                return -1;
            }
        }
    }
    return 1;
}
//MYSTRCASECMP FIN

//INCREMENTATION LOGIN DEBUT
void incrementerUser(int* i) {

    FILE* file = fopen("compteurUser.bin", "rb");
    if (file != NULL) {
        fread(i, sizeof(int), 1, file);
        fclose(file);
    }

    (*i)++;

    file = fopen("compteurUser.bin", "wb");
    if (file != NULL) {
        fwrite(i, sizeof(int), 1, file);
        fclose(file);
    }
}
void incrementerBailleur(int* j) {

    FILE* file = fopen("compteurBailleur.bin", "rb");
    if (file != NULL) {
        fread(j, sizeof(int), 1, file);
        fclose(file);
    }

    (*j)++;

    file = fopen("compteurBailleur.bin", "wb");
    if (file != NULL) {
        fwrite(j, sizeof(int), 1, file);
        fclose(file);
    }
}
void incrementerLocation(int* l) {

    FILE* file = fopen("compteurLocation.bin", "rb");
    if (file != NULL) {
        fread(l, sizeof(int), 1, file);
        fclose(file);
    }

    (*l)++;

    file = fopen("compteurLocation.bin", "wb");
    if (file != NULL) {
        fwrite(l, sizeof(int), 1, file);
        fclose(file);
    }
}
void incrementerClient(int* c) {

    FILE* file = fopen("compteurClient.bin", "rb");
    if (file != NULL) {
        fread(c, sizeof(int), 1, file);
        fclose(file);
    }

    (*c)++;

    file = fopen("compteurClient.bin", "wb");
    if (file != NULL) {
        fwrite(c, sizeof(int), 1, file);
        fclose(file);
    }
}
int incrementerContrat() {
    FILE* file = fopen("compteurContrat.bin", "rb+");
    int co;

    if (file == NULL) {
        // Le fichier n'existe pas, initialiser co à 0
        co = 0;
        file = fopen("compteurContrat.bin", "wb");
        fwrite(&co, sizeof(int), 1, file);
        fclose(file);
    } else {
        // Le fichier existe, lire la valeur de co
        fread(&co, sizeof(int), 1, file);
        co++;
        fseek(file, 0, SEEK_SET);
        fwrite(&co, sizeof(int), 1, file);
        fclose(file);
    }

    return co;
}

int incrementerPaiement() {
    FILE* file = fopen("compteurPaiement.bin", "rb+");
    int pa;

    if (file == NULL) {
        // Le fichier n'existe pas, initialiser pa à 0
        pa = 0;
        file = fopen("compteurPaiement.bin", "wb");
        fwrite(&pa, sizeof(int), 1, file);
        fclose(file);
    } else {
        // Le fichier existe, lire la valeur de pa
        fread(&pa, sizeof(int), 1, file);
        pa++;
        fseek(file, 0, SEEK_SET);
        fwrite(&pa, sizeof(int), 1, file);
        fclose(file);
    }

    return pa;
}



//INCREMENTATION LOGIN FIN

//VERIF PHONE NUMBER DEBUT
/*
    permet de verifier si le numero de telephone est  bon
    return 1 si mauvais et 0 si bon
*/
int verifPhoneNumber(char numb[]){
    int i;
    if(myStrlen(numb)!=9){
        return 1;
    }
    for(i=0;i<myStrlen(numb);i++){
        if(numb[i]<'0' || numb[i]>'9'){
            return 1;
        }
    }
    if(myStrnCmp(numb,"70",2)==-1 && myStrnCmp(numb,"75",2)==-1 && myStrnCmp(numb,"76",2)==-1 && myStrnCmp(numb,"77",2)==-1 && myStrnCmp(numb,"78",2)==-1){
        return 1;
    }
    return 0;

}


//VERIF PHONE NUMBER FIN

//VERIF MAIL DEBUT
/*
    permet de verifier si l'email est  bon(se termine par "@gmail.com" et ne contient que des chiffres et des lettres
    return 1 si mauvais et 0 si bon
*/
int verifMail(char mail[]){
    int i;
    if(myStrStr(mail,"@gmail.com")==1){
        return 1;
    }
    for(i=0;i<myStrlen(mail)-10;i++){
        if((mail[i]<'a' || mail[i]>'z') && (mail[i]<'A' || mail[i]>'Z') && (mail[i]<'0' || mail[i]>'9')){
            return 1;
        }
    }
    return 0;

}


//VERIF MAIL FIN


//VERIF LETTRE DEBUT
/*
    permet de verifier par exemple nom et prenom ne contiennent que des lettres
    return 1 si mauvais et 0 si bon
*/
int verifLetter(char ch[]){
    int i;
    if(myStrlen(ch)<2){
        return 1;
    }
    for(i=0;i<myStrlen(ch);i++){
        if((ch[i]<'a' || ch[i]>'z') && (ch[i]<'A' || ch[i]>'Z')){
            return 1;
        }
    }
    return 0;

}


//VERIF MAIL FIN

//VERIF PASSWORD DEBUT
int verifierMotDePasse(char motDePasse[]) {
    int longueur = myStrlen(motDePasse);
    int cpt=0,verif;
    int i;

    if (longueur < 8) {
        puts("Au moins 8 caracteres");
        return 1; // Mot de passe trop court
    }
    for(i=0;i<longueur;i++){
        if(motDePasse[i]>='a' && motDePasse[i]<='z'){
            cpt++;
            verif=0;
            break;
        }else{
            verif=1;
        }
    }
    if(verif==1){
        puts("Abscence de Minuscule");
        verif=0;
    }
    for(i=0;i<longueur;i++){
        if(motDePasse[i]>='A' && motDePasse[i]<='Z'){
            cpt++;
            verif=0;
            break;
        }else{
            verif=1;
        }
    }
    if(verif==1){
        puts("Abscence de Majuscule");
        verif=0;
    }
    for(i=0;i<longueur;i++){
        if(motDePasse[i]>='0' && motDePasse[i]<='9'){
            cpt++;
            verif=0;
            break;
        }else{
            verif=1;
        }
    }
    if(verif==1){
        puts("Abscence de Chiffre");
        verif=0;
    }
    for(i=0;i<longueur;i++){
        if(motDePasse[i]=='@' || motDePasse[i]=='$' || motDePasse[i]=='*' || motDePasse[i]=='-' || motDePasse[i]=='&' || motDePasse[i]=='#' || motDePasse[i]=='_'){ // "@$*-_&#"
            cpt++;
            verif=0;
            break;
        }else{
            verif=1;
        }
    }
    if(verif==1){
        puts("Abscence de Caractere speciale (@$*-_&#)");
        verif=0;
    }



    if (cpt==4) {
        return 0; // Mot de passe valide
    } else {
        return 1; // Mot de passe invalide
    }
}


//VERIF PASSWORD FIN



DATES scanDate(char chaine[]){
    DATES date;
    int i=0;
    do{
        gets(chaine);
        sscanf(chaine,"%d/%d/%d",&date.jours ,&date.mois,&date.annee);
        if(i!=0){
            if((date.jours<=0 || date.jours>31) || (date.mois<=0 || date.mois>12) || (date.annee<0)){
                puts("ERREUR, veuillez reessayer");
            }
        }
        i++;
    } while ((date.jours<=0 || date.jours>31) || (date.mois<=0 || date.mois>12) || (date.annee<0));

    return date;

}

int estDateAnterieure(DATES dateSaisie, DATES dateActuelle) {
    if (dateSaisie.annee < dateActuelle.annee) {
        return 1;
    } else if (dateSaisie.annee == dateActuelle.annee) {
        if (dateSaisie.mois < dateActuelle.mois) {
            return 1;
        } else if (dateSaisie.mois == dateActuelle.mois) {
            if (dateSaisie.jours < dateActuelle.jours) {
                return 1;
            }
        }
    }

    return 0;
}
