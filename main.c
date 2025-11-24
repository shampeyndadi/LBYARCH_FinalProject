#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "image_helpers.h"
#include "imgCvtGrayFloatToInt.h"

int main(){

    int h, w;

    printf("Enter height and width (ie. 3 4): ");
    scanf("%d %d", &h, &w);

    long total = (long) h * w;

    float *in = malloc(total * sizeof(float));
    int *out = malloc(total * sizeof(int));

    for (long i = 0; i < total; i++){
        printf("Enter float pixel: ");
        scanf("%f", &in[i]);
    }

    printf("\n");

    printf("Input Image:\n");
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            printf("%.2f ", in[i * w + j]);
        }
        printf("\n");
    }

    imgCvtGrayFloatToInt(in, out, total);

    printf("\nOutput Image:\n");
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            printf("%d ", out[i * w + j]);
        }
        printf("\n");
    }

    free(in);
    free(out);

    return 0;
}