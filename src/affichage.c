/**
* \file affichage.c
* \brief fonctions d'affichages
*
*   SAE 1.01
*/

#include <stdio.h>
#include "utilitaire.h"

#include "config.h"


/**
* Affiche les numéros des fonctions.
*/
void affMenu(void)
{
    printf("\n%s[Gestion d'un complexe sportif]\e[0m\n\n", STY_FCYAN);

    printf("%sCommande :  \e[0m", STY_BWHITE);
    for (int i = 0; i < 60; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_TOPR);

    printf("%s\t\e[1m0\e[0m # Afficher ce menu\t\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m1\e[0m # Créer un nouvel adhérent\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m2\e[0m # Supprimer un adherent\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m3\e[0m # Alimenter une carte\t\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m4\e[0m # Activer une carte\t\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m5\e[0m # Désactiver une carte\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m6\e[0m # Afficher les informations d'un adherent\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m7\e[0m # Afficher les informations de tout les adhérents\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m8\e[0m # Afficher le nombre d'entrées par activité dans la journée\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m9\e[0m # Saisir entrée d'un adhérent\t\t\t\t\t%s\n", BOX_VERT, BOX_VERT);
    printf("%s\t\e[1m10\e[0m # Quitter la gestion du centre (fin de journée)\t\t%s\n", BOX_VERT, BOX_VERT);
    
    printf("%s", BOX_BOTL); for (int i = 0; i < 71; i++) printf("%s", BOX_HORI); printf("%s\n", BOX_BOTR);
    printf("\n");
}

/**
* Recherche l'adherent grace à la fonciton recherche, test si il existe et si
* c'est le cas, affiche les information le concernant.
*/
void affInfoAdhe(int numAdhe, int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int nbAdhe)
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("[affInfoAdhe] erreur: numéro adherent non valide.\n");
        return;
    }

    printf("\n");
    printf("%s[affInfoAdhe]%s N° adherent :\t\t%d\n", STY_FMAGEN, STY_NULL, Tnum[ins]);
    printf("%s[affInfoAdhe]%s Etat de la carte :\t%d\n", STY_FMAGEN, STY_NULL, Tetat[ins]);
    printf("%s[affInfoAdhe]%s Nombre de points :\t%d\n", STY_FMAGEN, STY_NULL, TnbPoints[ins]);
    printf("%s[affInfoAdhe]%s N° catégorie :\t%d\n", STY_FMAGEN, STY_NULL, Tcat[ins]);
}

/**
* Affiche sous forme de tableau tous les adhérents du club et les information
* les concernants.
*/
void affInfoTous(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int nbAdhe)
{
    printf("%s[affInfoTous]%s %sinformations générales : %s", STY_FMAGEN, STY_NULL, STY_BWHITE, STY_NULL);
    for (int i = 0; i < 27; i++) printf("%s", BOX_HORI);
    printf("\n\n");

    printf("%sN°adhérent\t%s Etat\t%s Nb de pts\t%s N°catégorie%s\n", BOX_VERT, BOX_VERT, BOX_VERT, BOX_VERT, BOX_VERT);
    for (int i = 0; i < 48; i++) printf("%s", BOX_HORI);

    for (int i = 0; i < nbAdhe; i++)
        printf("%s\t%d\t%s %d\t%s %d\t\t%s %d\t%s\n", BOX_VERT, Tnum[i], BOX_VERT, Tetat[i], BOX_VERT, TnbPoints[i], BOX_VERT, Tcat[i], BOX_VERT);

    printf("\n"); for (int i = 0; i < 48; i++) printf("%s", BOX_HORI); printf("\n");
}
/**
 * Affiche les activités disponibles et leurs coût
*/
void affInfoAct(void)
{   
    printf("\n");
    printf("[SaiseAct] Entrez Le Numéro D'activité Correspondant :\n");
    printf("------------------------------------------------------\n\n");
    printf("\t 1 # Kayak : %d points\n", CO_KAYAK);
    printf("\t 2 # Boxe : %d points\n", CO_BOXE);
    printf("\t 3 # Musculation : %d points\n", CO_MUSCU);
    printf("\t 4 # Gym : %d points\n", CO_GYM);
    printf("\t 5 # AquaGym : %d points\n", CO_AQUAGYM);
    printf("\t 6 # Vélo : %d points\n", CO_VELO);
    printf("\t 7 # Sqash : %d points\n", CO_SQASH);
    printf("\t 8 # Tennis : %d points\n", CO_TENNIS);
    printf("\t 9 # Basket : %d points\n", CO_BASKET);
    printf("\t 10 # Foot : %d points\n", CO_FOOT);
    printf("\n");
}
/**
 * Affiche le nombre par activités sur ce jour 
*/
void affichnbEntrAct(int TnbEntr[],int tlog)
{   
    
    printf("------------------------------------------------------\n\n");
    printf("[AffichEntrAct] Nombres d'entrées de la journée :\n\n");
    printf("\t 1 # Kayak : %d Entrées\n",TnbEntr[0]);
    printf("\t 2 # Boxe : %d Entrées\n",TnbEntr[1]);
    printf("\t 3 # Musculation : %d Entrées\n",TnbEntr[2]);
    printf("\t 4 # Gym : %d Entrées\n",TnbEntr[3]);
    printf("\t 5 # AquaGym : %d Entrées\n",TnbEntr[4]);
    printf("\t 6 # Vélo : %d Entrées\n",TnbEntr[5]);
    printf("\t 7 # Sqash : %d Entrées\n",TnbEntr[6]);
    printf("\t 8 # Tennis : %d Entrées\n",TnbEntr[7]);
    printf("\t 9 # Basket : %d Entrées\n",TnbEntr[8]);
    printf("\t 10 # Foot : %d Entrées\n",TnbEntr[9]);
    printf("\n");
}
