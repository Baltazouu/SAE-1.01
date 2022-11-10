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
    printf("\n%s[Gestion d'un complexe sportif]%s\n\n", STY_FCYAN, STY_NULL);

    printf("%sCommande :  \e[0m", STY_BWHITE);
    for (int i = 0; i < 60; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_TOPR);

    printf("%s\t%s0%s # Afficher ce menu\t\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s1%s # Créer un nouvel adhérent\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s2%s # Supprimer un adherent\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s3%s # Alimenter une carte\t\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s4%s # Activer une carte\t\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s5%s # Désactiver une carte\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s6%s # Afficher les informations d'un adherent\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s7%s # Afficher les informations de tout les adhérents\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s8%s # Afficher le nombre d'entrées par activité dans la journée\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s9%s # Saisir entrée d'un adhérent\t\t\t\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    printf("%s\t%s10%s # Quitter la gestion du centre (fin de journée)\t\t%s\n", BOX_VERT, STY_BOLD, STY_NULL, BOX_VERT);
    
    printf("%s", BOX_BOTL); for (int i = 0; i < 71; i++) printf("%s", BOX_HORI); printf("%s\n", BOX_BOTR);
    printf("\n");
}

/**
* Recherche l'adherent grace à la fonciton recherche, test si il existe et si
* c'est le cas, affiche les information le concernant.
*/
void affInfoAdhe(int numAdhe, int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int TnbEntr[], int nbAdhe)
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("%s[affInfoAdhe] erreur:%s numéro adherent non valide.\n", STY_FRED, STY_NULL);
        return;
    }

    printf("\n");
    printf("%s[affInfoAdhe]%s N° adherent :\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, Tnum[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s Etat de la carte :\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, Tetat[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s Nombre de points :\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, TnbPoints[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s N° catégorie :\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, Tcat[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s Nb de passage :\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, TnbEntr[ins], STY_NULL);
}

/**
* Affiche sous forme de tableau tous les adhérents du club et les information
* les concernants.
*/
void affInfoTous(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int nbAdhe)
{
    printf("%s[affInfoTous]%s %sinformations générales : %s", STY_FBLUE, STY_NULL, STY_BWHITE, STY_NULL);
    for (int i = 0; i < 27; i++) printf("%s", BOX_HORI);
    printf("\n\n");

    printf("\t%s", BOX_TOPL);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 7; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_TOPR);

    printf("\t%s%s N°adhérent%s\t%s %sEtat%s\t%s %sNb de pts%s\t%s %sN°catégorie%s\t%s\n", BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT);
    printf("\t%s", BOX_VERR);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 7; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_VERL);

    for (int i = 0; i < nbAdhe; i++)
        printf("\t%s   %d\t%s   %d\t%s   %d\t\t%s     %d\t\t%s\n", BOX_VERT, Tnum[i], BOX_VERT, Tetat[i], BOX_VERT, TnbPoints[i], BOX_VERT, Tcat[i], BOX_VERT);

    printf("\t%s", BOX_BOTL);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_UPHO);
    for (int i = 0; i < 7; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_UPHO);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_UPHO);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_BOTR);
}
/**
 * Affiche les activités disponibles et leurs coût
*/
void affInfoAct(void)
{   
    printf("\n");
    printf("%s[SaiseAct]%s Entrez Le Numéro D'activité Correspondant :\n", STY_FBLUE, STY_NULL);
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
    
    printf("%s[AffichEntrAct]%s Nombres d'entrées de la journée :\n", STY_FBLUE, STY_NULL);
    printf("------------------------------------------------------\n\n");
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
