/**
* \file gestion.h
* \brief fonctions de gestions des adherents
*
*   SAE 1.01
*/

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
int ajoutAdher(int *nbAdher, int nbCredits, int nCat,
               int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int tmax);

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
             int Tnum[], int Tetat[], int TnbPoints[], int Tcat[]);

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

/**
 * \brief Gère L'entrée d'un adhérent dans le centre
 * \param nbAdhe Nombre D'adhérents dans le centre (taille logique des trois tableaux suivants)
 * \param Tnum Tableau des numéros d'adhérents
 * \param Tetat Tableau de l'état des cartes des adhérents
 * \param TnbPoints Tableau du nombre de points des adhérents
 * \param TnbEntr Tableau du nombre d'entrés par activité
 * \param TnumAdheEntre Tavbleau du numéros des adhérents qui sont déjà rentrés dans la journée
 * \param nbAdheEntre nombre d'adhérents entrés dans la journé (taille logique TnumAdheEntre)
*/
void EntreAdhe(int nbAdhe,int Tnum[],int Tetat[],int TnbPoints[],int Tcat[],int TnbEntr[],int TnumAdheEntre[],int * nbAdheEntre);

/**
 * \brief Vérifie que l'adhérent n'est pas déjà entré dans le centre ajd
 * \param numAdhe Numéro d'adhérent en question
 * \param TnumAdheEntre Tableau des numéros d'adhérents entrés ajd
 * \param nbAdheEntre Nombre D'adhérents entrés ajd (tlog TnumAdheEntre)
 * \return 0 si pas d'erreur -1 si adhérent déjà entré
*/
int VerifAdheNonEntre(int numAdhe,int TnumAdheEntre[],int *nbAdheEntre);
