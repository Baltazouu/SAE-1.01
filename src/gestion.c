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
* Met à jour les trois tableau en insérant dans l'ordre croissant des numéros
* d'adherents le nouvel id, état et nombre de points. (utilisation de la
* fonction d'insertion)
* Met à jour la taille logique du tableau.
*/
int ajoutAdher(int *nbAdher, int nbCredits,
               int Tnum[], int Tetat[], int TnbPoints[], int tmax)
{
    int val = 1001;
    int ins = recherche1ereOccu(Tnum, *nbAdher, &val);

    if (insertionNombre(val, ins, Tnum, *nbAdher, tmax)) {
        printf("[ajoutAdher] erreur: insertion.\n");
        return -1;
    }

    insertionNombre(1, ins, Tetat, *nbAdher, tmax);
    insertionNombre(nbCredits, ins, TnbPoints, *nbAdher, tmax);

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
             int Tnum[], int Tetat[], int TnbPoints[])
{
    int presence;
    int ins = rechercheNombre(numAdhe, Tnum, &presence, *tlog);
    if (!presence) {
        printf("[suppAdhe] erreur: numéro adherent non valide.\n");
        return -1;
    }

    suppressionNombre(ins, Tnum, *tlog);
    suppressionNombre(ins, Tetat, *tlog);
    suppressionNombre(ins, TnbPoints, *tlog);

    *tlog -= 1;
    printf("tlog after = %d", *tlog);
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
        printf("[alimCarte] erreur: numéro adherent non valide.\n");
        return -1;
    }
    if (Tetat[ins] == 0) {
        printf("[alimCarte] erreur: carte désactivée.\n");
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
        printf("[activationCarte] erreur: numéro adherent non valide.\n");
        return -1;
    }

    if (Tetat[ins] == 1) {
        printf("[activationCarte] note: carte déjà activée.\n");
        return 0;
    }

    Tetat[ins] = 1;
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
        printf("[activationCarte] erreur: numéro adherent non valide.\n");
        return -1;
    }

    if (Tetat[ins] == 0) {
        printf("[activationCarte] note: carte déjà desactivée.\n");
        return 0;
    }

    Tetat[ins] = 0;
    return 0;
}


void EntreAdhe(int nbAdhe,int Tnum[],int Tetat[],int TnbPoints[],int TnbEntr[],int TnumAdheEntre[],int * nbAdheEntre,int TAdheintdt[],int *nbinterdt)
{   
    // INITIALISATION DES TABLES D'activités
    int nbAct = NBACT;   // nombre d'activités (10)
    int TnumAct[NBACT]={1,2,3,4,5,6,7,8,9,10};      // Tnuméros Activités
    int TCact[NBACT]= {
        CO_KAYAK, CO_BOXE, CO_MUSCU, CO_GYM, CO_AQUAGYM,
        CO_VELO, CO_SQASH, CO_TENNIS, CO_BASKET, CO_FOOT
    };
    int TnumAct[NBACT]={1,2,3,4,5,6,7,8,9,10};      // Tnuméros Activités
    int TCact[NBACT]={25,15,15,12,15,20,25,10,10,10};// TCouts activités
    int pos,presence,numAct;
    int numAdhe,rep,coderet;
    saisieEntrAdhe(&numAdhe);
    pos=VerifEntreeAdhe(nbAdhe,Tnum,Tetat,&numAdhe);

    if (pos==-1){return;}
    coderet=VerifAdheNonInterdit(numAdhe,TAdheintdt,nbinterdt,TnumAdheEntre,nbAdheEntre);
    if(coderet==-1)
    {
        return;
    }
    affInfoAdhe(numAdhe,Tnum,Tetat,TnbPoints,nbAdhe);
    affInfoAct();
    saisieAct(&numAct);
    verifPresenceAct(numAct,TnumAct,nbAct,&presence);
    coderet=VerifnbPRest(TCact,numAct,TnbPoints,pos,TnbEntr);
    if (coderet==-1){return;}
    saisie2ndAct(&rep);
    while (rep)
    {
        affInfoAdhe(numAdhe,Tnum,Tetat,TnbPoints,nbAdhe);
        affInfoAct();
        saisieAct(&numAct);
        verifPresenceAct(numAct,TnumAct,nbAct,&presence);
        VerifnbPRest(TCact,numAct,TnbPoints,pos,TnbEntr);
        saisie2ndAct(&rep);
    }
    printf("[EntreAdhe] Succès, Activités Enregistrées !\n");
    TnumAdheEntre[*nbAdheEntre]=numAdhe;
    *nbAdheEntre+=1;
    
    return;
}
<<<<<<< HEAD
=======


void InterdirAdhe(int numAdhe,int TAdheintdt[],int *nbInterdit,int Tnum[],int nbAdhe)
{   
    int presence;
    rechercheNombre(numAdhe,Tnum,&presence,nbAdhe);
    while(!presence)
    {   
        printf("[InterdAdhe] Erreur !! Le Numéro Spécifié N'est Pas Dans La Base, Retaper\n");
        saisieInterdAdhe(&numAdhe);
        rechercheNombre(numAdhe,Tnum,&presence,nbAdhe);
    }
    TAdheintdt[*nbInterdit]=numAdhe;
    *nbInterdit+=1;
    printf("[InterdAdhe] Succès : L'adhérent N°%d à un accès unique au centre pour la journée\n",numAdhe);    
}

int VerifAdheNonInterdit(int numAdhe,int TAdheInterdt[],int *nbInterdit,int TnumAdheEntre[],int *nbAdheEntre)
{
    int i,x;
    for (i=0;i<*nbInterdit;i++)
    {
        for (x=0;x<*nbAdheEntre;x++)
        {
            if (TAdheInterdt[i]==TnumAdheEntre[x])
            {
                printf("[EntreAdhe] Erreur, Vous Ne Pouvez Pas Accéder Deux Fois Au Centre Ajourd'hui !!\n");
                return -1;
            }
        }
    }
    return 0;
}
>>>>>>> dev
