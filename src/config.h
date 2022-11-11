/**
 * \file config.h
 * \brief Configuration du programme
 *
 *   SAE 1.01
 */


//! Taille maximal des tableaux Tnum Tetat TnbPoints
#define TMAX 100
//! cout minimum d'une activité
#define CMINACT 10
//! Nombre d'activités
#define NBACT 10
//! Catégories
#define NBCATEADHE 4
//! Ajout de point au chargement (fidélité)
#define AJT_PTS_CHARG   3

//!Récurrence du don de points
#define RecurPtsBonus 80 

//! Points Bonus Pour Les étudiants
#define BonEtu 20 

//! Points Bonus Pour Les Mineurs
#define BonMineur 15 

//!Points Bonus Pour Les Retraités
#define BonRetraite 12

//! Points Bonus Pour Les Majeurs
#define BonMaj 10 

//! Prix en points des activitées
#define CO_KAYAK    25
#define CO_BOXE     15
#define CO_MUSCU    15
#define CO_GYM      12
#define CO_AQUAGYM  15
#define CO_VELO     20
#define CO_SQASH    22
#define CO_TENNIS   25
#define CO_BASKET   10
#define CO_FOOT     10

//! Bordures d'affichage
// UTF-8 char
#define BOX_HORI    "\u2501"
#define BOX_VERT    "\u2503"
#define BOX_TOPL    "\u250f"
#define BOX_TOPR    "\u2513"
#define BOX_BOTL    "\u2517"
#define BOX_BOTR    "\u251b"
#define BOX_VERR    "\u2523"
#define BOX_VERL    "\u252b"
#define BOX_UPHO    "\u253b"
#define BOX_VERH    "\u254b"
#define BOX_DOWH    "\u2533"

//! Styles  
//  (ANSI Escape Sequances) - https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
#define STY_NULL    "\e[0m"
#define STY_BOLD    "\e[1m"
#define STY_FCYAN   "\e[1;36m"
#define STY_FGREEN  "\e[1;32m"
#define STY_FRED    "\e[1;31m"
#define STY_FMAGEN  "\e[1;35m"
#define STY_FBLUE   "\e[1;34m"
#define STY_FYELLOW "\e[1;33m"
#define STY_BWHITE  "\e[1;30;47m"
