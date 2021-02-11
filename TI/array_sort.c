#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void swap(int *d1, int *d2) {
    int tmp = *d1;
    *d1 = *d2;
    *d2 = tmp;
}

void array_sort(int *data, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

void array_print(int *data, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int *array_generate(int len, int max) {
    int *data = calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i) {
        data[i] = rand() % max;
    }
    return data;
}

int main() {
    int num_iterations, len;
    srand(time(NULL));
    printf("Length: ");
    scanf("%d", &len);
    printf("Number of iterations: ");
    scanf("%d", &num_iterations);
    double time_total = 0;
    for (int i = 0; i < num_iterations; ++i) {
        printf("*** iteration #%d ***\n", i);
        int *ptr = array_generate(len, MAX);
        array_print(ptr, len);
        clock_t t = clock();
        array_sort(ptr, len);
        t = clock() - t;
        array_print(ptr, len);
        double time = (double) t / CLOCKS_PER_SEC;
        printf("Time: %.8lf seconds\n", time);
        free(ptr);
        time_total += time;
    }
    printf("Average time: %.8lf seconds\n", time_total / num_iterations);
    return 0;
}
