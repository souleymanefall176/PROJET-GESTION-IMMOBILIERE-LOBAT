#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Voici un exemple d'algorithme simple de chiffrement en utilisant un décalage de caractères (également connu sous le nom de chiffrement de César) en langage C :
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

L'algorithme de chiffrement de César est une technique de chiffrement par décalage très simple. Il a été utilisé par Jules César pour protéger ses communications militaires.

L'idée principale de l'algorithme de chiffrement de César est de décaler chaque lettre du texte en clair d'un certain nombre de positions vers la droite dans l'alphabet. Ce décalage est également appelé "clé de chiffrement" ou "décalage de César".

Voici les étapes de l'algorithme de chiffrement de César :

1. Prendre le texte en clair à chiffrer.
2. Prendre un décalage (clé de chiffrement) qui représente le nombre de positions à décaler chaque lettre.
3. Parcourir chaque lettre du texte en clair.
4. Si la lettre est une lettre majuscule (A-Z), décaler la lettre de la clé de chiffrement positions vers la droite dans l'alphabet. Si le décalage dépasse Z, revenir au début de l'alphabet.
5. Si la lettre est une lettre minuscule (a-z), décaler la lettre de la clé de chiffrement positions vers la droite dans l'alphabet. Si le décalage dépasse z, revenir au début de l'alphabet.
6. Répéter les étapes 4 et 5 pour chaque lettre du texte en clair.
7. Le texte chiffré est le résultat obtenu après le décalage de toutes les lettres.

Pour déchiffrer un texte chiffré avec l'algorithme de chiffrement de César, il suffit d'effectuer un décalage de la clé de chiffrement en sens inverse (vers la gauche) pour revenir au texte en clair d'origine.

Il est important de noter que l'algorithme de chiffrement de César est très vulnérable aux attaques par force brute, car il n'y a que 26 décalages possibles (pour l'alphabet anglais). Par conséquent, il n'est pas adapté à une utilisation réelle où la sécurité des données est primordiale. Cependant, il peut être utilisé comme exemple pédagogique pour comprendre les concepts de base du chiffrement par décalage.

*/
