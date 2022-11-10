/**
* \file affichage.h
* \brief fonctions d'affichages
*
*   SAE 1.01
*/


/**
* \brief Affiche le menu principal de la gestion du centre
*/
void affMenu(void);

/**
* \brief Affiche une page d'informations concernant un adhérent
*
* \param numAdhe le numéro de l'adhérent
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents
* \param nbAdhe le nombre d'adherents (la taille logique des tableaux)
*/
void affInfoAdhe(int numAdhe, int Tnum[], int Tetat[], int TnbPoints[], 
    int Tcat[], int TnbEntr[],int tPtUtils[], int nbAdhe);
/**
* \brief Affiche Toute les infos sur les adherents
*
* \param Tnum tableau des numéros d'adherents
* \param Tetat tableau des états des compte adherents
* \param TnbPoints tableau des nombres de points des adherents
* \param nbAdhe le nombre d'adherents (la taille logique des tableaux)
  \param tPtUtils tableau des points utilisés pour points bonus
*/
void affInfoTous(int Tnum[], int Tetat[], int TnbPoints[], int Tcat[], int nbAdhe);

/**
 * \brief Affiche Liste Activités Proposés & leur cout
*/
void affInfoAct(void);

/**
 * \brief Affiche Nombre D'entrées par activités dans la journée
 * \param TnbrEntr Tableau du nombre d'entrées par act
 * \param tlog taille logique du tableau
*/
void affichnbEntrAct(int TnbEntr[],int tlog);

void affInfoCate(void);