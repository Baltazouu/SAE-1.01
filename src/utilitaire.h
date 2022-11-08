/*
* \file utilitaire.h
* \brief Fonctions utilitaires
*/


int rechercheNombre(int nb, int Table[], int *presence, int tlog);

int recherche1ereOccu(int Table[], int tlog, int *val);

int insertionNombre(int nb, int pos, int Table[], int tlog, int tmax);

void suppressionNombre(int pos, int Table[], int tlog);

int VerifEntreeAdhe(int nbAdhe,int Tnum[],int Tetat[],int *numAdhe);

void verifPresenceAct(int numAct,int TnumAct[],int nbAct,int *presence);

int VerifnbPRest(int TCact[],int numAct,int TnbPoints[],int posAdhe,int TnbEntr[]);
