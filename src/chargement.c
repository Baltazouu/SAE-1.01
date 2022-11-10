/*
* \file chargement.c
* \brief fonctions de chargements
*
*   SAE 1.01
*/

#include <stdio.h>

#include "config.h"

/**
* Ouvre le fichier "adherents.txt" en lecture et test si tout c'est bien passé.
* Lit dans ce fichier chaque ligne et récupère et place les données de chaque
* colones des tableaux, en gardant le nombre d'élement chargés dans les tableaux.
*/
int chargement(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[],int tPtUtils[], int tmax)
{
    FILE *fl;
    fl = fopen("data/adherents.txt","r");
    if (fl == NULL) { printf("[chargement] Erreur: Ouverture Fichier.\n"); return -1; }

    int num, etat, nbPoints, cat,ptutils;
    int i = 0;

    fscanf(fl,"%d %d %d %d %d",&num,&etat,&nbPoints,&cat,&ptutils);
    while (!feof(fl))
    {
        if (i == tmax) { fclose(fl); return -2; }

        Tnum[i] = num;
        Tetat[i] = etat;
        TnbPoints[i] = nbPoints + AJT_PTS_CHARG;
        Tcat[i] = cat;
        tPtUtils[i] = ptutils;

        fscanf(fl,"%d %d %d %d %d",&num,&etat,&nbPoints,&cat,&ptutils);
        i++;
    }

    fclose(fl);
    return i;
}

/**
* Ouvre le fichier "adherents.txt" en écriture et test si tout c'est bien passé.
* Clone les tableaux dans le dossier à l'inverse de la fonction de chargement.
*/
int sauvegarde(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[],int tPtUtils[], int nbAdhe)
{
    FILE *fl;
    fl = fopen("data/adherents.txt","w");
    if (fl == NULL) { printf("[sauvegarde] Erreur: Ouverture Fichier.\n"); return -1; }

    int i;
    for (i = 0; i < nbAdhe; i++) {
        fprintf(fl, "%d\t%d\t%d\t%d\t%d\n", Tnum[i], Tetat[i], TnbPoints[i], Tcat[i],tPtUtils[i]);
    }

    fclose(fl);
    return 0;
}
