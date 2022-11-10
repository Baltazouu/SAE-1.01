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

//: Bordures d'affichage
#define BOX_HORI    "\u2501"
#define BOX_VERT    "\u2503"
#define BOX_TOPL    "\u250f"
#define BOX_TOPR    "\u2513"
#define BOX_BOTL    "\u2517"
#define BOX_BOTR    "\u251b"

//! Styles
#define STY_NULL    "\e[0m"
#define STY_BOLD    "\e[1m"
#define STY_FCYAN   "\e[1;36m"
#define STY_FGREEN  "\e[1;32m"
#define STY_FRED    "\e[1;31m"
#define STY_FMAGEN  "\e[1;35m"
#define STY_FBLUE   "\e[1;34m"
#define STY_BWHITE  "\e[1;30;47m"
