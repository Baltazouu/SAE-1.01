#include<stdio.h>

int fajoutadherent(int * numCarte){
    int i,x;
    FILE *fadherent;
    fadherent=fopen("adherents.txt","a+");//ajout en lecture + écriture à la fin du fichier
    if(fadherent==NULL){printf("problème Ouverture Fichier Adhérents.\n");return -1;}
    while (!feof(fadherent))
    {
        fscanf(fadherent,"%d %d",&i,&x);
    }
    if(i==0){i=1000;x=2000;}//si aucun adhérent présent : on initialise le premier au numéro 1000;
                            // on initialise la premiere Carte à 2000
    fprintf(fadherent,"%d",i+1);
    fprintf(fadherent,"\t%d\n",x+1);
    *numCarte=x+1;
    return i+1; // le nombre d'adhérent est égal a
    fclose(fadherent);


}


int main(void){
    int nbrAdherent;int numCarte;
    nbrAdherent=fajoutadherent(&numCarte);
    printf("Le Nouvel Adhérent à possède L'indentifiant %d \n",nbrAdherent);
    printf("Son Numéro De Carte Est : %d\n",numCarte);
     // le nombre d'adhérent est égal au numéro du dérnier adhérent - 1000
}
