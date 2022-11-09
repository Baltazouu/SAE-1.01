/**
* \file gestion.h
* \brief fonctions de gestions des adherents
*
*   SAE 1.01
*/

#define NBACT 10 // 10 Activités

/**
* \brief Ajout d'un adherent
*
* \param nbAdher nombre d'adherents
* \param nbCredits nombre de crédits à la création du compte
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents
* \param tmax taille physiques des tableaux précédent
*
* \return le nouvel id du nouvel adherent; -1 si erreur
*/
int ajoutAdher(int *nbAdher, int nbCredits,
               int Tnum[], int Tetat[], int TnbPoints[], int tmax);

/**
* \brief Suppression d'un adherent
*
* \param numAdhe numiéro de adherent
* \param tlog taille logique des tableaux
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents
*
* \return 0 si tous se passe bien, -1 sinon
*/
int suppAdhe(int numAdhe, int *tlog,
             int Tnum[], int Tetat[], int TnbPoints[]);

/**
* \brief Alimentation en points de la carte. Permet aussi le débit.
*
* \param points le nombre de points ajoutés à la carte. (peut être négatif)
* \param numAdhe numiéro de adherent
* \param nbAdhe nombre d'adherents
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents
*
* \return 0 si tout se passe bien, -1 si le numéro n'est pas valide, -2 si la carte est désactivée
*/
int alimCarte(int points, int numAdhe, int nbAdhe,
              int Tnum[], int Tetat[], int TnbPoints[]);

/**
* \brief Active une carte
*
* \param numAdhe numiéro de adherent
* \param nbAdhe nombre d'adherents
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
*
* \return 0 si tout se passe bien, -1 si le numéro n'est pas valide
*/
int activationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[]);

/**
* \brief Désactive une carte
*
* \param numAdhe numiéro de adherent
* \param nbAdhe nombre d'adherents
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
*
* \return 0 si tout se passe bien, -1 si le numéro n'est pas valide
*/
int desactivationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[]);

void EntreAdhe(int nbAdhe,int Tnum[],int Tetat[],int TnbPoints[],int TnbEntr[]);
