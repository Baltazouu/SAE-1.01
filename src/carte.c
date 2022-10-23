/**
* \file carte.c
* \brief Gestion des points sur la carte adhérent
* \author Alexandre Agostinho
* \date 22/09/2022
*/
#include <stdio.h>

/**
 * \param tAdhe (int[]): tableau des numéros d'adhérents
 * \param tNPoints (int[]): tableau des numbre de poiunt par adhérent
 * \param tMax (int): taille physique des tableaux
 * \return (int): >0 si erreur; sinon le nombre d'adhérents chargés
 */
int chargPoints(int *tAdhe, int *tNPoints, int tMax) {

    FILE *fe = fopen("./data/points.don", "r");
    if (fe == NULL) { printf("erreur chargement de fichier"); fclose(fe); return -1; }

    int adhe, nPoints, i = 0;

    fscanf(fe, "%d %d", &adhe, &nPoints);
    while (!feof(fe)) {

        if (i == tMax) { printf("erreur taille de tableux"); fclose(fe); return -2; }

        tAdhe[i] = adhe;
        tNPoints[i] = nPoints;

        fscanf(fe, "%d %d", &adhe, &nPoints);
        i++;
    }

    fclose(fe);
    return i;
}


/**
 * \param tAdhe (int[]): tableau des numéros d'adhérents
 * \param tNPoints (int[]): tableau des numbre de poiunt par adhérent
 * \param tLog (int): taille logique des tableaux
 * \return (int): >0 si erreur; sinon le nombre d'adhérents sauvgardés
 */
int sauvgPoints(int *tAdhe, int *tNPoints, int tLog) {

    FILE *fe = fopen("./data/points.don", "w");
    if (fe == NULL) { printf("erreur chargement de fichier"); fclose(fe); return -1; }

    int i; for (i = 0; i < tLog; i++) {
        fprintf(fe, "%d\t%d\n", tAdhe[i], tNPoints[i]);
    }

    fclose(fe);
    return i;
}
