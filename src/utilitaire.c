/*
* \file utilitaire.c
* \brief Fonctions utilitaires
*/

#include <stdio.h>
#include "saisie.h"
#include "utilitaire.h"

int rechercheNombre(int nb, int Table[], int *presence, int tlog)
{
    int i;
    for (i = 0; i < tlog; i++) {
        if (Table[i] == nb) { *presence = 1; return i; }
        if (Table[i] > nb) { *presence = 0; return i; }
    }
    *presence = 0; return i;
}

int recherche1ereOccu(int Table[], int tlog, int *val)
{
    int i;
    for (i = 0; i < tlog; i++) {
        if (Table[i] > *val) return i;
        *val += 1;
    }
    return i;
}


int insertionNombre(int nb, int pos, int Table[], int tlog, int tmax)
{
    if (tlog == tmax) {
        printf("[insertionNombre] erreur: taille maximale atteinte.\n");
        return -1;
    }

    int i;
    for (i = tlog; i > pos; i--) {
        Table[i] = Table[i-1];
    }

    Table[pos] = nb;

    return 0;
}

void suppressionNombre(int pos, int Table[], int tlog)
{
    int i;
    for (i = pos; i < tlog; i++) {
        Table[i] = Table[i+i];
    }
}

int VerifEntreeAdhe(int nbAdhe,int Tnum[],int Tetat[],int *numAdhe)
{       
    int presence,pos;
    pos=rechercheNombre(*numAdhe,Tnum,&presence,nbAdhe);
    while (presence==0)
    {
        printf("[EntrAdhe] Erreur !! Le Numéro Spécifé N'est Pas Dans La Base !\n");
        saisieEntrAdhe(numAdhe);// on redemande.
        rechercheNombre(*numAdhe,Tnum,&presence,nbAdhe);
    }
    if (Tetat[pos]==0)
    {
        printf("[EntrAdhe] Erreur !! Carte N°%d Désactivée Entrée Impossible\n",Tnum[pos]);
        return -1;
    }
    return pos;
}

void verifPresenceAct(int numAct,int TnumAct[],int nbAct,int *presence)
{
    rechercheNombre(numAct,TnumAct,presence,nbAct);
    while (*presence==0)
    {
        printf("[EntrAdhe] Erreur !! Le Numéro Spécifié N'est Pas Dans La Liste\n");
        saisieAct(&numAct);
        rechercheNombre(numAct,TnumAct,presence,nbAct);
    }
    return;
}

int VerifnbPRest(int TCact[],int numAct,int TnbPoints[],int posAdhe,int TnbEntr[])
{
    if (TCact[numAct-1]>TnbPoints[posAdhe])
    {
        printf("[EntrAdhe] Erreur !! Vous Ne Disposez Pas D'assez De Points Pour Réaliser Cette Activité !\n");
        return -1;
    }
    TnbPoints[posAdhe]-=TCact[numAct-1];
    TnbEntr[numAct-1]+=1;
    return 0;
}