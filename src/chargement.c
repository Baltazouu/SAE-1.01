/*
* \file chargement.c
* \brief fonctions de chargements
*/

#include <stdio.h>


int chargement(int Tnum[], int Tetat[], int TnbPoints[], int tmax)
{
    FILE *fl;
    fl = fopen("data/adherents.txt","r");
    if (fl == NULL) { printf("[chargement] Erreur: Ouverture Fichier.\n"); return -1; }

    int num, etat, nbPoints;
    int i = 0;

    fscanf(fl,"%d %d %d",&num,&etat,&nbPoints);
    while (!feof(fl))
    {
        if (i == tmax) { fclose(fl); return -2; }

        Tnum[i] = num;
        Tetat[i] = etat;
        TnbPoints[i] = nbPoints;

        fscanf(fl,"%d %d %d",&num,&etat,&nbPoints);
        i++;
    }

    fclose(fl);
    return i;
}

int sauvegarde(int Tnum[], int Tetat[], int TnbPoints[], int nbAdhe)
{
    FILE *fl;
    fl = fopen("data/adherents.txt","w");
    if (fl == NULL) { printf("[sauvegarde] Erreur: Ouverture Fichier.\n"); return -1; }

    int i;
    for (i = 0; i < nbAdhe; i++) {
        fprintf(fl, "%d\t%d\t%d\n", Tnum[i], Tetat[i], TnbPoints[i]);
    }

    fclose(fl);
    return 0;
}
