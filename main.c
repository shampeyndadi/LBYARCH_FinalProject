#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "image_helpers.h"
#include "imgCvtGrayFloatToInt.h"

#define CLEAR() system("cls")

int main() {

    int terminate = 0;

    while (!terminate) {

        int h, w, mode;

        CLEAR();
        printf("=====================================\n");
        printf("   Grayscale Float → Int Converter\n");
        printf("=====================================\n\n");

        printf("Choose mode:\n");
        printf("  1 - Manual input\n");
        printf("  2 - Random image generation\n");
        printf("  3 - Performance test only\n");
        printf("  4 - Exit program\n");
        printf("-------------------------------------\n");
        printf("Enter choice: ");

        scanf("%d", &mode);

        if (mode == 4) {
            CLEAR();
            printf("\nProgram terminated.\n");
            break;
        }

        CLEAR();
        printf("=====================================\n");
        printf("   Enter image dimensions\n");
        printf("=====================================\n\n");

        printf("Enter height and width (ie. 3 4): ");
        scanf("%d %d", &h, &w);

        long total = (long)h * w;

        float *in  = malloc(total * sizeof(float));
        int   *out = malloc(total * sizeof(int));

        if (!in || !out) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        CLEAR();
        printf("=====================================\n");
        if (mode == 1) {

            printf("Manual Input Mode\n");
            printf("=====================================\n");

            for (long i = 0; i < total; i++) {
                printf("Enter float pixel %ld: ", i);
                scanf("%f", &in[i]);
            }

            CLEAR();
            printf("=====================================\n");
            printf("Input Image (float)\n");
            printf("=====================================\n");

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    printf("%.2f ", in[i*w + j]);
                }
                printf("\n");
            }

            imgCvtGrayFloatToInt(in, out, total);

            printf("\n=====================================\n");
            printf("Converted Image (int)\n");
            printf("=====================================\n");
            printImageInt(out, h, w);
        }
        else if (mode == 2) {

            printf("Random Image Mode\n");
            printf("=====================================\n");

            srand((unsigned)time(NULL));
            generateRandomImage(in, total);

            printf("Input Image (float):\n");
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    printf("%.2f ", in[i*w + j]);
                }
                printf("\n");
            }

            imgCvtGrayFloatToInt(in, out, total);

            printf("\n=====================================\n");
            printf("Converted Image (int)\n");
            printf("=====================================\n");
            printImageInt(out, h, w);
        }
        else if (mode == 3) {

            printf("Performance Test Mode\n");
            printf("=====================================\n");

            srand((unsigned)time(NULL));
            generateRandomImage(in, total);

            LARGE_INTEGER freq, start, end;
            QueryPerformanceFrequency(&freq);

            double total_time = 0.0;

            for (int i = 0; i < 30; i++) {
                QueryPerformanceCounter(&start);
                imgCvtGrayFloatToInt(in, out, total);
                QueryPerformanceCounter(&end);

                total_time +=
                    (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
            }

            printf("\nAverage execution time (high res): %.10f seconds\n",
                   total_time / 30.0);

            free(in);
            free(out);
            printf("\nReturning to main menu...\n");
            system("pause");
            continue;
        }

        printf("\n=====================================\n");
        printf("Performance Test (Final)\n");
        printf("=====================================\n");

        LARGE_INTEGER freq, start, end;
        QueryPerformanceFrequency(&freq);

        double total_time = 0.0;

        for (int i = 0; i < 30; i++) {
            QueryPerformanceCounter(&start);
            imgCvtGrayFloatToInt(in, out, total);
            QueryPerformanceCounter(&end);

            total_time +=
                (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
        }

        printf("\nAverage execution time (high res): %.10f seconds\n",
               total_time / 30.0);

        free(in);
        free(out);
        system("pause");

        printf("\nReturning to main menu...\n");
    }

    return 0;
}
