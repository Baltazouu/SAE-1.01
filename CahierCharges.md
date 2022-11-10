# SAE-1.01 Receuil de Besoins

## **Cahier Des Charges**

## Développeurs :
* **Agostihno Alexandre (TP1)**
* **Dudonné Baptiste (TP1)**

## Fichiers : adherents.txt

Ce fichier content 4 Données :
* Numéro D'adhérent (``1001,1002,..``)
* Etat Carte (``1`` :Activée / ``0`` : Désactivée)
* Nombre de points (ex : ``75``)
* Catégorie Adhérent : (``1`` : Etudiant / ``2`` : Mineur / ``3`` : Majeur Salarié / ``4`` : Retraité )

## Fichiers : config.h
C'est dans ce fichier que l'on peut modifier les paramètres de notre programme de gestion, celui-ci contient : 

données relatives aux adhérents :
* TMAX (Nombre maximal d'adhérents dans le centre)

données relatives aux activités : 
* NBACT (Nombre d'activités proposées)
* CO_KAYAK    : Coût activité Kayak
* CO_BOXE     : Coût activité Boxe
* CO_MUSCU    : Coût activité Muscu
* CO_GYM      : Coût activité GYM
* CO_AQUAGYM  : Coût activité Aquagym
* CO_VELO     : Coût activité vélo
* CO_SQASH    : Coût activité Sqash
* CO_TENNIS   : Coût activité Tennis
* CO_BASKET   : Coût activité Basket
* CO_FOOT     : Coût activité Foot


## Fonctions : 
**Logiciel de gestion d'un centre sportif** 

Ce logiciel permet d'administrer un centre sportif à l'aide d'une structure fonctionnele. Lors du démarrage du programme, la fonction globale est lancée, celle-ci se déroule dans l'ordre suiviant :

* chargement des données du fichier "adherent.txt" dans des tableaux (**TnumAdhe,Tactive,TnbPoints,Tcategorie**)
* Ensuite, la fonction globale affiche les commandes disponibles et permet de  saisir le choix de l'utilisateur.
* Une fois la saisie effectuée, le programme execute la fonction correspodante
* Après chaque commande, la fonction globale est relancée.



**Liste des fonctions disponibles** :

* 1 : Créer un nouvel adhérent
* 2 : Supprimer un Adhérent
* 3 : Alimenter une carte d'adhérent
* 4 : Activer Une Carte d'adhérent 
* 5 : Désactiver une Carte D'adhérent (mauvais comportement, ...)
* 6 : Afficher les informations d'un adhérent
* 7 : Afficher les information de tous les adhérents
* 8 : Afficher les informations 
* 9 : Saisir une entrée d'un adhérent dans le centre



##  Fonction Globale :
 

La fonction Globale Permet d'affichier tout les choix disponibles au lancement de l'application et de saisir le choix  de l'utilisateur : 
```
[Gestion d'un complexe sportif] | 1     | 57
                1002    | 1     | 40
                1003    | 1     | 10
                1004    | 1     | 17
                1005    | 1     | 16
                1006    | 1     | 24
                1007    | 1     | 23
                1008    | 1     | 234
        ---------------------------------------------
```
## A noter  :
* Après toutes commandes excepté 10, la commande gestion sera executée pour entrer le nouveau choix et continuer l'administration du centre 

## Commande 0 : Réafficher le menu : 

* Cette Commande Réaffiche La Liste des commandes (Fonction globale)


``` 

[gestion] Saisir la commande (#0 -menu):
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```


##  Commande 1 : Créer Un Nouvel Adhérent

Dans cette fonction, le Premier Adhérent de La Base est initialisé à 1000. Le Suiviant 1001 etc..
* Saisie du nombre de crédits
* Création de l'adhérent (ajout des données dans les tableaux)
```
[ajoutAdher] Saisir le nombre de crédit :       70

[ajoutAdher] succes: Adhérent n°1009 créé avec 70 points.
```

## Commande 2 : Supprimer un adhérent

*  saisie du numéro d'adhérent à supprimer
* suppression de l'adhérent (suppression adhérent de tous tableaux)

```
[suppAdhe] Saisir le numéro Adherent :  1001
[suppAdhe] succes: Adhérent n°1001 supprimé.
```

## Commande 3 : Alimenter une carte 
* Saisie du numéro d'adhérent (~ de carte) à alimenter
* Saisie du numéros de points à ajouter
* Alimentation de la carte (alimentation dans le tableau (**TnbPoints**))

```
[suppAdhe] Saisir le numéro Adherent :  1001
[suppAdhe] succes: Adhérent n°1001 supprimé.
```
## Commande 4 : Activer une carte 
* Saisie du numéro d'adhérent (~ de carte)
* Activation Carte (modification **Tactive** à 1)

```
[activationCarte] Saisir le numéro Adherent :   1001
[activationCarte] note: carte déjà activée.

[activationCarte] succes: Carte n°1001 activée.
```
## Commande 5 : Désactiver une carte 
* Saisie du numéro d'adhérent (~ de carte)
* Désactivation de la carte (modification **Tactive** à 0)

```
[desactivationCarte] Saisir le numéro Adherent :        1003

[desactivationCarte] succes: Carte n°1003 desactivée.
```

## Commande 6 : Afficher les informations d'un adhérent

* saisie du numéro d'adhérent
* affichange numéro adhérent (**TnumAdhe**)
* affichage état carte (**Tetat**)
* affichage nombre de points restants (**TnbPoints**) 

```
[affInfoAdhe] Saisir le numéro Adherent :       1005

[affInfoAdhe] N° adherent :             1005
[affInfoAdhe] Etat de la carte :        1
[affInfoAdhe] Nombre de points :        16
```

## Commande 7 : Affichage information de tous les adhérents
* affichage des informations de tous es adhérents (Affichage Tous Tableaux)

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
* Affichage nombre entrées par activité dans la journée (**TnbEntr**)


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
* Affichage information adhérent (**Tnum,Tactive,TnbPoints,TcatAdhe**)
* Affichage Infos Activités (**TnumAct**, noms,**TcAct**)
* Saisie numéro d'activité
* Soustraction des points (**TnbPoint**)
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

# Compilation du projet : 

Comment Complier et executer le projet : 

* Depuis la racine du projet : lancer un ``make``, le make va alors créer répertoire bin dans lequel seront placés tous les binaires.
* Un Lien vers un executable sera alors crée dans la racine sous le nom de ``sae-1.01``
* Contenu de votre dossier après le make :
```
bin  CahierCharges.md  data  Doxyfile  makefile  README.md  sae1-01   src
```
* Executez le lien : ``./sae-1.01``

## Vous pouvez désormais administrer le centre !