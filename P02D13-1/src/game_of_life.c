#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define XMAX 80
#define YMAX 25

int create_random_matrix(int (*matrix)[XMAX]);
int logic(int (*current_matrix)[XMAX]);
void output(int (*matrix)[XMAX]);

int main() {
    int matrix[YMAX][XMAX];
    int sum = 1;
    create_random_matrix(matrix);
    while (sum != 0) {
        sum = 0;
        output(matrix);
        logic(matrix);
        for (int i = 0; i < YMAX; i++) {
            for (int j = 0; j < XMAX; j++) {
                sum += matrix[i][j];
            }
        }
    }
}
int create_random_matrix(int (*matrix)[XMAX]) {
    int a;
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            int a = rand() % 2;
            matrix[i][j] = a;
        }
    }
    return **matrix;
}
int logic(int (*current_matrix)[XMAX]) {
    int future_matrix[YMAX][XMAX];
    int buf;
    int neigh = 0;
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            buf = current_matrix[i][j];
            if (i > 0 && i < 24 && j > 0 && j < 79) {  // если "сканируемая" клетка не на границе
                if (current_matrix[i - 1][j - 1] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][j + 1] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[i + 1][j - 1] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][j + 1] == 1) neigh++;
                if (neigh < 2 || neigh > 3) buf = 0;
                if (buf == 1 && (neigh == 2 || neigh == 3)) buf = 1;
                if (buf == 0 && neigh == 3) buf = 1;
            }
            if (i == 0 && j > 0 && j < 79) {
                // условия для клеток на верхней границы
            }
            if (i == 24 && j > 0 && j < 79) {
                // условия для клеток на нижней границе
            }
            if (j == 0 && i > 0 && i < 24) {
                // условия для клеток на левой границе
            }
            if (j == 79 && i > 0 && i < 24) {
                // условия для клеток на правой границе
            }
            future_matrix[i][j] = buf;
        }
    }
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            current_matrix[i][j] = future_matrix[i][j];
        }
    }
    return **current_matrix;
}
void output(int (*matrix)[XMAX]) {
    printf("\n");
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            if ((j < XMAX - 1) && (i < YMAX)) {
                if (matrix[i][j] == 0)
                    printf(" ");
                else
                    printf("*");
            }
            if ((j == 79) && (i == 0)) {
                if (matrix[i][j] == 0) {
                    printf(" \n");
                } else {
                    printf("*\n");
                }
            }
            if ((j == 79) && (i < YMAX - 1)) {
                if (matrix[i][j] == 0) {
                    printf(" \n");
                } else {
                    printf("*\n");
                }
            }
            if ((j == XMAX - 1) && (i == YMAX - 1)) {
                if (matrix[i][j] == 0)
                    printf(" ");
                else
                    printf("*");
            }
        }
    }
    sleep(1);
    system("clear");
}
