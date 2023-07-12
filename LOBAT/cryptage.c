#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Voici un exemple d'algorithme simple de chiffrement en utilisant un d�calage de caract�res (�galement connu sous le nom de chiffrement de C�sar) en langage C :
void chiffrer(char* texteClair, int decalage) {
    int longueur = strlen(texteClair);

    for (int i = 0; i < longueur; i++) {
        if (texteClair[i] >= 'a' && texteClair[i] <= 'z') {
            texteClair[i] = 'a' + (texteClair[i] - 'a' + decalage) % 26;
        } else if (texteClair[i] >= 'A' && texteClair[i] <= 'Z') {
            texteClair[i] = 'A' + (texteClair[i] - 'A' + decalage) % 26;
        }
    }
}

void dechiffrer(char* texteChiffre,int decalage) {
    int longueur = strlen(texteChiffre);

    for (int i = 0; i < longueur; i++) {
        if (texteChiffre[i] >= 'a' && texteChiffre[i] <= 'z') {
            texteChiffre[i] = 'a' + (texteChiffre[i] - 'a' - decalage + 26) % 26;
        } else if (texteChiffre[i] >= 'A' && texteChiffre[i] <= 'Z') {
            texteChiffre[i] = 'A' + (texteChiffre[i] - 'A' - decalage + 26) % 26;
        }
    }
}
/*

L'algorithme de chiffrement de C�sar est une technique de chiffrement par d�calage tr�s simple. Il a �t� utilis� par Jules C�sar pour prot�ger ses communications militaires.

L'id�e principale de l'algorithme de chiffrement de C�sar est de d�caler chaque lettre du texte en clair d'un certain nombre de positions vers la droite dans l'alphabet. Ce d�calage est �galement appel� "cl� de chiffrement" ou "d�calage de C�sar".

Voici les �tapes de l'algorithme de chiffrement de C�sar :

1. Prendre le texte en clair � chiffrer.
2. Prendre un d�calage (cl� de chiffrement) qui repr�sente le nombre de positions � d�caler chaque lettre.
3. Parcourir chaque lettre du texte en clair.
4. Si la lettre est une lettre majuscule (A-Z), d�caler la lettre de la cl� de chiffrement positions vers la droite dans l'alphabet. Si le d�calage d�passe Z, revenir au d�but de l'alphabet.
5. Si la lettre est une lettre minuscule (a-z), d�caler la lettre de la cl� de chiffrement positions vers la droite dans l'alphabet. Si le d�calage d�passe z, revenir au d�but de l'alphabet.
6. R�p�ter les �tapes 4 et 5 pour chaque lettre du texte en clair.
7. Le texte chiffr� est le r�sultat obtenu apr�s le d�calage de toutes les lettres.

Pour d�chiffrer un texte chiffr� avec l'algorithme de chiffrement de C�sar, il suffit d'effectuer un d�calage de la cl� de chiffrement en sens inverse (vers la gauche) pour revenir au texte en clair d'origine.

Il est important de noter que l'algorithme de chiffrement de C�sar est tr�s vuln�rable aux attaques par force brute, car il n'y a que 26 d�calages possibles (pour l'alphabet anglais). Par cons�quent, il n'est pas adapt� � une utilisation r�elle o� la s�curit� des donn�es est primordiale. Cependant, il peut �tre utilis� comme exemple p�dagogique pour comprendre les concepts de base du chiffrement par d�calage.

*/
