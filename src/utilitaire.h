/*
* \file utilitaire.h
* \brief Fonctions utilitaires
*
*   SAE 1.01
*/


/**
* \brief Recherche d'un nombre dans un tableau trié
*
* \param nb le nombre recherché
* \parma Table le tableau trié de recherche
* \param presence booleen vrai si le nombre est présent dans le tableau
* \param tlog taille logique de Table
*
* \return la position d'insertion du nombre dans le tableau trié
*/
int rechercheNombre(int nb, int Table[], int *presence, int tlog);

/**
* \brief Recherche de la première occurence d'un trou dans une suite de nombres
*
* \parma Table le tableau trié de recherche
* \param tlog taille logique de Table
* \param val la valeur du premier trou trouvé dans la suite
*
* \return la position d'insertion de ce nombre dans le tableau trié
*/
int recherche1ereOccu(int Table[], int tlog, int *val);

/**
* \brief Insertion d'un nombre dans un tableau trié
*
* \param nb le nombre à insérer
* \param pos la position du nombre à insérer
* \param Table le tableau dans lequel insérer ce nombre
* \param tlog la taille logique du tableau
* \param tmax la taille physique du tableau
*
* \return 0 si tout se passe bien, -1 si la taille maximale de Table est atteinte
*/
int insertionNombre(int nb, int pos, int Table[], int tlog, int tmax);

/**
* \brief Suppression d'un nombre dans un tableau trié
*
* \param pos la position du nombre à supprimer
* \param Table le tableau où la suppression doit s'effectuer
* \param tlog la taille logique du tableau
*/
void suppressionNombre(int pos, int Table[], int tlog);

int VerifEntreeAdhe(int nbAdhe,int Tnum[],int Tetat[],int *numAdhe);

void verifPresenceAct(int numAct,int TnumAct[],int nbAct,int *presence);

int VerifnbPRest(int TCact[],int numAct,int TnbPoints[],int posAdhe,int TnbEntr[]);
