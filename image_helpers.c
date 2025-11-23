#include <stdio.h>
#include <stdlib.h>
#include "image_helpers.h"

void generateRandomImage(float *arr, long total){
    long i;

    for (i = 0; i < total; i++){
        arr[i] = (float) rand() / RAND_MAX;
    }
}

void printImageInt(int *arr, int h, int w){
    int i, j;

    for (i = 0; i < h; i++){
        for (j = 0; j < w; j++){
            printf("%d ", arr[i * w + j]);
        }
        printf("\n");
    }
}

