/**
* \file gestion.c
* \brief fonctions de gestions des adherents
*
*   SAE 1.01
*/

#include <stdio.h>
#include "gestion.h"
#include "utilitaire.h"
#include "saisie.h"
#include "affichage.h"
#include "config.h"

/**
* Utilise la fonction de recherche de la première occurence d'un nombre pas ou
* plus utilisé et l'utilise comme nouvel id.
* Met à jour les quatre tableaux en insérant dans l'ordre croissant des numéros
* d'adherents le nouvel id, état, nombre de points et catégorie. (utilisation de la
* fonction d'insertion)
* Met à jour la taille logique des tableaux.
*/
int ajoutAdher(int *nbAdher, int nbCredits, int nCat,
               int Tnum[], int Tetat[], int TnbPoints[], int Tcat[],int tPtUtils[],int tmax)
{
    int val = 1001;
    int ins = recherche1ereOccu(Tnum, *nbAdher, &val);

    if (insertionNombre(val, ins, Tnum, *nbAdher, tmax)) {
        printf("%s[ajoutAdher] erreur%s: insertion.\n", STY_FRED, STY_NULL);
        return -1;
    }
    if (nbCredits<1){
        printf("[AjoutAdher] Erreur !! Impossible de créditer des points négatifs !!\n");
        return -1;;
    }
    insertionNombre(1, ins, Tetat, *nbAdher, tmax);
    insertionNombre(nbCredits, ins, TnbPoints, *nbAdher, tmax);
    insertionNombre(nCat, ins, Tcat, *nbAdher, tmax);
    insertionNombre(0,ins,tPtUtils,*nbAdher,tmax);

    *nbAdher += 1;
    return val;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Met à jour les trois tableau en supprimant les lignes et décalant le reste du
* tableau. (utilisation de la fonction de suppression)
* Met à jour la taille logique du tableau.
*/
int suppAdhe(int numAdhe, int *tlog,
             int Tnum[], int Tetat[], int TnbPoints[], int Tcat[],int tPtUtils [])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, *tlog);
    if (!presence) {
        printf("%s[suppAdhe] erreur%s: numéro adherent non valide.\n", STY_FRED, STY_NULL);
        return -1;
    }

    suppressionNombre(ins, Tnum, *tlog);
    suppressionNombre(ins, Tetat, *tlog);
    suppressionNombre(ins, TnbPoints, *tlog);
    suppressionNombre(ins, Tcat, *tlog);
    suppressionNombre(ins,tPtUtils,*tlog);

    *tlog -= 1;
    return 0;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Teste si l'id existe et si la carte est active.
* Ajoute le nombre de points donnés en paramètre au nombre de points actuel de
* l'adherent. Ce nombre peut être négatif dans le cas d'un débit de points.
*/
int alimCarte(int points, int numAdhe, int nbAdhe,
              int Tnum[], int Tetat[], int TnbPoints[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("%s[alimCarte] erreur:%s numéro adherent non valide.\n", STY_FRED, STY_NULL);
        return -1;
    }
    if (Tetat[ins] == 0) {
        printf("%s[alimCarte] erreur:%s carte désactivée.\n", STY_FRED, STY_NULL);
        return -2;
    }

    TnbPoints[ins] += points;
    return 0;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Teste si l'id existe.
* Met à jour si besoin l'état de la carte.
*/
int activationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("%s[activationCarte] erreur:%s numéro adherent non valide.\n", STY_FRED, STY_NULL);
        return -1;
    }

    if (Tetat[ins] == 1) {
        printf("%s[activationCarte] note:%s carte déjà activée.\n", STY_FYELLOW, STY_NULL);
        return 0;
    }
    Tetat[ins] = 1;
    printf("\n%s[activationCarte] succes:%s Carte n°%d activée.\n",STY_FGREEN,STY_NULL,numAdhe);
    return 0;
}

/**
* Utilise la fonction de recherche de nombre dans un tableau pour trouver
* l'existance et la position d'insertion de l'id de l'adherent dans les tableaux.
* Teste si l'id existe.
* Met à jour si besoin l'état de la carte.
*/
int desactivationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, nbAdhe);
    if (!presence) {
        printf("%s[desactivationCarte] erreur:%s numéro adherent non valide.\n", STY_FRED, STY_NULL);
        return -1;
    }

    if (Tetat[ins] == 0) {
        printf("%s[desactivationCarte] note:%s carte déjà desactivée.\n", STY_FYELLOW, STY_NULL);
        return 0;
    }

    Tetat[ins] = 0;
    printf("\n%s[desactivationCarte] succes:%s Carte n°%d desactivée.\n",STY_FGREEN, STY_NULL,numAdhe);
    return 0;
}

/**
 * Fonction Entrée d'adhérent dans le centre : 
 * - saisie d'un adhérent via fonction adaptée.
 * -vérifie la présence de l'adhérent saisie via fonction verification d'entrée "VerifEntreAdhe" :
 *      cette fonction vérifie que la carte d'adhérent est dans la base et qu'elle
 *      n'est pas désactivée et renvoie, elle renvoie également la position 
 *      du numéro d'adhérent dans les tableaux.
 * - Vérifie que l'adhérent n'est pas déjà rentré dans la journée via fonction "VerifAdheNonEntre"
 * - Vérifie Que L'adhérent Dispose D'un minimum de points (cout de l'activité la moins chère.)
 * - Puis via "verifNbPRest" Vérifie qu'il reste assez de points pour l'activité saisie
 *          et retire les points à l'adhérent
 * 
 *  
*/
void EntreAdhe(int nbAdhe,int Tnum[],int Tetat[],int TnbPoints[],int Tcat[],int TnbEntr[],int TnumAdheEntre[],int * nbAdheEntre,int tPtUtils[])
{   
    // INITIALISATION DES TABLES D'activités
    int nbAct = NBACT;   // nombre d'activités (10)
    int TnumAct[NBACT]={1,2,3,4,5,6,7,8,9,10};      // Tnuméros Activités
    int TCact[NBACT]= {
        CO_KAYAK, CO_BOXE, CO_MUSCU, CO_GYM, CO_AQUAGYM,
        CO_VELO, CO_SQASH, CO_TENNIS, CO_BASKET, CO_FOOT};

    int pos,presence,numAct;
    int numAdhe,rep,coderet;
    saisieEntrAdhe(&numAdhe);
    pos=VerifEntreeAdhe(nbAdhe,Tnum,Tetat,&numAdhe);

    if (pos==-1){return;}
    
    coderet=VerifAdheNonEntre(numAdhe,TnumAdheEntre,nbAdheEntre);
    
    if(coderet==-1)
    {
        return;
    }
    if (TnbPoints[pos]<CMINACT)
    {
        printf("%s[EntrAdhe] Erreur !!%s Vous ne disposez pas d'assez de points pour réaliser une activité\n", STY_FRED, STY_NULL);
        return;
    }
    printf("\e[1;1H\e[2J"); // escape sequance pour clear la console
    affInfoAdhe(numAdhe,Tnum,Tetat,TnbPoints,Tcat,TnumAdheEntre, tPtUtils,nbAdhe);
    affInfoAct();
    saisieAct(&numAct);
    verifPresenceAct(&numAct,TnumAct,nbAct,&presence);
    //vérifie que l'adhérent dispose d'assez de points et les encaisse. 
    VerifnbPRest(TCact,numAct,TnbPoints,pos,TnbEntr,Tcat[pos],tPtUtils);
    
    saisie2ndAct(&rep);
    
    while (rep)
    {
        printf("\e[1;1H\e[2J"); // escape sequance pour clear la console
        if (TnbPoints[pos]<CMINACT)
        {
            printf("%s[EntrAdhe] Erreur !!%s Vous ne disposez plus d'assez de points pour réaliser une activité\n", STY_FRED, STY_NULL);
        return;
        }
        affInfoAdhe(numAdhe,Tnum,Tetat,TnbPoints,Tcat,TnumAdheEntre,tPtUtils, nbAdhe);
        affInfoAct();
        saisieAct(&numAct);
        verifPresenceAct(&numAct,TnumAct,nbAct,&presence);
        VerifnbPRest(TCact,numAct,TnbPoints,pos,TnbEntr,Tcat[pos],tPtUtils);
        saisie2ndAct(&rep);
    }

    TnumAdheEntre[*nbAdheEntre]=numAdhe;
    *nbAdheEntre+=1;
    
    printf("\e[1;1H\e[2J"); // escape sequance pour clear la console
    affInfoAdhe(numAdhe,Tnum,Tetat,TnbPoints,Tcat,TnumAdheEntre,tPtUtils,nbAdhe);
    printf("\n%s[EntreAdhe] Succès,%s Activités Enregistrées !\n", STY_FGREEN, STY_NULL);
    
    return;
}


/**
 * Fonction qui vérifie que l'adhérent n'a pas déjà fréquenté le centre dans la journée
 * Dans ce cas, elle renvoie un message et un code d'erreur
*/
int VerifAdheNonEntre(int numAdhe,int TnumAdheEntre[],int *nbAdheEntre)
{
    int i;
    for (i=0;i<*nbAdheEntre;i++)
    {
        if (TnumAdheEntre[i]==numAdhe)
        {
            printf("%s[EntreAdhe] Erreur !!%s L'adhérent à déjà fréquenté le centre Ajourd'hui !\n", STY_FRED, STY_NULL);
            return -1;
        }
    }
    return 0;
}
