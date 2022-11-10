/*
* \file saisie.c
* \brief Fonctions de saisie
*/

#include <stdio.h>

#include "config.h"

void saisieAjoutAdher(int *nbCredits, int *cat)
{
    printf("%s[ajoutAdher]%s Saisir le nombre de crédit :\t", STY_FBLUE, STY_NULL);
    scanf("%d", nbCredits);
    printf("%s[ajoutAdher]%s Saisir la catégorie :\t", STY_FBLUE, STY_NULL);
    scanf("%d", cat);
}

void saisieSuppAdhe(int *numAdhe)
{
    printf("[suppAdhe] Saisir le numéro Adherent :\t");
    scanf("%d", numAdhe);
}

void saisieAlimCarte(int *numAdhe, int *points)
{
    printf("%s[alimCarte]%s Saisir le numéro Adherent :\t\t", STY_FMAGEN, STY_NULL);
    scanf("%d", numAdhe);
    printf("%s[alimCarte]%s Saisir le nombre de points :\t", STY_FMAGEN, STY_NULL);
    scanf("%d", points);
}

void saisieActivationCarte(int *numAdhe)
{
    printf("[activationCarte] Saisir le numéro Adherent :\t");
    scanf("%d", numAdhe);
}

void saisieDesactivationCarte(int *numAdhe)
{
    printf("[desactivationCarte] Saisir le numéro Adherent :\t");
    scanf("%d", numAdhe);
}

void saisieAffInfoAdhe(int *numAdhe)
{
    printf("%s[affInfoAdhe]%s Saisir le numéro Adherent :\t", STY_FMAGEN, STY_NULL);
    scanf("%d", numAdhe);
}

void saisieChoix(int *choix)
{
    printf("\n%s[gestion]%s Saisir la commande (#0 -menu):       \n", STY_FMAGEN, STY_NULL);
    for (int i = 0; i < 73; i++) printf("%s", BOX_HORI);
    printf("\e[1A\e[25D\e[1,32m");
    scanf("%d", choix);
    printf("\n");
}

void saisieEntrAdhe(int *numadhe)
{
    printf("[EntrAdhe] Saisissez Le Numéro De L'adhérent entrant : ");
    scanf("%d",numadhe);
    printf("\n");
}
void saisieAct(int *numAct)
{
    printf("[EntrAdhe] Saisissez Le Numéro D'activité : ");
    scanf("%d",numAct);
    printf("\n");
}
void saisie2ndAct(int *rep)
{  
    printf("[EntrAdhe] Souhaitez Vous Choisir Une Autre Activité ( 1 : Oui | 0 : Non ) : ");
    scanf("%d",rep);
    printf("\n");
}

void saisieInterdAdhe(int *numAdhe)
{
    printf("[InterdAdhe] Entrez Le Numéro D'adhérent : ");
    scanf("%d",numAdhe);
    printf("\n");
}
