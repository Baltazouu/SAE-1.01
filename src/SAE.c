#include<stdio.h>

int fajoutadherent(int *nombreAdherent){
    int numero,i=0;
    FILE *fadherent;
    fadherent=fopen("data/adherents.txt","a+");//ajout en lecture + écriture à la fin du fichier
    if(fadherent==NULL){printf("problème Ouverture Fichier Adhérents.\n");return -1;}
    fscanf(fadherent,"%d",&numero);
    while (!feof(fadherent))
    {
        fscanf(fadherent,"%d",&numero);
        i++;
    }
    if(numero==0)numero=1000;//si aucun adhérent présent : on initialise le premier au numéro 1000;
                            
    fprintf(fadherent,"%d\n",numero+1);
    
     // le nombre d'adhérent est égal a
    fclose(fadherent);
    *nombreAdherent=i+1;
    return numero+1;

}


int rechercheNombre(int nbr,int Table[],int len_table)
{
    int i;
    for(i=0;i<len_table;i++)
    {      
        
        if(Table[i]==nbr){
        //printf("le Nombre %d se trouve en position %d\n",Table[i],i);
        //printf("%d\n",Table[i]);
        return i;}  
    }
    return -1;
}


int fsuppressionadherent(int num_adherent,int nbr_adherent)
{   
    //printf("Ca fonctionne");
    int i=0,x=0;
    int pos,nAdherent;
    int tAdherent[nbr_adherent];
    FILE *fadherent; FILE *fichier;
    fadherent=fopen("data/adherents.txt","r");
    if(fadherent==NULL){printf("Problème Ouverture Fichier !!"); return -1;}
    //fscanf(fadherent,"%d",&nAdherent);
    while (!feof(fadherent))
    {   
        //printf("i : %d\n",i);
        if(i==nbr_adherent)break;//{printf("Erreur Probleme Taille Tables !\n"); return -1;}
        fscanf(fadherent,"%d",&nAdherent);
        tAdherent[i]=nAdherent;
        
        i++;
    }
    fclose(fadherent);
    pos=rechercheNombre(num_adherent,tAdherent,nbr_adherent);
    if (pos==1){printf("Erreur ! Carte Non Présente Dans La Base...");return -1;}
    
    for(x=pos;x<nbr_adherent-1;x++)
    {   
        tAdherent[x]=tAdherent[x+1];
    }
    
    
    fichier=fopen("data/adherents.txt","w");
    if (fadherent==NULL){printf("Problème Ouverture Fichier !");return -1;}
    for(x=0;x<nbr_adherent-1;x++)
    {   
        fprintf(fichier,"%d\n",tAdherent[x]);
    }
    fclose(fichier);
    printf("Adhérent Et Carte N°%d Supprimés Avec Succès\n",num_adherent);
    printf("Il y'a à présent %d adhérents dans le club\n",nbr_adherent-1);
    return nbr_adherent-1;

}


int main(void)
{   
    int nbrAdherent,numero,i;
    for (i=0;i<50;i++){
        numero=fajoutadherent(&nbrAdherent);// le nombre d'adhérent est égal au numéro du dérnier adhérent - 1000
        printf("Nouvel Adhérent est Crée, Sa Carte Est La N°%d \n",numero);}
    printf("il y'a %d Adhérents Dans Le Club.\n",nbrAdherent);// le numéro de carte est égale au au numéro de la derniere carte -1000
    printf("Entrez Le Numéro D'adhérent à supprimer : ");
    scanf("%d",&numero);
    nbrAdherent=fsuppressionadherent(numero,nbrAdherent);
    numero=fajoutadherent(&nbrAdherent);
    printf("il y'a %d Adhérents Dans Le Club.\n",nbrAdherent);
    
    return 0;
    

}
