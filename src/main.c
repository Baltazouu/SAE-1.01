/**
* \file main.c
* \brief Main (tests)
* \author Alexandre Agostinho
* \date 22/09/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

#define TMAX 30

void testChargSauvgPoints() {
    int tAdhe[TMAX], tNPoints[TMAX];
    int tLog = chargPoints(tAdhe, tNPoints, TMAX);
    if (tLog < 0) { return; }

    printf("tAdhe\tNPoints\n\n");
    for (int i = 0; i < tLog; i++) {
        printf("%d\t%d\n", tAdhe[i], tNPoints[i]);
    }

    printf("\n--Save-------\n");

    tAdhe[4] = 255; tNPoints[4] = 255;
    tAdhe[7] = 255; tNPoints[7] = 255;
    tAdhe[11] = 255; tNPoints[11] = 255;

    if (sauvgPoints(tAdhe, tNPoints, tLog) > 0) {
        system("cat data/points.don");
    }
}

int main(void) {

    testChargSauvgPoints();
    return 0;
}
