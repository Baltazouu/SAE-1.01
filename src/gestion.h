/*
* \file gestion.h
* \brief fonctions de gestions des adherents
*/

#define NBACT 10 // 10 Activités

int ajoutAdher(int *nbAdher, int nbCredits,
               int Tnum[], int Tetat[], int TnbPoints[], int tmax);

int suppAdhe(int numAdhe, int *tlog,
             int Tnum[], int Tetat[], int TnbPoints[]);

int alimCarte(int points, int numAdhe, int nbAdhe,
              int Tnum[], int Tetat[], int TnbPoints[]);

int activationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[]);

int desactivationCarte(int numAdhe, int nbAdhe, int Tnum[], int Tetat[]);

void EntreAdhe(int nbAdhe,int Tnum[],int Tetat[],int TnbPoints[],int TnbEntr[],int TnumAdheEntre[],int * nbAdheEntre,int TAdheintdt[],int *nbinterdt)
;
void InterdirAdhe(int numAdhe,int TAdheintdt[],int *nbInterdit,int Tnum[],int nbAdhe);

int VerifAdheNonInterdit(int numAdhe,int TAdheInterdt[],int *nbInterdit,int TnumAdheEntre[],int *nbAdheEntre);