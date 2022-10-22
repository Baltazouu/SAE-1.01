#include<stdio.h>

int fajoutadherent(int *nombreAdherent){
    int i;
    FILE *fadherent;
    fadherent=fopen("adherents.txt","a+");//ajout en lecture + écriture à la fin du fichier
    if(fadherent==NULL){printf("problème Ouverture Fichier Adhérents.\n");return -1;}
    fscanf(fadherent,"%d",&i);
    while (!feof(fadherent))
    {
        fscanf(fadherent,"%d",&i);
    }
    if(i==0){i=1000;}//si aucun adhérent présent : on initialise le premier au numéro 1000;
                            // on initialise la premiere Carte à 2000
    fprintf(fadherent,"%d\n",i+1);
    
     // le nombre d'adhérent est égal a
    fclose(fadherent);
    *nombreAdherent=i+1;
    return i+1;
}

int rechercheNombre(int nbr,int Table[],int len_table)
{
    int i;
    for(i=0;i<len_table;i++)
    {    if(Table[i]==nbr){return i;}   }
    return -1;
}


int fsuppressionadherent(int num_adherent,int nbr_adherent)
{   
    //printf("Ca fonctionne");
    int i=0,nAdherent,pos;
    int tAdherent[nbr_adherent];
    FILE *fadherent;
    fadherent=fopen("adherents.txt","r");
    fscanf(fadherent,"%d %d",nAdherent);
    while (!feof(fadherent))
    {   
        if(i==nbr_adherent){printf("Erreur Probleme Taille Tables !"); return -1;}
        fscanf(fadherent,"%d",&nAdherent);
        tAdherent[i]=nAdherent;
        
        i++;
    }
    fclose(fadherent);
    pos=rechercheNombre(num_adherent,tAdherent,nbr_adherent);
    if (pos==1){printf("Erreur ! Carte Non Présente Dans La Base...");return -1;}
    for(i=pos;i<nbr_adherent-1;i++)
    {   tAdherent[i+1]=tAdherent[i+1];  }
    return nbr_adherent-1;
}


int main(void)
{   
    int nAdherent, nbrAdherent;
    nAdherent=fajoutadherent(&nbrAdherent);// le nombre d'adhérent est égal au numéro du dérnier adhérent - 1000
    printf("Nouvel Adhérent est Crée, Sa Carte Est La N°%d \n",nAdherent);
    printf("il y'a %d Adhérents Dans Le Club.\n",nbrAdherent-1000);// le numéro de carte est égale au au numéro de la derniere carte -1000
    int supp=1012;
    nbrAdherent=fsuppressionadherent(supp,nbrAdherent);
    printf("Il y'a %d adhérents Dans La Base\n",nbrAdherent);
}
