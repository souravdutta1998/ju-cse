#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Max 30
    int P,i;
    P = 3419;
    int series[Max],remainder[Max];
    printf("Prime number = %d, divides L[i]\n",P);
    printf("____________________________________\n");
    printf("i\t   Ist L[i]  \tRemainder[i]\n");
    printf("-----------------------------------\n");
    for(i=0;i<Max;i++){
        float x;
        int y;
        int r = 45676789;
        x = rand();
        y = (r*x/RAND_MAX);
        series[i] = y;
        remainder[i] = ( y % P);
        printf("%0.7d  | %0.10d | %0.7d\n",i+1,series[i],remainder[i]);
    }

    return 0;
}

