/**
* \file saisie.c
* \brief Fonctions de saisie
*
*   SAE 1.01
*/

#include <stdio.h>
#include "affichage.h"
#include "config.h"

/**
 * Fonction saisie de l'ajout d'un adhérent
 *  + test si la catégorie est valide
 */
int saisieAjoutAdher(int *nbCredits, int *cat)
{
    printf("%s[ajoutAdher]%s Saisir le nombre de crédit :\t", STY_FBLUE, STY_NULL);
    scanf("%d", nbCredits);
    affInfoCate();
    printf("%s[ajoutAdher]%s Saisir la catégorie :\t", STY_FBLUE, STY_NULL);
    scanf("%d", cat);
    if (*cat > 4 || *cat < 1)
            {
                printf("%s[ajoutAdher]Erreur !!%s Catégorie inconnue !!",STY_FRED,STY_NULL);
                return -1;
            }
    return 0;
}

/**
 * Fonction saisie pour la suppréssion d'un adhérent
 */
void saisieSuppAdhe(int *numAdhe)
{
    printf("%s[suppAdhe]%s Saisir le numéro Adherent :\t", STY_FBLUE, STY_NULL);
    scanf("%d", numAdhe);
}

/**
 * Fonction saisie pour l'alimentation de la carte
 */
void saisieAlimCarte(int *numAdhe, int *points)
{
    printf("%s[alimCarte]%s Saisir le numéro Adherent :\t\t", STY_FBLUE, STY_NULL);
    scanf("%d", numAdhe);
    printf("%s[alimCarte]%s Saisir le nombre de points :\t", STY_FBLUE, STY_NULL);
    scanf("%d", points);
}

/**
 * Fonction saisie pour l'activation de la carte
 */
void saisieActivationCarte(int *numAdhe)
{
    printf("%s[activationCarte]%s Saisir le numéro Adherent :\t", STY_FBLUE, STY_NULL);
    scanf("%d", numAdhe);
}

/**
 * Fonction saisie pour la desactivation de la carte
 */
void saisieDesactivationCarte(int *numAdhe)
{
    printf("%s[desactivationCarte]%s Saisir le numéro Adherent :\t", STY_FBLUE, STY_NULL);
    scanf("%d", numAdhe);
}

/**
 * Fonction saisie pour l'affichage des inforamtion d'un adhérent
 */
void saisieAffInfoAdhe(int *numAdhe)
{
    printf("%s[affInfoAdhe]%s Saisir le numéro Adherent :\t", STY_FBLUE, STY_NULL);
    scanf("%d", numAdhe);
}

/**
 * Fonction saisie pour le choix dans le menu principal
 */
void saisieChoix(int *choix)
{
    printf("\n%s[gestion]%s Saisir la commande (#0 -menu):       \n", STY_FMAGEN, STY_NULL);
    for (int i = 0; i < 73; i++) printf("%s", BOX_HORI);
    printf("\e[1A\e[5D\e[1,32m");
    scanf("%d", choix);
    printf("\n");
}

/**
 * Fonction saisie pour le numéro d'adhérant entrant
 */
void saisieEntrAdhe(int *numadhe)
{
    printf("%s[EntrAdhe]%s Saisissez Le Numéro De L'adhérent entrant : ", STY_FBLUE, STY_NULL);
    scanf("%d",numadhe);
    printf("\n");
}
/**
 * Fonction saisie pour le numéro d'activité
 */
void saisieAct(int *numAct)
{
    printf("%s[EntrAdhe]%s Saisissez Le Numéro D'activité : ", STY_FBLUE, STY_NULL);
    scanf("%d",numAct);
    printf("\n");
}
/**
 * Fonction saisie pour le numéro d'activité après en avoir déja saisie une
 */
void saisie2ndAct(int *rep)
{  
    printf("%s[EntrAdhe]%s Souhaitez Vous Choisir Une Autre Activité ( %s1%s : Oui | %s0%s : Non ) : ", STY_FYELLOW, STY_NULL, STY_BOLD, STY_NULL, STY_BOLD, STY_NULL);
    scanf("%d",rep);
    printf("\n");
}