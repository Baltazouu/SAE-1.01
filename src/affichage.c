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
void affInfoAdhe(int numAdhe, int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int TnumAdheEntre[], int tPtUtils[], int nbAdhe)
{
    int presence, entree;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    rechercheNombre(numAdhe, TnumAdheEntre, &entree, nbAdhe);
    if (!presence) {
        printf("%s[affInfoAdhe] erreur:%s numéro adherent non valide.\n", STY_FRED, STY_NULL);
        return;
    }

    printf("\n");
    printf("%s[affInfoAdhe]%s N° adherent :\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, Tnum[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s Etat de la carte :\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_FCYAN, Tetat[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s Nombre de points :\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_FGREEN, TnbPoints[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s N° catégorie :\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, Tcat[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s PTS de Fidelité:\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_FYELLOW, tPtUtils[ins], STY_NULL);
    printf("%s[affInfoAdhe]%s Est déjà rentré :\t\t%s%d%s\n", STY_FBLUE, STY_NULL, STY_BOLD, entree, STY_NULL);
}

/**
* Affiche sous forme de tableau tous les adhérents du club et les information
* les concernants.
*/
void affInfoTous(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int tPtUtils[], int nbAdhe)
{
    printf("%s[affInfoTous]%s %sinformations générales : %s", STY_FBLUE, STY_NULL, STY_BWHITE, STY_NULL);
    for (int i = 0; i < 42; i++) printf("%s", BOX_HORI);
    printf("\n\n");

    printf("\t%s", BOX_TOPL);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 7; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_TOPR);

    printf("\t%s%s N°adhérent%s\t%s %sEtat%s\t%s %sNb de pts%s\t%s %sN°catégorie%s\t%s %sPts Fidelité%s  %s\n", BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT);
    printf("\t%s", BOX_VERR);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 7; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_VERL);

    for (int i = 0; i < nbAdhe; i++)
        printf("\t%s     %d\t%s   %d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\n", BOX_VERT, Tnum[i], BOX_VERT, Tetat[i], BOX_VERT, TnbPoints[i], BOX_VERT, Tcat[i], BOX_VERT, tPtUtils[i], BOX_VERT);

    printf("\t%s", BOX_BOTL);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_UPHO);
    for (int i = 0; i < 7; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_UPHO);
    for (int i = 0; i < 15; i++) printf("%s", BOX_HORI);
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
    for (int i = 0; i < 54; i++) printf("%s", BOX_HORI);
    printf("\n\n\t%s\t\t\t\t\t%s\n", BOX_TOPL, BOX_TOPR);
    printf("\t%s\t 1 # Kayak : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_KAYAK,STY_NULL,BOX_VERT);
    printf("\t%s\t 2 # Boxe : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_BOXE,STY_NULL,BOX_VERT);
    printf("\t%s\t 3 # Musculation : %s%d%s points\t%s\n",BOX_VERT,STY_FCYAN,CO_MUSCU,STY_NULL,BOX_VERT);
    printf("\t%s\t 4 # Gym : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_GYM,STY_NULL,BOX_VERT);
    printf("\t%s\t 5 # AquaGym : %s%d%s points\t%s\n",BOX_VERT,STY_FCYAN,CO_AQUAGYM,STY_NULL,BOX_VERT);
    printf("\t%s\t 6 # Vélo : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_VELO,STY_NULL,BOX_VERT);
    printf("\t%s\t 7 # Sqash : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_SQASH,STY_NULL,BOX_VERT);
    printf("\t%s\t 8 # Tennis : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_TENNIS,STY_NULL,BOX_VERT);
    printf("\t%s\t 9 # Basket : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_BASKET,STY_NULL,BOX_VERT);
    printf("\t%s\t 10 # Foot : %s%d%s points\t\t%s\n",BOX_VERT,STY_FCYAN,CO_FOOT,STY_NULL,BOX_VERT);
    printf("\t%s\t\t\t\t\t%s\n\n", BOX_BOTL, BOX_BOTR);
}
/**
 * Affiche le nombre par activités sur ce jour 
*/
void affichnbEntrAct(int TnbEntr[],int tlog)
{   
    printf("%s[AffichEntrAct]%s Nombres d'entrées de la journée :\n", STY_FBLUE, STY_NULL);
    for (int i = 0; i < 50; i++) printf("%s", BOX_HORI);
    printf("\n\n\t%s\t\t\t\t\t%s\n", BOX_TOPL, BOX_TOPR);
    printf("\t%s\t 1 # Kayak : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[0],STY_NULL,BOX_VERT);
    printf("\t%s\t 2 # Boxe : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[1],STY_NULL,BOX_VERT);
    printf("\t%s\t 3 # Musculation : %s%d%s Entrées\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[2],STY_NULL,BOX_VERT);
    printf("\t%s\t 4 # Gym : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[3],STY_NULL,BOX_VERT);
    printf("\t%s\t 5 # AquaGym : %s%d%s Entrées\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[4],STY_NULL,BOX_VERT);
    printf("\t%s\t 6 # Vélo : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[5],STY_NULL,BOX_VERT);
    printf("\t%s\t 7 # Sqash : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[6],STY_NULL,BOX_VERT);
    printf("\t%s\t 8 # Tennis : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[7],STY_NULL,BOX_VERT);
    printf("\t%s\t 9 # Basket : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[8],STY_NULL,BOX_VERT);
    printf("\t%s\t 10 # Foot : %s%d%s Entrées\t\t%s\n",BOX_VERT,STY_FCYAN,TnbEntr[9],STY_NULL,BOX_VERT);
    printf("\t%s\t\t\t\t\t%s\n\n", BOX_BOTL, BOX_BOTR);
}

/**
 * affiche les catégories d'utilisateur disponible
*/
void affInfoCate(void)
{   
    int Tcat[NBCATEADHE]={1,2,3,4};
    char TcatName[][20]={"Etudiant\t\t\t","Mineur\t\t\t","Majeur Salarié\t\t","Retraité\t\t\t"};
    int i;

    printf("%s\n[affInfoTous]%s %sCatégories  D'utilisateurs : \n\n%s", STY_FBLUE, STY_NULL, STY_BWHITE, STY_NULL);
    for ( i = 0; i < 50; i++) printf("%s", BOX_HORI);
    printf("\n\n");

    printf("\t%s", BOX_TOPL);
    for ( i = 0; i < 9; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_DOWH);
    for ( i = 0; i < 29; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_TOPR);

    printf("\t%s%s Numéro%s  %s \t%sCatégorie%s\t\t%s\n", BOX_VERT, STY_FYELLOW, STY_NULL, BOX_VERT, STY_FYELLOW,STY_NULL, BOX_VERT);
    printf("\t%s", BOX_VERR);

    for ( i = 0; i < 9; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_VERH);
    for ( i = 0; i < 29; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_VERL);

    for ( i = 0; i < NBCATEADHE; i++)
        printf("\t%s  %d\t  %s   %s%s\n", BOX_VERT, Tcat[i], BOX_VERT,
         TcatName[i], BOX_VERT);

    printf("\t%s", BOX_BOTL);
    for (int i = 0; i < 9; i++) printf("%s", BOX_HORI);
    printf("%s", BOX_UPHO);
    for (int i = 0; i < 29; i++) printf("%s", BOX_HORI);
    printf("%s\n", BOX_BOTR);
    printf("\n");
}
