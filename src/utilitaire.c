/*
* \file utilitaire.c
* \brief Fonctions utilitaires
*
*   SAE 1.01
*/

#include <stdio.h>


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
        printf("[insertionNombre] erreur: taille maximale atteinte.\n");
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
    for (i = pos; i < tlog; i++) {
        Table[i] = Table[i+i];
    }
}
