/**
* \file gestion.c
* \brief fonctions de gestions des adherents
*
*   SAE 1.01
*/

#include <stdio.h>
#include "utilitaire.h"


/**
* Utilise la fonction de recherche de la première occurence d'un nombre pas ou
* plus utilisé et l'utilise comme nouvel id.
* Met à jour les trois tableau en insérant dans l'ordre croissant des numéros
* d'adherents le nouvel id, état et nombre de points. (utilisation de la
* fonction d'insertion)
* Met à jour la taille logique du tableau.
*/
int ajoutAdher(int *nbAdher, int nbCredits,
               int Tnum[], int Tetat[], int TnbPoints[], int tmax)
{
    int val = 1001;
    int ins = recherche1ereOccu(Tnum, *nbAdher, &val);

    if (insertionNombre(val, ins, Tnum, *nbAdher, tmax)) {
        printf("[ajoutAdher] erreur: insertion.\n");
        return -1;
    }

    insertionNombre(1, ins, Tetat, *nbAdher, tmax);
    insertionNombre(nbCredits, ins, TnbPoints, *nbAdher, tmax);

    *nbAdher += 1;
    return val;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Met à jour les trois tableau en supprimant les lignes et décalant le reste du
* tableau. (utilisation de la fonction de suppression)
* Met à jour la taille logique du tableau.
*/
int suppAdhe(int numAdhe, int *tlog,
             int Tnum[], int Tetat[], int TnbPoints[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, *tlog);
    if (!presence) {
        printf("[suppAdhe] erreur: numéro adherent non valide.\n");
        return -1;
    }

    suppressionNombre(ins, Tnum, *tlog);
    suppressionNombre(ins, Tetat, *tlog);
    suppressionNombre(ins, TnbPoints, *tlog);

    *tlog -= 1;
    return 0;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Teste si l'id existe et si la carte est active.
* Ajoute le nombre de points donnés en paramètre au nombre de points actuel de
* l'adherent. Ce nombre peut être négatif dans le cas d'un débit de points.
*/
int alimCarte(int points, int numAdhe, int nbAdhe,
              int Tnum[], int Tetat[], int TnbPoints[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("[alimCarte] erreur: numéro adherent non valide.\n");
        return -1;
    }
    if (Tetat[ins] == 0) {
        printf("[alimCarte] erreur: carte désactivée.\n");
        return -2;
    }

    TnbPoints[ins] += points;
    return 0;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Teste si l'id existe.
* Met à jour si besoin l'état de la carte.
*/
int activationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("[activationCarte] erreur: numéro adherent non valide.\n");
        return -1;
    }

    if (Tetat[ins] == 1) {
        printf("[activationCarte] note: carte déjà activée.\n");
        return 0;
    }

    Tetat[ins] = 1;
    return 0;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Teste si l'id existe.
* Met à jour si besoin l'état de la carte.
*/
int desactivationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("[activationCarte] erreur: numéro adherent non valide.\n");
        return -1;
    }

    if (Tetat[ins] == 0) {
        printf("[activationCarte] note: carte déjà desactivée.\n");
        return 0;
    }

    Tetat[ins] = 0;
    return 0;
}
