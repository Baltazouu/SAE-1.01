# SAE-1.01 Receuil de Besoins

## Développeurs :
* **Agostihno Alexandre (TP1)**
* **Dudonné Baptiste (TP1)**

## Cahier Des Charges



##  Fonction Globale :
 

La fonction Globale Permet d'affichier tout les choix disponibles au lancement de l'application : 
```
[Gestion d'un complexe sportif]

Commande :  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃       0 # Afficher ce menu                                            ┃
┃       1 # Créer un nouvel adhérent                                    ┃
┃       2 # Supprimer un adherent                                       ┃
┃       3 # Alimenter une carte                                         ┃
┃       4 # Activer une carte                                           ┃
┃       5 # Désactiver une carte                                        ┃
┃       6 # Afficher les informations d'un adherent                     ┃
┃       7 # Afficher les informations de tout les adhérents             ┃
┃       8 # Afficher le nombre d'entrées par activité dans la journée   ┃
┃       9 # Saisir entrée d'un adhérent                                 ┃
┃       10 # Quitter la gestion du centre (fin de journée)              ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛


[gestion] Saisir la commande (#0 -menu):
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

```
## A noter  :
* Après toutes commandes excepté 10, il sera la commande gestion pour continuer l'administration du centre 
``` 

[gestion] Saisir la commande (#0 -menu):
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
## Commande 0 : Réafficher le menu : 

* Cette Commande Réaffiche La Liste des commandes 


##  Commande 1 : Créer Un Nouvel Adhérent

Dans cette fonction, le Premier Adhérent de La Base est initialisé à 1000. Le Suiviant 1001 etc..
* Saisie du nombre de crédits
* Création de l'adhérent
```
[ajoutAdher] Saisir le nombre de crédit :       70

[ajoutAdher] succes: Adhérent n°1009 créé avec 70 points.
```

## Commande 2 : Supprimer un adhérent

*  saisie du numéro d'adhérent à supprimer
* suppression de l'adhérent



```
[suppAdhe] Saisir le numéro Adherent :  1001
[suppAdhe] succes: Adhérent n°1001 supprimé.
```

## Commande 3 : Alimenter une carte 
* Saisie du numéro d'adhérent (~ de carte) à alimenter
* Saisie du numéros de points à ajouter
* Alimentation de la carte

```
[suppAdhe] Saisir le numéro Adherent :  1001
[suppAdhe] succes: Adhérent n°1001 supprimé.
```
## Commande 4 : Activer une carte 
* Saisie du numéro d'adhérent (~ de carte)
* Activation Carte

```
[activationCarte] Saisir le numéro Adherent :   1001
[activationCarte] note: carte déjà activée.

[activationCarte] succes: Carte n°1001 activée.
```
## Commande 5 : Désactiver une carte 
* Saisie du numéro d'adhérent (~ de carte)
* Désactivation de la carte

```
[desactivationCarte] Saisir le numéro Adherent :        1003

[desactivationCarte] succes: Carte n°1003 desactivée.
```

## Commande 6 : Afficher les informations d'un adhérent

* saisie du numéro d'adhérent
* affichange numéro adhérent
* affichage état carte
* affichage nombre de points restants

```
[affInfoAdhe] Saisir le numéro Adherent :       1005

[affInfoAdhe] N° adherent :             1005
[affInfoAdhe] Etat de la carte :        1
[affInfoAdhe] Nombre de points :        16
```

## Commande 7 : Affichage information de tous les adhérents
* affichage des informations de tous es adhérents

```
[affInfoTous] informations générales : ----------------------------

        N°adhérent      | Etat  | Nb de points
        ---------------------------------------------
                1001    | 1     | 57
                1002    | 1     | 40
                1003    | 1     | 10
                1004    | 1     | 17
                1005    | 1     | 16
                1006    | 1     | 24
                1007    | 1     | 23
                1008    | 1     | 234
        ---------------------------------------------
```

## Commande 8 : Afficher le nombre d'entrées par activités dans la journée
* Affichage nombre entrées par activité dans la journée

```
[AffichEntrAct] Nombres d'entrées de la journée :

         1 # Kayak : 3 Entrées
         2 # Boxe : 1 Entrées
         3 # Musculation : 0 Entrées
         4 # Gym : 1 Entrées
         5 # AquaGym : 2 Entrées
         6 # Vélo : 2 Entrées
         7 # Sqash : 1 Entrées
         8 # Tennis : 4 Entrées
         9 # Basket : 2 Entrées
         10 # Foot : 2 Entrées
```

## Commande 9 : Saisir entrée d'un adhérent
* Saisie numéro adhérent entrant
* Affichage information adhérent
* Affichage Infos Activités (numéros, noms, cout)
* Saisie numéro d'activité
* Soustraction des points 
* Saisie Autre Activité (Boucle Affichage,saisie activité)

```
[EntrAdhe] Saisissez Le Numéro De l'adhérent entrant : 1008
[affInfoAdhe] N° adherent :             1008
[affInfoAdhe] Etat de la carte :        1
[affInfoAdhe] Nombre de points :        234

[EntrAdhe] Entrez Le Numéro D'activité Correspondant :
------------------------------------------------------

         1 # Kayak : 25 points
         2 # Boxe : 15 points
         3 # Musculation : 15 points
         4 # Gym : 12 points
         5 # AquaGym : 15 points
         6 # Vélo : 20 points
         7 # Sqash : 22 points
         8 # Tennis : 25 points
         9 # Basket : 10 points
         10 # Foot : 10 points

[EntrAdhe] Saisissez Le Numéro D'activité : 4

[EntrAdhe] Souhaitez Vous Choisir Une Autre Activité ( 1 : Oui | 0 : Non ) : 
```

## Commande 10 : Quitter la gestion du centre

* sauvegarde des tableaux d'entiers Tnum[]
, Tetat[ ], TnbPoints []
 dans le fichier adherents.txt
 * Affichage du nombre d'adhérents sauvegardés
 * Fin du programme.
```
[sauvegarde] succes: 8 adherents sauvegardés.
```
