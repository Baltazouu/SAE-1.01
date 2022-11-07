/*
* \file gestion.c
* \brief fonctions de gestions des adherents
*/

#include <stdio.h>
#include "utilitaire.h"
#include "saisie.h"
#include "affichage.h"

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


void EntreeAdhe(int nbAdhe,int Tnum[],int Tetat[],int TnbPoints[])
{       
    int nbAct=10;   // nombre d'activités
    int TnumAct[10]={1,2,3,4,5,6,7,8,9,10};        // Tnuméros Activités
    int TCact[10]={25,15,15,12,15,20,25,10,10,10};// TCouts activités
    int pos,presence,numAct;
    int numAdhe;
    saisieEntrAdhe(&numAdhe);
    pos=rechercheNombre(numAdhe,Tnum,&presence,nbAdhe);
    if (presence==0)
    {
        printf("[EntrAdhe] Erreur !! Le Numéro Spécifé N'est Pas Dans La Base !\n");
        return;
    }
    if (Tetat[pos]==0)
    {
        printf("[EntrAdhe] Erreur !! Carte N°%d Désactivée Entrée Impossible\n",Tnum[pos]);
        return;
    }
    printf("\n[EntrAdhe] Carte N°%d, %d Points Restants",Tnum[pos],TnbPoints[pos]);
    affInfoAct();
    saisieAct(&numAct);
    rechercheNombre(numAct,TnumAct,&presence,nbAct);
    while (presence==0)
    {
        printf("[EntrAdhe] Erreur !! Le Numéro Spécifié N'est Pas Dans La Liste\n");
        saisieAct(&numAct);
        rechercheNombre(numAct,TnumAct,&presence,nbAct);
    }
    if (TCact[numAct-1]>TnbPoints[pos])
    {
        printf("[EntrAdhe] Erreur !! Vous Ne Disposez Pas D'assez De Points Pour Réaliser Cette Activité !\n");
        return;
    }
    TnbPoints[pos]-=TCact[numAct-1];
    int rep;
    saisie2ndAct(&rep);
    while (rep)
    {   
        printf("\n[EntrAdhe] Carte N°%d, %d Points Restants",Tnum[pos],TnbPoints[pos]);
        affInfoAct();
        saisieAct(&numAct);
        rechercheNombre(numAct,TnumAct,&presence,nbAct);
        while (presence==0)
        {
            printf("[EntrAdhe] Erreur !! Le Numéro Spécifié N'est Pas Dans La Liste !\n");
            saisieAct(&numAct);
            rechercheNombre(numAct,TnumAct,&presence,nbAct);
        }
        if (TCact[numAct-1]>TnbPoints[pos])
        {
        printf("[EntrAdhe] Erreur !! Vous Ne Disposez Pas D'assez De Points Pour Réaliser Cette Activité !\n");
        return;
        }
        TnbPoints[pos]-=TCact[numAct-1];
        saisie2ndAct(&rep);
    }
    return;
}