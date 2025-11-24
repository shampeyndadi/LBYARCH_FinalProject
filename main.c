#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "image_helpers.h"
#include "imgCvtGrayFloatToInt.h"

int main(){

    int h, w;

    printf("Enter height and width: ");
    scanf("%d %d", &h, &w);

    long total = (long) h * w;

    float *in = malloc(total * sizeof(float));
    int *out = malloc(total * sizeof(int));

    printf("Enter float pixels: \n");
    for (long i = 0; i < total; i++){
        scanf("%f", &in[i]);
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            printf ("%.2f ", in[i * w + j]);
        }
        printf ("\n");
    }

    return 0;
}