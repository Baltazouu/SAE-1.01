/* sae.h 
//author : Baptiste Dudonné
//date : Nov 1st.
 file : tp5.h

    brief: fonctions ajout / suppression d'un adhérent 
           création et alimentation carte
*/

int fajoutadherent(int *nombreAdherent,int nbC);
/* Ajoute un numéro d'adhérent dans le fichier et lui insère le nombre de crédits
la fonction retourne le numéro du nouvel adhérent */

int rechercheNombre(int nbr,int Table[],int len_table);
// recherche un nombre dans une table et renvoie sa position

int fsuppressionadherent(int num_adherent,int nbr_adherent);/*
supprime un adhérent et ses informations en fonction du nombre d'adhére et du numéro
*/

void fsupp(int nbrAdherent);
//  fonction de saisie du numéro d'adhérent a supprimer et nécéssite
// le nombre d'adhérents

int ajoutadher(void);
//fonction de saisie du nombre de crédits à ajouter pour la création
// d'un nouvel adhérent.