/*
* \file globale.c
* \brief Lancement des actions
*/

#include <stdio.h>

#include "chargement.h"
#include "gestion.h"
#include "affichage.h"
#include "saisie.h"

#define TMAX 100


int globale(void)
{
    int commande, sortie = 0;
    int Tnum[TMAX], Tetat[TMAX], TnbPoints[TMAX];

    int numAdhe, nbAdhe, points;
    int val;

    nbAdhe = chargement(Tnum, Tetat, TnbPoints, TMAX);
    printf("nbAdhe -> %d", nbAdhe);

    affMenu();
    saisieChoix(&commande);
    while (!sortie) {

        if (commande == 1) {
            printf("\n");
            saisieAjoutAdher(&points);
            val = ajoutAdher(&nbAdhe, points, Tnum, Tetat, TnbPoints, TMAX);
            if (val > 0)
                printf("[ajoutAdher] succes: Adhérent n°%d créé avec %d points.\n",
                       val, points);
        } else if (commande == 2) {
            printf("\n");
            saisieSuppAdhe(&numAdhe);
            if (!suppAdhe(numAdhe, &nbAdhe, Tnum, Tetat, TnbPoints))
                printf("[suppAdhe] succes: Adhérent n°%d supprimé.\n",
                       numAdhe);
        } else if (commande == 3) {
            printf("\n");
            saisieAlimCarte(&numAdhe, &points);
            if (!alimCarte(points, numAdhe, nbAdhe, Tnum, Tetat, TnbPoints))
                printf("[alimCarte] succes: %d point(s) ajouté à l'adhérent n°%d.\n",
                       points, numAdhe);
        } else if (commande == 4) {
            printf("\n");
            saisieActivationCarte(&numAdhe);
            if (!activationCarte(numAdhe, nbAdhe, Tnum, Tetat))
                printf("[activationCarte] succes: Carte n°%d activée.\n",
                       numAdhe);
        } else if (commande == 5) {
            printf("\n");
            saisieActivationCarte(&numAdhe);
            if (!desactivationCarte(numAdhe, nbAdhe, Tnum, Tetat))
                printf("[desactivationCarte] succes: Carte n°%d desactivée.\n",
                       numAdhe);
        } else if (commande == 6) {
            printf("\n");
            saisieAffInfoAdhe(&numAdhe);
            affInfoAdhe(numAdhe, Tnum, Tetat, TnbPoints, nbAdhe);
        } else if (commande == 7) {
            printf("\n");
            affInfoTous(Tnum, Tetat, TnbPoints, nbAdhe);
        } else if (commande == 8) {
            printf("\n");
            printf("[gestion] note: commande non implémentée\n");
        } else if (commande == 9) {
            printf("\n");
            sortie = 1;
            if (!sauvegarde(Tnum, Tetat, TnbPoints, nbAdhe))
                printf("[sauvegarde] succes: %d adherents sauvegardé.\n",
                       nbAdhe);
        } else {
            printf("[gestion] erreur: commande inconnue\n");
        }

        if (!sortie) {
            affMenu();
            saisieChoix(&commande);
        }
    }

    return 0;
}

int main(void)
{
    globale();
}
