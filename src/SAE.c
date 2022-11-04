#include<stdio.h>
#include"SAE.h"

int fnbr_adherents(void){

    int nbr_adherents;
    FILE *fe;
    fe=fopen("data/nbradherents.txt","r");
    if (fe==NULL){return -1;}
    fscanf(fe,"%d",&nbr_adherents);
    fclose(fe);
    return nbr_adherents;
}


int fajoutadherent(int *nombreAdherent,int nbC){
    int numero,active_carte,nbr_credit,i=0;
    FILE *fadherent;
    fadherent=fopen("data/adherents.txt","a+");//ajout en lecture + écriture à la fin du fichier
    if(fadherent==NULL){printf("problème Ouverture Fichier Adhérents.\n");return -1;}
    fscanf(fadherent,"%d %d %d",&numero,&active_carte,&nbr_credit);
    while (!feof(fadherent))
    {
        fscanf(fadherent,"%d %d %d",&numero,&active_carte,&nbr_credit);
        i++;
    }
    if(numero==0)
        {
        numero=1000;//si aucun adhérent présent : on initialise le premier au numéro 1001;
        //fprintf(fadherent,"%d\t%d\t%d\n",numero+1,1,nbC);
        }
    
    fprintf(fadherent,"%d\t%d\t%d\n",numero+1,1,nbC);       
            // quand on crée un adhérent, on active forcément sa carte et on la crédit de nbC
    
     // le nombre d'adhérent est égal a
    fclose(fadherent);
    *nombreAdherent=i+1;

    FILE *fe;
    fe=fopen("data/nbradherents.txt","w");
    if (fe==NULL)return -1;//pb ouverture fichier : return -1
    fprintf(fe,"%d",*nombreAdherent);
    fclose(fe);
    return numero+1;// on stocke le nombre d'adhérents dans un fichier à part

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
    int pos,nAdherent,carte_active,credits;
    int tAdherent[nbr_adherent],tcarte_active[nbr_adherent],tcredit[nbr_adherent];
    FILE *fadherent; FILE *fichier;
    fadherent=fopen("data/adherents.txt","r");
    if(fadherent==NULL){printf("Problème Ouverture Fichier !!\n"); return -1;}
    fscanf(fadherent,"%d %d %d",&nAdherent,&carte_active,&credits);
    while (!feof(fadherent))
    {   
        if(i==nbr_adherent)return -1;//{printf("Erreur Probleme Taille Tables !\n"); return -1;}
        
        tAdherent[i]=nAdherent;
        tcarte_active[i]=carte_active;
        tcredit[i]=credits;
        fscanf(fadherent,"%d %d %d",&nAdherent,&carte_active,&credits);
        i++;
    }
    fclose(fadherent);
    pos=rechercheNombre(num_adherent,tAdherent,nbr_adherent);
    if (pos==-1){printf("Erreur ! N° De Carte Non Présente Dans La Base...\n");return -1;}
    
    for(x=pos;x<nbr_adherent-1;x++)
    {   
        tAdherent[x]=tAdherent[x+1];
        tcarte_active[x]=tcarte_active[x+1];
        tcredit[x]=tcredit[x+1];
    }
    
    
    fichier=fopen("data/adherents.txt","w");
    if (fadherent==NULL){printf("Problème Ouverture Fichier !\n");return -1;}
    for(x=0;x<nbr_adherent-1;x++)
    {   
        fprintf(fichier,"%d\t%d\t%d\n",tAdherent[x],tcarte_active[x],tcredit[x]);
    }
    fclose(fichier);
    printf("Adhérent Et Carte N°%d Supprimés Avec Succès\n",num_adherent);
    printf("Il y'a à présent %d adhérents dans le club\n",nbr_adherent-1);
    FILE *fe;
    fe=fopen("data/nbradherents.txt","w");
    if (fe==NULL)return -1;//pb ouverture fichier : return -1
    fprintf(fe,"%d",nbr_adherent-1);
    fclose(fe);
    return nbr_adherent-1;

}

void fsupp(void){  
    int numero,nbrAdherent;
    nbrAdherent=fnbr_adherents();// la fonction va chercher le nombre d'adhérents dans le fichier nnbr_adhérents
    if (nbrAdherent==-1){printf("Erreur Ouverture Fichier ! :/");return;}
    printf("Entrez Le Numéro D'adhérent à supprimer : ");
    scanf("%d",&numero);
    nbrAdherent=fsuppressionadherent(numero,nbrAdherent);  
}



int ajoutadher(void)
{   
    int numero,nbrAdherent,nbcredits;
    printf("Combien de Crédits Souhaitez Vous Allouer à Votre Carte : ");
    scanf("%d",&nbcredits);
    while (nbcredits<1)
    {
        printf("Erreur !! Vous Devez Obligatoirement Allouer Des Crédits à votre carte !");
        printf("Combien de Crédits Souhaitez Vous Allouer à la carte : ");
        scanf("%d",&nbcredits); 
    }
    numero=fajoutadherent(&nbrAdherent,nbcredits);// le nombre d'adhérent est égal au numéro du dérnier adhérent - 1000
    printf("Nouvel Adhérent est Crée, Sa Carte Est La N°%d. Il Dispose de %d Crédits. \n",numero,nbcredits);
    printf("il y'a à présent %d Adhérents Dans Le Club.\n",nbrAdherent);// le numéro de carte est égale au au numéro de la derniere carte -1000
    return 0;
}


void falim(void){
    int nbr_credits;
    printf("Entrez Le Numéro de Carte à allouer");
    scanf("%d",&nbr_credits);
}

void fafficha1derent(void){

    int numadherent;
    int num,active,nbpoints;
    printf("Entrez Le Numéro D'adhérent à afficher : ");
    scanf("%d",&numadherent);
    FILE *fe;
    fe=fopen("data/adherents.txt","r");
    if (fe==NULL){printf("Erreur Ouverture Fichier !!");return;}
    fscanf(fe,"%d %d %d",&num,&active,&nbpoints);
    while(!feof(fe))
    {   
        //printf("numero : %d",num);
        if (num==numadherent)
        {
            printf("Numéro\tEtat Carte\tNombre de Points :\n");
            printf("%d\t\t%d\t\t%d\n",num,active,nbpoints);
            return;
        }
        fscanf(fe,"%d %d %d",&num,&active,&nbpoints);
    }
    printf("Erreur, Le Numéro Spécifié N'est pas dans la base !!\n");
    fclose(fe);

}


void faffichtousadherent (void)
{
    int numero,carteactive,nbpoints;
    FILE *fe;
    fe=fopen("data/adherents.txt","r");
    if (fe==NULL){printf("Erreur Ouverture Fichier\n"); return;}
    printf("Numéro\tEtat Carte\tNombre de Points :\n");
    fscanf(fe,"%d %d %d",&numero,&carteactive,&nbpoints);
    while(!feof(fe))
    {
        printf("%d\t\t%d\t\t%d\n",numero,carteactive,nbpoints);
        fscanf(fe,"%d %d %d",&numero,&carteactive,&nbpoints);
    }
    fclose(fe);
    return;

}
// ---------------------------------- WORKS ^^ -----------------------------------------//
//-----------------------------------       ||  ---------------------------------------//

void fonctiongenerale(void){

    int choix;
    printf("Gestion D'un Complexe Sportif !\n");
    printf("Entrez Les Numéros de la commande Correspondante :\n\n");


    printf("\t\t# Créer Un Nouvel Adhérent : 1\n");

    printf("\t\t# Supprimer Un Adhérent : 2\n");
    
    printf("\t\t# Alimenter Une Carte : 3\n");
    
    printf("\t\t# Activer Une Carte : 4\n");
    
    printf("\t\t# Désactiver Une Carte : 5\n");
    
    printf("\t\t# Afficher Les informations d'un adhérent : 6\n");

    printf("\t\t# Afficher Les informations de tous les adhérent : 7\n");
    
    printf("\t\t# Afficher le nombre d'entrées par activité dans la journée : 8\n");
    
    printf("\t\tQuitter La Gestion du Centre : 9\n");
    
    printf("\nEntrez Votre Choix : ");
    scanf("%d",&choix);
    //while (choix!=7)
    //{
        if (choix==1)   {ajoutadher();}

        if (choix==2)   {fsupp();}

        if (choix==3){return; }

        if (choix==4){return;}

        if (choix==5){return;}

        if (choix==6){ fafficha1derent(); return;}

        if (choix==7){ faffichtousadherent(); return;}
        //printf("Entrez Le Choix Correspondant : ")
        //fscanf("%d",&choix);
    //}
    return;

}


int main(void)
{
    fonctiongenerale();
    return 0;
}