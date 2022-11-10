/*
* \file chargement.h
* \brief fonctions de chargements
*
*   SAE 1.01
*/

/**
* \brief Charge le fichier "adherents.txt" dans les tableaux
*
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents
* \param Tcat Tableau des catégories d'utilisateurs
* \param tPtUtils Tableau des points utilisés pour points bonus
* \param tmax taille maximale des tableaux
*
* \return la taille logique des tableaux, -1 si il y a un problème d'ouverture de fichier
*/
int chargement(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[],int tPtUtils[], int tmax);

/**
* \brief Sauvegarde le fichier "adherents.txt" depuis les tableaux
*
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents 
* \param Tcat Tableau des catégories d'utilisateurs
* \param tPtUtils Tableau des points utlisés pour points bonus
* \param nbAdhe nombre d'adherents (taille logique)
*
* \return 0 si tout va bien, -1 si il y a un problème d'ouverture de fichier
*/
int sauvegarde(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[],int tPtUtils[], int nbAdhe);
