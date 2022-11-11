/**
* \file saisie.h
* \brief Fonctions de saisie
*
*   SAE 1.01
*/

/**
 * \brief Fonction Saisie Nombre de Crédits Lors de l'ajout d'un adhérent
 *
 * \param nbCredits Nombre de Crédits à allouer à un adhérent
 * \param cat identifiant de la catégorie de l'adhérent
 * 
 * \return -1 si l'id de la catégorie est inconnu, 0 sinon
*/
int saisieAjoutAdher(int *nbCredits, int *cat);

/**
 * \brief Fonction Saisie Pour La Suppression d'un adhérent
 * 
 * \param numAdhe Numéro d'adhérent à supprimer
*/
void saisieSuppAdhe(int *numAdhe);

/**
 * \brief Fonction Saisie Pour Alimentation d'une Carte
 *
 * \param numAdhe numéro de carte(& adhérent) à alimenter
 * \param points nombre de points à alimenter
*/
void saisieAlimCarte(int *numAdhe, int *points);

/**
 * \brief Fonction Saisie activation Carte
 * 
 * \param numAdhe numéro de carte (& adhérent) à alimenter
*/
void saisieActivationCarte(int *numAdhe);

/**
 * \brief Fonction Saisie désactivation Carte
 *
 * \param numAdhe Numéro de Carte (&adhérent à désactiver
*/
void saisieDesactivationCarte(int *numAdhe);

/**
 * \brief Fonction saisie du numéro d'adhérent à afficher
 *
 * \param numAdhe Numéro de Carte (&adhérent à désactiver
*/
void saisieAffInfoAdhe(int *numAdhe);

/**
 * \brief Fonction Saisie Choix Pour les activités
 * 
 * \param choix choix (1-11) de le l'action dans la fonction globale
*/
void saisieChoix(int *choix);

/**
 * \brief Fonction saisie entrée adhérent
 * \param numadhe numéro adhérent entrant
*/
void saisieEntrAdhe(int *numadhe);

/**
 * \brief Saisie Activité (1-10) 
 * \param numAct Numéro activité choisie
*/
void saisieAct(int *numAct);

/**
 * \brief Fonction Pour Saisir Si l'adhérent souhaite entrer une deuxième (ou plus) activité(s) 
 * \param rep réponse (1 : oui 0: non)
*/
void saisie2ndAct(int *rep);



