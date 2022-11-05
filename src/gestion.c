/*
* \file gestion.c
* \brief fonctions de gestions des adherents
*/

#include <stdio.h>
#include "utilitaire.h"

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

    *nbAdher -= 1;
    return val;
}

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
