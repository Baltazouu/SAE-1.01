/*
* \file utilitaire.c
* \brief Fonctions utilitaires
*
*   SAE 1.01
*/

#include <stdio.h>
#include "saisie.h"
#include "utilitaire.h"

#include "config.h"


/**
* Tant que le nombre est plus petit que le nombre recherché, passe au nombre
* suivant en enrgistrant la position dans ce tableau à chaque fois.
* Si le nombre est égal, passe le booleen presence à 1.
* Si il est plus grand, alors le nombre n'existe pas :  presence est mis à 0.
* S'arrête de chercher si l'élément est trouvé, supérieur ou si tlog est atteint
*/
int rechercheNombre(int nb, int Table[], int *presence, int tlog)
{
    int i;
    for (i = 0; i < tlog; i++) {
        if (Table[i] == nb) { *presence = 1; return i; }
        if (Table[i] > nb) { *presence = 0; return i; }
    }
    *presence = 0; return i;
}

/**
* Verifie que les valeurs de table forme une suite tel que N+1 = N+1.
* S'arrête à la première valeur du tableau qui ne remplis pas cette condition et
* renvoie par val la valeur qui aurrai du se trouvé à cette position.
*/
int recherche1ereOccu(int Table[], int tlog, int *val)
{
    int i;
    for (i = 0; i < tlog; i++) {
        if (Table[i] > *val) return i;
        *val += 1;
    }
    return i;
}

/**
* Test si il y a la place d'insérer un nouveau nombre.
* Décale tout les élément du tableau à partir de la position d'insertion et y
* place le nouvel élément.
*/
int insertionNombre(int nb, int pos, int Table[], int tlog, int tmax)
{
    if (tlog == tmax) {
        printf("%s[insertionNombre] erreur:%s taille maximale atteinte.\n", STY_FRED, STY_NULL);
        return -1;
    }

    int i;
    for (i = tlog; i > pos; i--) {
        Table[i] = Table[i-1];
    }

    Table[pos] = nb;

    return 0;
}

/**
* Décale tout les éléments du tableau pour couvrir l'élément à cette position
* afin de le supprimer.
*/
void suppressionNombre(int pos, int Table[], int tlog)
{
    int i;
    for (i = pos; i < tlog-1; i++) 
    {
        Table[i] = Table[i+1];
    }
}

/** 
 * Vérifie que l'adhérent entré est présent dans les tables
 * Vérifie que l'adhérent entré n'est pas désactivé
*/
int VerifEntreeAdhe(int nbAdhe,int Tnum[],int Tetat[],int *numAdhe)
{       
    int presence,pos;
    pos=rechercheNombre(*numAdhe,Tnum,&presence,nbAdhe);
    while (presence==0)
    {
        printf("%s[EntrAdhe] Erreur !!%s Le Numéro Spécifé N'est Pas Dans La Base !\n", STY_FRED, STY_NULL);
        saisieEntrAdhe(numAdhe);// on redemande.
        rechercheNombre(*numAdhe,Tnum,&presence,nbAdhe);
    }
    if (Tetat[pos]==0)
    {
        printf("%s[EntrAdhe] Erreur !!%s Carte N°%d Désactivée Entrée Impossible\n", STY_FRED, STY_NULL,Tnum[pos]);
        return -1;
    }
    return pos;
}

/**
 * vérifie que l'activitée saisie est dans la liste des activités proposées
*/
void verifPresenceAct(int *numAct,int TnumAct[],int nbAct,int *presence)
{
    rechercheNombre(*numAct,TnumAct,presence,nbAct);
    while(*presence==0)
    {
        printf("%s[EntrAdhe] Erreur !!%s Le Numéro Spécifié N'est Pas Dans La Liste\n", STY_FRED, STY_NULL);
        saisieAct(numAct);
        rechercheNombre(*numAct,TnumAct,presence,nbAct);
    }
    return;
}

/**
 * vérifie que l'adhérent saisit dispose d'assez de points pour réaliser une activité
 * Vérifie que l'adhérent dispose d'assez de points pour réaliser l'activité qu'il souhaite réaliser
 * Encaisse les points de l'adhérent
 * Compte le nombre de points utilisés et offre des points si le nombre dépasse 60.
*/
void VerifnbPRest(int TCact[],int numAct,int TnbPoints[],int posAdhe,int TnbEntr[], int cat,int tPtUtils[])
{   
    
    if (TnbPoints[posAdhe]<CMINACT){printf("[EntrAdhe] Erreur !! Vous Ne Disposez Plus D'assez de points !\n"); return;}
    if (TCact[numAct-1]>TnbPoints[posAdhe])
    {
        printf("%s[EntrAdhe] Erreur !!%s Vous Ne Disposez Pas D'assez De Points Pour Réaliser Cette Activité !\n", STY_FRED, STY_NULL);
        return;
    }
    TnbPoints[posAdhe]-=(TCact[numAct-1]);
    TnbEntr[numAct-1]+=1;
    tPtUtils[posAdhe]+=TCact[numAct-1];
    if (tPtUtils[posAdhe]>RecurPtsBonus)
    {   
        if (cat==1)
        {
            TnbPoints[posAdhe]+=BonEtu;
            printf("%s[EntrAdhe] Fidélité,%s Vous Avez Dépensé %d Points, Le Centre Vous Offre %d Points :)\n",STY_FYELLOW,STY_NULL,RecurPtsBonus,BonEtu);
        }
        else if(cat==2){
            TnbPoints[posAdhe]+=BonMineur;
            printf("%s[EntrAdhe] Fidélité,%s Vous Avez Dépensé %d Points, Le Centre Vous Offre %d Points :)\n",STY_FYELLOW,STY_NULL,RecurPtsBonus,BonMineur);
        }
        else if (cat==3)
        {
            TnbPoints[posAdhe]+=BonRetraite;
            printf("%s[EntrAdhe] Fidélité,%s Vous Avez Dépensé %d Points, Le Centre Vous Offre %d Points :)\n",STY_FYELLOW,STY_NULL,RecurPtsBonus,BonRetraite);
        }
        else if (cat==4)
        {
            TnbPoints[posAdhe]+=BonMaj;
            printf("%s[EntrAdhe] Fidélité,%s Vous Avez Dépensé %d Points, Le Centre Vous Offre %d Points :)\n",STY_FYELLOW,STY_NULL,RecurPtsBonus,BonMaj);
        }
        else 
        {
            printf("%s[EntrAdhe] Erreur,%s Pas de Catégorie détéctée\n", STY_FRED, STY_NULL);
            return;
        }
        tPtUtils[posAdhe]-=80;
    }
    return;
}
