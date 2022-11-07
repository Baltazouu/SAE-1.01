/*
* \file affichage.c
* \brief fonctions d'affichages
*
*   SAE 1.01
*/

#include <stdio.h>
#include "utilitaire.h"


/**
* Affiche les numéros des fonctions.
*/
void affMenu(void)
{
    printf("\n[Gestion d'un complexe sportif]\n\n");

    printf("Commande :  -------------------------------------------------------\n");
    printf("\t1 # Créer un nouvel adhérent\n");
    printf("\t2 # Supprimer un adherent\n");
    printf("\t3 # Alimenter une carte\n");
    printf("\t4 # Activer une carte\n");
    printf("\t5 # Désactiver une carte\n");
    printf("\t6 # Afficher les informations d'un adherent\n");
    printf("\t7 # Afficher les informations de tout les adhérents\n");
    printf("\t8 # Afficher le nombre d'entrées par activité dnas la journée\n");
    printf("\t9 # Quitter la gestion du centre (fin de journée)\n");
    printf("-------------------------------------------------------------------\n");
    printf("\n");
}

/**
* Recherche l'adherent grace à la fonciton recherche, test si il existe et si
* c'est le cas, affiche les information le concernant.
*/
void affInfoAdhe(int numAdhe, int Tnum[], int Tetat[], int TnbPoints[], int nbAdhe)
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("[affInfoAdhe] erreur: numéro adherent non valide.\n");
        return;
    }

    printf("\n");
    printf("[affInfoAdhe] N° adherent :\t%d\n", Tnum[ins]);
    printf("[affInfoAdhe] Etat de la carte :\t%d\n", Tetat[ins]);
    printf("[affInfoAdhe] Nombre de points :\t%d\n", TnbPoints[ins]);
}

/**
* Affiche sous forme de tableau tous les adhérents du club et les information
* les concernants.
*/
void affInfoTous(int Tnum[], int Tetat[], int TnbPoints[], int nbAdhe)
{
    printf("[affInfoTous] informations générales : ----------------------------\n\n");

    printf("\tN°adhérent\t| Etat\t| Nb de points\n");
    printf("\t---------------------------------------------\n");

    for (int i = 0; i < nbAdhe; i++)
        printf("\t\t%d\t| %d\t| %d\n", Tnum[i], Tetat[i], TnbPoints[i]);

    printf("\t---------------------------------------------\n");
}
