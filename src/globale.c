/*
* \file globale.c
* \brief Lancement des actions
*/

#include <stdio.h>

#include "chargement.h"
#include "gestion.h"
#include "affichage.h"
#include "saisie.h"

#include "config.h"


int globale(void)
{
    int commande, sortie = 0;
    int Tnum[TMAX], Tetat[TMAX], TnbPoints[TMAX], Tcat[TMAX];
    int TnbEntr[NBACT]={0,0,0,0,0,0,0,0,0,0};
    int TnumAdheEntre[TMAX],nbAdheEntre=0;
    int numAdhe, nbAdhe, points, cat;
    int val;

    nbAdhe = chargement(Tnum, Tetat, TnbPoints, Tcat, TMAX);

    printf("\e[1;1H\e[2J"); // escape sequance pour clear la console
    affMenu();
    saisieChoix(&commande);
    printf("\e[1;1H\e[2J"); // clear console
    while (!sortie) {

        if (commande == 1) {
            printf("\n");
            saisieAjoutAdher(&points, &cat);
            val = ajoutAdher(&nbAdhe, points, cat, Tnum, Tetat, TnbPoints, Tcat, TMAX);
            if (val > 0)
                printf("\n%s[ajoutAdher] succes%s: Adhérent n°%d, de cat %d, créé avec %d points.\n",
                       STY_FGREEN, STY_NULL, val, cat, points);
        } 
        else if (commande == 2) {
            printf("\n");
            saisieSuppAdhe(&numAdhe);
            if (!suppAdhe(numAdhe, &nbAdhe, Tnum, Tetat, TnbPoints, Tcat))
                printf("\n[suppAdhe] succes: Adhérent n°%d supprimé.\n",numAdhe);
        } 
        else if (commande == 3) {
            printf("\n");
            saisieAlimCarte(&numAdhe, &points);
            if (!alimCarte(points, numAdhe, nbAdhe, Tnum, Tetat, TnbPoints))
                printf("\n[alimCarte] succes: %d point(s) ajouté à l'adhérent n°%d.\n",
                       points, numAdhe);
        } 
        else if (commande == 4) {
            printf("\n");
            saisieActivationCarte(&numAdhe);
            if (!activationCarte(numAdhe, nbAdhe, Tnum, Tetat))
                printf("\n[activationCarte] succes: Carte n°%d activée.\n",numAdhe);
        } 
        else if (commande == 5) {
            printf("\n");
            saisieActivationCarte(&numAdhe);
            if (!desactivationCarte(numAdhe, nbAdhe, Tnum, Tetat))
                printf("\n[desactivationCarte] succesnbAdhe,Tnum,Tetat,TnbPoints,TnbEntr: Carte n°%d desactivée.\n",numAdhe);
        } 
        else if (commande == 6) {
            printf("\n");
            saisieAffInfoAdhe(&numAdhe);
            affInfoAdhe(numAdhe, Tnum, Tetat, TnbPoints, Tcat, nbAdhe);
        } 
        else if (commande == 7) {
            printf("\n");
            affInfoTous(Tnum, Tetat, TnbPoints, Tcat, nbAdhe);
        } 
        else if (commande == 8) {
            printf("\n");
            affichnbEntrAct(TnbEntr,NBACT);
        } 
        else if (commande==9){
            printf("\n");
            EntreAdhe(nbAdhe,Tnum,Tetat,TnbPoints,Tcat,TnbEntr,TnumAdheEntre,&nbAdheEntre);
        }
        else if (commande == 10)
        {
            printf("\n");
            sortie = 1;
            if (!sauvegarde(Tnum, Tetat, TnbPoints, Tcat, nbAdhe))
                printf("\n[sauvegarde] succes: %d adherents sauvegardés.\n\n",nbAdhe);
        } else if (commande == 0) {
            printf("\n");
            affMenu();
        }
        else {
            printf("\n[gestion] erreur: commande inconnue\n");
            affMenu();
        }

        if (!sortie) {
            printf("\n");
            saisieChoix(&commande);
            printf("\e[1;1H\e[2J"); // clear console
        }
    }

    return 0;
}

int main(void)
{
    return globale();
}
