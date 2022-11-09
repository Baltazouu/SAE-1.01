/*
* \file saisie.c
* \brief Fonctions de saisie
*/

#include <stdio.h>


void saisieAjoutAdher(int *nbCredits)
{
    printf("[ajoutAdher] Saisir le nombre de crédit :\t");
    scanf("%d", nbCredits);
}

void saisieSuppAdhe(int *numAdhe)
{
    printf("[suppAdhe] Saisir le numéro Adherent :\t");
    scanf("%d", numAdhe);
}

void saisieAlimCarte(int *numAdhe, int *points)
{
    printf("[alimCarte] Saisir le numéro Adherent :\t\t");
    scanf("%d", numAdhe);
    printf("[alimCarte] Saisir le nombre de points :\t");
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
    printf("[affInfoAdhe] Saisir le numéro Adherent :\t");
    scanf("%d", numAdhe);
}

void saisieChoix(int *choix)
{
    printf("[gestion] Saisir le choix :\t");
    scanf("%d", choix);
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