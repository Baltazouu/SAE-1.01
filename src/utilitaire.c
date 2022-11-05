/*
* \file utilitaire.c
* \brief Fonctions utilitaires
*/

#include <stdio.h>

int rechercheNombre(int nb, int Table[], int *presence, int tlog)
{
    int i;
    for (i = 0; i < tlog; i++) {
        if (Table[i] == nb) { *presence = 1; return i; }
        if (Table[i] > nb) { *presence = 0; return i; }
    }
    *presence = 0; return i;
}

int recherche1ereOccu(int Table[], int tlog, int *val)
{
    int i;
    for (i = 0; i < tlog; i++) {
        if (Table[i] > *val) return i;
        *val += 1;
    }
    return i;
}


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

void suppressionNombre(int pos, int Table[], int tlog)
{
    int i;
    for (i = pos; i < tlog; i++) {
        Table[i] = Table[i+i];
    }
}
