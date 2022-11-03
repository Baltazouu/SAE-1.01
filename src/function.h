
// ATTENTION: NOM DES FONCTIONS NON DEFINITIFS
// ATTENTION: PARAMETRES INCOMPLET/PROVISOIRE
//
// CE FICHIER EST UNE LISTE PROVISOIRE DES FONCTIONS A CREE


// ajout d'adhérents
int ajoutAdherents(int nbAdhe, ...);
int controleSaisieAdherents(...);

// ajout/retrait de points (utilisé aussi pour les bonus)
int ajoutPoints(int nAdhe, int nbPoints, ...);
int retraitPoints(int nAdhe, int nbPoints, ...);

// test si le client est déjà venu dans la journée
int estDejaVenu(int nAdhe, ...);

// activation/desactivation d'une carte
int activationCarte(int nAdhe, int active);

// fonctions d'affichages
void affInfoAdherent(int nAdhe, ...);
void affInfoToutAdherent(...);
void affNbEntrees(int nActi, ...);

// sauvegarde et chargement
int chargementAdherents(...);
int sauvegardeAdherents(...);

// fonctions utilitaires (a complété au besoin)
int rechercheAdhe(int nAdhe, ...);
