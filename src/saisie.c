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
    printf("[alimCarte] Saisir le numéro Adherent :\t");
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
