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
* \param Table le tableau trié de recherche
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

/**
 *  \brief Vérifie pour la fonction EntreAdhe si le nombre entré est bien dans la base et si sa carte n'est pas désactivée
 *  \param nbAdhe nombres d'adhérent de la table (taille logique)
 *  \param Tnum Table de numéros des adhérents
 *  \param Tetat Table d'état des numéros d'adhérents
 *  \param numAdhe Numéro d'adhérent entré
*/
int VerifEntreeAdhe(int nbAdhe,int Tnum[],int Tetat[],int *numAdhe);

/**
 *  \brief Vérifie que l'activitée entrée est bien dans la base et boucle en cas contraire
 *  \param numAct Numéro d'activité entré
 *  \param TnumAct Table des numéros d'activités
 *  \param nbAct nombre d'activités : taille logique de TnumAct
 *  \param presence est égale à 0 si le numéro d'act n'est pas dans la base 
*/
void verifPresenceAct(int numAct,int TnumAct[],int nbAct,int *presence);

/**
 * \brief Vérifie que l'adhérent spécifié dispose d'assez de points pour réaliser l'activité
 * \param TCact Tableau des coûts des activités
 * \param numAct Numéro activité choisie
 * \param TnbPoints Tableau du nombre de points des adhérents
 * \param posAdhe position de l'adhérent dans le tableau
 * \param TnbEntr nombre d'entrées d'activités par jour
*/
int VerifnbPRest(int TCact[],int numAct,int TnbPoints[],int posAdhe,int TnbEntr[], int cat);
