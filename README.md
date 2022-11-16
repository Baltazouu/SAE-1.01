# SAE-1.01

*Membres du groupe :*  
  * Alexandre Agostinho
  * Baptiste Dudonne

**Cahier des charges disponble [ici](https://github.com/Baltazouu/SAE-1.01/wiki/Cahier-des-Charges).**

## Instructions/Utilisation des outils

### MAKE

*Sur la racine du projet:*

* build le programme : 
```make```

* build et executer le programme : 
```make && ./sae1-01```

* build et executer le programme (mode silencieux) : 
```make -s && ./sae1-01```

* clean les binaires: 
```make clbin```

* clean les données: 
```make cldata```

* clean tout: 
```make clall```

* générer la doc html : 
```make doc```

### GIT

##### Les branches
On utilise les branches pour ne pas travailler sur les même version du projet et donc éviter les conflits entre les fichers lors de modifications.  
On utilise aussi les branche pour séparer les versions du programme.

Les principales branches sont :
  * la branche `main` : où se trouve le programme final et fonctionnel
  * la branche `dev` : où se trouve les differents 'merges' des version, on passe par cette branche pour réunir les fonctionnalitées entre elles.
  * les autres branches : généralement au moins une par personne, ou une par groupe de fonctionnalités (par ex: la branche affichage où dessus sera fait toutes les fonctionnalités liées à l'affichage)  

Les commandes :
  * `git switch [branche]` : se déplacer sur une branche
  * `git branch` : lister toutes les branches
  * `git branch [branche]` : créé une branche (altérnative : `git switch -c [branche]` qui nous déplace directement sur la branche après l'avoir créé)

##### Les commits
C'est des sauvegardes de la versions actuelle du projet sur la branche coressondante. Le truc cool avec git c'est que tout les commits sont enregistrés donc si il y a un problème on peut toujours revenir en arrière.  

Les commandes :
  * `git add [fichier|dossier]` : ajouter des fichers au commit. A faire avant de créé un commit. Généralement utilisé comme cela : `git add .` pour ajouter tout les fichier qui n'ont pas été ajoutés.
  * `git status` : voir le status des fichers avant un commit.
  * `git commit -m "[message]"` : créer un commit des fichiers ajoutés (message obligatoire, expliquer brièvement ce qui à été fait depuis l'ancien commit. Ex: git commit -m "ajout fonction affichageAdherent").

##### Le server et le client git
C'est une sorte de drive qui permet de géré à distance le repo git. Codefirst permet notemment de gérer l'avancement des projets (onglet `projet`) via un tableau répertoriant tout ce qui est fait et doit être fait.  

Du côté du client, pour travailler il doit avoir git sur son pc, récupérer le projet, le mettre à jour avant de commencer à travailler dessus et envoyer les modifications au serveur.

Les commandes :
  * `git clone [lien]` : sert à créer et importer le répo en local. S'en servir seulement la première fois. Le lien se trouve dans l'onglet `code` à coté du bouton `HTML`.
  * `git pull` : importe les dernères modifications du repo distant (si il y en a) et met à jour la version de la branche sur laquelle on se trouve. Penser à commit avant. Si il y à un conflit, c'est que quelqu'un à travailler sur la même branche.
  * `git push -u origin [branche]` : (à entrer lors d'un changement de branche) sert à envoyer les derniers commits au seveur.
  * `git push` : idem, à utilisé seulement quand la première à été déjà utilisée depuis le changement de branche.
