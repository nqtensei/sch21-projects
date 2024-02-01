#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int ch_mode(int *n);
int input_stat(int (*arr)[NMAX], int *s, int *a);
int **input_dyn1(int *s, int *a);
int **input_dyn2(int *s, int *a);
int **input_dyn3(int *s, int *a);
void output_stat(int (*arr)[NMAX], int s, int a);
void output_dyn(int **arr, int s, int a);

int main() {
    int n = ch_mode(&n);
    int s, a;
    if (n == 1) {
        int arr[NMAX][NMAX];
        if (input_stat(arr, &s, &a) == 0) {
            printf("n/a");
        } else {
            output_stat(arr, s, a);
        }
    }
    if (n == 2) {
        int **arr = input_dyn1(&s, &a);
        if (!arr) {
            printf("n/a");
        } else {
            output_dyn(arr, s, a);
        }
    }
    if (n == 3) {
        int **arr = input_dyn2(&s, &a);
        if (!arr) {
            printf("n/a");
        } else {
            output_dyn(arr, s, a);
        }
    }
    if (n == 4) {
        int **arr = input_dyn3(&s, &a);
        if (!arr) {
            printf("n/a");
        } else {
            output_dyn(arr, s, a);
        }
    }
    if (n != 1 && n != 2 && n != 3 && n != 4) {
        printf("n/a");
    }
}
int ch_mode(int *n) {
    if (!scanf("%d", n) || *n <= 0 || *n > 4 || getchar() != '\n') {
        return 0;
    }
    return *n;
}
int input_stat(int (*arr)[NMAX], int *s, int *a) {
    if (!scanf("%d %d", s, a) || *s <= 0 || *s > NMAX || *a <= 0 || *a > NMAX || getchar() != '\n') {
        return 0;
    }
    int val;
    for (int i = 0; i < *s; i++) {
        for (int j = 0; j < *a; j++) {
            if (scanf("%d", &val) == 0) {
                return 0;
            } else {
                arr[i][j] = val;
            }
        }
    }
    if (getchar() != '\n') return 0;
    return 1;
}
int **input_dyn1(int *s, int *a) {
    if (!scanf("%d %d", s, a) || *s <= 0 || *s > NMAX || *a <= 0 || *a > NMAX || getchar() != '\n') {
        return NULL;
    }
    int val;
    int **al = malloc(*s * *a * sizeof(int) + *s * sizeof(int));
    int *ptr = (int *)(al + *s);
    for (int i = 0; i < *s; i++) {
        al[i] = ptr + *a * i;
    }
    for (int i = 0; i < *s; i++) {
        for (int j = 0; j < *a; j++) {
            if (!scanf("%d", &val) != 0) {
                free(al);
                return NULL;
            } else {
                al[i][j] = val;
            }
        }
        if (getchar() != '\n') {
            free(al);
            return NULL;
        }
    }
    return al;
}
int **input_dyn2(int *s, int *a) {
    if (!scanf("%d %d", s, a) || *s <= 0 || *s > NMAX || *a <= 0 || *a > NMAX || getchar() != '\n') {
        return NULL;
    }
    int val;
    int **al = malloc(*s * sizeof(int));
    int *val_arr = malloc(*s * *a * sizeof(int));
    for (int i = 0; i < *s; i++) {
        al[i] = val_arr + *a * i;
    }
    for (int i = 0; i < *s; i++) {
        for (int j = 0; j < *a; j++) {
            if (scanf("%d", &val) == 0) {
                free(al);
                return NULL;
            } else {
                al[i][j] = val;
            }
        }
        if (getchar() != '\n') {
            free(al);
            return NULL;
        }
    }
    return al;
}
int **input_dyn3(int *s, int *a) {
    if (!scanf("%d %d", s, a) || *s <= 0 || *s > NMAX || *a <= 0 || *a > NMAX || getchar() != '\n') {
        return NULL;
    }
    int val;
    int **arr = malloc(*s * sizeof(int));
    for (int i = 0; i < *s; i++) {
        arr[i] = malloc(*a * sizeof(int));
    }
    for (int i = 0; i < *s; i++) {
        for (int j = 0; j < *a; j++) {
            if (scanf("%d", &val) == 0) {
                free(arr);
                return NULL;
            } else {
                arr[i][j] = val;
            }
        }
        if (getchar() != '\n') {
            free(arr);
            return NULL;
        }
    }
    return arr;
}
void output_stat(int (*arr)[NMAX], int s, int a) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < a; j++) {
            if ((j < a - 1) && (i < s)) {
                printf("%d ", arr[i][j]);
            }
            if ((j == a - 1) && (i < s - 1)) {
                printf("%d\n", arr[i][j]);
            }
            if ((j == a - 1) && (i == s - 1)) {
                printf("%d", arr[i][j]);
            }
        }
    }
}
void output_dyn(int **arr, int s, int a) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < a; j++) {
            if ((j < a - 1) && (i < s)) {
                printf("%d ", arr[i][j]);
            }
            if ((j == a - 1) && (i < s - 1)) {
                printf("%d\n", arr[i][j]);
            }
            if ((j == a - 1) && (i == s - 1)) {
                printf("%d", arr[i][j]);
            }
        }
    }
    free(arr);
}