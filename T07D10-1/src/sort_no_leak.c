#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int *input(int *n);
int sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n = 0;
    int *data = input(&n);
    if (!data) {
        printf("n/a");
    } else {
        sort(data, n);
        output(data, n);
        free(data);
    }
}
int *input(int *n) {
    if (!scanf("%d", n) || *n <= 0 || *n > NMAX || getchar() != '\n') {
        return NULL;
    }
    int *a = (int *)malloc(*n * sizeof(int));
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) == 0) {
            free(a);
            return NULL;
        }
    }
    if (getchar() != '\n') {
        free(a);
        return NULL;
    }

    return a;
}
int sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
    return 1;
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}